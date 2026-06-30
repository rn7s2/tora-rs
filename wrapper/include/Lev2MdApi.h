#pragma once

namespace tora_lev2md {
struct FensUserInfoField;
struct ReqUserLoginField;
struct RspUserLoginField;
struct RspInfoField;
struct UserLogoutField;
struct SpecificSecurityField;
struct Lev2MarketDataField;
struct Lev2IndexField;
struct Lev2TransactionField;
struct Lev2OrderDetailField;
struct Lev2PHMarketDataField;
struct Lev2PHTransactionField;
struct Lev2ResendTransactionField;
struct Lev2ResendOrderDetailField;
struct Lev2XTSMarketDataField;
struct Lev2XTSTickField;
struct Lev2NGTSTickField;
struct Lev2BondMarketDataField;
struct Lev2BondOrderDetailField;
struct Lev2BondTransactionField;
struct Lev2IOPVField;
struct ExIndexField;
struct Lev2MdApi;
struct Lev2MdSpi;
class CLev2MdSpi;
}

#include "tora-rs/src/lev2md.rs.h"
#include "tora-rs/wrapper/include/CLev2MdSpi.h"
#include "TORATstpLev2MdApi.h"
#include "rust/cxx.h"
#include <cstdint>
#include <memory>

namespace tora_lev2md {
using namespace TORALEV2API;

struct Lev2MdApi {
    Lev2MdApi(rust::Box<Lev2MdSpi> gateway, uint8_t md_sub_mode, bool cached_mode);
    ~Lev2MdApi();
    rust::String GetApiVersion() const;
    void Init(rust::String cpuCores) const;
    int32_t Join() const;
    void RegisterFront(rust::String pszFrontAddress) const;
    void RegisterNameServer(rust::String pszNsAddress) const;
    void RegisterMulticast(rust::String pszMulticastAddress, rust::String pszInterfaceIP, rust::String pszSourceIp, rust::String pInterfaceName, int32_t rxqCapacity, bool bEFVI) const;
    int32_t SubscribeMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeIndex(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeIndex(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribePHMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribePHMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribePHTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribePHTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeResendTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeResendTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeResendOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeResendOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeXTSMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeXTSMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeXTSTick(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeXTSTick(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeNGTSTick(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeNGTSTick(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeBondMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeBondMarketData(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeBondTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeBondTransaction(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeBondOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeBondOrderDetail(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t SubscribeIOPV(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t UnSubscribeIOPV(rust::Vec<rust::String> ppSecurityID, uint8_t ExchageID) const;
    int32_t ReqUserLogin(ReqUserLoginField pReqUserLoginField, int32_t nRequestID) const;
    int32_t ReqUserLogout(UserLogoutField pUserLogout, int32_t nRequestID) const;

    CTORATstpLev2MdApi *api;
    CLev2MdSpi *spi;
};

std::unique_ptr<Lev2MdApi> CreateLev2MdApi(rust::Box<Lev2MdSpi> gateway, uint8_t md_sub_mode, bool cached_mode);
} // namespace tora_lev2md
