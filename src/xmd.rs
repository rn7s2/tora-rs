#[allow(unused_imports)]
use std::fs::create_dir_all;
#[allow(unused_imports)]
use std::path::Path;
use std::sync::mpsc::Sender;
pub use ffi::*;
pub type UniquePtr<T> = cxx::UniquePtr<T>;

#[derive(Debug, Clone, Copy)]
pub enum TORA_TE_RESUME_TYPE {
    TORA_TERT_RESTART = 0,
    TORA_TERT_RESUME = 1,
    TORA_TERT_QUICK = 2,
}

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
/// TTORATstpAuthModeType是一个认证方式类型
/// //////////////////////////////////////////////////////////////////////
/// 密码
pub const TORA_TSTP_AM_Password: u8 = '0' as u8;
/// 指纹
pub const TORA_TSTP_AM_FingerPrint: u8 = '1' as u8;
/// 钥匙串
pub const TORA_TSTP_AM_CertInfo: u8 = '2' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpLangType是一个语言类型
/// //////////////////////////////////////////////////////////////////////
/// 简体中文
pub const TORA_TSTP_LGT_ZHCN: u8 = '0' as u8;
/// 中文香港
pub const TORA_TSTP_LGT_ZHHK: u8 = '1' as u8;
/// 英文美国
pub const TORA_TSTP_LGT_ENUS: u8 = '2' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpDeviceTypeType是一个设备类别类型
/// //////////////////////////////////////////////////////////////////////
/// PC端
pub const TORA_TSTP_DT_PC: u8 = '0' as u8;
/// 移动端
pub const TORA_TSTP_DT_Mobile: u8 = '1' as u8;
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
/// TTORATstpExchangeIDType是一个交易所代码类型
/// //////////////////////////////////////////////////////////////////////
/// 上海交易所
pub const TORA_TSTP_EXD_SSE: u8 = '1' as u8;
/// 深圳交易所
pub const TORA_TSTP_EXD_SZSE: u8 = '2' as u8;
/// 香港交易所
pub const TORA_TSTP_EXD_HK: u8 = '3' as u8;
/// 北京证券交易所
pub const TORA_TSTP_EXD_BSE: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpMarketIDType是一个市场代码类型
/// //////////////////////////////////////////////////////////////////////
/// 上海A股
pub const TORA_TSTP_MKD_SHA: u8 = '1' as u8;
/// 深圳A股
pub const TORA_TSTP_MKD_SZA: u8 = '2' as u8;
/// 上海B股
pub const TORA_TSTP_MKD_SHB: u8 = '3' as u8;
/// 深圳B股
pub const TORA_TSTP_MKD_SZB: u8 = '4' as u8;
/// 深圳三版A股
pub const TORA_TSTP_MKD_SZThreeA: u8 = '5' as u8;
/// 深圳三版B股
pub const TORA_TSTP_MKD_SZThreeB: u8 = '6' as u8;
/// 境外市场
pub const TORA_TSTP_MKD_Foreign: u8 = '7' as u8;
/// 深圳港股通市场
pub const TORA_TSTP_MKD_SZHK: u8 = '8' as u8;
/// 上海港股通市场
pub const TORA_TSTP_MKD_SHHK: u8 = '9' as u8;
/// 北京主板
pub const TORA_TSTP_MKD_BJMain: u8 = 'a' as u8;
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
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpEndFlagType是一个结束标志类型
/// //////////////////////////////////////////////////////////////////////
/// 待续
pub const TORA_TSTP_EF_ToBeContinued: u8 = '1' as u8;
/// 批结束
pub const TORA_TSTP_EF_BatchEnd: u8 = '2' as u8;
/// 全部完成
pub const TORA_TSTP_EF_Completed: u8 = '3' as u8;
/// 无数据
pub const TORA_TSTP_EF_NOP: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpMarketStatusType是一个市场状态类型
/// //////////////////////////////////////////////////////////////////////
/// 未知
pub const TORA_TSTP_MST_UnKnown: u8 = '#' as u8;
/// 开盘前
pub const TORA_TSTP_MST_BeforeTrading: u8 = '0' as u8;
/// 连续交易
pub const TORA_TSTP_MST_Continous: u8 = '1' as u8;
/// 收盘
pub const TORA_TSTP_MST_Closed: u8 = '2' as u8;
/// 开盘集合竞价
pub const TORA_TSTP_MST_OpenCallAuction: u8 = '3' as u8;
/// (港股通)未开市
pub const TORA_TSTP_MST_SZSEHKUnopened: u8 = 'a' as u8;
/// (港股通)开盘集合竞价输入买卖盘
pub const TORA_TSTP_MST_SZSEHKOpenCallAuctionInput: u8 = 'b' as u8;
/// (港股通)开盘集合竞价对盘前
pub const TORA_TSTP_MST_SZSEHKOpenCallAuctionBeforeMatch: u8 = 'c' as u8;
/// (港股通)开盘集合竞价对盘
pub const TORA_TSTP_MST_SZSEHKOpenCallAuctionMatch: u8 = 'd' as u8;
/// (港股通)暂停
pub const TORA_TSTP_MST_SZSEHKHalt: u8 = 'e' as u8;
/// (港股通)持续交易
pub const TORA_TSTP_MST_SZSEHKContinous: u8 = 'f' as u8;
/// (港股通)Exchange Intervention
pub const TORA_TSTP_MST_SZSEHKExchangeIntervention: u8 = 'g' as u8;
/// (港股通)收盘集合竞价参考价定价
pub const TORA_TSTP_MST_SZSEHKCloseCallAuctionReferencePrice: u8 = 'h' as u8;
/// (港股通)收盘集合竞价输入买卖盘
pub const TORA_TSTP_MST_SZSEHKCloseCallAuctionInput: u8 = 'i' as u8;
/// (港股通)收盘集合竞价不可取消
pub const TORA_TSTP_MST_SZSEHKCloseCallAuctionCannotCancel: u8 = 'j' as u8;
/// (港股通)收盘集合竞价对盘
pub const TORA_TSTP_MST_SZSEHKCloseCallAuctionMatch: u8 = 'k' as u8;
/// (港股通)收盘集合竞价随机收市
pub const TORA_TSTP_MST_SZSEHKCloseCallAuctionRandomClosed: u8 = 'l' as u8;
/// (港股通)取消买卖盘
pub const TORA_TSTP_MST_SZSEHKCancel: u8 = 'm' as u8;
/// (港股通)收市
pub const TORA_TSTP_MST_SZSEHKClosed: u8 = 'n' as u8;
/// (港股通)全日收市
pub const TORA_TSTP_MST_SZSEHKWholeClosed: u8 = 'o' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpMDSubModeType是一个行情订阅模式类型
/// //////////////////////////////////////////////////////////////////////
/// TCP连接模式
pub const TORA_TSTP_MST_TCP: u8 = '0' as u8;
/// UDP单播模式
pub const TORA_TSTP_MST_UDP: u8 = '1' as u8;
/// UDP组播模式
pub const TORA_TSTP_MST_MCAST: u8 = '2' as u8;

unsafe impl Send for XMdApi {}
unsafe impl Sync for XMdApi {}

impl XMdApi {
    pub fn CreateXMdApiAndSpi(tx: Sender<XMdSpiMsg>, md_sub_mode: u8, derive_md_sub_mode: u8) -> UniquePtr<XMdApi> {
        CreateXMdApi(Box::new(XMdSpi { tx }), md_sub_mode, derive_md_sub_mode)
    }
}

#[derive(Debug, Clone)]
pub enum XMdSpiMsg {
    OnFrontConnected,
    OnFrontDisconnected(i32),
    OnRspGetConnectionInfo(Box<ConnectionInfoField>, Box<RspInfoField>, i32),
    OnRspUserLogin(Box<RspUserLoginField>, Box<RspInfoField>, i32),
    OnRspUserLogout(Box<UserLogoutField>, Box<RspInfoField>, i32),
    OnRspSubMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspSubPHMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubPHMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspSubSpecialMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubSpecialMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspSubSimplifyMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubSimplifyMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspSubIOPV(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubIOPV(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspSubSecurityStatus(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubSecurityStatus(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspSubMarketStatus(Box<SpecificMarketField>, Box<RspInfoField>),
    OnRspUnSubMarketStatus(Box<SpecificMarketField>, Box<RspInfoField>),
    OnRspSubImcParams(Box<SpecificMarketField>, Box<RspInfoField>),
    OnRspUnSubImcParams(Box<SpecificMarketField>, Box<RspInfoField>),
    OnRspInquiryMarketDataMirror(Box<MarketDataField>, Box<RspInfoField>, i32, bool),
    OnRspInquiryPHMarketDataMirror(Box<PHMarketDataField>, Box<RspInfoField>, i32, bool),
    OnRspInquirySpecialMarketDataMirror(Box<SpecialMarketDataField>, Box<RspInfoField>, i32, bool),
    OnRspSubSPMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubSPMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspSubSPSimplifyMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubSPSimplifyMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspSubSPSecurityStatus(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubSPSecurityStatus(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspSubSPMarketStatus(Box<SpecificMarketField>, Box<RspInfoField>),
    OnRspUnSubSPMarketStatus(Box<SpecificMarketField>, Box<RspInfoField>),
    OnRspInquirySPMarketDataMirror(Box<MarketDataField>, Box<RspInfoField>, i32, bool),
    OnRtnMarketData(Box<MarketDataField>),
    OnRtnPHMarketData(Box<PHMarketDataField>),
    OnRtnSpecialMarketData(Box<SpecialMarketDataField>),
    OnRtnSimplifyMarketData(Box<SimplifyMarketDataField>),
    OnRtnIOPV(Box<IOPVField>),
    OnRtnSecurityStatus(Box<SecurityStatusField>),
    OnRtnMarketStatus(Box<MarketStatusField>),
    OnRtnImcParams(Box<ImcParamsField>),
    OnRtnSPMarketData(Box<MarketDataField>),
    OnRtnSPSimplifyMarketData(Box<SimplifyMarketDataField>),
    OnRtnSPSecurityStatus(Box<SecurityStatusField>),
    OnRtnSPMarketStatus(Box<MarketStatusField>),
    OnRspSubRapidMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRspUnSubRapidMarketData(Box<SpecificSecurityField>, Box<RspInfoField>),
    OnRtnRapidMarketData(Box<RapidMarketDataField>),
}

pub struct XMdSpi {
    tx: Sender<XMdSpiMsg>,
}

impl XMdSpi {
    pub fn OnFrontConnected(&self) { self.tx.send(XMdSpiMsg::OnFrontConnected).ok(); }
    pub fn OnFrontDisconnected(&self, nReason: i32) { self.tx.send(XMdSpiMsg::OnFrontDisconnected(nReason)).ok(); }
    pub fn OnRspGetConnectionInfo(&self, pConnectionInfoField: ConnectionInfoField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(XMdSpiMsg::OnRspGetConnectionInfo(Box::new(pConnectionInfoField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspUserLogin(&self, pRspUserLoginField: RspUserLoginField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(XMdSpiMsg::OnRspUserLogin(Box::new(pRspUserLoginField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspUserLogout(&self, pUserLogoutField: UserLogoutField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(XMdSpiMsg::OnRspUserLogout(Box::new(pUserLogoutField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspSubMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubPHMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubPHMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubPHMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubPHMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubSpecialMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubSpecialMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubSpecialMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubSpecialMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubSimplifyMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubSimplifyMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubSimplifyMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubSimplifyMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubIOPV(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubIOPV(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubIOPV(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubIOPV(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubSecurityStatus(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubSecurityStatus(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubSecurityStatus(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubSecurityStatus(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubMarketStatus(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubMarketStatus(Box::new(pSpecificMarketField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubMarketStatus(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubMarketStatus(Box::new(pSpecificMarketField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubImcParams(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubImcParams(Box::new(pSpecificMarketField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubImcParams(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubImcParams(Box::new(pSpecificMarketField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspInquiryMarketDataMirror(&self, pMarketDataField: MarketDataField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(XMdSpiMsg::OnRspInquiryMarketDataMirror(Box::new(pMarketDataField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspInquiryPHMarketDataMirror(&self, pPHMarketDataField: PHMarketDataField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(XMdSpiMsg::OnRspInquiryPHMarketDataMirror(Box::new(pPHMarketDataField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspInquirySpecialMarketDataMirror(&self, pMarketDataField: SpecialMarketDataField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(XMdSpiMsg::OnRspInquirySpecialMarketDataMirror(Box::new(pMarketDataField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspSubSPMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubSPMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubSPMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubSPMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubSPSimplifyMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubSPSimplifyMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubSPSimplifyMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubSPSimplifyMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubSPSecurityStatus(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubSPSecurityStatus(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubSPSecurityStatus(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubSPSecurityStatus(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspSubSPMarketStatus(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubSPMarketStatus(Box::new(pSpecificMarketField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubSPMarketStatus(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubSPMarketStatus(Box::new(pSpecificMarketField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspInquirySPMarketDataMirror(&self, pMarketDataField: MarketDataField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(XMdSpiMsg::OnRspInquirySPMarketDataMirror(Box::new(pMarketDataField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRtnMarketData(&self, pMarketDataField: MarketDataField) { self.tx.send(XMdSpiMsg::OnRtnMarketData(Box::new(pMarketDataField))).ok(); }
    pub fn OnRtnPHMarketData(&self, pPHMarketDataField: PHMarketDataField) { self.tx.send(XMdSpiMsg::OnRtnPHMarketData(Box::new(pPHMarketDataField))).ok(); }
    pub fn OnRtnSpecialMarketData(&self, pSpecialMarketDataField: SpecialMarketDataField) { self.tx.send(XMdSpiMsg::OnRtnSpecialMarketData(Box::new(pSpecialMarketDataField))).ok(); }
    pub fn OnRtnSimplifyMarketData(&self, pSimplifyMarketDataField: SimplifyMarketDataField) { self.tx.send(XMdSpiMsg::OnRtnSimplifyMarketData(Box::new(pSimplifyMarketDataField))).ok(); }
    pub fn OnRtnIOPV(&self, pIOPVField: IOPVField) { self.tx.send(XMdSpiMsg::OnRtnIOPV(Box::new(pIOPVField))).ok(); }
    pub fn OnRtnSecurityStatus(&self, pSecurityStatusField: SecurityStatusField) { self.tx.send(XMdSpiMsg::OnRtnSecurityStatus(Box::new(pSecurityStatusField))).ok(); }
    pub fn OnRtnMarketStatus(&self, pMarketStatusField: MarketStatusField) { self.tx.send(XMdSpiMsg::OnRtnMarketStatus(Box::new(pMarketStatusField))).ok(); }
    pub fn OnRtnImcParams(&self, pImcParamsField: ImcParamsField) { self.tx.send(XMdSpiMsg::OnRtnImcParams(Box::new(pImcParamsField))).ok(); }
    pub fn OnRtnSPMarketData(&self, pMarketDataField: MarketDataField) { self.tx.send(XMdSpiMsg::OnRtnSPMarketData(Box::new(pMarketDataField))).ok(); }
    pub fn OnRtnSPSimplifyMarketData(&self, pSimplifyMarketDataField: SimplifyMarketDataField) { self.tx.send(XMdSpiMsg::OnRtnSPSimplifyMarketData(Box::new(pSimplifyMarketDataField))).ok(); }
    pub fn OnRtnSPSecurityStatus(&self, pSecurityStatusField: SecurityStatusField) { self.tx.send(XMdSpiMsg::OnRtnSPSecurityStatus(Box::new(pSecurityStatusField))).ok(); }
    pub fn OnRtnSPMarketStatus(&self, pMarketStatusField: MarketStatusField) { self.tx.send(XMdSpiMsg::OnRtnSPMarketStatus(Box::new(pMarketStatusField))).ok(); }
    pub fn OnRspSubRapidMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspSubRapidMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRspUnSubRapidMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField) { self.tx.send(XMdSpiMsg::OnRspUnSubRapidMarketData(Box::new(pSpecificSecurityField), Box::new(pRspInfoField))).ok(); }
    pub fn OnRtnRapidMarketData(&self, pRapidMarketDataField: RapidMarketDataField) { self.tx.send(XMdSpiMsg::OnRtnRapidMarketData(Box::new(pRapidMarketDataField))).ok(); }
}

#[cxx::bridge(namespace = "tora_xmd")]
mod ffi {
    extern "Rust" {
        type XMdSpi;
        pub fn OnFrontConnected(&self);
        pub fn OnFrontDisconnected(&self, nReason: i32);
        pub fn OnRspGetConnectionInfo(&self, pConnectionInfoField: ConnectionInfoField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspUserLogin(&self, pRspUserLoginField: RspUserLoginField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspUserLogout(&self, pUserLogoutField: UserLogoutField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspSubMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspSubPHMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubPHMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspSubSpecialMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubSpecialMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspSubSimplifyMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubSimplifyMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspSubIOPV(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubIOPV(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspSubSecurityStatus(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubSecurityStatus(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspSubMarketStatus(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubMarketStatus(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField);
        pub fn OnRspSubImcParams(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubImcParams(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField);
        pub fn OnRspInquiryMarketDataMirror(&self, pMarketDataField: MarketDataField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspInquiryPHMarketDataMirror(&self, pPHMarketDataField: PHMarketDataField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspInquirySpecialMarketDataMirror(&self, pMarketDataField: SpecialMarketDataField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspSubSPMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubSPMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspSubSPSimplifyMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubSPSimplifyMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspSubSPSecurityStatus(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubSPSecurityStatus(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspSubSPMarketStatus(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubSPMarketStatus(&self, pSpecificMarketField: SpecificMarketField, pRspInfoField: RspInfoField);
        pub fn OnRspInquirySPMarketDataMirror(&self, pMarketDataField: MarketDataField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRtnMarketData(&self, pMarketDataField: MarketDataField);
        pub fn OnRtnPHMarketData(&self, pPHMarketDataField: PHMarketDataField);
        pub fn OnRtnSpecialMarketData(&self, pSpecialMarketDataField: SpecialMarketDataField);
        pub fn OnRtnSimplifyMarketData(&self, pSimplifyMarketDataField: SimplifyMarketDataField);
        pub fn OnRtnIOPV(&self, pIOPVField: IOPVField);
        pub fn OnRtnSecurityStatus(&self, pSecurityStatusField: SecurityStatusField);
        pub fn OnRtnMarketStatus(&self, pMarketStatusField: MarketStatusField);
        pub fn OnRtnImcParams(&self, pImcParamsField: ImcParamsField);
        pub fn OnRtnSPMarketData(&self, pMarketDataField: MarketDataField);
        pub fn OnRtnSPSimplifyMarketData(&self, pSimplifyMarketDataField: SimplifyMarketDataField);
        pub fn OnRtnSPSecurityStatus(&self, pSecurityStatusField: SecurityStatusField);
        pub fn OnRtnSPMarketStatus(&self, pMarketStatusField: MarketStatusField);
        pub fn OnRspSubRapidMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRspUnSubRapidMarketData(&self, pSpecificSecurityField: SpecificSecurityField, pRspInfoField: RspInfoField);
        pub fn OnRtnRapidMarketData(&self, pRapidMarketDataField: RapidMarketDataField);
    }

    unsafe extern "C++" {
        include!("tora-rs/wrapper/include/XMdApi.h");
        type XMdApi;
        fn CreateXMdApi(spi: Box<XMdSpi>, md_sub_mode: u8, derive_md_sub_mode: u8) -> UniquePtr<XMdApi>;
        /// 获取API版本号
        ///
        /// # Returns
        /// 版本号
        fn GetApiVersion(&self) -> String;
        /// 初始化运行环境
        ///
        /// # Parameters
        /// - `cpuCores` — API内部线程绑核参数，仅在组播订阅模式下有效。
        ///
        /// # Remarks
        /// 默认不绑核运行，支持最多绑3个核，优先级依次为：回调线程、合成快照网络I/O线程、普通行情网络I/O线程。
        /// 例如"0"表示API回调线程绑定到第0核上运行，"0,5,17"表示上述3个线程依次绑定在第0核、第5核、第17核上运行。
        /// 对于大部分不需要同时使用普通行情和合成快照的用户来说，如有绑核的必要，则2个核即可满足需求。如：
        /// "0,5"表示API回调线程、合成快照网络I/O线程分别绑定到第0核、第5核上运行，如未注册衍生服务则第5核绑定普通行情网络I/O线程。
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
        /// RegisterNameServer优先于RegisterFront
        fn RegisterNameServer(&self, pszNsAddress: String);
        /// 注册名字服务器用户信息
        ///
        /// # Parameters
        /// - `pFensUserInfoField` — 用户信息。
        fn RegisterFensUserInfo(&self, pFensUserInfoField: FensUserInfoField);
        /// 注册组播地址
        ///
        /// # Parameters
        /// - `pszMulticastAddress` — 组播网络地址,如:"udp://224.3.9.110:34567"。
        /// - `pszInterfaceIP` — 接收网卡地址,如:"127.0.0.1",填NULL则依次轮询尝试本机所有网卡加入组播组。
        /// - `pszSourceIp` — 组播数据包源地址,如:"127.0.0.1",填NULL表示不校验数据包源。
        ///
        /// # Remarks
        /// 仅在使用UDP组播方式工作时有效
        fn RegisterMulticast(&self, pszMulticastAddress: String, pszInterfaceIP: String, pszSourceIp: String);
        /// 注册衍生服务服务器网络地址
        ///
        /// # Parameters
        /// - `pszNsAddress` — 衍生服务服务器网络地址。
        ///
        /// # Remarks
        /// 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:15001”。
        /// “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”15001”代表服务器端口号。
        fn RegisterDeriveServer(&self, pszDeriveAddress: String);
        /// 注册衍生服务服务器组播地址
        ///
        /// # Parameters
        /// - `pszMulticastAddress` — 组播网络地址,如:"udp://224.3.9.110:34567"。
        /// - `pszInterfaceIP` — 接收网卡地址,如:"127.0.0.1",填NULL则依次轮询尝试本机所有网卡加入组播组。
        /// - `pszSourceIp` — 组播数据包源地址,如:"127.0.0.1",填NULL表示不校验数据包源。
        ///
        /// # Remarks
        /// 仅在使用UDP组播方式工作时有效
        fn RegisterDeriveMulticast(&self, pszMulticastAddress: String, pszInterfaceIP: String, pszSourceIp: String);
        /// 获取连接信息
        fn ReqGetConnectionInfo(&self, nRequestID: i32) -> i32;
        /// 用户登录请求
        fn ReqUserLogin(&self, pReqUserLoginField: ReqUserLoginField, nRequestID: i32) -> i32;
        /// 登出请求
        fn ReqUserLogout(&self, pUserLogoutField: UserLogoutField, nRequestID: i32) -> i32;
        /// 订阅行情
        fn SubscribeMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订行情
        fn UnSubscribeMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 订阅盘后行情
        fn SubscribePHMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订盘后行情
        fn UnSubscribePHMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 订阅特定行情
        fn SubscribeSpecialMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订特定行情
        fn UnSubscribeSpecialMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 订阅简易行情（仅TCP模式下可用）
        fn SubscribeSimplifyMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订简易行情（仅TCP模式下可用）
        fn UnSubscribeSimplifyMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 订阅独立IOPV行情
        fn SubscribeIOPV(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订独立IOPV行情
        fn UnSubscribeIOPV(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 订阅合约状态
        fn SubscribeSecurityStatus(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订合约状态
        fn UnSubscribeSecurityStatus(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 订阅市场状态
        fn SubscribeMarketStatus(&self, MarketID: u8) -> i32;
        /// 退订市场状态
        fn UnSubscribeMarketStatus(&self, MarketID: u8) -> i32;
        /// 订阅国际市场互联状态
        fn SubscribeImcParams(&self, MarketID: u8) -> i32;
        /// 退订国际市场互联状态
        fn UnSubscribeImcParams(&self, MarketID: u8) -> i32;
        /// 查询行情快照（仅TCP模式下可用）
        fn ReqInquiryMarketDataMirror(&self, pInquiryMarketDataField: InquiryMarketDataField, nRequestID: i32) -> i32;
        /// 查询盘后行情快照（仅TCP模式下可用）
        fn ReqInquiryPHMarketDataMirror(&self, pInquiryMarketDataField: InquiryMarketDataField, nRequestID: i32) -> i32;
        /// 查询特定行情快照（仅TCP模式下可用）
        fn ReqInquirySpecialMarketDataMirror(&self, pInquirySpecialMarketDataField: InquirySpecialMarketDataField, nRequestID: i32) -> i32;
        /// 订阅期权行情
        fn SubscribeSPMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订期权行情
        fn UnSubscribeSPMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 订阅期权简易行情（仅TCP模式下可用）
        fn SubscribeSPSimplifyMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订期权简易行情（仅TCP模式下可用）
        fn UnSubscribeSPSimplifyMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 订阅期权合约状态
        fn SubscribeSPSecurityStatus(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订期权合约状态
        fn UnSubscribeSPSecurityStatus(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 订阅期权市场状态
        fn SubscribeSPMarketStatus(&self, MarketID: u8) -> i32;
        /// 退订期权市场状态
        fn UnSubscribeSPMarketStatus(&self, MarketID: u8) -> i32;
        /// 查询期权行情快照（仅TCP模式下可用）
        fn ReqInquirySPMarketDataMirror(&self, pInquiryMarketDataField: InquiryMarketDataField, nRequestID: i32) -> i32;
        /// 订阅合成快照（衍生服务）
        fn SubscribeRapidMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
        /// 退订合成快照（衍生服务）
        fn UnSubscribeRapidMarketData(&self, ppSecurityID: Vec<String>, ExchangeID: u8) -> i32;
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
        /// 经纪公司部门代码（以资金账号方式登录时必填）
        DepartmentID: String,
        /// 认证方式(指纹或钥匙串认证时必填)
        AuthMode: u8,
        /// 密码(密码认证时必填)
        Password: String,
        /// 用户端产品信息
        UserProductInfo: String,
        /// 接口端产品信息
        InterfaceProductInfo: String,
        /// 终端采集信息
        TerminalInfo: String,
        /// 内网IP地址
        InnerIPAddress: String,
        /// 外网IP地址
        OuterIPAddress: String,
        /// Mac地址
        MacAddress: String,
        /// 接口语言
        Lang: u8,
        /// 终端动态秘钥
        DynamicPassword: String,
        /// 设备标识(指纹认证时必填)
        DeviceID: String,
        /// 认证序列号(指纹或钥匙串认证时必填)
        CertSerial: String,
        /// 设备类别(指纹或钥匙串认证时必填)
        DeviceType: u8,
    }
    /// 登录响应
    #[derive(Debug, Clone, Default)]
    struct RspUserLoginField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 登录账户
        LogInAccount: String,
        /// 登录账户类型
        LogInAccountType: u8,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 最大报单引用
        MaxOrderRef: i32,
        /// 私有流长度
        PrivateFlowCount: i32,
        /// 公有流长度
        PublicFlowCount: i32,
        /// 登录时间
        LoginTime: String,
        /// 交易系统名称
        SystemName: String,
        /// 交易日
        TradingDay: String,
        /// 用户代码
        UserID: String,
        /// 用户名称
        UserName: String,
        /// 用户类型
        UserType: u8,
        /// 报单流控
        OrderInsertCommFlux: i32,
        /// 撤单流控
        OrderActionCommFlux: i32,
        /// 密码到期日期
        PasswordExpiryDate: String,
        /// 是否需要改密
        NeedUpdatePassword: i32,
        /// 认证序列号
        CertSerial: String,
        /// 内网IP地址
        InnerIPAddress: String,
        /// 外网IP地址
        OuterIPAddress: String,
        /// Mac地址
        MacAddress: String,
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
    /// 订阅市场
    #[derive(Debug, Clone, Default)]
    struct SpecificMarketField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 市场代码
        MarketID: u8,
    }
    /// 查询行情快照
    #[derive(Debug, Clone, Default)]
    struct InquiryMarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
    }
    /// 深度行情通知
    #[derive(Debug, Clone, Default)]
    struct MarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易日
        TradingDay: String,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券名称
        SecurityName: String,
        /// 昨收盘价
        PreClosePrice: f64,
        /// 今开盘价
        OpenPrice: f64,
        /// 成交量
        Volume: i64,
        /// 成交额
        Turnover: f64,
        /// 成交笔数
        TradingCount: i64,
        /// 最新价（港股为按盘价）
        LastPrice: f64,
        /// 最高价
        HighestPrice: f64,
        /// 最低价
        LowestPrice: f64,
        /// 买1价
        BidPrice1: f64,
        /// 卖1价
        AskPrice1: f64,
        /// 涨停价（港股为冷静期或集合竞价的价格上限）
        UpperLimitPrice: f64,
        /// 跌停价（港股为冷静期或集合竞价的价格下限）
        LowerLimitPrice: f64,
        /// 市盈率1
        PERatio1: f64,
        /// 市盈率2
        PERatio2: f64,
        /// 价格升跌1
        PriceUpDown1: f64,
        /// 价格升跌2
        PriceUpDown2: f64,
        /// 持仓量
        OpenInterest: f64,
        /// 买1量
        BidVolume1: i64,
        /// 卖1量
        AskVolume1: i64,
        /// 买2价
        BidPrice2: f64,
        /// 买2量
        BidVolume2: i64,
        /// 卖2价
        AskPrice2: f64,
        /// 卖2量
        AskVolume2: i64,
        /// 买3价
        BidPrice3: f64,
        /// 买3量
        BidVolume3: i64,
        /// 卖3价
        AskPrice3: f64,
        /// 卖3量
        AskVolume3: i64,
        /// 买4价
        BidPrice4: f64,
        /// 买4量
        BidVolume4: i64,
        /// 卖4价
        AskPrice4: f64,
        /// 卖4量
        AskVolume4: i64,
        /// 买5价
        BidPrice5: f64,
        /// 买5量
        BidVolume5: i64,
        /// 卖5价
        AskPrice5: f64,
        /// 卖5量
        AskVolume5: i64,
        /// 更新时间
        UpdateTime: String,
        /// 更新毫秒
        UpdateMillisec: i32,
        /// 今收盘价
        ClosePrice: f64,
        /// 今结算价
        SettlementPrice: f64,
        /// 行情产品实时状态
        MDSecurityStat: u8,
        /// 警示级别
        HWLevel: i32,
        /// 基金T-1日收盘时刻净值
        PreCloseIOPV: f64,
        /// 基金实时参考净值
        IOPV: f64,
        /// ETF实时申购数量
        ETFPurVolume: i64,
        /// ETF实时申购笔数
        ETFPurCount: i64,
        /// ETF实时赎回数量
        ETFRedVolume: i64,
        /// ETF实时赎回笔数
        ETFRedCount: i64,
    }
    /// 查询响应域
    #[derive(Debug, Clone, Default)]
    struct QryRspInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 结束标识
        EndFlag: u8,
        /// 错误代码
        ErrorID: i32,
        /// 错误信息
        ErrorMsg: String,
    }
    /// 盘后行情通知
    #[derive(Debug, Clone, Default)]
    struct PHMarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易日
        TradingDay: String,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券名称
        SecurityName: String,
        /// 成交量
        Volume: i64,
        /// 成交金额
        Turnover: f64,
        /// 今收盘价
        ClosePrice: f64,
        /// 涨停价
        UpperLimitPrice: f64,
        /// 跌停价
        LowerLimitPrice: f64,
        /// 买入申报数量
        BidVolume: i64,
        /// 卖出申报数量
        AskVolume: i64,
        /// 更新时间
        UpdateTime: String,
        /// 更新毫秒
        UpdateMillisec: i32,
        /// 行情产品实时状态
        MDSecurityStat: u8,
        /// 警示级别
        HWLevel: i32,
    }
    /// 查询特定行情快照
    #[derive(Debug, Clone, Default)]
    struct InquirySpecialMarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
    }
    /// 特别行情通知
    #[derive(Debug, Clone, Default)]
    struct SpecialMarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易日
        TradingDay: String,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券名称
        SecurityName: String,
        /// 移动平均价
        MovingAvgPrice: f64,
        /// 采样数量
        MovingAvgPriceSamplingNum: i32,
        /// 最后修改时间
        UpdateTime: String,
        /// 最后修改毫秒
        UpdateMillisec: i32,
    }
    /// 简易行情
    #[derive(Debug, Clone, Default)]
    struct SimplifyMarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 证券名称
        SecurityName: String,
        /// 昨收盘价
        PreClosePrice: f64,
        /// 最新价
        LastPrice: f64,
        /// 买1价
        BidPrice1: f64,
        /// 卖1价
        AskPrice1: f64,
        /// 最高价
        HighestPrice: f64,
        /// 最低价
        LowestPrice: f64,
        /// 涨停价
        UpperLimitPrice: f64,
        /// 跌停价
        LowerLimitPrice: f64,
        /// 今收盘价
        ClosePrice: f64,
        /// 今结算价
        SettlementPrice: f64,
        /// 更新时间
        UpdateTime: String,
    }
    /// 合约状态
    #[derive(Debug, Clone, Default)]
    struct SecurityStatusField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 是否停牌
        IsSuspend: i32,
        /// 是否波动性中断
        IsBreak: i32,
        /// 是否长期停牌
        IsLongSuspend: i32,
        /// 是否熔断
        IsCircuitBreak: i32,
        /// 是否可融资买入
        IsSupportMarginBuy: i32,
        /// 是否可融券卖出
        IsSupportShortSell: i32,
        /// 是否可申购
        IsSupportPur: i32,
        /// 是否可赎回
        IsSupportRed: i32,
        /// 是否可拆分
        IsSupportSplit: i32,
        /// 是否可合并
        IsSupportMerge: i32,
        /// 是否可质押入库
        IsSupportPleadgeIn: i32,
        /// 是否可质押出库
        IsSupportPleadgeOut: i32,
        /// 是否可整手买
        IsSupportRoundLotBuy: i32,
        /// 是否可整手卖
        IsSupportRoundLotSell: i32,
        /// 是否可零股买
        IsSupportOddLotBuy: i32,
        /// 是否可零股卖
        IsSupportOddLotSell: i32,
        /// 是否可行权
        IsSupportExercise: i32,
        /// 是否限制买入开仓
        IsLimitBuy: i32,
        /// 是否限制卖出开仓
        IsLimitSell: i32,
        /// 是否限制备兑开仓
        IsLimitCover: i32,
        /// 是否限制做市商报价
        IsLimitMarketMaker: i32,
    }
    /// 市场状态
    #[derive(Debug, Clone, Default)]
    struct MarketStatusField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 市场代码
        MarketID: u8,
        /// 市场状态
        MarketStatus: u8,
    }
    /// 深港通国际市场互联状态信息
    #[derive(Debug, Clone, Default)]
    struct ImcParamsField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 市场代码
        MarketID: u8,
        /// 是否开放
        OpenFlag: i32,
        /// 初始额度
        ThresholdAmount: f64,
        /// 日中剩余额度
        PosAmt: f64,
        /// 额度是否可用
        AmountStatus: i32,
    }
    /// 独立IOPV行情
    #[derive(Debug, Clone, Default)]
    struct IOPVField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券名称
        SecurityName: String,
        /// 更新时间
        UpdateTime: String,
        /// 更新毫秒
        UpdateMillisec: i32,
        /// 基金实时参考净值
        IOPV: f64,
        /// 基金行情实时状态(只有深圳行情有效)
        MDSecurityStat: u8,
    }
    /// 合成快照
    #[derive(Debug, Clone, Default)]
    struct RapidMarketDataField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
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
        /// 涨停板价(只有深圳行情有效)
        UpperLimitPrice: f64,
        /// 跌停板价(只有深圳行情有效)
        LowerLimitPrice: f64,
        /// 今收盘价(只有上海行情有效)
        ClosePrice: f64,
        /// 行情产品实时状态
        MDSecurityStat: u8,
        /// 基金实时参考净值
        IOPV: f64,
        /// 内盘
        InnerSell: i64,
        /// 外盘
        OuterBuy: i64,
        /// 申买剩余笔数一
        BidCount1: i32,
        /// 申卖剩余笔数一
        AskCount1: i32,
        /// 申卖剩余笔数二
        AskCount2: i32,
        /// 申卖剩余笔数三
        AskCount3: i32,
        /// 申买剩余笔数二
        BidCount2: i32,
        /// 申买剩余笔数三
        BidCount3: i32,
        /// 申卖剩余笔数四
        AskCount4: i32,
        /// 申卖剩余笔数五
        AskCount5: i32,
        /// 申买剩余笔数四
        BidCount4: i32,
        /// 申买剩余笔数五
        BidCount5: i32,
        /// 申卖剩余笔数六
        AskCount6: i32,
        /// 申卖剩余笔数七
        AskCount7: i32,
        /// 申买剩余笔数六
        BidCount6: i32,
        /// 申买剩余笔数七
        BidCount7: i32,
        /// 申卖剩余笔数八
        AskCount8: i32,
        /// 申卖剩余笔数九
        AskCount9: i32,
        /// 申买剩余笔数八
        BidCount8: i32,
        /// 申买剩余笔数九
        BidCount9: i32,
        /// 申买剩余笔数十
        BidCount10: i32,
        /// 申卖剩余笔数十
        AskCount10: i32,
    }
    /// fens用户信息
    #[derive(Debug, Clone, Default)]
    struct FensUserInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 版本信息
        FensVer: u16,
        /// 环境编号
        FensEnvID: String,
        /// 节点编号
        FensNodeID: String,
        /// Fens用户代码
        FensUserID: String,
        /// 用户代码
        UserID: String,
        /// 终端信息
        ClientInfo: String,
    }
    /// 连接信息
    #[derive(Debug, Clone, Default)]
    struct ConnectionInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 内网IP地址
        InnerIPAddress: String,
        /// 内网端口号
        InnerPort: i32,
        /// 外网IP地址
        OuterIPAddress: String,
        /// 外网端口号
        OuterPort: i32,
        /// MAC地址
        MacAddress: String,
    }
}
