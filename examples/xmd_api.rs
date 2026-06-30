//! Level-1 行情接口（XMd）示例。
//!
//! 运行：`cargo run --example xmd_api`
//! 使用 fast 行情库：`cargo run --example xmd_api --features fast-xmd`
//!
//! 模拟环境地址见 <https://n-sight.com.cn/>。

use std::sync::{Arc, mpsc::channel};
use tora_rs::xmd::{ReqUserLoginField, TORA_TSTP_EXD_SSE, TORA_TSTP_MST_TCP, XMdApi, XMdSpiMsg};

const FRONT_ADDR: &str = "tcp://210.14.72.21:4402";
// 沪市证券代码（上交所）。
const SECURITIES: &[&str] = &["600000", "601398"];

fn main() {
    let (tx, rx) = channel();

    // CreateXMdApiAndSpi(tx, md_sub_mode, derive_md_sub_mode)
    let api = Arc::new(XMdApi::CreateXMdApiAndSpi(
        tx,
        TORA_TSTP_MST_TCP,
        TORA_TSTP_MST_TCP,
    ));
    api.RegisterFront(FRONT_ADDR.to_string());
    // 不绑定 CPU 核心。
    api.Init(String::new());

    loop {
        match rx.recv().unwrap() {
            XMdSpiMsg::OnFrontConnected => {
                println!("front connected");
                api.ReqUserLogin(ReqUserLoginField::default(), 1);
            }
            XMdSpiMsg::OnRspUserLogin(_login, rsp_info, _req_id) => {
                if rsp_info.ErrorID != 0 {
                    println!("login failed: {:?}", rsp_info);
                    continue;
                }
                println!("login success");
                let ids: Vec<String> = SECURITIES.iter().map(|s| s.to_string()).collect();
                api.SubscribeMarketData(ids, TORA_TSTP_EXD_SSE);
            }
            XMdSpiMsg::OnRtnMarketData(tick) => {
                println!("{:?}", tick);
            }
            _ => {}
        }
    }
}
