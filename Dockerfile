# check=skip=FromPlatformFlagConstDisallowed
# (Pinning the platform to linux/amd64 in FROM is intentional — see below — so
#  the above directive silences BuildKit's constant-`--platform` lint. A parser
#  directive must be the very first line, before any other comment.)

# TORA STP ships only linux/amd64 (and Windows) prebuilt libraries — there is no
# macOS build — so this crate cannot be compiled/linked on an Apple-Silicon host
# directly. This image pins linux/amd64 so it builds anywhere Docker runs,
# emulating x86-64 on arm64 machines if needed.
#
#   docker build --platform=linux/amd64 -t tora-rs .
#
# edition 2024 needs Rust >= 1.85; the buildpack-deps base already provides g++
# and curl, and glibc supplies iconv(3). build.rs downloads the TORA SDK bundles
# at build time and extracts them with `unzip`, which the base lacks — install it.
FROM --platform=linux/amd64 rust:1-bookworm AS build

RUN apt-get update \
    && apt-get install -y --no-install-recommends unzip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tora-rs
COPY . .

# Build the library + examples for every fast/standard combination, proving the
# fast variants can be selected independently for xmd and trader.
RUN set -eux; \
    cargo build --examples; \
    cargo build --examples --features fast-xmd; \
    cargo build --examples --features fast-trader; \
    cargo build --examples --features fast-xmd,fast-trader

CMD ["bash"]
