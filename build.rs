use std::{
    env, fs,
    path::{Path, PathBuf},
    process::Command,
};

// The three TORA STP C++ SDK bundles. The native libraries are too large for
// crates.io's package size limit, so they're fetched at build time instead of
// shipped inside the crate. Each is a zip-of-a-zip: the outer archive holds a
// `version.txt` and an inner zip, and the inner zip holds the `TORATstp*.h`
// headers next to the Linux `.so` and the Windows `x64`/`x86` `.dll`/`.lib`
// binaries. We extract the headers + Linux `.so` + Windows `x64` `.dll`/`.lib`
// of all three into `$OUT_DIR/lib` and link there. On a version bump, update
// these URLs.
const TORA_ASSET_URLS: &[&str] = &[
    "https://ctp-api.ruiqilei.com/tora/API_Stock_C%2B%2B_td%20v4.1.8_20260422.zip",
    "https://ctp-api.ruiqilei.com/tora/Api_Stock_lv1_C%2B%2B_md%20v1.0.9_20250825.zip",
    "https://ctp-api.ruiqilei.com/tora/API_Stock_lv2_C%2B%2B%20v4.0.8_20251126.zip",
];

// The cxx wrapper sources. Each TORA API family — trader (`TORASTOCKAPI`),
// Level-1 MD (`TORALEV1API`), Level-2 MD (`TORALEV2API`) — gets a Converter /
// Spi / Api translation unit.
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
    // docs.rs builds in a sandbox without network access, so the bundle download
    // in `ensure_lib_dir` would fail. Rustdoc only type-checks the crate
    // (cxx::bridge expands on the Rust side; no link step), so skip the
    // download + C++ build + lib copies entirely.
    if env::var_os("DOCS_RS").is_some() {
        return;
    }

    let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());
    // Native libs land under OUT_DIR (not the source tree) so `cargo publish`
    // verification doesn't reject this build script for modifying source.
    let lib_dir = out_dir.join("lib");
    ensure_lib_dir(&lib_dir);
    assert!(
        lib_dir.join("TORATstpTraderApi.h").exists(),
        "TORA SDK headers missing under {} after download — the bundle layout \
         may have changed; run `cargo clean` and rebuild to re-fetch",
        lib_dir.display()
    );

    let target_os = env::var("CARGO_CFG_TARGET_OS").unwrap_or_default();

    // The fast variants are ABI-identical drop-in replacements (they export the
    // exact same mangled `CTORATstp*Api::Create*`/vtable symbols), so the choice
    // is purely which dynamic library we link against — selectable independently
    // for the trader and the Level-1 MD families.
    let fast_trader = env::var_os("CARGO_FEATURE_FAST_TRADER").is_some();
    let fast_xmd = env::var_os("CARGO_FEATURE_FAST_XMD").is_some();
    let trader_lib = if fast_trader {
        "fasttraderapi"
    } else {
        "traderapi"
    };
    let xmd_lib = if fast_xmd { "xfastmdapi" } else { "xmdapi" };
    let lev2md_lib = "lev2mdapi";
    let link_libs = [trader_lib, xmd_lib, lev2md_lib];

    // --- link against the downloaded SDK -----------------------------------
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

/// Downloads the three TORA SDK bundles and extracts the headers + Linux `.so`
/// + Windows `x64` `.dll`/`.lib` of each into `lib_dir` (a flat directory under
/// `$OUT_DIR`) if it isn't already there.
///
/// `OUT_DIR` is per-build (target/profile/build-script hash), and any change to
/// the `TORA_ASSET_URLS` constant re-hashes build.rs and yields a fresh
/// `OUT_DIR`. So if `lib_dir` already exists it must be the set this build
/// wants — no version check needed. Extraction happens into a sibling staging
/// dir and is renamed in atomically, so a partial run can never be mistaken for
/// a complete one.
///
/// Uses `curl` + `unzip` (Unix) / `tar` (Windows) rather than Rust HTTP/zip
/// crates: those add multi-megabyte build-time deps for what the system tools
/// already do. They're universally available on supported platforms — see the
/// README "构建依赖 / Build requirements".
fn ensure_lib_dir(lib_dir: &Path) {
    if lib_dir.exists() {
        return;
    }

    // Two scratch dirs next to the final lib_dir: `scratch` holds the downloaded
    // zips and their raw extraction; `staging` is the clean flat set we collect
    // into and atomically rename to lib_dir.
    let scratch = lib_dir.with_file_name("lib.scratch");
    let staging = lib_dir.with_file_name("lib.partial");
    for d in [&scratch, &staging] {
        if d.exists() {
            fs::remove_dir_all(d)
                .unwrap_or_else(|e| panic!("failed to clear {}: {}", d.display(), e));
        }
    }
    let raw = scratch.join("raw");
    fs::create_dir_all(&raw)
        .unwrap_or_else(|e| panic!("failed to create {}: {}", raw.display(), e));
    fs::create_dir_all(&staging)
        .unwrap_or_else(|e| panic!("failed to create {}: {}", staging.display(), e));

    // Not `cargo:warning=` — cargo caches those in the build script's `output`
    // file and replays them on every subsequent build of this package, even
    // when build.rs doesn't re-run, so a one-time download would otherwise
    // produce a permanent warning. `eprintln!` goes to captured stderr (shown
    // with `cargo build -vv` or on failure) and isn't replayed.
    eprintln!("tora-rs: downloading TORA SDK bundles — this happens once per OUT_DIR");

    // Download + extract each outer bundle into `raw`.
    for (i, url) in TORA_ASSET_URLS.iter().enumerate() {
        let zip_path = scratch.join(format!("asset-{i}.zip"));
        let status = Command::new("curl")
            .arg("-fsSL")
            .arg("--retry")
            .arg("3")
            .arg("-o")
            .arg(&zip_path)
            .arg(url)
            .status()
            .expect("`curl` not found — required to fetch TORA SDK bundles (see README)");
        assert!(
            status.success(),
            "failed to download TORA SDK bundle from {}",
            url
        );
        unzip_into(&zip_path, &raw);
    }

    // Each outer bundle dropped an inner `*.zip` (the real payload) into `raw`;
    // extract those in place. TORA never nests deeper than this.
    for inner in find_zips(&raw) {
        unzip_into(&inner, &raw);
    }

    // Flatten the wanted files into `staging`.
    collect_sdk_files(&raw, &staging);

    let _ = fs::remove_dir_all(&scratch);

    // Atomic publish: lib_dir only ever exists when collection succeeded.
    fs::rename(&staging, lib_dir).unwrap_or_else(|e| {
        panic!(
            "failed to rename {} → {}: {}",
            staging.display(),
            lib_dir.display(),
            e
        )
    });
}

/// Extract `zip` into `dest`, creating it if needed. Prefers `unzip` on Unix
/// (ships with macOS, in every mainstream Linux base repo); falls back to
/// `tar -xf` on Windows, which ships with Windows 10 1803+ and reads zip via
/// libarchive.
fn unzip_into(zip: &Path, dest: &Path) {
    let status = if cfg!(target_os = "windows") {
        Command::new("tar")
            .arg("-xf")
            .arg(zip)
            .arg("-C")
            .arg(dest)
            .status()
            .expect("`tar` not found — required to extract on Windows (see README)")
    } else {
        Command::new("unzip")
            .arg("-q")
            .arg("-o")
            .arg(zip)
            .arg("-d")
            .arg(dest)
            .status()
            .expect("`unzip` not found — required to extract TORA bundles (see README)")
    };
    assert!(
        status.success(),
        "failed to extract {} into {}",
        zip.display(),
        dest.display()
    );
}

/// All `*.zip` files directly under `dir` (the inner bundle payloads).
fn find_zips(dir: &Path) -> Vec<PathBuf> {
    let mut out = Vec::new();
    for entry in fs::read_dir(dir).unwrap_or_else(|e| panic!("read_dir {}: {}", dir.display(), e)) {
        let p = entry.unwrap().path();
        if p.extension().and_then(|s| s.to_str()) == Some("zip") {
            out.push(p);
        }
    }
    out
}

/// Walk `raw` and copy the SDK files this crate needs into the flat `staging`
/// dir: every `*.h` header, every Linux `*.so`, and the Windows `*.dll`/`*.lib`
/// under an `x64` directory. The bundles also ship 32-bit copies under `x86`
/// (same basenames) — those are skipped so they can't clobber the x64 ones.
fn collect_sdk_files(raw: &Path, staging: &Path) {
    visit_files(raw, &mut |path| {
        let in_x86 = path_has_component(path, "x86");
        let in_x64 = path_has_component(path, "x64");
        if in_x86 {
            return;
        }
        let name = match path.file_name().and_then(|s| s.to_str()) {
            Some(n) => n,
            None => return,
        };
        let lower = name.to_lowercase();
        let want = lower.ends_with(".h")
            || lower.ends_with(".so")
            || ((lower.ends_with(".dll") || lower.ends_with(".lib")) && in_x64);
        if want {
            let dst = staging.join(name);
            fs::copy(path, &dst)
                .unwrap_or_else(|e| panic!("copy {} -> {}: {}", path.display(), dst.display(), e));
        }
    });
}

/// True if any path component equals `needle` (e.g. the `x64` / `x86` dirs).
fn path_has_component(path: &Path, needle: &str) -> bool {
    path.components()
        .any(|c| c.as_os_str().to_str() == Some(needle))
}

/// Depth-first walk invoking `f` on every regular file under `dir`.
fn visit_files(dir: &Path, f: &mut dyn FnMut(&Path)) {
    for entry in fs::read_dir(dir).unwrap_or_else(|e| panic!("read_dir {}: {}", dir.display(), e)) {
        let p = entry.unwrap().path();
        if p.is_dir() {
            visit_files(&p, f);
        } else {
            f(&p);
        }
    }
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
        fs::copy(&src, &dst)
            .unwrap_or_else(|e| panic!("copy {} -> {}: {}", src.display(), dst.display(), e));
    }
}
