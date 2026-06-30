#include "tora-rs/wrapper/include/TraderApi.h"
#include "tora-rs/wrapper/include/TraderConverter.h"

namespace tora_trader {
using namespace TORASTOCKAPI;

TraderApi::TraderApi(rust::Box<TraderSpi> gateway, rust::String flow_path, bool is_encrypt, uint8_t trade_comm_mode, rust::String interface_addr, bool is_using_order_ex) {
    spi = new CTraderSpi(std::move(gateway));
    api = CTORATstpTraderApi::CreateTstpTraderApi(flow_path.c_str(), is_encrypt, trade_comm_mode, interface_addr.c_str(), is_using_order_ex);
    api->RegisterSpi(spi);
}

TraderApi::~TraderApi() {
    if (api) {
        api->Release();
        api = nullptr;
    }
    delete spi;
    spi = nullptr;
}

std::unique_ptr<TraderApi> CreateTraderApi(rust::Box<TraderSpi> gateway, rust::String flow_path, bool is_encrypt, uint8_t trade_comm_mode, rust::String interface_addr, bool is_using_order_ex) {
    return std::make_unique<TraderApi>(std::move(gateway), flow_path, is_encrypt, trade_comm_mode, interface_addr, is_using_order_ex);
}

rust::String TraderApi::GetApiVersion() const {
    return api->GetApiVersion();
}

void TraderApi::Init() const {
    api->Init();
}

int32_t TraderApi::Join() const {
    return api->Join();
}

void TraderApi::RegisterFront(rust::String pszFrontAddress) const {
    api->RegisterFront(const_cast<char *>(pszFrontAddress.c_str()));
}

void TraderApi::RegisterNameServer(rust::String pszNsAddress) const {
    api->RegisterNameServer(const_cast<char *>(pszNsAddress.c_str()));
}

void TraderApi::RegisterFensUserInfo(FensUserInfoField pFensUserInfoField) const {
    CTORATstpFensUserInfoField req(Converter::FensUserInfoFieldToCpp(pFensUserInfoField));
    api->RegisterFensUserInfo(&req);
}

void TraderApi::SubscribePrivateTopic(int32_t nResumeType) const {
    api->SubscribePrivateTopic((TORA_TE_RESUME_TYPE)nResumeType);
}

void TraderApi::SubscribePublicTopic(int32_t nResumeType) const {
    api->SubscribePublicTopic((TORA_TE_RESUME_TYPE)nResumeType);
}

int32_t TraderApi::ReqGetConnectionInfo(int32_t nRequestID) const {
    return api->ReqGetConnectionInfo(nRequestID);
}

int32_t TraderApi::ReqUserLogin(ReqUserLoginField pReqUserLoginField, int32_t nRequestID) const {
    CTORATstpReqUserLoginField req(Converter::ReqUserLoginFieldToCpp(pReqUserLoginField));
    return api->ReqUserLogin(&req, nRequestID);
}

int32_t TraderApi::ReqUserLogout(UserLogoutField pUserLogoutField, int32_t nRequestID) const {
    CTORATstpUserLogoutField req(Converter::UserLogoutFieldToCpp(pUserLogoutField));
    return api->ReqUserLogout(&req, nRequestID);
}

int32_t TraderApi::ReqUserPasswordUpdate(UserPasswordUpdateField pUserPasswordUpdateField, int32_t nRequestID) const {
    CTORATstpUserPasswordUpdateField req(Converter::UserPasswordUpdateFieldToCpp(pUserPasswordUpdateField));
    return api->ReqUserPasswordUpdate(&req, nRequestID);
}

int32_t TraderApi::ReqInputDeviceSerial(ReqInputDeviceSerialField pReqInputDeviceSerialField, int32_t nRequestID) const {
    CTORATstpReqInputDeviceSerialField req(Converter::ReqInputDeviceSerialFieldToCpp(pReqInputDeviceSerialField));
    return api->ReqInputDeviceSerial(&req, nRequestID);
}

int32_t TraderApi::ReqOrderInsert(InputOrderField pInputOrderField, int32_t nRequestID) const {
    CTORATstpInputOrderField req(Converter::InputOrderFieldToCpp(pInputOrderField));
    return api->ReqOrderInsert(&req, nRequestID);
}

int32_t TraderApi::ReqPublicOfferedFundOrderInsert(InputOrderField pInputOrderField, int32_t nRequestID) const {
    CTORATstpInputOrderField req(Converter::InputOrderFieldToCpp(pInputOrderField));
    return api->ReqPublicOfferedFundOrderInsert(&req, nRequestID);
}

int32_t TraderApi::ReqOrderAction(InputOrderActionField pInputOrderActionField, int32_t nRequestID) const {
    CTORATstpInputOrderActionField req(Converter::InputOrderActionFieldToCpp(pInputOrderActionField));
    return api->ReqOrderAction(&req, nRequestID);
}

int32_t TraderApi::ReqCondOrderInsert(InputCondOrderField pInputCondOrderField, int32_t nRequestID) const {
    CTORATstpInputCondOrderField req(Converter::InputCondOrderFieldToCpp(pInputCondOrderField));
    return api->ReqCondOrderInsert(&req, nRequestID);
}

int32_t TraderApi::ReqCondOrderAction(InputCondOrderActionField pInputCondOrderActionField, int32_t nRequestID) const {
    CTORATstpInputCondOrderActionField req(Converter::InputCondOrderActionFieldToCpp(pInputCondOrderActionField));
    return api->ReqCondOrderAction(&req, nRequestID);
}

int32_t TraderApi::ReqNegoOrderInsert(InputNegoOrderField pInputNegoOrderField, int32_t nRequestID) const {
    CTORATstpInputNegoOrderField req(Converter::InputNegoOrderFieldToCpp(pInputNegoOrderField));
    return api->ReqNegoOrderInsert(&req, nRequestID);
}

int32_t TraderApi::ReqNegoOrderAction(InputNegoOrderActionField pInputNegoOrderActionField, int32_t nRequestID) const {
    CTORATstpInputNegoOrderActionField req(Converter::InputNegoOrderActionFieldToCpp(pInputNegoOrderActionField));
    return api->ReqNegoOrderAction(&req, nRequestID);
}

int32_t TraderApi::ReqOrderInsertEx(InputOrderExField pInputOrderExField, int32_t nRequestID) const {
    CTORATstpInputOrderExField req(Converter::InputOrderExFieldToCpp(pInputOrderExField));
    return api->ReqOrderInsertEx(&req, nRequestID);
}

int32_t TraderApi::ReqOrderActionEx(InputOrderActionExField pInputOrderActionExField, int32_t nRequestID) const {
    CTORATstpInputOrderActionExField req(Converter::InputOrderActionExFieldToCpp(pInputOrderActionExField));
    return api->ReqOrderActionEx(&req, nRequestID);
}

int32_t TraderApi::ReqTransferFund(InputTransferFundField pInputTransferFundField, int32_t nRequestID) const {
    CTORATstpInputTransferFundField req(Converter::InputTransferFundFieldToCpp(pInputTransferFundField));
    return api->ReqTransferFund(&req, nRequestID);
}

int32_t TraderApi::ReqTransferPosition(InputTransferPositionField pInputTransferPositionField, int32_t nRequestID) const {
    CTORATstpInputTransferPositionField req(Converter::InputTransferPositionFieldToCpp(pInputTransferPositionField));
    return api->ReqTransferPosition(&req, nRequestID);
}

int32_t TraderApi::ReqInquiryJZFund(ReqInquiryJZFundField pReqInquiryJZFundField, int32_t nRequestID) const {
    CTORATstpReqInquiryJZFundField req(Converter::ReqInquiryJZFundFieldToCpp(pReqInquiryJZFundField));
    return api->ReqInquiryJZFund(&req, nRequestID);
}

int32_t TraderApi::ReqInquiryBankAccountFund(ReqInquiryBankAccountFundField pReqInquiryBankAccountFundField, int32_t nRequestID) const {
    CTORATstpReqInquiryBankAccountFundField req(Converter::ReqInquiryBankAccountFundFieldToCpp(pReqInquiryBankAccountFundField));
    return api->ReqInquiryBankAccountFund(&req, nRequestID);
}

int32_t TraderApi::ReqInquiryMaxOrderVolume(ReqInquiryMaxOrderVolumeField pReqInquiryMaxOrderVolumeField, int32_t nRequestID) const {
    CTORATstpReqInquiryMaxOrderVolumeField req(Converter::ReqInquiryMaxOrderVolumeFieldToCpp(pReqInquiryMaxOrderVolumeField));
    return api->ReqInquiryMaxOrderVolume(&req, nRequestID);
}

int32_t TraderApi::ReqInquiryTradeConcentration(InquiryTradeConcentrationField pInquiryTradeConcentrationField, int32_t nRequestID) const {
    CTORATstpInquiryTradeConcentrationField req(Converter::InquiryTradeConcentrationFieldToCpp(pInquiryTradeConcentrationField));
    return api->ReqInquiryTradeConcentration(&req, nRequestID);
}

int32_t TraderApi::ReqModifyOpenPosCost(ReqModifyOpenPosCostField pReqModifyOpenPosCostField, int32_t nRequestID) const {
    CTORATstpReqModifyOpenPosCostField req(Converter::ReqModifyOpenPosCostFieldToCpp(pReqModifyOpenPosCostField));
    return api->ReqModifyOpenPosCost(&req, nRequestID);
}

int32_t TraderApi::ReqInputNodeFundAssignment(InputNodeFundAssignmentField pInputNodeFundAssignmentField, int32_t nRequestID) const {
    CTORATstpInputNodeFundAssignmentField req(Converter::InputNodeFundAssignmentFieldToCpp(pInputNodeFundAssignmentField));
    return api->ReqInputNodeFundAssignment(&req, nRequestID);
}

int32_t TraderApi::ReqInquiryNodeFundAssignment(ReqInquiryNodeFundAssignmentField pReqInquiryNodeFundAssignmentField, int32_t nRequestID) const {
    CTORATstpReqInquiryNodeFundAssignmentField req(Converter::ReqInquiryNodeFundAssignmentFieldToCpp(pReqInquiryNodeFundAssignmentField));
    return api->ReqInquiryNodeFundAssignment(&req, nRequestID);
}

int32_t TraderApi::ReqQryExchange(QryExchangeField pQryExchangeField, int32_t nRequestID) const {
    CTORATstpQryExchangeField req(Converter::QryExchangeFieldToCpp(pQryExchangeField));
    return api->ReqQryExchange(&req, nRequestID);
}

int32_t TraderApi::ReqQrySecurity(QrySecurityField pQrySecurityField, int32_t nRequestID) const {
    CTORATstpQrySecurityField req(Converter::QrySecurityFieldToCpp(pQrySecurityField));
    return api->ReqQrySecurity(&req, nRequestID);
}

int32_t TraderApi::ReqQryIPOInfo(QryIPOInfoField pQryIPOInfoField, int32_t nRequestID) const {
    CTORATstpQryIPOInfoField req(Converter::QryIPOInfoFieldToCpp(pQryIPOInfoField));
    return api->ReqQryIPOInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryUser(QryUserField pQryUserField, int32_t nRequestID) const {
    CTORATstpQryUserField req(Converter::QryUserFieldToCpp(pQryUserField));
    return api->ReqQryUser(&req, nRequestID);
}

int32_t TraderApi::ReqQryInvestor(QryInvestorField pQryInvestorField, int32_t nRequestID) const {
    CTORATstpQryInvestorField req(Converter::QryInvestorFieldToCpp(pQryInvestorField));
    return api->ReqQryInvestor(&req, nRequestID);
}

int32_t TraderApi::ReqQryShareholderAccount(QryShareholderAccountField pQryShareholderAccountField, int32_t nRequestID) const {
    CTORATstpQryShareholderAccountField req(Converter::QryShareholderAccountFieldToCpp(pQryShareholderAccountField));
    return api->ReqQryShareholderAccount(&req, nRequestID);
}

int32_t TraderApi::ReqQryRationalInfo(QryRationalInfoField pQryRationalInfoField, int32_t nRequestID) const {
    CTORATstpQryRationalInfoField req(Converter::QryRationalInfoFieldToCpp(pQryRationalInfoField));
    return api->ReqQryRationalInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryOrder(QryOrderField pQryOrderField, int32_t nRequestID) const {
    CTORATstpQryOrderField req(Converter::QryOrderFieldToCpp(pQryOrderField));
    return api->ReqQryOrder(&req, nRequestID);
}

int32_t TraderApi::ReqQryOrderAction(QryOrderActionField pQryOrderActionField, int32_t nRequestID) const {
    CTORATstpQryOrderActionField req(Converter::QryOrderActionFieldToCpp(pQryOrderActionField));
    return api->ReqQryOrderAction(&req, nRequestID);
}

int32_t TraderApi::ReqQryTrade(QryTradeField pQryTradeField, int32_t nRequestID) const {
    CTORATstpQryTradeField req(Converter::QryTradeFieldToCpp(pQryTradeField));
    return api->ReqQryTrade(&req, nRequestID);
}

int32_t TraderApi::ReqQryTradingAccount(QryTradingAccountField pQryTradingAccountField, int32_t nRequestID) const {
    CTORATstpQryTradingAccountField req(Converter::QryTradingAccountFieldToCpp(pQryTradingAccountField));
    return api->ReqQryTradingAccount(&req, nRequestID);
}

int32_t TraderApi::ReqQryPosition(QryPositionField pQryPositionField, int32_t nRequestID) const {
    CTORATstpQryPositionField req(Converter::QryPositionFieldToCpp(pQryPositionField));
    return api->ReqQryPosition(&req, nRequestID);
}

int32_t TraderApi::ReqQryTradingFee(QryTradingFeeField pQryTradingFeeField, int32_t nRequestID) const {
    CTORATstpQryTradingFeeField req(Converter::QryTradingFeeFieldToCpp(pQryTradingFeeField));
    return api->ReqQryTradingFee(&req, nRequestID);
}

int32_t TraderApi::ReqQryInvestorTradingFee(QryInvestorTradingFeeField pQryInvestorTradingFeeField, int32_t nRequestID) const {
    CTORATstpQryInvestorTradingFeeField req(Converter::QryInvestorTradingFeeFieldToCpp(pQryInvestorTradingFeeField));
    return api->ReqQryInvestorTradingFee(&req, nRequestID);
}

int32_t TraderApi::ReqQryIPOQuota(QryIPOQuotaField pQryIPOQuotaField, int32_t nRequestID) const {
    CTORATstpQryIPOQuotaField req(Converter::QryIPOQuotaFieldToCpp(pQryIPOQuotaField));
    return api->ReqQryIPOQuota(&req, nRequestID);
}

int32_t TraderApi::ReqQryOrderFundDetail(QryOrderFundDetailField pQryOrderFundDetailField, int32_t nRequestID) const {
    CTORATstpQryOrderFundDetailField req(Converter::QryOrderFundDetailFieldToCpp(pQryOrderFundDetailField));
    return api->ReqQryOrderFundDetail(&req, nRequestID);
}

int32_t TraderApi::ReqQryFundTransferDetail(QryFundTransferDetailField pQryFundTransferDetailField, int32_t nRequestID) const {
    CTORATstpQryFundTransferDetailField req(Converter::QryFundTransferDetailFieldToCpp(pQryFundTransferDetailField));
    return api->ReqQryFundTransferDetail(&req, nRequestID);
}

int32_t TraderApi::ReqQryPositionTransferDetail(QryPositionTransferDetailField pQryPositionTransferDetailField, int32_t nRequestID) const {
    CTORATstpQryPositionTransferDetailField req(Converter::QryPositionTransferDetailFieldToCpp(pQryPositionTransferDetailField));
    return api->ReqQryPositionTransferDetail(&req, nRequestID);
}

int32_t TraderApi::ReqQryPeripheryPositionTransferDetail(QryPeripheryPositionTransferDetailField pQryPeripheryPositionTransferDetailField, int32_t nRequestID) const {
    CTORATstpQryPeripheryPositionTransferDetailField req(Converter::QryPeripheryPositionTransferDetailFieldToCpp(pQryPeripheryPositionTransferDetailField));
    return api->ReqQryPeripheryPositionTransferDetail(&req, nRequestID);
}

int32_t TraderApi::ReqQryPeripheryFundTransferDetail(QryPeripheryFundTransferDetailField pQryPeripheryFundTransferDetailField, int32_t nRequestID) const {
    CTORATstpQryPeripheryFundTransferDetailField req(Converter::QryPeripheryFundTransferDetailFieldToCpp(pQryPeripheryFundTransferDetailField));
    return api->ReqQryPeripheryFundTransferDetail(&req, nRequestID);
}

int32_t TraderApi::ReqQryBondConversionInfo(QryBondConversionInfoField pQryBondConversionInfoField, int32_t nRequestID) const {
    CTORATstpQryBondConversionInfoField req(Converter::QryBondConversionInfoFieldToCpp(pQryBondConversionInfoField));
    return api->ReqQryBondConversionInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryBondPutbackInfo(QryBondPutbackInfoField pQryBondPutbackInfoField, int32_t nRequestID) const {
    CTORATstpQryBondPutbackInfoField req(Converter::QryBondPutbackInfoFieldToCpp(pQryBondPutbackInfoField));
    return api->ReqQryBondPutbackInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryInvestorCondOrderLimitParam(QryInvestorCondOrderLimitParamField pQryInvestorCondOrderLimitParamField, int32_t nRequestID) const {
    CTORATstpQryInvestorCondOrderLimitParamField req(Converter::QryInvestorCondOrderLimitParamFieldToCpp(pQryInvestorCondOrderLimitParamField));
    return api->ReqQryInvestorCondOrderLimitParam(&req, nRequestID);
}

int32_t TraderApi::ReqQryConditionOrder(QryConditionOrderField pQryConditionOrderField, int32_t nRequestID) const {
    CTORATstpQryConditionOrderField req(Converter::QryConditionOrderFieldToCpp(pQryConditionOrderField));
    return api->ReqQryConditionOrder(&req, nRequestID);
}

int32_t TraderApi::ReqQryCondOrderAction(QryCondOrderActionField pQryCondOrderActionField, int32_t nRequestID) const {
    CTORATstpQryCondOrderActionField req(Converter::QryCondOrderActionFieldToCpp(pQryCondOrderActionField));
    return api->ReqQryCondOrderAction(&req, nRequestID);
}

int32_t TraderApi::ReqQryTradingNotice(QryTradingNoticeField pQryTradingNoticeField, int32_t nRequestID) const {
    CTORATstpQryTradingNoticeField req(Converter::QryTradingNoticeFieldToCpp(pQryTradingNoticeField));
    return api->ReqQryTradingNotice(&req, nRequestID);
}

int32_t TraderApi::ReqQryIPONumberResult(QryIPONumberResultField pQryIPONumberResultField, int32_t nRequestID) const {
    CTORATstpQryIPONumberResultField req(Converter::QryIPONumberResultFieldToCpp(pQryIPONumberResultField));
    return api->ReqQryIPONumberResult(&req, nRequestID);
}

int32_t TraderApi::ReqQryIPOMatchNumberResult(QryIPOMatchNumberResultField pQryIPOMatchNumberResultField, int32_t nRequestID) const {
    CTORATstpQryIPOMatchNumberResultField req(Converter::QryIPOMatchNumberResultFieldToCpp(pQryIPOMatchNumberResultField));
    return api->ReqQryIPOMatchNumberResult(&req, nRequestID);
}

int32_t TraderApi::ReqQryShareholderSpecPrivilege(QryShareholderSpecPrivilegeField pQryShareholderSpecPrivilegeField, int32_t nRequestID) const {
    CTORATstpQryShareholderSpecPrivilegeField req(Converter::QryShareholderSpecPrivilegeFieldToCpp(pQryShareholderSpecPrivilegeField));
    return api->ReqQryShareholderSpecPrivilege(&req, nRequestID);
}

int32_t TraderApi::ReqQryMarket(QryMarketField pQryMarketField, int32_t nRequestID) const {
    CTORATstpQryMarketField req(Converter::QryMarketFieldToCpp(pQryMarketField));
    return api->ReqQryMarket(&req, nRequestID);
}

int32_t TraderApi::ReqQryETFFile(QryETFFileField pQryETFFileField, int32_t nRequestID) const {
    CTORATstpQryETFFileField req(Converter::QryETFFileFieldToCpp(pQryETFFileField));
    return api->ReqQryETFFile(&req, nRequestID);
}

int32_t TraderApi::ReqQryETFBasket(QryETFBasketField pQryETFBasketField, int32_t nRequestID) const {
    CTORATstpQryETFBasketField req(Converter::QryETFBasketFieldToCpp(pQryETFBasketField));
    return api->ReqQryETFBasket(&req, nRequestID);
}

int32_t TraderApi::ReqQryInvestorPositionLimit(QryInvestorPositionLimitField pQryInvestorPositionLimitField, int32_t nRequestID) const {
    CTORATstpQryInvestorPositionLimitField req(Converter::QryInvestorPositionLimitFieldToCpp(pQryInvestorPositionLimitField));
    return api->ReqQryInvestorPositionLimit(&req, nRequestID);
}

int32_t TraderApi::ReqQryImcParams(QryImcParamsField pQryImcParamsField, int32_t nRequestID) const {
    CTORATstpQryImcParamsField req(Converter::QryImcParamsFieldToCpp(pQryImcParamsField));
    return api->ReqQryImcParams(&req, nRequestID);
}

int32_t TraderApi::ReqQryImcExchangeRate(QryImcExchangeRateField pQryImcExchangeRateField, int32_t nRequestID) const {
    CTORATstpQryImcExchangeRateField req(Converter::QryImcExchangeRateFieldToCpp(pQryImcExchangeRateField));
    return api->ReqQryImcExchangeRate(&req, nRequestID);
}

int32_t TraderApi::ReqQryHKPriceTickInfo(QryHKPriceTickInfoField pQryHKPriceTickInfoField, int32_t nRequestID) const {
    CTORATstpQryHKPriceTickInfoField req(Converter::QryHKPriceTickInfoFieldToCpp(pQryHKPriceTickInfoField));
    return api->ReqQryHKPriceTickInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryLofFundInfo(QryLofFundInfoField pQryLofFundInfoField, int32_t nRequestID) const {
    CTORATstpQryLofFundInfoField req(Converter::QryLofFundInfoFieldToCpp(pQryLofFundInfoField));
    return api->ReqQryLofFundInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryPledgePosition(QryPledgePositionField pQryPledgePositionField, int32_t nRequestID) const {
    CTORATstpQryPledgePositionField req(Converter::QryPledgePositionFieldToCpp(pQryPledgePositionField));
    return api->ReqQryPledgePosition(&req, nRequestID);
}

int32_t TraderApi::ReqQryPledgeInfo(QryPledgeInfoField pQryPledgeInfoField, int32_t nRequestID) const {
    CTORATstpQryPledgeInfoField req(Converter::QryPledgeInfoFieldToCpp(pQryPledgeInfoField));
    return api->ReqQryPledgeInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQrySystemNodeInfo(QrySystemNodeInfoField pQrySystemNodeInfoField, int32_t nRequestID) const {
    CTORATstpQrySystemNodeInfoField req(Converter::QrySystemNodeInfoFieldToCpp(pQrySystemNodeInfoField));
    return api->ReqQrySystemNodeInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryStandardBondPosition(QryStandardBondPositionField pQryStandardBondPositionField, int32_t nRequestID) const {
    CTORATstpQryStandardBondPositionField req(Converter::QryStandardBondPositionFieldToCpp(pQryStandardBondPositionField));
    return api->ReqQryStandardBondPosition(&req, nRequestID);
}

int32_t TraderApi::ReqQryPrematurityRepoOrder(QryPrematurityRepoOrderField pQryPrematurityRepoOrderField, int32_t nRequestID) const {
    CTORATstpQryPrematurityRepoOrderField req(Converter::QryPrematurityRepoOrderFieldToCpp(pQryPrematurityRepoOrderField));
    return api->ReqQryPrematurityRepoOrder(&req, nRequestID);
}

int32_t TraderApi::ReqQryNegoOrder(QryNegoOrderField pQryNegoOrderField, int32_t nRequestID) const {
    CTORATstpQryNegoOrderField req(Converter::QryNegoOrderFieldToCpp(pQryNegoOrderField));
    return api->ReqQryNegoOrder(&req, nRequestID);
}

int32_t TraderApi::ReqQryNegoOrderAction(QryNegoOrderActionField pQryNegoOrderActionField, int32_t nRequestID) const {
    CTORATstpQryNegoOrderActionField req(Converter::QryNegoOrderActionFieldToCpp(pQryNegoOrderActionField));
    return api->ReqQryNegoOrderAction(&req, nRequestID);
}

int32_t TraderApi::ReqQryNegoTrade(QryNegoTradeField pQryNegoTradeField, int32_t nRequestID) const {
    CTORATstpQryNegoTradeField req(Converter::QryNegoTradeFieldToCpp(pQryNegoTradeField));
    return api->ReqQryNegoTrade(&req, nRequestID);
}

int32_t TraderApi::ReqQryNegotiationParam(QryNegotiationParamField pQryNegotiationParamField, int32_t nRequestID) const {
    CTORATstpQryNegotiationParamField req(Converter::QryNegotiationParamFieldToCpp(pQryNegotiationParamField));
    return api->ReqQryNegotiationParam(&req, nRequestID);
}

int32_t TraderApi::ReqQryPublicOfferedFundInfo(QryPublicOfferedFundInfoField pQryPublicOfferedFundInfoField, int32_t nRequestID) const {
    CTORATstpQryPublicOfferedFundInfoField req(Converter::QryPublicOfferedFundInfoFieldToCpp(pQryPublicOfferedFundInfoField));
    return api->ReqQryPublicOfferedFundInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryPublicOfferedFundTradeDetail(QryPublicOfferedFundTradeDetailField pQryPublicOfferedFundTradeDetailField, int32_t nRequestID) const {
    CTORATstpQryPublicOfferedFundTradeDetailField req(Converter::QryPublicOfferedFundTradeDetailFieldToCpp(pQryPublicOfferedFundTradeDetailField));
    return api->ReqQryPublicOfferedFundTradeDetail(&req, nRequestID);
}

int32_t TraderApi::ReqQryTenderInfo(QryTenderInfoField pQryTenderInfoField, int32_t nRequestID) const {
    CTORATstpQryTenderInfoField req(Converter::QryTenderInfoFieldToCpp(pQryTenderInfoField));
    return api->ReqQryTenderInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryAdditionalOfferingInfo(QryAdditionalOfferingInfoField pQryAdditionalOfferingInfoField, int32_t nRequestID) const {
    CTORATstpQryAdditionalOfferingInfoField req(Converter::QryAdditionalOfferingInfoFieldToCpp(pQryAdditionalOfferingInfoField));
    return api->ReqQryAdditionalOfferingInfo(&req, nRequestID);
}

int32_t TraderApi::ReqQryAdditionalOfferingQuota(QryAdditionalOfferingQuotaField pQryAdditionalOfferingQuotaField, int32_t nRequestID) const {
    CTORATstpQryAdditionalOfferingQuotaField req(Converter::QryAdditionalOfferingQuotaFieldToCpp(pQryAdditionalOfferingQuotaField));
    return api->ReqQryAdditionalOfferingQuota(&req, nRequestID);
}

int32_t TraderApi::ReqForceUserExit(ForceUserLogoutField pForceUserLogoutField, int32_t nRequestID) const {
    CTORATstpForceUserLogoutField req(Converter::ForceUserLogoutFieldToCpp(pForceUserLogoutField));
    return api->ReqForceUserExit(&req, nRequestID);
}

int32_t TraderApi::ReqForceUserLogout(ForceUserLogoutField pForceUserLogoutField, int32_t nRequestID) const {
    CTORATstpForceUserLogoutField req(Converter::ForceUserLogoutFieldToCpp(pForceUserLogoutField));
    return api->ReqForceUserLogout(&req, nRequestID);
}

int32_t TraderApi::ReqActivateUser(ActivateUserField pActivateUserField, int32_t nRequestID) const {
    CTORATstpActivateUserField req(Converter::ActivateUserFieldToCpp(pActivateUserField));
    return api->ReqActivateUser(&req, nRequestID);
}

} // namespace tora_trader
