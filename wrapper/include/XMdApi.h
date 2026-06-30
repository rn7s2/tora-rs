#pragma once

namespace tora_xmd {
struct ReqUserLoginField;
struct RspUserLoginField;
struct RspInfoField;
struct UserLogoutField;
struct SpecificSecurityField;
struct SpecificMarketField;
struct InquiryMarketDataField;
struct MarketDataField;
struct QryRspInfoField;
struct PHMarketDataField;
struct InquirySpecialMarketDataField;
struct SpecialMarketDataField;
struct SimplifyMarketDataField;
struct SecurityStatusField;
struct MarketStatusField;
struct ImcParamsField;
struct IOPVField;
struct RapidMarketDataField;
struct FensUserInfoField;
struct ConnectionInfoField;
struct XMdApi;
struct XMdSpi;
class CXMdSpi;
}

#include "tora-rs/src/xmd.rs.h"
#include "tora-rs/wrapper/include/CXMdSpi.h"
#include "TORATstpXMdApi.h"
#include "rust/cxx.h"
#include <cstdint>
#include <memory>

namespace tora_xmd {
using namespace TORALEV1API;

struct XMdApi {
    XMdApi(rust::Box<XMdSpi> gateway, uint8_t md_sub_mode, uint8_t derive_md_sub_mode);
    ~XMdApi();
    rust::String GetApiVersion() const;
    void Init(rust::String cpuCores) const;
    int32_t Join() const;
    void RegisterFront(rust::String pszFrontAddress) const;
    void RegisterNameServer(rust::String pszNsAddress) const;
    void RegisterFensUserInfo(FensUserInfoField pFensUserInfoField) const;
    void RegisterMulticast(rust::String pszMulticastAddress, rust::String pszInterfaceIP, rust::String pszSourceIp) const;
    void RegisterDeriveServer(rust::String pszDeriveAddress) const;
    void RegisterDeriveMulticast(rust::String pszMulticastAddress, rust::String pszInterfaceIP, rust::String pszSourceIp) const;
    int32_t ReqGetConnectionInfo(int32_t nRequestID) const;
    int32_t ReqUserLogin(ReqUserLoginField pReqUserLoginField, int32_t nRequestID) const;
    int32_t ReqUserLogout(UserLogoutField pUserLogoutField, int32_t nRequestID) const;
    int32_t SubscribeMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribeMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t SubscribePHMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribePHMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t SubscribeSpecialMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribeSpecialMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t SubscribeSimplifyMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribeSimplifyMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t SubscribeIOPV(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribeIOPV(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t SubscribeSecurityStatus(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribeSecurityStatus(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t SubscribeMarketStatus(uint8_t MarketID) const;
    int32_t UnSubscribeMarketStatus(uint8_t MarketID) const;
    int32_t SubscribeImcParams(uint8_t MarketID) const;
    int32_t UnSubscribeImcParams(uint8_t MarketID) const;
    int32_t ReqInquiryMarketDataMirror(InquiryMarketDataField pInquiryMarketDataField, int32_t nRequestID) const;
    int32_t ReqInquiryPHMarketDataMirror(InquiryMarketDataField pInquiryMarketDataField, int32_t nRequestID) const;
    int32_t ReqInquirySpecialMarketDataMirror(InquirySpecialMarketDataField pInquirySpecialMarketDataField, int32_t nRequestID) const;
    int32_t SubscribeSPMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribeSPMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t SubscribeSPSimplifyMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribeSPSimplifyMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t SubscribeSPSecurityStatus(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribeSPSecurityStatus(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t SubscribeSPMarketStatus(uint8_t MarketID) const;
    int32_t UnSubscribeSPMarketStatus(uint8_t MarketID) const;
    int32_t ReqInquirySPMarketDataMirror(InquiryMarketDataField pInquiryMarketDataField, int32_t nRequestID) const;
    int32_t SubscribeRapidMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;
    int32_t UnSubscribeRapidMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchangeID) const;

    CTORATstpXMdApi *api;
    CXMdSpi *spi;
};

std::unique_ptr<XMdApi> CreateXMdApi(rust::Box<XMdSpi> gateway, uint8_t md_sub_mode, uint8_t derive_md_sub_mode);
} // namespace tora_xmd
