#pragma once
#include "tora-rs/src/trader.rs.h"
#include "TORATstpTraderApi.h"
#include "rust/cxx.h"
#include <cstdint>

namespace tora_trader {
using namespace TORASTOCKAPI;

class CTraderSpi : public CTORATstpTraderSpi
{
public:
    explicit CTraderSpi(rust::Box<TraderSpi> gateway);
    void OnFrontConnected() override;
    void OnFrontDisconnected(int32_t nReason) override;
    void OnRspError(CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspGetConnectionInfo(CTORATstpConnectionInfoField* pConnectionInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLoginField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspUserLogout(CTORATstpUserLogoutField* pUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspUserPasswordUpdate(CTORATstpUserPasswordUpdateField* pUserPasswordUpdateField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspInputDeviceSerial(CTORATstpRspInputDeviceSerialField* pRspInputDeviceSerialField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspPublicOfferedFundOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRtnOrder(CTORATstpOrderField* pOrderField) override;
    void OnErrRtnOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRtnTrade(CTORATstpTradeField* pTradeField) override;
    void OnRspOrderAction(CTORATstpInputOrderActionField* pInputOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnErrRtnOrderAction(CTORATstpInputOrderActionField* pInputOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspCondOrderInsert(CTORATstpInputCondOrderField* pInputCondOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRtnCondOrder(CTORATstpConditionOrderField* pConditionOrderField) override;
    void OnErrRtnCondOrderInsert(CTORATstpInputCondOrderField* pInputCondOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspCondOrderAction(CTORATstpInputCondOrderActionField* pInputCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnErrRtnCondOrderAction(CTORATstpInputCondOrderActionField* pInputCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspNegoOrderInsert(CTORATstpInputNegoOrderField* pInputNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRtnNegoOrder(CTORATstpNegoOrderField* pNegoOrderField) override;
    void OnErrRtnNegoOrderInsert(CTORATstpInputNegoOrderField* pInputNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRtnNegoTrade(CTORATstpNegoTradeField* pNegoTradeField) override;
    void OnRspNegoOrderAction(CTORATstpInputNegoOrderActionField* pInputNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnErrRtnNegoOrderAction(CTORATstpInputNegoOrderActionField* pInputNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspOrderInsertEx(CTORATstpInputOrderExField* pInputOrderExField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspOrderActionEx(CTORATstpInputOrderActionExField* pInputOrderActionExField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRtnMarketStatus(CTORATstpMarketStatusField* pMarketStatusField) override;
    void OnRspTransferFund(CTORATstpInputTransferFundField* pInputTransferFundField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnErrRtnTransferFund(CTORATstpInputTransferFundField* pInputTransferFundField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRtnTransferFund(CTORATstpTransferFundField* pTransferFundField) override;
    void OnRspTransferPosition(CTORATstpInputTransferPositionField* pInputTransferPositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnErrRtnTransferPosition(CTORATstpInputTransferPositionField* pInputTransferPositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRtnTransferPosition(CTORATstpTransferPositionField* pTransferPositionField) override;
    void OnRtnPeripheryTransferPosition(CTORATstpPeripheryTransferPositionField* pPeripheryTransferPositionField) override;
    void OnRtnPeripheryTransferFund(CTORATstpPeripheryTransferFundField* pPeripheryTransferFundField) override;
    void OnRspInquiryJZFund(CTORATstpRspInquiryJZFundField* pRspInquiryJZFundField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspInquiryBankAccountFund(CTORATstpRspInquiryBankAccountFundField* pRspInquiryBankAccountFundField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRtnTradingNotice(CTORATstpTradingNoticeField* pTradingNoticeField) override;
    void OnRspInquiryMaxOrderVolume(CTORATstpRspInquiryMaxOrderVolumeField* pRspInquiryMaxOrderVolumeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspInquiryTradeConcentration(CTORATstpInquiryTradeConcentrationField* pInquiryTradeConcentrationField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspModifyOpenPosCost(CTORATstpReqModifyOpenPosCostField* pReqModifyOpenPosCostField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspInputNodeFundAssignment(CTORATstpInputNodeFundAssignmentField* pInputNodeFundAssignmentField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspInquiryNodeFundAssignment(CTORATstpRspInquiryNodeFundAssignmentField* pRspInquiryNodeFundAssignmentField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspQryExchange(CTORATstpExchangeField* pExchangeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQrySecurity(CTORATstpSecurityField* pSecurityField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryIPOInfo(CTORATstpIPOInfoField* pIPOInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryUser(CTORATstpUserField* pUserField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryInvestor(CTORATstpInvestorField* pInvestorField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryShareholderAccount(CTORATstpShareholderAccountField* pShareholderAccountField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryRationalInfo(CTORATstpRationalInfoField* pRationalInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryOrder(CTORATstpOrderField* pOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryOrderAction(CTORATstpOrderActionField* pOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryTrade(CTORATstpTradeField* pTradeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryTradingAccount(CTORATstpTradingAccountField* pTradingAccountField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryPosition(CTORATstpPositionField* pPositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryTradingFee(CTORATstpTradingFeeField* pTradingFeeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryInvestorTradingFee(CTORATstpInvestorTradingFeeField* pInvestorTradingFeeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryIPOQuota(CTORATstpIPOQuotaField* pIPOQuotaField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryOrderFundDetail(CTORATstpOrderFundDetailField* pOrderFundDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryFundTransferDetail(CTORATstpFundTransferDetailField* pFundTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryPositionTransferDetail(CTORATstpPositionTransferDetailField* pPositionTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryPeripheryPositionTransferDetail(CTORATstpPeripheryPositionTransferDetailField* pPeripheryPositionTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryPeripheryFundTransferDetail(CTORATstpPeripheryFundTransferDetailField* pPeripheryFundTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryBondConversionInfo(CTORATstpBondConversionInfoField* pBondConversionInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryBondPutbackInfo(CTORATstpBondPutbackInfoField* pBondPutbackInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryInvestorCondOrderLimitParam(CTORATstpInvestorCondOrderLimitParamField* pInvestorCondOrderLimitParamField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryConditionOrder(CTORATstpConditionOrderField* pConditionOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryCondOrderAction(CTORATstpCondOrderActionField* pCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryTradingNotice(CTORATstpTradingNoticeField* pTradingNoticeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryIPONumberResult(CTORATstpIPONumberResultField* pIPONumberResultField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryIPOMatchNumberResult(CTORATstpIPOMatchNumberResultField* pIPOMatchNumberResultField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryShareholderSpecPrivilege(CTORATstpShareholderSpecPrivilegeField* pShareholderSpecPrivilegeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryMarket(CTORATstpMarketField* pMarketField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryETFFile(CTORATstpETFFileField* pETFFileField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryETFBasket(CTORATstpETFBasketField* pETFBasketField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryInvestorPositionLimit(CTORATstpInvestorPositionLimitField* pInvestorPositionLimitField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryImcParams(CTORATstpImcParamsField* pImcParamsField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryImcExchangeRate(CTORATstpImcExchangeRateField* pImcExchangeRateField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryHKPriceTickInfo(CTORATstpHKPriceTickInfoField* pHKPriceTickInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryLofFundInfo(CTORATstpLofFundInfoField* pLofFundInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryPledgePosition(CTORATstpPledgePositionField* pPledgePositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryPledgeInfo(CTORATstpPledgeInfoField* pPledgeInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQrySystemNodeInfo(CTORATstpSystemNodeInfoField* pSystemNodeInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryStandardBondPosition(CTORATstpStandardBondPositionField* pStandardBondPositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryPrematurityRepoOrder(CTORATstpPrematurityRepoOrderField* pPrematurityRepoOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryNegoOrder(CTORATstpNegoOrderField* pNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryNegoOrderAction(CTORATstpNegoOrderActionField* pNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryNegoTrade(CTORATstpNegoTradeField* pNegoTradeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryNegotiationParam(CTORATstpNegotiationParamField* pNegotiationParamField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryPublicOfferedFundInfo(CTORATstpPublicOfferedFundInfoField* pPublicOfferedFundInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryPublicOfferedFundTradeDetail(CTORATstpPublicOfferedFundTradeDetailField* pPublicOfferedFundTradeDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryTenderInfo(CTORATstpTenderInfoField* pTenderInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryAdditionalOfferingInfo(CTORATstpAdditionalOfferingInfoField* pAdditionalOfferingInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspQryAdditionalOfferingQuota(CTORATstpAdditionalOfferingQuotaField* pAdditionalOfferingQuotaField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspForceUserExit(CTORATstpForceUserLogoutField* pForceUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspForceUserLogout(CTORATstpForceUserLogoutField* pForceUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspActivateUser(CTORATstpActivateUserField* pActivateUserField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;

private:
    rust::Box<TraderSpi> gateway;
};
} // namespace tora_trader
