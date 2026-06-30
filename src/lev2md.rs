#[allow(unused_imports)]
use std::fs::create_dir_all;
#[allow(unused_imports)]
use std::path::Path;
use std::sync::mpsc::Sender;
pub use ffi::*;
pub type UniquePtr<T> = cxx::UniquePtr<T>;

/// //////////////////////////////////////////////////////////////////////
/// TTORATstpExchangeIDType是一个交易所代码类型
/// //////////////////////////////////////////////////////////////////////
/// 通用(内部使用)
pub const TORA_TSTP_EXD_COMM: u8 = '0' as u8;
/// 上海交易所
pub const TORA_TSTP_EXD_SSE: u8 = '1' as u8;
/// 深圳交易所
pub const TORA_TSTP_EXD_SZSE: u8 = '2' as u8;
/// 香港交易所
pub const TORA_TSTP_EXD_HK: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpAuthModeType是一个认证方式类型
/// //////////////////////////////////////////////////////////////////////
/// 密码
pub const TORA_TSTP_AM_Password: u8 = '0' as u8;
/// 指纹
pub const TORA_TSTP_AM_FingerPrint: u8 = '1' as u8;
/// 钥匙串
pub const TORA_TSTP_AM_CertInfo: u8 = '2' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpMDSubModeType是一个行情订阅模式类型
/// //////////////////////////////////////////////////////////////////////
/// TCP连接模式
pub const TORA_TSTP_MST_TCP: u8 = '0' as u8;
/// UDP单播模式
pub const TORA_TSTP_MST_UDP: u8 = '1' as u8;
/// UDP组播模式
pub const TORA_TSTP_MST_MCAST: u8 = '2' as u8;
/// 预留
pub const TORA_TSTP_MST_DMA: u8 = '3' as u8;
/// PROXY模式
pub const TORA_TSTP_MST_PROXY: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpUserTypeType是一个用户类型类型
/// //////////////////////////////////////////////////////////////////////
/// 经纪公司用户
pub const TORA_TSTP_UTYPE_BrokerUser: u8 = '0' as u8;
/// 超级用户
pub const TORA_TSTP_UTYPE_SuperUser: u8 = '1' as u8;
/// 投资者用户
pub const TORA_TSTP_UTYPE_Investor: u8 = '2' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpLogInAccountTypeType是一个登录账户类型类型
/// //////////////////////////////////////////////////////////////////////
/// 用户代码
pub const TORA_TSTP_LACT_UserID: u8 = '0' as u8;
/// 资金账号
pub const TORA_TSTP_LACT_AccountID: u8 = '1' as u8;
/// 上海A股
pub const TORA_TSTP_LACT_SHAStock: u8 = '2' as u8;
/// 深圳A股
pub const TORA_TSTP_LACT_SZAStock: u8 = '3' as u8;
/// 上海B股
pub const TORA_TSTP_LACT_SHBStock: u8 = '4' as u8;
/// 深圳B股
pub const TORA_TSTP_LACT_SZBStock: u8 = '5' as u8;
/// 三板A
pub const TORA_TSTP_LACT_ThreeNewBoardA: u8 = '6' as u8;
/// 三板B
pub const TORA_TSTP_LACT_ThreeNewBoardB: u8 = '7' as u8;
/// 港股
pub const TORA_TSTP_LACT_HKStock: u8 = '8' as u8;
/// 统一用户代码
pub const TORA_TSTP_LACT_UnifiedUserID: u8 = '9' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpMKSubTypeType是一个行情订阅类别类型
/// //////////////////////////////////////////////////////////////////////
/// 快照行情
pub const TORA_TSTP_MKST_MarketData: u8 = 'M' as u8;
/// 指数
pub const TORA_TSTP_MKST_Index: u8 = 'I' as u8;
/// 逐笔成交
pub const TORA_TSTP_MKST_Transaction: u8 = 'T' as u8;
/// 逐笔委托
pub const TORA_TSTP_MKST_OrderDetail: u8 = 'O' as u8;
/// 盘后定价行情
pub const TORA_TSTP_MKST_PHMarketData: u8 = 'H' as u8;
/// 盘后定价逐笔成交
pub const TORA_TSTP_MKST_PHTransaction: u8 = 'P' as u8;
/// 逐笔重传成交
pub const TORA_TSTP_MKST_ResendTransaction: u8 = 'R' as u8;
/// 逐笔重传委托
pub const TORA_TSTP_MKST_ResendOrderDetail: u8 = 'D' as u8;
/// 债券快照行情(上海)
pub const TORA_TSTP_MKST_XTSMarketData: u8 = 'X' as u8;
/// 债券逐笔行情(上海)
pub const TORA_TSTP_MKST_XTSTick: u8 = 'K' as u8;
/// 债券快照行情
pub const TORA_TSTP_MKST_BondMarketData: u8 = 'U' as u8;
/// 债券逐笔成交
pub const TORA_TSTP_MKST_BondTransaction: u8 = 'W' as u8;
/// 债券逐笔委托
pub const TORA_TSTP_MKST_BondOrderDetail: u8 = 'V' as u8;
/// 逐笔合并行情(上海)
pub const TORA_TSTP_MKST_NGTSTick: u8 = 'N' as u8;
/// IOPV独立行情
pub const TORA_TSTP_MKST_IOPV: u8 = 'Q' as u8;
/// Ex指数
pub const TORA_TSTP_MKST_ExIndex: u8 = 'E' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpLOrderTypeType是一个订单类别类型
/// //////////////////////////////////////////////////////////////////////
/// 市价
pub const TORA_TSTP_LOT_Market: u8 = '1' as u8;
/// 限价
pub const TORA_TSTP_LOT_Limit: u8 = '2' as u8;
/// 本方最优
pub const TORA_TSTP_LOT_HomeBest: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpLSideType是一个委托方向类型
/// //////////////////////////////////////////////////////////////////////
/// 买
pub const TORA_TSTP_LSD_Buy: u8 = '1' as u8;
/// 卖
pub const TORA_TSTP_LSD_Sell: u8 = '2' as u8;
/// 借入
pub const TORA_TSTP_LSD_Borrow: u8 = '3' as u8;
/// 借出
pub const TORA_TSTP_LSD_Lend: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpExecTypeType是一个成交类别类型
/// //////////////////////////////////////////////////////////////////////
/// 成交
pub const TORA_TSTP_ECT_Fill: u8 = '1' as u8;
/// 撤销
pub const TORA_TSTP_ECT_Cancel: u8 = '2' as u8;
/// 未知
pub const TORA_TSTP_ECT_Unknown: u8 = 'N' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpLOrderStatusType是一个订单状态类型
/// //////////////////////////////////////////////////////////////////////
/// 新增
pub const TORA_TSTP_LOS_Add: u8 = 'A' as u8;
/// 删除
pub const TORA_TSTP_LOS_Delete: u8 = 'D' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpMDSecurityStatType是一个行情证券状态类型
/// //////////////////////////////////////////////////////////////////////
/// 开盘前
pub const TORA_TSTP_MSST_PreOpen: u8 = '0' as u8;
/// 集合竞价
pub const TORA_TSTP_MSST_CallAuction: u8 = '1' as u8;
/// 连续交易
pub const TORA_TSTP_MSST_Continous: u8 = '2' as u8;
/// 休市
pub const TORA_TSTP_MSST_Pause: u8 = '3' as u8;
/// 停牌
pub const TORA_TSTP_MSST_Suspend: u8 = '4' as u8;
/// 长期停牌
pub const TORA_TSTP_MSST_LongSuspend: u8 = '5' as u8;
/// 波动性中断
pub const TORA_TSTP_MSST_UndulationInt: u8 = '6' as u8;
/// 熔断可恢复
pub const TORA_TSTP_MSST_CircuitBreak: u8 = '7' as u8;
/// 熔断不可恢复
pub const TORA_TSTP_MSST_CircuitBreakU: u8 = '8' as u8;
/// 闭市
pub const TORA_TSTP_MSST_Close: u8 = '9' as u8;
/// 其它
pub const TORA_TSTP_MSST_Other: u8 = 'a' as u8;
/// 收盘集合竞价
pub const TORA_TSTP_MSST_CloseCallAuction: u8 = 'b' as u8;
/// 集中撮合(盘后定价)
pub const TORA_TSTP_MSST_CallMatch: u8 = 'c' as u8;
/// 连续交易(盘后定价)
pub const TORA_TSTP_MSST_PostContinous: u8 = 'd' as u8;
/// 闭市(盘后定价)
pub const TORA_TSTP_MSST_PostClose: u8 = 'e' as u8;
/// 开盘前(盘后定价)
pub const TORA_TSTP_MSST_PrePostOpen: u8 = 'f' as u8;
/// 未上市
pub const TORA_TSTP_MSST_Unlisted: u8 = 'g' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpTradeBSFlagType是一个内外盘标志类型
/// //////////////////////////////////////////////////////////////////////
/// 外盘,主动买
pub const TORA_TSTP_TBSF_Buy: u8 = 'B' as u8;
/// 内盘,主动卖
pub const TORA_TSTP_TBSF_Sell: u8 = 'S' as u8;
/// 未知
pub const TORA_TSTP_TBSF_Unknown: u8 = 'N' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpLTickTypeType是一个逐笔类型类型
/// //////////////////////////////////////////////////////////////////////
/// 新增委托订单
pub const TORA_TSTP_LTT_Add: u8 = 'A' as u8;
/// 删除委托订单
pub const TORA_TSTP_LTT_Delete: u8 = 'D' as u8;
/// 产品状态订单
pub const TORA_TSTP_LTT_Status: u8 = 'S' as u8;
/// 成交
pub const TORA_TSTP_LTT_Trade: u8 = 'T' as u8;

unsafe impl Send for Lev2MdApi {}
unsafe impl Sync for Lev2MdApi {}

impl Lev2MdApi {
    pub fn CreateLev2MdApiAndSpi(tx: Sender<Lev2MdSpiMsg>, md_sub_mode: u8, cached_mode: bool) -> UniquePtr<Lev2MdApi> {
        CreateLev2MdApi(Box::new(Lev2MdSpi { tx }), md_sub_mode, cached_mode)
    }
}

#[derive(Debug, Clone)]
pub enum Lev2MdSpiMsg {
    OnFrontConnected,
    OnFrontDisconnected(i32),
    OnRspError(Box<RspInfoField>, i32, bool),
    OnRspUserLogin(Box<RspUserLoginField>, Box<RspInfoField>, i32, bool),
    OnRspUserLogout(Box<UserLogoutField>, Box<RspInfoField>, i32, bool),
    OnRspSubMarketData(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubMarketData(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubIndex(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubIndex(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubTransaction(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubTransaction(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubOrderDetail(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubOrderDetail(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubPHMarketData(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubPHMarketData(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubPHTransaction(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubPHTransaction(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubResendTransaction(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubResendTransaction(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubResendOrderDetail(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubResendOrderDetail(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubXTSMarketData(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubXTSMarketData(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubXTSTick(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubXTSTick(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubNGTSTick(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubNGTSTick(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubBondMarketData(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubBondMarketData(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubBondTransaction(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubBondTransaction(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubBondOrderDetail(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubBondOrderDetail(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspSubIOPV(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRspUnSubIOPV(Box<SpecificSecurityField>, Box<RspInfoField>, i32, bool),
    OnRtnMarketData(Box<Lev2MarketDataField>, i32, Vec<i32>, i32, Vec<i32>),
    OnRtnIndex(Box<Lev2IndexField>),
    OnRtnTransaction(Box<Lev2TransactionField>),
    OnRtnOrderDetail(Box<Lev2OrderDetailField>),
    OnRtnPHMarketData(Box<Lev2PHMarketDataField>, i32, Vec<i32>, i32, Vec<i32>),
    OnRtnPHTransaction(Box<Lev2PHTransactionField>),
    OnRtnResendTransaction(Box<Lev2ResendTransactionField>),
    OnRtnResendOrderDetail(Box<Lev2ResendOrderDetailField>),
    OnRtnXTSMarketData(Box<Lev2XTSMarketDataField>, i32, Vec<i32>, i32, Vec<i32>),
    OnRtnXTSTick(Box<Lev2XTSTickField>),
    OnRtnNGTSTick(Box<Lev2NGTSTickField>),
    OnRtnBondMarketData(Box<Lev2BondMarketDataField>, i32, Vec<i32>, i32, Vec<i32>),
    OnRtnBondTransaction(Box<Lev2BondTransactionField>),
    OnRtnBondOrderDetail(Box<Lev2BondOrderDetailField>),
    OnRtnIOPV(Box<Lev2IOPVField>),
}

pub struct Lev2MdSpi {
    tx: Sender<Lev2MdSpiMsg>,
}

impl Lev2MdSpi {
    pub fn OnFrontConnected(&self) { self.tx.send(Lev2MdSpiMsg::OnFrontConnected).ok(); }
    pub fn OnFrontDisconnected(&self, nReason: i32) { self.tx.send(Lev2MdSpiMsg::OnFrontDisconnected(nReason)).ok(); }
    pub fn OnRspError(&self, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspError(Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUserLogin(&self, pRspUserLogin: RspUserLoginField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUserLogin(Box::new(pRspUserLogin), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUserLogout(&self, pUserLogout: UserLogoutField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUserLogout(Box::new(pUserLogout), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubMarketData(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubMarketData(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubIndex(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubIndex(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubIndex(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubIndex(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubTransaction(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubTransaction(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubOrderDetail(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubOrderDetail(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubPHMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubPHMarketData(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubPHMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubPHMarketData(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubPHTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubPHTransaction(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubPHTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubPHTransaction(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubResendTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubResendTransaction(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubResendTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubResendTransaction(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubResendOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubResendOrderDetail(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubResendOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubResendOrderDetail(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubXTSMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubXTSMarketData(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubXTSMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubXTSMarketData(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubXTSTick(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubXTSTick(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubXTSTick(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubXTSTick(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubNGTSTick(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubNGTSTick(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubNGTSTick(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubNGTSTick(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubBondMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubBondMarketData(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubBondMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubBondMarketData(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubBondTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubBondTransaction(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubBondTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubBondTransaction(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubBondOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubBondOrderDetail(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubBondOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubBondOrderDetail(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubIOPV(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspSubIOPV(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRspUnSubIOPV(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(Lev2MdSpiMsg::OnRspUnSubIOPV(Box::new(pSpecificSecurity), Box::new(pRspInfo), nRequestID, bIsLast)).ok(); }
    pub fn OnRtnMarketData(&self, pMarketData: Lev2MarketDataField, FirstLevelBuyNum: i32, FirstLevelBuyOrderVolumes: Vec<i32>, FirstLevelSellNum: i32, FirstLevelSellOrderVolumes: Vec<i32>) { self.tx.send(Lev2MdSpiMsg::OnRtnMarketData(Box::new(pMarketData), FirstLevelBuyNum, FirstLevelBuyOrderVolumes, FirstLevelSellNum, FirstLevelSellOrderVolumes)).ok(); }
    pub fn OnRtnIndex(&self, pIndex: Lev2IndexField) { self.tx.send(Lev2MdSpiMsg::OnRtnIndex(Box::new(pIndex))).ok(); }
    pub fn OnRtnTransaction(&self, pTransaction: Lev2TransactionField) { self.tx.send(Lev2MdSpiMsg::OnRtnTransaction(Box::new(pTransaction))).ok(); }
    pub fn OnRtnOrderDetail(&self, pOrderDetail: Lev2OrderDetailField) { self.tx.send(Lev2MdSpiMsg::OnRtnOrderDetail(Box::new(pOrderDetail))).ok(); }
    pub fn OnRtnPHMarketData(&self, pPHMarketData: Lev2PHMarketDataField, FirstLevelBuyNum: i32, FirstLevelBuyOrderVolumes: Vec<i32>, FirstLevelSellNum: i32, FirstLevelSellOrderVolumes: Vec<i32>) { self.tx.send(Lev2MdSpiMsg::OnRtnPHMarketData(Box::new(pPHMarketData), FirstLevelBuyNum, FirstLevelBuyOrderVolumes, FirstLevelSellNum, FirstLevelSellOrderVolumes)).ok(); }
    pub fn OnRtnPHTransaction(&self, pTransaction: Lev2PHTransactionField) { self.tx.send(Lev2MdSpiMsg::OnRtnPHTransaction(Box::new(pTransaction))).ok(); }
    pub fn OnRtnResendTransaction(&self, pTransaction: Lev2ResendTransactionField) { self.tx.send(Lev2MdSpiMsg::OnRtnResendTransaction(Box::new(pTransaction))).ok(); }
    pub fn OnRtnResendOrderDetail(&self, pOrderDetail: Lev2ResendOrderDetailField) { self.tx.send(Lev2MdSpiMsg::OnRtnResendOrderDetail(Box::new(pOrderDetail))).ok(); }
    pub fn OnRtnXTSMarketData(&self, pMarketData: Lev2XTSMarketDataField, FirstLevelBuyNum: i32, FirstLevelBuyOrderVolumes: Vec<i32>, FirstLevelSellNum: i32, FirstLevelSellOrderVolumes: Vec<i32>) { self.tx.send(Lev2MdSpiMsg::OnRtnXTSMarketData(Box::new(pMarketData), FirstLevelBuyNum, FirstLevelBuyOrderVolumes, FirstLevelSellNum, FirstLevelSellOrderVolumes)).ok(); }
    pub fn OnRtnXTSTick(&self, pTick: Lev2XTSTickField) { self.tx.send(Lev2MdSpiMsg::OnRtnXTSTick(Box::new(pTick))).ok(); }
    pub fn OnRtnNGTSTick(&self, pTick: Lev2NGTSTickField) { self.tx.send(Lev2MdSpiMsg::OnRtnNGTSTick(Box::new(pTick))).ok(); }
    pub fn OnRtnBondMarketData(&self, pMarketData: Lev2BondMarketDataField, FirstLevelBuyNum: i32, FirstLevelBuyOrderVolumes: Vec<i32>, FirstLevelSellNum: i32, FirstLevelSellOrderVolumes: Vec<i32>) { self.tx.send(Lev2MdSpiMsg::OnRtnBondMarketData(Box::new(pMarketData), FirstLevelBuyNum, FirstLevelBuyOrderVolumes, FirstLevelSellNum, FirstLevelSellOrderVolumes)).ok(); }
    pub fn OnRtnBondTransaction(&self, pTransaction: Lev2BondTransactionField) { self.tx.send(Lev2MdSpiMsg::OnRtnBondTransaction(Box::new(pTransaction))).ok(); }
    pub fn OnRtnBondOrderDetail(&self, pOrderDetail: Lev2BondOrderDetailField) { self.tx.send(Lev2MdSpiMsg::OnRtnBondOrderDetail(Box::new(pOrderDetail))).ok(); }
    pub fn OnRtnIOPV(&self, pIOPV: Lev2IOPVField) { self.tx.send(Lev2MdSpiMsg::OnRtnIOPV(Box::new(pIOPV))).ok(); }
}

#[cxx::bridge(namespace = "tora_lev2md")]
mod ffi {
    extern "Rust" {
        type Lev2MdSpi;
        pub fn OnFrontConnected(&self);
        pub fn OnFrontDisconnected(&self, nReason: i32);
        pub fn OnRspError(&self, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUserLogin(&self, pRspUserLogin: RspUserLoginField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUserLogout(&self, pUserLogout: UserLogoutField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubIndex(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubIndex(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubPHMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubPHMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubPHTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubPHTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubResendTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubResendTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubResendOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubResendOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubXTSMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubXTSMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubXTSTick(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubXTSTick(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubNGTSTick(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubNGTSTick(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubBondMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubBondMarketData(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubBondTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubBondTransaction(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubBondOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubBondOrderDetail(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubIOPV(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspUnSubIOPV(&self, pSpecificSecurity: SpecificSecurityField, pRspInfo: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRtnMarketData(&self, pMarketData: Lev2MarketDataField, FirstLevelBuyNum: i32, FirstLevelBuyOrderVolumes: Vec<i32>, FirstLevelSellNum: i32, FirstLevelSellOrderVolumes: Vec<i32>);
        pub fn OnRtnIndex(&self, pIndex: Lev2IndexField);
        pub fn OnRtnTransaction(&self, pTransaction: Lev2TransactionField);
        pub fn OnRtnOrderDetail(&self, pOrderDetail: Lev2OrderDetailField);
        pub fn OnRtnPHMarketData(&self, pPHMarketData: Lev2PHMarketDataField, FirstLevelBuyNum: i32, FirstLevelBuyOrderVolumes: Vec<i32>, FirstLevelSellNum: i32, FirstLevelSellOrderVolumes: Vec<i32>);
        pub fn OnRtnPHTransaction(&self, pTransaction: Lev2PHTransactionField);
        pub fn OnRtnResendTransaction(&self, pTransaction: Lev2ResendTransactionField);
        pub fn OnRtnResendOrderDetail(&self, pOrderDetail: Lev2ResendOrderDetailField);
        pub fn OnRtnXTSMarketData(&self, pMarketData: Lev2XTSMarketDataField, FirstLevelBuyNum: i32, FirstLevelBuyOrderVolumes: Vec<i32>, FirstLevelSellNum: i32, FirstLevelSellOrderVolumes: Vec<i32>);
        pub fn OnRtnXTSTick(&self, pTick: Lev2XTSTickField);
        pub fn OnRtnNGTSTick(&self, pTick: Lev2NGTSTickField);
        pub fn OnRtnBondMarketData(&self, pMarketData: Lev2BondMarketDataField, FirstLevelBuyNum: i32, FirstLevelBuyOrderVolumes: Vec<i32>, FirstLevelSellNum: i32, FirstLevelSellOrderVolumes: Vec<i32>);
        pub fn OnRtnBondTransaction(&self, pTransaction: Lev2BondTransactionField);
        pub fn OnRtnBondOrderDetail(&self, pOrderDetail: Lev2BondOrderDetailField);
        pub fn OnRtnIOPV(&self, pIOPV: Lev2IOPVField);
    }

    unsafe extern "C++" {
        include!("tora-rs/wrapper/include/Lev2MdApi.h");
        type Lev2MdApi;
        fn CreateLev2MdApi(spi: Box<Lev2MdSpi>, md_sub_mode: u8, cached_mode: bool) -> UniquePtr<Lev2MdApi>;
        /// 获取API版本号
        ///
        /// # Returns
        /// 版本号
        fn GetApiVersion(&self) -> String;
        /// # Remarks
        /// 初始化运行环境,只有调用后,接口才开始工作
        fn Init(&self, cpuCores: String);
        /// 等待接口线程结束运行
        ///
        /// # Returns
        /// 线程退出代码
        fn Join(&self) -> i32;
        /// 注册前置机网络地址
        ///
        /// # Parameters
        /// - `pszFrontAddress` — 前置机网络地址。
        ///
        /// # Remarks
        /// 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
        /// “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
        fn RegisterFront(&self, pszFrontAddress: String);
        /// 注册名字服务器网络地址
        ///
        /// # Parameters
        /// - `pszNsAddress` — 名字服务器网络地址。
        ///
        /// # Remarks
        /// 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
        /// “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
        /// RegisterFront/RegisterMulticast与RegisterNameServer二选一
        fn RegisterNameServer(&self, pszNsAddress: String);
        /// 注册组播地址
        ///
        /// # Parameters
        /// - `pszMulticastAddress` — 组播网络地址,如:"udp://224.3.9.110:34567"。
        /// - `pszInterfaceIP` — 接收网卡地址,如:"127.0.0.1",填NULL则依次轮询尝试本机所有网卡加入组播组。
        /// - `pszSourceIp` — 组播数据包源地址,如:"127.0.0.1",填NULL表示不校验数据包源。
        /// - `pInterfaceName` — 接收网卡名,如enp101s0f1,efvi接收时有意义
        /// - `rxqCapacity` — 接收队列大小,rxqCapacity<=0 则取默认值，（512，1024，2048，4096),efvi接收时有意义
        /// - `bEFVI` — EFVI接收模式开关(linux)
        ///
        /// # Remarks
        /// 在使用UDP组播方式工作时调用
        fn RegisterMulticast(&self, pszMulticastAddress: String, pszInterfaceIP: String, pszSourceIp: String, pInterfaceName: String, rxqCapacity: i32, bEFVI: bool);
        /// 订阅行情。（上海非债券类、深圳非债券类、深圳可转债）
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeMarketData(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订行情。（上海非债券类、深圳非债券类、深圳可转债）
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeMarketData(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅指数行情。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeIndex(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订指数行情。
        ///
        /// # Parameters
        /// - `ppInstrumentID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeIndex(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅逐笔成交。（深圳非债券类、深圳可转债）
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeTransaction(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订逐笔成交。（深圳非债券类、深圳可转债）
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeTransaction(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅逐笔委托。（深圳非债券类、深圳可转债）
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeOrderDetail(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订逐笔委托。（深圳非债券类、深圳可转债）
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeOrderDetail(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅盘后定价行情。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribePHMarketData(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订盘后定价行情。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribePHMarketData(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅盘后定价逐笔成交。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribePHTransaction(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订盘后定价逐笔成交。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribePHTransaction(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅逐笔重传成交。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeResendTransaction(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订逐笔重传成交。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeResendTransaction(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅逐笔重传委托。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeResendOrderDetail(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订逐笔重传委托。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeResendOrderDetail(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅上海XTS债券行情。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeXTSMarketData(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订上海XTS债券行情。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeXTSMarketData(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅上海XTS债券逐笔行情。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeXTSTick(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订上海XTS债券逐笔行情。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeXTSTick(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅上海NGTS上海非债券类逐笔行情。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeNGTSTick(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订上海NGTS上海非债券类、逐笔行情。
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeNGTSTick(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅深圳债券(不包含可转债)快照行情
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeBondMarketData(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订深圳债券(不包含可转债)快照行情
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeBondMarketData(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅深圳债券(不包含可转债)逐笔成交
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeBondTransaction(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订深圳债券(不包含可转债)逐笔成交
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeBondTransaction(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅深圳债券(不包含可转债)逐笔委托
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeBondOrderDetail(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订深圳债券(不包含可转债)逐笔委托
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeBondOrderDetail(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 订阅IOPV独立行情
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn SubscribeIOPV(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 退订IOPV独立行情
        ///
        /// # Parameters
        /// - `ppSecurityID` — 合约ID
        /// - `nCount` — 要订阅/退订行情的合约个数
        fn UnSubscribeIOPV(&self, ppSecurityID: Vec<String>, ExchageID: u8) -> i32;
        /// 用户登录请求
        fn ReqUserLogin(&self, pReqUserLoginField: ReqUserLoginField, nRequestID: i32) -> i32;
        /// 登出请求
        fn ReqUserLogout(&self, pUserLogout: UserLogoutField, nRequestID: i32) -> i32;
    }
    /// fens用户信息
    #[derive(Debug, Clone, Default)]
    struct FensUserInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 登录账户
        LogInAccount: String,
        /// 登录账户类型
        LogInAccountType: u8,
    }
    /// 登录请求
    #[derive(Debug, Clone, Default)]
    struct ReqUserLoginField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 登录账户
        LogInAccount: String,
        /// 登录账户类型
        LogInAccountType: u8,
        /// 密码(密码认证时必填)
        Password: String,
        /// 用户端产品信息
        UserProductInfo: String,
        /// 接口端产品信息
        InterfaceProductInfo: String,
        /// 协议信息
        ProtocolInfo: String,
        /// Mac地址
        MacAddress: String,
        /// 移动设备手机号
        Mobile: String,
        /// 内网IP地址
        InnerIPAddress: String,
        /// 接口语言
        Lang: Vec<u8>,
        /// 终端信息
        TerminalInfo: String,
        /// 网关Mac地址
        GWMacAddress: String,
        /// 网关内网IP地址
        GWInnerIPAddress: String,
        /// 网关外网IP地址
        GWOuterIPAddress: String,
        /// 一级机构代码（以资金账号方式登录时必填）
        DepartmentID: String,
        /// 硬盘序列号
        HDSerial: String,
        /// 认证方式(指纹或钥匙串认证时必填)
        AuthMode: u8,
        /// 设备标识(指纹认证时必填)
        DeviceID: String,
        /// 认证序列号(指纹或钥匙串认证时必填)
        CertSerial: String,
        /// 外网IP地址
        OuterIPAddress: String,
        /// 动态密码
        DynamicPassword: String,
        /// 外网端口号
        OuterPort: i32,
    }
    /// 登录应答
    #[derive(Debug, Clone, Default)]
    struct RspUserLoginField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 登录时间
        LoginTime: String,
        /// 登录账户
        LogInAccount: String,
        /// 登录账户类型
        LogInAccountType: u8,
        /// 交易系统名称
        SystemName: String,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 最大报单引用
        MaxOrderRef: String,
        /// 私有流长度
        PrivateFlowCount: i32,
        /// 公有流长度
        PublicFlowCount: i32,
        /// 交易日
        TradingDay: String,
        /// 用户代码
        UserID: String,
        /// 用户名称
        UserName: String,
        /// 用户类型
        UserType: u8,
        /// 一级机构代码
        DepartmentID: String,
        /// 终端IP地址
        InnerIPAddress: String,
        /// Mac地址
        MacAddress: String,
        /// 硬盘序列号
        HDSerial: String,
        /// 报单流控
        OrderInsertCommFlux: i32,
        /// 密码修改周期(天),置为0表永久有效
        PasswordUpdatePeriod: i32,
        /// 密码有效剩余天数
        PasswordRemainDays: i32,
        /// 是否需要改密
        NeedUpdatePassword: i32,
        /// 撤单流控
        OrderActionCommFlux: i32,
        /// 移动设备手机号
        Mobile: String,
        /// 外网IP地址
        OuterIPAddress: String,
        /// 认证序列号
        CertSerial: String,
        /// 外网端口号
        OuterPort: i32,
    }
    /// 响应信息
    #[derive(Debug, Clone, Default)]
    struct RspInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 错误代码
        ErrorID: i32,
        /// 错误信息
        ErrorMsg: String,
    }
    /// 用户登出
    #[derive(Debug, Clone, Default)]
    struct UserLogoutField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户代码
        UserID: String,
    }
    /// 订阅行情
    #[derive(Debug, Clone, Default)]
    struct SpecificSecurityField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
    }
    /// Lev2行情
    #[derive(Debug, Clone, Default)]
    struct Lev2MarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 行情交易所代码
        ExchangeID: u8,
        /// 时间戳
        DataTimeStamp: i32,
        /// 昨收盘
        PreClosePrice: f64,
        /// 今开盘
        OpenPrice: f64,
        /// 成交笔数
        NumTrades: i64,
        /// 成交总量
        TotalVolumeTrade: i64,
        /// 成交总金额
        TotalValueTrade: f64,
        /// 委托买入总量
        TotalBidVolume: i64,
        /// 加权平均委托买价格
        AvgBidPrice: f64,
        /// 委托卖出总量
        TotalAskVolume: i64,
        /// 加权平均委托卖价格
        AvgAskPrice: f64,
        /// 最高价
        HighestPrice: f64,
        /// 最低价
        LowestPrice: f64,
        /// 现价
        LastPrice: f64,
        /// 申买价一
        BidPrice1: f64,
        /// 申买量一
        BidVolume1: i64,
        /// 申卖价一
        AskPrice1: f64,
        /// 申卖量一
        AskVolume1: i64,
        /// 申卖价二
        AskPrice2: f64,
        /// 申卖量二
        AskVolume2: i64,
        /// 申卖价三
        AskPrice3: f64,
        /// 申卖量三
        AskVolume3: i64,
        /// 申买价二
        BidPrice2: f64,
        /// 申买量二
        BidVolume2: i64,
        /// 申买价三
        BidPrice3: f64,
        /// 申买量三
        BidVolume3: i64,
        /// 申卖价四
        AskPrice4: f64,
        /// 申卖量四
        AskVolume4: i64,
        /// 申卖价五
        AskPrice5: f64,
        /// 申卖量五
        AskVolume5: i64,
        /// 申买价四
        BidPrice4: f64,
        /// 申买量四
        BidVolume4: i64,
        /// 申买价五
        BidPrice5: f64,
        /// 申买量五
        BidVolume5: i64,
        /// 申卖价六
        AskPrice6: f64,
        /// 申卖量六
        AskVolume6: i64,
        /// 申卖价七
        AskPrice7: f64,
        /// 申卖量七
        AskVolume7: i64,
        /// 申买价六
        BidPrice6: f64,
        /// 申买量六
        BidVolume6: i64,
        /// 申买价七
        BidPrice7: f64,
        /// 申买量七
        BidVolume7: i64,
        /// 申卖价八
        AskPrice8: f64,
        /// 申卖量八
        AskVolume8: i64,
        /// 申卖价九
        AskPrice9: f64,
        /// 申卖量九
        AskVolume9: i64,
        /// 申买价八
        BidPrice8: f64,
        /// 申买量八
        BidVolume8: i64,
        /// 申买价九
        BidPrice9: f64,
        /// 申买量九
        BidVolume9: i64,
        /// 申买价十
        BidPrice10: f64,
        /// 申买量十
        BidVolume10: i64,
        /// 申卖价十
        AskPrice10: f64,
        /// 申卖量十
        AskVolume10: i64,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
        /// 涨停板价(只有深圳行情有效)
        UpperLimitPrice: f64,
        /// 跌停板价(只有深圳行情有效)
        LowerLimitPrice: f64,
        /// 今收盘价(只有上海行情有效)
        ClosePrice: f64,
        /// 行情产品实时状态
        MDSecurityStat: u8,
        /// 买入总笔数(只有上海行情有效)
        TotalBidNumber: i32,
        /// 卖出总笔数(只有上海行情有效)
        TotalOfferNumber: i32,
        /// 买入委托成交最大等待时间(只有上海行情有效)
        BidTradeMaxDuration: i32,
        /// 卖出委托成交最大等待时间(只有上海行情有效)
        OfferTradeMaxDuration: i32,
        /// 基金实时参考净值
        IOPV: f64,
        /// 卖一价上总委托笔数
        Ask1NumOrders: i32,
        /// 买一价上总委托笔数
        Bid1NumOrders: i32,
        /// 卖二价上总委托笔数
        Ask2NumOrders: i32,
        /// 买二价上总委托笔数
        Bid2NumOrders: i32,
        /// 卖三价上总委托笔数
        Ask3NumOrders: i32,
        /// 买三价上总委托笔数
        Bid3NumOrders: i32,
        /// 卖四价上总委托笔数
        Ask4NumOrders: i32,
        /// 买四价上总委托笔数
        Bid4NumOrders: i32,
        /// 卖五价上总委托笔数
        Ask5NumOrders: i32,
        /// 买五价上总委托笔数
        Bid5NumOrders: i32,
        /// 卖六价上总委托笔数
        Ask6NumOrders: i32,
        /// 买六价上总委托笔数
        Bid6NumOrders: i32,
        /// 卖七价上总委托笔数
        Ask7NumOrders: i32,
        /// 买七价上总委托笔数
        Bid7NumOrders: i32,
        /// 卖八价上总委托笔数
        Ask8NumOrders: i32,
        /// 买八价上总委托笔数
        Bid8NumOrders: i32,
        /// 卖九价上总委托笔数
        Ask9NumOrders: i32,
        /// 买九价上总委托笔数
        Bid9NumOrders: i32,
        /// 卖十价上总委托笔数
        Ask10NumOrders: i32,
        /// 买十价上总委托笔数
        Bid10NumOrders: i32,
        /// 买入撤单笔数(只有上海行情有效)
        WithdrawBuyNumber: i32,
        /// 买入撤单数量(只有上海行情有效)
        WithdrawBuyAmount: i64,
        /// 买入撤单金额(只有上海行情有效)
        WithdrawBuyMoney: f64,
        /// 卖出撤单笔数(只有上海行情有效)
        WithdrawSellNumber: i32,
        /// 卖出撤单数量(只有上海行情有效)
        WithdrawSellAmount: i64,
        /// 卖出撤单金额(只有上海行情有效)
        WithdrawSellMoney: f64,
    }
    /// Lev2指数行情
    #[derive(Debug, Clone, Default)]
    struct Lev2IndexField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 时间戳
        DataTimeStamp: i32,
        /// 前收盘指数
        PreCloseIndex: f64,
        /// 今开盘指数
        OpenIndex: f64,
        /// 最高指数
        HighIndex: f64,
        /// 最低指数
        LowIndex: f64,
        /// 最新指数
        LastIndex: f64,
        /// 参与计算相应指数的成交金额（元
        Turnover: f64,
        /// 参与计算相应指数的交易数量(手)
        TotalVolumeTraded: i64,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
        /// 收盘指数
        CloseIndex: f64,
    }
    /// Lev2逐笔成交
    #[derive(Debug, Clone, Default)]
    struct Lev2TransactionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 时间戳
        TradeTime: i32,
        /// 成交价格
        TradePrice: f64,
        /// 成交数量
        TradeVolume: i64,
        /// 成交类别（只有深圳行情有效）
        ExecType: u8,
        /// 主序号
        MainSeq: i32,
        /// 子序号
        SubSeq: i64,
        /// 买方委托序号
        BuyNo: i64,
        /// 卖方委托序号
        SellNo: i64,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
        /// 内外盘标志（只有上海行情有效）
        TradeBSFlag: u8,
        /// 业务序号（只有上海行情有效）
        BizIndex: i64,
    }
    /// Lev2逐笔委托
    #[derive(Debug, Clone, Default)]
    struct Lev2OrderDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 时间戳
        OrderTime: i32,
        /// 委托价格
        Price: f64,
        /// 委托数量
        Volume: i64,
        /// 委托方向
        Side: u8,
        /// 订单类别（只有深圳行情有效）
        OrderType: u8,
        /// 主序号
        MainSeq: i32,
        /// 子序号
        SubSeq: i32,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
        /// 委托序号
        OrderNO: i64,
        /// 订单状态
        OrderStatus: u8,
        /// 业务序号（只有上海行情有效）
        BizIndex: i64,
    }
    /// Lev2盘后定价行情
    #[derive(Debug, Clone, Default)]
    struct Lev2PHMarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 行情交易所代码
        ExchangeID: u8,
        /// 时间戳
        DataTimeStamp: i32,
        /// 今收盘价(只有上海行情有效)
        ClosePrice: f64,
        /// 行情产品实时状态
        MDSecurityStat: u8,
        /// 成交笔数
        NumTrades: i64,
        /// 成交总量
        TotalVolumeTrade: i64,
        /// 成交总金额
        TotalValueTrade: f64,
        /// 委托买入总量
        TotalBidVolume: i64,
        /// 委托卖出总量
        TotalAskVolume: i64,
        /// 买入撤单笔数
        WithdrawBuyNumber: i64,
        /// 买入撤单数量
        WithdrawBuyAmount: i64,
        /// 卖出撤单笔数
        WithdrawSellNumber: i64,
        /// 卖出撤单数量
        WithdrawSellAmount: i64,
        /// 申买量1
        BidOrderQty: i64,
        /// 实际的买委托笔数1
        BidNumOrders: i64,
        /// 申卖量1
        AskOrderQty: i64,
        /// 实际的卖委托笔数1
        AskNumOrders: i64,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
    }
    /// Lev2盘后定价逐笔成交
    #[derive(Debug, Clone, Default)]
    struct Lev2PHTransactionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 时间戳
        TradeTime: i32,
        /// 成交价格
        TradePrice: f64,
        /// 成交数量
        TradeVolume: i64,
        /// 成交金额(元)
        TradeMoney: f64,
        /// 成交类别
        ExecType: u8,
        /// 主序号
        MainSeq: i32,
        /// 子序号
        SubSeq: i64,
        /// 买方委托序号
        BuyNo: i64,
        /// 卖方委托序号
        SellNo: i64,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
        /// 内外盘标志
        TradeBSFlag: u8,
    }
    /// Lev2逐笔成交重传
    #[derive(Debug, Clone, Default)]
    struct Lev2ResendTransactionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 时间戳
        TradeTime: i32,
        /// 成交价格
        TradePrice: f64,
        /// 成交数量
        TradeVolume: i64,
        /// 成交类别（只有深圳行情有效）
        ExecType: u8,
        /// 主序号
        MainSeq: i32,
        /// 子序号
        SubSeq: i64,
        /// 买方委托序号
        BuyNo: i64,
        /// 卖方委托序号
        SellNo: i64,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
        /// 内外盘标志（只有上海行情有效）
        TradeBSFlag: u8,
        /// 业务序号（只有上海行情有效）
        BizIndex: i64,
    }
    /// Lev2逐笔委托重传
    #[derive(Debug, Clone, Default)]
    struct Lev2ResendOrderDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 时间戳
        OrderTime: i32,
        /// 委托价格
        Price: f64,
        /// 委托数量
        Volume: i64,
        /// 委托方向
        Side: u8,
        /// 订单类别（只有深圳行情有效）
        OrderType: u8,
        /// 主序号
        MainSeq: i32,
        /// 子序号
        SubSeq: i32,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
        /// 委托序号
        OrderNO: i64,
        /// 订单状态
        OrderStatus: u8,
        /// 业务序号（只有上海行情有效）
        BizIndex: i64,
    }
    /// Lev2债券快照行情(上海)
    #[derive(Debug, Clone, Default)]
    struct Lev2XTSMarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 行情交易所代码
        ExchangeID: u8,
        /// 时间戳
        DataTimeStamp: i32,
        /// 昨收盘
        PreClosePrice: f64,
        /// 今开盘
        OpenPrice: f64,
        /// 成交笔数
        NumTrades: i64,
        /// 成交总量
        TotalVolumeTrade: i64,
        /// 成交总金额
        TotalValueTrade: f64,
        /// 委托买入总量
        TotalBidVolume: i64,
        /// 加权平均委托买价格
        AvgBidPrice: f64,
        /// 委托卖出总量
        TotalAskVolume: i64,
        /// 加权平均委托卖价格
        AvgAskPrice: f64,
        /// 最高价
        HighestPrice: f64,
        /// 最低价
        LowestPrice: f64,
        /// 现价
        LastPrice: f64,
        /// 申买价一
        BidPrice1: f64,
        /// 申买量一
        BidVolume1: i64,
        /// 买一价上总委托笔数
        Bid1NumOrders: i32,
        /// 申卖价一
        AskPrice1: f64,
        /// 申卖量一
        AskVolume1: i64,
        /// 卖一价上总委托笔数
        Ask1NumOrders: i32,
        /// 申卖价二
        AskPrice2: f64,
        /// 申卖量二
        AskVolume2: i64,
        /// 卖二价上总委托笔数
        Ask2NumOrders: i32,
        /// 申卖价三
        AskPrice3: f64,
        /// 申卖量三
        AskVolume3: i64,
        /// 卖三价上总委托笔数
        Ask3NumOrders: i32,
        /// 申买价二
        BidPrice2: f64,
        /// 申买量二
        BidVolume2: i64,
        /// 买二价上总委托笔数
        Bid2NumOrders: i32,
        /// 申买价三
        BidPrice3: f64,
        /// 申买量三
        BidVolume3: i64,
        /// 买三价上总委托笔数
        Bid3NumOrders: i32,
        /// 申卖价四
        AskPrice4: f64,
        /// 申卖量四
        AskVolume4: i64,
        /// 卖四价上总委托笔数
        Ask4NumOrders: i32,
        /// 申卖价五
        AskPrice5: f64,
        /// 申卖量五
        AskVolume5: i64,
        /// 卖五价上总委托笔数
        Ask5NumOrders: i32,
        /// 申买价四
        BidPrice4: f64,
        /// 申买量四
        BidVolume4: i64,
        /// 买四价上总委托笔数
        Bid4NumOrders: i32,
        /// 申买价五
        BidPrice5: f64,
        /// 申买量五
        BidVolume5: i64,
        /// 买五价上总委托笔数
        Bid5NumOrders: i32,
        /// 申卖价六
        AskPrice6: f64,
        /// 申卖量六
        AskVolume6: i64,
        /// 卖六价上总委托笔数
        Ask6NumOrders: i32,
        /// 申卖价七
        AskPrice7: f64,
        /// 申卖量七
        AskVolume7: i64,
        /// 卖七价上总委托笔数
        Ask7NumOrders: i32,
        /// 申买价六
        BidPrice6: f64,
        /// 申买量六
        BidVolume6: i64,
        /// 买六价上总委托笔数
        Bid6NumOrders: i32,
        /// 申买价七
        BidPrice7: f64,
        /// 申买量七
        BidVolume7: i64,
        /// 买七价上总委托笔数
        Bid7NumOrders: i32,
        /// 申卖价八
        AskPrice8: f64,
        /// 申卖量八
        AskVolume8: i64,
        /// 卖八价上总委托笔数
        Ask8NumOrders: i32,
        /// 申卖价九
        AskPrice9: f64,
        /// 申卖量九
        AskVolume9: i64,
        /// 卖九价上总委托笔数
        Ask9NumOrders: i32,
        /// 申买价八
        BidPrice8: f64,
        /// 申买量八
        BidVolume8: i64,
        /// 买八价上总委托笔数
        Bid8NumOrders: i32,
        /// 申买价九
        BidPrice9: f64,
        /// 申买量九
        BidVolume9: i64,
        /// 买九价上总委托笔数
        Bid9NumOrders: i32,
        /// 申买价十
        BidPrice10: f64,
        /// 申买量十
        BidVolume10: i64,
        /// 买十价上总委托笔数
        Bid10NumOrders: i32,
        /// 申卖价十
        AskPrice10: f64,
        /// 申卖量十
        AskVolume10: i64,
        /// 卖十价上总委托笔数
        Ask10NumOrders: i32,
        /// 今收盘价
        ClosePrice: f64,
        /// 行情产品实时状态
        MDSecurityStat: u8,
        /// 买入总笔数
        TotalBidNumber: i32,
        /// 卖出总笔数
        TotalOfferNumber: i32,
        /// 买入委托成交量最大等待时间
        BidTradeMaxDuration: i32,
        /// 卖出委托成交量最大等待时间
        OfferTradeMaxDuration: i32,
        /// 买入撤单笔数
        WithdrawBuyNumber: i32,
        /// 买入撤单数量
        WithdrawBuyAmount: i64,
        /// 买入撤单金额
        WithdrawBuyMoney: f64,
        /// 卖出撤单笔数
        WithdrawSellNumber: i32,
        /// 卖出撤单数量
        WithdrawSellAmount: i64,
        /// 卖出撤单金额
        WithdrawSellMoney: f64,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
    }
    /// Lev2债券逐笔行情(上海)
    #[derive(Debug, Clone, Default)]
    struct Lev2XTSTickField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 主序号
        MainSeq: i32,
        /// 子序号
        SubSeq: i64,
        /// 时间戳
        TickTime: i32,
        /// 逐笔类型
        TickType: u8,
        /// 买方委托序号
        BuyNo: i64,
        /// 卖方委托序号
        SellNo: i64,
        /// 价格
        Price: f64,
        /// 数量
        Volume: i64,
        /// 成交金额
        TradeMoney: f64,
        /// 委托方向
        Side: u8,
        /// 内外盘标志
        TradeBSFlag: u8,
        /// 行情产品实时状态
        MDSecurityStat: u8,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
    }
    /// Lev2逐笔行情(上海)
    #[derive(Debug, Clone, Default)]
    struct Lev2NGTSTickField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 主序号
        MainSeq: i32,
        /// 子序号
        SubSeq: i64,
        /// 时间戳
        TickTime: i32,
        /// 逐笔类型
        TickType: u8,
        /// 买方委托序号
        BuyNo: i64,
        /// 卖方委托序号
        SellNo: i64,
        /// 价格
        Price: f64,
        /// 数量
        Volume: i64,
        /// 成交金额或新增委托订单已成交委托量
        TradeMoney: f64,
        /// 委托方向
        Side: u8,
        /// 内外盘标志
        TradeBSFlag: u8,
        /// 行情产品实时状态
        MDSecurityStat: u8,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
    }
    /// Lev2深圳债券快照行情
    #[derive(Debug, Clone, Default)]
    struct Lev2BondMarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 行情交易所代码
        ExchangeID: u8,
        /// 时间戳
        DataTimeStamp: i32,
        /// 昨收盘
        PreClosePrice: f64,
        /// 今开盘
        OpenPrice: f64,
        /// 昨收盘加权平均价
        AvgPreClosePrice: f64,
        /// 成交笔数
        NumTrades: i64,
        /// 成交总量
        TotalVolumeTrade: i64,
        /// 成交总金额
        TotalValueTrade: f64,
        /// 匹配成交成交量
        AuctionVolumeTrade: i64,
        /// 匹配成交成交金额
        AuctionValueTrade: f64,
        /// 委托买入总量
        TotalBidVolume: i64,
        /// 加权平均委托买价格
        AvgBidPrice: f64,
        /// 委托卖出总量
        TotalAskVolume: i64,
        /// 加权平均委托卖价格
        AvgAskPrice: f64,
        /// 最高价
        HighestPrice: f64,
        /// 最低价
        LowestPrice: f64,
        /// 最近价
        LastPrice: f64,
        /// 匹配成交最近价
        AuctionLastPrice: f64,
        /// 加权平均价格
        AvgPrice: f64,
        /// 升跌1
        PriceUpDown1: f64,
        /// 升跌2
        PriceUpDown2: f64,
        /// 今收盘价
        ClosePrice: f64,
        /// 行情产品实时状态
        MDSecurityStat: u8,
        /// 申买价一
        BidPrice1: f64,
        /// 申买量一
        BidVolume1: i64,
        /// 买一价上总委托笔数
        Bid1NumOrders: i32,
        /// 申卖价一
        AskPrice1: f64,
        /// 申卖量一
        AskVolume1: i64,
        /// 卖一价上总委托笔数
        Ask1NumOrders: i32,
        /// 申卖价二
        AskPrice2: f64,
        /// 申卖量二
        AskVolume2: i64,
        /// 卖二价上总委托笔数
        Ask2NumOrders: i32,
        /// 申卖价三
        AskPrice3: f64,
        /// 申卖量三
        AskVolume3: i64,
        /// 卖三价上总委托笔数
        Ask3NumOrders: i32,
        /// 申买价二
        BidPrice2: f64,
        /// 申买量二
        BidVolume2: i64,
        /// 买二价上总委托笔数
        Bid2NumOrders: i32,
        /// 申买价三
        BidPrice3: f64,
        /// 申买量三
        BidVolume3: i64,
        /// 买三价上总委托笔数
        Bid3NumOrders: i32,
        /// 申卖价四
        AskPrice4: f64,
        /// 申卖量四
        AskVolume4: i64,
        /// 卖四价上总委托笔数
        Ask4NumOrders: i32,
        /// 申卖价五
        AskPrice5: f64,
        /// 申卖量五
        AskVolume5: i64,
        /// 卖五价上总委托笔数
        Ask5NumOrders: i32,
        /// 申买价四
        BidPrice4: f64,
        /// 申买量四
        BidVolume4: i64,
        /// 买四价上总委托笔数
        Bid4NumOrders: i32,
        /// 申买价五
        BidPrice5: f64,
        /// 申买量五
        BidVolume5: i64,
        /// 买五价上总委托笔数
        Bid5NumOrders: i32,
        /// 申卖价六
        AskPrice6: f64,
        /// 申卖量六
        AskVolume6: i64,
        /// 卖六价上总委托笔数
        Ask6NumOrders: i32,
        /// 申卖价七
        AskPrice7: f64,
        /// 申卖量七
        AskVolume7: i64,
        /// 卖七价上总委托笔数
        Ask7NumOrders: i32,
        /// 申买价六
        BidPrice6: f64,
        /// 申买量六
        BidVolume6: i64,
        /// 买六价上总委托笔数
        Bid6NumOrders: i32,
        /// 申买价七
        BidPrice7: f64,
        /// 申买量七
        BidVolume7: i64,
        /// 买七价上总委托笔数
        Bid7NumOrders: i32,
        /// 申卖价八
        AskPrice8: f64,
        /// 申卖量八
        AskVolume8: i64,
        /// 卖八价上总委托笔数
        Ask8NumOrders: i32,
        /// 申卖价九
        AskPrice9: f64,
        /// 申卖量九
        AskVolume9: i64,
        /// 卖九价上总委托笔数
        Ask9NumOrders: i32,
        /// 申买价八
        BidPrice8: f64,
        /// 申买量八
        BidVolume8: i64,
        /// 买八价上总委托笔数
        Bid8NumOrders: i32,
        /// 申买价九
        BidPrice9: f64,
        /// 申买量九
        BidVolume9: i64,
        /// 买九价上总委托笔数
        Bid9NumOrders: i32,
        /// 申买价十
        BidPrice10: f64,
        /// 申买量十
        BidVolume10: i64,
        /// 买十价上总委托笔数
        Bid10NumOrders: i32,
        /// 申卖价十
        AskPrice10: f64,
        /// 申卖量十
        AskVolume10: i64,
        /// 卖十价上总委托笔数
        Ask10NumOrders: i32,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
    }
    /// Lev2深圳债券逐笔行情
    #[derive(Debug, Clone, Default)]
    struct Lev2BondOrderDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 时间戳
        OrderTime: i32,
        /// 委托价格
        Price: f64,
        /// 委托数量
        Volume: i64,
        /// 委托方向
        Side: u8,
        /// 订单类别
        OrderType: u8,
        /// 主序号
        MainSeq: i32,
        /// 子序号
        SubSeq: i64,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
    }
    /// Lev2深圳债券逐笔行情
    #[derive(Debug, Clone, Default)]
    struct Lev2BondTransactionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 时间戳
        TradeTime: i32,
        /// 成交价格
        TradePrice: f64,
        /// 成交数量
        TradeVolume: i64,
        /// 成交类别
        ExecType: u8,
        /// 主序号
        MainSeq: i32,
        /// 子序号
        SubSeq: i64,
        /// 买方委托序号
        BuyNo: i64,
        /// 卖方委托序号
        SellNo: i64,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
    }
    /// Lev2独立IOPV行情
    #[derive(Debug, Clone, Default)]
    struct Lev2IOPVField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 时间戳HHMMSSsss
        DataTimeStamp: i32,
        /// 基金实时参考净值
        IOPV: f64,
        /// 基金行情实时状态(只有深圳行情有效)
        MDSecurityStat: u8,
        /// 附加信息1
        Info1: i32,
        /// 附加信息2
        Info2: i32,
        /// 附加信息3
        Info3: i32,
    }
    /// 指数行情
    #[derive(Debug, Clone, Default)]
    struct ExIndexField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 时间戳HHMMSSsss
        DataTimeStamp: i32,
        /// 前收盘指数
        PreCloseIndex: f64,
        /// 今开盘指数
        OpenIndex: f64,
        /// 最高指数
        HighIndex: f64,
        /// 最低指数
        LowIndex: f64,
        /// 最新指数
        LastIndex: f64,
        /// 参与计算相应指数的成交金额（元
        Turnover: f64,
        /// 参与计算相应指数的交易数量(手)
        TotalVolumeTraded: i64,
        /// 收盘指数
        CloseIndex: f64,
    }
}
