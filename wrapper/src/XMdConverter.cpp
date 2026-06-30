#include "tora-rs/wrapper/include/XMdConverter.h"

namespace tora_xmd {
using namespace TORALEV1API;

#ifdef _WIN32

#include <Windows.h>

std::string Converter::GbkToUtf8(const char *src_str)
{
    if (src_str == nullptr)
        return std::string();

    int wlen = MultiByteToWideChar(936, 0, src_str, -1, nullptr, 0);
    if (wlen <= 0)
        return std::string();

    std::wstring wstr(static_cast<size_t>(wlen), L'\0');
    if (MultiByteToWideChar(936, 0, src_str, -1, &wstr[0], wlen) <= 0)
        return std::string();

    int len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1,
                                  nullptr, 0, nullptr, nullptr);
    if (len <= 0)
        return std::string();

    std::string str(static_cast<size_t>(len), '\0');
    if (WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1,
                            &str[0], len, nullptr, nullptr) <= 0)
        return std::string();

    if (!str.empty() && str.back() == '\0')
        str.pop_back();

    return str;
}

#else

#include <iconv.h>
#include <cerrno>

std::string Converter::GbkToUtf8(const char *src_str)
{
    if (src_str == nullptr)
        return std::string();

    iconv_t cd = iconv_open("UTF-8", "GBK");
    if (cd == (iconv_t)-1)
        return std::string();

    static const char REPL[] = "\xEF\xBF\xBD";  // U+FFFD
    const size_t REPL_LEN = 3;

    size_t inlen = strlen(src_str);
    size_t outcap = inlen * 4 + 1;
    std::string out(outcap, '\0');

    char *inbuf = const_cast<char *>(src_str);
    char *outbuf = &out[0];
    size_t outleft = outcap;

    while (inlen > 0)
    {
        size_t ret = iconv(cd, &inbuf, &inlen, &outbuf, &outleft);
        if (ret != (size_t)-1)
            break;

        if (errno == E2BIG)
        {
            size_t used = outcap - outleft;
            outcap *= 2;
            out.resize(outcap);
            outbuf = &out[0] + used;
            outleft = outcap - used;
            continue;
        }

        if (outleft < REPL_LEN)
        {
            size_t used = outcap - outleft;
            outcap *= 2;
            out.resize(outcap);
            outbuf = &out[0] + used;
            outleft = outcap - used;
        }
        memcpy(outbuf, REPL, REPL_LEN);
        outbuf += REPL_LEN;
        outleft -= REPL_LEN;
        ++inbuf;
        --inlen;
    }

    iconv_close(cd);
    out.resize(outcap - outleft);
    return out;
}

#endif

rust::String Converter::GbkToRustString(const char *src_str)
{
    if (src_str == nullptr)
        return rust::String("");
    return rust::String(Converter::GbkToUtf8(src_str));
}

CTORATstpReqUserLoginField Converter::ReqUserLoginFieldToCpp(ReqUserLoginField x) {
    CTORATstpReqUserLoginField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.LogInAccount, x.LogInAccount.c_str());
    y.LogInAccountType = x.LogInAccountType;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    y.AuthMode = x.AuthMode;
    strcpy(y.Password, x.Password.c_str());
    strcpy(y.UserProductInfo, x.UserProductInfo.c_str());
    strcpy(y.InterfaceProductInfo, x.InterfaceProductInfo.c_str());
    strcpy(y.TerminalInfo, x.TerminalInfo.c_str());
    strcpy(y.InnerIPAddress, x.InnerIPAddress.c_str());
    strcpy(y.OuterIPAddress, x.OuterIPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    y.Lang = x.Lang;
    strcpy(y.DynamicPassword, x.DynamicPassword.c_str());
    strcpy(y.DeviceID, x.DeviceID.c_str());
    strcpy(y.CertSerial, x.CertSerial.c_str());
    y.DeviceType = x.DeviceType;
    return y;
}

ReqUserLoginField Converter::CTORATstpReqUserLoginFieldToRust(CTORATstpReqUserLoginField* x) {
    if (x == nullptr)
        return ReqUserLoginField{.is_null = true};
    ReqUserLoginField y{};
    y.LogInAccount = Converter::GbkToRustString(x->LogInAccount);
    y.LogInAccountType = x->LogInAccountType;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AuthMode = x->AuthMode;
    y.Password = Converter::GbkToRustString(x->Password);
    y.UserProductInfo = Converter::GbkToRustString(x->UserProductInfo);
    y.InterfaceProductInfo = Converter::GbkToRustString(x->InterfaceProductInfo);
    y.TerminalInfo = Converter::GbkToRustString(x->TerminalInfo);
    y.InnerIPAddress = Converter::GbkToRustString(x->InnerIPAddress);
    y.OuterIPAddress = Converter::GbkToRustString(x->OuterIPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    y.Lang = x->Lang;
    y.DynamicPassword = Converter::GbkToRustString(x->DynamicPassword);
    y.DeviceID = Converter::GbkToRustString(x->DeviceID);
    y.CertSerial = Converter::GbkToRustString(x->CertSerial);
    y.DeviceType = x->DeviceType;
    return y;
}

CTORATstpRspUserLoginField Converter::RspUserLoginFieldToCpp(RspUserLoginField x) {
    CTORATstpRspUserLoginField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.LogInAccount, x.LogInAccount.c_str());
    y.LogInAccountType = x.LogInAccountType;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.MaxOrderRef = x.MaxOrderRef;
    y.PrivateFlowCount = x.PrivateFlowCount;
    y.PublicFlowCount = x.PublicFlowCount;
    strcpy(y.LoginTime, x.LoginTime.c_str());
    strcpy(y.SystemName, x.SystemName.c_str());
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.UserID, x.UserID.c_str());
    strcpy(y.UserName, x.UserName.c_str());
    y.UserType = x.UserType;
    y.OrderInsertCommFlux = x.OrderInsertCommFlux;
    y.OrderActionCommFlux = x.OrderActionCommFlux;
    strcpy(y.PasswordExpiryDate, x.PasswordExpiryDate.c_str());
    y.NeedUpdatePassword = x.NeedUpdatePassword;
    strcpy(y.CertSerial, x.CertSerial.c_str());
    strcpy(y.InnerIPAddress, x.InnerIPAddress.c_str());
    strcpy(y.OuterIPAddress, x.OuterIPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    return y;
}

RspUserLoginField Converter::CTORATstpRspUserLoginFieldToRust(CTORATstpRspUserLoginField* x) {
    if (x == nullptr)
        return RspUserLoginField{.is_null = true};
    RspUserLoginField y{};
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.LogInAccount = Converter::GbkToRustString(x->LogInAccount);
    y.LogInAccountType = x->LogInAccountType;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.MaxOrderRef = x->MaxOrderRef;
    y.PrivateFlowCount = x->PrivateFlowCount;
    y.PublicFlowCount = x->PublicFlowCount;
    y.LoginTime = Converter::GbkToRustString(x->LoginTime);
    y.SystemName = Converter::GbkToRustString(x->SystemName);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.UserID = Converter::GbkToRustString(x->UserID);
    y.UserName = Converter::GbkToRustString(x->UserName);
    y.UserType = x->UserType;
    y.OrderInsertCommFlux = x->OrderInsertCommFlux;
    y.OrderActionCommFlux = x->OrderActionCommFlux;
    y.PasswordExpiryDate = Converter::GbkToRustString(x->PasswordExpiryDate);
    y.NeedUpdatePassword = x->NeedUpdatePassword;
    y.CertSerial = Converter::GbkToRustString(x->CertSerial);
    y.InnerIPAddress = Converter::GbkToRustString(x->InnerIPAddress);
    y.OuterIPAddress = Converter::GbkToRustString(x->OuterIPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    return y;
}

CTORATstpRspInfoField Converter::RspInfoFieldToCpp(RspInfoField x) {
    CTORATstpRspInfoField y;
    memset(&y, 0, sizeof(y));
    y.ErrorID = x.ErrorID;
    strcpy(y.ErrorMsg, x.ErrorMsg.c_str());
    return y;
}

RspInfoField Converter::CTORATstpRspInfoFieldToRust(CTORATstpRspInfoField* x) {
    if (x == nullptr)
        return RspInfoField{.is_null = true};
    RspInfoField y{};
    y.ErrorID = x->ErrorID;
    y.ErrorMsg = Converter::GbkToRustString(x->ErrorMsg);
    return y;
}

CTORATstpUserLogoutField Converter::UserLogoutFieldToCpp(UserLogoutField x) {
    CTORATstpUserLogoutField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.UserID, x.UserID.c_str());
    return y;
}

UserLogoutField Converter::CTORATstpUserLogoutFieldToRust(CTORATstpUserLogoutField* x) {
    if (x == nullptr)
        return UserLogoutField{.is_null = true};
    UserLogoutField y{};
    y.UserID = Converter::GbkToRustString(x->UserID);
    return y;
}

CTORATstpSpecificSecurityField Converter::SpecificSecurityFieldToCpp(SpecificSecurityField x) {
    CTORATstpSpecificSecurityField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

SpecificSecurityField Converter::CTORATstpSpecificSecurityFieldToRust(CTORATstpSpecificSecurityField* x) {
    if (x == nullptr)
        return SpecificSecurityField{.is_null = true};
    SpecificSecurityField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpSpecificMarketField Converter::SpecificMarketFieldToCpp(SpecificMarketField x) {
    CTORATstpSpecificMarketField y;
    memset(&y, 0, sizeof(y));
    y.MarketID = x.MarketID;
    return y;
}

SpecificMarketField Converter::CTORATstpSpecificMarketFieldToRust(CTORATstpSpecificMarketField* x) {
    if (x == nullptr)
        return SpecificMarketField{.is_null = true};
    SpecificMarketField y{};
    y.MarketID = x->MarketID;
    return y;
}

CTORATstpInquiryMarketDataField Converter::InquiryMarketDataFieldToCpp(InquiryMarketDataField x) {
    CTORATstpInquiryMarketDataField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

InquiryMarketDataField Converter::CTORATstpInquiryMarketDataFieldToRust(CTORATstpInquiryMarketDataField* x) {
    if (x == nullptr)
        return InquiryMarketDataField{.is_null = true};
    InquiryMarketDataField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpMarketDataField Converter::MarketDataFieldToCpp(MarketDataField x) {
    CTORATstpMarketDataField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.PreClosePrice = x.PreClosePrice;
    y.OpenPrice = x.OpenPrice;
    y.Volume = x.Volume;
    y.Turnover = x.Turnover;
    y.TradingCount = x.TradingCount;
    y.LastPrice = x.LastPrice;
    y.HighestPrice = x.HighestPrice;
    y.LowestPrice = x.LowestPrice;
    y.BidPrice1 = x.BidPrice1;
    y.AskPrice1 = x.AskPrice1;
    y.UpperLimitPrice = x.UpperLimitPrice;
    y.LowerLimitPrice = x.LowerLimitPrice;
    y.PERatio1 = x.PERatio1;
    y.PERatio2 = x.PERatio2;
    y.PriceUpDown1 = x.PriceUpDown1;
    y.PriceUpDown2 = x.PriceUpDown2;
    y.OpenInterest = x.OpenInterest;
    y.BidVolume1 = x.BidVolume1;
    y.AskVolume1 = x.AskVolume1;
    y.BidPrice2 = x.BidPrice2;
    y.BidVolume2 = x.BidVolume2;
    y.AskPrice2 = x.AskPrice2;
    y.AskVolume2 = x.AskVolume2;
    y.BidPrice3 = x.BidPrice3;
    y.BidVolume3 = x.BidVolume3;
    y.AskPrice3 = x.AskPrice3;
    y.AskVolume3 = x.AskVolume3;
    y.BidPrice4 = x.BidPrice4;
    y.BidVolume4 = x.BidVolume4;
    y.AskPrice4 = x.AskPrice4;
    y.AskVolume4 = x.AskVolume4;
    y.BidPrice5 = x.BidPrice5;
    y.BidVolume5 = x.BidVolume5;
    y.AskPrice5 = x.AskPrice5;
    y.AskVolume5 = x.AskVolume5;
    strcpy(y.UpdateTime, x.UpdateTime.c_str());
    y.UpdateMillisec = x.UpdateMillisec;
    y.ClosePrice = x.ClosePrice;
    y.SettlementPrice = x.SettlementPrice;
    y.MDSecurityStat = x.MDSecurityStat;
    y.HWLevel = x.HWLevel;
    y.PreCloseIOPV = x.PreCloseIOPV;
    y.IOPV = x.IOPV;
    y.ETFPurVolume = x.ETFPurVolume;
    y.ETFPurCount = x.ETFPurCount;
    y.ETFRedVolume = x.ETFRedVolume;
    y.ETFRedCount = x.ETFRedCount;
    return y;
}

MarketDataField Converter::CTORATstpMarketDataFieldToRust(CTORATstpMarketDataField* x) {
    if (x == nullptr)
        return MarketDataField{.is_null = true};
    MarketDataField y{};
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.PreClosePrice = x->PreClosePrice;
    y.OpenPrice = x->OpenPrice;
    y.Volume = x->Volume;
    y.Turnover = x->Turnover;
    y.TradingCount = x->TradingCount;
    y.LastPrice = x->LastPrice;
    y.HighestPrice = x->HighestPrice;
    y.LowestPrice = x->LowestPrice;
    y.BidPrice1 = x->BidPrice1;
    y.AskPrice1 = x->AskPrice1;
    y.UpperLimitPrice = x->UpperLimitPrice;
    y.LowerLimitPrice = x->LowerLimitPrice;
    y.PERatio1 = x->PERatio1;
    y.PERatio2 = x->PERatio2;
    y.PriceUpDown1 = x->PriceUpDown1;
    y.PriceUpDown2 = x->PriceUpDown2;
    y.OpenInterest = x->OpenInterest;
    y.BidVolume1 = x->BidVolume1;
    y.AskVolume1 = x->AskVolume1;
    y.BidPrice2 = x->BidPrice2;
    y.BidVolume2 = x->BidVolume2;
    y.AskPrice2 = x->AskPrice2;
    y.AskVolume2 = x->AskVolume2;
    y.BidPrice3 = x->BidPrice3;
    y.BidVolume3 = x->BidVolume3;
    y.AskPrice3 = x->AskPrice3;
    y.AskVolume3 = x->AskVolume3;
    y.BidPrice4 = x->BidPrice4;
    y.BidVolume4 = x->BidVolume4;
    y.AskPrice4 = x->AskPrice4;
    y.AskVolume4 = x->AskVolume4;
    y.BidPrice5 = x->BidPrice5;
    y.BidVolume5 = x->BidVolume5;
    y.AskPrice5 = x->AskPrice5;
    y.AskVolume5 = x->AskVolume5;
    y.UpdateTime = Converter::GbkToRustString(x->UpdateTime);
    y.UpdateMillisec = x->UpdateMillisec;
    y.ClosePrice = x->ClosePrice;
    y.SettlementPrice = x->SettlementPrice;
    y.MDSecurityStat = x->MDSecurityStat;
    y.HWLevel = x->HWLevel;
    y.PreCloseIOPV = x->PreCloseIOPV;
    y.IOPV = x->IOPV;
    y.ETFPurVolume = x->ETFPurVolume;
    y.ETFPurCount = x->ETFPurCount;
    y.ETFRedVolume = x->ETFRedVolume;
    y.ETFRedCount = x->ETFRedCount;
    return y;
}

CTORATstpQryRspInfoField Converter::QryRspInfoFieldToCpp(QryRspInfoField x) {
    CTORATstpQryRspInfoField y;
    memset(&y, 0, sizeof(y));
    y.EndFlag = x.EndFlag;
    y.ErrorID = x.ErrorID;
    strcpy(y.ErrorMsg, x.ErrorMsg.c_str());
    return y;
}

QryRspInfoField Converter::CTORATstpQryRspInfoFieldToRust(CTORATstpQryRspInfoField* x) {
    if (x == nullptr)
        return QryRspInfoField{.is_null = true};
    QryRspInfoField y{};
    y.EndFlag = x->EndFlag;
    y.ErrorID = x->ErrorID;
    y.ErrorMsg = Converter::GbkToRustString(x->ErrorMsg);
    return y;
}

CTORATstpPHMarketDataField Converter::PHMarketDataFieldToCpp(PHMarketDataField x) {
    CTORATstpPHMarketDataField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.Volume = x.Volume;
    y.Turnover = x.Turnover;
    y.ClosePrice = x.ClosePrice;
    y.UpperLimitPrice = x.UpperLimitPrice;
    y.LowerLimitPrice = x.LowerLimitPrice;
    y.BidVolume = x.BidVolume;
    y.AskVolume = x.AskVolume;
    strcpy(y.UpdateTime, x.UpdateTime.c_str());
    y.UpdateMillisec = x.UpdateMillisec;
    y.MDSecurityStat = x.MDSecurityStat;
    y.HWLevel = x.HWLevel;
    return y;
}

PHMarketDataField Converter::CTORATstpPHMarketDataFieldToRust(CTORATstpPHMarketDataField* x) {
    if (x == nullptr)
        return PHMarketDataField{.is_null = true};
    PHMarketDataField y{};
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.Volume = x->Volume;
    y.Turnover = x->Turnover;
    y.ClosePrice = x->ClosePrice;
    y.UpperLimitPrice = x->UpperLimitPrice;
    y.LowerLimitPrice = x->LowerLimitPrice;
    y.BidVolume = x->BidVolume;
    y.AskVolume = x->AskVolume;
    y.UpdateTime = Converter::GbkToRustString(x->UpdateTime);
    y.UpdateMillisec = x->UpdateMillisec;
    y.MDSecurityStat = x->MDSecurityStat;
    y.HWLevel = x->HWLevel;
    return y;
}

CTORATstpInquirySpecialMarketDataField Converter::InquirySpecialMarketDataFieldToCpp(InquirySpecialMarketDataField x) {
    CTORATstpInquirySpecialMarketDataField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

InquirySpecialMarketDataField Converter::CTORATstpInquirySpecialMarketDataFieldToRust(CTORATstpInquirySpecialMarketDataField* x) {
    if (x == nullptr)
        return InquirySpecialMarketDataField{.is_null = true};
    InquirySpecialMarketDataField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpSpecialMarketDataField Converter::SpecialMarketDataFieldToCpp(SpecialMarketDataField x) {
    CTORATstpSpecialMarketDataField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.MovingAvgPrice = x.MovingAvgPrice;
    y.MovingAvgPriceSamplingNum = x.MovingAvgPriceSamplingNum;
    strcpy(y.UpdateTime, x.UpdateTime.c_str());
    y.UpdateMillisec = x.UpdateMillisec;
    return y;
}

SpecialMarketDataField Converter::CTORATstpSpecialMarketDataFieldToRust(CTORATstpSpecialMarketDataField* x) {
    if (x == nullptr)
        return SpecialMarketDataField{.is_null = true};
    SpecialMarketDataField y{};
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.MovingAvgPrice = x->MovingAvgPrice;
    y.MovingAvgPriceSamplingNum = x->MovingAvgPriceSamplingNum;
    y.UpdateTime = Converter::GbkToRustString(x->UpdateTime);
    y.UpdateMillisec = x->UpdateMillisec;
    return y;
}

CTORATstpSimplifyMarketDataField Converter::SimplifyMarketDataFieldToCpp(SimplifyMarketDataField x) {
    CTORATstpSimplifyMarketDataField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.PreClosePrice = x.PreClosePrice;
    y.LastPrice = x.LastPrice;
    y.BidPrice1 = x.BidPrice1;
    y.AskPrice1 = x.AskPrice1;
    y.HighestPrice = x.HighestPrice;
    y.LowestPrice = x.LowestPrice;
    y.UpperLimitPrice = x.UpperLimitPrice;
    y.LowerLimitPrice = x.LowerLimitPrice;
    y.ClosePrice = x.ClosePrice;
    y.SettlementPrice = x.SettlementPrice;
    strcpy(y.UpdateTime, x.UpdateTime.c_str());
    return y;
}

SimplifyMarketDataField Converter::CTORATstpSimplifyMarketDataFieldToRust(CTORATstpSimplifyMarketDataField* x) {
    if (x == nullptr)
        return SimplifyMarketDataField{.is_null = true};
    SimplifyMarketDataField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.PreClosePrice = x->PreClosePrice;
    y.LastPrice = x->LastPrice;
    y.BidPrice1 = x->BidPrice1;
    y.AskPrice1 = x->AskPrice1;
    y.HighestPrice = x->HighestPrice;
    y.LowestPrice = x->LowestPrice;
    y.UpperLimitPrice = x->UpperLimitPrice;
    y.LowerLimitPrice = x->LowerLimitPrice;
    y.ClosePrice = x->ClosePrice;
    y.SettlementPrice = x->SettlementPrice;
    y.UpdateTime = Converter::GbkToRustString(x->UpdateTime);
    return y;
}

CTORATstpSecurityStatusField Converter::SecurityStatusFieldToCpp(SecurityStatusField x) {
    CTORATstpSecurityStatusField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.IsSuspend = x.IsSuspend;
    y.IsBreak = x.IsBreak;
    y.IsLongSuspend = x.IsLongSuspend;
    y.IsCircuitBreak = x.IsCircuitBreak;
    y.IsSupportMarginBuy = x.IsSupportMarginBuy;
    y.IsSupportShortSell = x.IsSupportShortSell;
    y.IsSupportPur = x.IsSupportPur;
    y.IsSupportRed = x.IsSupportRed;
    y.IsSupportSplit = x.IsSupportSplit;
    y.IsSupportMerge = x.IsSupportMerge;
    y.IsSupportPleadgeIn = x.IsSupportPleadgeIn;
    y.IsSupportPleadgeOut = x.IsSupportPleadgeOut;
    y.IsSupportRoundLotBuy = x.IsSupportRoundLotBuy;
    y.IsSupportRoundLotSell = x.IsSupportRoundLotSell;
    y.IsSupportOddLotBuy = x.IsSupportOddLotBuy;
    y.IsSupportOddLotSell = x.IsSupportOddLotSell;
    y.IsSupportExercise = x.IsSupportExercise;
    y.IsLimitBuy = x.IsLimitBuy;
    y.IsLimitSell = x.IsLimitSell;
    y.IsLimitCover = x.IsLimitCover;
    y.IsLimitMarketMaker = x.IsLimitMarketMaker;
    return y;
}

SecurityStatusField Converter::CTORATstpSecurityStatusFieldToRust(CTORATstpSecurityStatusField* x) {
    if (x == nullptr)
        return SecurityStatusField{.is_null = true};
    SecurityStatusField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.IsSuspend = x->IsSuspend;
    y.IsBreak = x->IsBreak;
    y.IsLongSuspend = x->IsLongSuspend;
    y.IsCircuitBreak = x->IsCircuitBreak;
    y.IsSupportMarginBuy = x->IsSupportMarginBuy;
    y.IsSupportShortSell = x->IsSupportShortSell;
    y.IsSupportPur = x->IsSupportPur;
    y.IsSupportRed = x->IsSupportRed;
    y.IsSupportSplit = x->IsSupportSplit;
    y.IsSupportMerge = x->IsSupportMerge;
    y.IsSupportPleadgeIn = x->IsSupportPleadgeIn;
    y.IsSupportPleadgeOut = x->IsSupportPleadgeOut;
    y.IsSupportRoundLotBuy = x->IsSupportRoundLotBuy;
    y.IsSupportRoundLotSell = x->IsSupportRoundLotSell;
    y.IsSupportOddLotBuy = x->IsSupportOddLotBuy;
    y.IsSupportOddLotSell = x->IsSupportOddLotSell;
    y.IsSupportExercise = x->IsSupportExercise;
    y.IsLimitBuy = x->IsLimitBuy;
    y.IsLimitSell = x->IsLimitSell;
    y.IsLimitCover = x->IsLimitCover;
    y.IsLimitMarketMaker = x->IsLimitMarketMaker;
    return y;
}

CTORATstpMarketStatusField Converter::MarketStatusFieldToCpp(MarketStatusField x) {
    CTORATstpMarketStatusField y;
    memset(&y, 0, sizeof(y));
    y.MarketID = x.MarketID;
    y.MarketStatus = x.MarketStatus;
    return y;
}

MarketStatusField Converter::CTORATstpMarketStatusFieldToRust(CTORATstpMarketStatusField* x) {
    if (x == nullptr)
        return MarketStatusField{.is_null = true};
    MarketStatusField y{};
    y.MarketID = x->MarketID;
    y.MarketStatus = x->MarketStatus;
    return y;
}

CTORATstpImcParamsField Converter::ImcParamsFieldToCpp(ImcParamsField x) {
    CTORATstpImcParamsField y;
    memset(&y, 0, sizeof(y));
    y.MarketID = x.MarketID;
    y.OpenFlag = x.OpenFlag;
    y.ThresholdAmount = x.ThresholdAmount;
    y.PosAmt = x.PosAmt;
    y.AmountStatus = x.AmountStatus;
    return y;
}

ImcParamsField Converter::CTORATstpImcParamsFieldToRust(CTORATstpImcParamsField* x) {
    if (x == nullptr)
        return ImcParamsField{.is_null = true};
    ImcParamsField y{};
    y.MarketID = x->MarketID;
    y.OpenFlag = x->OpenFlag;
    y.ThresholdAmount = x->ThresholdAmount;
    y.PosAmt = x->PosAmt;
    y.AmountStatus = x->AmountStatus;
    return y;
}

CTORATstpIOPVField Converter::IOPVFieldToCpp(IOPVField x) {
    CTORATstpIOPVField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityName, x.SecurityName.c_str());
    strcpy(y.UpdateTime, x.UpdateTime.c_str());
    y.UpdateMillisec = x.UpdateMillisec;
    y.IOPV = x.IOPV;
    y.MDSecurityStat = x.MDSecurityStat;
    return y;
}

IOPVField Converter::CTORATstpIOPVFieldToRust(CTORATstpIOPVField* x) {
    if (x == nullptr)
        return IOPVField{.is_null = true};
    IOPVField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.UpdateTime = Converter::GbkToRustString(x->UpdateTime);
    y.UpdateMillisec = x->UpdateMillisec;
    y.IOPV = x->IOPV;
    y.MDSecurityStat = x->MDSecurityStat;
    return y;
}

CTORATstpRapidMarketDataField Converter::RapidMarketDataFieldToCpp(RapidMarketDataField x) {
    CTORATstpRapidMarketDataField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.DataTimeStamp = x.DataTimeStamp;
    y.PreClosePrice = x.PreClosePrice;
    y.OpenPrice = x.OpenPrice;
    y.NumTrades = x.NumTrades;
    y.TotalVolumeTrade = x.TotalVolumeTrade;
    y.TotalValueTrade = x.TotalValueTrade;
    y.HighestPrice = x.HighestPrice;
    y.LowestPrice = x.LowestPrice;
    y.LastPrice = x.LastPrice;
    y.BidPrice1 = x.BidPrice1;
    y.BidVolume1 = x.BidVolume1;
    y.AskPrice1 = x.AskPrice1;
    y.AskVolume1 = x.AskVolume1;
    y.AskPrice2 = x.AskPrice2;
    y.AskVolume2 = x.AskVolume2;
    y.AskPrice3 = x.AskPrice3;
    y.AskVolume3 = x.AskVolume3;
    y.BidPrice2 = x.BidPrice2;
    y.BidVolume2 = x.BidVolume2;
    y.BidPrice3 = x.BidPrice3;
    y.BidVolume3 = x.BidVolume3;
    y.AskPrice4 = x.AskPrice4;
    y.AskVolume4 = x.AskVolume4;
    y.AskPrice5 = x.AskPrice5;
    y.AskVolume5 = x.AskVolume5;
    y.BidPrice4 = x.BidPrice4;
    y.BidVolume4 = x.BidVolume4;
    y.BidPrice5 = x.BidPrice5;
    y.BidVolume5 = x.BidVolume5;
    y.AskPrice6 = x.AskPrice6;
    y.AskVolume6 = x.AskVolume6;
    y.AskPrice7 = x.AskPrice7;
    y.AskVolume7 = x.AskVolume7;
    y.BidPrice6 = x.BidPrice6;
    y.BidVolume6 = x.BidVolume6;
    y.BidPrice7 = x.BidPrice7;
    y.BidVolume7 = x.BidVolume7;
    y.AskPrice8 = x.AskPrice8;
    y.AskVolume8 = x.AskVolume8;
    y.AskPrice9 = x.AskPrice9;
    y.AskVolume9 = x.AskVolume9;
    y.BidPrice8 = x.BidPrice8;
    y.BidVolume8 = x.BidVolume8;
    y.BidPrice9 = x.BidPrice9;
    y.BidVolume9 = x.BidVolume9;
    y.BidPrice10 = x.BidPrice10;
    y.BidVolume10 = x.BidVolume10;
    y.AskPrice10 = x.AskPrice10;
    y.AskVolume10 = x.AskVolume10;
    y.UpperLimitPrice = x.UpperLimitPrice;
    y.LowerLimitPrice = x.LowerLimitPrice;
    y.ClosePrice = x.ClosePrice;
    y.MDSecurityStat = x.MDSecurityStat;
    y.IOPV = x.IOPV;
    y.InnerSell = x.InnerSell;
    y.OuterBuy = x.OuterBuy;
    y.BidCount1 = x.BidCount1;
    y.AskCount1 = x.AskCount1;
    y.AskCount2 = x.AskCount2;
    y.AskCount3 = x.AskCount3;
    y.BidCount2 = x.BidCount2;
    y.BidCount3 = x.BidCount3;
    y.AskCount4 = x.AskCount4;
    y.AskCount5 = x.AskCount5;
    y.BidCount4 = x.BidCount4;
    y.BidCount5 = x.BidCount5;
    y.AskCount6 = x.AskCount6;
    y.AskCount7 = x.AskCount7;
    y.BidCount6 = x.BidCount6;
    y.BidCount7 = x.BidCount7;
    y.AskCount8 = x.AskCount8;
    y.AskCount9 = x.AskCount9;
    y.BidCount8 = x.BidCount8;
    y.BidCount9 = x.BidCount9;
    y.BidCount10 = x.BidCount10;
    y.AskCount10 = x.AskCount10;
    return y;
}

RapidMarketDataField Converter::CTORATstpRapidMarketDataFieldToRust(CTORATstpRapidMarketDataField* x) {
    if (x == nullptr)
        return RapidMarketDataField{.is_null = true};
    RapidMarketDataField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.DataTimeStamp = x->DataTimeStamp;
    y.PreClosePrice = x->PreClosePrice;
    y.OpenPrice = x->OpenPrice;
    y.NumTrades = x->NumTrades;
    y.TotalVolumeTrade = x->TotalVolumeTrade;
    y.TotalValueTrade = x->TotalValueTrade;
    y.HighestPrice = x->HighestPrice;
    y.LowestPrice = x->LowestPrice;
    y.LastPrice = x->LastPrice;
    y.BidPrice1 = x->BidPrice1;
    y.BidVolume1 = x->BidVolume1;
    y.AskPrice1 = x->AskPrice1;
    y.AskVolume1 = x->AskVolume1;
    y.AskPrice2 = x->AskPrice2;
    y.AskVolume2 = x->AskVolume2;
    y.AskPrice3 = x->AskPrice3;
    y.AskVolume3 = x->AskVolume3;
    y.BidPrice2 = x->BidPrice2;
    y.BidVolume2 = x->BidVolume2;
    y.BidPrice3 = x->BidPrice3;
    y.BidVolume3 = x->BidVolume3;
    y.AskPrice4 = x->AskPrice4;
    y.AskVolume4 = x->AskVolume4;
    y.AskPrice5 = x->AskPrice5;
    y.AskVolume5 = x->AskVolume5;
    y.BidPrice4 = x->BidPrice4;
    y.BidVolume4 = x->BidVolume4;
    y.BidPrice5 = x->BidPrice5;
    y.BidVolume5 = x->BidVolume5;
    y.AskPrice6 = x->AskPrice6;
    y.AskVolume6 = x->AskVolume6;
    y.AskPrice7 = x->AskPrice7;
    y.AskVolume7 = x->AskVolume7;
    y.BidPrice6 = x->BidPrice6;
    y.BidVolume6 = x->BidVolume6;
    y.BidPrice7 = x->BidPrice7;
    y.BidVolume7 = x->BidVolume7;
    y.AskPrice8 = x->AskPrice8;
    y.AskVolume8 = x->AskVolume8;
    y.AskPrice9 = x->AskPrice9;
    y.AskVolume9 = x->AskVolume9;
    y.BidPrice8 = x->BidPrice8;
    y.BidVolume8 = x->BidVolume8;
    y.BidPrice9 = x->BidPrice9;
    y.BidVolume9 = x->BidVolume9;
    y.BidPrice10 = x->BidPrice10;
    y.BidVolume10 = x->BidVolume10;
    y.AskPrice10 = x->AskPrice10;
    y.AskVolume10 = x->AskVolume10;
    y.UpperLimitPrice = x->UpperLimitPrice;
    y.LowerLimitPrice = x->LowerLimitPrice;
    y.ClosePrice = x->ClosePrice;
    y.MDSecurityStat = x->MDSecurityStat;
    y.IOPV = x->IOPV;
    y.InnerSell = x->InnerSell;
    y.OuterBuy = x->OuterBuy;
    y.BidCount1 = x->BidCount1;
    y.AskCount1 = x->AskCount1;
    y.AskCount2 = x->AskCount2;
    y.AskCount3 = x->AskCount3;
    y.BidCount2 = x->BidCount2;
    y.BidCount3 = x->BidCount3;
    y.AskCount4 = x->AskCount4;
    y.AskCount5 = x->AskCount5;
    y.BidCount4 = x->BidCount4;
    y.BidCount5 = x->BidCount5;
    y.AskCount6 = x->AskCount6;
    y.AskCount7 = x->AskCount7;
    y.BidCount6 = x->BidCount6;
    y.BidCount7 = x->BidCount7;
    y.AskCount8 = x->AskCount8;
    y.AskCount9 = x->AskCount9;
    y.BidCount8 = x->BidCount8;
    y.BidCount9 = x->BidCount9;
    y.BidCount10 = x->BidCount10;
    y.AskCount10 = x->AskCount10;
    return y;
}

CTORATstpFensUserInfoField Converter::FensUserInfoFieldToCpp(FensUserInfoField x) {
    CTORATstpFensUserInfoField y;
    memset(&y, 0, sizeof(y));
    y.FensVer = x.FensVer;
    strcpy(y.FensEnvID, x.FensEnvID.c_str());
    strcpy(y.FensNodeID, x.FensNodeID.c_str());
    strcpy(y.FensUserID, x.FensUserID.c_str());
    strcpy(y.UserID, x.UserID.c_str());
    strcpy(y.ClientInfo, x.ClientInfo.c_str());
    return y;
}

FensUserInfoField Converter::CTORATstpFensUserInfoFieldToRust(CTORATstpFensUserInfoField* x) {
    if (x == nullptr)
        return FensUserInfoField{.is_null = true};
    FensUserInfoField y{};
    y.FensVer = x->FensVer;
    y.FensEnvID = Converter::GbkToRustString(x->FensEnvID);
    y.FensNodeID = Converter::GbkToRustString(x->FensNodeID);
    y.FensUserID = Converter::GbkToRustString(x->FensUserID);
    y.UserID = Converter::GbkToRustString(x->UserID);
    y.ClientInfo = Converter::GbkToRustString(x->ClientInfo);
    return y;
}

CTORATstpConnectionInfoField Converter::ConnectionInfoFieldToCpp(ConnectionInfoField x) {
    CTORATstpConnectionInfoField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InnerIPAddress, x.InnerIPAddress.c_str());
    y.InnerPort = x.InnerPort;
    strcpy(y.OuterIPAddress, x.OuterIPAddress.c_str());
    y.OuterPort = x.OuterPort;
    strcpy(y.MacAddress, x.MacAddress.c_str());
    return y;
}

ConnectionInfoField Converter::CTORATstpConnectionInfoFieldToRust(CTORATstpConnectionInfoField* x) {
    if (x == nullptr)
        return ConnectionInfoField{.is_null = true};
    ConnectionInfoField y{};
    y.InnerIPAddress = Converter::GbkToRustString(x->InnerIPAddress);
    y.InnerPort = x->InnerPort;
    y.OuterIPAddress = Converter::GbkToRustString(x->OuterIPAddress);
    y.OuterPort = x->OuterPort;
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    return y;
}

} // namespace tora_xmd
