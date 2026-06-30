#include "tora-rs/wrapper/include/XMdApi.h"
#include "tora-rs/wrapper/include/XMdConverter.h"

namespace tora_xmd {
using namespace TORALEV1API;

XMdApi::XMdApi(rust::Box<XMdSpi> gateway, uint8_t md_sub_mode, uint8_t derive_md_sub_mode) {
    spi = new CXMdSpi(std::move(gateway));
    api = CTORATstpXMdApi::CreateTstpXMdApi(md_sub_mode, derive_md_sub_mode);
    api->RegisterSpi(spi);
}

XMdApi::~XMdApi() {
    if (api) {
        api->Release();
        api = nullptr;
    }
    delete spi;
    spi = nullptr;
}

std::unique_ptr<XMdApi> CreateXMdApi(rust::Box<XMdSpi> gateway, uint8_t md_sub_mode, uint8_t derive_md_sub_mode) {
    return std::make_unique<XMdApi>(std::move(gateway), md_sub_mode, derive_md_sub_mode);
}

rust::String XMdApi::GetApiVersion() const {
    return api->GetApiVersion();
}

void XMdApi::Init(rust::String cpuCores) const {
    api->Init(const_cast<char *>(cpuCores.c_str()));
}

int32_t XMdApi::Join() const {
    return api->Join();
}

void XMdApi::RegisterFront(rust::String pszFrontAddress) const {
    api->RegisterFront(const_cast<char *>(pszFrontAddress.c_str()));
}

void XMdApi::RegisterNameServer(rust::String pszNsAddress) const {
    api->RegisterNameServer(const_cast<char *>(pszNsAddress.c_str()));
}

void XMdApi::RegisterFensUserInfo(FensUserInfoField pFensUserInfoField) const {
    CTORATstpFensUserInfoField req(Converter::FensUserInfoFieldToCpp(pFensUserInfoField));
    api->RegisterFensUserInfo(&req);
}

void XMdApi::RegisterMulticast(rust::String pszMulticastAddress, rust::String pszInterfaceIP, rust::String pszSourceIp) const {
    api->RegisterMulticast(const_cast<char *>(pszMulticastAddress.c_str()), const_cast<char *>(pszInterfaceIP.c_str()), const_cast<char *>(pszSourceIp.c_str()));
}

void XMdApi::RegisterDeriveServer(rust::String pszDeriveAddress) const {
    api->RegisterDeriveServer(const_cast<char *>(pszDeriveAddress.c_str()));
}

void XMdApi::RegisterDeriveMulticast(rust::String pszMulticastAddress, rust::String pszInterfaceIP, rust::String pszSourceIp) const {
    api->RegisterDeriveMulticast(const_cast<char *>(pszMulticastAddress.c_str()), const_cast<char *>(pszInterfaceIP.c_str()), const_cast<char *>(pszSourceIp.c_str()));
}

int32_t XMdApi::ReqGetConnectionInfo(int32_t nRequestID) const {
    return api->ReqGetConnectionInfo(nRequestID);
}

int32_t XMdApi::ReqUserLogin(ReqUserLoginField pReqUserLoginField, int32_t nRequestID) const {
    CTORATstpReqUserLoginField req(Converter::ReqUserLoginFieldToCpp(pReqUserLoginField));
    return api->ReqUserLogin(&req, nRequestID);
}

int32_t XMdApi::ReqUserLogout(UserLogoutField pUserLogoutField, int32_t nRequestID) const {
    CTORATstpUserLogoutField req(Converter::UserLogoutFieldToCpp(pUserLogoutField));
    return api->ReqUserLogout(&req, nRequestID);
}

int32_t XMdApi::SubscribeMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribeMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::SubscribePHMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribePHMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribePHMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribePHMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::SubscribeSpecialMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeSpecialMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribeSpecialMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeSpecialMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::SubscribeSimplifyMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeSimplifyMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribeSimplifyMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeSimplifyMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::SubscribeIOPV(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeIOPV(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribeIOPV(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeIOPV(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::SubscribeSecurityStatus(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeSecurityStatus(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribeSecurityStatus(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeSecurityStatus(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::SubscribeMarketStatus(uint8_t MarketID) const {
    return api->SubscribeMarketStatus(MarketID);
}

int32_t XMdApi::UnSubscribeMarketStatus(uint8_t MarketID) const {
    return api->UnSubscribeMarketStatus(MarketID);
}

int32_t XMdApi::SubscribeImcParams(uint8_t MarketID) const {
    return api->SubscribeImcParams(MarketID);
}

int32_t XMdApi::UnSubscribeImcParams(uint8_t MarketID) const {
    return api->UnSubscribeImcParams(MarketID);
}

int32_t XMdApi::ReqInquiryMarketDataMirror(InquiryMarketDataField pInquiryMarketDataField, int32_t nRequestID) const {
    CTORATstpInquiryMarketDataField req(Converter::InquiryMarketDataFieldToCpp(pInquiryMarketDataField));
    return api->ReqInquiryMarketDataMirror(&req, nRequestID);
}

int32_t XMdApi::ReqInquiryPHMarketDataMirror(InquiryMarketDataField pInquiryMarketDataField, int32_t nRequestID) const {
    CTORATstpInquiryMarketDataField req(Converter::InquiryMarketDataFieldToCpp(pInquiryMarketDataField));
    return api->ReqInquiryPHMarketDataMirror(&req, nRequestID);
}

int32_t XMdApi::ReqInquirySpecialMarketDataMirror(InquirySpecialMarketDataField pInquirySpecialMarketDataField, int32_t nRequestID) const {
    CTORATstpInquirySpecialMarketDataField req(Converter::InquirySpecialMarketDataFieldToCpp(pInquirySpecialMarketDataField));
    return api->ReqInquirySpecialMarketDataMirror(&req, nRequestID);
}

int32_t XMdApi::SubscribeSPMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeSPMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribeSPMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeSPMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::SubscribeSPSimplifyMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeSPSimplifyMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribeSPSimplifyMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeSPSimplifyMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::SubscribeSPSecurityStatus(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeSPSecurityStatus(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribeSPSecurityStatus(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeSPSecurityStatus(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::SubscribeSPMarketStatus(uint8_t MarketID) const {
    return api->SubscribeSPMarketStatus(MarketID);
}

int32_t XMdApi::UnSubscribeSPMarketStatus(uint8_t MarketID) const {
    return api->UnSubscribeSPMarketStatus(MarketID);
}

int32_t XMdApi::ReqInquirySPMarketDataMirror(InquiryMarketDataField pInquiryMarketDataField, int32_t nRequestID) const {
    CTORATstpInquiryMarketDataField req(Converter::InquiryMarketDataFieldToCpp(pInquiryMarketDataField));
    return api->ReqInquirySPMarketDataMirror(&req, nRequestID);
}

int32_t XMdApi::SubscribeRapidMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeRapidMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t XMdApi::UnSubscribeRapidMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeRapidMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchangeID);
    delete[] ppSecurityID_raw;
    return ret;
}

} // namespace tora_xmd
