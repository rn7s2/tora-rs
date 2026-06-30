//! 交易接口（Trader）示例。
//!
//! 运行：`cargo run --example trader_api`
//! 使用 fast 交易库：`cargo run --example trader_api --features fast-trader`
//!
//! 模拟环境地址见 <https://n-sight.com.cn/>。

use std::sync::{Arc, mpsc::channel};
use tora_rs::trader::{
    QrySecurityField, ReqUserLoginField, TORA_TE_RESUME_TYPE, TORA_TSTP_TCM_TCP, TraderApi,
    TraderSpiMsg,
};

const FRONT_ADDR: &str = "tcp://210.14.72.21:4400";
const FLOW_PATH: &str = "TraderFlow/";
const LOGIN_ACCOUNT: &str = "...";
const PASSWORD: &str = "...";

fn main() {
    let (tx, rx) = channel();

    // CreateTraderApiAndSpi(tx, flow_path, is_encrypt, trade_comm_mode,
    //                       interface_addr, is_using_order_ex)
    let api = Arc::new(TraderApi::CreateTraderApiAndSpi(
        tx,
        FLOW_PATH.to_string(),
        false,
        TORA_TSTP_TCM_TCP,
        String::new(),
        false,
    ));
    api.RegisterFront(FRONT_ADDR.to_string());
    api.SubscribePublicTopic(TORA_TE_RESUME_TYPE::TORA_TERT_QUICK as i32);
    api.SubscribePrivateTopic(TORA_TE_RESUME_TYPE::TORA_TERT_QUICK as i32);
    api.Init();

    loop {
        match rx.recv().unwrap() {
            TraderSpiMsg::OnFrontConnected => {
                println!("front connected");
                let req = ReqUserLoginField {
                    LogInAccount: LOGIN_ACCOUNT.to_string(),
                    Password: PASSWORD.to_string(),
                    ..Default::default()
                };
                api.ReqUserLogin(req, 1);
            }
            TraderSpiMsg::OnRspUserLogin(_login, rsp_info, _req_id) => {
                if rsp_info.ErrorID != 0 {
                    println!("login failed: {:?}", rsp_info);
                    std::process::exit(1);
                }
                println!("login success");
                api.ReqQrySecurity(QrySecurityField::default(), 2);
            }
            TraderSpiMsg::OnRspQrySecurity(security, rsp_info, _req_id, is_last) => {
                if security.is_null {
                    println!("qry security done: {:?}", rsp_info);
                    continue;
                }
                println!("security (last={is_last}): {:?}", security);
            }
            _ => {}
        }
    }
}
