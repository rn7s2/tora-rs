#include "tora-rs/wrapper/include/Lev2MdConverter.h"

namespace tora_lev2md {
using namespace TORALEV2API;

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

CTORATstpFensUserInfoField Converter::FensUserInfoFieldToCpp(FensUserInfoField x) {
    CTORATstpFensUserInfoField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.LogInAccount, x.LogInAccount.c_str());
    y.LogInAccountType = x.LogInAccountType;
    return y;
}

FensUserInfoField Converter::CTORATstpFensUserInfoFieldToRust(CTORATstpFensUserInfoField* x) {
    if (x == nullptr)
        return FensUserInfoField{.is_null = true};
    FensUserInfoField y{};
    y.LogInAccount = Converter::GbkToRustString(x->LogInAccount);
    y.LogInAccountType = x->LogInAccountType;
    return y;
}

CTORATstpReqUserLoginField Converter::ReqUserLoginFieldToCpp(ReqUserLoginField x) {
    CTORATstpReqUserLoginField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.LogInAccount, x.LogInAccount.c_str());
    y.LogInAccountType = x.LogInAccountType;
    strcpy(y.Password, x.Password.c_str());
    strcpy(y.UserProductInfo, x.UserProductInfo.c_str());
    strcpy(y.InterfaceProductInfo, x.InterfaceProductInfo.c_str());
    strcpy(y.ProtocolInfo, x.ProtocolInfo.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    strcpy(y.Mobile, x.Mobile.c_str());
    strcpy(y.InnerIPAddress, x.InnerIPAddress.c_str());
    memcpy(y.Lang, x.Lang.data(), x.Lang.size() * sizeof(uint8_t));
    strcpy(y.TerminalInfo, x.TerminalInfo.c_str());
    strcpy(y.GWMacAddress, x.GWMacAddress.c_str());
    strcpy(y.GWInnerIPAddress, x.GWInnerIPAddress.c_str());
    strcpy(y.GWOuterIPAddress, x.GWOuterIPAddress.c_str());
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.HDSerial, x.HDSerial.c_str());
    y.AuthMode = x.AuthMode;
    strcpy(y.DeviceID, x.DeviceID.c_str());
    strcpy(y.CertSerial, x.CertSerial.c_str());
    strcpy(y.OuterIPAddress, x.OuterIPAddress.c_str());
    strcpy(y.DynamicPassword, x.DynamicPassword.c_str());
    y.OuterPort = x.OuterPort;
    return y;
}

ReqUserLoginField Converter::CTORATstpReqUserLoginFieldToRust(CTORATstpReqUserLoginField* x) {
    if (x == nullptr)
        return ReqUserLoginField{.is_null = true};
    ReqUserLoginField y{};
    y.LogInAccount = Converter::GbkToRustString(x->LogInAccount);
    y.LogInAccountType = x->LogInAccountType;
    y.Password = Converter::GbkToRustString(x->Password);
    y.UserProductInfo = Converter::GbkToRustString(x->UserProductInfo);
    y.InterfaceProductInfo = Converter::GbkToRustString(x->InterfaceProductInfo);
    y.ProtocolInfo = Converter::GbkToRustString(x->ProtocolInfo);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    y.Mobile = Converter::GbkToRustString(x->Mobile);
    y.InnerIPAddress = Converter::GbkToRustString(x->InnerIPAddress);
    for (int i = 0; i < 17; i++)
        y.Lang.push_back(x->Lang[i]);
    y.TerminalInfo = Converter::GbkToRustString(x->TerminalInfo);
    y.GWMacAddress = Converter::GbkToRustString(x->GWMacAddress);
    y.GWInnerIPAddress = Converter::GbkToRustString(x->GWInnerIPAddress);
    y.GWOuterIPAddress = Converter::GbkToRustString(x->GWOuterIPAddress);
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.HDSerial = Converter::GbkToRustString(x->HDSerial);
    y.AuthMode = x->AuthMode;
    y.DeviceID = Converter::GbkToRustString(x->DeviceID);
    y.CertSerial = Converter::GbkToRustString(x->CertSerial);
    y.OuterIPAddress = Converter::GbkToRustString(x->OuterIPAddress);
    y.DynamicPassword = Converter::GbkToRustString(x->DynamicPassword);
    y.OuterPort = x->OuterPort;
    return y;
}

CTORATstpRspUserLoginField Converter::RspUserLoginFieldToCpp(RspUserLoginField x) {
    CTORATstpRspUserLoginField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.LoginTime, x.LoginTime.c_str());
    strcpy(y.LogInAccount, x.LogInAccount.c_str());
    y.LogInAccountType = x.LogInAccountType;
    strcpy(y.SystemName, x.SystemName.c_str());
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    strcpy(y.MaxOrderRef, x.MaxOrderRef.c_str());
    y.PrivateFlowCount = x.PrivateFlowCount;
    y.PublicFlowCount = x.PublicFlowCount;
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.UserID, x.UserID.c_str());
    strcpy(y.UserName, x.UserName.c_str());
    y.UserType = x.UserType;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.InnerIPAddress, x.InnerIPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    strcpy(y.HDSerial, x.HDSerial.c_str());
    y.OrderInsertCommFlux = x.OrderInsertCommFlux;
    y.PasswordUpdatePeriod = x.PasswordUpdatePeriod;
    y.PasswordRemainDays = x.PasswordRemainDays;
    y.NeedUpdatePassword = x.NeedUpdatePassword;
    y.OrderActionCommFlux = x.OrderActionCommFlux;
    strcpy(y.Mobile, x.Mobile.c_str());
    strcpy(y.OuterIPAddress, x.OuterIPAddress.c_str());
    strcpy(y.CertSerial, x.CertSerial.c_str());
    y.OuterPort = x.OuterPort;
    return y;
}

RspUserLoginField Converter::CTORATstpRspUserLoginFieldToRust(CTORATstpRspUserLoginField* x) {
    if (x == nullptr)
        return RspUserLoginField{.is_null = true};
    RspUserLoginField y{};
    y.LoginTime = Converter::GbkToRustString(x->LoginTime);
    y.LogInAccount = Converter::GbkToRustString(x->LogInAccount);
    y.LogInAccountType = x->LogInAccountType;
    y.SystemName = Converter::GbkToRustString(x->SystemName);
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.MaxOrderRef = Converter::GbkToRustString(x->MaxOrderRef);
    y.PrivateFlowCount = x->PrivateFlowCount;
    y.PublicFlowCount = x->PublicFlowCount;
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.UserID = Converter::GbkToRustString(x->UserID);
    y.UserName = Converter::GbkToRustString(x->UserName);
    y.UserType = x->UserType;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.InnerIPAddress = Converter::GbkToRustString(x->InnerIPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    y.HDSerial = Converter::GbkToRustString(x->HDSerial);
    y.OrderInsertCommFlux = x->OrderInsertCommFlux;
    y.PasswordUpdatePeriod = x->PasswordUpdatePeriod;
    y.PasswordRemainDays = x->PasswordRemainDays;
    y.NeedUpdatePassword = x->NeedUpdatePassword;
    y.OrderActionCommFlux = x->OrderActionCommFlux;
    y.Mobile = Converter::GbkToRustString(x->Mobile);
    y.OuterIPAddress = Converter::GbkToRustString(x->OuterIPAddress);
    y.CertSerial = Converter::GbkToRustString(x->CertSerial);
    y.OuterPort = x->OuterPort;
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

CTORATstpLev2MarketDataField Converter::Lev2MarketDataFieldToCpp(Lev2MarketDataField x) {
    CTORATstpLev2MarketDataField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.DataTimeStamp = x.DataTimeStamp;
    y.PreClosePrice = x.PreClosePrice;
    y.OpenPrice = x.OpenPrice;
    y.NumTrades = x.NumTrades;
    y.TotalVolumeTrade = x.TotalVolumeTrade;
    y.TotalValueTrade = x.TotalValueTrade;
    y.TotalBidVolume = x.TotalBidVolume;
    y.AvgBidPrice = x.AvgBidPrice;
    y.TotalAskVolume = x.TotalAskVolume;
    y.AvgAskPrice = x.AvgAskPrice;
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
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    y.UpperLimitPrice = x.UpperLimitPrice;
    y.LowerLimitPrice = x.LowerLimitPrice;
    y.ClosePrice = x.ClosePrice;
    y.MDSecurityStat = x.MDSecurityStat;
    y.TotalBidNumber = x.TotalBidNumber;
    y.TotalOfferNumber = x.TotalOfferNumber;
    y.BidTradeMaxDuration = x.BidTradeMaxDuration;
    y.OfferTradeMaxDuration = x.OfferTradeMaxDuration;
    y.IOPV = x.IOPV;
    y.Ask1NumOrders = x.Ask1NumOrders;
    y.Bid1NumOrders = x.Bid1NumOrders;
    y.Ask2NumOrders = x.Ask2NumOrders;
    y.Bid2NumOrders = x.Bid2NumOrders;
    y.Ask3NumOrders = x.Ask3NumOrders;
    y.Bid3NumOrders = x.Bid3NumOrders;
    y.Ask4NumOrders = x.Ask4NumOrders;
    y.Bid4NumOrders = x.Bid4NumOrders;
    y.Ask5NumOrders = x.Ask5NumOrders;
    y.Bid5NumOrders = x.Bid5NumOrders;
    y.Ask6NumOrders = x.Ask6NumOrders;
    y.Bid6NumOrders = x.Bid6NumOrders;
    y.Ask7NumOrders = x.Ask7NumOrders;
    y.Bid7NumOrders = x.Bid7NumOrders;
    y.Ask8NumOrders = x.Ask8NumOrders;
    y.Bid8NumOrders = x.Bid8NumOrders;
    y.Ask9NumOrders = x.Ask9NumOrders;
    y.Bid9NumOrders = x.Bid9NumOrders;
    y.Ask10NumOrders = x.Ask10NumOrders;
    y.Bid10NumOrders = x.Bid10NumOrders;
    y.WithdrawBuyNumber = x.WithdrawBuyNumber;
    y.WithdrawBuyAmount = x.WithdrawBuyAmount;
    y.WithdrawBuyMoney = x.WithdrawBuyMoney;
    y.WithdrawSellNumber = x.WithdrawSellNumber;
    y.WithdrawSellAmount = x.WithdrawSellAmount;
    y.WithdrawSellMoney = x.WithdrawSellMoney;
    return y;
}

Lev2MarketDataField Converter::CTORATstpLev2MarketDataFieldToRust(CTORATstpLev2MarketDataField* x) {
    if (x == nullptr)
        return Lev2MarketDataField{.is_null = true};
    Lev2MarketDataField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.DataTimeStamp = x->DataTimeStamp;
    y.PreClosePrice = x->PreClosePrice;
    y.OpenPrice = x->OpenPrice;
    y.NumTrades = x->NumTrades;
    y.TotalVolumeTrade = x->TotalVolumeTrade;
    y.TotalValueTrade = x->TotalValueTrade;
    y.TotalBidVolume = x->TotalBidVolume;
    y.AvgBidPrice = x->AvgBidPrice;
    y.TotalAskVolume = x->TotalAskVolume;
    y.AvgAskPrice = x->AvgAskPrice;
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
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    y.UpperLimitPrice = x->UpperLimitPrice;
    y.LowerLimitPrice = x->LowerLimitPrice;
    y.ClosePrice = x->ClosePrice;
    y.MDSecurityStat = x->MDSecurityStat;
    y.TotalBidNumber = x->TotalBidNumber;
    y.TotalOfferNumber = x->TotalOfferNumber;
    y.BidTradeMaxDuration = x->BidTradeMaxDuration;
    y.OfferTradeMaxDuration = x->OfferTradeMaxDuration;
    y.IOPV = x->IOPV;
    y.Ask1NumOrders = x->Ask1NumOrders;
    y.Bid1NumOrders = x->Bid1NumOrders;
    y.Ask2NumOrders = x->Ask2NumOrders;
    y.Bid2NumOrders = x->Bid2NumOrders;
    y.Ask3NumOrders = x->Ask3NumOrders;
    y.Bid3NumOrders = x->Bid3NumOrders;
    y.Ask4NumOrders = x->Ask4NumOrders;
    y.Bid4NumOrders = x->Bid4NumOrders;
    y.Ask5NumOrders = x->Ask5NumOrders;
    y.Bid5NumOrders = x->Bid5NumOrders;
    y.Ask6NumOrders = x->Ask6NumOrders;
    y.Bid6NumOrders = x->Bid6NumOrders;
    y.Ask7NumOrders = x->Ask7NumOrders;
    y.Bid7NumOrders = x->Bid7NumOrders;
    y.Ask8NumOrders = x->Ask8NumOrders;
    y.Bid8NumOrders = x->Bid8NumOrders;
    y.Ask9NumOrders = x->Ask9NumOrders;
    y.Bid9NumOrders = x->Bid9NumOrders;
    y.Ask10NumOrders = x->Ask10NumOrders;
    y.Bid10NumOrders = x->Bid10NumOrders;
    y.WithdrawBuyNumber = x->WithdrawBuyNumber;
    y.WithdrawBuyAmount = x->WithdrawBuyAmount;
    y.WithdrawBuyMoney = x->WithdrawBuyMoney;
    y.WithdrawSellNumber = x->WithdrawSellNumber;
    y.WithdrawSellAmount = x->WithdrawSellAmount;
    y.WithdrawSellMoney = x->WithdrawSellMoney;
    return y;
}

CTORATstpLev2IndexField Converter::Lev2IndexFieldToCpp(Lev2IndexField x) {
    CTORATstpLev2IndexField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.DataTimeStamp = x.DataTimeStamp;
    y.PreCloseIndex = x.PreCloseIndex;
    y.OpenIndex = x.OpenIndex;
    y.HighIndex = x.HighIndex;
    y.LowIndex = x.LowIndex;
    y.LastIndex = x.LastIndex;
    y.Turnover = x.Turnover;
    y.TotalVolumeTraded = x.TotalVolumeTraded;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    y.CloseIndex = x.CloseIndex;
    return y;
}

Lev2IndexField Converter::CTORATstpLev2IndexFieldToRust(CTORATstpLev2IndexField* x) {
    if (x == nullptr)
        return Lev2IndexField{.is_null = true};
    Lev2IndexField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.DataTimeStamp = x->DataTimeStamp;
    y.PreCloseIndex = x->PreCloseIndex;
    y.OpenIndex = x->OpenIndex;
    y.HighIndex = x->HighIndex;
    y.LowIndex = x->LowIndex;
    y.LastIndex = x->LastIndex;
    y.Turnover = x->Turnover;
    y.TotalVolumeTraded = x->TotalVolumeTraded;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    y.CloseIndex = x->CloseIndex;
    return y;
}

CTORATstpLev2TransactionField Converter::Lev2TransactionFieldToCpp(Lev2TransactionField x) {
    CTORATstpLev2TransactionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.TradeTime = x.TradeTime;
    y.TradePrice = x.TradePrice;
    y.TradeVolume = x.TradeVolume;
    y.ExecType = x.ExecType;
    y.MainSeq = x.MainSeq;
    y.SubSeq = x.SubSeq;
    y.BuyNo = x.BuyNo;
    y.SellNo = x.SellNo;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    y.TradeBSFlag = x.TradeBSFlag;
    y.BizIndex = x.BizIndex;
    return y;
}

Lev2TransactionField Converter::CTORATstpLev2TransactionFieldToRust(CTORATstpLev2TransactionField* x) {
    if (x == nullptr)
        return Lev2TransactionField{.is_null = true};
    Lev2TransactionField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TradeTime = x->TradeTime;
    y.TradePrice = x->TradePrice;
    y.TradeVolume = x->TradeVolume;
    y.ExecType = x->ExecType;
    y.MainSeq = x->MainSeq;
    y.SubSeq = x->SubSeq;
    y.BuyNo = x->BuyNo;
    y.SellNo = x->SellNo;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    y.TradeBSFlag = x->TradeBSFlag;
    y.BizIndex = x->BizIndex;
    return y;
}

CTORATstpLev2OrderDetailField Converter::Lev2OrderDetailFieldToCpp(Lev2OrderDetailField x) {
    CTORATstpLev2OrderDetailField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.OrderTime = x.OrderTime;
    y.Price = x.Price;
    y.Volume = x.Volume;
    y.Side = x.Side;
    y.OrderType = x.OrderType;
    y.MainSeq = x.MainSeq;
    y.SubSeq = x.SubSeq;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    y.OrderNO = x.OrderNO;
    y.OrderStatus = x.OrderStatus;
    y.BizIndex = x.BizIndex;
    return y;
}

Lev2OrderDetailField Converter::CTORATstpLev2OrderDetailFieldToRust(CTORATstpLev2OrderDetailField* x) {
    if (x == nullptr)
        return Lev2OrderDetailField{.is_null = true};
    Lev2OrderDetailField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.OrderTime = x->OrderTime;
    y.Price = x->Price;
    y.Volume = x->Volume;
    y.Side = x->Side;
    y.OrderType = x->OrderType;
    y.MainSeq = x->MainSeq;
    y.SubSeq = x->SubSeq;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    y.OrderNO = x->OrderNO;
    y.OrderStatus = x->OrderStatus;
    y.BizIndex = x->BizIndex;
    return y;
}

CTORATstpLev2PHMarketDataField Converter::Lev2PHMarketDataFieldToCpp(Lev2PHMarketDataField x) {
    CTORATstpLev2PHMarketDataField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.DataTimeStamp = x.DataTimeStamp;
    y.ClosePrice = x.ClosePrice;
    y.MDSecurityStat = x.MDSecurityStat;
    y.NumTrades = x.NumTrades;
    y.TotalVolumeTrade = x.TotalVolumeTrade;
    y.TotalValueTrade = x.TotalValueTrade;
    y.TotalBidVolume = x.TotalBidVolume;
    y.TotalAskVolume = x.TotalAskVolume;
    y.WithdrawBuyNumber = x.WithdrawBuyNumber;
    y.WithdrawBuyAmount = x.WithdrawBuyAmount;
    y.WithdrawSellNumber = x.WithdrawSellNumber;
    y.WithdrawSellAmount = x.WithdrawSellAmount;
    y.BidOrderQty = x.BidOrderQty;
    y.BidNumOrders = x.BidNumOrders;
    y.AskOrderQty = x.AskOrderQty;
    y.AskNumOrders = x.AskNumOrders;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    return y;
}

Lev2PHMarketDataField Converter::CTORATstpLev2PHMarketDataFieldToRust(CTORATstpLev2PHMarketDataField* x) {
    if (x == nullptr)
        return Lev2PHMarketDataField{.is_null = true};
    Lev2PHMarketDataField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.DataTimeStamp = x->DataTimeStamp;
    y.ClosePrice = x->ClosePrice;
    y.MDSecurityStat = x->MDSecurityStat;
    y.NumTrades = x->NumTrades;
    y.TotalVolumeTrade = x->TotalVolumeTrade;
    y.TotalValueTrade = x->TotalValueTrade;
    y.TotalBidVolume = x->TotalBidVolume;
    y.TotalAskVolume = x->TotalAskVolume;
    y.WithdrawBuyNumber = x->WithdrawBuyNumber;
    y.WithdrawBuyAmount = x->WithdrawBuyAmount;
    y.WithdrawSellNumber = x->WithdrawSellNumber;
    y.WithdrawSellAmount = x->WithdrawSellAmount;
    y.BidOrderQty = x->BidOrderQty;
    y.BidNumOrders = x->BidNumOrders;
    y.AskOrderQty = x->AskOrderQty;
    y.AskNumOrders = x->AskNumOrders;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    return y;
}

CTORATstpLev2PHTransactionField Converter::Lev2PHTransactionFieldToCpp(Lev2PHTransactionField x) {
    CTORATstpLev2PHTransactionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.TradeTime = x.TradeTime;
    y.TradePrice = x.TradePrice;
    y.TradeVolume = x.TradeVolume;
    y.TradeMoney = x.TradeMoney;
    y.ExecType = x.ExecType;
    y.MainSeq = x.MainSeq;
    y.SubSeq = x.SubSeq;
    y.BuyNo = x.BuyNo;
    y.SellNo = x.SellNo;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    y.TradeBSFlag = x.TradeBSFlag;
    return y;
}

Lev2PHTransactionField Converter::CTORATstpLev2PHTransactionFieldToRust(CTORATstpLev2PHTransactionField* x) {
    if (x == nullptr)
        return Lev2PHTransactionField{.is_null = true};
    Lev2PHTransactionField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TradeTime = x->TradeTime;
    y.TradePrice = x->TradePrice;
    y.TradeVolume = x->TradeVolume;
    y.TradeMoney = x->TradeMoney;
    y.ExecType = x->ExecType;
    y.MainSeq = x->MainSeq;
    y.SubSeq = x->SubSeq;
    y.BuyNo = x->BuyNo;
    y.SellNo = x->SellNo;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    y.TradeBSFlag = x->TradeBSFlag;
    return y;
}

CTORATstpLev2ResendTransactionField Converter::Lev2ResendTransactionFieldToCpp(Lev2ResendTransactionField x) {
    CTORATstpLev2ResendTransactionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.TradeTime = x.TradeTime;
    y.TradePrice = x.TradePrice;
    y.TradeVolume = x.TradeVolume;
    y.ExecType = x.ExecType;
    y.MainSeq = x.MainSeq;
    y.SubSeq = x.SubSeq;
    y.BuyNo = x.BuyNo;
    y.SellNo = x.SellNo;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    y.TradeBSFlag = x.TradeBSFlag;
    y.BizIndex = x.BizIndex;
    return y;
}

Lev2ResendTransactionField Converter::CTORATstpLev2ResendTransactionFieldToRust(CTORATstpLev2ResendTransactionField* x) {
    if (x == nullptr)
        return Lev2ResendTransactionField{.is_null = true};
    Lev2ResendTransactionField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TradeTime = x->TradeTime;
    y.TradePrice = x->TradePrice;
    y.TradeVolume = x->TradeVolume;
    y.ExecType = x->ExecType;
    y.MainSeq = x->MainSeq;
    y.SubSeq = x->SubSeq;
    y.BuyNo = x->BuyNo;
    y.SellNo = x->SellNo;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    y.TradeBSFlag = x->TradeBSFlag;
    y.BizIndex = x->BizIndex;
    return y;
}

CTORATstpLev2ResendOrderDetailField Converter::Lev2ResendOrderDetailFieldToCpp(Lev2ResendOrderDetailField x) {
    CTORATstpLev2ResendOrderDetailField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.OrderTime = x.OrderTime;
    y.Price = x.Price;
    y.Volume = x.Volume;
    y.Side = x.Side;
    y.OrderType = x.OrderType;
    y.MainSeq = x.MainSeq;
    y.SubSeq = x.SubSeq;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    y.OrderNO = x.OrderNO;
    y.OrderStatus = x.OrderStatus;
    y.BizIndex = x.BizIndex;
    return y;
}

Lev2ResendOrderDetailField Converter::CTORATstpLev2ResendOrderDetailFieldToRust(CTORATstpLev2ResendOrderDetailField* x) {
    if (x == nullptr)
        return Lev2ResendOrderDetailField{.is_null = true};
    Lev2ResendOrderDetailField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.OrderTime = x->OrderTime;
    y.Price = x->Price;
    y.Volume = x->Volume;
    y.Side = x->Side;
    y.OrderType = x->OrderType;
    y.MainSeq = x->MainSeq;
    y.SubSeq = x->SubSeq;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    y.OrderNO = x->OrderNO;
    y.OrderStatus = x->OrderStatus;
    y.BizIndex = x->BizIndex;
    return y;
}

CTORATstpLev2XTSMarketDataField Converter::Lev2XTSMarketDataFieldToCpp(Lev2XTSMarketDataField x) {
    CTORATstpLev2XTSMarketDataField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.DataTimeStamp = x.DataTimeStamp;
    y.PreClosePrice = x.PreClosePrice;
    y.OpenPrice = x.OpenPrice;
    y.NumTrades = x.NumTrades;
    y.TotalVolumeTrade = x.TotalVolumeTrade;
    y.TotalValueTrade = x.TotalValueTrade;
    y.TotalBidVolume = x.TotalBidVolume;
    y.AvgBidPrice = x.AvgBidPrice;
    y.TotalAskVolume = x.TotalAskVolume;
    y.AvgAskPrice = x.AvgAskPrice;
    y.HighestPrice = x.HighestPrice;
    y.LowestPrice = x.LowestPrice;
    y.LastPrice = x.LastPrice;
    y.BidPrice1 = x.BidPrice1;
    y.BidVolume1 = x.BidVolume1;
    y.Bid1NumOrders = x.Bid1NumOrders;
    y.AskPrice1 = x.AskPrice1;
    y.AskVolume1 = x.AskVolume1;
    y.Ask1NumOrders = x.Ask1NumOrders;
    y.AskPrice2 = x.AskPrice2;
    y.AskVolume2 = x.AskVolume2;
    y.Ask2NumOrders = x.Ask2NumOrders;
    y.AskPrice3 = x.AskPrice3;
    y.AskVolume3 = x.AskVolume3;
    y.Ask3NumOrders = x.Ask3NumOrders;
    y.BidPrice2 = x.BidPrice2;
    y.BidVolume2 = x.BidVolume2;
    y.Bid2NumOrders = x.Bid2NumOrders;
    y.BidPrice3 = x.BidPrice3;
    y.BidVolume3 = x.BidVolume3;
    y.Bid3NumOrders = x.Bid3NumOrders;
    y.AskPrice4 = x.AskPrice4;
    y.AskVolume4 = x.AskVolume4;
    y.Ask4NumOrders = x.Ask4NumOrders;
    y.AskPrice5 = x.AskPrice5;
    y.AskVolume5 = x.AskVolume5;
    y.Ask5NumOrders = x.Ask5NumOrders;
    y.BidPrice4 = x.BidPrice4;
    y.BidVolume4 = x.BidVolume4;
    y.Bid4NumOrders = x.Bid4NumOrders;
    y.BidPrice5 = x.BidPrice5;
    y.BidVolume5 = x.BidVolume5;
    y.Bid5NumOrders = x.Bid5NumOrders;
    y.AskPrice6 = x.AskPrice6;
    y.AskVolume6 = x.AskVolume6;
    y.Ask6NumOrders = x.Ask6NumOrders;
    y.AskPrice7 = x.AskPrice7;
    y.AskVolume7 = x.AskVolume7;
    y.Ask7NumOrders = x.Ask7NumOrders;
    y.BidPrice6 = x.BidPrice6;
    y.BidVolume6 = x.BidVolume6;
    y.Bid6NumOrders = x.Bid6NumOrders;
    y.BidPrice7 = x.BidPrice7;
    y.BidVolume7 = x.BidVolume7;
    y.Bid7NumOrders = x.Bid7NumOrders;
    y.AskPrice8 = x.AskPrice8;
    y.AskVolume8 = x.AskVolume8;
    y.Ask8NumOrders = x.Ask8NumOrders;
    y.AskPrice9 = x.AskPrice9;
    y.AskVolume9 = x.AskVolume9;
    y.Ask9NumOrders = x.Ask9NumOrders;
    y.BidPrice8 = x.BidPrice8;
    y.BidVolume8 = x.BidVolume8;
    y.Bid8NumOrders = x.Bid8NumOrders;
    y.BidPrice9 = x.BidPrice9;
    y.BidVolume9 = x.BidVolume9;
    y.Bid9NumOrders = x.Bid9NumOrders;
    y.BidPrice10 = x.BidPrice10;
    y.BidVolume10 = x.BidVolume10;
    y.Bid10NumOrders = x.Bid10NumOrders;
    y.AskPrice10 = x.AskPrice10;
    y.AskVolume10 = x.AskVolume10;
    y.Ask10NumOrders = x.Ask10NumOrders;
    y.ClosePrice = x.ClosePrice;
    y.MDSecurityStat = x.MDSecurityStat;
    y.TotalBidNumber = x.TotalBidNumber;
    y.TotalOfferNumber = x.TotalOfferNumber;
    y.BidTradeMaxDuration = x.BidTradeMaxDuration;
    y.OfferTradeMaxDuration = x.OfferTradeMaxDuration;
    y.WithdrawBuyNumber = x.WithdrawBuyNumber;
    y.WithdrawBuyAmount = x.WithdrawBuyAmount;
    y.WithdrawBuyMoney = x.WithdrawBuyMoney;
    y.WithdrawSellNumber = x.WithdrawSellNumber;
    y.WithdrawSellAmount = x.WithdrawSellAmount;
    y.WithdrawSellMoney = x.WithdrawSellMoney;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    return y;
}

Lev2XTSMarketDataField Converter::CTORATstpLev2XTSMarketDataFieldToRust(CTORATstpLev2XTSMarketDataField* x) {
    if (x == nullptr)
        return Lev2XTSMarketDataField{.is_null = true};
    Lev2XTSMarketDataField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.DataTimeStamp = x->DataTimeStamp;
    y.PreClosePrice = x->PreClosePrice;
    y.OpenPrice = x->OpenPrice;
    y.NumTrades = x->NumTrades;
    y.TotalVolumeTrade = x->TotalVolumeTrade;
    y.TotalValueTrade = x->TotalValueTrade;
    y.TotalBidVolume = x->TotalBidVolume;
    y.AvgBidPrice = x->AvgBidPrice;
    y.TotalAskVolume = x->TotalAskVolume;
    y.AvgAskPrice = x->AvgAskPrice;
    y.HighestPrice = x->HighestPrice;
    y.LowestPrice = x->LowestPrice;
    y.LastPrice = x->LastPrice;
    y.BidPrice1 = x->BidPrice1;
    y.BidVolume1 = x->BidVolume1;
    y.Bid1NumOrders = x->Bid1NumOrders;
    y.AskPrice1 = x->AskPrice1;
    y.AskVolume1 = x->AskVolume1;
    y.Ask1NumOrders = x->Ask1NumOrders;
    y.AskPrice2 = x->AskPrice2;
    y.AskVolume2 = x->AskVolume2;
    y.Ask2NumOrders = x->Ask2NumOrders;
    y.AskPrice3 = x->AskPrice3;
    y.AskVolume3 = x->AskVolume3;
    y.Ask3NumOrders = x->Ask3NumOrders;
    y.BidPrice2 = x->BidPrice2;
    y.BidVolume2 = x->BidVolume2;
    y.Bid2NumOrders = x->Bid2NumOrders;
    y.BidPrice3 = x->BidPrice3;
    y.BidVolume3 = x->BidVolume3;
    y.Bid3NumOrders = x->Bid3NumOrders;
    y.AskPrice4 = x->AskPrice4;
    y.AskVolume4 = x->AskVolume4;
    y.Ask4NumOrders = x->Ask4NumOrders;
    y.AskPrice5 = x->AskPrice5;
    y.AskVolume5 = x->AskVolume5;
    y.Ask5NumOrders = x->Ask5NumOrders;
    y.BidPrice4 = x->BidPrice4;
    y.BidVolume4 = x->BidVolume4;
    y.Bid4NumOrders = x->Bid4NumOrders;
    y.BidPrice5 = x->BidPrice5;
    y.BidVolume5 = x->BidVolume5;
    y.Bid5NumOrders = x->Bid5NumOrders;
    y.AskPrice6 = x->AskPrice6;
    y.AskVolume6 = x->AskVolume6;
    y.Ask6NumOrders = x->Ask6NumOrders;
    y.AskPrice7 = x->AskPrice7;
    y.AskVolume7 = x->AskVolume7;
    y.Ask7NumOrders = x->Ask7NumOrders;
    y.BidPrice6 = x->BidPrice6;
    y.BidVolume6 = x->BidVolume6;
    y.Bid6NumOrders = x->Bid6NumOrders;
    y.BidPrice7 = x->BidPrice7;
    y.BidVolume7 = x->BidVolume7;
    y.Bid7NumOrders = x->Bid7NumOrders;
    y.AskPrice8 = x->AskPrice8;
    y.AskVolume8 = x->AskVolume8;
    y.Ask8NumOrders = x->Ask8NumOrders;
    y.AskPrice9 = x->AskPrice9;
    y.AskVolume9 = x->AskVolume9;
    y.Ask9NumOrders = x->Ask9NumOrders;
    y.BidPrice8 = x->BidPrice8;
    y.BidVolume8 = x->BidVolume8;
    y.Bid8NumOrders = x->Bid8NumOrders;
    y.BidPrice9 = x->BidPrice9;
    y.BidVolume9 = x->BidVolume9;
    y.Bid9NumOrders = x->Bid9NumOrders;
    y.BidPrice10 = x->BidPrice10;
    y.BidVolume10 = x->BidVolume10;
    y.Bid10NumOrders = x->Bid10NumOrders;
    y.AskPrice10 = x->AskPrice10;
    y.AskVolume10 = x->AskVolume10;
    y.Ask10NumOrders = x->Ask10NumOrders;
    y.ClosePrice = x->ClosePrice;
    y.MDSecurityStat = x->MDSecurityStat;
    y.TotalBidNumber = x->TotalBidNumber;
    y.TotalOfferNumber = x->TotalOfferNumber;
    y.BidTradeMaxDuration = x->BidTradeMaxDuration;
    y.OfferTradeMaxDuration = x->OfferTradeMaxDuration;
    y.WithdrawBuyNumber = x->WithdrawBuyNumber;
    y.WithdrawBuyAmount = x->WithdrawBuyAmount;
    y.WithdrawBuyMoney = x->WithdrawBuyMoney;
    y.WithdrawSellNumber = x->WithdrawSellNumber;
    y.WithdrawSellAmount = x->WithdrawSellAmount;
    y.WithdrawSellMoney = x->WithdrawSellMoney;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    return y;
}

CTORATstpLev2XTSTickField Converter::Lev2XTSTickFieldToCpp(Lev2XTSTickField x) {
    CTORATstpLev2XTSTickField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.MainSeq = x.MainSeq;
    y.SubSeq = x.SubSeq;
    y.TickTime = x.TickTime;
    y.TickType = x.TickType;
    y.BuyNo = x.BuyNo;
    y.SellNo = x.SellNo;
    y.Price = x.Price;
    y.Volume = x.Volume;
    y.TradeMoney = x.TradeMoney;
    y.Side = x.Side;
    y.TradeBSFlag = x.TradeBSFlag;
    y.MDSecurityStat = x.MDSecurityStat;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    return y;
}

Lev2XTSTickField Converter::CTORATstpLev2XTSTickFieldToRust(CTORATstpLev2XTSTickField* x) {
    if (x == nullptr)
        return Lev2XTSTickField{.is_null = true};
    Lev2XTSTickField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.MainSeq = x->MainSeq;
    y.SubSeq = x->SubSeq;
    y.TickTime = x->TickTime;
    y.TickType = x->TickType;
    y.BuyNo = x->BuyNo;
    y.SellNo = x->SellNo;
    y.Price = x->Price;
    y.Volume = x->Volume;
    y.TradeMoney = x->TradeMoney;
    y.Side = x->Side;
    y.TradeBSFlag = x->TradeBSFlag;
    y.MDSecurityStat = x->MDSecurityStat;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    return y;
}

CTORATstpLev2NGTSTickField Converter::Lev2NGTSTickFieldToCpp(Lev2NGTSTickField x) {
    CTORATstpLev2NGTSTickField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.MainSeq = x.MainSeq;
    y.SubSeq = x.SubSeq;
    y.TickTime = x.TickTime;
    y.TickType = x.TickType;
    y.BuyNo = x.BuyNo;
    y.SellNo = x.SellNo;
    y.Price = x.Price;
    y.Volume = x.Volume;
    y.TradeMoney = x.TradeMoney;
    y.Side = x.Side;
    y.TradeBSFlag = x.TradeBSFlag;
    y.MDSecurityStat = x.MDSecurityStat;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    return y;
}

Lev2NGTSTickField Converter::CTORATstpLev2NGTSTickFieldToRust(CTORATstpLev2NGTSTickField* x) {
    if (x == nullptr)
        return Lev2NGTSTickField{.is_null = true};
    Lev2NGTSTickField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.MainSeq = x->MainSeq;
    y.SubSeq = x->SubSeq;
    y.TickTime = x->TickTime;
    y.TickType = x->TickType;
    y.BuyNo = x->BuyNo;
    y.SellNo = x->SellNo;
    y.Price = x->Price;
    y.Volume = x->Volume;
    y.TradeMoney = x->TradeMoney;
    y.Side = x->Side;
    y.TradeBSFlag = x->TradeBSFlag;
    y.MDSecurityStat = x->MDSecurityStat;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    return y;
}

CTORATstpLev2BondMarketDataField Converter::Lev2BondMarketDataFieldToCpp(Lev2BondMarketDataField x) {
    CTORATstpLev2BondMarketDataField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.DataTimeStamp = x.DataTimeStamp;
    y.PreClosePrice = x.PreClosePrice;
    y.OpenPrice = x.OpenPrice;
    y.AvgPreClosePrice = x.AvgPreClosePrice;
    y.NumTrades = x.NumTrades;
    y.TotalVolumeTrade = x.TotalVolumeTrade;
    y.TotalValueTrade = x.TotalValueTrade;
    y.AuctionVolumeTrade = x.AuctionVolumeTrade;
    y.AuctionValueTrade = x.AuctionValueTrade;
    y.TotalBidVolume = x.TotalBidVolume;
    y.AvgBidPrice = x.AvgBidPrice;
    y.TotalAskVolume = x.TotalAskVolume;
    y.AvgAskPrice = x.AvgAskPrice;
    y.HighestPrice = x.HighestPrice;
    y.LowestPrice = x.LowestPrice;
    y.LastPrice = x.LastPrice;
    y.AuctionLastPrice = x.AuctionLastPrice;
    y.AvgPrice = x.AvgPrice;
    y.PriceUpDown1 = x.PriceUpDown1;
    y.PriceUpDown2 = x.PriceUpDown2;
    y.ClosePrice = x.ClosePrice;
    y.MDSecurityStat = x.MDSecurityStat;
    y.BidPrice1 = x.BidPrice1;
    y.BidVolume1 = x.BidVolume1;
    y.Bid1NumOrders = x.Bid1NumOrders;
    y.AskPrice1 = x.AskPrice1;
    y.AskVolume1 = x.AskVolume1;
    y.Ask1NumOrders = x.Ask1NumOrders;
    y.AskPrice2 = x.AskPrice2;
    y.AskVolume2 = x.AskVolume2;
    y.Ask2NumOrders = x.Ask2NumOrders;
    y.AskPrice3 = x.AskPrice3;
    y.AskVolume3 = x.AskVolume3;
    y.Ask3NumOrders = x.Ask3NumOrders;
    y.BidPrice2 = x.BidPrice2;
    y.BidVolume2 = x.BidVolume2;
    y.Bid2NumOrders = x.Bid2NumOrders;
    y.BidPrice3 = x.BidPrice3;
    y.BidVolume3 = x.BidVolume3;
    y.Bid3NumOrders = x.Bid3NumOrders;
    y.AskPrice4 = x.AskPrice4;
    y.AskVolume4 = x.AskVolume4;
    y.Ask4NumOrders = x.Ask4NumOrders;
    y.AskPrice5 = x.AskPrice5;
    y.AskVolume5 = x.AskVolume5;
    y.Ask5NumOrders = x.Ask5NumOrders;
    y.BidPrice4 = x.BidPrice4;
    y.BidVolume4 = x.BidVolume4;
    y.Bid4NumOrders = x.Bid4NumOrders;
    y.BidPrice5 = x.BidPrice5;
    y.BidVolume5 = x.BidVolume5;
    y.Bid5NumOrders = x.Bid5NumOrders;
    y.AskPrice6 = x.AskPrice6;
    y.AskVolume6 = x.AskVolume6;
    y.Ask6NumOrders = x.Ask6NumOrders;
    y.AskPrice7 = x.AskPrice7;
    y.AskVolume7 = x.AskVolume7;
    y.Ask7NumOrders = x.Ask7NumOrders;
    y.BidPrice6 = x.BidPrice6;
    y.BidVolume6 = x.BidVolume6;
    y.Bid6NumOrders = x.Bid6NumOrders;
    y.BidPrice7 = x.BidPrice7;
    y.BidVolume7 = x.BidVolume7;
    y.Bid7NumOrders = x.Bid7NumOrders;
    y.AskPrice8 = x.AskPrice8;
    y.AskVolume8 = x.AskVolume8;
    y.Ask8NumOrders = x.Ask8NumOrders;
    y.AskPrice9 = x.AskPrice9;
    y.AskVolume9 = x.AskVolume9;
    y.Ask9NumOrders = x.Ask9NumOrders;
    y.BidPrice8 = x.BidPrice8;
    y.BidVolume8 = x.BidVolume8;
    y.Bid8NumOrders = x.Bid8NumOrders;
    y.BidPrice9 = x.BidPrice9;
    y.BidVolume9 = x.BidVolume9;
    y.Bid9NumOrders = x.Bid9NumOrders;
    y.BidPrice10 = x.BidPrice10;
    y.BidVolume10 = x.BidVolume10;
    y.Bid10NumOrders = x.Bid10NumOrders;
    y.AskPrice10 = x.AskPrice10;
    y.AskVolume10 = x.AskVolume10;
    y.Ask10NumOrders = x.Ask10NumOrders;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    return y;
}

Lev2BondMarketDataField Converter::CTORATstpLev2BondMarketDataFieldToRust(CTORATstpLev2BondMarketDataField* x) {
    if (x == nullptr)
        return Lev2BondMarketDataField{.is_null = true};
    Lev2BondMarketDataField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.DataTimeStamp = x->DataTimeStamp;
    y.PreClosePrice = x->PreClosePrice;
    y.OpenPrice = x->OpenPrice;
    y.AvgPreClosePrice = x->AvgPreClosePrice;
    y.NumTrades = x->NumTrades;
    y.TotalVolumeTrade = x->TotalVolumeTrade;
    y.TotalValueTrade = x->TotalValueTrade;
    y.AuctionVolumeTrade = x->AuctionVolumeTrade;
    y.AuctionValueTrade = x->AuctionValueTrade;
    y.TotalBidVolume = x->TotalBidVolume;
    y.AvgBidPrice = x->AvgBidPrice;
    y.TotalAskVolume = x->TotalAskVolume;
    y.AvgAskPrice = x->AvgAskPrice;
    y.HighestPrice = x->HighestPrice;
    y.LowestPrice = x->LowestPrice;
    y.LastPrice = x->LastPrice;
    y.AuctionLastPrice = x->AuctionLastPrice;
    y.AvgPrice = x->AvgPrice;
    y.PriceUpDown1 = x->PriceUpDown1;
    y.PriceUpDown2 = x->PriceUpDown2;
    y.ClosePrice = x->ClosePrice;
    y.MDSecurityStat = x->MDSecurityStat;
    y.BidPrice1 = x->BidPrice1;
    y.BidVolume1 = x->BidVolume1;
    y.Bid1NumOrders = x->Bid1NumOrders;
    y.AskPrice1 = x->AskPrice1;
    y.AskVolume1 = x->AskVolume1;
    y.Ask1NumOrders = x->Ask1NumOrders;
    y.AskPrice2 = x->AskPrice2;
    y.AskVolume2 = x->AskVolume2;
    y.Ask2NumOrders = x->Ask2NumOrders;
    y.AskPrice3 = x->AskPrice3;
    y.AskVolume3 = x->AskVolume3;
    y.Ask3NumOrders = x->Ask3NumOrders;
    y.BidPrice2 = x->BidPrice2;
    y.BidVolume2 = x->BidVolume2;
    y.Bid2NumOrders = x->Bid2NumOrders;
    y.BidPrice3 = x->BidPrice3;
    y.BidVolume3 = x->BidVolume3;
    y.Bid3NumOrders = x->Bid3NumOrders;
    y.AskPrice4 = x->AskPrice4;
    y.AskVolume4 = x->AskVolume4;
    y.Ask4NumOrders = x->Ask4NumOrders;
    y.AskPrice5 = x->AskPrice5;
    y.AskVolume5 = x->AskVolume5;
    y.Ask5NumOrders = x->Ask5NumOrders;
    y.BidPrice4 = x->BidPrice4;
    y.BidVolume4 = x->BidVolume4;
    y.Bid4NumOrders = x->Bid4NumOrders;
    y.BidPrice5 = x->BidPrice5;
    y.BidVolume5 = x->BidVolume5;
    y.Bid5NumOrders = x->Bid5NumOrders;
    y.AskPrice6 = x->AskPrice6;
    y.AskVolume6 = x->AskVolume6;
    y.Ask6NumOrders = x->Ask6NumOrders;
    y.AskPrice7 = x->AskPrice7;
    y.AskVolume7 = x->AskVolume7;
    y.Ask7NumOrders = x->Ask7NumOrders;
    y.BidPrice6 = x->BidPrice6;
    y.BidVolume6 = x->BidVolume6;
    y.Bid6NumOrders = x->Bid6NumOrders;
    y.BidPrice7 = x->BidPrice7;
    y.BidVolume7 = x->BidVolume7;
    y.Bid7NumOrders = x->Bid7NumOrders;
    y.AskPrice8 = x->AskPrice8;
    y.AskVolume8 = x->AskVolume8;
    y.Ask8NumOrders = x->Ask8NumOrders;
    y.AskPrice9 = x->AskPrice9;
    y.AskVolume9 = x->AskVolume9;
    y.Ask9NumOrders = x->Ask9NumOrders;
    y.BidPrice8 = x->BidPrice8;
    y.BidVolume8 = x->BidVolume8;
    y.Bid8NumOrders = x->Bid8NumOrders;
    y.BidPrice9 = x->BidPrice9;
    y.BidVolume9 = x->BidVolume9;
    y.Bid9NumOrders = x->Bid9NumOrders;
    y.BidPrice10 = x->BidPrice10;
    y.BidVolume10 = x->BidVolume10;
    y.Bid10NumOrders = x->Bid10NumOrders;
    y.AskPrice10 = x->AskPrice10;
    y.AskVolume10 = x->AskVolume10;
    y.Ask10NumOrders = x->Ask10NumOrders;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    return y;
}

CTORATstpLev2BondOrderDetailField Converter::Lev2BondOrderDetailFieldToCpp(Lev2BondOrderDetailField x) {
    CTORATstpLev2BondOrderDetailField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.OrderTime = x.OrderTime;
    y.Price = x.Price;
    y.Volume = x.Volume;
    y.Side = x.Side;
    y.OrderType = x.OrderType;
    y.MainSeq = x.MainSeq;
    y.SubSeq = x.SubSeq;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    return y;
}

Lev2BondOrderDetailField Converter::CTORATstpLev2BondOrderDetailFieldToRust(CTORATstpLev2BondOrderDetailField* x) {
    if (x == nullptr)
        return Lev2BondOrderDetailField{.is_null = true};
    Lev2BondOrderDetailField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.OrderTime = x->OrderTime;
    y.Price = x->Price;
    y.Volume = x->Volume;
    y.Side = x->Side;
    y.OrderType = x->OrderType;
    y.MainSeq = x->MainSeq;
    y.SubSeq = x->SubSeq;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    return y;
}

CTORATstpLev2BondTransactionField Converter::Lev2BondTransactionFieldToCpp(Lev2BondTransactionField x) {
    CTORATstpLev2BondTransactionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.TradeTime = x.TradeTime;
    y.TradePrice = x.TradePrice;
    y.TradeVolume = x.TradeVolume;
    y.ExecType = x.ExecType;
    y.MainSeq = x.MainSeq;
    y.SubSeq = x.SubSeq;
    y.BuyNo = x.BuyNo;
    y.SellNo = x.SellNo;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    return y;
}

Lev2BondTransactionField Converter::CTORATstpLev2BondTransactionFieldToRust(CTORATstpLev2BondTransactionField* x) {
    if (x == nullptr)
        return Lev2BondTransactionField{.is_null = true};
    Lev2BondTransactionField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TradeTime = x->TradeTime;
    y.TradePrice = x->TradePrice;
    y.TradeVolume = x->TradeVolume;
    y.ExecType = x->ExecType;
    y.MainSeq = x->MainSeq;
    y.SubSeq = x->SubSeq;
    y.BuyNo = x->BuyNo;
    y.SellNo = x->SellNo;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    return y;
}

CTORATstpLev2IOPVField Converter::Lev2IOPVFieldToCpp(Lev2IOPVField x) {
    CTORATstpLev2IOPVField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.DataTimeStamp = x.DataTimeStamp;
    y.IOPV = x.IOPV;
    y.MDSecurityStat = x.MDSecurityStat;
    y.Info1 = x.Info1;
    y.Info2 = x.Info2;
    y.Info3 = x.Info3;
    return y;
}

Lev2IOPVField Converter::CTORATstpLev2IOPVFieldToRust(CTORATstpLev2IOPVField* x) {
    if (x == nullptr)
        return Lev2IOPVField{.is_null = true};
    Lev2IOPVField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.DataTimeStamp = x->DataTimeStamp;
    y.IOPV = x->IOPV;
    y.MDSecurityStat = x->MDSecurityStat;
    y.Info1 = x->Info1;
    y.Info2 = x->Info2;
    y.Info3 = x->Info3;
    return y;
}

CTORATstpExIndexField Converter::ExIndexFieldToCpp(ExIndexField x) {
    CTORATstpExIndexField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.DataTimeStamp = x.DataTimeStamp;
    y.PreCloseIndex = x.PreCloseIndex;
    y.OpenIndex = x.OpenIndex;
    y.HighIndex = x.HighIndex;
    y.LowIndex = x.LowIndex;
    y.LastIndex = x.LastIndex;
    y.Turnover = x.Turnover;
    y.TotalVolumeTraded = x.TotalVolumeTraded;
    y.CloseIndex = x.CloseIndex;
    return y;
}

ExIndexField Converter::CTORATstpExIndexFieldToRust(CTORATstpExIndexField* x) {
    if (x == nullptr)
        return ExIndexField{.is_null = true};
    ExIndexField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.DataTimeStamp = x->DataTimeStamp;
    y.PreCloseIndex = x->PreCloseIndex;
    y.OpenIndex = x->OpenIndex;
    y.HighIndex = x->HighIndex;
    y.LowIndex = x->LowIndex;
    y.LastIndex = x->LastIndex;
    y.Turnover = x->Turnover;
    y.TotalVolumeTraded = x->TotalVolumeTraded;
    y.CloseIndex = x->CloseIndex;
    return y;
}

} // namespace tora_lev2md
