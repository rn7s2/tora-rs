use std::{
    env, fs,
    path::{Path, PathBuf},
};

// Generated cxx wrapper sources (see ../tora-rs-generator). Each TORA API family
// — trader (`TORASTOCKAPI`), Level-1 MD (`TORALEV1API`), Level-2 MD
// (`TORALEV2API`) — gets a Converter / Spi / Api translation unit.
const WRAPPER_SRCS: &[&str] = &[
    "wrapper/src/TraderConverter.cpp",
    "wrapper/src/CTraderSpi.cpp",
    "wrapper/src/TraderApi.cpp",
    "wrapper/src/XMdConverter.cpp",
    "wrapper/src/CXMdSpi.cpp",
    "wrapper/src/XMdApi.cpp",
    "wrapper/src/Lev2MdConverter.cpp",
    "wrapper/src/CLev2MdSpi.cpp",
    "wrapper/src/Lev2MdApi.cpp",
];

// Wrapper headers — listed only so a manual edit re-triggers the build.
const WRAPPER_HEADERS: &[&str] = &[
    "wrapper/include/TraderConverter.h",
    "wrapper/include/CTraderSpi.h",
    "wrapper/include/TraderApi.h",
    "wrapper/include/XMdConverter.h",
    "wrapper/include/CXMdSpi.h",
    "wrapper/include/XMdApi.h",
    "wrapper/include/Lev2MdConverter.h",
    "wrapper/include/CLev2MdSpi.h",
    "wrapper/include/Lev2MdApi.h",
];

fn main() {
    let manifest_dir = PathBuf::from(env::var("CARGO_MANIFEST_DIR").unwrap());

    // Unlike ctp-rs, the TORA SDK is vendored directly under `lib/` (no R2
    // download): headers (`TORATstp*.h`) and the Linux `.so` / Windows
    // `.dll`+`.lib` binaries all live here.
    let lib_dir = manifest_dir.join("lib");
    assert!(
        lib_dir.join("TORATstpTraderApi.h").exists(),
        "vendored TORA SDK not found under {} — the crate ships its headers and \
         prebuilt libraries there; the checkout looks incomplete",
        lib_dir.display()
    );

    let target_os = env::var("CARGO_CFG_TARGET_OS").unwrap_or_default();

    // The fast variants are ABI-identical drop-in replacements (they export the
    // exact same mangled `CTORATstp*Api::Create*`/vtable symbols), so the choice
    // is purely which dynamic library we link against — selectable independently
    // for the trader and the Level-1 MD families.
    let fast_trader = env::var_os("CARGO_FEATURE_FAST_TRADER").is_some();
    let fast_xmd = env::var_os("CARGO_FEATURE_FAST_XMD").is_some();
    let trader_lib = if fast_trader { "fasttraderapi" } else { "traderapi" };
    let xmd_lib = if fast_xmd { "xfastmdapi" } else { "xmdapi" };
    let lev2md_lib = "lev2mdapi";
    let link_libs = [trader_lib, xmd_lib, lev2md_lib];

    // --- link against the vendored SDK --------------------------------------
    println!("cargo:rustc-link-search=native={}", lib_dir.display());
    for lib in link_libs {
        // On Linux the linker resolves `lib<name>.so`; on Windows MSVC the
        // import `<name>.lib`. Both sit side by side in `lib_dir`.
        println!("cargo:rustc-link-lib=dylib={}", lib);
    }
    // So a standalone (non-`cargo run`) binary finds the sibling `.so` we copy
    // next to it below, without the user having to set LD_LIBRARY_PATH.
    if target_os == "linux" {
        println!("cargo:rustc-link-arg=-Wl,-rpath,$ORIGIN");
    }

    // --- compile the generated cxx wrapper ----------------------------------
    // One bridge file per TORA family: cxx requires globally-unique type idents
    // *within a single source file* it processes, and the families share many
    // struct names. Separate files → separate cxx translation units, so the
    // shared names (each in its own C++ namespace) don't collide.
    let mut build = cxx_build::bridges(["src/trader.rs", "src/xmd.rs", "src/lev2md.rs"]);
    build.include(&lib_dir); // resolves the plain `#include "TORATstp*.h"`
    build
        .flag_if_supported("/EHsc")
        .flag_if_supported("/std:c++20")
        .flag_if_supported("/utf-8")
        .flag_if_supported("/w")
        .flag_if_supported("-std=c++20")
        .flag_if_supported("-w");
    build.files(WRAPPER_SRCS).compile("tora_rs");

    // cxx_build already emits rerun-if-changed for the bridge files; cover the
    // module root and the hand-listed wrapper sources/headers too.
    println!("cargo:rerun-if-changed=src/lib.rs");
    for f in WRAPPER_SRCS.iter().chain(WRAPPER_HEADERS) {
        println!("cargo:rerun-if-changed={}", f);
    }

    // --- copy the selected runtime libraries next to the binary -------------
    // Mirrors ctp-rs: Win/Linux load a dynamic library at runtime, so it must be
    // deployed alongside the executable.
    copy_runtime_libs(&lib_dir, &target_os, &link_libs);
}

/// Copy each linked dynamic library from `lib_dir` into the per-profile target
/// directory (e.g. `target/debug/`) so the produced executables can load them.
fn copy_runtime_libs(lib_dir: &Path, target_os: &str, libs: &[&str]) {
    // OUT_DIR is `target/<profile>/build/<pkg-hash>/out`; pop 3 to reach
    // `target/<profile>/`, where Cargo places the binaries.
    let target_dir = {
        let mut p = PathBuf::from(env::var("OUT_DIR").unwrap());
        let _ = p.pop() && p.pop() && p.pop();
        p
    };

    for lib in libs {
        let file = match target_os {
            "windows" => format!("{lib}.dll"),
            "linux" => format!("lib{lib}.so"),
            // Other targets don't ship a TORA SDK; nothing to copy.
            _ => return,
        };
        let src = lib_dir.join(&file);
        let dst = target_dir.join(&file);
        fs::copy(&src, &dst).unwrap_or_else(|e| {
            panic!("copy {} -> {}: {}", src.display(), dst.display(), e)
        });
    }
}
