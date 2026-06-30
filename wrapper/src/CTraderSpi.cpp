#include "tora-rs/wrapper/include/CTraderSpi.h"
#include "tora-rs/wrapper/include/TraderConverter.h"

namespace tora_trader {
using namespace TORASTOCKAPI;

CTraderSpi::CTraderSpi(rust::Box<TraderSpi> gateway) : gateway(std::move(gateway)) { }

void CTraderSpi::OnFrontConnected() {
    this->gateway->OnFrontConnected(
    );
}

void CTraderSpi::OnFrontDisconnected(int32_t nReason) {
    this->gateway->OnFrontDisconnected(
        nReason
    );
}

void CTraderSpi::OnRspError(CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspError(
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspGetConnectionInfo(CTORATstpConnectionInfoField* pConnectionInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspGetConnectionInfo(
        Converter::CTORATstpConnectionInfoFieldToRust(pConnectionInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLoginField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspUserLogin(
        Converter::CTORATstpRspUserLoginFieldToRust(pRspUserLoginField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspUserLogout(CTORATstpUserLogoutField* pUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspUserLogout(
        Converter::CTORATstpUserLogoutFieldToRust(pUserLogoutField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspUserPasswordUpdate(CTORATstpUserPasswordUpdateField* pUserPasswordUpdateField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspUserPasswordUpdate(
        Converter::CTORATstpUserPasswordUpdateFieldToRust(pUserPasswordUpdateField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspInputDeviceSerial(CTORATstpRspInputDeviceSerialField* pRspInputDeviceSerialField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspInputDeviceSerial(
        Converter::CTORATstpRspInputDeviceSerialFieldToRust(pRspInputDeviceSerialField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspOrderInsert(
        Converter::CTORATstpInputOrderFieldToRust(pInputOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspPublicOfferedFundOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspPublicOfferedFundOrderInsert(
        Converter::CTORATstpInputOrderFieldToRust(pInputOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRtnOrder(CTORATstpOrderField* pOrderField) {
    this->gateway->OnRtnOrder(
        Converter::CTORATstpOrderFieldToRust(pOrderField)
    );
}

void CTraderSpi::OnErrRtnOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnErrRtnOrderInsert(
        Converter::CTORATstpInputOrderFieldToRust(pInputOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRtnTrade(CTORATstpTradeField* pTradeField) {
    this->gateway->OnRtnTrade(
        Converter::CTORATstpTradeFieldToRust(pTradeField)
    );
}

void CTraderSpi::OnRspOrderAction(CTORATstpInputOrderActionField* pInputOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspOrderAction(
        Converter::CTORATstpInputOrderActionFieldToRust(pInputOrderActionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnErrRtnOrderAction(CTORATstpInputOrderActionField* pInputOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnErrRtnOrderAction(
        Converter::CTORATstpInputOrderActionFieldToRust(pInputOrderActionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspCondOrderInsert(CTORATstpInputCondOrderField* pInputCondOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspCondOrderInsert(
        Converter::CTORATstpInputCondOrderFieldToRust(pInputCondOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRtnCondOrder(CTORATstpConditionOrderField* pConditionOrderField) {
    this->gateway->OnRtnCondOrder(
        Converter::CTORATstpConditionOrderFieldToRust(pConditionOrderField)
    );
}

void CTraderSpi::OnErrRtnCondOrderInsert(CTORATstpInputCondOrderField* pInputCondOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnErrRtnCondOrderInsert(
        Converter::CTORATstpInputCondOrderFieldToRust(pInputCondOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspCondOrderAction(CTORATstpInputCondOrderActionField* pInputCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspCondOrderAction(
        Converter::CTORATstpInputCondOrderActionFieldToRust(pInputCondOrderActionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnErrRtnCondOrderAction(CTORATstpInputCondOrderActionField* pInputCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnErrRtnCondOrderAction(
        Converter::CTORATstpInputCondOrderActionFieldToRust(pInputCondOrderActionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspNegoOrderInsert(CTORATstpInputNegoOrderField* pInputNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspNegoOrderInsert(
        Converter::CTORATstpInputNegoOrderFieldToRust(pInputNegoOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRtnNegoOrder(CTORATstpNegoOrderField* pNegoOrderField) {
    this->gateway->OnRtnNegoOrder(
        Converter::CTORATstpNegoOrderFieldToRust(pNegoOrderField)
    );
}

void CTraderSpi::OnErrRtnNegoOrderInsert(CTORATstpInputNegoOrderField* pInputNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnErrRtnNegoOrderInsert(
        Converter::CTORATstpInputNegoOrderFieldToRust(pInputNegoOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRtnNegoTrade(CTORATstpNegoTradeField* pNegoTradeField) {
    this->gateway->OnRtnNegoTrade(
        Converter::CTORATstpNegoTradeFieldToRust(pNegoTradeField)
    );
}

void CTraderSpi::OnRspNegoOrderAction(CTORATstpInputNegoOrderActionField* pInputNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspNegoOrderAction(
        Converter::CTORATstpInputNegoOrderActionFieldToRust(pInputNegoOrderActionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnErrRtnNegoOrderAction(CTORATstpInputNegoOrderActionField* pInputNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnErrRtnNegoOrderAction(
        Converter::CTORATstpInputNegoOrderActionFieldToRust(pInputNegoOrderActionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspOrderInsertEx(CTORATstpInputOrderExField* pInputOrderExField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspOrderInsertEx(
        Converter::CTORATstpInputOrderExFieldToRust(pInputOrderExField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspOrderActionEx(CTORATstpInputOrderActionExField* pInputOrderActionExField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspOrderActionEx(
        Converter::CTORATstpInputOrderActionExFieldToRust(pInputOrderActionExField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRtnMarketStatus(CTORATstpMarketStatusField* pMarketStatusField) {
    this->gateway->OnRtnMarketStatus(
        Converter::CTORATstpMarketStatusFieldToRust(pMarketStatusField)
    );
}

void CTraderSpi::OnRspTransferFund(CTORATstpInputTransferFundField* pInputTransferFundField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspTransferFund(
        Converter::CTORATstpInputTransferFundFieldToRust(pInputTransferFundField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnErrRtnTransferFund(CTORATstpInputTransferFundField* pInputTransferFundField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnErrRtnTransferFund(
        Converter::CTORATstpInputTransferFundFieldToRust(pInputTransferFundField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRtnTransferFund(CTORATstpTransferFundField* pTransferFundField) {
    this->gateway->OnRtnTransferFund(
        Converter::CTORATstpTransferFundFieldToRust(pTransferFundField)
    );
}

void CTraderSpi::OnRspTransferPosition(CTORATstpInputTransferPositionField* pInputTransferPositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspTransferPosition(
        Converter::CTORATstpInputTransferPositionFieldToRust(pInputTransferPositionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnErrRtnTransferPosition(CTORATstpInputTransferPositionField* pInputTransferPositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnErrRtnTransferPosition(
        Converter::CTORATstpInputTransferPositionFieldToRust(pInputTransferPositionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRtnTransferPosition(CTORATstpTransferPositionField* pTransferPositionField) {
    this->gateway->OnRtnTransferPosition(
        Converter::CTORATstpTransferPositionFieldToRust(pTransferPositionField)
    );
}

void CTraderSpi::OnRtnPeripheryTransferPosition(CTORATstpPeripheryTransferPositionField* pPeripheryTransferPositionField) {
    this->gateway->OnRtnPeripheryTransferPosition(
        Converter::CTORATstpPeripheryTransferPositionFieldToRust(pPeripheryTransferPositionField)
    );
}

void CTraderSpi::OnRtnPeripheryTransferFund(CTORATstpPeripheryTransferFundField* pPeripheryTransferFundField) {
    this->gateway->OnRtnPeripheryTransferFund(
        Converter::CTORATstpPeripheryTransferFundFieldToRust(pPeripheryTransferFundField)
    );
}

void CTraderSpi::OnRspInquiryJZFund(CTORATstpRspInquiryJZFundField* pRspInquiryJZFundField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspInquiryJZFund(
        Converter::CTORATstpRspInquiryJZFundFieldToRust(pRspInquiryJZFundField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspInquiryBankAccountFund(CTORATstpRspInquiryBankAccountFundField* pRspInquiryBankAccountFundField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspInquiryBankAccountFund(
        Converter::CTORATstpRspInquiryBankAccountFundFieldToRust(pRspInquiryBankAccountFundField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRtnTradingNotice(CTORATstpTradingNoticeField* pTradingNoticeField) {
    this->gateway->OnRtnTradingNotice(
        Converter::CTORATstpTradingNoticeFieldToRust(pTradingNoticeField)
    );
}

void CTraderSpi::OnRspInquiryMaxOrderVolume(CTORATstpRspInquiryMaxOrderVolumeField* pRspInquiryMaxOrderVolumeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspInquiryMaxOrderVolume(
        Converter::CTORATstpRspInquiryMaxOrderVolumeFieldToRust(pRspInquiryMaxOrderVolumeField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspInquiryTradeConcentration(CTORATstpInquiryTradeConcentrationField* pInquiryTradeConcentrationField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspInquiryTradeConcentration(
        Converter::CTORATstpInquiryTradeConcentrationFieldToRust(pInquiryTradeConcentrationField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspModifyOpenPosCost(CTORATstpReqModifyOpenPosCostField* pReqModifyOpenPosCostField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspModifyOpenPosCost(
        Converter::CTORATstpReqModifyOpenPosCostFieldToRust(pReqModifyOpenPosCostField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspInputNodeFundAssignment(CTORATstpInputNodeFundAssignmentField* pInputNodeFundAssignmentField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspInputNodeFundAssignment(
        Converter::CTORATstpInputNodeFundAssignmentFieldToRust(pInputNodeFundAssignmentField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspInquiryNodeFundAssignment(CTORATstpRspInquiryNodeFundAssignmentField* pRspInquiryNodeFundAssignmentField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspInquiryNodeFundAssignment(
        Converter::CTORATstpRspInquiryNodeFundAssignmentFieldToRust(pRspInquiryNodeFundAssignmentField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspQryExchange(CTORATstpExchangeField* pExchangeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryExchange(
        Converter::CTORATstpExchangeFieldToRust(pExchangeField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQrySecurity(CTORATstpSecurityField* pSecurityField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQrySecurity(
        Converter::CTORATstpSecurityFieldToRust(pSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryIPOInfo(CTORATstpIPOInfoField* pIPOInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryIPOInfo(
        Converter::CTORATstpIPOInfoFieldToRust(pIPOInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryUser(CTORATstpUserField* pUserField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryUser(
        Converter::CTORATstpUserFieldToRust(pUserField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryInvestor(CTORATstpInvestorField* pInvestorField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryInvestor(
        Converter::CTORATstpInvestorFieldToRust(pInvestorField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryShareholderAccount(CTORATstpShareholderAccountField* pShareholderAccountField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryShareholderAccount(
        Converter::CTORATstpShareholderAccountFieldToRust(pShareholderAccountField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryRationalInfo(CTORATstpRationalInfoField* pRationalInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryRationalInfo(
        Converter::CTORATstpRationalInfoFieldToRust(pRationalInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryOrder(CTORATstpOrderField* pOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryOrder(
        Converter::CTORATstpOrderFieldToRust(pOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryOrderAction(CTORATstpOrderActionField* pOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryOrderAction(
        Converter::CTORATstpOrderActionFieldToRust(pOrderActionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryTrade(CTORATstpTradeField* pTradeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryTrade(
        Converter::CTORATstpTradeFieldToRust(pTradeField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryTradingAccount(CTORATstpTradingAccountField* pTradingAccountField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryTradingAccount(
        Converter::CTORATstpTradingAccountFieldToRust(pTradingAccountField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryPosition(CTORATstpPositionField* pPositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryPosition(
        Converter::CTORATstpPositionFieldToRust(pPositionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryTradingFee(CTORATstpTradingFeeField* pTradingFeeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryTradingFee(
        Converter::CTORATstpTradingFeeFieldToRust(pTradingFeeField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryInvestorTradingFee(CTORATstpInvestorTradingFeeField* pInvestorTradingFeeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryInvestorTradingFee(
        Converter::CTORATstpInvestorTradingFeeFieldToRust(pInvestorTradingFeeField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryIPOQuota(CTORATstpIPOQuotaField* pIPOQuotaField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryIPOQuota(
        Converter::CTORATstpIPOQuotaFieldToRust(pIPOQuotaField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryOrderFundDetail(CTORATstpOrderFundDetailField* pOrderFundDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryOrderFundDetail(
        Converter::CTORATstpOrderFundDetailFieldToRust(pOrderFundDetailField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryFundTransferDetail(CTORATstpFundTransferDetailField* pFundTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryFundTransferDetail(
        Converter::CTORATstpFundTransferDetailFieldToRust(pFundTransferDetailField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryPositionTransferDetail(CTORATstpPositionTransferDetailField* pPositionTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryPositionTransferDetail(
        Converter::CTORATstpPositionTransferDetailFieldToRust(pPositionTransferDetailField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryPeripheryPositionTransferDetail(CTORATstpPeripheryPositionTransferDetailField* pPeripheryPositionTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryPeripheryPositionTransferDetail(
        Converter::CTORATstpPeripheryPositionTransferDetailFieldToRust(pPeripheryPositionTransferDetailField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryPeripheryFundTransferDetail(CTORATstpPeripheryFundTransferDetailField* pPeripheryFundTransferDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryPeripheryFundTransferDetail(
        Converter::CTORATstpPeripheryFundTransferDetailFieldToRust(pPeripheryFundTransferDetailField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryBondConversionInfo(CTORATstpBondConversionInfoField* pBondConversionInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryBondConversionInfo(
        Converter::CTORATstpBondConversionInfoFieldToRust(pBondConversionInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryBondPutbackInfo(CTORATstpBondPutbackInfoField* pBondPutbackInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryBondPutbackInfo(
        Converter::CTORATstpBondPutbackInfoFieldToRust(pBondPutbackInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryInvestorCondOrderLimitParam(CTORATstpInvestorCondOrderLimitParamField* pInvestorCondOrderLimitParamField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryInvestorCondOrderLimitParam(
        Converter::CTORATstpInvestorCondOrderLimitParamFieldToRust(pInvestorCondOrderLimitParamField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryConditionOrder(CTORATstpConditionOrderField* pConditionOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryConditionOrder(
        Converter::CTORATstpConditionOrderFieldToRust(pConditionOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryCondOrderAction(CTORATstpCondOrderActionField* pCondOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryCondOrderAction(
        Converter::CTORATstpCondOrderActionFieldToRust(pCondOrderActionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryTradingNotice(CTORATstpTradingNoticeField* pTradingNoticeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryTradingNotice(
        Converter::CTORATstpTradingNoticeFieldToRust(pTradingNoticeField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryIPONumberResult(CTORATstpIPONumberResultField* pIPONumberResultField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryIPONumberResult(
        Converter::CTORATstpIPONumberResultFieldToRust(pIPONumberResultField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryIPOMatchNumberResult(CTORATstpIPOMatchNumberResultField* pIPOMatchNumberResultField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryIPOMatchNumberResult(
        Converter::CTORATstpIPOMatchNumberResultFieldToRust(pIPOMatchNumberResultField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryShareholderSpecPrivilege(CTORATstpShareholderSpecPrivilegeField* pShareholderSpecPrivilegeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryShareholderSpecPrivilege(
        Converter::CTORATstpShareholderSpecPrivilegeFieldToRust(pShareholderSpecPrivilegeField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryMarket(CTORATstpMarketField* pMarketField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryMarket(
        Converter::CTORATstpMarketFieldToRust(pMarketField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryETFFile(CTORATstpETFFileField* pETFFileField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryETFFile(
        Converter::CTORATstpETFFileFieldToRust(pETFFileField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryETFBasket(CTORATstpETFBasketField* pETFBasketField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryETFBasket(
        Converter::CTORATstpETFBasketFieldToRust(pETFBasketField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryInvestorPositionLimit(CTORATstpInvestorPositionLimitField* pInvestorPositionLimitField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryInvestorPositionLimit(
        Converter::CTORATstpInvestorPositionLimitFieldToRust(pInvestorPositionLimitField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryImcParams(CTORATstpImcParamsField* pImcParamsField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryImcParams(
        Converter::CTORATstpImcParamsFieldToRust(pImcParamsField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryImcExchangeRate(CTORATstpImcExchangeRateField* pImcExchangeRateField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryImcExchangeRate(
        Converter::CTORATstpImcExchangeRateFieldToRust(pImcExchangeRateField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryHKPriceTickInfo(CTORATstpHKPriceTickInfoField* pHKPriceTickInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryHKPriceTickInfo(
        Converter::CTORATstpHKPriceTickInfoFieldToRust(pHKPriceTickInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryLofFundInfo(CTORATstpLofFundInfoField* pLofFundInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryLofFundInfo(
        Converter::CTORATstpLofFundInfoFieldToRust(pLofFundInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryPledgePosition(CTORATstpPledgePositionField* pPledgePositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryPledgePosition(
        Converter::CTORATstpPledgePositionFieldToRust(pPledgePositionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryPledgeInfo(CTORATstpPledgeInfoField* pPledgeInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryPledgeInfo(
        Converter::CTORATstpPledgeInfoFieldToRust(pPledgeInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQrySystemNodeInfo(CTORATstpSystemNodeInfoField* pSystemNodeInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQrySystemNodeInfo(
        Converter::CTORATstpSystemNodeInfoFieldToRust(pSystemNodeInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryStandardBondPosition(CTORATstpStandardBondPositionField* pStandardBondPositionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryStandardBondPosition(
        Converter::CTORATstpStandardBondPositionFieldToRust(pStandardBondPositionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryPrematurityRepoOrder(CTORATstpPrematurityRepoOrderField* pPrematurityRepoOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryPrematurityRepoOrder(
        Converter::CTORATstpPrematurityRepoOrderFieldToRust(pPrematurityRepoOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryNegoOrder(CTORATstpNegoOrderField* pNegoOrderField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryNegoOrder(
        Converter::CTORATstpNegoOrderFieldToRust(pNegoOrderField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryNegoOrderAction(CTORATstpNegoOrderActionField* pNegoOrderActionField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryNegoOrderAction(
        Converter::CTORATstpNegoOrderActionFieldToRust(pNegoOrderActionField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryNegoTrade(CTORATstpNegoTradeField* pNegoTradeField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryNegoTrade(
        Converter::CTORATstpNegoTradeFieldToRust(pNegoTradeField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryNegotiationParam(CTORATstpNegotiationParamField* pNegotiationParamField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryNegotiationParam(
        Converter::CTORATstpNegotiationParamFieldToRust(pNegotiationParamField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryPublicOfferedFundInfo(CTORATstpPublicOfferedFundInfoField* pPublicOfferedFundInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryPublicOfferedFundInfo(
        Converter::CTORATstpPublicOfferedFundInfoFieldToRust(pPublicOfferedFundInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryPublicOfferedFundTradeDetail(CTORATstpPublicOfferedFundTradeDetailField* pPublicOfferedFundTradeDetailField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryPublicOfferedFundTradeDetail(
        Converter::CTORATstpPublicOfferedFundTradeDetailFieldToRust(pPublicOfferedFundTradeDetailField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryTenderInfo(CTORATstpTenderInfoField* pTenderInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryTenderInfo(
        Converter::CTORATstpTenderInfoFieldToRust(pTenderInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryAdditionalOfferingInfo(CTORATstpAdditionalOfferingInfoField* pAdditionalOfferingInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryAdditionalOfferingInfo(
        Converter::CTORATstpAdditionalOfferingInfoFieldToRust(pAdditionalOfferingInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspQryAdditionalOfferingQuota(CTORATstpAdditionalOfferingQuotaField* pAdditionalOfferingQuotaField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspQryAdditionalOfferingQuota(
        Converter::CTORATstpAdditionalOfferingQuotaFieldToRust(pAdditionalOfferingQuotaField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CTraderSpi::OnRspForceUserExit(CTORATstpForceUserLogoutField* pForceUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspForceUserExit(
        Converter::CTORATstpForceUserLogoutFieldToRust(pForceUserLogoutField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspForceUserLogout(CTORATstpForceUserLogoutField* pForceUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspForceUserLogout(
        Converter::CTORATstpForceUserLogoutFieldToRust(pForceUserLogoutField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CTraderSpi::OnRspActivateUser(CTORATstpActivateUserField* pActivateUserField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspActivateUser(
        Converter::CTORATstpActivateUserFieldToRust(pActivateUserField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

} // namespace tora_trader
