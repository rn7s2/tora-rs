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
/// 北京A股
pub const TORA_TSTP_LACT_BJAStock: u8 = 'a' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpAuthModeType是一个认证方式类型
/// //////////////////////////////////////////////////////////////////////
/// 密码
pub const TORA_TSTP_AM_Password: u8 = '0' as u8;
/// 指纹
pub const TORA_TSTP_AM_FingerPrint: u8 = '1' as u8;
/// 钥匙串
pub const TORA_TSTP_AM_CertInfo: u8 = '2' as u8;
/// 代理秘钥
pub const TORA_TSTP_AM_AgentKey: u8 = '3' as u8;
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
pub const TORA_TSTP_DVT_PC: u8 = '0' as u8;
/// 移动端
pub const TORA_TSTP_DVT_Mobile: u8 = '1' as u8;
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
/// 通用(内部使用)
pub const TORA_TSTP_EXD_COMM: u8 = '0' as u8;
/// 上海交易所
pub const TORA_TSTP_EXD_SSE: u8 = '1' as u8;
/// 深圳交易所
pub const TORA_TSTP_EXD_SZSE: u8 = '2' as u8;
/// 香港交易所
pub const TORA_TSTP_EXD_HK: u8 = '3' as u8;
/// 北京证券交易所
pub const TORA_TSTP_EXD_BSE: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpDirectionType是一个报单方向类型
/// //////////////////////////////////////////////////////////////////////
/// 买入
pub const TORA_TSTP_D_Buy: u8 = '0' as u8;
/// 卖出
pub const TORA_TSTP_D_Sell: u8 = '1' as u8;
/// ETF申购
pub const TORA_TSTP_D_ETFPur: u8 = '2' as u8;
/// ETF赎回
pub const TORA_TSTP_D_ETFRed: u8 = '3' as u8;
/// 新股申购
pub const TORA_TSTP_D_IPO: u8 = '4' as u8;
/// 正回购
pub const TORA_TSTP_D_Repurchase: u8 = '5' as u8;
/// 逆回购
pub const TORA_TSTP_D_ReverseRepur: u8 = '6' as u8;
/// 开放式基金申购
pub const TORA_TSTP_D_OeFundPur: u8 = '8' as u8;
/// 开放式基金赎回
pub const TORA_TSTP_D_OeFundRed: u8 = '9' as u8;
/// 担保品划入
pub const TORA_TSTP_D_CollateralIn: u8 = 'a' as u8;
/// 担保品划出
pub const TORA_TSTP_D_CollateralOut: u8 = 'b' as u8;
/// 质押入库
pub const TORA_TSTP_D_PledgeIn: u8 = 'd' as u8;
/// 质押出库
pub const TORA_TSTP_D_PledgeOut: u8 = 'e' as u8;
/// 配股配债
pub const TORA_TSTP_D_Rationed: u8 = 'f' as u8;
/// 基金拆分
pub const TORA_TSTP_D_Split: u8 = 'g' as u8;
/// 基金合并
pub const TORA_TSTP_D_Merge: u8 = 'h' as u8;
/// 融资买入
pub const TORA_TSTP_D_CreditBuy: u8 = 'i' as u8;
/// 融券卖出
pub const TORA_TSTP_D_CreditSell: u8 = 'j' as u8;
/// 卖券还款
pub const TORA_TSTP_D_SellRepay: u8 = 'k' as u8;
/// 买券还券
pub const TORA_TSTP_D_BuyRepay: u8 = 'l' as u8;
/// 还券划转
pub const TORA_TSTP_D_RepayTransfer: u8 = 'm' as u8;
/// 余券划转
pub const TORA_TSTP_D_SurplusTransfer: u8 = 'n' as u8;
/// 源券划转
pub const TORA_TSTP_D_SourceTransfer: u8 = 'o' as u8;
/// 债券转股
pub const TORA_TSTP_D_BondConvertStock: u8 = 't' as u8;
/// 债券回售
pub const TORA_TSTP_D_BondPutback: u8 = 'u' as u8;
/// ETF实物申购
pub const TORA_TSTP_D_ETFOtPur: u8 = 'v' as u8;
/// ETF实物赎回
pub const TORA_TSTP_D_ETFOtRed: u8 = 'w' as u8;
/// 回售撤销
pub const TORA_TSTP_D_PutbackRelieve: u8 = 'x' as u8;
/// 意向买入
pub const TORA_TSTP_D_IOIBuy: u8 = 'A' as u8;
/// 意向卖出
pub const TORA_TSTP_D_IOISell: u8 = 'B' as u8;
/// 成交确认买入
pub const TORA_TSTP_D_TCRBuy: u8 = 'C' as u8;
/// 成交确认卖出
pub const TORA_TSTP_D_TCRSell: u8 = 'D' as u8;
/// 要约预受
pub const TORA_TSTP_D_TenderAccept: u8 = 'E' as u8;
/// 要约解除
pub const TORA_TSTP_D_TenderRelieve: u8 = 'F' as u8;
/// 公开扩募
pub const TORA_TSTP_D_PublicOffering: u8 = 'G' as u8;
/// 配售扩募
pub const TORA_TSTP_D_PlacementOffering: u8 = 'H' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpOrderPriceTypeType是一个报单价格条件类型
/// //////////////////////////////////////////////////////////////////////
/// 任意价
pub const TORA_TSTP_OPT_AnyPrice: u8 = '1' as u8;
/// 限价
pub const TORA_TSTP_OPT_LimitPrice: u8 = '2' as u8;
/// 最优价
pub const TORA_TSTP_OPT_BestPrice: u8 = '3' as u8;
/// 盘后定价
pub const TORA_TSTP_OPT_FixPrice: u8 = '4' as u8;
/// 五档价
pub const TORA_TSTP_OPT_FiveLevelPrice: u8 = '5' as u8;
/// 本方最优
pub const TORA_TSTP_OPT_HomeBestPrice: u8 = '6' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpTimeConditionType是一个有效期类型类型
/// //////////////////////////////////////////////////////////////////////
/// 立即完成，否则撤销
pub const TORA_TSTP_TC_IOC: u8 = '1' as u8;
/// 本节有效
pub const TORA_TSTP_TC_GFS: u8 = '2' as u8;
/// 当日有效
pub const TORA_TSTP_TC_GFD: u8 = '3' as u8;
/// 指定日期前有效
pub const TORA_TSTP_TC_GTD: u8 = '4' as u8;
/// 撤销前有效
pub const TORA_TSTP_TC_GTC: u8 = '5' as u8;
/// 集合竞价有效
pub const TORA_TSTP_TC_GFA: u8 = '6' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpVolumeConditionType是一个成交量类型类型
/// //////////////////////////////////////////////////////////////////////
/// 任何数量
pub const TORA_TSTP_VC_AV: u8 = '1' as u8;
/// 最小数量
pub const TORA_TSTP_VC_MV: u8 = '2' as u8;
/// 全部数量
pub const TORA_TSTP_VC_CV: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpOperwayType是一个委托方式类型
/// //////////////////////////////////////////////////////////////////////
/// 空
pub const TORA_TSTP_OPERW_Non: u8 = ' ' as u8;
/// 电话委托
pub const TORA_TSTP_OPERW_Telephone: u8 = '0' as u8;
/// 柜台委托
pub const TORA_TSTP_OPERW_OTC: u8 = '1' as u8;
/// 移动客户端委托
pub const TORA_TSTP_OPERW_MobileClient: u8 = '2' as u8;
/// PC客户端委托
pub const TORA_TSTP_OPERW_PCClient: u8 = '3' as u8;
/// TY委托
pub const TORA_TSTP_OPERW_TY: u8 = '4' as u8;
/// 通道委托
pub const TORA_TSTP_OPERW_Channel: u8 = '5' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpLotTypeType是一个港股订单数量类型类型
/// //////////////////////////////////////////////////////////////////////
/// 零股订单
pub const TORA_TSTP_LT_OddLot: u8 = '0' as u8;
/// 整手订单
pub const TORA_TSTP_LT_RoundLot: u8 = '1' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpCondCheckType是一个委托条件检查类型
/// //////////////////////////////////////////////////////////////////////
/// 不做任何检查
pub const TORA_TSTP_CCT_None: u8 = '0' as u8;
/// 自成交检查
pub const TORA_TSTP_CCT_SelfDeal: u8 = '1' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpForceCloseReasonType是一个强平原因类型
/// //////////////////////////////////////////////////////////////////////
/// 非强平
pub const TORA_TSTP_FCC_NotForceClose: u8 = '0' as u8;
/// 资金不足
pub const TORA_TSTP_FCC_MoneyNotEnough: u8 = '1' as u8;
/// 仓位超限
pub const TORA_TSTP_FCC_PositionOverFull: u8 = '2' as u8;
/// 其它
pub const TORA_TSTP_FCC_Other: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpCreditQuotaTypeType是一个信用头寸类型类型
/// //////////////////////////////////////////////////////////////////////
/// 普通
pub const TORA_TSTP_CQT_Normal: u8 = '0' as u8;
/// 专项
pub const TORA_TSTP_CQT_Special: u8 = '1' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpOrderStatusType是一个报单状态类型
/// //////////////////////////////////////////////////////////////////////
/// 预埋
pub const TORA_TSTP_OST_Cached: u8 = '0' as u8;
/// 未知
pub const TORA_TSTP_OST_Unknown: u8 = '1' as u8;
/// 交易所已接收
pub const TORA_TSTP_OST_Accepted: u8 = '2' as u8;
/// 部分成交
pub const TORA_TSTP_OST_PartTraded: u8 = '3' as u8;
/// 全部成交
pub const TORA_TSTP_OST_AllTraded: u8 = '4' as u8;
/// 部成部撤
pub const TORA_TSTP_OST_PartTradeCanceled: u8 = '5' as u8;
/// 全部撤单
pub const TORA_TSTP_OST_AllCanceled: u8 = '6' as u8;
/// 交易所已拒绝
pub const TORA_TSTP_OST_Rejected: u8 = '7' as u8;
/// 发往交易核心
pub const TORA_TSTP_OST_SendTradeEngine: u8 = '#' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpOrderSubmitStatusType是一个报单提交状态类型
/// //////////////////////////////////////////////////////////////////////
/// 未提交
pub const TORA_TSTP_OSS_InsertUnSubmit: u8 = '0' as u8;
/// 已提交
pub const TORA_TSTP_OSS_InsertSubmitted: u8 = '1' as u8;
/// 撤单未提交
pub const TORA_TSTP_OSS_CancelUnSubmit: u8 = '2' as u8;
/// 撤单已提交
pub const TORA_TSTP_OSS_CancelSubmitted: u8 = '3' as u8;
/// 撤单已被拒绝
pub const TORA_TSTP_OSS_CancelRejected: u8 = '4' as u8;
/// 撤单已删除
pub const TORA_TSTP_OSS_CancelDeleted: u8 = '5' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpCurrencyIDType是一个币种类型
/// //////////////////////////////////////////////////////////////////////
/// 人民币
pub const TORA_TSTP_CID_CNY: u8 = '1' as u8;
/// 港币
pub const TORA_TSTP_CID_HKD: u8 = '2' as u8;
/// 美元
pub const TORA_TSTP_CID_USD: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpOrderTypeType是一个报单类型类型
/// //////////////////////////////////////////////////////////////////////
/// 正常
pub const TORA_TSTP_ORDT_Normal: u8 = '0' as u8;
/// 报价衍生
pub const TORA_TSTP_ORDT_DeriveFromQuote: u8 = '1' as u8;
/// 组合衍生
pub const TORA_TSTP_ORDT_DeriveFromCombination: u8 = '2' as u8;
/// 组合报单
pub const TORA_TSTP_ORDT_Combination: u8 = '3' as u8;
/// 条件单
pub const TORA_TSTP_ORDT_ConditionalOrder: u8 = '4' as u8;
/// 互换单
pub const TORA_TSTP_ORDT_Swap: u8 = '5' as u8;
/// 预埋单
pub const TORA_TSTP_ORDT_Cache: u8 = '6' as u8;
/// 夜市委托
pub const TORA_TSTP_ORDT_Night: u8 = '7' as u8;
/// 通道委托
pub const TORA_TSTP_ORDT_Board: u8 = '8' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpActionFlagType是一个操作标志类型
/// //////////////////////////////////////////////////////////////////////
/// 删除
pub const TORA_TSTP_AF_Delete: u8 = '0' as u8;
/// 修改
pub const TORA_TSTP_AF_Modify: u8 = '3' as u8;
/// 强制删除
pub const TORA_TSTP_AF_ForceDelete: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpTriggerOrderVolumeTypeType是一个触发基准数量类型类型
/// //////////////////////////////////////////////////////////////////////
/// 自定义数量
pub const TORA_TSTP_TOVT_CustomVol: u8 = '1' as u8;
/// 相关数量
pub const TORA_TSTP_TOVT_RelativeVol: u8 = '2' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpTriggerOrderPriceTypeType是一个触发基准价格类型类型
/// //////////////////////////////////////////////////////////////////////
/// 自定义价格
pub const TORA_TSTP_TOPT_CustomPrice: u8 = '1' as u8;
/// 最新价
pub const TORA_TSTP_TOPT_LastPrice: u8 = '2' as u8;
/// 卖一价
pub const TORA_TSTP_TOPT_AskPrice1: u8 = '3' as u8;
/// 买一价
pub const TORA_TSTP_TOPT_BidPrice1: u8 = '4' as u8;
/// 相关价
pub const TORA_TSTP_TOPT_Relative: u8 = '5' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpContingentConditionType是一个触发条件类型
/// //////////////////////////////////////////////////////////////////////
/// 成交触发
pub const TORA_TSTP_CC_TradeTouch: u8 = '0' as u8;
/// 撤单触发
pub const TORA_TSTP_CC_CancelTouch: u8 = '1' as u8;
/// 时间触发
pub const TORA_TSTP_CC_TimeTouch: u8 = '2' as u8;
/// 交易时段触发
pub const TORA_TSTP_CC_SegmentTouch: u8 = '3' as u8;
/// 最新价大于等于条件价
pub const TORA_TSTP_CC_LastPriceGreaterThanStopPrice: u8 = '4' as u8;
/// 最新价小于等于条件价
pub const TORA_TSTP_CC_LastPriceLesserThanStopPrice: u8 = '5' as u8;
/// 卖一价大于等于条件价
pub const TORA_TSTP_CC_AskPriceGreaterEqualStopPrice: u8 = '6' as u8;
/// 卖一价小于等于条件价
pub const TORA_TSTP_CC_AskPriceLesserEqualStopPrice: u8 = '7' as u8;
/// 买一价大于等于条件价
pub const TORA_TSTP_CC_BidPriceGreaterEqualStopPrice: u8 = '8' as u8;
/// 买一价小于等于条件价
pub const TORA_TSTP_CC_BidPriceLesserEqualStopPrice: u8 = '9' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpCondOrderStatusType是一个条件单状态类型
/// //////////////////////////////////////////////////////////////////////
/// 初始
pub const TORA_TSTP_COST_Initial: u8 = '#' as u8;
/// 未触发
pub const TORA_TSTP_COST_NotTouched: u8 = '0' as u8;
/// 已触发
pub const TORA_TSTP_COST_Touched: u8 = '1' as u8;
/// 已结束
pub const TORA_TSTP_COST_Finished: u8 = '2' as u8;
/// 已撤销
pub const TORA_TSTP_COST_Cancel: u8 = '3' as u8;
/// 触发失败
pub const TORA_TSTP_COST_Failed: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpMarketIDType是一个市场代码类型
/// //////////////////////////////////////////////////////////////////////
/// 通用(内部使用)
pub const TORA_TSTP_MKD_COMMON: u8 = '0' as u8;
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
/// TTORATstpTransferDirectionType是一个转移方向类型
/// //////////////////////////////////////////////////////////////////////
/// 蓝补
pub const TORA_TSTP_TRNSD_In: u8 = '0' as u8;
/// 红冲
pub const TORA_TSTP_TRNSD_Out: u8 = '1' as u8;
/// 集中交易调入
pub const TORA_TSTP_TRNSD_MoveIn: u8 = '2' as u8;
/// 集中交易调出
pub const TORA_TSTP_TRNSD_MoveOut: u8 = '3' as u8;
/// 冻结
pub const TORA_TSTP_TRNSD_Freeze: u8 = '4' as u8;
/// 解冻
pub const TORA_TSTP_TRNSD_UnFreeze: u8 = '5' as u8;
/// 证券转银行
pub const TORA_TSTP_TRNSD_StockToBank: u8 = '6' as u8;
/// 银行转证券
pub const TORA_TSTP_TRNSD_BankToStock: u8 = '7' as u8;
/// 外部节点转入
pub const TORA_TSTP_TRNSD_NodeMoveIn: u8 = 'c' as u8;
/// 外部节点转出
pub const TORA_TSTP_TRNSD_NodeMoveOut: u8 = 'd' as u8;
/// 直接还款
pub const TORA_TSTP_TRNSD_CashRepay: u8 = 'f' as u8;
/// 直接还息(内部使用)
pub const TORA_TSTP_TRNSD_CashRepayInterestFee: u8 = 'g' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpBankIDType是一个银行代码类型
/// //////////////////////////////////////////////////////////////////////
/// 中国建设银行
pub const TORA_TSTP_BKID_CCB: u8 = '1' as u8;
/// 中国农业银行
pub const TORA_TSTP_BKID_ABC: u8 = '2' as u8;
/// 中国工商银行
pub const TORA_TSTP_BKID_ICBC: u8 = '3' as u8;
/// 中国银行
pub const TORA_TSTP_BKID_BOC: u8 = '4' as u8;
/// 中国招商银行
pub const TORA_TSTP_BKID_CMB: u8 = '5' as u8;
/// 中国交通银行
pub const TORA_TSTP_BKID_BC: u8 = '6' as u8;
/// 浦东发展银行
pub const TORA_TSTP_BKID_SPDB: u8 = '7' as u8;
/// 兴业银行
pub const TORA_TSTP_BKID_CIB: u8 = '8' as u8;
/// 中国光大银行
pub const TORA_TSTP_BKID_CEB: u8 = '9' as u8;
/// 广东发展银行
pub const TORA_TSTP_BKID_GDB: u8 = 'a' as u8;
/// 南京银行
pub const TORA_TSTP_BKID_NJCB: u8 = 'b' as u8;
/// 上海银行
pub const TORA_TSTP_BKID_SHCB: u8 = 'c' as u8;
/// 中信银行
pub const TORA_TSTP_BKID_CITICB: u8 = 'd' as u8;
/// 华夏银行
pub const TORA_TSTP_BKID_HXB: u8 = 'e' as u8;
/// 民生银行
pub const TORA_TSTP_BKID_CMBC: u8 = 'f' as u8;
/// 平安银行
pub const TORA_TSTP_BKID_PACB: u8 = 'g' as u8;
/// 宁波银行
pub const TORA_TSTP_BKID_NBCB: u8 = 'h' as u8;
/// 北京银行
pub const TORA_TSTP_BKID_BOB: u8 = 'i' as u8;
/// 邮储银行
pub const TORA_TSTP_BKID_PSBC: u8 = 'j' as u8;
/// 江苏银行
pub const TORA_TSTP_BKID_SUYH: u8 = 'k' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpTransferStatusType是一个转移状态类型
/// //////////////////////////////////////////////////////////////////////
/// 转移正在处理
pub const TORA_TSTP_TRANST_TranferHandling: u8 = '0' as u8;
/// 转移成功
pub const TORA_TSTP_TRANST_TransferSuccess: u8 = '1' as u8;
/// 转移失败
pub const TORA_TSTP_TRANST_TransferFail: u8 = '2' as u8;
/// 冲正正在处理
pub const TORA_TSTP_TRANST_RepealHandling: u8 = '3' as u8;
/// 冲正成功
pub const TORA_TSTP_TRANST_RepealSuccess: u8 = '4' as u8;
/// 冲正失败
pub const TORA_TSTP_TRANST_RepealFail: u8 = '5' as u8;
/// 外部系统已接收
pub const TORA_TSTP_TRANST_ExternalAccepted: u8 = '6' as u8;
/// 发往交易核心
pub const TORA_TSTP_TRANST_SendTradeEngine: u8 = '#' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpTransferPositionTypeType是一个转移持仓类型类型
/// //////////////////////////////////////////////////////////////////////
/// 任意仓
pub const TORA_TSTP_TPT_ALL: u8 = '0' as u8;
/// 昨仓
pub const TORA_TSTP_TPT_History: u8 = '1' as u8;
/// 今买卖仓
pub const TORA_TSTP_TPT_TodayBS: u8 = '2' as u8;
/// 今申赎仓
pub const TORA_TSTP_TPT_TodayPR: u8 = '3' as u8;
/// 今拆分合并仓
pub const TORA_TSTP_TPT_TodaySM: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpDataSyncStatusType是一个数据同步状态类型
/// //////////////////////////////////////////////////////////////////////
/// 未同步
pub const TORA_TSTP_DS_Asynchronous: u8 = '1' as u8;
/// 同步中
pub const TORA_TSTP_DS_Synchronizing: u8 = '2' as u8;
/// 已同步
pub const TORA_TSTP_DS_Synchronized: u8 = '3' as u8;
/// 全部同步完成
pub const TORA_TSTP_DS_AllSynchronized: u8 = '4' as u8;
/// 预同步完成
pub const TORA_TSTP_DS_PreSync: u8 = '5' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpProductIDType是一个证券品种代码类型
/// //////////////////////////////////////////////////////////////////////
/// 通用(内部使用)
pub const TORA_TSTP_PID_COMMON: u8 = '0' as u8;
/// 上海股票
pub const TORA_TSTP_PID_SHStock: u8 = '1' as u8;
/// 上海基金
pub const TORA_TSTP_PID_SHFund: u8 = '3' as u8;
/// 上海债券
pub const TORA_TSTP_PID_SHBond: u8 = '4' as u8;
/// 上海标准券
pub const TORA_TSTP_PID_SHStandard: u8 = '5' as u8;
/// 上海质押式回购
pub const TORA_TSTP_PID_SHRepurchase: u8 = '6' as u8;
/// 深圳股票
pub const TORA_TSTP_PID_SZStock: u8 = '7' as u8;
/// 深圳基金
pub const TORA_TSTP_PID_SZFund: u8 = '9' as u8;
/// 深圳债券
pub const TORA_TSTP_PID_SZBond: u8 = 'a' as u8;
/// 深圳标准券
pub const TORA_TSTP_PID_SZStandard: u8 = 'b' as u8;
/// 深圳质押式回购
pub const TORA_TSTP_PID_SZRepurchase: u8 = 'c' as u8;
/// 深港通港股主板
pub const TORA_TSTP_PID_SZSEHKMain: u8 = 'd' as u8;
/// 深港通港股创业板
pub const TORA_TSTP_PID_SZSEHKGEM: u8 = 'e' as u8;
/// 深港通港股扩充交易证券
pub const TORA_TSTP_PID_SZSEHKETS: u8 = 'f' as u8;
/// 深港通港股NasdaqAMX市场
pub const TORA_TSTP_PID_SZSEHKNasdaqAMX: u8 = 'g' as u8;
/// 上海科创板
pub const TORA_TSTP_PID_SHKC: u8 = 'i' as u8;
/// 北京股票
pub const TORA_TSTP_PID_BJStock: u8 = 'j' as u8;
/// 沪港通港股主板
pub const TORA_TSTP_PID_SSEHKMain: u8 = 'k' as u8;
/// 沪港通港股创业板
pub const TORA_TSTP_PID_SSEHKGEM: u8 = 'l' as u8;
/// 沪港通港股扩充交易证券
pub const TORA_TSTP_PID_SSEHKETS: u8 = 'm' as u8;
/// 沪港通港股NasdaqAMX市场
pub const TORA_TSTP_PID_SSEHKNasdaqAMX: u8 = 'n' as u8;
/// 北京债券
pub const TORA_TSTP_PID_BJBond: u8 = 'o' as u8;
/// 北京基金
pub const TORA_TSTP_PID_BJFund: u8 = 'p' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpSecurityTypeType是一个证券类别类型
/// //////////////////////////////////////////////////////////////////////
/// 通用(内部使用)
pub const TORA_TSTP_STP_COMMON: u8 = '0' as u8;
/// 上海A股
pub const TORA_TSTP_STP_SHAShares: u8 = 'a' as u8;
/// 上海单市场股票ETF
pub const TORA_TSTP_STP_SHSingleMarketStockETF: u8 = 'b' as u8;
/// 上海单市场实物债券ETF
pub const TORA_TSTP_STP_SHSingleMarketBondETF: u8 = 'c' as u8;
/// 上海黄金ETF
pub const TORA_TSTP_STP_SHGoldETF: u8 = 'd' as u8;
/// 上海货币ETF
pub const TORA_TSTP_STP_SHTradableMonetaryFund: u8 = 'e' as u8;
/// 上海国债地方债
pub const TORA_TSTP_STP_SHBondNation: u8 = 'f' as u8;
/// 上海企业债
pub const TORA_TSTP_STP_SHBondCorporation: u8 = 'g' as u8;
/// 上海公司债
pub const TORA_TSTP_STP_SHBondCompany: u8 = 'h' as u8;
/// 上海可转债
pub const TORA_TSTP_STP_SHBondConversion: u8 = 'i' as u8;
/// 上海分离债
pub const TORA_TSTP_STP_SHBondSeparation: u8 = 'j' as u8;
/// 上海标准券
pub const TORA_TSTP_STP_SHStandard: u8 = 'o' as u8;
/// 上海质押式回购
pub const TORA_TSTP_STP_SHRepo: u8 = 'p' as u8;
/// 上海封闭式基金
pub const TORA_TSTP_STP_SHCEFund: u8 = 'q' as u8;
/// 上海开放式基金
pub const TORA_TSTP_STP_SHOEFund: u8 = 'r' as u8;
/// 上海跨市场股票ETF
pub const TORA_TSTP_STP_SHCrossMarketStockETF: u8 = 's' as u8;
/// 上海跨境ETF
pub const TORA_TSTP_STP_SHCrossBorderETF: u8 = 't' as u8;
/// 上海分级母基金
pub const TORA_TSTP_STP_SHMontherStructFund: u8 = 'u' as u8;
/// 上海分级子基金
pub const TORA_TSTP_STP_SHSubStructFund: u8 = 'v' as u8;
/// 上海实时申赎货币基金
pub const TORA_TSTP_STP_SHRealTimeMonetaryFund: u8 = 'w' as u8;
/// 上海可交换债
pub const TORA_TSTP_STP_SHExchangeableBond: u8 = 'x' as u8;
/// 上海标准LOF基金
pub const TORA_TSTP_STP_SHLOF: u8 = 'A' as u8;
/// 深圳主板A股
pub const TORA_TSTP_STP_SZMainAShares: u8 = 'B' as u8;
/// 深圳中小企业板
pub const TORA_TSTP_STP_SZSME: u8 = 'C' as u8;
/// 深圳国债、地方债
pub const TORA_TSTP_STP_SZBondNation: u8 = 'D' as u8;
/// 深圳企业债
pub const TORA_TSTP_STP_SZBondCorporation: u8 = 'E' as u8;
/// 深圳公司债
pub const TORA_TSTP_STP_SZBondCompany: u8 = 'F' as u8;
/// 深圳可转债
pub const TORA_TSTP_STP_SZBondConversion: u8 = 'G' as u8;
/// 深圳分离债
pub const TORA_TSTP_STP_SZBondSeparation: u8 = 'H' as u8;
/// 深圳创业板(注册制)
pub const TORA_TSTP_STP_SZGEMReg: u8 = 'I' as u8;
/// 深圳创业板可转债(注册制)
pub const TORA_TSTP_STP_SZGEMBondConversionReg: u8 = 'J' as u8;
/// 深圳跨境ETF
pub const TORA_TSTP_STP_SZCrossBorderETF: u8 = 'K' as u8;
/// 深圳黄金ETF
pub const TORA_TSTP_STP_SZGoldETF: u8 = 'L' as u8;
/// 深圳现金债券ETF
pub const TORA_TSTP_STP_SZCashBondETF: u8 = 'M' as u8;
/// 深圳单市场股票ETF
pub const TORA_TSTP_STP_SZSingleMarketStockETF: u8 = 'N' as u8;
/// 深圳单市场实物债券ETF
pub const TORA_TSTP_STP_SZSingleMarketBondETF: u8 = 'O' as u8;
/// 深圳货币ETF
pub const TORA_TSTP_STP_SZMonetaryFundETF: u8 = 'P' as u8;
/// 深圳创业板
pub const TORA_TSTP_STP_SZGEM: u8 = 'Q' as u8;
/// 深圳创业板可交换债
pub const TORA_TSTP_STP_SZGEMExchangeableBond: u8 = 'R' as u8;
/// 深圳创业板可交换债(注册制)
pub const TORA_TSTP_STP_SZGEMExchangeableBondReg: u8 = 'S' as u8;
/// 深圳标准券
pub const TORA_TSTP_STP_SZStandard: u8 = 'T' as u8;
/// 深圳质押式回购
pub const TORA_TSTP_STP_SZRepo: u8 = 'U' as u8;
/// 深圳封闭式基金
pub const TORA_TSTP_STP_SZCEFund: u8 = 'V' as u8;
/// 深圳开放式基金
pub const TORA_TSTP_STP_SZOEFund: u8 = 'W' as u8;
/// 深圳跨境开放式基金
pub const TORA_TSTP_STP_SZCrossBorderOEFund: u8 = 'X' as u8;
/// 深圳跨市场股票ETF
pub const TORA_TSTP_STP_SZCrossMarketStockETF: u8 = 'Y' as u8;
/// 深圳标准LOF基金
pub const TORA_TSTP_STP_SZLOF: u8 = 'Z' as u8;
/// 深圳跨境LOF基金
pub const TORA_TSTP_STP_SZCrossBorderLOF: u8 = '1' as u8;
/// 深圳传统分级母基金
pub const TORA_TSTP_STP_SZMontherStructFund: u8 = '2' as u8;
/// 深圳传统分级子基金
pub const TORA_TSTP_STP_SZSubStructFund: u8 = '3' as u8;
/// 深圳跨境分级母基金
pub const TORA_TSTP_STP_SZMontherCrossBorderStructFund: u8 = '4' as u8;
/// 深圳跨境分级子基金
pub const TORA_TSTP_STP_SZSubCrossBorderStructFund: u8 = '5' as u8;
/// 深圳可交换债
pub const TORA_TSTP_STP_SZExchangeableBond: u8 = '6' as u8;
/// 深圳创业板可转债
pub const TORA_TSTP_STP_SZGEMBondConversion: u8 = '7' as u8;
/// 深港通港股债券
pub const TORA_TSTP_STP_SZSEHKBond: u8 = '8' as u8;
/// 深港通港股一篮子权证
pub const TORA_TSTP_STP_SZSEHKBasketWarrant: u8 = '9' as u8;
/// 深港通港股股本
pub const TORA_TSTP_STP_SZSEHKEquity: u8 = 'y' as u8;
/// 深港通港股信托
pub const TORA_TSTP_STP_SZSEHKTrust: u8 = 'z' as u8;
/// 深港通港股权证
pub const TORA_TSTP_STP_SZSEHKWarrant: u8 = '#' as u8;
/// 上海存托凭证
pub const TORA_TSTP_STP_SHCDR: u8 = '+' as u8;
/// 上海科创板股票
pub const TORA_TSTP_STP_SHKC: u8 = '*' as u8;
/// 科创板产品（上市后前5个交易日）
pub const TORA_TSTP_STP_SHKC1: u8 = '^' as u8;
/// 上海科创板存托凭证
pub const TORA_TSTP_STP_SHKCCDR: u8 = '-' as u8;
/// 深圳主板、中小板创新企业股票或存托凭证
pub const TORA_TSTP_STP_SZCDR: u8 = 'k' as u8;
/// 深圳创业板创新企业股票或存托凭证
pub const TORA_TSTP_STP_SZGEMCDR: u8 = 'l' as u8;
/// 深圳创业板创新企业股票或存托凭证(注册制)
pub const TORA_TSTP_STP_SZGEMCDRReg: u8 = 'm' as u8;
/// 深圳商品期货ETF
pub const TORA_TSTP_STP_SZCommFuturesETF: u8 = 'n' as u8;
/// 深圳基础设施基金
pub const TORA_TSTP_STP_SZInfrastructureFund: u8 = '=' as u8;
/// 上海科创板ETF
pub const TORA_TSTP_STP_SHKCETF: u8 = '@' as u8;
/// 上海科创板LOF
pub const TORA_TSTP_STP_SHKCLOF: u8 = '%' as u8;
/// 上海科创板可转债
pub const TORA_TSTP_STP_SHKCBondConversion: u8 = '$' as u8;
/// 上海定向可转债
pub const TORA_TSTP_STP_SHOrientedConversionBond: u8 = '<' as u8;
/// 深圳定向可转债
pub const TORA_TSTP_STP_SZOrientedConversionBond: u8 = '>' as u8;
/// 上海基础设施基金
pub const TORA_TSTP_STP_SHInfrastructureFund: u8 = '~' as u8;
/// 北京股票
pub const TORA_TSTP_STP_BJStock: u8 = '[' as u8;
/// 上海科创板可交换债
pub const TORA_TSTP_STP_SHKCExchangeableBond: u8 = ']' as u8;
/// 沪港通港股债券
pub const TORA_TSTP_STP_SSEHKBond: u8 = '(' as u8;
/// 沪港通港股一篮子权证
pub const TORA_TSTP_STP_SSEHKBasketWarrant: u8 = ')' as u8;
/// 沪港通港股股本
pub const TORA_TSTP_STP_SSEHKEquity: u8 = '&' as u8;
/// 沪港通港股信托
pub const TORA_TSTP_STP_SSEHKTrust: u8 = '{' as u8;
/// 沪港通港股权证
pub const TORA_TSTP_STP_SSEHKWarrant: u8 = '}' as u8;
/// 上海跨市场债券ETF
pub const TORA_TSTP_STP_SHCrossMarketBondETF: u8 = '_' as u8;
/// 深圳跨市场债券ETF
pub const TORA_TSTP_STP_SZCrossMarketBondETF: u8 = ':' as u8;
/// 北京公司债
pub const TORA_TSTP_STP_BJBondCompany: u8 = '.' as u8;
/// 上海多资产ETF
pub const TORA_TSTP_STP_SHMultiAssetETF: u8 = '`' as u8;
/// 深圳多资产ETF
pub const TORA_TSTP_STP_SZMultiAssetETF: u8 = '!' as u8;
/// 上海现金债券ETF
pub const TORA_TSTP_STP_SHCashBondETF: u8 = ';' as u8;
/// 北京单市场股票ETF
pub const TORA_TSTP_STP_BJSingleMarketStockETF: u8 = '/' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpOrderUnitType是一个申报单位类型
/// //////////////////////////////////////////////////////////////////////
/// 手
pub const TORA_TSTP_OUT_Shou: u8 = '0' as u8;
/// 股
pub const TORA_TSTP_OUT_Gu: u8 = '1' as u8;
/// 份
pub const TORA_TSTP_OUT_Fen: u8 = '2' as u8;
/// 张
pub const TORA_TSTP_OUT_Zhang: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpIssueModeType是一个发行方式类型
/// //////////////////////////////////////////////////////////////////////
/// 市值配售方式
pub const TORA_TSTP_IMO_ValueLimit: u8 = '0' as u8;
/// 增发定价方式
pub const TORA_TSTP_IMO_AddIssue: u8 = '1' as u8;
/// 信用申购方式
pub const TORA_TSTP_IMO_Credit: u8 = '2' as u8;
/// 定价发行(北交所)
pub const TORA_TSTP_IMO_Fixed: u8 = '3' as u8;
/// 竞价发行(北交所)
pub const TORA_TSTP_IMO_Auction: u8 = '4' as u8;
/// 询价发行(北交所)
pub const TORA_TSTP_IMO_BookBuilding: u8 = '5' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpLoginStatusType是一个登录状态类型
/// //////////////////////////////////////////////////////////////////////
/// 启用
pub const TORA_TSTP_USTS_Enabled: u8 = '1' as u8;
/// 禁用
pub const TORA_TSTP_USTS_Disabled: u8 = '2' as u8;
/// 锁定
pub const TORA_TSTP_USTS_Locked: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpInvestorTypeType是一个投资者类型类型
/// //////////////////////////////////////////////////////////////////////
/// 个人
pub const TORA_TSTP_CT_Person: u8 = '0' as u8;
/// 机构
pub const TORA_TSTP_CT_Company: u8 = '1' as u8;
/// 自营
pub const TORA_TSTP_CT_SelfOperate: u8 = '5' as u8;
/// 测试
pub const TORA_TSTP_CT_Test: u8 = '#' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpIdCardTypeType是一个证件类型类型
/// //////////////////////////////////////////////////////////////////////
/// 组织机构代码
pub const TORA_TSTP_ICT_EID: u8 = '0' as u8;
/// 中国公民身份证
pub const TORA_TSTP_ICT_IDCard: u8 = '1' as u8;
/// 军官证
pub const TORA_TSTP_ICT_OfficerIDCard: u8 = '2' as u8;
/// 警官证
pub const TORA_TSTP_ICT_PoliceIDCard: u8 = '3' as u8;
/// 士兵证
pub const TORA_TSTP_ICT_SoldierIDCard: u8 = '4' as u8;
/// 户口簿
pub const TORA_TSTP_ICT_HouseholdRegister: u8 = '5' as u8;
/// 护照
pub const TORA_TSTP_ICT_Passport: u8 = '6' as u8;
/// 台胞证
pub const TORA_TSTP_ICT_TaiwanCompatriotIDCard: u8 = '7' as u8;
/// 回乡证
pub const TORA_TSTP_ICT_HomeComingCard: u8 = '8' as u8;
/// 营业执照号
pub const TORA_TSTP_ICT_LicenseNo: u8 = '9' as u8;
/// 税务登记号/当地纳税ID
pub const TORA_TSTP_ICT_TaxNo: u8 = 'A' as u8;
/// 港澳居民来往内地通行证
pub const TORA_TSTP_ICT_HMMainlandTravelPermit: u8 = 'B' as u8;
/// 台湾居民来往大陆通行证
pub const TORA_TSTP_ICT_TwMainlandTravelPermit: u8 = 'C' as u8;
/// 驾照
pub const TORA_TSTP_ICT_DrivingLicense: u8 = 'D' as u8;
/// 当地社保ID
pub const TORA_TSTP_ICT_SocialID: u8 = 'F' as u8;
/// 当地身份证
pub const TORA_TSTP_ICT_LocalID: u8 = 'G' as u8;
/// 商业登记证
pub const TORA_TSTP_ICT_BusinessRegistration: u8 = 'H' as u8;
/// 港澳永久性居民身份证
pub const TORA_TSTP_ICT_HKMCIDCard: u8 = 'I' as u8;
/// 人行开户许可证
pub const TORA_TSTP_ICT_AccountsPermits: u8 = 'J' as u8;
/// 其他证件
pub const TORA_TSTP_ICT_OtherCard: u8 = 'x' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpTradingStatusType是一个交易状态类型
/// //////////////////////////////////////////////////////////////////////
/// 正常
pub const TORA_TSTP_TS_Normal: u8 = '1' as u8;
/// 正在强平
pub const TORA_TSTP_TS_ForceClosing: u8 = '2' as u8;
/// 异常
pub const TORA_TSTP_TS_Exception: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpProfInvestorTypeType是一个专业投资者类别类型
/// //////////////////////////////////////////////////////////////////////
/// 非专业投资者
pub const TORA_TSTP_PIT_Normal: u8 = '0' as u8;
/// 专业投资者
pub const TORA_TSTP_PIT_Professional: u8 = '1' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpPlanTypeType是一个套餐类型类型
/// //////////////////////////////////////////////////////////////////////
/// 标准套餐
pub const TORA_TSTP_PLTP_Standard: u8 = '0' as u8;
/// 智能套餐
pub const TORA_TSTP_PLTP_Smart: u8 = '1' as u8;
/// 预留1
pub const TORA_TSTP_PLTP_Reserve1: u8 = '2' as u8;
/// 预留2
pub const TORA_TSTP_PLTP_Reserve2: u8 = '3' as u8;
/// 未定义类型（内部使用）
pub const TORA_TSTP_PLTP_Undefined: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpShareholderIDTypeType是一个股东账户类型类型
/// //////////////////////////////////////////////////////////////////////
/// 投机
pub const TORA_TSTP_SIDT_Speculation: u8 = '1' as u8;
/// 套利
pub const TORA_TSTP_SIDT_Arbitrage: u8 = '2' as u8;
/// 套保
pub const TORA_TSTP_SIDT_Hedge: u8 = '3' as u8;
/// 普通
pub const TORA_TSTP_SIDT_Normal: u8 = 'a' as u8;
/// 信用
pub const TORA_TSTP_SIDT_Credit: u8 = 'b' as u8;
/// 衍生品
pub const TORA_TSTP_SIDT_Derivatives: u8 = 'c' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpCancelOrderStatusType是一个撤单状态类型
/// //////////////////////////////////////////////////////////////////////
/// 预埋
pub const TORA_TSTP_CORDS_Cached: u8 = '0' as u8;
/// 已提交
pub const TORA_TSTP_CORDS_Submitted: u8 = '1' as u8;
/// 成功
pub const TORA_TSTP_CORDS_Success: u8 = '2' as u8;
/// 拒绝
pub const TORA_TSTP_CORDS_Rejected: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpCancelOrderTypeType是一个撤单类型类型
/// //////////////////////////////////////////////////////////////////////
/// 普通撤单
pub const TORA_TSTP_CORDT_Normal: u8 = '0' as u8;
/// 强制撤单
pub const TORA_TSTP_CORDT_Force: u8 = '1' as u8;
/// 预埋撤单
pub const TORA_TSTP_CORDT_Cache: u8 = '2' as u8;
/// 通道撤单
pub const TORA_TSTP_CORDT_Board: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpAccountTypeType是一个资金账户类型类型
/// //////////////////////////////////////////////////////////////////////
/// 普通
pub const TORA_TSTP_FAT_Normal: u8 = '1' as u8;
/// 信用
pub const TORA_TSTP_FAT_Credit: u8 = '2' as u8;
/// 衍生品
pub const TORA_TSTP_FAT_Derivatives: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpBizClassType是一个业务类别类型
/// //////////////////////////////////////////////////////////////////////
/// 买入
pub const TORA_TSTP_BC_Buy: u8 = '0' as u8;
/// 卖出
pub const TORA_TSTP_BC_Sell: u8 = '1' as u8;
/// ETF申购
pub const TORA_TSTP_BC_ETFPur: u8 = '2' as u8;
/// ETF赎回
pub const TORA_TSTP_BC_ETFRed: u8 = '3' as u8;
/// 新股申购
pub const TORA_TSTP_BC_SubscribingShares: u8 = '4' as u8;
/// 正回购
pub const TORA_TSTP_BC_Repurchase: u8 = '5' as u8;
/// 逆回购
pub const TORA_TSTP_BC_ReverseRepur: u8 = '6' as u8;
/// 开放式基金申购
pub const TORA_TSTP_BC_OeFundPur: u8 = '8' as u8;
/// 开放式基金赎回
pub const TORA_TSTP_BC_OeFundRed: u8 = '9' as u8;
/// 担保品划入
pub const TORA_TSTP_BC_CollateralIn: u8 = 'a' as u8;
/// 担保品划出
pub const TORA_TSTP_BC_CollateralOut: u8 = 'b' as u8;
/// 质押入库
pub const TORA_TSTP_BC_PledgeIn: u8 = 'd' as u8;
/// 质押出库
pub const TORA_TSTP_BC_PledgeOut: u8 = 'e' as u8;
/// 配股配债
pub const TORA_TSTP_BC_Rationed: u8 = 'f' as u8;
/// 开放式基金拆分
pub const TORA_TSTP_BC_Split: u8 = 'g' as u8;
/// 开放式基金合并
pub const TORA_TSTP_BC_Merge: u8 = 'h' as u8;
/// 融资买入
pub const TORA_TSTP_BC_CreditBuy: u8 = 'i' as u8;
/// 融券卖出
pub const TORA_TSTP_BC_CreditSell: u8 = 'j' as u8;
/// 卖券还款
pub const TORA_TSTP_BC_SellRepay: u8 = 'k' as u8;
/// 买券还券
pub const TORA_TSTP_BC_BuyRepay: u8 = 'l' as u8;
/// 还券划转
pub const TORA_TSTP_BC_RepayTransfer: u8 = 'm' as u8;
/// 余券划转
pub const TORA_TSTP_BC_SurplusTransfer: u8 = 'n' as u8;
/// 源券划转
pub const TORA_TSTP_BC_SourceTransfer: u8 = 'o' as u8;
/// 卖券强平还款(内部使用)
pub const TORA_TSTP_BC_ForceSellRepay: u8 = 'p' as u8;
/// 买券强平还券(内部使用)
pub const TORA_TSTP_BC_ForceBuyRepay: u8 = 'q' as u8;
/// 负债展期(内部使用)
pub const TORA_TSTP_BC_DebtExtend: u8 = 'r' as u8;
/// 转托管
pub const TORA_TSTP_BC_CustodyTransfer: u8 = 's' as u8;
/// 债券转股
pub const TORA_TSTP_BC_BondConvertStock: u8 = 't' as u8;
/// 债券回售
pub const TORA_TSTP_BC_BondPutback: u8 = 'u' as u8;
/// ETF实物申购
pub const TORA_TSTP_BC_ETFOtPur: u8 = 'v' as u8;
/// ETF实物赎回
pub const TORA_TSTP_BC_ETFOtRed: u8 = 'w' as u8;
/// 回售撤销
pub const TORA_TSTP_BC_PutbackRelieve: u8 = 'x' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpBrokerageTypeType是一个佣金类型类型
/// //////////////////////////////////////////////////////////////////////
/// 毛佣金
pub const TORA_TSTP_BT_Gross: u8 = '0' as u8;
/// 净佣金
pub const TORA_TSTP_BT_Net: u8 = '1' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpOperateSourceType是一个操作来源类型
/// //////////////////////////////////////////////////////////////////////
/// 实时上场
pub const TORA_TSTP_OPRTSRC_DBCommand: u8 = '0' as u8;
/// API调用
pub const TORA_TSTP_OPRTSRC_SyncAPI: u8 = '1' as u8;
/// 自动触发
pub const TORA_TSTP_OPRTSRC_AutoTrigger: u8 = '2' as u8;
/// API紧急上场
pub const TORA_TSTP_OPRTSRC_EmergencyAPI: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpSpecPrivilegeTypeType是一个特殊权限类别类型
/// //////////////////////////////////////////////////////////////////////
/// 创业板
pub const TORA_TSTP_SPLT_GEM: u8 = '0' as u8;
/// 风险警示板
pub const TORA_TSTP_SPLT_RiskWarning: u8 = '1' as u8;
/// 退市整理板
pub const TORA_TSTP_SPLT_Delisting: u8 = '2' as u8;
/// 港股通
pub const TORA_TSTP_SPLT_HK: u8 = '3' as u8;
/// 科创板
pub const TORA_TSTP_SPLT_SHKC: u8 = '4' as u8;
/// 创业板注册制
pub const TORA_TSTP_SPLT_GEMRegistration: u8 = '5' as u8;
/// 分级基金
pub const TORA_TSTP_SPLT_StructFund: u8 = '6' as u8;
/// 可转债
pub const TORA_TSTP_SPLT_ConvertBond: u8 = '7' as u8;
/// 基础设施基金
pub const TORA_TSTP_SPLT_InfrastructureFund: u8 = '8' as u8;
/// 定向可转债
pub const TORA_TSTP_SPLT_OrientedConvertBond: u8 = '9' as u8;
/// 北交所股票
pub const TORA_TSTP_SPLT_BJStock: u8 = 'a' as u8;
/// 主板交易
pub const TORA_TSTP_SPLT_Main: u8 = 'b' as u8;
/// 退市整理版可转债
pub const TORA_TSTP_SPLT_DelConvertBond: u8 = 'c' as u8;
/// 科创板成长层
pub const TORA_TSTP_SPLT_SHKCU: u8 = 'd' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpCreRedTypeType是一个申赎类型类型
/// //////////////////////////////////////////////////////////////////////
/// 普通申赎
pub const TORA_TSTP_CRT_IS: u8 = '0' as u8;
/// 实物申赎
pub const TORA_TSTP_CRT_OS: u8 = '1' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpETFCurrenceReplaceStatusType是一个ETF现金替代标志类型
/// //////////////////////////////////////////////////////////////////////
/// 禁止现金替代
pub const TORA_TSTP_ETFCTSTAT_Forbidden: u8 = '0' as u8;
/// 可以现金替代
pub const TORA_TSTP_ETFCTSTAT_Allow: u8 = '1' as u8;
/// 必须现金替代
pub const TORA_TSTP_ETFCTSTAT_Force: u8 = '2' as u8;
/// 跨市退补现金替代
pub const TORA_TSTP_ETFCTSTAT_CBAllow: u8 = '3' as u8;
/// 跨市必须现金替代
pub const TORA_TSTP_ETFCTSTAT_CBForce: u8 = '4' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpPriceTickIDType是一个价差品种类型
/// //////////////////////////////////////////////////////////////////////
/// 股本证券
pub const TORA_TSTP_PTID_Stock: u8 = '0' as u8;
/// 债务证券
pub const TORA_TSTP_PTID_Bond: u8 = '1' as u8;
/// 股票期权
pub const TORA_TSTP_PTID_Option: u8 = '2' as u8;
/// 买卖基金
pub const TORA_TSTP_PTID_Fund: u8 = '3' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpPriceTickTypeType是一个价差类别类型
/// //////////////////////////////////////////////////////////////////////
/// 价格上下限
pub const TORA_TSTP_PPT_LimitPrice: u8 = '0' as u8;
/// 价差组
pub const TORA_TSTP_PPT_PriceTick: u8 = '1' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpFundTypeType是一个基金类型类型
/// //////////////////////////////////////////////////////////////////////
/// 标准LOF
pub const TORA_TSTP_FUT_Normal: u8 = '0' as u8;
/// 分级母基金
pub const TORA_TSTP_FUT_Mother: u8 = '1' as u8;
/// 分级子基金
pub const TORA_TSTP_FUT_Sub: u8 = '2' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpTradeReportTypeType是一个成交回报类型类型
/// //////////////////////////////////////////////////////////////////////
/// ETF成交
pub const TORA_TSTP_TRT_ETF: u8 = '1' as u8;
/// 成分券成交
pub const TORA_TSTP_TRT_Basket: u8 = '2' as u8;
/// 资金替代成交
pub const TORA_TSTP_TRT_CashSubs: u8 = '3' as u8;
/// 交收成交
pub const TORA_TSTP_TRT_Delivery: u8 = '4' as u8;
/// 冲正
pub const TORA_TSTP_TRT_Repeal: u8 = '5' as u8;
/// //////////////////////////////////////////////////////////////////////
/// TTORATstpTradeCommModeType是一个交易通讯模式类型
/// //////////////////////////////////////////////////////////////////////
/// TCP模式
pub const TORA_TSTP_TCM_TCP: u8 = '0' as u8;
/// UDP模式
pub const TORA_TSTP_TCM_UDP: u8 = '1' as u8;
/// PROXY模式
pub const TORA_TSTP_TCM_PROXY: u8 = '2' as u8;
/// sf网卡tcpdirect模式-TCP
pub const TORA_TSTP_TCM_TCPDIRECT: u8 = '3' as u8;

unsafe impl Send for TraderApi {}
unsafe impl Sync for TraderApi {}

impl TraderApi {
    pub fn CreateTraderApiAndSpi(tx: Sender<TraderSpiMsg>, flow_path: String, is_encrypt: bool, trade_comm_mode: u8, interface_addr: String, is_using_order_ex: bool) -> UniquePtr<TraderApi> {
        if !Path::new(&flow_path).exists() {
            create_dir_all(&flow_path).unwrap();
        }
        CreateTraderApi(Box::new(TraderSpi { tx }), flow_path, is_encrypt, trade_comm_mode, interface_addr, is_using_order_ex)
    }
}

#[derive(Debug, Clone)]
pub enum TraderSpiMsg {
    OnFrontConnected,
    OnFrontDisconnected(i32),
    OnRspError(Box<RspInfoField>, i32, bool),
    OnRspGetConnectionInfo(Box<ConnectionInfoField>, Box<RspInfoField>, i32),
    OnRspUserLogin(Box<RspUserLoginField>, Box<RspInfoField>, i32),
    OnRspUserLogout(Box<UserLogoutField>, Box<RspInfoField>, i32),
    OnRspUserPasswordUpdate(Box<UserPasswordUpdateField>, Box<RspInfoField>, i32),
    OnRspInputDeviceSerial(Box<RspInputDeviceSerialField>, Box<RspInfoField>, i32),
    OnRspOrderInsert(Box<InputOrderField>, Box<RspInfoField>, i32),
    OnRspPublicOfferedFundOrderInsert(Box<InputOrderField>, Box<RspInfoField>, i32),
    OnRtnOrder(Box<OrderField>),
    OnErrRtnOrderInsert(Box<InputOrderField>, Box<RspInfoField>, i32),
    OnRtnTrade(Box<TradeField>),
    OnRspOrderAction(Box<InputOrderActionField>, Box<RspInfoField>, i32),
    OnErrRtnOrderAction(Box<InputOrderActionField>, Box<RspInfoField>, i32),
    OnRspCondOrderInsert(Box<InputCondOrderField>, Box<RspInfoField>, i32),
    OnRtnCondOrder(Box<ConditionOrderField>),
    OnErrRtnCondOrderInsert(Box<InputCondOrderField>, Box<RspInfoField>, i32),
    OnRspCondOrderAction(Box<InputCondOrderActionField>, Box<RspInfoField>, i32),
    OnErrRtnCondOrderAction(Box<InputCondOrderActionField>, Box<RspInfoField>, i32),
    OnRspNegoOrderInsert(Box<InputNegoOrderField>, Box<RspInfoField>, i32),
    OnRtnNegoOrder(Box<NegoOrderField>),
    OnErrRtnNegoOrderInsert(Box<InputNegoOrderField>, Box<RspInfoField>, i32),
    OnRtnNegoTrade(Box<NegoTradeField>),
    OnRspNegoOrderAction(Box<InputNegoOrderActionField>, Box<RspInfoField>, i32),
    OnErrRtnNegoOrderAction(Box<InputNegoOrderActionField>, Box<RspInfoField>, i32),
    OnRspOrderInsertEx(Box<InputOrderExField>, Box<RspInfoField>, i32),
    OnRspOrderActionEx(Box<InputOrderActionExField>, Box<RspInfoField>, i32),
    OnRtnMarketStatus(Box<MarketStatusField>),
    OnRspTransferFund(Box<InputTransferFundField>, Box<RspInfoField>, i32),
    OnErrRtnTransferFund(Box<InputTransferFundField>, Box<RspInfoField>, i32),
    OnRtnTransferFund(Box<TransferFundField>),
    OnRspTransferPosition(Box<InputTransferPositionField>, Box<RspInfoField>, i32),
    OnErrRtnTransferPosition(Box<InputTransferPositionField>, Box<RspInfoField>, i32),
    OnRtnTransferPosition(Box<TransferPositionField>),
    OnRtnPeripheryTransferPosition(Box<PeripheryTransferPositionField>),
    OnRtnPeripheryTransferFund(Box<PeripheryTransferFundField>),
    OnRspInquiryJZFund(Box<RspInquiryJZFundField>, Box<RspInfoField>, i32),
    OnRspInquiryBankAccountFund(Box<RspInquiryBankAccountFundField>, Box<RspInfoField>, i32),
    OnRtnTradingNotice(Box<TradingNoticeField>),
    OnRspInquiryMaxOrderVolume(Box<RspInquiryMaxOrderVolumeField>, Box<RspInfoField>, i32),
    OnRspInquiryTradeConcentration(Box<InquiryTradeConcentrationField>, Box<RspInfoField>, i32),
    OnRspModifyOpenPosCost(Box<ReqModifyOpenPosCostField>, Box<RspInfoField>, i32),
    OnRspInputNodeFundAssignment(Box<InputNodeFundAssignmentField>, Box<RspInfoField>, i32),
    OnRspInquiryNodeFundAssignment(Box<RspInquiryNodeFundAssignmentField>, Box<RspInfoField>, i32),
    OnRspQryExchange(Box<ExchangeField>, Box<RspInfoField>, i32, bool),
    OnRspQrySecurity(Box<SecurityField>, Box<RspInfoField>, i32, bool),
    OnRspQryIPOInfo(Box<IPOInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryUser(Box<UserField>, Box<RspInfoField>, i32, bool),
    OnRspQryInvestor(Box<InvestorField>, Box<RspInfoField>, i32, bool),
    OnRspQryShareholderAccount(Box<ShareholderAccountField>, Box<RspInfoField>, i32, bool),
    OnRspQryRationalInfo(Box<RationalInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryOrder(Box<OrderField>, Box<RspInfoField>, i32, bool),
    OnRspQryOrderAction(Box<OrderActionField>, Box<RspInfoField>, i32, bool),
    OnRspQryTrade(Box<TradeField>, Box<RspInfoField>, i32, bool),
    OnRspQryTradingAccount(Box<TradingAccountField>, Box<RspInfoField>, i32, bool),
    OnRspQryPosition(Box<PositionField>, Box<RspInfoField>, i32, bool),
    OnRspQryTradingFee(Box<TradingFeeField>, Box<RspInfoField>, i32, bool),
    OnRspQryInvestorTradingFee(Box<InvestorTradingFeeField>, Box<RspInfoField>, i32, bool),
    OnRspQryIPOQuota(Box<IPOQuotaField>, Box<RspInfoField>, i32, bool),
    OnRspQryOrderFundDetail(Box<OrderFundDetailField>, Box<RspInfoField>, i32, bool),
    OnRspQryFundTransferDetail(Box<FundTransferDetailField>, Box<RspInfoField>, i32, bool),
    OnRspQryPositionTransferDetail(Box<PositionTransferDetailField>, Box<RspInfoField>, i32, bool),
    OnRspQryPeripheryPositionTransferDetail(Box<PeripheryPositionTransferDetailField>, Box<RspInfoField>, i32, bool),
    OnRspQryPeripheryFundTransferDetail(Box<PeripheryFundTransferDetailField>, Box<RspInfoField>, i32, bool),
    OnRspQryBondConversionInfo(Box<BondConversionInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryBondPutbackInfo(Box<BondPutbackInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryInvestorCondOrderLimitParam(Box<InvestorCondOrderLimitParamField>, Box<RspInfoField>, i32, bool),
    OnRspQryConditionOrder(Box<ConditionOrderField>, Box<RspInfoField>, i32, bool),
    OnRspQryCondOrderAction(Box<CondOrderActionField>, Box<RspInfoField>, i32, bool),
    OnRspQryTradingNotice(Box<TradingNoticeField>, Box<RspInfoField>, i32, bool),
    OnRspQryIPONumberResult(Box<IPONumberResultField>, Box<RspInfoField>, i32, bool),
    OnRspQryIPOMatchNumberResult(Box<IPOMatchNumberResultField>, Box<RspInfoField>, i32, bool),
    OnRspQryShareholderSpecPrivilege(Box<ShareholderSpecPrivilegeField>, Box<RspInfoField>, i32, bool),
    OnRspQryMarket(Box<MarketField>, Box<RspInfoField>, i32, bool),
    OnRspQryETFFile(Box<ETFFileField>, Box<RspInfoField>, i32, bool),
    OnRspQryETFBasket(Box<ETFBasketField>, Box<RspInfoField>, i32, bool),
    OnRspQryInvestorPositionLimit(Box<InvestorPositionLimitField>, Box<RspInfoField>, i32, bool),
    OnRspQryImcParams(Box<ImcParamsField>, Box<RspInfoField>, i32, bool),
    OnRspQryImcExchangeRate(Box<ImcExchangeRateField>, Box<RspInfoField>, i32, bool),
    OnRspQryHKPriceTickInfo(Box<HKPriceTickInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryLofFundInfo(Box<LofFundInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryPledgePosition(Box<PledgePositionField>, Box<RspInfoField>, i32, bool),
    OnRspQryPledgeInfo(Box<PledgeInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQrySystemNodeInfo(Box<SystemNodeInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryStandardBondPosition(Box<StandardBondPositionField>, Box<RspInfoField>, i32, bool),
    OnRspQryPrematurityRepoOrder(Box<PrematurityRepoOrderField>, Box<RspInfoField>, i32, bool),
    OnRspQryNegoOrder(Box<NegoOrderField>, Box<RspInfoField>, i32, bool),
    OnRspQryNegoOrderAction(Box<NegoOrderActionField>, Box<RspInfoField>, i32, bool),
    OnRspQryNegoTrade(Box<NegoTradeField>, Box<RspInfoField>, i32, bool),
    OnRspQryNegotiationParam(Box<NegotiationParamField>, Box<RspInfoField>, i32, bool),
    OnRspQryPublicOfferedFundInfo(Box<PublicOfferedFundInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryPublicOfferedFundTradeDetail(Box<PublicOfferedFundTradeDetailField>, Box<RspInfoField>, i32, bool),
    OnRspQryTenderInfo(Box<TenderInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryAdditionalOfferingInfo(Box<AdditionalOfferingInfoField>, Box<RspInfoField>, i32, bool),
    OnRspQryAdditionalOfferingQuota(Box<AdditionalOfferingQuotaField>, Box<RspInfoField>, i32, bool),
    OnRspForceUserExit(Box<ForceUserLogoutField>, Box<RspInfoField>, i32),
    OnRspForceUserLogout(Box<ForceUserLogoutField>, Box<RspInfoField>, i32),
    OnRspActivateUser(Box<ActivateUserField>, Box<RspInfoField>, i32),
}

pub struct TraderSpi {
    tx: Sender<TraderSpiMsg>,
}

impl TraderSpi {
    pub fn OnFrontConnected(&self) { self.tx.send(TraderSpiMsg::OnFrontConnected).ok(); }
    pub fn OnFrontDisconnected(&self, nReason: i32) { self.tx.send(TraderSpiMsg::OnFrontDisconnected(nReason)).ok(); }
    pub fn OnRspError(&self, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspError(Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspGetConnectionInfo(&self, pConnectionInfoField: ConnectionInfoField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspGetConnectionInfo(Box::new(pConnectionInfoField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspUserLogin(&self, pRspUserLoginField: RspUserLoginField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspUserLogin(Box::new(pRspUserLoginField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspUserLogout(&self, pUserLogoutField: UserLogoutField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspUserLogout(Box::new(pUserLogoutField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspUserPasswordUpdate(&self, pUserPasswordUpdateField: UserPasswordUpdateField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspUserPasswordUpdate(Box::new(pUserPasswordUpdateField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspInputDeviceSerial(&self, pRspInputDeviceSerialField: RspInputDeviceSerialField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspInputDeviceSerial(Box::new(pRspInputDeviceSerialField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspOrderInsert(&self, pInputOrderField: InputOrderField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspOrderInsert(Box::new(pInputOrderField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspPublicOfferedFundOrderInsert(&self, pInputOrderField: InputOrderField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspPublicOfferedFundOrderInsert(Box::new(pInputOrderField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRtnOrder(&self, pOrderField: OrderField) { self.tx.send(TraderSpiMsg::OnRtnOrder(Box::new(pOrderField))).ok(); }
    pub fn OnErrRtnOrderInsert(&self, pInputOrderField: InputOrderField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnErrRtnOrderInsert(Box::new(pInputOrderField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRtnTrade(&self, pTradeField: TradeField) { self.tx.send(TraderSpiMsg::OnRtnTrade(Box::new(pTradeField))).ok(); }
    pub fn OnRspOrderAction(&self, pInputOrderActionField: InputOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspOrderAction(Box::new(pInputOrderActionField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnErrRtnOrderAction(&self, pInputOrderActionField: InputOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnErrRtnOrderAction(Box::new(pInputOrderActionField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspCondOrderInsert(&self, pInputCondOrderField: InputCondOrderField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspCondOrderInsert(Box::new(pInputCondOrderField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRtnCondOrder(&self, pConditionOrderField: ConditionOrderField) { self.tx.send(TraderSpiMsg::OnRtnCondOrder(Box::new(pConditionOrderField))).ok(); }
    pub fn OnErrRtnCondOrderInsert(&self, pInputCondOrderField: InputCondOrderField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnErrRtnCondOrderInsert(Box::new(pInputCondOrderField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspCondOrderAction(&self, pInputCondOrderActionField: InputCondOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspCondOrderAction(Box::new(pInputCondOrderActionField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnErrRtnCondOrderAction(&self, pInputCondOrderActionField: InputCondOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnErrRtnCondOrderAction(Box::new(pInputCondOrderActionField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspNegoOrderInsert(&self, pInputNegoOrderField: InputNegoOrderField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspNegoOrderInsert(Box::new(pInputNegoOrderField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRtnNegoOrder(&self, pNegoOrderField: NegoOrderField) { self.tx.send(TraderSpiMsg::OnRtnNegoOrder(Box::new(pNegoOrderField))).ok(); }
    pub fn OnErrRtnNegoOrderInsert(&self, pInputNegoOrderField: InputNegoOrderField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnErrRtnNegoOrderInsert(Box::new(pInputNegoOrderField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRtnNegoTrade(&self, pNegoTradeField: NegoTradeField) { self.tx.send(TraderSpiMsg::OnRtnNegoTrade(Box::new(pNegoTradeField))).ok(); }
    pub fn OnRspNegoOrderAction(&self, pInputNegoOrderActionField: InputNegoOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspNegoOrderAction(Box::new(pInputNegoOrderActionField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnErrRtnNegoOrderAction(&self, pInputNegoOrderActionField: InputNegoOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnErrRtnNegoOrderAction(Box::new(pInputNegoOrderActionField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspOrderInsertEx(&self, pInputOrderExField: InputOrderExField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspOrderInsertEx(Box::new(pInputOrderExField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspOrderActionEx(&self, pInputOrderActionExField: InputOrderActionExField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspOrderActionEx(Box::new(pInputOrderActionExField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRtnMarketStatus(&self, pMarketStatusField: MarketStatusField) { self.tx.send(TraderSpiMsg::OnRtnMarketStatus(Box::new(pMarketStatusField))).ok(); }
    pub fn OnRspTransferFund(&self, pInputTransferFundField: InputTransferFundField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspTransferFund(Box::new(pInputTransferFundField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnErrRtnTransferFund(&self, pInputTransferFundField: InputTransferFundField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnErrRtnTransferFund(Box::new(pInputTransferFundField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRtnTransferFund(&self, pTransferFundField: TransferFundField) { self.tx.send(TraderSpiMsg::OnRtnTransferFund(Box::new(pTransferFundField))).ok(); }
    pub fn OnRspTransferPosition(&self, pInputTransferPositionField: InputTransferPositionField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspTransferPosition(Box::new(pInputTransferPositionField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnErrRtnTransferPosition(&self, pInputTransferPositionField: InputTransferPositionField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnErrRtnTransferPosition(Box::new(pInputTransferPositionField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRtnTransferPosition(&self, pTransferPositionField: TransferPositionField) { self.tx.send(TraderSpiMsg::OnRtnTransferPosition(Box::new(pTransferPositionField))).ok(); }
    pub fn OnRtnPeripheryTransferPosition(&self, pPeripheryTransferPositionField: PeripheryTransferPositionField) { self.tx.send(TraderSpiMsg::OnRtnPeripheryTransferPosition(Box::new(pPeripheryTransferPositionField))).ok(); }
    pub fn OnRtnPeripheryTransferFund(&self, pPeripheryTransferFundField: PeripheryTransferFundField) { self.tx.send(TraderSpiMsg::OnRtnPeripheryTransferFund(Box::new(pPeripheryTransferFundField))).ok(); }
    pub fn OnRspInquiryJZFund(&self, pRspInquiryJZFundField: RspInquiryJZFundField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspInquiryJZFund(Box::new(pRspInquiryJZFundField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspInquiryBankAccountFund(&self, pRspInquiryBankAccountFundField: RspInquiryBankAccountFundField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspInquiryBankAccountFund(Box::new(pRspInquiryBankAccountFundField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRtnTradingNotice(&self, pTradingNoticeField: TradingNoticeField) { self.tx.send(TraderSpiMsg::OnRtnTradingNotice(Box::new(pTradingNoticeField))).ok(); }
    pub fn OnRspInquiryMaxOrderVolume(&self, pRspInquiryMaxOrderVolumeField: RspInquiryMaxOrderVolumeField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspInquiryMaxOrderVolume(Box::new(pRspInquiryMaxOrderVolumeField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspInquiryTradeConcentration(&self, pInquiryTradeConcentrationField: InquiryTradeConcentrationField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspInquiryTradeConcentration(Box::new(pInquiryTradeConcentrationField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspModifyOpenPosCost(&self, pReqModifyOpenPosCostField: ReqModifyOpenPosCostField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspModifyOpenPosCost(Box::new(pReqModifyOpenPosCostField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspInputNodeFundAssignment(&self, pInputNodeFundAssignmentField: InputNodeFundAssignmentField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspInputNodeFundAssignment(Box::new(pInputNodeFundAssignmentField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspInquiryNodeFundAssignment(&self, pRspInquiryNodeFundAssignmentField: RspInquiryNodeFundAssignmentField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspInquiryNodeFundAssignment(Box::new(pRspInquiryNodeFundAssignmentField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspQryExchange(&self, pExchangeField: ExchangeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryExchange(Box::new(pExchangeField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQrySecurity(&self, pSecurityField: SecurityField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQrySecurity(Box::new(pSecurityField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryIPOInfo(&self, pIPOInfoField: IPOInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryIPOInfo(Box::new(pIPOInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryUser(&self, pUserField: UserField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryUser(Box::new(pUserField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryInvestor(&self, pInvestorField: InvestorField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryInvestor(Box::new(pInvestorField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryShareholderAccount(&self, pShareholderAccountField: ShareholderAccountField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryShareholderAccount(Box::new(pShareholderAccountField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryRationalInfo(&self, pRationalInfoField: RationalInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryRationalInfo(Box::new(pRationalInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryOrder(&self, pOrderField: OrderField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryOrder(Box::new(pOrderField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryOrderAction(&self, pOrderActionField: OrderActionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryOrderAction(Box::new(pOrderActionField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryTrade(&self, pTradeField: TradeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryTrade(Box::new(pTradeField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryTradingAccount(&self, pTradingAccountField: TradingAccountField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryTradingAccount(Box::new(pTradingAccountField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryPosition(&self, pPositionField: PositionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryPosition(Box::new(pPositionField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryTradingFee(&self, pTradingFeeField: TradingFeeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryTradingFee(Box::new(pTradingFeeField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryInvestorTradingFee(&self, pInvestorTradingFeeField: InvestorTradingFeeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryInvestorTradingFee(Box::new(pInvestorTradingFeeField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryIPOQuota(&self, pIPOQuotaField: IPOQuotaField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryIPOQuota(Box::new(pIPOQuotaField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryOrderFundDetail(&self, pOrderFundDetailField: OrderFundDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryOrderFundDetail(Box::new(pOrderFundDetailField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryFundTransferDetail(&self, pFundTransferDetailField: FundTransferDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryFundTransferDetail(Box::new(pFundTransferDetailField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryPositionTransferDetail(&self, pPositionTransferDetailField: PositionTransferDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryPositionTransferDetail(Box::new(pPositionTransferDetailField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryPeripheryPositionTransferDetail(&self, pPeripheryPositionTransferDetailField: PeripheryPositionTransferDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryPeripheryPositionTransferDetail(Box::new(pPeripheryPositionTransferDetailField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryPeripheryFundTransferDetail(&self, pPeripheryFundTransferDetailField: PeripheryFundTransferDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryPeripheryFundTransferDetail(Box::new(pPeripheryFundTransferDetailField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryBondConversionInfo(&self, pBondConversionInfoField: BondConversionInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryBondConversionInfo(Box::new(pBondConversionInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryBondPutbackInfo(&self, pBondPutbackInfoField: BondPutbackInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryBondPutbackInfo(Box::new(pBondPutbackInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryInvestorCondOrderLimitParam(&self, pInvestorCondOrderLimitParamField: InvestorCondOrderLimitParamField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryInvestorCondOrderLimitParam(Box::new(pInvestorCondOrderLimitParamField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryConditionOrder(&self, pConditionOrderField: ConditionOrderField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryConditionOrder(Box::new(pConditionOrderField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryCondOrderAction(&self, pCondOrderActionField: CondOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryCondOrderAction(Box::new(pCondOrderActionField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryTradingNotice(&self, pTradingNoticeField: TradingNoticeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryTradingNotice(Box::new(pTradingNoticeField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryIPONumberResult(&self, pIPONumberResultField: IPONumberResultField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryIPONumberResult(Box::new(pIPONumberResultField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryIPOMatchNumberResult(&self, pIPOMatchNumberResultField: IPOMatchNumberResultField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryIPOMatchNumberResult(Box::new(pIPOMatchNumberResultField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryShareholderSpecPrivilege(&self, pShareholderSpecPrivilegeField: ShareholderSpecPrivilegeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryShareholderSpecPrivilege(Box::new(pShareholderSpecPrivilegeField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryMarket(&self, pMarketField: MarketField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryMarket(Box::new(pMarketField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryETFFile(&self, pETFFileField: ETFFileField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryETFFile(Box::new(pETFFileField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryETFBasket(&self, pETFBasketField: ETFBasketField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryETFBasket(Box::new(pETFBasketField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryInvestorPositionLimit(&self, pInvestorPositionLimitField: InvestorPositionLimitField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryInvestorPositionLimit(Box::new(pInvestorPositionLimitField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryImcParams(&self, pImcParamsField: ImcParamsField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryImcParams(Box::new(pImcParamsField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryImcExchangeRate(&self, pImcExchangeRateField: ImcExchangeRateField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryImcExchangeRate(Box::new(pImcExchangeRateField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryHKPriceTickInfo(&self, pHKPriceTickInfoField: HKPriceTickInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryHKPriceTickInfo(Box::new(pHKPriceTickInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryLofFundInfo(&self, pLofFundInfoField: LofFundInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryLofFundInfo(Box::new(pLofFundInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryPledgePosition(&self, pPledgePositionField: PledgePositionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryPledgePosition(Box::new(pPledgePositionField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryPledgeInfo(&self, pPledgeInfoField: PledgeInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryPledgeInfo(Box::new(pPledgeInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQrySystemNodeInfo(&self, pSystemNodeInfoField: SystemNodeInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQrySystemNodeInfo(Box::new(pSystemNodeInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryStandardBondPosition(&self, pStandardBondPositionField: StandardBondPositionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryStandardBondPosition(Box::new(pStandardBondPositionField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryPrematurityRepoOrder(&self, pPrematurityRepoOrderField: PrematurityRepoOrderField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryPrematurityRepoOrder(Box::new(pPrematurityRepoOrderField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryNegoOrder(&self, pNegoOrderField: NegoOrderField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryNegoOrder(Box::new(pNegoOrderField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryNegoOrderAction(&self, pNegoOrderActionField: NegoOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryNegoOrderAction(Box::new(pNegoOrderActionField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryNegoTrade(&self, pNegoTradeField: NegoTradeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryNegoTrade(Box::new(pNegoTradeField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryNegotiationParam(&self, pNegotiationParamField: NegotiationParamField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryNegotiationParam(Box::new(pNegotiationParamField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryPublicOfferedFundInfo(&self, pPublicOfferedFundInfoField: PublicOfferedFundInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryPublicOfferedFundInfo(Box::new(pPublicOfferedFundInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryPublicOfferedFundTradeDetail(&self, pPublicOfferedFundTradeDetailField: PublicOfferedFundTradeDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryPublicOfferedFundTradeDetail(Box::new(pPublicOfferedFundTradeDetailField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryTenderInfo(&self, pTenderInfoField: TenderInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryTenderInfo(Box::new(pTenderInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryAdditionalOfferingInfo(&self, pAdditionalOfferingInfoField: AdditionalOfferingInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryAdditionalOfferingInfo(Box::new(pAdditionalOfferingInfoField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspQryAdditionalOfferingQuota(&self, pAdditionalOfferingQuotaField: AdditionalOfferingQuotaField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool) { self.tx.send(TraderSpiMsg::OnRspQryAdditionalOfferingQuota(Box::new(pAdditionalOfferingQuotaField), Box::new(pRspInfoField), nRequestID, bIsLast)).ok(); }
    pub fn OnRspForceUserExit(&self, pForceUserLogoutField: ForceUserLogoutField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspForceUserExit(Box::new(pForceUserLogoutField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspForceUserLogout(&self, pForceUserLogoutField: ForceUserLogoutField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspForceUserLogout(Box::new(pForceUserLogoutField), Box::new(pRspInfoField), nRequestID)).ok(); }
    pub fn OnRspActivateUser(&self, pActivateUserField: ActivateUserField, pRspInfoField: RspInfoField, nRequestID: i32) { self.tx.send(TraderSpiMsg::OnRspActivateUser(Box::new(pActivateUserField), Box::new(pRspInfoField), nRequestID)).ok(); }
}

#[cxx::bridge(namespace = "tora_trader")]
mod ffi {
    extern "Rust" {
        type TraderSpi;
        pub fn OnFrontConnected(&self);
        pub fn OnFrontDisconnected(&self, nReason: i32);
        pub fn OnRspError(&self, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspGetConnectionInfo(&self, pConnectionInfoField: ConnectionInfoField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspUserLogin(&self, pRspUserLoginField: RspUserLoginField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspUserLogout(&self, pUserLogoutField: UserLogoutField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspUserPasswordUpdate(&self, pUserPasswordUpdateField: UserPasswordUpdateField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspInputDeviceSerial(&self, pRspInputDeviceSerialField: RspInputDeviceSerialField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspOrderInsert(&self, pInputOrderField: InputOrderField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspPublicOfferedFundOrderInsert(&self, pInputOrderField: InputOrderField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRtnOrder(&self, pOrderField: OrderField);
        pub fn OnErrRtnOrderInsert(&self, pInputOrderField: InputOrderField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRtnTrade(&self, pTradeField: TradeField);
        pub fn OnRspOrderAction(&self, pInputOrderActionField: InputOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnErrRtnOrderAction(&self, pInputOrderActionField: InputOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspCondOrderInsert(&self, pInputCondOrderField: InputCondOrderField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRtnCondOrder(&self, pConditionOrderField: ConditionOrderField);
        pub fn OnErrRtnCondOrderInsert(&self, pInputCondOrderField: InputCondOrderField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspCondOrderAction(&self, pInputCondOrderActionField: InputCondOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnErrRtnCondOrderAction(&self, pInputCondOrderActionField: InputCondOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspNegoOrderInsert(&self, pInputNegoOrderField: InputNegoOrderField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRtnNegoOrder(&self, pNegoOrderField: NegoOrderField);
        pub fn OnErrRtnNegoOrderInsert(&self, pInputNegoOrderField: InputNegoOrderField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRtnNegoTrade(&self, pNegoTradeField: NegoTradeField);
        pub fn OnRspNegoOrderAction(&self, pInputNegoOrderActionField: InputNegoOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnErrRtnNegoOrderAction(&self, pInputNegoOrderActionField: InputNegoOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspOrderInsertEx(&self, pInputOrderExField: InputOrderExField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspOrderActionEx(&self, pInputOrderActionExField: InputOrderActionExField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRtnMarketStatus(&self, pMarketStatusField: MarketStatusField);
        pub fn OnRspTransferFund(&self, pInputTransferFundField: InputTransferFundField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnErrRtnTransferFund(&self, pInputTransferFundField: InputTransferFundField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRtnTransferFund(&self, pTransferFundField: TransferFundField);
        pub fn OnRspTransferPosition(&self, pInputTransferPositionField: InputTransferPositionField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnErrRtnTransferPosition(&self, pInputTransferPositionField: InputTransferPositionField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRtnTransferPosition(&self, pTransferPositionField: TransferPositionField);
        pub fn OnRtnPeripheryTransferPosition(&self, pPeripheryTransferPositionField: PeripheryTransferPositionField);
        pub fn OnRtnPeripheryTransferFund(&self, pPeripheryTransferFundField: PeripheryTransferFundField);
        pub fn OnRspInquiryJZFund(&self, pRspInquiryJZFundField: RspInquiryJZFundField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspInquiryBankAccountFund(&self, pRspInquiryBankAccountFundField: RspInquiryBankAccountFundField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRtnTradingNotice(&self, pTradingNoticeField: TradingNoticeField);
        pub fn OnRspInquiryMaxOrderVolume(&self, pRspInquiryMaxOrderVolumeField: RspInquiryMaxOrderVolumeField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspInquiryTradeConcentration(&self, pInquiryTradeConcentrationField: InquiryTradeConcentrationField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspModifyOpenPosCost(&self, pReqModifyOpenPosCostField: ReqModifyOpenPosCostField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspInputNodeFundAssignment(&self, pInputNodeFundAssignmentField: InputNodeFundAssignmentField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspInquiryNodeFundAssignment(&self, pRspInquiryNodeFundAssignmentField: RspInquiryNodeFundAssignmentField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspQryExchange(&self, pExchangeField: ExchangeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQrySecurity(&self, pSecurityField: SecurityField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryIPOInfo(&self, pIPOInfoField: IPOInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryUser(&self, pUserField: UserField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryInvestor(&self, pInvestorField: InvestorField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryShareholderAccount(&self, pShareholderAccountField: ShareholderAccountField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryRationalInfo(&self, pRationalInfoField: RationalInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryOrder(&self, pOrderField: OrderField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryOrderAction(&self, pOrderActionField: OrderActionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryTrade(&self, pTradeField: TradeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryTradingAccount(&self, pTradingAccountField: TradingAccountField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryPosition(&self, pPositionField: PositionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryTradingFee(&self, pTradingFeeField: TradingFeeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryInvestorTradingFee(&self, pInvestorTradingFeeField: InvestorTradingFeeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryIPOQuota(&self, pIPOQuotaField: IPOQuotaField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryOrderFundDetail(&self, pOrderFundDetailField: OrderFundDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryFundTransferDetail(&self, pFundTransferDetailField: FundTransferDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryPositionTransferDetail(&self, pPositionTransferDetailField: PositionTransferDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryPeripheryPositionTransferDetail(&self, pPeripheryPositionTransferDetailField: PeripheryPositionTransferDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryPeripheryFundTransferDetail(&self, pPeripheryFundTransferDetailField: PeripheryFundTransferDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryBondConversionInfo(&self, pBondConversionInfoField: BondConversionInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryBondPutbackInfo(&self, pBondPutbackInfoField: BondPutbackInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryInvestorCondOrderLimitParam(&self, pInvestorCondOrderLimitParamField: InvestorCondOrderLimitParamField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryConditionOrder(&self, pConditionOrderField: ConditionOrderField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryCondOrderAction(&self, pCondOrderActionField: CondOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryTradingNotice(&self, pTradingNoticeField: TradingNoticeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryIPONumberResult(&self, pIPONumberResultField: IPONumberResultField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryIPOMatchNumberResult(&self, pIPOMatchNumberResultField: IPOMatchNumberResultField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryShareholderSpecPrivilege(&self, pShareholderSpecPrivilegeField: ShareholderSpecPrivilegeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryMarket(&self, pMarketField: MarketField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryETFFile(&self, pETFFileField: ETFFileField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryETFBasket(&self, pETFBasketField: ETFBasketField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryInvestorPositionLimit(&self, pInvestorPositionLimitField: InvestorPositionLimitField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryImcParams(&self, pImcParamsField: ImcParamsField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryImcExchangeRate(&self, pImcExchangeRateField: ImcExchangeRateField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryHKPriceTickInfo(&self, pHKPriceTickInfoField: HKPriceTickInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryLofFundInfo(&self, pLofFundInfoField: LofFundInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryPledgePosition(&self, pPledgePositionField: PledgePositionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryPledgeInfo(&self, pPledgeInfoField: PledgeInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQrySystemNodeInfo(&self, pSystemNodeInfoField: SystemNodeInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryStandardBondPosition(&self, pStandardBondPositionField: StandardBondPositionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryPrematurityRepoOrder(&self, pPrematurityRepoOrderField: PrematurityRepoOrderField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryNegoOrder(&self, pNegoOrderField: NegoOrderField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryNegoOrderAction(&self, pNegoOrderActionField: NegoOrderActionField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryNegoTrade(&self, pNegoTradeField: NegoTradeField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryNegotiationParam(&self, pNegotiationParamField: NegotiationParamField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryPublicOfferedFundInfo(&self, pPublicOfferedFundInfoField: PublicOfferedFundInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryPublicOfferedFundTradeDetail(&self, pPublicOfferedFundTradeDetailField: PublicOfferedFundTradeDetailField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryTenderInfo(&self, pTenderInfoField: TenderInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryAdditionalOfferingInfo(&self, pAdditionalOfferingInfoField: AdditionalOfferingInfoField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspQryAdditionalOfferingQuota(&self, pAdditionalOfferingQuotaField: AdditionalOfferingQuotaField, pRspInfoField: RspInfoField, nRequestID: i32, bIsLast: bool);
        pub fn OnRspForceUserExit(&self, pForceUserLogoutField: ForceUserLogoutField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspForceUserLogout(&self, pForceUserLogoutField: ForceUserLogoutField, pRspInfoField: RspInfoField, nRequestID: i32);
        pub fn OnRspActivateUser(&self, pActivateUserField: ActivateUserField, pRspInfoField: RspInfoField, nRequestID: i32);
    }

    unsafe extern "C++" {
        include!("tora-rs/wrapper/include/TraderApi.h");
        type TraderApi;
        fn CreateTraderApi(spi: Box<TraderSpi>, flow_path: String, is_encrypt: bool, trade_comm_mode: u8, interface_addr: String, is_using_order_ex: bool) -> UniquePtr<TraderApi>;
        /// 获取API版本号
        ///
        /// # Returns
        /// 版本号
        fn GetApiVersion(&self) -> String;
        /// 初始化
        ///
        /// # Remarks
        /// 初始化运行环境,只有调用后,接口才开始工作
        fn Init(&self);
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
        /// RegisterNameServer和RegisterFront任选其一。
        fn RegisterNameServer(&self, pszNsAddress: String);
        /// 注册名字服务器用户信息
        ///
        /// # Parameters
        /// - `pFensUserInfoField` — 用户信息。
        fn RegisterFensUserInfo(&self, pFensUserInfoField: FensUserInfoField);
        /// 订阅私有流
        ///
        /// # Parameters
        /// - `nResumeType` — 私有流重传方式
        ///   - TORA_TERT_RESTART:从本交易日开始重传
        ///   - TORA_TERT_RESUME:从上次收到的续传
        ///   - TORA_TERT_QUICK:只传送登录后私有流的内容
        ///
        /// # Remarks
        /// 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
        fn SubscribePrivateTopic(&self, nResumeType: i32);
        /// 订阅公共流
        ///
        /// # Parameters
        /// - `nResumeType` — 公共流重传方式
        ///   - TORA_TERT_RESTART:从本交易日开始重传
        ///   - TORA_TERT_RESUME:从上次收到的续传
        ///   - TORA_TERT_QUICK:只传送登录后公共流的内容
        ///
        /// # Remarks
        /// 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
        fn SubscribePublicTopic(&self, nResumeType: i32);
        /// 获取连接信息
        fn ReqGetConnectionInfo(&self, nRequestID: i32) -> i32;
        /// 登录请求
        fn ReqUserLogin(&self, pReqUserLoginField: ReqUserLoginField, nRequestID: i32) -> i32;
        /// 登出请求
        fn ReqUserLogout(&self, pUserLogoutField: UserLogoutField, nRequestID: i32) -> i32;
        /// 修改密码请求
        fn ReqUserPasswordUpdate(&self, pUserPasswordUpdateField: UserPasswordUpdateField, nRequestID: i32) -> i32;
        /// 录入设备序列请求
        fn ReqInputDeviceSerial(&self, pReqInputDeviceSerialField: ReqInputDeviceSerialField, nRequestID: i32) -> i32;
        /// 报单录入请求
        fn ReqOrderInsert(&self, pInputOrderField: InputOrderField, nRequestID: i32) -> i32;
        /// 公募基金管理人调仓报单请求
        fn ReqPublicOfferedFundOrderInsert(&self, pInputOrderField: InputOrderField, nRequestID: i32) -> i32;
        /// 撤单请求
        fn ReqOrderAction(&self, pInputOrderActionField: InputOrderActionField, nRequestID: i32) -> i32;
        /// 条件单录入请求
        fn ReqCondOrderInsert(&self, pInputCondOrderField: InputCondOrderField, nRequestID: i32) -> i32;
        /// 条件单撤单请求
        fn ReqCondOrderAction(&self, pInputCondOrderActionField: InputCondOrderActionField, nRequestID: i32) -> i32;
        /// 协议交易报单录入请求
        fn ReqNegoOrderInsert(&self, pInputNegoOrderField: InputNegoOrderField, nRequestID: i32) -> i32;
        /// 协议交易报单操作录入请求
        fn ReqNegoOrderAction(&self, pInputNegoOrderActionField: InputNegoOrderActionField, nRequestID: i32) -> i32;
        /// 报单录入请求（扩展）
        fn ReqOrderInsertEx(&self, pInputOrderExField: InputOrderExField, nRequestID: i32) -> i32;
        /// 报单操作请求（扩展）
        fn ReqOrderActionEx(&self, pInputOrderActionExField: InputOrderActionExField, nRequestID: i32) -> i32;
        /// 资金转移请求
        fn ReqTransferFund(&self, pInputTransferFundField: InputTransferFundField, nRequestID: i32) -> i32;
        /// 仓位转移请求
        fn ReqTransferPosition(&self, pInputTransferPositionField: InputTransferPositionField, nRequestID: i32) -> i32;
        /// 查询集中交易系统资金请求
        fn ReqInquiryJZFund(&self, pReqInquiryJZFundField: ReqInquiryJZFundField, nRequestID: i32) -> i32;
        /// 查询银行账户余额请求
        fn ReqInquiryBankAccountFund(&self, pReqInquiryBankAccountFundField: ReqInquiryBankAccountFundField, nRequestID: i32) -> i32;
        /// 查询最大报单量请求
        fn ReqInquiryMaxOrderVolume(&self, pReqInquiryMaxOrderVolumeField: ReqInquiryMaxOrderVolumeField, nRequestID: i32) -> i32;
        /// 查询交易成交集中度请求
        fn ReqInquiryTradeConcentration(&self, pInquiryTradeConcentrationField: InquiryTradeConcentrationField, nRequestID: i32) -> i32;
        /// 请求修改开仓成本请求
        fn ReqModifyOpenPosCost(&self, pReqModifyOpenPosCostField: ReqModifyOpenPosCostField, nRequestID: i32) -> i32;
        /// 录入节点资金分配信息请求
        fn ReqInputNodeFundAssignment(&self, pInputNodeFundAssignmentField: InputNodeFundAssignmentField, nRequestID: i32) -> i32;
        /// 查询节点资金分配比例请求
        fn ReqInquiryNodeFundAssignment(&self, pReqInquiryNodeFundAssignmentField: ReqInquiryNodeFundAssignmentField, nRequestID: i32) -> i32;
        /// 查询交易所请求
        fn ReqQryExchange(&self, pQryExchangeField: QryExchangeField, nRequestID: i32) -> i32;
        /// 查询证券信息请求
        fn ReqQrySecurity(&self, pQrySecurityField: QrySecurityField, nRequestID: i32) -> i32;
        /// 查询新股信息请求
        fn ReqQryIPOInfo(&self, pQryIPOInfoField: QryIPOInfoField, nRequestID: i32) -> i32;
        /// 查询用户请求
        fn ReqQryUser(&self, pQryUserField: QryUserField, nRequestID: i32) -> i32;
        /// 查询投资者请求
        fn ReqQryInvestor(&self, pQryInvestorField: QryInvestorField, nRequestID: i32) -> i32;
        /// 查询股东账户请求
        fn ReqQryShareholderAccount(&self, pQryShareholderAccountField: QryShareholderAccountField, nRequestID: i32) -> i32;
        /// 查询配股配债信息请求
        fn ReqQryRationalInfo(&self, pQryRationalInfoField: QryRationalInfoField, nRequestID: i32) -> i32;
        /// 查询报单请求
        fn ReqQryOrder(&self, pQryOrderField: QryOrderField, nRequestID: i32) -> i32;
        /// 查询撤单请求
        fn ReqQryOrderAction(&self, pQryOrderActionField: QryOrderActionField, nRequestID: i32) -> i32;
        /// 查询成交请求
        fn ReqQryTrade(&self, pQryTradeField: QryTradeField, nRequestID: i32) -> i32;
        /// 查询资金账户请求
        fn ReqQryTradingAccount(&self, pQryTradingAccountField: QryTradingAccountField, nRequestID: i32) -> i32;
        /// 查询投资者持仓请求
        fn ReqQryPosition(&self, pQryPositionField: QryPositionField, nRequestID: i32) -> i32;
        /// 查询基础交易费率请求
        fn ReqQryTradingFee(&self, pQryTradingFeeField: QryTradingFeeField, nRequestID: i32) -> i32;
        /// 查询佣金费率请求
        fn ReqQryInvestorTradingFee(&self, pQryInvestorTradingFeeField: QryInvestorTradingFeeField, nRequestID: i32) -> i32;
        /// 查询新股申购额度请求
        fn ReqQryIPOQuota(&self, pQryIPOQuotaField: QryIPOQuotaField, nRequestID: i32) -> i32;
        /// 查询报单明细资金请求
        fn ReqQryOrderFundDetail(&self, pQryOrderFundDetailField: QryOrderFundDetailField, nRequestID: i32) -> i32;
        /// 查询资金转移流水请求
        fn ReqQryFundTransferDetail(&self, pQryFundTransferDetailField: QryFundTransferDetailField, nRequestID: i32) -> i32;
        /// 查询持仓转移流水请求
        fn ReqQryPositionTransferDetail(&self, pQryPositionTransferDetailField: QryPositionTransferDetailField, nRequestID: i32) -> i32;
        /// 查询外围系统仓位调拨流水请求
        fn ReqQryPeripheryPositionTransferDetail(&self, pQryPeripheryPositionTransferDetailField: QryPeripheryPositionTransferDetailField, nRequestID: i32) -> i32;
        /// 查询外围系统资金调拨流水请求
        fn ReqQryPeripheryFundTransferDetail(&self, pQryPeripheryFundTransferDetailField: QryPeripheryFundTransferDetailField, nRequestID: i32) -> i32;
        /// 查询债券转股信息请求
        fn ReqQryBondConversionInfo(&self, pQryBondConversionInfoField: QryBondConversionInfoField, nRequestID: i32) -> i32;
        /// 查询债券回售信息请求
        fn ReqQryBondPutbackInfo(&self, pQryBondPutbackInfoField: QryBondPutbackInfoField, nRequestID: i32) -> i32;
        /// 查询投资者条件单限制参数请求
        fn ReqQryInvestorCondOrderLimitParam(&self, pQryInvestorCondOrderLimitParamField: QryInvestorCondOrderLimitParamField, nRequestID: i32) -> i32;
        /// 查询条件单请求
        fn ReqQryConditionOrder(&self, pQryConditionOrderField: QryConditionOrderField, nRequestID: i32) -> i32;
        /// 查询条件单撤单请求
        fn ReqQryCondOrderAction(&self, pQryCondOrderActionField: QryCondOrderActionField, nRequestID: i32) -> i32;
        /// 查询交易通知请求
        fn ReqQryTradingNotice(&self, pQryTradingNoticeField: QryTradingNoticeField, nRequestID: i32) -> i32;
        /// 查询新股申购配号结果请求
        fn ReqQryIPONumberResult(&self, pQryIPONumberResultField: QryIPONumberResultField, nRequestID: i32) -> i32;
        /// 查询新股申购中签结果请求
        fn ReqQryIPOMatchNumberResult(&self, pQryIPOMatchNumberResultField: QryIPOMatchNumberResultField, nRequestID: i32) -> i32;
        /// 查询交易协议请求
        fn ReqQryShareholderSpecPrivilege(&self, pQryShareholderSpecPrivilegeField: QryShareholderSpecPrivilegeField, nRequestID: i32) -> i32;
        /// 查询市场请求
        fn ReqQryMarket(&self, pQryMarketField: QryMarketField, nRequestID: i32) -> i32;
        /// 查询ETF清单信息请求
        fn ReqQryETFFile(&self, pQryETFFileField: QryETFFileField, nRequestID: i32) -> i32;
        /// 查询ETF成份证券信息请求
        fn ReqQryETFBasket(&self, pQryETFBasketField: QryETFBasketField, nRequestID: i32) -> i32;
        /// 查询投资者限仓信息请求
        fn ReqQryInvestorPositionLimit(&self, pQryInvestorPositionLimitField: QryInvestorPositionLimitField, nRequestID: i32) -> i32;
        /// 查询国际市场互联状态信息请求
        fn ReqQryImcParams(&self, pQryImcParamsField: QryImcParamsField, nRequestID: i32) -> i32;
        /// 查询国际市场互联汇率信息请求
        fn ReqQryImcExchangeRate(&self, pQryImcExchangeRateField: QryImcExchangeRateField, nRequestID: i32) -> i32;
        /// 查询最小价差信息请求
        fn ReqQryHKPriceTickInfo(&self, pQryHKPriceTickInfoField: QryHKPriceTickInfoField, nRequestID: i32) -> i32;
        /// 查询LOF基金信息请求
        fn ReqQryLofFundInfo(&self, pQryLofFundInfoField: QryLofFundInfoField, nRequestID: i32) -> i32;
        /// 查询投资者质押持仓请求
        fn ReqQryPledgePosition(&self, pQryPledgePositionField: QryPledgePositionField, nRequestID: i32) -> i32;
        /// 查询证券质押信息请求
        fn ReqQryPledgeInfo(&self, pQryPledgeInfoField: QryPledgeInfoField, nRequestID: i32) -> i32;
        /// 查询系统节点信息请求
        fn ReqQrySystemNodeInfo(&self, pQrySystemNodeInfoField: QrySystemNodeInfoField, nRequestID: i32) -> i32;
        /// 查询标准券额度请求
        fn ReqQryStandardBondPosition(&self, pQryStandardBondPositionField: QryStandardBondPositionField, nRequestID: i32) -> i32;
        /// 查询未到期债券质押回购委托请求
        fn ReqQryPrematurityRepoOrder(&self, pQryPrematurityRepoOrderField: QryPrematurityRepoOrderField, nRequestID: i32) -> i32;
        /// 查询协议交易报单请求
        fn ReqQryNegoOrder(&self, pQryNegoOrderField: QryNegoOrderField, nRequestID: i32) -> i32;
        /// 查询协议交易撤单请求
        fn ReqQryNegoOrderAction(&self, pQryNegoOrderActionField: QryNegoOrderActionField, nRequestID: i32) -> i32;
        /// 查询协议交易成交请求
        fn ReqQryNegoTrade(&self, pQryNegoTradeField: QryNegoTradeField, nRequestID: i32) -> i32;
        /// 查询协议交易参数请求
        fn ReqQryNegotiationParam(&self, pQryNegotiationParamField: QryNegotiationParamField, nRequestID: i32) -> i32;
        /// 查询公募基金发行信息请求
        fn ReqQryPublicOfferedFundInfo(&self, pQryPublicOfferedFundInfoField: QryPublicOfferedFundInfoField, nRequestID: i32) -> i32;
        /// 查询公募基金申赎成交明细请求
        fn ReqQryPublicOfferedFundTradeDetail(&self, pQryPublicOfferedFundTradeDetailField: QryPublicOfferedFundTradeDetailField, nRequestID: i32) -> i32;
        /// 查询要约收购信息
        fn ReqQryTenderInfo(&self, pQryTenderInfoField: QryTenderInfoField, nRequestID: i32) -> i32;
        /// 查询基础设施基金非定向扩募信息请求
        fn ReqQryAdditionalOfferingInfo(&self, pQryAdditionalOfferingInfoField: QryAdditionalOfferingInfoField, nRequestID: i32) -> i32;
        /// 查询基础设施基金非定向扩募配售额度请求
        fn ReqQryAdditionalOfferingQuota(&self, pQryAdditionalOfferingQuotaField: QryAdditionalOfferingQuotaField, nRequestID: i32) -> i32;
        /// 强制用户登出请求
        fn ReqForceUserExit(&self, pForceUserLogoutField: ForceUserLogoutField, nRequestID: i32) -> i32;
        /// 强制用户退出请求
        fn ReqForceUserLogout(&self, pForceUserLogoutField: ForceUserLogoutField, nRequestID: i32) -> i32;
        /// 激活用户请求
        fn ReqActivateUser(&self, pActivateUserField: ActivateUserField, nRequestID: i32) -> i32;
    }
    /// 登录请求
    #[derive(Debug, Clone, Default)]
    struct ReqUserLoginField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
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
        /// 关联节点编号(内部使用)
        NodeRef: i32,
        /// 网关内网IP地址
        GwInnerIPAddress: String,
        /// 网关外网IP地址
        GwOuterIPAddress: String,
        /// 网关Mac地址
        GwMacAddress: String,
    }
    /// 登录响应
    #[derive(Debug, Clone, Default)]
    struct RspUserLoginField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
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
        /// 关联节点编号(内部使用)
        NodeRef: i32,
        /// 交易流控
        TradeCommFlux: i32,
        /// 查询流控
        QueryCommFlux: i32,
        /// 委托流控
        OrderCommFlux: i32,
        /// 行情流控
        MarketCommFlux: i32,
        /// 行情订阅限制
        MarketSubLimit: i32,
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
        /// 用户请求编号
        UserRequestID: i32,
        /// 用户代码
        UserID: String,
    }
    /// 修改用户密码
    #[derive(Debug, Clone, Default)]
    struct UserPasswordUpdateField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户代码
        UserID: String,
        /// 旧密码
        OldPassword: String,
        /// 新密码
        NewPassword: String,
        /// 用户请求编号
        UserRequestID: i32,
    }
    /// 请求录入设备序列
    #[derive(Debug, Clone, Default)]
    struct ReqInputDeviceSerialField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 用户代码
        UserID: String,
        /// 设备标识
        DeviceID: String,
        /// 设备序列号
        CertSerial: String,
        /// 设备类别
        DeviceType: u8,
    }
    /// 录入设备序列响应
    #[derive(Debug, Clone, Default)]
    struct RspInputDeviceSerialField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 用户代码
        UserID: String,
    }
    /// 输入报单
    #[derive(Debug, Clone, Default)]
    struct InputOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 买卖方向
        Direction: u8,
        /// 价格
        LimitPrice: f64,
        /// 数量
        VolumeTotalOriginal: i32,
        /// 报单价格条件
        OrderPriceType: u8,
        /// 有效期类型
        TimeCondition: u8,
        /// 成交量类型
        VolumeCondition: u8,
        /// 委托方式
        Operway: u8,
        /// 报单引用
        OrderRef: i32,
        /// 港股通订单数量类型
        LotType: u8,
        /// 系统报单编号
        OrderSysID: String,
        /// 条件检查
        CondCheck: u8,
        /// 有效日期
        GTDate: String,
        /// 强平原因(两融专用)
        ForceCloseReason: u8,
        /// 指定偿还的信用负债编号（该字段置空表示不指定偿还）(两融专用)
        CreditDebtID: String,
        /// 头寸类型(两融专用)
        CreditQuotaType: u8,
        /// 费息折扣券编号（0表示不使用折扣券）(两融专用)
        DiscountCouponID: i32,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 报单
    #[derive(Debug, Clone, Default)]
    struct OrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 买卖方向
        Direction: u8,
        /// 报单价格条件
        OrderPriceType: u8,
        /// 有效期类型
        TimeCondition: u8,
        /// 成交量类型
        VolumeCondition: u8,
        /// 价格
        LimitPrice: f64,
        /// 数量
        VolumeTotalOriginal: i32,
        /// 港股通订单数量类型
        LotType: u8,
        /// 有效日期
        GTDate: String,
        /// 委托方式
        Operway: u8,
        /// 条件检查
        CondCheck: u8,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 请求编号
        RequestID: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 报单引用
        OrderRef: i32,
        /// 本地报单编号
        OrderLocalID: String,
        /// 系统报单编号
        OrderSysID: String,
        /// 报单状态
        OrderStatus: u8,
        /// 报单提交状态
        OrderSubmitStatus: u8,
        /// 状态信息
        StatusMsg: String,
        /// 已成交数量
        VolumeTraded: i32,
        /// 已撤销数量
        VolumeCanceled: i32,
        /// 交易日
        TradingDay: String,
        /// 申报用户
        InsertUser: Vec<u8>,
        /// 申报日期
        InsertDate: String,
        /// 申报时间
        InsertTime: String,
        /// 交易所接收时间
        AcceptTime: String,
        /// 撤销用户
        CancelUser: Vec<u8>,
        /// 撤销时间
        CancelTime: String,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 交易单元代码
        PbuID: String,
        /// 成交金额
        Turnover: f64,
        /// 报单类型
        OrderType: u8,
        /// 用户端产品信息
        UserProductInfo: String,
        /// 强平原因(两融专用)
        ForceCloseReason: u8,
        /// 信用头寸编号(两融专用)
        CreditQuotaID: String,
        /// 头寸类型(两融专用)
        CreditQuotaType: u8,
        /// 信用负债编号(两融专用)
        CreditDebtID: String,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
        /// 回报附加浮点型数据信息
        RtnFloatInfo: f64,
        /// 回报附加整型数据
        RtnIntInfo: i32,
        /// 回报附加浮点型数据1
        RtnFloatInfo1: f64,
        /// 回报附加浮点型数据2
        RtnFloatInfo2: f64,
        /// 回报附加浮点型数据3
        RtnFloatInfo3: f64,
        /// 交易所接受时间戳
        AcceptTimeStamp: i64,
    }
    /// 用户标识
    #[derive(Debug, Clone, Default)]
    struct UserRefField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户代码
        UserID: String,
    }
    /// 成交
    #[derive(Debug, Clone, Default)]
    struct TradeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 成交编号
        TradeID: String,
        /// 买卖方向
        Direction: u8,
        /// 系统报单编号
        OrderSysID: String,
        /// 本地报单编号
        OrderLocalID: String,
        /// 成交价格
        Price: f64,
        /// 成交数量
        Volume: i32,
        /// 成交日期
        TradeDate: String,
        /// 成交时间
        TradeTime: String,
        /// 交易日
        TradingDay: String,
        /// 交易单元代码
        PbuID: String,
        /// 报单引用
        OrderRef: i32,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
    }
    /// 输入撤单操作
    #[derive(Debug, Clone, Default)]
    struct InputOrderActionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 被撤报单前置编号
        FrontID: i32,
        /// 被撤报单会话编号
        SessionID: i32,
        /// 被撤报单引用
        OrderRef: i32,
        /// 被撤报单系统编号
        OrderSysID: String,
        /// 操作标志
        ActionFlag: u8,
        /// 报单操作引用
        OrderActionRef: i32,
        /// 系统撤单编号
        CancelOrderSysID: String,
        /// 委托方式
        Operway: u8,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 条件单录入域
    #[derive(Debug, Clone, Default)]
    struct InputCondOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 买卖方向
        Direction: u8,
        /// 价格类型
        OrderPriceType: u8,
        /// 有效期类型
        TimeCondition: u8,
        /// 成交量类型
        VolumeCondition: u8,
        /// 报单价格
        LimitPrice: f64,
        /// 报单数量
        VolumeTotalOriginal: i32,
        /// 委托方式
        Operway: u8,
        /// 港股通订单数量类型
        LotType: u8,
        /// 条件检查
        CondCheck: u8,
        /// 有效日期
        GTDate: String,
        /// 强平原因(两融专用)
        ForceCloseReason: u8,
        /// 指定偿还的信用负债编号（该字段置空表示不指定偿还）(两融专用)
        CreditDebtID: String,
        /// 头寸类型(两融专用)
        CreditQuotaType: u8,
        /// 费息折扣券编号（0表示不使用折扣券）(两融专用)
        DiscountCouponID: i32,
        /// 条件报单引用
        CondOrderRef: i32,
        /// 条件报单编号
        CondOrderID: i32,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 触发基准数量类型
        TriggerOrderVolumeType: u8,
        /// 触发基准价类型
        TriggerOrderPriceType: u8,
        /// 条件单触发条件
        ContingentCondition: u8,
        /// 条件价
        ConditionPrice: f64,
        /// 价格浮动tick数
        PriceTicks: i32,
        /// 数量浮动倍数
        VolumeMultiple: i32,
        /// 相关前置编号
        RelativeFrontID: i32,
        /// 相关会话编号
        RelativeSessionID: i32,
        /// 相关条件参数
        RelativeParam: Vec<u8>,
        /// 附加条件单触发条件
        AppendContingentCondition: u8,
        /// 附加条件价
        AppendConditionPrice: f64,
        /// 附加相关前置编号
        AppendRelativeFrontID: i32,
        /// 附加相关会话编号
        AppendRelativeSessionID: i32,
        /// 附加相关条件参数
        AppendRelativeParam: Vec<u8>,
    }
    /// 条件单域
    #[derive(Debug, Clone, Default)]
    struct ConditionOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 买卖方向
        Direction: u8,
        /// 价格类型
        OrderPriceType: u8,
        /// 有效期类型
        TimeCondition: u8,
        /// 成交量类型
        VolumeCondition: u8,
        /// 报单价格
        LimitPrice: f64,
        /// 报单数量
        VolumeTotalOriginal: i32,
        /// 委托方式
        Operway: u8,
        /// 港股通订单数量类型
        LotType: u8,
        /// 条件检查
        CondCheck: u8,
        /// 有效日期
        GTDate: String,
        /// 强平原因(两融专用)
        ForceCloseReason: u8,
        /// 指定偿还的信用负债编号（该字段置空表示不指定偿还）(两融专用)
        CreditDebtID: String,
        /// 头寸类型(两融专用)
        CreditQuotaType: u8,
        /// 费息折扣券编号（0表示不使用折扣券）(两融专用)
        DiscountCouponID: i32,
        /// 条件报单引用
        CondOrderRef: i32,
        /// 报单编号
        CondOrderID: i32,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 触发基准数量类型
        TriggerOrderVolumeType: u8,
        /// 触发基准价类型
        TriggerOrderPriceType: u8,
        /// 条件单触发条件
        ContingentCondition: u8,
        /// 条件价
        ConditionPrice: f64,
        /// 价格浮动tick数
        PriceTicks: i32,
        /// 数量浮动倍数
        VolumeMultiple: i32,
        /// 相关前置编号
        RelativeFrontID: i32,
        /// 相关会话编号
        RelativeSessionID: i32,
        /// 相关条件参数
        RelativeParam: Vec<u8>,
        /// 附加条件单触发条件
        AppendContingentCondition: u8,
        /// 附加条件价
        AppendConditionPrice: f64,
        /// 附加相关前置编号
        AppendRelativeFrontID: i32,
        /// 附加相关会话编号
        AppendRelativeSessionID: i32,
        /// 附加相关条件参数
        AppendRelativeParam: Vec<u8>,
        /// 请求编号
        RequestID: i32,
        /// 交易日
        TradingDay: String,
        /// 条件单状态
        CondOrderStatus: u8,
        /// 状态信息
        StatusMsg: String,
        /// 申报用户
        InsertUser: Vec<u8>,
        /// 申报日期
        InsertDate: String,
        /// 申报时间
        InsertTime: String,
        /// 触发日期
        ActiveDate: String,
        /// 触发时间
        ActiveTime: String,
        /// 撤销用户
        CancelUser: Vec<u8>,
        /// 撤销时间
        CancelTime: String,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 用户端产品信息
        UserProductInfo: String,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
    }
    /// 条件单操作录入
    #[derive(Debug, Clone, Default)]
    struct InputCondOrderActionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 被撤条件单前置编号
        FrontID: i32,
        /// 被撤条件单会话编号
        SessionID: i32,
        /// 被撤条件单引用
        CondOrderRef: i32,
        /// 被撤条件单编号
        CondOrderID: i32,
        /// 操作标志
        ActionFlag: u8,
        /// 委托方式
        Operway: u8,
        /// 条件单操作引用
        CondOrderActionRef: i32,
        /// 条件单撤单编号
        CancelCondOrderID: i32,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 输入报单
    #[derive(Debug, Clone, Default)]
    struct InputNegoOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 买卖方向
        Direction: u8,
        /// 价格
        LimitPrice: f64,
        /// 数量
        VolumeTotalOriginal: i32,
        /// 联系人(意向申报时必填)
        Contractor: Vec<u8>,
        /// 联系方式(意向申报时必填)
        ContractorInfo: String,
        /// 约定号(成交申报时必填)
        ConfirmID: String,
        /// 对手方席位号(成交申报时必填)
        CounterpartyPbuID: String,
        /// 系统报单编号
        OrderSysID: String,
        /// 委托方式
        Operway: u8,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 协议交易报单
    #[derive(Debug, Clone, Default)]
    struct NegoOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 买卖方向
        Direction: u8,
        /// 价格
        LimitPrice: f64,
        /// 数量
        VolumeTotalOriginal: i32,
        /// 联系人
        Contractor: Vec<u8>,
        /// 联系方式
        ContractorInfo: String,
        /// 约定号
        ConfirmID: String,
        /// 对手方席位号
        CounterpartyPbuID: String,
        /// 委托方式
        Operway: u8,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 请求编号
        RequestID: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 本地报单编号
        OrderLocalID: String,
        /// 系统报单编号
        OrderSysID: String,
        /// 报单状态
        OrderStatus: u8,
        /// 报单提交状态
        OrderSubmitStatus: u8,
        /// 状态信息
        StatusMsg: String,
        /// 已成交数量
        VolumeTraded: i32,
        /// 已撤销数量
        VolumeCanceled: i32,
        /// 交易日
        TradingDay: String,
        /// 申报用户
        InsertUser: Vec<u8>,
        /// 申报日期
        InsertDate: String,
        /// 申报时间
        InsertTime: String,
        /// 交易所接收时间
        AcceptTime: String,
        /// 撤销用户
        CancelUser: Vec<u8>,
        /// 撤销时间
        CancelTime: String,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 交易单元代码
        PbuID: String,
        /// 用户端产品信息
        UserProductInfo: String,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
    }
    /// 协议交易成交
    #[derive(Debug, Clone, Default)]
    struct NegoTradeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 成交编号
        TradeID: String,
        /// 买卖方向
        Direction: u8,
        /// 系统报单编号
        OrderSysID: String,
        /// 本地报单编号
        OrderLocalID: String,
        /// 成交价格
        Price: f64,
        /// 成交数量
        Volume: i32,
        /// 成交日期
        TradeDate: String,
        /// 成交时间
        TradeTime: String,
        /// 交易日
        TradingDay: String,
        /// 交易单元代码
        PbuID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 对手方交易单元代码
        CounterpartyPbuID: String,
        /// 对手方股东账号
        CounterpartyShareholderID: String,
    }
    /// 输入协议交易撤单操作
    #[derive(Debug, Clone, Default)]
    struct InputNegoOrderActionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 被撤报单系统编号
        OrderSysID: String,
        /// 操作标志
        ActionFlag: u8,
        /// 系统撤单编号
        CancelOrderSysID: String,
        /// 委托方式
        Operway: u8,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 输入报单
    #[derive(Debug, Clone, Default)]
    struct InputOrderExField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 买卖方向
        Direction: u8,
        /// 价格
        LimitPrice: f64,
        /// 数量
        VolumeTotalOriginal: i32,
        /// 报单价格条件
        OrderPriceType: u8,
        /// 有效期类型
        TimeCondition: u8,
        /// 成交量类型
        VolumeCondition: u8,
        /// 委托方式
        Operway: u8,
        /// 报单引用
        OrderRef: i32,
        /// 港股通订单数量类型
        LotType: u8,
        /// 系统报单编号
        OrderSysID: String,
        /// 条件检查
        CondCheck: u8,
        /// 有效日期
        GTDate: String,
        /// 强平原因(两融专用)
        ForceCloseReason: u8,
        /// 指定偿还的信用负债编号（该字段置空表示不指定偿还）(两融专用)
        CreditDebtID: String,
        /// 头寸类型(两融专用)
        CreditQuotaType: u8,
        /// 费息折扣券编号（0表示不使用折扣券）(两融专用)
        DiscountCouponID: i32,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 关联节点编号
        NodeRef: i32,
    }
    /// 输入撤单操作
    #[derive(Debug, Clone, Default)]
    struct InputOrderActionExField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 被撤报单前置编号
        FrontID: i32,
        /// 被撤报单会话编号
        SessionID: i32,
        /// 被撤报单引用
        OrderRef: i32,
        /// 被撤报单系统编号
        OrderSysID: String,
        /// 操作标志
        ActionFlag: u8,
        /// 报单操作引用
        OrderActionRef: i32,
        /// 系统撤单编号
        CancelOrderSysID: String,
        /// 委托方式
        Operway: u8,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 证券代码
        SecurityID: String,
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
    /// 资金转移
    #[derive(Debug, Clone, Default)]
    struct InputTransferFundField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 申请流水号
        ApplySerial: i32,
        /// 转移方向
        TransferDirection: u8,
        /// 转移金额
        Amount: f64,
        /// 银行代码(银证转账时必填)
        BankID: u8,
        /// 资金密码(证券转银行时必填)
        AccountPassword: String,
        /// 银行密码(银行转证券时必填)
        BankPassword: String,
        /// 外部节点号(节点间资金调拨时必填)
        ExternalNodeID: i32,
        /// 指定偿还的信用负债编号(两融专用)
        CreditDebtID: String,
        /// 强平原因(两融专用)
        ForceCloseReason: u8,
        /// 实际偿还金额(返回)(两融专用)
        RealAmount: f64,
        /// 强制标识(证券转银行时有效)
        ForceFlag: i32,
    }
    /// 资金转移回报
    #[derive(Debug, Clone, Default)]
    struct TransferFundField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 转移流水号
        FundSerial: i32,
        /// 申请流水号
        ApplySerial: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 转移方向
        TransferDirection: u8,
        /// 转移金额
        Amount: f64,
        /// 转移状态
        TransferStatus: u8,
        /// 操作人员
        OperatorID: String,
        /// 操作日期
        OperateDate: String,
        /// 操作时间
        OperateTime: String,
        /// 签约银行账户
        BankAccountID: String,
        /// 银行代码
        BankID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 外部节点号
        ExternalNodeID: i32,
        /// 强平原因(两融专用)
        ForceCloseReason: u8,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
        /// 投资单元代码
        BusinessUnitID: String,
    }
    /// 仓位转移
    #[derive(Debug, Clone, Default)]
    struct InputTransferPositionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 申请流水号
        ApplySerial: i32,
        /// 转移方向
        TransferDirection: u8,
        /// 数量
        Volume: i32,
        /// 转移持仓类型
        TransferPositionType: u8,
        /// 用户请求编号
        UserRequestID: i32,
        /// 市场代码
        MarketID: u8,
        /// 外部节点编号(外部系统转仓时必填)
        ExternalNodeID: i32,
    }
    /// 仓位转移回报
    #[derive(Debug, Clone, Default)]
    struct TransferPositionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 仓位转移流水号
        PositionSerial: i32,
        /// 申请流水号
        ApplySerial: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 股东账户代码
        ShareholderID: String,
        /// 市场代码
        MarketID: u8,
        /// 证券代码
        SecurityID: String,
        /// 交易日
        TradingDay: String,
        /// 转移方向
        TransferDirection: u8,
        /// 转移持仓类型
        TransferPositionType: u8,
        /// 昨日持仓数量
        HistoryVolume: i32,
        /// 今日买卖持仓数量
        TodayBSVolume: i32,
        /// 今日申赎持仓数量
        TodayPRVolume: i32,
        /// 今日拆分合并持仓数量
        TodaySMVolume: i32,
        /// 转移状态
        TransferStatus: u8,
        /// 操作人员
        OperatorID: String,
        /// 操作日期
        OperateDate: String,
        /// 操作时间
        OperateTime: String,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
        /// 外部节点编号
        ExternalNodeID: i32,
    }
    /// 外围系统仓位转移回报
    #[derive(Debug, Clone, Default)]
    struct PeripheryTransferPositionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 仓位调拨流水号
        PositionSerial: i32,
        /// 仓位调拨请求流水号
        ApplySerial: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 仓位调拨方向
        TransferDirection: u8,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 今日买卖仓位转入转出数量
        TodayBSPos: i32,
        /// 今日申赎仓位转入数量
        TodayPRPos: i32,
        /// 昨日仓位转入数量
        HistoryPos: i32,
        /// 交易日
        TradingDay: String,
        /// 仓位调拨原因
        TransferReason: String,
        /// 转移状态
        TransferStatus: u8,
        /// 操作日期
        OperateDate: String,
        /// 操作时间
        OperateTime: String,
        /// 冲正日期
        RepealDate: String,
        /// 冲正时间
        RepealTime: String,
        /// 冲正原因
        RepealReason: String,
        /// 状态信息
        StatusMsg: String,
        /// 今日拆分合并仓位转入数量
        TodaySMPos: i32,
    }
    /// 外围系统资金转移回报
    #[derive(Debug, Clone, Default)]
    struct PeripheryTransferFundField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 资金调拨流水号
        FundSerial: i32,
        /// 资金调拨请求流水号
        ApplySerial: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 资金调拨方向
        TransferDirection: u8,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 转移金额
        Amount: f64,
        /// 投资者代码
        InvestorID: String,
        /// 资金调拨原因
        TransferReason: String,
        /// 转移状态
        TransferStatus: u8,
        /// 操作日期
        OperateDate: String,
        /// 操作时间
        OperateTime: String,
        /// 冲正日期
        RepealDate: String,
        /// 冲正时间
        RepealTime: String,
        /// 冲正原因
        RepealReason: String,
        /// 状态信息
        StatusMsg: String,
        /// 投资单元代码
        BusinessUnitID: String,
    }
    /// 查询集中交易系统资金请求
    #[derive(Debug, Clone, Default)]
    struct ReqInquiryJZFundField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 用户请求编号
        UserRequestID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
    }
    /// 查询集中交易系统资金响应
    #[derive(Debug, Clone, Default)]
    struct RspInquiryJZFundField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 可用金额
        UsefulMoney: f64,
        /// 可取额度
        FetchLimit: f64,
        /// 用户请求编号
        UserRequestID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
    }
    /// 查询银行账户余额请求
    #[derive(Debug, Clone, Default)]
    struct ReqInquiryBankAccountFundField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 银行代码
        BankID: u8,
        /// 银行密码
        BankPassword: String,
    }
    /// 查询银行账户余额响应
    #[derive(Debug, Clone, Default)]
    struct RspInquiryBankAccountFundField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 银行代码
        BankID: u8,
        /// 签约银行账户
        BankAccountID: String,
        /// 账户余额
        Balance: f64,
    }
    /// 交易通知
    #[derive(Debug, Clone, Default)]
    struct TradingNoticeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 通知流水号
        NoticeSerial: i32,
        /// 通知日期
        InsertDate: String,
        /// 通知时间
        InsertTime: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 通知消息内容
        Content: String,
        /// 操作员
        OperatorID: String,
    }
    /// 查询最大报单量请求
    #[derive(Debug, Clone, Default)]
    struct ReqInquiryMaxOrderVolumeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 买卖方向
        Direction: u8,
        /// 报单价格条件
        OrderPriceType: u8,
        /// 有效期类型
        TimeCondition: u8,
        /// 成交量类型
        VolumeCondition: u8,
        /// 价格
        LimitPrice: f64,
        /// 港股通订单数量类型
        LotType: u8,
        /// 最大委托手数
        MaxVolume: i32,
        /// 指定偿还的信用负债编号（该字段置空表示不指定偿还）（两融专用）
        CreditDebtID: String,
        /// 头寸类型（两融专用）
        CreditQuotaType: u8,
    }
    /// 查询最大报单量响应
    #[derive(Debug, Clone, Default)]
    struct RspInquiryMaxOrderVolumeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 买卖方向
        Direction: u8,
        /// 报单价格条件
        OrderPriceType: u8,
        /// 有效期类型
        TimeCondition: u8,
        /// 成交量类型
        VolumeCondition: u8,
        /// 价格
        LimitPrice: f64,
        /// 港股通订单数量类型
        LotType: u8,
        /// 最大委托手数
        MaxVolume: i32,
        /// 指定偿还的信用负债编号（该字段置空表示不指定偿还）（两融专用）
        CreditDebtID: String,
        /// 头寸类型（两融专用）
        CreditQuotaType: u8,
    }
    /// 交易成交集中度
    #[derive(Debug, Clone, Default)]
    struct InquiryTradeConcentrationField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 证券代码
        SecurityID: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 资金账户代码
        AccountID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 投资者成交量/成交总量
        ConcentrationRatio1: f64,
        /// 投资者成交金额/成交总金额
        ConcentrationRatio2: f64,
    }
    /// 请求修改开仓成本
    #[derive(Debug, Clone, Default)]
    struct ReqModifyOpenPosCostField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 开仓成本
        OpenPosCost: f64,
    }
    /// 录入节点资金分配信息
    #[derive(Debug, Clone, Default)]
    struct InputNodeFundAssignmentField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账号
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 节点编号1
        NodeID1: i32,
        /// 资金比例1
        AmtRatio1: f64,
        /// 节点编号2
        NodeID2: i32,
        /// 资金比例2
        AmtRatio2: f64,
        /// 节点编号3
        NodeID3: i32,
        /// 资金比例3
        AmtRatio3: f64,
        /// 节点编号4
        NodeID4: i32,
        /// 资金比例4
        AmtRatio4: f64,
        /// 节点编号5
        NodeID5: i32,
        /// 资金比例5
        AmtRatio5: f64,
    }
    /// 查询节点资金分配比例请求
    #[derive(Debug, Clone, Default)]
    struct ReqInquiryNodeFundAssignmentField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账号
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 节点编号
        NodeID: i32,
        /// 用户请求编号
        UserRequestID: i32,
    }
    /// 查询节点资金分配比例响应
    #[derive(Debug, Clone, Default)]
    struct RspInquiryNodeFundAssignmentField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户请求编号
        UserRequestID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账号
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 节点编号1
        NodeID1: i32,
        /// 资金比例1
        AmtRatio1: f64,
        /// 节点编号2
        NodeID2: i32,
        /// 资金比例2
        AmtRatio2: f64,
        /// 节点编号3
        NodeID3: i32,
        /// 资金比例3
        AmtRatio3: f64,
        /// 节点编号4
        NodeID4: i32,
        /// 资金比例4
        AmtRatio4: f64,
        /// 节点编号5
        NodeID5: i32,
        /// 资金比例5
        AmtRatio5: f64,
    }
    /// 查询交易所
    #[derive(Debug, Clone, Default)]
    struct QryExchangeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
    }
    /// 交易所
    #[derive(Debug, Clone, Default)]
    struct ExchangeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 交易所名称
        ExchangeName: String,
        /// 交易日
        TradingDay: String,
        /// 数据同步状态
        DataSyncStatus: u8,
    }
    /// 查询证券信息
    #[derive(Debug, Clone, Default)]
    struct QrySecurityField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 产品代码
        ProductID: u8,
    }
    /// 证券信息
    #[derive(Debug, Clone, Default)]
    struct SecurityField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易日
        TradingDay: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 证券名称
        SecurityName: String,
        /// 证券名称(短)
        ShortSecurityName: String,
        /// 基础证券代码
        UnderlyingSecurityID: String,
        /// 市场代码
        MarketID: u8,
        /// 产品代码
        ProductID: u8,
        /// 证券类别
        SecurityType: u8,
        /// 申报单位
        OrderUnit: u8,
        /// 限价买入交易单位
        LimitBuyTradingUnit: i32,
        /// 限价单买最大下单量
        MaxLimitOrderBuyVolume: i32,
        /// 限价单买最小下单量
        MinLimitOrderBuyVolume: i32,
        /// 限价卖出交易单位
        LimitSellTradingUnit: i32,
        /// 限价单卖最大下单量
        MaxLimitOrderSellVolume: i32,
        /// 限价单卖最小下单量
        MinLimitOrderSellVolume: i32,
        /// 市价买入交易单位
        MarketBuyTradingUnit: i32,
        /// 市价单买最大下单量
        MaxMarketOrderBuyVolume: i32,
        /// 市价单买最小下单量
        MinMarketOrderBuyVolume: i32,
        /// 市价卖出交易单位
        MarketSellTradingUnit: i32,
        /// 市价单卖最大下单量
        MaxMarketOrderSellVolume: i32,
        /// 市价单卖最小下单量
        MinMarketOrderSellVolume: i32,
        /// 盘后定价买入交易单位
        FixPriceBuyTradingUnit: i32,
        /// 盘后定价买最大下单量
        MaxFixPriceOrderBuyVolume: i32,
        /// 盘后定价买最小下单量
        MinFixPriceOrderBuyVolume: i32,
        /// 盘后定价卖出交易单位
        FixPriceSellTradingUnit: i32,
        /// 盘后定价卖最大下单量
        MaxFixPriceOrderSellVolume: i32,
        /// 盘后定价卖最小下单量
        MinFixPriceOrderSellVolume: i32,
        /// 数量乘数
        VolumeMultiple: i32,
        /// 最小变动价位
        PriceTick: f64,
        /// 上市日
        OpenDate: String,
        /// 面值
        ParValue: f64,
        /// 证券状态
        SecurityStatus: i64,
        /// 债券应计利息
        BondInterest: f64,
        /// 折算率
        ConversionRate: f64,
        /// 总股本
        TotalEquity: f64,
        /// 流通股本
        CirculationEquity: f64,
        /// 是否限制涨跌停板价
        bPriceLimit: i32,
        /// 昨收盘价
        PreClosePrice: f64,
        /// 涨停板价
        UpperLimitPrice: f64,
        /// 跌停板价
        LowerLimitPrice: f64,
        /// 是否可当日回转交易
        DayTrading: i32,
    }
    /// 查询新股信息
    #[derive(Debug, Clone, Default)]
    struct QryIPOInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 申购代码
        SecurityID: String,
    }
    /// 新股信息
    #[derive(Debug, Clone, Default)]
    struct IPOInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 申购代码
        SecurityID: String,
        /// 市场代码
        MarketID: u8,
        /// 产品代码
        ProductID: u8,
        /// 证券类别代码
        SecurityType: u8,
        /// 最小申购价格
        MinPrice: f64,
        /// 币种代码
        CurrencyID: u8,
        /// 申购证券名称
        SecurityName: String,
        /// 新股证券代码
        UnderlyingSecurityID: String,
        /// 新股证券名称
        UnderlyingSecurityName: String,
        /// 网上申购最小数量
        MinVolume: i32,
        /// 网上申购最大数量
        MaxVolume: i32,
        /// 网上申购单位数量
        VolumeUnit: i32,
        /// 发行方式
        IssueMode: u8,
        /// 交易日
        TradingDay: String,
        /// 最大申购价格
        MaxPrice: f64,
        /// 备注
        Remark: i64,
    }
    /// 查询用户
    #[derive(Debug, Clone, Default)]
    struct QryUserField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户代码
        UserID: String,
        /// 用户类型
        UserType: u8,
    }
    /// 用户
    #[derive(Debug, Clone, Default)]
    struct UserField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户代码
        UserID: String,
        /// 用户名称
        UserName: String,
        /// 用户类型
        UserType: u8,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 登录限制数
        LoginLimit: i32,
        /// 登录状态
        LoginStatus: u8,
        /// 开户日期
        OpenDate: String,
        /// 销户日期
        CloseDate: String,
        /// 报单流控
        OrderInsertCommFlux: i32,
        /// 撤单流控
        OrderActionCommFlux: i32,
        /// 交易流控
        TradeCommFlux: i32,
        /// 查询流控
        QueryCommFlux: i32,
        /// 委托流控
        OrderCommFlux: i32,
    }
    /// 查询投资者
    #[derive(Debug, Clone, Default)]
    struct QryInvestorField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
    }
    /// 投资者
    #[derive(Debug, Clone, Default)]
    struct InvestorField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 投资者类型
        InvestorType: u8,
        /// 投资者名称
        InvestorName: String,
        /// 证件类型
        IdCardType: u8,
        /// 证件号码
        IdCardNo: String,
        /// 开户日期
        OpenDate: String,
        /// 销户日期
        CloseDate: String,
        /// 交易状态
        TradingStatus: u8,
        /// 委托方式
        Operways: Vec<u8>,
        /// 手机
        Mobile: String,
        /// 联系电话
        Telephone: String,
        /// 电子邮件
        Email: String,
        /// 传真
        Fax: Vec<u8>,
        /// 通讯地址
        Address: String,
        /// 邮政编码
        ZipCode: String,
        /// 专业投资者类别
        ProfInvestorType: u8,
        /// 套餐类型(两融专用)
        PlanType: u8,
        /// 是否允许投资者自切套餐(两融专用)
        AllowSelfSwitchPlan: i32,
        /// 备注
        Remark: String,
    }
    /// 查询交易股东账户
    #[derive(Debug, Clone, Default)]
    struct QryShareholderAccountField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 股东账户账户代码
        ShareholderID: String,
        /// 股东账户类型
        ShareholderIDType: u8,
    }
    /// 交易股东账户
    #[derive(Debug, Clone, Default)]
    struct ShareholderAccountField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 客户代码
        ShareholderID: String,
        /// 股东账户类型
        ShareholderIDType: u8,
        /// 市场代码
        MarketID: u8,
        /// 普通买卖白名单控制标志(两融专用)
        BSWhiteListCtl: i32,
        /// 主账户标识
        MainFlag: i32,
    }
    /// 查询配股配债信息
    #[derive(Debug, Clone, Default)]
    struct QryRationalInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 配股配债代码
        SecurityID: String,
    }
    /// 配股配债信息
    #[derive(Debug, Clone, Default)]
    struct RationalInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易日
        TradingDay: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 申购代码
        SecurityID: String,
        /// 配股配债价格
        Price: f64,
        /// 市场代码
        MarketID: u8,
        /// 证券品种代码
        ProductID: u8,
        /// 证券类别代码
        SecurityType: u8,
        /// 配股名称
        SecurityName: String,
        /// 基础证券代码
        UnderlyingSecurityID: String,
        /// 基础证券名称
        UnderlyingSecurityName: String,
        /// 配股配债最小数量
        MinVolume: i32,
        /// 配股配债最大数量
        MaxVolume: i32,
        /// 配股配债单位数量
        VolumeUnit: i32,
    }
    /// 查询报单
    #[derive(Debug, Clone, Default)]
    struct QryOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 证券代码
        SecurityID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 系统报单编号
        OrderSysID: String,
        /// Insert Time
        InsertTimeStart: Vec<u8>,
        /// Insert Time
        InsertTimeEnd: Vec<u8>,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 是否可撤
        IsCancel: i32,
    }
    /// 查询撤单
    #[derive(Debug, Clone, Default)]
    struct QryOrderActionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户账户代码
        ShareholderID: String,
        /// 本地报单编号
        OrderLocalID: String,
        /// 本地撤单编号
        CancelOrderLocalID: String,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 撤单
    #[derive(Debug, Clone, Default)]
    struct OrderActionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 被撤报单前置编号
        FrontID: i32,
        /// 被撤报单会话编号
        SessionID: i32,
        /// 被撤报单引用
        OrderRef: i32,
        /// 被撤报单系统编号
        OrderSysID: String,
        /// 操作标志
        ActionFlag: u8,
        /// 本地撤单编号
        CancelOrderLocalID: String,
        /// 委托方式
        Operway: u8,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 被撤报单本地编号
        OrderLocalID: String,
        /// 操作用户
        ActionUser: Vec<u8>,
        /// 交易日
        TradingDay: String,
        /// 操作日期
        ActionDate: String,
        /// 操作时间
        ActionTime: String,
        /// 撤单状态
        CancelOrderStatus: u8,
        /// 状态信息
        StatusMsg: String,
        /// 请求编号
        RequestID: i32,
        /// 撤单前置编号
        ActionFrontID: i32,
        /// 撤单会话编号
        ActionSessionID: i32,
        /// 撤单引用
        OrderActionRef: i32,
        /// 本地撤单系统编号
        CancelOrderSysID: String,
        /// 撤单类型
        CancelOrderType: u8,
        /// 交易单元代码
        PbuID: String,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
    }
    /// 查询成交
    #[derive(Debug, Clone, Default)]
    struct QryTradeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 证券代码
        SecurityID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 成交编号
        TradeID: String,
        /// Insert Time
        TradeTimeStart: Vec<u8>,
        /// Insert Time
        TradeTimeEnd: Vec<u8>,
    }
    /// 查询资金账户
    #[derive(Debug, Clone, Default)]
    struct QryTradingAccountField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 币种
        CurrencyID: u8,
        /// 资金账户代码
        AccountID: String,
        /// 资金账户类型
        AccountType: u8,
        /// 经纪公司部门代码
        DepartmentID: String,
    }
    /// 资金账户
    #[derive(Debug, Clone, Default)]
    struct TradingAccountField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种代码
        CurrencyID: u8,
        /// 上日结存
        PreDeposit: f64,
        /// 可用资金
        UsefulMoney: f64,
        /// 可取资金
        FetchLimit: f64,
        /// 上日未交收金额(港股通专用字段)
        PreUnDeliveredMoney: f64,
        /// 可用未交收金额(港股通专用字段)
        UnDeliveredMoney: f64,
        /// 当日入金金额
        Deposit: f64,
        /// 当日出金金额
        Withdraw: f64,
        /// 冻结的资金(港股通该字段不包括未交收部分冻结资金)
        FrozenCash: f64,
        /// 冻结未交收金额(港股通专用)
        UnDeliveredFrozenCash: f64,
        /// 冻结的手续费(港股通该字段不包括未交收部分冻结手续费)
        FrozenCommission: f64,
        /// 冻结未交收手续费(港股通专用)
        UnDeliveredFrozenCommission: f64,
        /// 手续费(港股通该字段不包括未交收部分手续费)
        Commission: f64,
        /// 占用未交收手续费(港股通专用)
        UnDeliveredCommission: f64,
        /// 资金账户类型
        AccountType: u8,
        /// 资金账户所属投资者代码
        InvestorID: String,
        /// 银行代码
        BankID: u8,
        /// 银行账户
        BankAccountID: String,
        /// 权利金收入(两融专用)
        RoyaltyIn: f64,
        /// 权利金支出(两融专用)
        RoyaltyOut: f64,
        /// 融券卖出金额(两融专用)
        CreditSellAmount: f64,
        /// 融券卖出使用金额(用于偿还融资负债或买特殊品种的金额)(两融专用)
        CreditSellUseAmount: f64,
        /// 虚拟资产(两融专用)
        VirtualAssets: f64,
        /// 融券卖出金额冻结(用于偿还融资负债或买特殊品种的未成交冻结金额)(两融专用)
        CreditSellFrozenAmount: f64,
        /// 属主单元
        OwnerUnit: Vec<u8>,
    }
    /// 查询投资者持仓
    #[derive(Debug, Clone, Default)]
    struct QryPositionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 证券代码
        SecurityID: String,
        /// 股东账户代码
        ShareholderID: String,
    }
    /// 投资者持仓
    #[derive(Debug, Clone, Default)]
    struct PositionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 市场代码
        MarketID: u8,
        /// 股东账户代码
        ShareholderID: String,
        /// 交易日
        TradingDay: String,
        /// 证券代码
        SecurityID: String,
        /// 证券名称
        SecurityName: String,
        /// 昨仓
        HistoryPos: i32,
        /// 昨仓冻结
        HistoryPosFrozen: i32,
        /// 今买卖仓
        TodayBSPos: i32,
        /// 今买卖仓冻结
        TodayBSPosFrozen: i32,
        /// 今日申赎持仓
        TodayPRPos: i32,
        /// 今日申赎持仓冻结
        TodayPRPosFrozen: i32,
        /// 今拆分合并持仓
        TodaySMPos: i32,
        /// 今拆分合并持仓冻结
        TodaySMPosFrozen: i32,
        /// 昨仓成本价
        HistoryPosPrice: f64,
        /// 持仓成本
        TotalPosCost: f64,
        /// 上次余额(盘中不变)
        PrePosition: i32,
        /// 股份可用
        AvailablePosition: i32,
        /// 股份余额
        CurrentPosition: i32,
        /// 开仓成本
        OpenPosCost: f64,
        /// 融资仓位(两融专用)
        CreditBuyPos: i32,
        /// 融券仓位(两融专用)
        CreditSellPos: i32,
        /// 今日融券仓位(两融专用)
        TodayCreditSellPos: i32,
        /// 划出仓位(两融专用)
        CollateralOutPos: i32,
        /// 还券未成交数量(两融专用)
        RepayUntradeVolume: i32,
        /// 直接还券未成交数量(两融专用)
        RepayTransferUntradeVolume: i32,
        /// 担保品买入未成交金额(两融专用)
        CollateralBuyUntradeAmount: f64,
        /// 担保品买入未成交数量(两融专用)
        CollateralBuyUntradeVolume: i32,
        /// 融资买入金额(包含交易费用)(两融专用)
        CreditBuyAmount: f64,
        /// 融资买入未成交金额(包含交易费用)(两融专用)
        CreditBuyUntradeAmount: f64,
        /// 融资冻结保证金(两融专用)
        CreditBuyFrozenMargin: f64,
        /// 融资买入利息(两融专用)
        CreditBuyInterestFee: f64,
        /// 融资买入未成交数量(两融专用)
        CreditBuyUntradeVolume: i32,
        /// 融券卖出金额(以成交价计算)(两融专用)
        CreditSellAmount: f64,
        /// 融券卖出未成交金额(两融专用)
        CreditSellUntradeAmount: f64,
        /// 融券冻结保证金(两融专用)
        CreditSellFrozenMargin: f64,
        /// 融券卖出息费(两融专用)
        CreditSellInterestFee: f64,
        /// 融券卖出未成交数量(两融专用)
        CreditSellUntradeVolume: i32,
        /// 划入待收仓(两融专用)
        CollateralInPos: i32,
        /// 融资流动冻结保证金(两融专用)
        CreditBuyFrozenCirculateMargin: f64,
        /// 融券流动冻结保证金(两融专用)
        CreditSellFrozenCirculateMargin: f64,
        /// 累计平仓盈亏(两融专用)
        CloseProfit: f64,
        /// 当日累计开仓数量
        TodayTotalOpenVolume: i32,
        /// 今手续费
        TodayCommission: f64,
        /// 当日累计买入金额
        TodayTotalBuyAmount: f64,
        /// 当日累计卖出金额
        TodayTotalSellAmount: f64,
        /// 上日冻结(盘中不变)
        PreFrozen: i32,
        /// 当日累计平仓数量
        TodayTotalCloseVolume: i32,
    }
    /// 查询基础交易费率
    #[derive(Debug, Clone, Default)]
    struct QryTradingFeeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
    }
    /// 基础交易费率
    #[derive(Debug, Clone, Default)]
    struct TradingFeeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 产品代码
        ProductID: u8,
        /// 证券类别代码
        SecurityType: u8,
        /// 证券代码
        SecurityID: String,
        /// 业务类别
        BizClass: u8,
        /// 印花税(港股印花税)按金额收取比例
        StampTaxRatioByAmt: f64,
        /// 印花税(港股印花税)按面值收取比例
        StampTaxRatioByPar: f64,
        /// 印花税(港股印花税,单位港币)按笔收取金额
        StampTaxFeePerOrder: f64,
        /// 印花税(港股印花税,单位港币)按数量收取金额
        StampTaxFeeByVolume: f64,
        /// 印花税(港股印花税,单位港币)最低收取金额
        StampTaxFeeMin: f64,
        /// 印花税(港股印花税,单位港币)最高收取金额
        StampTaxFeeMax: f64,
        /// 过户费(港股证券组合费)按金额收取比例
        TransferRatioByAmt: f64,
        /// 过户费(港股证券组合费)按面值收取比例
        TransferRatioByPar: f64,
        /// 过户费(港股证券组合费,单位港币)按笔收取金额
        TransferFeePerOrder: f64,
        /// 过户费(港股证券组合费,单位港币)按数量收取金额
        TransferFeeByVolume: f64,
        /// 过户费(港股证券组合费,单位港币)最低收取金额
        TransferFeeMin: f64,
        /// 过户费(港股证券组合费,单位港币)最高收取金额
        TransferFeeMax: f64,
        /// 经手费(港股交易费)按金额收取比例
        HandlingRatioByAmt: f64,
        /// 经手费(港股交易费)按面值收取比例
        HandlingRatioByPar: f64,
        /// 经手费(港股交易费,单位港币)按笔收取金额
        HandlingFeePerOrder: f64,
        /// 经手费(港股交易费,单位港币)按数量收取金额
        HandlingFeeByVolume: f64,
        /// 经手费(港股交易费,单位港币)最低收取金额
        HandlingFeeMin: f64,
        /// 经手费(港股交易费,单位港币)最高收取金额
        HandlingFeeMax: f64,
        /// 证管费(港股交易征费)按金额收取比例
        RegulateRatioByAmt: f64,
        /// 证管费(港股交易征费)按面值收取比例
        RegulateRatioByPar: f64,
        /// 证管费(港股交易征费,单位港币)按笔收取金额
        RegulateFeePerOrder: f64,
        /// 证管费(港股交易征费,单位港币)按数量收取金额
        RegulateFeeByVolume: f64,
        /// 证管费(港股交易征费,单位港币)最低收取金额
        RegulateFeeMin: f64,
        /// 证管费(港股交易征费,单位港币)最高收取金额
        RegulateFeeMax: f64,
        /// 结算费(港股股份交收费)按金额收取比例
        SettlementRatioByAmt: f64,
        /// 结算费(港股股份交收费)按面值收取比例
        SettlementRatioByPar: f64,
        /// 结算费(港股股份交收费,单位港币)按笔收取金额
        SettlementFeePerOrder: f64,
        /// 结算费(港股股份交收费,单位港币)按数量收取金额
        SettlementFeeByVolume: f64,
        /// 结算费(港股股份交收费,单位港币)最低收取金额
        SettlementFeeMin: f64,
        /// 结算费(港股股份交收费,单位港币)最高收取金额
        SettlementFeeMax: f64,
    }
    /// 查询佣金费率
    #[derive(Debug, Clone, Default)]
    struct QryInvestorTradingFeeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 经纪公司部门代码
        DepartmentID: String,
    }
    /// 佣金费率
    #[derive(Debug, Clone, Default)]
    struct InvestorTradingFeeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 产品代码
        ProductID: u8,
        /// 证券类别代码
        SecurityType: u8,
        /// 合约代码
        SecurityID: String,
        /// 业务类别
        BizClass: u8,
        /// 佣金类型
        BrokerageType: u8,
        /// 佣金按金额收取比例
        RatioByAmt: f64,
        /// 佣金按面值收取比例
        RatioByPar: f64,
        /// 佣金按笔收取金额
        FeePerOrder: f64,
        /// 佣金最低收取金额
        FeeMin: f64,
        /// 佣金最高收取金额
        FeeMax: f64,
        /// 佣金按数量收取金额
        FeeByVolume: f64,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 报单类型
        OrderType: u8,
    }
    /// 查询新股申购额度
    #[derive(Debug, Clone, Default)]
    struct QryIPOQuotaField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 股东账户代码
        ShareholderID: String,
    }
    /// 新股申购额度
    #[derive(Debug, Clone, Default)]
    struct IPOQuotaField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 客户代码
        ShareholderID: String,
        /// 可申购额度
        MaxVolume: i64,
        /// 科创板可申购额度
        KCMaxVolume: i64,
    }
    /// 查询报单明细资金
    #[derive(Debug, Clone, Default)]
    struct QryOrderFundDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 证券代码
        SecurityID: String,
        /// 系统报单编号
        OrderSysID: String,
    }
    /// 报单明细资金
    #[derive(Debug, Clone, Default)]
    struct OrderFundDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 交易日
        TradingDay: String,
        /// 系统报单编号
        OrderSysID: String,
        /// 交易单元代码
        PbuID: String,
        /// 本地报单编号
        OrderLocalID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 资金账户代码
        AccountID: String,
        /// 报单金额
        OrderAmount: f64,
        /// 成交金额
        Turnover: f64,
        /// 印花税(港股为印花税)
        StampTaxFee: f64,
        /// 经手费(港股为交易费)
        HandlingFee: f64,
        /// 过户费(港股为证券组合费)
        TransferFee: f64,
        /// 证管费(港股为交易征费)
        RegulateFee: f64,
        /// 结算费(港股为股份交收费)
        SettlementFee: f64,
        /// 佣金
        BrokerageFee: f64,
        /// 总费用
        TotalFee: f64,
        /// 报单初始冻结金额
        OrderCashFrozen: f64,
        /// 预估冻结现金
        EstimateCashFrozen: f64,
        /// 初始冻结总费用
        TotalFeeFrozen: f64,
        /// 初始冻结金额合计
        TotalFrozen: f64,
        /// 保证金(两融专用)
        Margin: f64,
        /// 偿还金额(两融专用)
        RepayAmount: f64,
        /// 偿还数量(两融专用)
        RepayVolume: i32,
        /// 初始冻结保证金(两融专用)
        MarginFrozen: f64,
        /// 初始冻结流动保证金(两融专用)
        CirculateMarginFrozen: f64,
    }
    /// 查询资金转移流水
    #[derive(Debug, Clone, Default)]
    struct QryFundTransferDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 转移方向
        TransferDirection: u8,
    }
    /// 资金转移流水
    #[derive(Debug, Clone, Default)]
    struct FundTransferDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 转账流水号
        FundSerial: i32,
        /// 申请流水号
        ApplySerial: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 转移方向
        TransferDirection: u8,
        /// 出入金金额
        Amount: f64,
        /// 转移状态
        TransferStatus: u8,
        /// 操作来源
        OperateSource: u8,
        /// 操作人员
        OperatorID: String,
        /// 操作日期
        OperateDate: String,
        /// 操作时间
        OperateTime: String,
        /// 状态信息
        StatusMsg: String,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 银行代码
        BankID: u8,
        /// 签约银行账户
        BankAccountID: String,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
        /// 投资者代码
        InvestorID: String,
        /// 外部流水号
        ExternalSerial: String,
        /// 外部系统节点号
        ExternalNodeID: i32,
        /// 强平原因(两融专用)
        ForceCloseReason: u8,
        /// (直接还款用)指定偿还时的负债编号(两融专用)
        CreditDebtID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 业务编号
        BizRef: String,
        /// 交易所代码
        ExchangeRef: u8,
    }
    /// 查询持仓转移流水
    #[derive(Debug, Clone, Default)]
    struct QryPositionTransferDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 转移方向
        TransferDirection: u8,
        /// 投资单元代码
        BusinessUnitID: String,
    }
    /// 持仓转移流水
    #[derive(Debug, Clone, Default)]
    struct PositionTransferDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 流水号
        PositionSerial: i32,
        /// 申请流水号
        ApplySerial: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 投资者代码
        InvestorID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 交易账户代码
        ShareholderID: String,
        /// 市场代码
        MarketID: u8,
        /// 证券代码
        SecurityID: String,
        /// 交易日期
        TradingDay: String,
        /// 转移方向
        TransferDirection: u8,
        /// 转移持仓类型
        TransferPositionType: u8,
        /// 转移状态
        TransferStatus: u8,
        /// 昨日仓位数量
        HistoryVolume: i32,
        /// 今日买卖仓位数量
        TodayBSVolume: i32,
        /// 今日申赎仓位数量
        TodayPRVolume: i32,
        /// 今日拆分合并仓位数量
        TodaySMVolume: i32,
        /// 操作人员
        OperatorID: String,
        /// 操作日期
        OperateDate: String,
        /// 操作时间
        OperateTime: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 状态信息
        StatusMsg: String,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
        /// 外部节点编号
        ExternalNodeID: i32,
    }
    /// 查询外围系统仓位调拨流水
    #[derive(Debug, Clone, Default)]
    struct QryPeripheryPositionTransferDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 仓位调拨方向
        TransferDirection: u8,
        /// 投资单元代码
        BusinessUnitID: String,
    }
    /// 外围系统仓位调拨流水
    #[derive(Debug, Clone, Default)]
    struct PeripheryPositionTransferDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 仓位调拨系统流水号
        PositionSerial: i32,
        /// 仓位调拨请求流水号
        ApplySerial: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 仓位调拨方向
        TransferDirection: u8,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 现货系统投资者代码
        InvestorID: String,
        /// 现货系统投资单元代码
        BusinessUnitID: String,
        /// 现货系统交易账户代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 今日买卖仓位转入转出数量
        TodayBSPos: i32,
        /// 今日申赎仓位转入数量
        TodayPRPos: i32,
        /// 今日拆分合并仓位转入数量
        TodaySMPos: i32,
        /// 昨日仓位转入数量
        HistoryPos: i32,
        /// 交易日期
        TradingDay: String,
        /// 仓位调拨原因
        TransferReason: String,
        /// 转移状态
        TransferStatus: u8,
        /// 操作日期
        OperateDate: String,
        /// 操作时间
        OperateTime: String,
        /// 冲正日期
        RepealDate: String,
        /// 冲正时间
        RepealTime: String,
        /// 冲正原因
        RepealReason: String,
        /// 状态信息
        StatusMsg: String,
    }
    /// 查询外围系统资金转移流水
    #[derive(Debug, Clone, Default)]
    struct QryPeripheryFundTransferDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 资金调拨方向
        TransferDirection: u8,
    }
    /// 外围系统资金转移流水
    #[derive(Debug, Clone, Default)]
    struct PeripheryFundTransferDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 转账流水号
        FundSerial: i32,
        /// 申请流水号
        ApplySerial: i32,
        /// 前置编号
        FrontID: i32,
        /// 会话编号
        SessionID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 资金账户代码
        AccountID: String,
        /// 币种
        CurrencyID: u8,
        /// 转移方向
        TransferDirection: u8,
        /// 出入金金额
        Amount: f64,
        /// 投资者代码
        InvestorID: String,
        /// 转移状态
        TransferStatus: u8,
        /// 资金调拨原因
        TransferReason: String,
        /// 操作日期
        OperateDate: String,
        /// 操作时间
        OperateTime: String,
        /// 冲正日期
        RepealDate: String,
        /// 冲正时间
        RepealTime: String,
        /// 冲正原因
        RepealReason: String,
        /// 状态信息
        StatusMsg: String,
        /// 投资单元代码
        BusinessUnitID: String,
    }
    /// 查询债券转股信息
    #[derive(Debug, Clone, Default)]
    struct QryBondConversionInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
    }
    /// 债券转股信息
    #[derive(Debug, Clone, Default)]
    struct BondConversionInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 证券代码
        SecurityID: String,
        /// 转股申报代码
        ConvertOrderID: String,
        /// 转股价格
        ConvertPrice: f64,
        /// 每次可以转股最小交易单位
        ConvertVolUnit: i32,
        /// 证券可以转股的最大数量
        ConvertVolMax: i32,
        /// 证券可以转股的最小数量
        ConvertVolMin: i32,
        /// 转股开始日期
        BeginDate: String,
        /// 转股截至日期
        EndDate: String,
        /// 转股名称
        ConvertName: String,
    }
    /// 查询债券回售信息
    #[derive(Debug, Clone, Default)]
    struct QryBondPutbackInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
    }
    /// 债券回售信息
    #[derive(Debug, Clone, Default)]
    struct BondPutbackInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 证券代码
        SecurityID: String,
        /// 回售申报代码
        PutbackOrderID: String,
        /// 回售名称
        PutbackName: String,
        /// 回售价格
        PutbackPrice: f64,
        /// 每次可以回售最小交易单位
        PutbackVolUnit: i32,
        /// 债券可以回售的最大数量
        PutbackVolMax: i32,
        /// 债券可以回售的最小数量
        PutbackVolMin: i32,
        /// 回售开始日期
        PutbackBeginDate: String,
        /// 回售结束日期
        PutbackEndDate: String,
        /// 回售撤销开始日期
        RelieveBeginDate: String,
        /// 回售撤销结束日期
        RelieveEndDate: String,
    }
    /// 查询投资者条件单限制参数
    #[derive(Debug, Clone, Default)]
    struct QryInvestorCondOrderLimitParamField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
    }
    /// 投资者条件单限制参数
    #[derive(Debug, Clone, Default)]
    struct InvestorCondOrderLimitParamField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 最大条件单数
        MaxCondOrderLimitCnt: i32,
        /// 当前条件单数
        CurrCondOrderCnt: i32,
    }
    /// 查询条件单
    #[derive(Debug, Clone, Default)]
    struct QryConditionOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 证券代码
        SecurityID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 报单编号
        CondOrderID: i32,
        /// Insert Time
        InsertTimeStart: Vec<u8>,
        /// Insert Time
        InsertTimeEnd: Vec<u8>,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 查询条件单撤单
    #[derive(Debug, Clone, Default)]
    struct QryCondOrderActionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 被撤条件单编号
        CondOrderID: i32,
        /// 条件单撤单编号
        CancelCondOrderID: i32,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 条件单撤单
    #[derive(Debug, Clone, Default)]
    struct CondOrderActionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 被撤条件单前置编号
        FrontID: i32,
        /// 被撤条件单会话编号
        SessionID: i32,
        /// 被撤条件单引用
        CondOrderRef: i32,
        /// 被撤条件单编号
        CondOrderID: i32,
        /// 操作标志
        ActionFlag: u8,
        /// 委托方式
        Operway: u8,
        /// 条件单操作引用
        CondOrderActionRef: i32,
        /// 条件单撤单编号
        CancelCondOrderID: i32,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 请求编号
        RequestID: i32,
        /// 撤单前置编号
        ActionFrontID: i32,
        /// 撤单会话编号
        ActionSessionID: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 操作用户
        ActionUser: Vec<u8>,
        /// 操作日期
        ActionDate: String,
        /// 操作时间
        ActionTime: String,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
    }
    /// 查询交易通知
    #[derive(Debug, Clone, Default)]
    struct QryTradingNoticeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// Insert Date
        InsertDateStart: Vec<u8>,
        /// Insert Date
        InsertDateEnd: Vec<u8>,
        /// Insert Time
        InsertTimeStart: Vec<u8>,
        /// Insert Time
        InsertTimeEnd: Vec<u8>,
    }
    /// 查询新股申购配号结果
    #[derive(Debug, Clone, Default)]
    struct QryIPONumberResultField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 申购代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 股东代码
        ShareholderID: String,
    }
    /// 新股申购配号结果
    #[derive(Debug, Clone, Default)]
    struct IPONumberResultField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 市场代码
        MarketID: u8,
        /// 股东代码
        ShareholderID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 日期
        Day: String,
        /// 申购证券名称
        SecurityName: String,
        /// 证券类别代码
        SecurityType: u8,
        /// 起始配号
        BeginNumberID: String,
        /// 配号数量
        Volume: i32,
        /// 投资者代码
        InvestorID: String,
    }
    /// 查询新股申购中签结果
    #[derive(Debug, Clone, Default)]
    struct QryIPOMatchNumberResultField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 申购代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 股东代码
        ShareholderID: String,
        /// 中签配号
        MatchNumberID: String,
    }
    /// 新股申购中签结果
    #[derive(Debug, Clone, Default)]
    struct IPOMatchNumberResultField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 市场代码
        MarketID: u8,
        /// 股东代码
        ShareholderID: String,
        /// 中签配号
        MatchNumberID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 日期
        Day: String,
        /// 申购证券名称
        SecurityName: String,
        /// 证券类别代码
        SecurityType: u8,
        /// 此中签号拥有的证券数量
        Volume: i32,
        /// 申购价格
        Price: f64,
        /// 申购金额
        Amout: f64,
        /// 投资者代码
        InvestorID: String,
    }
    /// 查询交易协议
    #[derive(Debug, Clone, Default)]
    struct QryShareholderSpecPrivilegeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 股东账户代码
        ShareholderID: String,
        /// 特殊权限类别
        SpecPrivilegeType: u8,
        /// 买卖方向
        Direction: u8,
        /// 市场代码
        MarketID: u8,
    }
    /// 交易协议
    #[derive(Debug, Clone, Default)]
    struct ShareholderSpecPrivilegeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 交易账户代码
        ShareholderID: String,
        /// 市场代码
        MarketID: u8,
        /// 特殊权限类别
        SpecPrivilegeType: u8,
        /// 报单类别
        Direction: u8,
        /// 是否禁止
        bForbidden: i32,
        /// 投资者代码
        InvestorID: String,
    }
    /// 查询市场
    #[derive(Debug, Clone, Default)]
    struct QryMarketField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
    }
    /// 市场
    #[derive(Debug, Clone, Default)]
    struct MarketField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 市场代码
        MarketID: u8,
        /// 市场名称
        MarketName: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场状态
        MarketStatus: u8,
    }
    /// 查询ETF清单信息
    #[derive(Debug, Clone, Default)]
    struct QryETFFileField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// ETF二级市场交易代码
        ETFSecurityID: String,
        /// ETF一级市场申赎代码
        ETFCreRedSecurityID: String,
    }
    /// ETF清单信息
    #[derive(Debug, Clone, Default)]
    struct ETFFileField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易日
        TradingDay: String,
        /// 交易所代码
        ExchangeID: u8,
        /// ETF交易代码
        ETFSecurityID: String,
        /// ETF申赎代码
        ETFCreRedSecurityID: String,
        /// 最小申购赎回单位份数
        CreationRedemptionUnit: i32,
        /// 最大现金替代比例
        Maxcashratio: f64,
        /// 预估现金差额
        EstimateCashComponent: f64,
        /// 前一交易日现金差额
        CashComponent: f64,
        /// 前一交易日基金单位净值
        NAV: f64,
        /// 前一交易日申赎基准单位净值
        NAVperCU: f64,
        /// 当日申购赎回基准单位的红利金额
        DividendPerCU: f64,
        /// ETF申赎类型
        ETFCreRedType: u8,
        /// ETF证券名称
        ETFSecurityName: String,
    }
    /// 查询ETF成份证券信息
    #[derive(Debug, Clone, Default)]
    struct QryETFBasketField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// ETF二级市场交易代码
        ETFSecurityID: String,
        /// ETF成份证券代码
        SecurityID: String,
    }
    /// ETF成份证券信息
    #[derive(Debug, Clone, Default)]
    struct ETFBasketField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易日
        TradingDay: String,
        /// 交易所代码
        ExchangeID: u8,
        /// ETF交易代码
        ETFSecurityID: String,
        /// ETF成份证券代码
        SecurityID: String,
        /// 成分证券名称
        SecurityName: String,
        /// 成分证券数量
        Volume: i32,
        /// 现金替代标志
        ETFCurrenceReplaceStatus: u8,
        /// 溢价比例
        Premium: f64,
        /// 申购替代金额
        CreationReplaceAmount: f64,
        /// 赎回替代金额
        RedemptionReplaceAmount: f64,
        /// 挂牌市场
        MarketID: u8,
        /// ETF申赎类型
        ETFCreRedType: u8,
    }
    /// 查询投资者限仓信息
    #[derive(Debug, Clone, Default)]
    struct QryInvestorPositionLimitField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 证券代码
        SecurityID: String,
    }
    /// 投资者限仓信息
    #[derive(Debug, Clone, Default)]
    struct InvestorPositionLimitField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 证券代码
        SecurityID: String,
        /// 当日买入额度
        BuyLimit: i32,
        /// 已使用当日买入额度
        BuyFrozen: i32,
        /// 当日卖出额度
        SellLimit: i32,
        /// 已使用当日卖出额度
        SellFrozen: i32,
        /// 当日申购额度
        PurchaseLimit: i32,
        /// 已使用当日申购额度
        PurchaseFrozen: i32,
        /// 当日赎回额度
        RedeemLimit: i32,
        /// 已使用当日赎回额度
        RedeemFrozen: i32,
        /// 当日质押入库额度
        PledgeInLimit: i32,
        /// 已使用当日质押入库额度
        PledgeInFrozen: i32,
        /// 当日质押出库额度
        PledgeOutLimit: i32,
        /// 已使用当日质押出库额度
        PledgeOutFrozen: i32,
        /// 当日债转股额度
        ConvertLimit: i32,
        /// 已使用当日债转股额度
        ConvertFrozen: i32,
        /// 当日债券回售额度
        PutbackLimit: i32,
        /// 已使用当日债券回售额度
        PutbackFrozen: i32,
        /// 当日配股配债额度
        RationalLimit: i32,
        /// 已使用当日配股配债额度
        RationalFrozen: i32,
        /// 总持仓额度
        TotalPositionLimit: i32,
        /// 已使用总持仓额度
        TotalPositionFrozen: i32,
        /// 当日拆分额度
        SplitLimit: i32,
        /// 已使用当日拆分额度
        SplitFrozen: i32,
        /// 当日合并额度
        MergeLimit: i32,
        /// 已使用当日合并额度
        MergeFrozen: i32,
        /// 通用统一个人识别码
        UUPIC: Vec<u8>,
    }
    /// 查询国际市场互联状态信息
    #[derive(Debug, Clone, Default)]
    struct QryImcParamsField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 市场代码
        MarketID: u8,
    }
    /// 国际市场互联状态信息
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
    /// 查询国际市场互联汇率信息
    #[derive(Debug, Clone, Default)]
    struct QryImcExchangeRateField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 源货币币种
        FromCurrency: u8,
        /// 目标货币币种
        ToCurrency: u8,
        /// 市场代码
        MarketID: u8,
    }
    /// 国际市场互联汇率信息
    #[derive(Debug, Clone, Default)]
    struct ImcExchangeRateField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 源货币币种
        FromCurrency: u8,
        /// 目标货币币种
        ToCurrency: u8,
        /// 参考汇率买入价
        BidRate: f64,
        /// 参考汇率卖出价
        OfferRate: f64,
        /// 参考汇率中间价
        MidPointRate: f64,
        /// 市场代码
        MarketID: u8,
    }
    /// 查询最小价差信息
    #[derive(Debug, Clone, Default)]
    struct QryHKPriceTickInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 价差品种
        PriceTickID: u8,
        /// 市场代码
        MarketID: u8,
    }
    /// 最小价差信息
    #[derive(Debug, Clone, Default)]
    struct HKPriceTickInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 价差品种
        PriceTickID: u8,
        /// 价差组号
        PriceTickGroupID: i32,
        /// 价差类别
        PriceTickType: u8,
        /// 价差组起始价格
        BeginPrice: f64,
        /// 价差组结束价格
        EndPrice: f64,
        /// 价差值
        PriceTick: f64,
        /// 市场代码
        MarketID: u8,
    }
    /// 查询LOF基金信息
    #[derive(Debug, Clone, Default)]
    struct QryLofFundInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 基金代码
        FundID: String,
        /// 主基金代码
        MainFundID: String,
    }
    /// LOF基金信息
    #[derive(Debug, Clone, Default)]
    struct LofFundInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 基金代码
        FundID: String,
        /// 主基金代码
        MainFundID: String,
        /// 基金类型
        FundType: u8,
        /// 拆分数量单位
        SplitUnit: i32,
        /// 最小拆分数量
        SplitMinVol: i32,
        /// 合并数量单位
        MergeUnit: i32,
        /// 最小合并数量
        MergeMinVol: i32,
        /// 基金转换系数
        FundRatio: f64,
    }
    /// 查询投资者质押持仓
    #[derive(Debug, Clone, Default)]
    struct QryPledgePositionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 股东账户代码
        ShareholderID: String,
        /// 投资单元代码
        BusinessUnitID: String,
    }
    /// 投资者质押持仓
    #[derive(Debug, Clone, Default)]
    struct PledgePositionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 客户代码
        ShareholderID: String,
        /// 交易日
        TradingDay: String,
        /// 昨日质押持仓
        HisPledgePos: i32,
        /// 昨日质押持仓冻结
        HisPledgePosFrozen: i32,
        /// 今日入库的质押持仓
        TodayPledgePos: i32,
        /// 今日入库的质押持仓冻结
        TodayPledgePosFrozen: i32,
        /// 昨日质押入库的现券总量
        PreTotalPledgePos: i32,
        /// 昨日质押入库的现券可用数量
        PreAvailablePledgePos: i32,
    }
    /// 查询证券质押信息
    #[derive(Debug, Clone, Default)]
    struct QryPledgeInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
    }
    /// 证券质押信息
    #[derive(Debug, Clone, Default)]
    struct PledgeInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 证券代码
        SecurityID: String,
        /// 质押申报代码
        PledgeOrderID: String,
        /// 质押名称
        PledgeName: String,
        /// 标准券代码
        StandardBondID: String,
        /// 标准券折算率/折算值
        ConversionRate: f64,
        /// 每次可以入库的最小交易单位
        PledgeInTradingUnit: i32,
        /// 每次可以出库的最小交易单位
        PledgeOutTradingUnit: i32,
        /// 证券可以入库的最大数量
        PledgeInVolMax: i32,
        /// 证券可以入库的最小数量
        PledgeInVolMin: i32,
        /// 证券可以出库的最大数量
        PledgeOutVolMax: i32,
        /// 证券可以出库的最小数量
        PledgeOutVolMin: i32,
    }
    /// 查询系统节点信息
    #[derive(Debug, Clone, Default)]
    struct QrySystemNodeInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 节点编号
        NodeID: i32,
    }
    /// 系统节点信息
    #[derive(Debug, Clone, Default)]
    struct SystemNodeInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 节点编号
        NodeID: i32,
        /// 节点信息
        NodeInfo: String,
        /// 是否当前节点
        bCurrent: i32,
    }
    /// 查询投资者标准券额度
    #[derive(Debug, Clone, Default)]
    struct QryStandardBondPositionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 股东账户代码
        ShareholderID: String,
        /// 投资单元代码
        BusinessUnitID: String,
    }
    /// 投资者标准券额度
    #[derive(Debug, Clone, Default)]
    struct StandardBondPositionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 证券代码
        SecurityID: String,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 客户代码
        ShareholderID: String,
        /// 交易日
        TradingDay: String,
        /// 标准券可用额度
        AvailablePosition: i32,
        /// 标准券可用额度冻结
        AvailablePosFrozen: i32,
        /// 标准券额度总量
        TotalPosition: i32,
    }
    /// 查询未到期债券质押回购委托
    #[derive(Debug, Clone, Default)]
    struct QryPrematurityRepoOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 投资者代码
        InvestorID: String,
        /// 证券代码
        SecurityID: String,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 股东账户代码
        ShareholderID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 本地报单编号
        OrderLocalID: String,
        /// 证券品种代码
        ProductID: u8,
        /// 证券类别代码
        SecurityType: u8,
        /// 买卖方向
        Direction: u8,
        /// 成交编号
        TradeID: String,
    }
    /// 未到期债券质押回购委托
    #[derive(Debug, Clone, Default)]
    struct PrematurityRepoOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 市场代码
        MarketID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 交易账户代码
        ShareholderID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 成交日期
        TradeDay: String,
        /// 到期日期
        ExpireDay: String,
        /// 报单编号
        OrderLocalID: String,
        /// 证券代码
        SecurityID: String,
        /// 证券名称
        SecurityName: String,
        /// 证券品种代码
        ProductID: u8,
        /// 证券类别代码
        SecurityType: u8,
        /// 报单类别
        Direction: u8,
        /// 成交数量
        VolumeTraded: i32,
        /// 成交价格
        Price: f64,
        /// 成交金额
        Turnover: f64,
        /// 成交编号
        TradeID: String,
        /// 购回应收金额
        RepoTotalMoney: f64,
        /// 利息金额
        InterestAmount: f64,
    }
    /// 查询协议交易报单
    #[derive(Debug, Clone, Default)]
    struct QryNegoOrderField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 证券代码
        SecurityID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 系统报单编号
        OrderSysID: String,
        /// Insert Time
        InsertTimeStart: Vec<u8>,
        /// Insert Time
        InsertTimeEnd: Vec<u8>,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 查询协议交易撤单
    #[derive(Debug, Clone, Default)]
    struct QryNegoOrderActionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户账户代码
        ShareholderID: String,
        /// 本地报单编号
        OrderLocalID: String,
        /// 本地撤单编号
        CancelOrderLocalID: String,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
    }
    /// 协议交易撤单
    #[derive(Debug, Clone, Default)]
    struct NegoOrderActionField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 操作标志
        ActionFlag: u8,
        /// 本地撤单编号
        CancelOrderLocalID: String,
        /// 系统撤单编号
        CancelOrderSysID: String,
        /// 被撤报单系统报单编号
        OrderSysID: String,
        /// 被撤报单本地报单编号
        OrderLocalID: String,
        /// 委托方式
        Operway: u8,
        /// 字符串附加信息
        SInfo: String,
        /// 整形附加信息
        IInfo: i32,
        /// 经纪公司部门代码
        DepartmentID: String,
        /// 操作用户
        ActionUser: Vec<u8>,
        /// 交易日
        TradingDay: String,
        /// 操作日期
        ActionDate: String,
        /// 操作时间
        ActionTime: String,
        /// 撤单状态
        CancelOrderStatus: u8,
        /// 状态信息
        StatusMsg: String,
        /// 请求编号
        RequestID: i32,
        /// 前置编号
        ActionFrontID: i32,
        /// 会话编号
        ActionSessionID: i32,
        /// 交易单元代码
        PbuID: String,
        /// IP地址
        IPAddress: String,
        /// Mac地址
        MacAddress: String,
    }
    /// 查询协议交易成交
    #[derive(Debug, Clone, Default)]
    struct QryNegoTradeField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 投资者代码
        InvestorID: String,
        /// 投资单元代码
        BusinessUnitID: String,
        /// 证券代码
        SecurityID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 成交编号
        TradeID: String,
        /// Insert Time
        TradeTimeStart: Vec<u8>,
        /// Insert Time
        TradeTimeEnd: Vec<u8>,
    }
    /// 查询协议交易参数
    #[derive(Debug, Clone, Default)]
    struct QryNegotiationParamField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
    }
    /// 协议交易参数
    #[derive(Debug, Clone, Default)]
    struct NegotiationParamField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 合约代码
        SecurityID: String,
        /// 买入交易单位
        BuyTradingUnit: i32,
        /// 卖出交易单位
        SellTradingUnit: i32,
        /// 数量门槛
        MinOrderVolume: i32,
        /// 金额门槛
        MinOrderAmt: f64,
        /// 最小变动价位
        PriceTick: f64,
        /// 涨停板价
        UpperLimitPrice: f64,
        /// 跌停板价
        LowerLimitPrice: f64,
        /// 是否有做市商
        bMarketMaker: i32,
    }
    /// 查询公募基金发行信息
    #[derive(Debug, Clone, Default)]
    struct QryPublicOfferedFundInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 基金代码
        SecurityID: String,
        /// 基金管理人代码
        ManagerID: String,
    }
    /// 公募基金发行信息
    #[derive(Debug, Clone, Default)]
    struct PublicOfferedFundInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 基金代码
        SecurityID: String,
        /// 基金管理人代码
        ManagerID: String,
        /// 转发回报交易单元
        ForwardPbuID: String,
        /// 转发回报股东账号
        ForwardShareholderID: String,
    }
    /// 查询公募基金申赎成交明细
    #[derive(Debug, Clone, Default)]
    struct QryPublicOfferedFundTradeDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 基金代码
        FundSecurityID: String,
        /// 基金管理人代码
        ManagerID: String,
        /// 起始索引序号
        IndexStart: i32,
        /// 结束索引序号
        IndexEnd: i32,
    }
    /// 公募基金申赎成交明细
    #[derive(Debug, Clone, Default)]
    struct PublicOfferedFundTradeDetailField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 股东账户代码
        ShareholderID: String,
        /// 申赎方向
        Direction: u8,
        /// 基金代码
        FundSecurityID: String,
        /// 成分股代码
        BasketSecurityID: String,
        /// 成交回报类型
        TradeReportType: u8,
        /// 成交编号
        TradeID: String,
        /// 交易单元代码
        PbuID: String,
        /// 本地报单编号
        OrderLocalID: String,
        /// 交易所订单编号
        ExchOrderID: String,
        /// 成交明细记录数
        TradeReportNums: i32,
        /// 成分股交付数量
        DeliveryVolume: i32,
        /// 总现金替代金额
        TotalSubsCash: f64,
        /// 沪市替代金额(仅沪市基金有效)
        SSESubsCash: f64,
        /// 深市替代金额(仅沪市基金有效)
        SZSESubsCash: f64,
        /// 港市替代金额(仅沪市基金有效)
        HKSubsCash: f64,
        /// 其它替代金额(仅沪市基金有效)
        OtherSubsCash: f64,
        /// 成交日期
        TradeDate: String,
        /// 成交时间
        TradeTime: String,
        /// 基金管理人代码
        ManagerID: String,
        /// 基金管理人交易单元
        ManagerPbuID: String,
        /// 基金管理人股东账号
        ManagerShareholderID: String,
        /// 数据索引
        DataIndex: i32,
        /// 成分股市场代码
        BasketMarketID: u8,
        /// 关联股东代码(跨市场ETF全实物申赎有效)
        AffiliatedShareholderID: String,
        /// 关联交易单元(跨市场ETF全实物申赎有效)
        AffiliatedPbuID: String,
    }
    /// 查询要约收购信息
    #[derive(Debug, Clone, Default)]
    struct QryTenderInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 要约收购编码
        TenderSecurityID: String,
        /// 收购参与人编码
        TendererID: String,
        /// 标的证券代码
        UnderlyingSecurityID: String,
    }
    /// 要约收购信息
    #[derive(Debug, Clone, Default)]
    struct TenderInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 要约收购编码
        TenderSecurityID: String,
        /// 收购参与人编码
        TendererID: String,
        /// 收购参与人名称
        TendererName: String,
        /// 标的证券代码
        UnderlyingSecurityID: String,
        /// 标的证券名称
        UnderlyingSecurityName: String,
        /// 证券品种代码
        ProductID: u8,
        /// 证券类别代码
        SecurityType: u8,
        /// 收购价格
        OfferingPrice: f64,
        /// 收购最小数量
        MinOrderVol: i32,
        /// 收购最大数量
        MaxOrderVol: i32,
        /// 收购单位
        OrderUnit: i32,
        /// 收购起始日期
        BeginDate: String,
        /// 收购结束日期
        EndDate: String,
    }
    /// 查询基础设施基金非定向扩募信息
    #[derive(Debug, Clone, Default)]
    struct QryAdditionalOfferingInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
    }
    /// 基础设施基金非定向扩募信息
    #[derive(Debug, Clone, Default)]
    struct AdditionalOfferingInfoField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 证券名称
        SecurityName: String,
        /// 产品代码
        ProductID: u8,
        /// 证券类别代码
        SecurityType: u8,
        /// 最小申购价格
        MinPrice: f64,
        /// 最大申购价格
        MaxPrice: f64,
        /// 最小申购数量
        MinVolume: i32,
        /// 最大申购数量
        MaxVolume: i32,
        /// 申购单位数量
        VolumeUnit: i32,
        /// 扩募开始日期
        BeginDate: String,
        /// 扩募截止日期
        EndDate: String,
        /// 备注
        Remark: i64,
    }
    /// 查询基础设施基金非定向扩募配售额度
    #[derive(Debug, Clone, Default)]
    struct QryAdditionalOfferingQuotaField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 证券代码
        SecurityID: String,
        /// 股东账户代码
        ShareholderID: String,
        /// 投资者代码
        InvestorID: String,
    }
    /// 基础设施基金非定向扩募配售额度
    #[derive(Debug, Clone, Default)]
    struct AdditionalOfferingQuotaField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 交易所代码
        ExchangeID: u8,
        /// 股东代码
        ShareholderID: String,
        /// 证券代码
        SecurityID: String,
        /// 投资者代码
        InvestorID: String,
        /// 配售额度
        MaxVolume: i32,
        /// 冻结额度
        FrzVolume: i32,
    }
    /// 强制交易员退出
    #[derive(Debug, Clone, Default)]
    struct ForceUserLogoutField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户代码
        UserID: String,
        /// 用户请求编号
        UserRequestID: i32,
    }
    /// 启用解锁用户
    #[derive(Debug, Clone, Default)]
    struct ActivateUserField {
        /// C++ 端传入的整体 Field 是否为 `nullptr`
        is_null: bool,
        /// 用户代码
        UserID: String,
        /// 用户请求编号
        UserRequestID: i32,
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
        /// 用户请求编号
        UserRequestID: i32,
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
