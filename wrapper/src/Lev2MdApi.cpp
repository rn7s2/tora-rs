#include "tora-rs/wrapper/include/Lev2MdApi.h"
#include "tora-rs/wrapper/include/Lev2MdConverter.h"

namespace tora_lev2md {
using namespace TORALEV2API;

Lev2MdApi::Lev2MdApi(rust::Box<Lev2MdSpi> gateway, uint8_t md_sub_mode, bool cached_mode) {
    spi = new CLev2MdSpi(std::move(gateway));
    api = CTORATstpLev2MdApi::CreateTstpLev2MdApi(md_sub_mode, cached_mode);
    api->RegisterSpi(spi);
}

Lev2MdApi::~Lev2MdApi() {
    if (api) {
        api->Release();
        api = nullptr;
    }
    delete spi;
    spi = nullptr;
}

std::unique_ptr<Lev2MdApi> CreateLev2MdApi(rust::Box<Lev2MdSpi> gateway, uint8_t md_sub_mode, bool cached_mode) {
    return std::make_unique<Lev2MdApi>(std::move(gateway), md_sub_mode, cached_mode);
}

rust::String Lev2MdApi::GetApiVersion() const {
    return api->GetApiVersion();
}

void Lev2MdApi::Init(rust::String cpuCores) const {
    api->Init(const_cast<char *>(cpuCores.c_str()));
}

int32_t Lev2MdApi::Join() const {
    return api->Join();
}

void Lev2MdApi::RegisterFront(rust::String pszFrontAddress) const {
    api->RegisterFront(const_cast<char *>(pszFrontAddress.c_str()));
}

void Lev2MdApi::RegisterNameServer(rust::String pszNsAddress) const {
    api->RegisterNameServer(const_cast<char *>(pszNsAddress.c_str()));
}

void Lev2MdApi::RegisterMulticast(rust::String pszMulticastAddress, rust::String pszInterfaceIP, rust::String pszSourceIp, rust::String pInterfaceName, int32_t rxqCapacity, bool bEFVI) const {
    api->RegisterMulticast(const_cast<char *>(pszMulticastAddress.c_str()), const_cast<char *>(pszInterfaceIP.c_str()), const_cast<char *>(pszSourceIp.c_str()), const_cast<char *>(pInterfaceName.c_str()), rxqCapacity, bEFVI);
}

int32_t Lev2MdApi::SubscribeMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeIndex(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeIndex(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeIndex(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeIndex(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeTransaction(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeTransaction(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeOrderDetail(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeOrderDetail(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribePHMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribePHMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribePHMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribePHMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribePHTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribePHTransaction(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribePHTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribePHTransaction(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeResendTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeResendTransaction(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeResendTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeResendTransaction(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeResendOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeResendOrderDetail(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeResendOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeResendOrderDetail(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeXTSMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeXTSMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeXTSMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeXTSMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeXTSTick(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeXTSTick(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeXTSTick(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeXTSTick(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeNGTSTick(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeNGTSTick(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeNGTSTick(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeNGTSTick(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeBondMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeBondMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeBondMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeBondMarketData(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeBondTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeBondTransaction(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeBondTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeBondTransaction(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeBondOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeBondOrderDetail(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeBondOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeBondOrderDetail(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::SubscribeIOPV(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->SubscribeIOPV(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::UnSubscribeIOPV(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const {
    char **ppSecurityID_raw = new char *[ppSecurityID.size()];
    for (std::size_t i = 0; i < ppSecurityID.size(); i++)
        ppSecurityID_raw[i] = const_cast<char *>(ppSecurityID[i].c_str());
    int ret = api->UnSubscribeIOPV(ppSecurityID_raw, static_cast<int>(ppSecurityID.size()), ExchageID);
    delete[] ppSecurityID_raw;
    return ret;
}

int32_t Lev2MdApi::ReqUserLogin(ReqUserLoginField pReqUserLoginField, int32_t nRequestID) const {
    CTORATstpReqUserLoginField req(Converter::ReqUserLoginFieldToCpp(pReqUserLoginField));
    return api->ReqUserLogin(&req, nRequestID);
}

int32_t Lev2MdApi::ReqUserLogout(UserLogoutField pUserLogout, int32_t nRequestID) const {
    CTORATstpUserLogoutField req(Converter::UserLogoutFieldToCpp(pUserLogout));
    return api->ReqUserLogout(&req, nRequestID);
}

} // namespace tora_lev2md
