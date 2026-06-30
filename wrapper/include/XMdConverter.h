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
}

#include "tora-rs/src/xmd.rs.h"
#include "TORATstpXMdApi.h"
#include "rust/cxx.h"
#include <cstring>
#include <string>

namespace tora_xmd {
using namespace TORALEV1API;

class Converter {
public:
    static std::string GbkToUtf8(const char *src_str);
    static rust::String GbkToRustString(const char *src_str);
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
    static CTORATstpSpecificMarketField SpecificMarketFieldToCpp(SpecificMarketField x);
    static SpecificMarketField CTORATstpSpecificMarketFieldToRust(CTORATstpSpecificMarketField* x);
    static CTORATstpInquiryMarketDataField InquiryMarketDataFieldToCpp(InquiryMarketDataField x);
    static InquiryMarketDataField CTORATstpInquiryMarketDataFieldToRust(CTORATstpInquiryMarketDataField* x);
    static CTORATstpMarketDataField MarketDataFieldToCpp(MarketDataField x);
    static MarketDataField CTORATstpMarketDataFieldToRust(CTORATstpMarketDataField* x);
    static CTORATstpQryRspInfoField QryRspInfoFieldToCpp(QryRspInfoField x);
    static QryRspInfoField CTORATstpQryRspInfoFieldToRust(CTORATstpQryRspInfoField* x);
    static CTORATstpPHMarketDataField PHMarketDataFieldToCpp(PHMarketDataField x);
    static PHMarketDataField CTORATstpPHMarketDataFieldToRust(CTORATstpPHMarketDataField* x);
    static CTORATstpInquirySpecialMarketDataField InquirySpecialMarketDataFieldToCpp(InquirySpecialMarketDataField x);
    static InquirySpecialMarketDataField CTORATstpInquirySpecialMarketDataFieldToRust(CTORATstpInquirySpecialMarketDataField* x);
    static CTORATstpSpecialMarketDataField SpecialMarketDataFieldToCpp(SpecialMarketDataField x);
    static SpecialMarketDataField CTORATstpSpecialMarketDataFieldToRust(CTORATstpSpecialMarketDataField* x);
    static CTORATstpSimplifyMarketDataField SimplifyMarketDataFieldToCpp(SimplifyMarketDataField x);
    static SimplifyMarketDataField CTORATstpSimplifyMarketDataFieldToRust(CTORATstpSimplifyMarketDataField* x);
    static CTORATstpSecurityStatusField SecurityStatusFieldToCpp(SecurityStatusField x);
    static SecurityStatusField CTORATstpSecurityStatusFieldToRust(CTORATstpSecurityStatusField* x);
    static CTORATstpMarketStatusField MarketStatusFieldToCpp(MarketStatusField x);
    static MarketStatusField CTORATstpMarketStatusFieldToRust(CTORATstpMarketStatusField* x);
    static CTORATstpImcParamsField ImcParamsFieldToCpp(ImcParamsField x);
    static ImcParamsField CTORATstpImcParamsFieldToRust(CTORATstpImcParamsField* x);
    static CTORATstpIOPVField IOPVFieldToCpp(IOPVField x);
    static IOPVField CTORATstpIOPVFieldToRust(CTORATstpIOPVField* x);
    static CTORATstpRapidMarketDataField RapidMarketDataFieldToCpp(RapidMarketDataField x);
    static RapidMarketDataField CTORATstpRapidMarketDataFieldToRust(CTORATstpRapidMarketDataField* x);
    static CTORATstpFensUserInfoField FensUserInfoFieldToCpp(FensUserInfoField x);
    static FensUserInfoField CTORATstpFensUserInfoFieldToRust(CTORATstpFensUserInfoField* x);
    static CTORATstpConnectionInfoField ConnectionInfoFieldToCpp(ConnectionInfoField x);
    static ConnectionInfoField CTORATstpConnectionInfoFieldToRust(CTORATstpConnectionInfoField* x);
};
} // namespace tora_xmd
