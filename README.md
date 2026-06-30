# tora-rs

TORA STP（华鑫奇点）证券交易系统 C++ 接口的安全、符合 Rust 惯用法的绑定。支持
Linux 与 Windows（TORA 无 macOS 版本）。

Safe & idiomatic Rust bindings for the TORA STP (华鑫奇点) securities trading
API. Linux + Windows only — TORA ships no macOS build.

## 特性

- **三套接口**，各为独立模块：
  - [`trader`] — 交易接口（C++ namespace `TORASTOCKAPI`）
  - [`xmd`] — Level-1 行情接口（`TORALEV1API`）
  - [`lev2md`] — Level-2 行情接口（`TORALEV2API`）
- **安全 API**：字段使用 Rust `String` / 所有权语义，GBK ↔ UTF-8 自动转换。
- **基于 channel 的回调**：SPI 回调通过标准库 `mpsc::channel` 投递。
- **可独立选择 fast 行情/交易库**（见下）。

## 快速开始

```sh
cargo build --examples
cargo run --example xmd_api      # Level-1 行情
cargo run --example trader_api   # 交易
```

绑定层（`src/lib.rs` 与 `wrapper/`）由
[`tora-rs-generator`](../tora-rs-generator) 从官方 TORA 头文件生成；`build.rs`、
`Cargo.toml` 与 `lib/` 下的 SDK 为手写/随仓库提供。

## Fast 变体

TORA 为交易与 Level-1 行情各提供一个低延迟「fast」实现。它们与标准库
**ABI 完全一致**（导出相同的 `CTORATstp*Api` 符号），因此切换只是改变链接的动态库。
通过 Cargo feature 独立选择：

| Feature        | 交易库链接        | 行情库链接（XMd） |
| -------------- | ----------------- | ----------------- |
| *(默认)*       | `traderapi`       | `xmdapi`          |
| `fast-trader`  | **`fasttraderapi`** | `xmdapi`        |
| `fast-xmd`     | `traderapi`       | **`xfastmdapi`**  |
| `fast`         | **`fasttraderapi`** | **`xfastmdapi`** |

```sh
cargo build --features fast-xmd                 # 只让行情走 fast
cargo build --features fast-trader              # 只让交易走 fast
cargo build --features fast-xmd,fast-trader     # 两者都 fast（等价于 --features fast）
```

Level-2 行情（`lev2md`）无 fast 变体，始终链接 `lev2mdapi`。

## SDK 与构建

- SDK（头文件 + Linux `.so` + Windows `.dll`/`.lib`）直接随仓库存放于 `lib/`，
  构建时无需下载。
- `build.rs` 把所链接的动态库复制到可执行文件同目录，Linux 下并设置
  `-rpath,$ORIGIN`，因此产出的二进制可直接运行。
- 需要 C++ 编译器（Linux: g++；Windows: MSVC）。Linux 的 GBK 转换走 glibc 自带的
  `iconv(3)`，无需额外依赖。

### 在 macOS 上构建

TORA 不提供 macOS 库，无法在 macOS 主机上直接链接。仓库内提供
[`Dockerfile`](./Dockerfile)（固定 `linux/amd64`）用于在任意主机上验证构建：

```sh
docker build --platform=linux/amd64 -t tora-rs .
```

它会以默认及全部 fast 组合编译库与示例，验证 xmd / trader 的 fast 变体可独立启用。

## 注意事项

- TORA 回报为空指针时，对应 Field 的 `is_null` 字段为 `true`。
- 字段名保持 TORA 原始命名（`#![allow(non_snake_case)]`）。
