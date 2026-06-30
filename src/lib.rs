//! TORA STP（华鑫奇点交易系统）C++ 接口的 Rust 绑定。
//!
//! 由官方 TORA 头文件生成；结构体字段名称与 TORA 原始命名保持一致。
//!
//! # [`trader`] — 交易接口（namespace `TORASTOCKAPI`）
//!
//! 通过 [`trader::TraderApi::CreateTraderApiAndSpi`] 创建实例，传入一个
//! [`std::sync::mpsc::Sender`] 用于接收 [`trader::TraderSpiMsg`] 回调消息。
//!
//! # [`xmd`] — Level-1 行情接口（namespace `TORALEV1API`）
//!
//! 通过 [`xmd::XMdApi::CreateXMdApiAndSpi`] 创建实例，传入一个
//! [`std::sync::mpsc::Sender`] 用于接收 [`xmd::XMdSpiMsg`] 回调消息。
//!
//! # [`lev2md`] — Level-2 行情接口（namespace `TORALEV2API`）
//!
//! 通过 [`lev2md::Lev2MdApi::CreateLev2MdApiAndSpi`] 创建实例，传入一个
//! [`std::sync::mpsc::Sender`] 用于接收 [`lev2md::Lev2MdSpiMsg`] 回调消息。

#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]
#![allow(dead_code)]

pub mod trader;
pub mod xmd;
pub mod lev2md;
