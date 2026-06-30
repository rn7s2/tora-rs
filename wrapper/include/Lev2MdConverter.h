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
}

#include "tora-rs/src/lev2md.rs.h"
#include "TORATstpLev2MdApi.h"
#include "rust/cxx.h"
#include <cstring>
#include <string>

namespace tora_lev2md {
using namespace TORALEV2API;

class Converter {
public:
    static std::string GbkToUtf8(const char *src_str);
    static rust::String GbkToRustString(const char *src_str);
    static CTORATstpFensUserInfoField FensUserInfoFieldToCpp(FensUserInfoField x);
    static FensUserInfoField CTORATstpFensUserInfoFieldToRust(CTORATstpFensUserInfoField* x);
    static CTORATstpReqUserLoginField ReqUserLoginFieldToCpp(ReqUserLoginField x);
    static ReqUserLoginField CTORATstpReqUserLoginFieldToRust(CTORATstpReqUserLoginField* x);
    static CTORATstpRspUserLoginField RspUserLoginFieldToCpp(RspUserLoginField x);
    static RspUserLoginField CTORATstpRspUserLoginFieldToRust(CTORATstpRspUserLoginField* x);
    static CTORATstpRspInfoField RspInfoFieldToCpp(RspInfoField x);
    static RspInfoField CTORATstpRspInfoFieldToRust(CTORATstpRspInfoField* x);
    static CTORATstpUserLogoutField UserLogoutFieldToCpp(UserLogoutField x);
    static UserLogoutField CTORATstpUserLogoutFieldToRust(CTORATstpUserLogoutField* x);
    static CTORATstpSpecificSecurityField SpecificSecurityFieldToCpp(SpecificSecurityField x);
    static SpecificSecurityField CTORATstpSpecificSecurityFieldToRust(CTORATstpSpecificSecurityField* x);
    static CTORATstpLev2MarketDataField Lev2MarketDataFieldToCpp(Lev2MarketDataField x);
    static Lev2MarketDataField CTORATstpLev2MarketDataFieldToRust(CTORATstpLev2MarketDataField* x);
    static CTORATstpLev2IndexField Lev2IndexFieldToCpp(Lev2IndexField x);
    static Lev2IndexField CTORATstpLev2IndexFieldToRust(CTORATstpLev2IndexField* x);
    static CTORATstpLev2TransactionField Lev2TransactionFieldToCpp(Lev2TransactionField x);
    static Lev2TransactionField CTORATstpLev2TransactionFieldToRust(CTORATstpLev2TransactionField* x);
    static CTORATstpLev2OrderDetailField Lev2OrderDetailFieldToCpp(Lev2OrderDetailField x);
    static Lev2OrderDetailField CTORATstpLev2OrderDetailFieldToRust(CTORATstpLev2OrderDetailField* x);
    static CTORATstpLev2PHMarketDataField Lev2PHMarketDataFieldToCpp(Lev2PHMarketDataField x);
    static Lev2PHMarketDataField CTORATstpLev2PHMarketDataFieldToRust(CTORATstpLev2PHMarketDataField* x);
    static CTORATstpLev2PHTransactionField Lev2PHTransactionFieldToCpp(Lev2PHTransactionField x);
    static Lev2PHTransactionField CTORATstpLev2PHTransactionFieldToRust(CTORATstpLev2PHTransactionField* x);
    static CTORATstpLev2ResendTransactionField Lev2ResendTransactionFieldToCpp(Lev2ResendTransactionField x);
    static Lev2ResendTransactionField CTORATstpLev2ResendTransactionFieldToRust(CTORATstpLev2ResendTransactionField* x);
    static CTORATstpLev2ResendOrderDetailField Lev2ResendOrderDetailFieldToCpp(Lev2ResendOrderDetailField x);
    static Lev2ResendOrderDetailField CTORATstpLev2ResendOrderDetailFieldToRust(CTORATstpLev2ResendOrderDetailField* x);
    static CTORATstpLev2XTSMarketDataField Lev2XTSMarketDataFieldToCpp(Lev2XTSMarketDataField x);
    static Lev2XTSMarketDataField CTORATstpLev2XTSMarketDataFieldToRust(CTORATstpLev2XTSMarketDataField* x);
    static CTORATstpLev2XTSTickField Lev2XTSTickFieldToCpp(Lev2XTSTickField x);
    static Lev2XTSTickField CTORATstpLev2XTSTickFieldToRust(CTORATstpLev2XTSTickField* x);
    static CTORATstpLev2NGTSTickField Lev2NGTSTickFieldToCpp(Lev2NGTSTickField x);
    static Lev2NGTSTickField CTORATstpLev2NGTSTickFieldToRust(CTORATstpLev2NGTSTickField* x);
    static CTORATstpLev2BondMarketDataField Lev2BondMarketDataFieldToCpp(Lev2BondMarketDataField x);
    static Lev2BondMarketDataField CTORATstpLev2BondMarketDataFieldToRust(CTORATstpLev2BondMarketDataField* x);
    static CTORATstpLev2BondOrderDetailField Lev2BondOrderDetailFieldToCpp(Lev2BondOrderDetailField x);
    static Lev2BondOrderDetailField CTORATstpLev2BondOrderDetailFieldToRust(CTORATstpLev2BondOrderDetailField* x);
    static CTORATstpLev2BondTransactionField Lev2BondTransactionFieldToCpp(Lev2BondTransactionField x);
    static Lev2BondTransactionField CTORATstpLev2BondTransactionFieldToRust(CTORATstpLev2BondTransactionField* x);
    static CTORATstpLev2IOPVField Lev2IOPVFieldToCpp(Lev2IOPVField x);
    static Lev2IOPVField CTORATstpLev2IOPVFieldToRust(CTORATstpLev2IOPVField* x);
    static CTORATstpExIndexField ExIndexFieldToCpp(ExIndexField x);
    static ExIndexField CTORATstpExIndexFieldToRust(CTORATstpExIndexField* x);
};
} // namespace tora_lev2md
