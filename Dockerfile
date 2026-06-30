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
# edition 2024 needs Rust >= 1.85; the buildpack-deps base already provides g++,
# and glibc supplies iconv(3), so no extra apt packages are required.
FROM --platform=linux/amd64 rust:1-bookworm AS build

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
