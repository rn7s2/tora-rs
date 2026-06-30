#include "tora-rs/wrapper/include/TraderConverter.h"

namespace tora_trader {
using namespace TORASTOCKAPI;

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
    y.UserRequestID = x.UserRequestID;
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
    y.NodeRef = x.NodeRef;
    strcpy(y.GwInnerIPAddress, x.GwInnerIPAddress.c_str());
    strcpy(y.GwOuterIPAddress, x.GwOuterIPAddress.c_str());
    strcpy(y.GwMacAddress, x.GwMacAddress.c_str());
    return y;
}

ReqUserLoginField Converter::CTORATstpReqUserLoginFieldToRust(CTORATstpReqUserLoginField* x) {
    if (x == nullptr)
        return ReqUserLoginField{.is_null = true};
    ReqUserLoginField y{};
    y.UserRequestID = x->UserRequestID;
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
    y.NodeRef = x->NodeRef;
    y.GwInnerIPAddress = Converter::GbkToRustString(x->GwInnerIPAddress);
    y.GwOuterIPAddress = Converter::GbkToRustString(x->GwOuterIPAddress);
    y.GwMacAddress = Converter::GbkToRustString(x->GwMacAddress);
    return y;
}

CTORATstpRspUserLoginField Converter::RspUserLoginFieldToCpp(RspUserLoginField x) {
    CTORATstpRspUserLoginField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
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
    y.NodeRef = x.NodeRef;
    y.TradeCommFlux = x.TradeCommFlux;
    y.QueryCommFlux = x.QueryCommFlux;
    y.OrderCommFlux = x.OrderCommFlux;
    y.MarketCommFlux = x.MarketCommFlux;
    y.MarketSubLimit = x.MarketSubLimit;
    return y;
}

RspUserLoginField Converter::CTORATstpRspUserLoginFieldToRust(CTORATstpRspUserLoginField* x) {
    if (x == nullptr)
        return RspUserLoginField{.is_null = true};
    RspUserLoginField y{};
    y.UserRequestID = x->UserRequestID;
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
    y.NodeRef = x->NodeRef;
    y.TradeCommFlux = x->TradeCommFlux;
    y.QueryCommFlux = x->QueryCommFlux;
    y.OrderCommFlux = x->OrderCommFlux;
    y.MarketCommFlux = x->MarketCommFlux;
    y.MarketSubLimit = x->MarketSubLimit;
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
    y.UserRequestID = x.UserRequestID;
    strcpy(y.UserID, x.UserID.c_str());
    return y;
}

UserLogoutField Converter::CTORATstpUserLogoutFieldToRust(CTORATstpUserLogoutField* x) {
    if (x == nullptr)
        return UserLogoutField{.is_null = true};
    UserLogoutField y{};
    y.UserRequestID = x->UserRequestID;
    y.UserID = Converter::GbkToRustString(x->UserID);
    return y;
}

CTORATstpUserPasswordUpdateField Converter::UserPasswordUpdateFieldToCpp(UserPasswordUpdateField x) {
    CTORATstpUserPasswordUpdateField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.UserID, x.UserID.c_str());
    strcpy(y.OldPassword, x.OldPassword.c_str());
    strcpy(y.NewPassword, x.NewPassword.c_str());
    y.UserRequestID = x.UserRequestID;
    return y;
}

UserPasswordUpdateField Converter::CTORATstpUserPasswordUpdateFieldToRust(CTORATstpUserPasswordUpdateField* x) {
    if (x == nullptr)
        return UserPasswordUpdateField{.is_null = true};
    UserPasswordUpdateField y{};
    y.UserID = Converter::GbkToRustString(x->UserID);
    y.OldPassword = Converter::GbkToRustString(x->OldPassword);
    y.NewPassword = Converter::GbkToRustString(x->NewPassword);
    y.UserRequestID = x->UserRequestID;
    return y;
}

CTORATstpReqInputDeviceSerialField Converter::ReqInputDeviceSerialFieldToCpp(ReqInputDeviceSerialField x) {
    CTORATstpReqInputDeviceSerialField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    strcpy(y.UserID, x.UserID.c_str());
    strcpy(y.DeviceID, x.DeviceID.c_str());
    strcpy(y.CertSerial, x.CertSerial.c_str());
    y.DeviceType = x.DeviceType;
    return y;
}

ReqInputDeviceSerialField Converter::CTORATstpReqInputDeviceSerialFieldToRust(CTORATstpReqInputDeviceSerialField* x) {
    if (x == nullptr)
        return ReqInputDeviceSerialField{.is_null = true};
    ReqInputDeviceSerialField y{};
    y.UserRequestID = x->UserRequestID;
    y.UserID = Converter::GbkToRustString(x->UserID);
    y.DeviceID = Converter::GbkToRustString(x->DeviceID);
    y.CertSerial = Converter::GbkToRustString(x->CertSerial);
    y.DeviceType = x->DeviceType;
    return y;
}

CTORATstpRspInputDeviceSerialField Converter::RspInputDeviceSerialFieldToCpp(RspInputDeviceSerialField x) {
    CTORATstpRspInputDeviceSerialField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    strcpy(y.UserID, x.UserID.c_str());
    return y;
}

RspInputDeviceSerialField Converter::CTORATstpRspInputDeviceSerialFieldToRust(CTORATstpRspInputDeviceSerialField* x) {
    if (x == nullptr)
        return RspInputDeviceSerialField{.is_null = true};
    RspInputDeviceSerialField y{};
    y.UserRequestID = x->UserRequestID;
    y.UserID = Converter::GbkToRustString(x->UserID);
    return y;
}

CTORATstpInputOrderField Converter::InputOrderFieldToCpp(InputOrderField x) {
    CTORATstpInputOrderField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.Direction = x.Direction;
    y.LimitPrice = x.LimitPrice;
    y.VolumeTotalOriginal = x.VolumeTotalOriginal;
    y.OrderPriceType = x.OrderPriceType;
    y.TimeCondition = x.TimeCondition;
    y.VolumeCondition = x.VolumeCondition;
    y.Operway = x.Operway;
    y.OrderRef = x.OrderRef;
    y.LotType = x.LotType;
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    y.CondCheck = x.CondCheck;
    strcpy(y.GTDate, x.GTDate.c_str());
    y.ForceCloseReason = x.ForceCloseReason;
    strcpy(y.CreditDebtID, x.CreditDebtID.c_str());
    y.CreditQuotaType = x.CreditQuotaType;
    y.DiscountCouponID = x.DiscountCouponID;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

InputOrderField Converter::CTORATstpInputOrderFieldToRust(CTORATstpInputOrderField* x) {
    if (x == nullptr)
        return InputOrderField{.is_null = true};
    InputOrderField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.Direction = x->Direction;
    y.LimitPrice = x->LimitPrice;
    y.VolumeTotalOriginal = x->VolumeTotalOriginal;
    y.OrderPriceType = x->OrderPriceType;
    y.TimeCondition = x->TimeCondition;
    y.VolumeCondition = x->VolumeCondition;
    y.Operway = x->Operway;
    y.OrderRef = x->OrderRef;
    y.LotType = x->LotType;
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.CondCheck = x->CondCheck;
    y.GTDate = Converter::GbkToRustString(x->GTDate);
    y.ForceCloseReason = x->ForceCloseReason;
    y.CreditDebtID = Converter::GbkToRustString(x->CreditDebtID);
    y.CreditQuotaType = x->CreditQuotaType;
    y.DiscountCouponID = x->DiscountCouponID;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpOrderField Converter::OrderFieldToCpp(OrderField x) {
    CTORATstpOrderField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.Direction = x.Direction;
    y.OrderPriceType = x.OrderPriceType;
    y.TimeCondition = x.TimeCondition;
    y.VolumeCondition = x.VolumeCondition;
    y.LimitPrice = x.LimitPrice;
    y.VolumeTotalOriginal = x.VolumeTotalOriginal;
    y.LotType = x.LotType;
    strcpy(y.GTDate, x.GTDate.c_str());
    y.Operway = x.Operway;
    y.CondCheck = x.CondCheck;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    y.RequestID = x.RequestID;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.OrderRef = x.OrderRef;
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    y.OrderStatus = x.OrderStatus;
    y.OrderSubmitStatus = x.OrderSubmitStatus;
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    y.VolumeTraded = x.VolumeTraded;
    y.VolumeCanceled = x.VolumeCanceled;
    strcpy(y.TradingDay, x.TradingDay.c_str());
    memcpy(y.InsertUser, x.InsertUser.data(), x.InsertUser.size() * sizeof(uint8_t));
    strcpy(y.InsertDate, x.InsertDate.c_str());
    strcpy(y.InsertTime, x.InsertTime.c_str());
    strcpy(y.AcceptTime, x.AcceptTime.c_str());
    memcpy(y.CancelUser, x.CancelUser.data(), x.CancelUser.size() * sizeof(uint8_t));
    strcpy(y.CancelTime, x.CancelTime.c_str());
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    strcpy(y.PbuID, x.PbuID.c_str());
    y.Turnover = x.Turnover;
    y.OrderType = x.OrderType;
    strcpy(y.UserProductInfo, x.UserProductInfo.c_str());
    y.ForceCloseReason = x.ForceCloseReason;
    strcpy(y.CreditQuotaID, x.CreditQuotaID.c_str());
    y.CreditQuotaType = x.CreditQuotaType;
    strcpy(y.CreditDebtID, x.CreditDebtID.c_str());
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    y.RtnFloatInfo = x.RtnFloatInfo;
    y.RtnIntInfo = x.RtnIntInfo;
    y.RtnFloatInfo1 = x.RtnFloatInfo1;
    y.RtnFloatInfo2 = x.RtnFloatInfo2;
    y.RtnFloatInfo3 = x.RtnFloatInfo3;
    y.AcceptTimeStamp = x.AcceptTimeStamp;
    return y;
}

OrderField Converter::CTORATstpOrderFieldToRust(CTORATstpOrderField* x) {
    if (x == nullptr)
        return OrderField{.is_null = true};
    OrderField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.Direction = x->Direction;
    y.OrderPriceType = x->OrderPriceType;
    y.TimeCondition = x->TimeCondition;
    y.VolumeCondition = x->VolumeCondition;
    y.LimitPrice = x->LimitPrice;
    y.VolumeTotalOriginal = x->VolumeTotalOriginal;
    y.LotType = x->LotType;
    y.GTDate = Converter::GbkToRustString(x->GTDate);
    y.Operway = x->Operway;
    y.CondCheck = x->CondCheck;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.RequestID = x->RequestID;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.OrderRef = x->OrderRef;
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.OrderStatus = x->OrderStatus;
    y.OrderSubmitStatus = x->OrderSubmitStatus;
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    y.VolumeTraded = x->VolumeTraded;
    y.VolumeCanceled = x->VolumeCanceled;
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    for (int i = 0; i < 16; i++)
        y.InsertUser.push_back(x->InsertUser[i]);
    y.InsertDate = Converter::GbkToRustString(x->InsertDate);
    y.InsertTime = Converter::GbkToRustString(x->InsertTime);
    y.AcceptTime = Converter::GbkToRustString(x->AcceptTime);
    for (int i = 0; i < 16; i++)
        y.CancelUser.push_back(x->CancelUser[i]);
    y.CancelTime = Converter::GbkToRustString(x->CancelTime);
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.PbuID = Converter::GbkToRustString(x->PbuID);
    y.Turnover = x->Turnover;
    y.OrderType = x->OrderType;
    y.UserProductInfo = Converter::GbkToRustString(x->UserProductInfo);
    y.ForceCloseReason = x->ForceCloseReason;
    y.CreditQuotaID = Converter::GbkToRustString(x->CreditQuotaID);
    y.CreditQuotaType = x->CreditQuotaType;
    y.CreditDebtID = Converter::GbkToRustString(x->CreditDebtID);
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    y.RtnFloatInfo = x->RtnFloatInfo;
    y.RtnIntInfo = x->RtnIntInfo;
    y.RtnFloatInfo1 = x->RtnFloatInfo1;
    y.RtnFloatInfo2 = x->RtnFloatInfo2;
    y.RtnFloatInfo3 = x->RtnFloatInfo3;
    y.AcceptTimeStamp = x->AcceptTimeStamp;
    return y;
}

CTORATstpUserRefField Converter::UserRefFieldToCpp(UserRefField x) {
    CTORATstpUserRefField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.UserID, x.UserID.c_str());
    return y;
}

UserRefField Converter::CTORATstpUserRefFieldToRust(CTORATstpUserRefField* x) {
    if (x == nullptr)
        return UserRefField{.is_null = true};
    UserRefField y{};
    y.UserID = Converter::GbkToRustString(x->UserID);
    return y;
}

CTORATstpTradeField Converter::TradeFieldToCpp(TradeField x) {
    CTORATstpTradeField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.TradeID, x.TradeID.c_str());
    y.Direction = x.Direction;
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    y.Price = x.Price;
    y.Volume = x.Volume;
    strcpy(y.TradeDate, x.TradeDate.c_str());
    strcpy(y.TradeTime, x.TradeTime.c_str());
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.PbuID, x.PbuID.c_str());
    y.OrderRef = x.OrderRef;
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    return y;
}

TradeField Converter::CTORATstpTradeFieldToRust(CTORATstpTradeField* x) {
    if (x == nullptr)
        return TradeField{.is_null = true};
    TradeField y{};
    y.ExchangeID = x->ExchangeID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TradeID = Converter::GbkToRustString(x->TradeID);
    y.Direction = x->Direction;
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.Price = x->Price;
    y.Volume = x->Volume;
    y.TradeDate = Converter::GbkToRustString(x->TradeDate);
    y.TradeTime = Converter::GbkToRustString(x->TradeTime);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.PbuID = Converter::GbkToRustString(x->PbuID);
    y.OrderRef = x->OrderRef;
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    return y;
}

CTORATstpInputOrderActionField Converter::InputOrderActionFieldToCpp(InputOrderActionField x) {
    CTORATstpInputOrderActionField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.OrderRef = x.OrderRef;
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    y.ActionFlag = x.ActionFlag;
    y.OrderActionRef = x.OrderActionRef;
    strcpy(y.CancelOrderSysID, x.CancelOrderSysID.c_str());
    y.Operway = x.Operway;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

InputOrderActionField Converter::CTORATstpInputOrderActionFieldToRust(CTORATstpInputOrderActionField* x) {
    if (x == nullptr)
        return InputOrderActionField{.is_null = true};
    InputOrderActionField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.OrderRef = x->OrderRef;
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.ActionFlag = x->ActionFlag;
    y.OrderActionRef = x->OrderActionRef;
    y.CancelOrderSysID = Converter::GbkToRustString(x->CancelOrderSysID);
    y.Operway = x->Operway;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpInputCondOrderField Converter::InputCondOrderFieldToCpp(InputCondOrderField x) {
    CTORATstpInputCondOrderField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.Direction = x.Direction;
    y.OrderPriceType = x.OrderPriceType;
    y.TimeCondition = x.TimeCondition;
    y.VolumeCondition = x.VolumeCondition;
    y.LimitPrice = x.LimitPrice;
    y.VolumeTotalOriginal = x.VolumeTotalOriginal;
    y.Operway = x.Operway;
    y.LotType = x.LotType;
    y.CondCheck = x.CondCheck;
    strcpy(y.GTDate, x.GTDate.c_str());
    y.ForceCloseReason = x.ForceCloseReason;
    strcpy(y.CreditDebtID, x.CreditDebtID.c_str());
    y.CreditQuotaType = x.CreditQuotaType;
    y.DiscountCouponID = x.DiscountCouponID;
    y.CondOrderRef = x.CondOrderRef;
    y.CondOrderID = x.CondOrderID;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    y.TriggerOrderVolumeType = x.TriggerOrderVolumeType;
    y.TriggerOrderPriceType = x.TriggerOrderPriceType;
    y.ContingentCondition = x.ContingentCondition;
    y.ConditionPrice = x.ConditionPrice;
    y.PriceTicks = x.PriceTicks;
    y.VolumeMultiple = x.VolumeMultiple;
    y.RelativeFrontID = x.RelativeFrontID;
    y.RelativeSessionID = x.RelativeSessionID;
    memcpy(y.RelativeParam, x.RelativeParam.data(), x.RelativeParam.size() * sizeof(uint8_t));
    y.AppendContingentCondition = x.AppendContingentCondition;
    y.AppendConditionPrice = x.AppendConditionPrice;
    y.AppendRelativeFrontID = x.AppendRelativeFrontID;
    y.AppendRelativeSessionID = x.AppendRelativeSessionID;
    memcpy(y.AppendRelativeParam, x.AppendRelativeParam.data(), x.AppendRelativeParam.size() * sizeof(uint8_t));
    return y;
}

InputCondOrderField Converter::CTORATstpInputCondOrderFieldToRust(CTORATstpInputCondOrderField* x) {
    if (x == nullptr)
        return InputCondOrderField{.is_null = true};
    InputCondOrderField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.Direction = x->Direction;
    y.OrderPriceType = x->OrderPriceType;
    y.TimeCondition = x->TimeCondition;
    y.VolumeCondition = x->VolumeCondition;
    y.LimitPrice = x->LimitPrice;
    y.VolumeTotalOriginal = x->VolumeTotalOriginal;
    y.Operway = x->Operway;
    y.LotType = x->LotType;
    y.CondCheck = x->CondCheck;
    y.GTDate = Converter::GbkToRustString(x->GTDate);
    y.ForceCloseReason = x->ForceCloseReason;
    y.CreditDebtID = Converter::GbkToRustString(x->CreditDebtID);
    y.CreditQuotaType = x->CreditQuotaType;
    y.DiscountCouponID = x->DiscountCouponID;
    y.CondOrderRef = x->CondOrderRef;
    y.CondOrderID = x->CondOrderID;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.TriggerOrderVolumeType = x->TriggerOrderVolumeType;
    y.TriggerOrderPriceType = x->TriggerOrderPriceType;
    y.ContingentCondition = x->ContingentCondition;
    y.ConditionPrice = x->ConditionPrice;
    y.PriceTicks = x->PriceTicks;
    y.VolumeMultiple = x->VolumeMultiple;
    y.RelativeFrontID = x->RelativeFrontID;
    y.RelativeSessionID = x->RelativeSessionID;
    for (int i = 0; i < 31; i++)
        y.RelativeParam.push_back(x->RelativeParam[i]);
    y.AppendContingentCondition = x->AppendContingentCondition;
    y.AppendConditionPrice = x->AppendConditionPrice;
    y.AppendRelativeFrontID = x->AppendRelativeFrontID;
    y.AppendRelativeSessionID = x->AppendRelativeSessionID;
    for (int i = 0; i < 31; i++)
        y.AppendRelativeParam.push_back(x->AppendRelativeParam[i]);
    return y;
}

CTORATstpConditionOrderField Converter::ConditionOrderFieldToCpp(ConditionOrderField x) {
    CTORATstpConditionOrderField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.Direction = x.Direction;
    y.OrderPriceType = x.OrderPriceType;
    y.TimeCondition = x.TimeCondition;
    y.VolumeCondition = x.VolumeCondition;
    y.LimitPrice = x.LimitPrice;
    y.VolumeTotalOriginal = x.VolumeTotalOriginal;
    y.Operway = x.Operway;
    y.LotType = x.LotType;
    y.CondCheck = x.CondCheck;
    strcpy(y.GTDate, x.GTDate.c_str());
    y.ForceCloseReason = x.ForceCloseReason;
    strcpy(y.CreditDebtID, x.CreditDebtID.c_str());
    y.CreditQuotaType = x.CreditQuotaType;
    y.DiscountCouponID = x.DiscountCouponID;
    y.CondOrderRef = x.CondOrderRef;
    y.CondOrderID = x.CondOrderID;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    y.TriggerOrderVolumeType = x.TriggerOrderVolumeType;
    y.TriggerOrderPriceType = x.TriggerOrderPriceType;
    y.ContingentCondition = x.ContingentCondition;
    y.ConditionPrice = x.ConditionPrice;
    y.PriceTicks = x.PriceTicks;
    y.VolumeMultiple = x.VolumeMultiple;
    y.RelativeFrontID = x.RelativeFrontID;
    y.RelativeSessionID = x.RelativeSessionID;
    memcpy(y.RelativeParam, x.RelativeParam.data(), x.RelativeParam.size() * sizeof(uint8_t));
    y.AppendContingentCondition = x.AppendContingentCondition;
    y.AppendConditionPrice = x.AppendConditionPrice;
    y.AppendRelativeFrontID = x.AppendRelativeFrontID;
    y.AppendRelativeSessionID = x.AppendRelativeSessionID;
    memcpy(y.AppendRelativeParam, x.AppendRelativeParam.data(), x.AppendRelativeParam.size() * sizeof(uint8_t));
    y.RequestID = x.RequestID;
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.CondOrderStatus = x.CondOrderStatus;
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    memcpy(y.InsertUser, x.InsertUser.data(), x.InsertUser.size() * sizeof(uint8_t));
    strcpy(y.InsertDate, x.InsertDate.c_str());
    strcpy(y.InsertTime, x.InsertTime.c_str());
    strcpy(y.ActiveDate, x.ActiveDate.c_str());
    strcpy(y.ActiveTime, x.ActiveTime.c_str());
    memcpy(y.CancelUser, x.CancelUser.data(), x.CancelUser.size() * sizeof(uint8_t));
    strcpy(y.CancelTime, x.CancelTime.c_str());
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.UserProductInfo, x.UserProductInfo.c_str());
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    return y;
}

ConditionOrderField Converter::CTORATstpConditionOrderFieldToRust(CTORATstpConditionOrderField* x) {
    if (x == nullptr)
        return ConditionOrderField{.is_null = true};
    ConditionOrderField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.Direction = x->Direction;
    y.OrderPriceType = x->OrderPriceType;
    y.TimeCondition = x->TimeCondition;
    y.VolumeCondition = x->VolumeCondition;
    y.LimitPrice = x->LimitPrice;
    y.VolumeTotalOriginal = x->VolumeTotalOriginal;
    y.Operway = x->Operway;
    y.LotType = x->LotType;
    y.CondCheck = x->CondCheck;
    y.GTDate = Converter::GbkToRustString(x->GTDate);
    y.ForceCloseReason = x->ForceCloseReason;
    y.CreditDebtID = Converter::GbkToRustString(x->CreditDebtID);
    y.CreditQuotaType = x->CreditQuotaType;
    y.DiscountCouponID = x->DiscountCouponID;
    y.CondOrderRef = x->CondOrderRef;
    y.CondOrderID = x->CondOrderID;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.TriggerOrderVolumeType = x->TriggerOrderVolumeType;
    y.TriggerOrderPriceType = x->TriggerOrderPriceType;
    y.ContingentCondition = x->ContingentCondition;
    y.ConditionPrice = x->ConditionPrice;
    y.PriceTicks = x->PriceTicks;
    y.VolumeMultiple = x->VolumeMultiple;
    y.RelativeFrontID = x->RelativeFrontID;
    y.RelativeSessionID = x->RelativeSessionID;
    for (int i = 0; i < 31; i++)
        y.RelativeParam.push_back(x->RelativeParam[i]);
    y.AppendContingentCondition = x->AppendContingentCondition;
    y.AppendConditionPrice = x->AppendConditionPrice;
    y.AppendRelativeFrontID = x->AppendRelativeFrontID;
    y.AppendRelativeSessionID = x->AppendRelativeSessionID;
    for (int i = 0; i < 31; i++)
        y.AppendRelativeParam.push_back(x->AppendRelativeParam[i]);
    y.RequestID = x->RequestID;
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.CondOrderStatus = x->CondOrderStatus;
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    for (int i = 0; i < 16; i++)
        y.InsertUser.push_back(x->InsertUser[i]);
    y.InsertDate = Converter::GbkToRustString(x->InsertDate);
    y.InsertTime = Converter::GbkToRustString(x->InsertTime);
    y.ActiveDate = Converter::GbkToRustString(x->ActiveDate);
    y.ActiveTime = Converter::GbkToRustString(x->ActiveTime);
    for (int i = 0; i < 16; i++)
        y.CancelUser.push_back(x->CancelUser[i]);
    y.CancelTime = Converter::GbkToRustString(x->CancelTime);
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.UserProductInfo = Converter::GbkToRustString(x->UserProductInfo);
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    return y;
}

CTORATstpInputCondOrderActionField Converter::InputCondOrderActionFieldToCpp(InputCondOrderActionField x) {
    CTORATstpInputCondOrderActionField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.CondOrderRef = x.CondOrderRef;
    y.CondOrderID = x.CondOrderID;
    y.ActionFlag = x.ActionFlag;
    y.Operway = x.Operway;
    y.CondOrderActionRef = x.CondOrderActionRef;
    y.CancelCondOrderID = x.CancelCondOrderID;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

InputCondOrderActionField Converter::CTORATstpInputCondOrderActionFieldToRust(CTORATstpInputCondOrderActionField* x) {
    if (x == nullptr)
        return InputCondOrderActionField{.is_null = true};
    InputCondOrderActionField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.CondOrderRef = x->CondOrderRef;
    y.CondOrderID = x->CondOrderID;
    y.ActionFlag = x->ActionFlag;
    y.Operway = x->Operway;
    y.CondOrderActionRef = x->CondOrderActionRef;
    y.CancelCondOrderID = x->CancelCondOrderID;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpInputNegoOrderField Converter::InputNegoOrderFieldToCpp(InputNegoOrderField x) {
    CTORATstpInputNegoOrderField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.Direction = x.Direction;
    y.LimitPrice = x.LimitPrice;
    y.VolumeTotalOriginal = x.VolumeTotalOriginal;
    memcpy(y.Contractor, x.Contractor.data(), x.Contractor.size() * sizeof(uint8_t));
    strcpy(y.ContractorInfo, x.ContractorInfo.c_str());
    strcpy(y.ConfirmID, x.ConfirmID.c_str());
    strcpy(y.CounterpartyPbuID, x.CounterpartyPbuID.c_str());
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    y.Operway = x.Operway;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

InputNegoOrderField Converter::CTORATstpInputNegoOrderFieldToRust(CTORATstpInputNegoOrderField* x) {
    if (x == nullptr)
        return InputNegoOrderField{.is_null = true};
    InputNegoOrderField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.Direction = x->Direction;
    y.LimitPrice = x->LimitPrice;
    y.VolumeTotalOriginal = x->VolumeTotalOriginal;
    for (int i = 0; i < 17; i++)
        y.Contractor.push_back(x->Contractor[i]);
    y.ContractorInfo = Converter::GbkToRustString(x->ContractorInfo);
    y.ConfirmID = Converter::GbkToRustString(x->ConfirmID);
    y.CounterpartyPbuID = Converter::GbkToRustString(x->CounterpartyPbuID);
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.Operway = x->Operway;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpNegoOrderField Converter::NegoOrderFieldToCpp(NegoOrderField x) {
    CTORATstpNegoOrderField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.Direction = x.Direction;
    y.LimitPrice = x.LimitPrice;
    y.VolumeTotalOriginal = x.VolumeTotalOriginal;
    memcpy(y.Contractor, x.Contractor.data(), x.Contractor.size() * sizeof(uint8_t));
    strcpy(y.ContractorInfo, x.ContractorInfo.c_str());
    strcpy(y.ConfirmID, x.ConfirmID.c_str());
    strcpy(y.CounterpartyPbuID, x.CounterpartyPbuID.c_str());
    y.Operway = x.Operway;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    y.RequestID = x.RequestID;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    y.OrderStatus = x.OrderStatus;
    y.OrderSubmitStatus = x.OrderSubmitStatus;
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    y.VolumeTraded = x.VolumeTraded;
    y.VolumeCanceled = x.VolumeCanceled;
    strcpy(y.TradingDay, x.TradingDay.c_str());
    memcpy(y.InsertUser, x.InsertUser.data(), x.InsertUser.size() * sizeof(uint8_t));
    strcpy(y.InsertDate, x.InsertDate.c_str());
    strcpy(y.InsertTime, x.InsertTime.c_str());
    strcpy(y.AcceptTime, x.AcceptTime.c_str());
    memcpy(y.CancelUser, x.CancelUser.data(), x.CancelUser.size() * sizeof(uint8_t));
    strcpy(y.CancelTime, x.CancelTime.c_str());
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    strcpy(y.PbuID, x.PbuID.c_str());
    strcpy(y.UserProductInfo, x.UserProductInfo.c_str());
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    return y;
}

NegoOrderField Converter::CTORATstpNegoOrderFieldToRust(CTORATstpNegoOrderField* x) {
    if (x == nullptr)
        return NegoOrderField{.is_null = true};
    NegoOrderField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.Direction = x->Direction;
    y.LimitPrice = x->LimitPrice;
    y.VolumeTotalOriginal = x->VolumeTotalOriginal;
    for (int i = 0; i < 17; i++)
        y.Contractor.push_back(x->Contractor[i]);
    y.ContractorInfo = Converter::GbkToRustString(x->ContractorInfo);
    y.ConfirmID = Converter::GbkToRustString(x->ConfirmID);
    y.CounterpartyPbuID = Converter::GbkToRustString(x->CounterpartyPbuID);
    y.Operway = x->Operway;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.RequestID = x->RequestID;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.OrderStatus = x->OrderStatus;
    y.OrderSubmitStatus = x->OrderSubmitStatus;
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    y.VolumeTraded = x->VolumeTraded;
    y.VolumeCanceled = x->VolumeCanceled;
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    for (int i = 0; i < 16; i++)
        y.InsertUser.push_back(x->InsertUser[i]);
    y.InsertDate = Converter::GbkToRustString(x->InsertDate);
    y.InsertTime = Converter::GbkToRustString(x->InsertTime);
    y.AcceptTime = Converter::GbkToRustString(x->AcceptTime);
    for (int i = 0; i < 16; i++)
        y.CancelUser.push_back(x->CancelUser[i]);
    y.CancelTime = Converter::GbkToRustString(x->CancelTime);
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.PbuID = Converter::GbkToRustString(x->PbuID);
    y.UserProductInfo = Converter::GbkToRustString(x->UserProductInfo);
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    return y;
}

CTORATstpNegoTradeField Converter::NegoTradeFieldToCpp(NegoTradeField x) {
    CTORATstpNegoTradeField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.TradeID, x.TradeID.c_str());
    y.Direction = x.Direction;
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    y.Price = x.Price;
    y.Volume = x.Volume;
    strcpy(y.TradeDate, x.TradeDate.c_str());
    strcpy(y.TradeTime, x.TradeTime.c_str());
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.PbuID, x.PbuID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    strcpy(y.CounterpartyPbuID, x.CounterpartyPbuID.c_str());
    strcpy(y.CounterpartyShareholderID, x.CounterpartyShareholderID.c_str());
    return y;
}

NegoTradeField Converter::CTORATstpNegoTradeFieldToRust(CTORATstpNegoTradeField* x) {
    if (x == nullptr)
        return NegoTradeField{.is_null = true};
    NegoTradeField y{};
    y.ExchangeID = x->ExchangeID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TradeID = Converter::GbkToRustString(x->TradeID);
    y.Direction = x->Direction;
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.Price = x->Price;
    y.Volume = x->Volume;
    y.TradeDate = Converter::GbkToRustString(x->TradeDate);
    y.TradeTime = Converter::GbkToRustString(x->TradeTime);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.PbuID = Converter::GbkToRustString(x->PbuID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.CounterpartyPbuID = Converter::GbkToRustString(x->CounterpartyPbuID);
    y.CounterpartyShareholderID = Converter::GbkToRustString(x->CounterpartyShareholderID);
    return y;
}

CTORATstpInputNegoOrderActionField Converter::InputNegoOrderActionFieldToCpp(InputNegoOrderActionField x) {
    CTORATstpInputNegoOrderActionField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    y.ActionFlag = x.ActionFlag;
    strcpy(y.CancelOrderSysID, x.CancelOrderSysID.c_str());
    y.Operway = x.Operway;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

InputNegoOrderActionField Converter::CTORATstpInputNegoOrderActionFieldToRust(CTORATstpInputNegoOrderActionField* x) {
    if (x == nullptr)
        return InputNegoOrderActionField{.is_null = true};
    InputNegoOrderActionField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.ActionFlag = x->ActionFlag;
    y.CancelOrderSysID = Converter::GbkToRustString(x->CancelOrderSysID);
    y.Operway = x->Operway;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpInputOrderExField Converter::InputOrderExFieldToCpp(InputOrderExField x) {
    CTORATstpInputOrderExField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.Direction = x.Direction;
    y.LimitPrice = x.LimitPrice;
    y.VolumeTotalOriginal = x.VolumeTotalOriginal;
    y.OrderPriceType = x.OrderPriceType;
    y.TimeCondition = x.TimeCondition;
    y.VolumeCondition = x.VolumeCondition;
    y.Operway = x.Operway;
    y.OrderRef = x.OrderRef;
    y.LotType = x.LotType;
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    y.CondCheck = x.CondCheck;
    strcpy(y.GTDate, x.GTDate.c_str());
    y.ForceCloseReason = x.ForceCloseReason;
    strcpy(y.CreditDebtID, x.CreditDebtID.c_str());
    y.CreditQuotaType = x.CreditQuotaType;
    y.DiscountCouponID = x.DiscountCouponID;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    y.NodeRef = x.NodeRef;
    return y;
}

InputOrderExField Converter::CTORATstpInputOrderExFieldToRust(CTORATstpInputOrderExField* x) {
    if (x == nullptr)
        return InputOrderExField{.is_null = true};
    InputOrderExField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.Direction = x->Direction;
    y.LimitPrice = x->LimitPrice;
    y.VolumeTotalOriginal = x->VolumeTotalOriginal;
    y.OrderPriceType = x->OrderPriceType;
    y.TimeCondition = x->TimeCondition;
    y.VolumeCondition = x->VolumeCondition;
    y.Operway = x->Operway;
    y.OrderRef = x->OrderRef;
    y.LotType = x->LotType;
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.CondCheck = x->CondCheck;
    y.GTDate = Converter::GbkToRustString(x->GTDate);
    y.ForceCloseReason = x->ForceCloseReason;
    y.CreditDebtID = Converter::GbkToRustString(x->CreditDebtID);
    y.CreditQuotaType = x->CreditQuotaType;
    y.DiscountCouponID = x->DiscountCouponID;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.NodeRef = x->NodeRef;
    return y;
}

CTORATstpInputOrderActionExField Converter::InputOrderActionExFieldToCpp(InputOrderActionExField x) {
    CTORATstpInputOrderActionExField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.OrderRef = x.OrderRef;
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    y.ActionFlag = x.ActionFlag;
    y.OrderActionRef = x.OrderActionRef;
    strcpy(y.CancelOrderSysID, x.CancelOrderSysID.c_str());
    y.Operway = x.Operway;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

InputOrderActionExField Converter::CTORATstpInputOrderActionExFieldToRust(CTORATstpInputOrderActionExField* x) {
    if (x == nullptr)
        return InputOrderActionExField{.is_null = true};
    InputOrderActionExField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.OrderRef = x->OrderRef;
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.ActionFlag = x->ActionFlag;
    y.OrderActionRef = x->OrderActionRef;
    y.CancelOrderSysID = Converter::GbkToRustString(x->CancelOrderSysID);
    y.Operway = x->Operway;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
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

CTORATstpInputTransferFundField Converter::InputTransferFundFieldToCpp(InputTransferFundField x) {
    CTORATstpInputTransferFundField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.ApplySerial = x.ApplySerial;
    y.TransferDirection = x.TransferDirection;
    y.Amount = x.Amount;
    y.BankID = x.BankID;
    strcpy(y.AccountPassword, x.AccountPassword.c_str());
    strcpy(y.BankPassword, x.BankPassword.c_str());
    y.ExternalNodeID = x.ExternalNodeID;
    strcpy(y.CreditDebtID, x.CreditDebtID.c_str());
    y.ForceCloseReason = x.ForceCloseReason;
    y.RealAmount = x.RealAmount;
    y.ForceFlag = x.ForceFlag;
    return y;
}

InputTransferFundField Converter::CTORATstpInputTransferFundFieldToRust(CTORATstpInputTransferFundField* x) {
    if (x == nullptr)
        return InputTransferFundField{.is_null = true};
    InputTransferFundField y{};
    y.UserRequestID = x->UserRequestID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.ApplySerial = x->ApplySerial;
    y.TransferDirection = x->TransferDirection;
    y.Amount = x->Amount;
    y.BankID = x->BankID;
    y.AccountPassword = Converter::GbkToRustString(x->AccountPassword);
    y.BankPassword = Converter::GbkToRustString(x->BankPassword);
    y.ExternalNodeID = x->ExternalNodeID;
    y.CreditDebtID = Converter::GbkToRustString(x->CreditDebtID);
    y.ForceCloseReason = x->ForceCloseReason;
    y.RealAmount = x->RealAmount;
    y.ForceFlag = x->ForceFlag;
    return y;
}

CTORATstpTransferFundField Converter::TransferFundFieldToCpp(TransferFundField x) {
    CTORATstpTransferFundField y;
    memset(&y, 0, sizeof(y));
    y.FundSerial = x.FundSerial;
    y.ApplySerial = x.ApplySerial;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.TransferDirection = x.TransferDirection;
    y.Amount = x.Amount;
    y.TransferStatus = x.TransferStatus;
    strcpy(y.OperatorID, x.OperatorID.c_str());
    strcpy(y.OperateDate, x.OperateDate.c_str());
    strcpy(y.OperateTime, x.OperateTime.c_str());
    strcpy(y.BankAccountID, x.BankAccountID.c_str());
    y.BankID = x.BankID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.ExternalNodeID = x.ExternalNodeID;
    y.ForceCloseReason = x.ForceCloseReason;
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    return y;
}

TransferFundField Converter::CTORATstpTransferFundFieldToRust(CTORATstpTransferFundField* x) {
    if (x == nullptr)
        return TransferFundField{.is_null = true};
    TransferFundField y{};
    y.FundSerial = x->FundSerial;
    y.ApplySerial = x->ApplySerial;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.TransferDirection = x->TransferDirection;
    y.Amount = x->Amount;
    y.TransferStatus = x->TransferStatus;
    y.OperatorID = Converter::GbkToRustString(x->OperatorID);
    y.OperateDate = Converter::GbkToRustString(x->OperateDate);
    y.OperateTime = Converter::GbkToRustString(x->OperateTime);
    y.BankAccountID = Converter::GbkToRustString(x->BankAccountID);
    y.BankID = x->BankID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExternalNodeID = x->ExternalNodeID;
    y.ForceCloseReason = x->ForceCloseReason;
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    return y;
}

CTORATstpInputTransferPositionField Converter::InputTransferPositionFieldToCpp(InputTransferPositionField x) {
    CTORATstpInputTransferPositionField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ApplySerial = x.ApplySerial;
    y.TransferDirection = x.TransferDirection;
    y.Volume = x.Volume;
    y.TransferPositionType = x.TransferPositionType;
    y.UserRequestID = x.UserRequestID;
    y.MarketID = x.MarketID;
    y.ExternalNodeID = x.ExternalNodeID;
    return y;
}

InputTransferPositionField Converter::CTORATstpInputTransferPositionFieldToRust(CTORATstpInputTransferPositionField* x) {
    if (x == nullptr)
        return InputTransferPositionField{.is_null = true};
    InputTransferPositionField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ApplySerial = x->ApplySerial;
    y.TransferDirection = x->TransferDirection;
    y.Volume = x->Volume;
    y.TransferPositionType = x->TransferPositionType;
    y.UserRequestID = x->UserRequestID;
    y.MarketID = x->MarketID;
    y.ExternalNodeID = x->ExternalNodeID;
    return y;
}

CTORATstpTransferPositionField Converter::TransferPositionFieldToCpp(TransferPositionField x) {
    CTORATstpTransferPositionField y;
    memset(&y, 0, sizeof(y));
    y.PositionSerial = x.PositionSerial;
    y.ApplySerial = x.ApplySerial;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.MarketID = x.MarketID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.TransferDirection = x.TransferDirection;
    y.TransferPositionType = x.TransferPositionType;
    y.HistoryVolume = x.HistoryVolume;
    y.TodayBSVolume = x.TodayBSVolume;
    y.TodayPRVolume = x.TodayPRVolume;
    y.TodaySMVolume = x.TodaySMVolume;
    y.TransferStatus = x.TransferStatus;
    strcpy(y.OperatorID, x.OperatorID.c_str());
    strcpy(y.OperateDate, x.OperateDate.c_str());
    strcpy(y.OperateTime, x.OperateTime.c_str());
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    y.ExternalNodeID = x.ExternalNodeID;
    return y;
}

TransferPositionField Converter::CTORATstpTransferPositionFieldToRust(CTORATstpTransferPositionField* x) {
    if (x == nullptr)
        return TransferPositionField{.is_null = true};
    TransferPositionField y{};
    y.PositionSerial = x->PositionSerial;
    y.ApplySerial = x->ApplySerial;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.MarketID = x->MarketID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.TransferDirection = x->TransferDirection;
    y.TransferPositionType = x->TransferPositionType;
    y.HistoryVolume = x->HistoryVolume;
    y.TodayBSVolume = x->TodayBSVolume;
    y.TodayPRVolume = x->TodayPRVolume;
    y.TodaySMVolume = x->TodaySMVolume;
    y.TransferStatus = x->TransferStatus;
    y.OperatorID = Converter::GbkToRustString(x->OperatorID);
    y.OperateDate = Converter::GbkToRustString(x->OperateDate);
    y.OperateTime = Converter::GbkToRustString(x->OperateTime);
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    y.ExternalNodeID = x->ExternalNodeID;
    return y;
}

CTORATstpPeripheryTransferPositionField Converter::PeripheryTransferPositionFieldToCpp(PeripheryTransferPositionField x) {
    CTORATstpPeripheryTransferPositionField y;
    memset(&y, 0, sizeof(y));
    y.PositionSerial = x.PositionSerial;
    y.ApplySerial = x.ApplySerial;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.TransferDirection = x.TransferDirection;
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.TodayBSPos = x.TodayBSPos;
    y.TodayPRPos = x.TodayPRPos;
    y.HistoryPos = x.HistoryPos;
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.TransferReason, x.TransferReason.c_str());
    y.TransferStatus = x.TransferStatus;
    strcpy(y.OperateDate, x.OperateDate.c_str());
    strcpy(y.OperateTime, x.OperateTime.c_str());
    strcpy(y.RepealDate, x.RepealDate.c_str());
    strcpy(y.RepealTime, x.RepealTime.c_str());
    strcpy(y.RepealReason, x.RepealReason.c_str());
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    y.TodaySMPos = x.TodaySMPos;
    return y;
}

PeripheryTransferPositionField Converter::CTORATstpPeripheryTransferPositionFieldToRust(CTORATstpPeripheryTransferPositionField* x) {
    if (x == nullptr)
        return PeripheryTransferPositionField{.is_null = true};
    PeripheryTransferPositionField y{};
    y.PositionSerial = x->PositionSerial;
    y.ApplySerial = x->ApplySerial;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.TransferDirection = x->TransferDirection;
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TodayBSPos = x->TodayBSPos;
    y.TodayPRPos = x->TodayPRPos;
    y.HistoryPos = x->HistoryPos;
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.TransferReason = Converter::GbkToRustString(x->TransferReason);
    y.TransferStatus = x->TransferStatus;
    y.OperateDate = Converter::GbkToRustString(x->OperateDate);
    y.OperateTime = Converter::GbkToRustString(x->OperateTime);
    y.RepealDate = Converter::GbkToRustString(x->RepealDate);
    y.RepealTime = Converter::GbkToRustString(x->RepealTime);
    y.RepealReason = Converter::GbkToRustString(x->RepealReason);
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    y.TodaySMPos = x->TodaySMPos;
    return y;
}

CTORATstpPeripheryTransferFundField Converter::PeripheryTransferFundFieldToCpp(PeripheryTransferFundField x) {
    CTORATstpPeripheryTransferFundField y;
    memset(&y, 0, sizeof(y));
    y.FundSerial = x.FundSerial;
    y.ApplySerial = x.ApplySerial;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.TransferDirection = x.TransferDirection;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.Amount = x.Amount;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.TransferReason, x.TransferReason.c_str());
    y.TransferStatus = x.TransferStatus;
    strcpy(y.OperateDate, x.OperateDate.c_str());
    strcpy(y.OperateTime, x.OperateTime.c_str());
    strcpy(y.RepealDate, x.RepealDate.c_str());
    strcpy(y.RepealTime, x.RepealTime.c_str());
    strcpy(y.RepealReason, x.RepealReason.c_str());
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    return y;
}

PeripheryTransferFundField Converter::CTORATstpPeripheryTransferFundFieldToRust(CTORATstpPeripheryTransferFundField* x) {
    if (x == nullptr)
        return PeripheryTransferFundField{.is_null = true};
    PeripheryTransferFundField y{};
    y.FundSerial = x->FundSerial;
    y.ApplySerial = x->ApplySerial;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.TransferDirection = x->TransferDirection;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.Amount = x->Amount;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.TransferReason = Converter::GbkToRustString(x->TransferReason);
    y.TransferStatus = x->TransferStatus;
    y.OperateDate = Converter::GbkToRustString(x->OperateDate);
    y.OperateTime = Converter::GbkToRustString(x->OperateTime);
    y.RepealDate = Converter::GbkToRustString(x->RepealDate);
    y.RepealTime = Converter::GbkToRustString(x->RepealTime);
    y.RepealReason = Converter::GbkToRustString(x->RepealReason);
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    return y;
}

CTORATstpReqInquiryJZFundField Converter::ReqInquiryJZFundFieldToCpp(ReqInquiryJZFundField x) {
    CTORATstpReqInquiryJZFundField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.UserRequestID = x.UserRequestID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    return y;
}

ReqInquiryJZFundField Converter::CTORATstpReqInquiryJZFundFieldToRust(CTORATstpReqInquiryJZFundField* x) {
    if (x == nullptr)
        return ReqInquiryJZFundField{.is_null = true};
    ReqInquiryJZFundField y{};
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.UserRequestID = x->UserRequestID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    return y;
}

CTORATstpRspInquiryJZFundField Converter::RspInquiryJZFundFieldToCpp(RspInquiryJZFundField x) {
    CTORATstpRspInquiryJZFundField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.UsefulMoney = x.UsefulMoney;
    y.FetchLimit = x.FetchLimit;
    y.UserRequestID = x.UserRequestID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    return y;
}

RspInquiryJZFundField Converter::CTORATstpRspInquiryJZFundFieldToRust(CTORATstpRspInquiryJZFundField* x) {
    if (x == nullptr)
        return RspInquiryJZFundField{.is_null = true};
    RspInquiryJZFundField y{};
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.UsefulMoney = x->UsefulMoney;
    y.FetchLimit = x->FetchLimit;
    y.UserRequestID = x->UserRequestID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    return y;
}

CTORATstpReqInquiryBankAccountFundField Converter::ReqInquiryBankAccountFundFieldToCpp(ReqInquiryBankAccountFundField x) {
    CTORATstpReqInquiryBankAccountFundField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.BankID = x.BankID;
    strcpy(y.BankPassword, x.BankPassword.c_str());
    return y;
}

ReqInquiryBankAccountFundField Converter::CTORATstpReqInquiryBankAccountFundFieldToRust(CTORATstpReqInquiryBankAccountFundField* x) {
    if (x == nullptr)
        return ReqInquiryBankAccountFundField{.is_null = true};
    ReqInquiryBankAccountFundField y{};
    y.UserRequestID = x->UserRequestID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.BankID = x->BankID;
    y.BankPassword = Converter::GbkToRustString(x->BankPassword);
    return y;
}

CTORATstpRspInquiryBankAccountFundField Converter::RspInquiryBankAccountFundFieldToCpp(RspInquiryBankAccountFundField x) {
    CTORATstpRspInquiryBankAccountFundField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.BankID = x.BankID;
    strcpy(y.BankAccountID, x.BankAccountID.c_str());
    y.Balance = x.Balance;
    return y;
}

RspInquiryBankAccountFundField Converter::CTORATstpRspInquiryBankAccountFundFieldToRust(CTORATstpRspInquiryBankAccountFundField* x) {
    if (x == nullptr)
        return RspInquiryBankAccountFundField{.is_null = true};
    RspInquiryBankAccountFundField y{};
    y.UserRequestID = x->UserRequestID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.BankID = x->BankID;
    y.BankAccountID = Converter::GbkToRustString(x->BankAccountID);
    y.Balance = x->Balance;
    return y;
}

CTORATstpTradingNoticeField Converter::TradingNoticeFieldToCpp(TradingNoticeField x) {
    CTORATstpTradingNoticeField y;
    memset(&y, 0, sizeof(y));
    y.NoticeSerial = x.NoticeSerial;
    strcpy(y.InsertDate, x.InsertDate.c_str());
    strcpy(y.InsertTime, x.InsertTime.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.Content, x.Content.c_str());
    strcpy(y.OperatorID, x.OperatorID.c_str());
    return y;
}

TradingNoticeField Converter::CTORATstpTradingNoticeFieldToRust(CTORATstpTradingNoticeField* x) {
    if (x == nullptr)
        return TradingNoticeField{.is_null = true};
    TradingNoticeField y{};
    y.NoticeSerial = x->NoticeSerial;
    y.InsertDate = Converter::GbkToRustString(x->InsertDate);
    y.InsertTime = Converter::GbkToRustString(x->InsertTime);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.Content = Converter::GbkToRustString(x->Content);
    y.OperatorID = Converter::GbkToRustString(x->OperatorID);
    return y;
}

CTORATstpReqInquiryMaxOrderVolumeField Converter::ReqInquiryMaxOrderVolumeFieldToCpp(ReqInquiryMaxOrderVolumeField x) {
    CTORATstpReqInquiryMaxOrderVolumeField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.Direction = x.Direction;
    y.OrderPriceType = x.OrderPriceType;
    y.TimeCondition = x.TimeCondition;
    y.VolumeCondition = x.VolumeCondition;
    y.LimitPrice = x.LimitPrice;
    y.LotType = x.LotType;
    y.MaxVolume = x.MaxVolume;
    strcpy(y.CreditDebtID, x.CreditDebtID.c_str());
    y.CreditQuotaType = x.CreditQuotaType;
    return y;
}

ReqInquiryMaxOrderVolumeField Converter::CTORATstpReqInquiryMaxOrderVolumeFieldToRust(CTORATstpReqInquiryMaxOrderVolumeField* x) {
    if (x == nullptr)
        return ReqInquiryMaxOrderVolumeField{.is_null = true};
    ReqInquiryMaxOrderVolumeField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.Direction = x->Direction;
    y.OrderPriceType = x->OrderPriceType;
    y.TimeCondition = x->TimeCondition;
    y.VolumeCondition = x->VolumeCondition;
    y.LimitPrice = x->LimitPrice;
    y.LotType = x->LotType;
    y.MaxVolume = x->MaxVolume;
    y.CreditDebtID = Converter::GbkToRustString(x->CreditDebtID);
    y.CreditQuotaType = x->CreditQuotaType;
    return y;
}

CTORATstpRspInquiryMaxOrderVolumeField Converter::RspInquiryMaxOrderVolumeFieldToCpp(RspInquiryMaxOrderVolumeField x) {
    CTORATstpRspInquiryMaxOrderVolumeField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.Direction = x.Direction;
    y.OrderPriceType = x.OrderPriceType;
    y.TimeCondition = x.TimeCondition;
    y.VolumeCondition = x.VolumeCondition;
    y.LimitPrice = x.LimitPrice;
    y.LotType = x.LotType;
    y.MaxVolume = x.MaxVolume;
    strcpy(y.CreditDebtID, x.CreditDebtID.c_str());
    y.CreditQuotaType = x.CreditQuotaType;
    return y;
}

RspInquiryMaxOrderVolumeField Converter::CTORATstpRspInquiryMaxOrderVolumeFieldToRust(CTORATstpRspInquiryMaxOrderVolumeField* x) {
    if (x == nullptr)
        return RspInquiryMaxOrderVolumeField{.is_null = true};
    RspInquiryMaxOrderVolumeField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.Direction = x->Direction;
    y.OrderPriceType = x->OrderPriceType;
    y.TimeCondition = x->TimeCondition;
    y.VolumeCondition = x->VolumeCondition;
    y.LimitPrice = x->LimitPrice;
    y.LotType = x->LotType;
    y.MaxVolume = x->MaxVolume;
    y.CreditDebtID = Converter::GbkToRustString(x->CreditDebtID);
    y.CreditQuotaType = x->CreditQuotaType;
    return y;
}

CTORATstpInquiryTradeConcentrationField Converter::InquiryTradeConcentrationFieldToCpp(InquiryTradeConcentrationField x) {
    CTORATstpInquiryTradeConcentrationField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.ConcentrationRatio1 = x.ConcentrationRatio1;
    y.ConcentrationRatio2 = x.ConcentrationRatio2;
    return y;
}

InquiryTradeConcentrationField Converter::CTORATstpInquiryTradeConcentrationFieldToRust(CTORATstpInquiryTradeConcentrationField* x) {
    if (x == nullptr)
        return InquiryTradeConcentrationField{.is_null = true};
    InquiryTradeConcentrationField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.ConcentrationRatio1 = x->ConcentrationRatio1;
    y.ConcentrationRatio2 = x->ConcentrationRatio2;
    return y;
}

CTORATstpReqModifyOpenPosCostField Converter::ReqModifyOpenPosCostFieldToCpp(ReqModifyOpenPosCostField x) {
    CTORATstpReqModifyOpenPosCostField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.OpenPosCost = x.OpenPosCost;
    return y;
}

ReqModifyOpenPosCostField Converter::CTORATstpReqModifyOpenPosCostFieldToRust(CTORATstpReqModifyOpenPosCostField* x) {
    if (x == nullptr)
        return ReqModifyOpenPosCostField{.is_null = true};
    ReqModifyOpenPosCostField y{};
    y.UserRequestID = x->UserRequestID;
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.OpenPosCost = x->OpenPosCost;
    return y;
}

CTORATstpInputNodeFundAssignmentField Converter::InputNodeFundAssignmentFieldToCpp(InputNodeFundAssignmentField x) {
    CTORATstpInputNodeFundAssignmentField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.NodeID1 = x.NodeID1;
    y.AmtRatio1 = x.AmtRatio1;
    y.NodeID2 = x.NodeID2;
    y.AmtRatio2 = x.AmtRatio2;
    y.NodeID3 = x.NodeID3;
    y.AmtRatio3 = x.AmtRatio3;
    y.NodeID4 = x.NodeID4;
    y.AmtRatio4 = x.AmtRatio4;
    y.NodeID5 = x.NodeID5;
    y.AmtRatio5 = x.AmtRatio5;
    return y;
}

InputNodeFundAssignmentField Converter::CTORATstpInputNodeFundAssignmentFieldToRust(CTORATstpInputNodeFundAssignmentField* x) {
    if (x == nullptr)
        return InputNodeFundAssignmentField{.is_null = true};
    InputNodeFundAssignmentField y{};
    y.UserRequestID = x->UserRequestID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.NodeID1 = x->NodeID1;
    y.AmtRatio1 = x->AmtRatio1;
    y.NodeID2 = x->NodeID2;
    y.AmtRatio2 = x->AmtRatio2;
    y.NodeID3 = x->NodeID3;
    y.AmtRatio3 = x->AmtRatio3;
    y.NodeID4 = x->NodeID4;
    y.AmtRatio4 = x->AmtRatio4;
    y.NodeID5 = x->NodeID5;
    y.AmtRatio5 = x->AmtRatio5;
    return y;
}

CTORATstpReqInquiryNodeFundAssignmentField Converter::ReqInquiryNodeFundAssignmentFieldToCpp(ReqInquiryNodeFundAssignmentField x) {
    CTORATstpReqInquiryNodeFundAssignmentField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.NodeID = x.NodeID;
    y.UserRequestID = x.UserRequestID;
    return y;
}

ReqInquiryNodeFundAssignmentField Converter::CTORATstpReqInquiryNodeFundAssignmentFieldToRust(CTORATstpReqInquiryNodeFundAssignmentField* x) {
    if (x == nullptr)
        return ReqInquiryNodeFundAssignmentField{.is_null = true};
    ReqInquiryNodeFundAssignmentField y{};
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.NodeID = x->NodeID;
    y.UserRequestID = x->UserRequestID;
    return y;
}

CTORATstpRspInquiryNodeFundAssignmentField Converter::RspInquiryNodeFundAssignmentFieldToCpp(RspInquiryNodeFundAssignmentField x) {
    CTORATstpRspInquiryNodeFundAssignmentField y;
    memset(&y, 0, sizeof(y));
    y.UserRequestID = x.UserRequestID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.NodeID1 = x.NodeID1;
    y.AmtRatio1 = x.AmtRatio1;
    y.NodeID2 = x.NodeID2;
    y.AmtRatio2 = x.AmtRatio2;
    y.NodeID3 = x.NodeID3;
    y.AmtRatio3 = x.AmtRatio3;
    y.NodeID4 = x.NodeID4;
    y.AmtRatio4 = x.AmtRatio4;
    y.NodeID5 = x.NodeID5;
    y.AmtRatio5 = x.AmtRatio5;
    return y;
}

RspInquiryNodeFundAssignmentField Converter::CTORATstpRspInquiryNodeFundAssignmentFieldToRust(CTORATstpRspInquiryNodeFundAssignmentField* x) {
    if (x == nullptr)
        return RspInquiryNodeFundAssignmentField{.is_null = true};
    RspInquiryNodeFundAssignmentField y{};
    y.UserRequestID = x->UserRequestID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.NodeID1 = x->NodeID1;
    y.AmtRatio1 = x->AmtRatio1;
    y.NodeID2 = x->NodeID2;
    y.AmtRatio2 = x->AmtRatio2;
    y.NodeID3 = x->NodeID3;
    y.AmtRatio3 = x->AmtRatio3;
    y.NodeID4 = x->NodeID4;
    y.AmtRatio4 = x->AmtRatio4;
    y.NodeID5 = x->NodeID5;
    y.AmtRatio5 = x->AmtRatio5;
    return y;
}

CTORATstpQryExchangeField Converter::QryExchangeFieldToCpp(QryExchangeField x) {
    CTORATstpQryExchangeField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    return y;
}

QryExchangeField Converter::CTORATstpQryExchangeFieldToRust(CTORATstpQryExchangeField* x) {
    if (x == nullptr)
        return QryExchangeField{.is_null = true};
    QryExchangeField y{};
    y.ExchangeID = x->ExchangeID;
    return y;
}

CTORATstpExchangeField Converter::ExchangeFieldToCpp(ExchangeField x) {
    CTORATstpExchangeField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ExchangeName, x.ExchangeName.c_str());
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.DataSyncStatus = x.DataSyncStatus;
    return y;
}

ExchangeField Converter::CTORATstpExchangeFieldToRust(CTORATstpExchangeField* x) {
    if (x == nullptr)
        return ExchangeField{.is_null = true};
    ExchangeField y{};
    y.ExchangeID = x->ExchangeID;
    y.ExchangeName = Converter::GbkToRustString(x->ExchangeName);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.DataSyncStatus = x->DataSyncStatus;
    return y;
}

CTORATstpQrySecurityField Converter::QrySecurityFieldToCpp(QrySecurityField x) {
    CTORATstpQrySecurityField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ProductID = x.ProductID;
    return y;
}

QrySecurityField Converter::CTORATstpQrySecurityFieldToRust(CTORATstpQrySecurityField* x) {
    if (x == nullptr)
        return QrySecurityField{.is_null = true};
    QrySecurityField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ProductID = x->ProductID;
    return y;
}

CTORATstpSecurityField Converter::SecurityFieldToCpp(SecurityField x) {
    CTORATstpSecurityField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.SecurityName, x.SecurityName.c_str());
    strcpy(y.ShortSecurityName, x.ShortSecurityName.c_str());
    strcpy(y.UnderlyingSecurityID, x.UnderlyingSecurityID.c_str());
    y.MarketID = x.MarketID;
    y.ProductID = x.ProductID;
    y.SecurityType = x.SecurityType;
    y.OrderUnit = x.OrderUnit;
    y.LimitBuyTradingUnit = x.LimitBuyTradingUnit;
    y.MaxLimitOrderBuyVolume = x.MaxLimitOrderBuyVolume;
    y.MinLimitOrderBuyVolume = x.MinLimitOrderBuyVolume;
    y.LimitSellTradingUnit = x.LimitSellTradingUnit;
    y.MaxLimitOrderSellVolume = x.MaxLimitOrderSellVolume;
    y.MinLimitOrderSellVolume = x.MinLimitOrderSellVolume;
    y.MarketBuyTradingUnit = x.MarketBuyTradingUnit;
    y.MaxMarketOrderBuyVolume = x.MaxMarketOrderBuyVolume;
    y.MinMarketOrderBuyVolume = x.MinMarketOrderBuyVolume;
    y.MarketSellTradingUnit = x.MarketSellTradingUnit;
    y.MaxMarketOrderSellVolume = x.MaxMarketOrderSellVolume;
    y.MinMarketOrderSellVolume = x.MinMarketOrderSellVolume;
    y.FixPriceBuyTradingUnit = x.FixPriceBuyTradingUnit;
    y.MaxFixPriceOrderBuyVolume = x.MaxFixPriceOrderBuyVolume;
    y.MinFixPriceOrderBuyVolume = x.MinFixPriceOrderBuyVolume;
    y.FixPriceSellTradingUnit = x.FixPriceSellTradingUnit;
    y.MaxFixPriceOrderSellVolume = x.MaxFixPriceOrderSellVolume;
    y.MinFixPriceOrderSellVolume = x.MinFixPriceOrderSellVolume;
    y.VolumeMultiple = x.VolumeMultiple;
    y.PriceTick = x.PriceTick;
    strcpy(y.OpenDate, x.OpenDate.c_str());
    y.ParValue = x.ParValue;
    y.SecurityStatus = x.SecurityStatus;
    y.BondInterest = x.BondInterest;
    y.ConversionRate = x.ConversionRate;
    y.TotalEquity = x.TotalEquity;
    y.CirculationEquity = x.CirculationEquity;
    y.bPriceLimit = x.bPriceLimit;
    y.PreClosePrice = x.PreClosePrice;
    y.UpperLimitPrice = x.UpperLimitPrice;
    y.LowerLimitPrice = x.LowerLimitPrice;
    y.DayTrading = x.DayTrading;
    return y;
}

SecurityField Converter::CTORATstpSecurityFieldToRust(CTORATstpSecurityField* x) {
    if (x == nullptr)
        return SecurityField{.is_null = true};
    SecurityField y{};
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.ShortSecurityName = Converter::GbkToRustString(x->ShortSecurityName);
    y.UnderlyingSecurityID = Converter::GbkToRustString(x->UnderlyingSecurityID);
    y.MarketID = x->MarketID;
    y.ProductID = x->ProductID;
    y.SecurityType = x->SecurityType;
    y.OrderUnit = x->OrderUnit;
    y.LimitBuyTradingUnit = x->LimitBuyTradingUnit;
    y.MaxLimitOrderBuyVolume = x->MaxLimitOrderBuyVolume;
    y.MinLimitOrderBuyVolume = x->MinLimitOrderBuyVolume;
    y.LimitSellTradingUnit = x->LimitSellTradingUnit;
    y.MaxLimitOrderSellVolume = x->MaxLimitOrderSellVolume;
    y.MinLimitOrderSellVolume = x->MinLimitOrderSellVolume;
    y.MarketBuyTradingUnit = x->MarketBuyTradingUnit;
    y.MaxMarketOrderBuyVolume = x->MaxMarketOrderBuyVolume;
    y.MinMarketOrderBuyVolume = x->MinMarketOrderBuyVolume;
    y.MarketSellTradingUnit = x->MarketSellTradingUnit;
    y.MaxMarketOrderSellVolume = x->MaxMarketOrderSellVolume;
    y.MinMarketOrderSellVolume = x->MinMarketOrderSellVolume;
    y.FixPriceBuyTradingUnit = x->FixPriceBuyTradingUnit;
    y.MaxFixPriceOrderBuyVolume = x->MaxFixPriceOrderBuyVolume;
    y.MinFixPriceOrderBuyVolume = x->MinFixPriceOrderBuyVolume;
    y.FixPriceSellTradingUnit = x->FixPriceSellTradingUnit;
    y.MaxFixPriceOrderSellVolume = x->MaxFixPriceOrderSellVolume;
    y.MinFixPriceOrderSellVolume = x->MinFixPriceOrderSellVolume;
    y.VolumeMultiple = x->VolumeMultiple;
    y.PriceTick = x->PriceTick;
    y.OpenDate = Converter::GbkToRustString(x->OpenDate);
    y.ParValue = x->ParValue;
    y.SecurityStatus = x->SecurityStatus;
    y.BondInterest = x->BondInterest;
    y.ConversionRate = x->ConversionRate;
    y.TotalEquity = x->TotalEquity;
    y.CirculationEquity = x->CirculationEquity;
    y.bPriceLimit = x->bPriceLimit;
    y.PreClosePrice = x->PreClosePrice;
    y.UpperLimitPrice = x->UpperLimitPrice;
    y.LowerLimitPrice = x->LowerLimitPrice;
    y.DayTrading = x->DayTrading;
    return y;
}

CTORATstpQryIPOInfoField Converter::QryIPOInfoFieldToCpp(QryIPOInfoField x) {
    CTORATstpQryIPOInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

QryIPOInfoField Converter::CTORATstpQryIPOInfoFieldToRust(CTORATstpQryIPOInfoField* x) {
    if (x == nullptr)
        return QryIPOInfoField{.is_null = true};
    QryIPOInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpIPOInfoField Converter::IPOInfoFieldToCpp(IPOInfoField x) {
    CTORATstpIPOInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.MarketID = x.MarketID;
    y.ProductID = x.ProductID;
    y.SecurityType = x.SecurityType;
    y.MinPrice = x.MinPrice;
    y.CurrencyID = x.CurrencyID;
    strcpy(y.SecurityName, x.SecurityName.c_str());
    strcpy(y.UnderlyingSecurityID, x.UnderlyingSecurityID.c_str());
    strcpy(y.UnderlyingSecurityName, x.UnderlyingSecurityName.c_str());
    y.MinVolume = x.MinVolume;
    y.MaxVolume = x.MaxVolume;
    y.VolumeUnit = x.VolumeUnit;
    y.IssueMode = x.IssueMode;
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.MaxPrice = x.MaxPrice;
    y.Remark = x.Remark;
    return y;
}

IPOInfoField Converter::CTORATstpIPOInfoFieldToRust(CTORATstpIPOInfoField* x) {
    if (x == nullptr)
        return IPOInfoField{.is_null = true};
    IPOInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.MarketID = x->MarketID;
    y.ProductID = x->ProductID;
    y.SecurityType = x->SecurityType;
    y.MinPrice = x->MinPrice;
    y.CurrencyID = x->CurrencyID;
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.UnderlyingSecurityID = Converter::GbkToRustString(x->UnderlyingSecurityID);
    y.UnderlyingSecurityName = Converter::GbkToRustString(x->UnderlyingSecurityName);
    y.MinVolume = x->MinVolume;
    y.MaxVolume = x->MaxVolume;
    y.VolumeUnit = x->VolumeUnit;
    y.IssueMode = x->IssueMode;
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.MaxPrice = x->MaxPrice;
    y.Remark = x->Remark;
    return y;
}

CTORATstpQryUserField Converter::QryUserFieldToCpp(QryUserField x) {
    CTORATstpQryUserField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.UserID, x.UserID.c_str());
    y.UserType = x.UserType;
    return y;
}

QryUserField Converter::CTORATstpQryUserFieldToRust(CTORATstpQryUserField* x) {
    if (x == nullptr)
        return QryUserField{.is_null = true};
    QryUserField y{};
    y.UserID = Converter::GbkToRustString(x->UserID);
    y.UserType = x->UserType;
    return y;
}

CTORATstpUserField Converter::UserFieldToCpp(UserField x) {
    CTORATstpUserField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.UserID, x.UserID.c_str());
    strcpy(y.UserName, x.UserName.c_str());
    y.UserType = x.UserType;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    y.LoginLimit = x.LoginLimit;
    y.LoginStatus = x.LoginStatus;
    strcpy(y.OpenDate, x.OpenDate.c_str());
    strcpy(y.CloseDate, x.CloseDate.c_str());
    y.OrderInsertCommFlux = x.OrderInsertCommFlux;
    y.OrderActionCommFlux = x.OrderActionCommFlux;
    y.TradeCommFlux = x.TradeCommFlux;
    y.QueryCommFlux = x.QueryCommFlux;
    y.OrderCommFlux = x.OrderCommFlux;
    return y;
}

UserField Converter::CTORATstpUserFieldToRust(CTORATstpUserField* x) {
    if (x == nullptr)
        return UserField{.is_null = true};
    UserField y{};
    y.UserID = Converter::GbkToRustString(x->UserID);
    y.UserName = Converter::GbkToRustString(x->UserName);
    y.UserType = x->UserType;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.LoginLimit = x->LoginLimit;
    y.LoginStatus = x->LoginStatus;
    y.OpenDate = Converter::GbkToRustString(x->OpenDate);
    y.CloseDate = Converter::GbkToRustString(x->CloseDate);
    y.OrderInsertCommFlux = x->OrderInsertCommFlux;
    y.OrderActionCommFlux = x->OrderActionCommFlux;
    y.TradeCommFlux = x->TradeCommFlux;
    y.QueryCommFlux = x->QueryCommFlux;
    y.OrderCommFlux = x->OrderCommFlux;
    return y;
}

CTORATstpQryInvestorField Converter::QryInvestorFieldToCpp(QryInvestorField x) {
    CTORATstpQryInvestorField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    return y;
}

QryInvestorField Converter::CTORATstpQryInvestorFieldToRust(CTORATstpQryInvestorField* x) {
    if (x == nullptr)
        return QryInvestorField{.is_null = true};
    QryInvestorField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    return y;
}

CTORATstpInvestorField Converter::InvestorFieldToCpp(InvestorField x) {
    CTORATstpInvestorField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.InvestorType = x.InvestorType;
    strcpy(y.InvestorName, x.InvestorName.c_str());
    y.IdCardType = x.IdCardType;
    strcpy(y.IdCardNo, x.IdCardNo.c_str());
    strcpy(y.OpenDate, x.OpenDate.c_str());
    strcpy(y.CloseDate, x.CloseDate.c_str());
    y.TradingStatus = x.TradingStatus;
    memcpy(y.Operways, x.Operways.data(), x.Operways.size() * sizeof(uint8_t));
    strcpy(y.Mobile, x.Mobile.c_str());
    strcpy(y.Telephone, x.Telephone.c_str());
    strcpy(y.Email, x.Email.c_str());
    memcpy(y.Fax, x.Fax.data(), x.Fax.size() * sizeof(uint8_t));
    strcpy(y.Address, x.Address.c_str());
    strcpy(y.ZipCode, x.ZipCode.c_str());
    y.ProfInvestorType = x.ProfInvestorType;
    y.PlanType = x.PlanType;
    y.AllowSelfSwitchPlan = x.AllowSelfSwitchPlan;
    strcpy(y.Remark, x.Remark.c_str());
    return y;
}

InvestorField Converter::CTORATstpInvestorFieldToRust(CTORATstpInvestorField* x) {
    if (x == nullptr)
        return InvestorField{.is_null = true};
    InvestorField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.InvestorType = x->InvestorType;
    y.InvestorName = Converter::GbkToRustString(x->InvestorName);
    y.IdCardType = x->IdCardType;
    y.IdCardNo = Converter::GbkToRustString(x->IdCardNo);
    y.OpenDate = Converter::GbkToRustString(x->OpenDate);
    y.CloseDate = Converter::GbkToRustString(x->CloseDate);
    y.TradingStatus = x->TradingStatus;
    for (int i = 0; i < 41; i++)
        y.Operways.push_back(x->Operways[i]);
    y.Mobile = Converter::GbkToRustString(x->Mobile);
    y.Telephone = Converter::GbkToRustString(x->Telephone);
    y.Email = Converter::GbkToRustString(x->Email);
    for (int i = 0; i < 21; i++)
        y.Fax.push_back(x->Fax[i]);
    y.Address = Converter::GbkToRustString(x->Address);
    y.ZipCode = Converter::GbkToRustString(x->ZipCode);
    y.ProfInvestorType = x->ProfInvestorType;
    y.PlanType = x->PlanType;
    y.AllowSelfSwitchPlan = x->AllowSelfSwitchPlan;
    y.Remark = Converter::GbkToRustString(x->Remark);
    return y;
}

CTORATstpQryShareholderAccountField Converter::QryShareholderAccountFieldToCpp(QryShareholderAccountField x) {
    CTORATstpQryShareholderAccountField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.ShareholderIDType = x.ShareholderIDType;
    return y;
}

QryShareholderAccountField Converter::CTORATstpQryShareholderAccountFieldToRust(CTORATstpQryShareholderAccountField* x) {
    if (x == nullptr)
        return QryShareholderAccountField{.is_null = true};
    QryShareholderAccountField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.ShareholderIDType = x->ShareholderIDType;
    return y;
}

CTORATstpShareholderAccountField Converter::ShareholderAccountFieldToCpp(ShareholderAccountField x) {
    CTORATstpShareholderAccountField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.ShareholderIDType = x.ShareholderIDType;
    y.MarketID = x.MarketID;
    y.BSWhiteListCtl = x.BSWhiteListCtl;
    y.MainFlag = x.MainFlag;
    return y;
}

ShareholderAccountField Converter::CTORATstpShareholderAccountFieldToRust(CTORATstpShareholderAccountField* x) {
    if (x == nullptr)
        return ShareholderAccountField{.is_null = true};
    ShareholderAccountField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.ShareholderIDType = x->ShareholderIDType;
    y.MarketID = x->MarketID;
    y.BSWhiteListCtl = x->BSWhiteListCtl;
    y.MainFlag = x->MainFlag;
    return y;
}

CTORATstpQryRationalInfoField Converter::QryRationalInfoFieldToCpp(QryRationalInfoField x) {
    CTORATstpQryRationalInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

QryRationalInfoField Converter::CTORATstpQryRationalInfoFieldToRust(CTORATstpQryRationalInfoField* x) {
    if (x == nullptr)
        return QryRationalInfoField{.is_null = true};
    QryRationalInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpRationalInfoField Converter::RationalInfoFieldToCpp(RationalInfoField x) {
    CTORATstpRationalInfoField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.Price = x.Price;
    y.MarketID = x.MarketID;
    y.ProductID = x.ProductID;
    y.SecurityType = x.SecurityType;
    strcpy(y.SecurityName, x.SecurityName.c_str());
    strcpy(y.UnderlyingSecurityID, x.UnderlyingSecurityID.c_str());
    strcpy(y.UnderlyingSecurityName, x.UnderlyingSecurityName.c_str());
    y.MinVolume = x.MinVolume;
    y.MaxVolume = x.MaxVolume;
    y.VolumeUnit = x.VolumeUnit;
    return y;
}

RationalInfoField Converter::CTORATstpRationalInfoFieldToRust(CTORATstpRationalInfoField* x) {
    if (x == nullptr)
        return RationalInfoField{.is_null = true};
    RationalInfoField y{};
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.Price = x->Price;
    y.MarketID = x->MarketID;
    y.ProductID = x->ProductID;
    y.SecurityType = x->SecurityType;
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.UnderlyingSecurityID = Converter::GbkToRustString(x->UnderlyingSecurityID);
    y.UnderlyingSecurityName = Converter::GbkToRustString(x->UnderlyingSecurityName);
    y.MinVolume = x->MinVolume;
    y.MaxVolume = x->MaxVolume;
    y.VolumeUnit = x->VolumeUnit;
    return y;
}

CTORATstpQryOrderField Converter::QryOrderFieldToCpp(QryOrderField x) {
    CTORATstpQryOrderField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    memcpy(y.InsertTimeStart, x.InsertTimeStart.data(), x.InsertTimeStart.size() * sizeof(uint8_t));
    memcpy(y.InsertTimeEnd, x.InsertTimeEnd.data(), x.InsertTimeEnd.size() * sizeof(uint8_t));
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    y.IsCancel = x.IsCancel;
    return y;
}

QryOrderField Converter::CTORATstpQryOrderFieldToRust(CTORATstpQryOrderField* x) {
    if (x == nullptr)
        return QryOrderField{.is_null = true};
    QryOrderField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    for (int i = 0; i < 9; i++)
        y.InsertTimeStart.push_back(x->InsertTimeStart[i]);
    for (int i = 0; i < 9; i++)
        y.InsertTimeEnd.push_back(x->InsertTimeEnd[i]);
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.IsCancel = x->IsCancel;
    return y;
}

CTORATstpQryOrderActionField Converter::QryOrderActionFieldToCpp(QryOrderActionField x) {
    CTORATstpQryOrderActionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    strcpy(y.CancelOrderLocalID, x.CancelOrderLocalID.c_str());
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

QryOrderActionField Converter::CTORATstpQryOrderActionFieldToRust(CTORATstpQryOrderActionField* x) {
    if (x == nullptr)
        return QryOrderActionField{.is_null = true};
    QryOrderActionField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.CancelOrderLocalID = Converter::GbkToRustString(x->CancelOrderLocalID);
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpOrderActionField Converter::OrderActionFieldToCpp(OrderActionField x) {
    CTORATstpOrderActionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.OrderRef = x.OrderRef;
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    y.ActionFlag = x.ActionFlag;
    strcpy(y.CancelOrderLocalID, x.CancelOrderLocalID.c_str());
    y.Operway = x.Operway;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    memcpy(y.ActionUser, x.ActionUser.data(), x.ActionUser.size() * sizeof(uint8_t));
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.ActionDate, x.ActionDate.c_str());
    strcpy(y.ActionTime, x.ActionTime.c_str());
    y.CancelOrderStatus = x.CancelOrderStatus;
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    y.RequestID = x.RequestID;
    y.ActionFrontID = x.ActionFrontID;
    y.ActionSessionID = x.ActionSessionID;
    y.OrderActionRef = x.OrderActionRef;
    strcpy(y.CancelOrderSysID, x.CancelOrderSysID.c_str());
    y.CancelOrderType = x.CancelOrderType;
    strcpy(y.PbuID, x.PbuID.c_str());
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    return y;
}

OrderActionField Converter::CTORATstpOrderActionFieldToRust(CTORATstpOrderActionField* x) {
    if (x == nullptr)
        return OrderActionField{.is_null = true};
    OrderActionField y{};
    y.ExchangeID = x->ExchangeID;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.OrderRef = x->OrderRef;
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.ActionFlag = x->ActionFlag;
    y.CancelOrderLocalID = Converter::GbkToRustString(x->CancelOrderLocalID);
    y.Operway = x->Operway;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    for (int i = 0; i < 16; i++)
        y.ActionUser.push_back(x->ActionUser[i]);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.ActionDate = Converter::GbkToRustString(x->ActionDate);
    y.ActionTime = Converter::GbkToRustString(x->ActionTime);
    y.CancelOrderStatus = x->CancelOrderStatus;
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    y.RequestID = x->RequestID;
    y.ActionFrontID = x->ActionFrontID;
    y.ActionSessionID = x->ActionSessionID;
    y.OrderActionRef = x->OrderActionRef;
    y.CancelOrderSysID = Converter::GbkToRustString(x->CancelOrderSysID);
    y.CancelOrderType = x->CancelOrderType;
    y.PbuID = Converter::GbkToRustString(x->PbuID);
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    return y;
}

CTORATstpQryTradeField Converter::QryTradeFieldToCpp(QryTradeField x) {
    CTORATstpQryTradeField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.TradeID, x.TradeID.c_str());
    memcpy(y.TradeTimeStart, x.TradeTimeStart.data(), x.TradeTimeStart.size() * sizeof(uint8_t));
    memcpy(y.TradeTimeEnd, x.TradeTimeEnd.data(), x.TradeTimeEnd.size() * sizeof(uint8_t));
    return y;
}

QryTradeField Converter::CTORATstpQryTradeFieldToRust(CTORATstpQryTradeField* x) {
    if (x == nullptr)
        return QryTradeField{.is_null = true};
    QryTradeField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.TradeID = Converter::GbkToRustString(x->TradeID);
    for (int i = 0; i < 9; i++)
        y.TradeTimeStart.push_back(x->TradeTimeStart[i]);
    for (int i = 0; i < 9; i++)
        y.TradeTimeEnd.push_back(x->TradeTimeEnd[i]);
    return y;
}

CTORATstpQryTradingAccountField Converter::QryTradingAccountFieldToCpp(QryTradingAccountField x) {
    CTORATstpQryTradingAccountField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.CurrencyID = x.CurrencyID;
    strcpy(y.AccountID, x.AccountID.c_str());
    y.AccountType = x.AccountType;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    return y;
}

QryTradingAccountField Converter::CTORATstpQryTradingAccountFieldToRust(CTORATstpQryTradingAccountField* x) {
    if (x == nullptr)
        return QryTradingAccountField{.is_null = true};
    QryTradingAccountField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.CurrencyID = x->CurrencyID;
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.AccountType = x->AccountType;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    return y;
}

CTORATstpTradingAccountField Converter::TradingAccountFieldToCpp(TradingAccountField x) {
    CTORATstpTradingAccountField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.PreDeposit = x.PreDeposit;
    y.UsefulMoney = x.UsefulMoney;
    y.FetchLimit = x.FetchLimit;
    y.PreUnDeliveredMoney = x.PreUnDeliveredMoney;
    y.UnDeliveredMoney = x.UnDeliveredMoney;
    y.Deposit = x.Deposit;
    y.Withdraw = x.Withdraw;
    y.FrozenCash = x.FrozenCash;
    y.UnDeliveredFrozenCash = x.UnDeliveredFrozenCash;
    y.FrozenCommission = x.FrozenCommission;
    y.UnDeliveredFrozenCommission = x.UnDeliveredFrozenCommission;
    y.Commission = x.Commission;
    y.UnDeliveredCommission = x.UnDeliveredCommission;
    y.AccountType = x.AccountType;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.BankID = x.BankID;
    strcpy(y.BankAccountID, x.BankAccountID.c_str());
    y.RoyaltyIn = x.RoyaltyIn;
    y.RoyaltyOut = x.RoyaltyOut;
    y.CreditSellAmount = x.CreditSellAmount;
    y.CreditSellUseAmount = x.CreditSellUseAmount;
    y.VirtualAssets = x.VirtualAssets;
    y.CreditSellFrozenAmount = x.CreditSellFrozenAmount;
    memcpy(y.OwnerUnit, x.OwnerUnit.data(), x.OwnerUnit.size() * sizeof(uint8_t));
    return y;
}

TradingAccountField Converter::CTORATstpTradingAccountFieldToRust(CTORATstpTradingAccountField* x) {
    if (x == nullptr)
        return TradingAccountField{.is_null = true};
    TradingAccountField y{};
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.PreDeposit = x->PreDeposit;
    y.UsefulMoney = x->UsefulMoney;
    y.FetchLimit = x->FetchLimit;
    y.PreUnDeliveredMoney = x->PreUnDeliveredMoney;
    y.UnDeliveredMoney = x->UnDeliveredMoney;
    y.Deposit = x->Deposit;
    y.Withdraw = x->Withdraw;
    y.FrozenCash = x->FrozenCash;
    y.UnDeliveredFrozenCash = x->UnDeliveredFrozenCash;
    y.FrozenCommission = x->FrozenCommission;
    y.UnDeliveredFrozenCommission = x->UnDeliveredFrozenCommission;
    y.Commission = x->Commission;
    y.UnDeliveredCommission = x->UnDeliveredCommission;
    y.AccountType = x->AccountType;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BankID = x->BankID;
    y.BankAccountID = Converter::GbkToRustString(x->BankAccountID);
    y.RoyaltyIn = x->RoyaltyIn;
    y.RoyaltyOut = x->RoyaltyOut;
    y.CreditSellAmount = x->CreditSellAmount;
    y.CreditSellUseAmount = x->CreditSellUseAmount;
    y.VirtualAssets = x->VirtualAssets;
    y.CreditSellFrozenAmount = x->CreditSellFrozenAmount;
    for (int i = 0; i < 16; i++)
        y.OwnerUnit.push_back(x->OwnerUnit[i]);
    return y;
}

CTORATstpQryPositionField Converter::QryPositionFieldToCpp(QryPositionField x) {
    CTORATstpQryPositionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    return y;
}

QryPositionField Converter::CTORATstpQryPositionFieldToRust(CTORATstpQryPositionField* x) {
    if (x == nullptr)
        return QryPositionField{.is_null = true};
    QryPositionField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    return y;
}

CTORATstpPositionField Converter::PositionFieldToCpp(PositionField x) {
    CTORATstpPositionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.HistoryPos = x.HistoryPos;
    y.HistoryPosFrozen = x.HistoryPosFrozen;
    y.TodayBSPos = x.TodayBSPos;
    y.TodayBSPosFrozen = x.TodayBSPosFrozen;
    y.TodayPRPos = x.TodayPRPos;
    y.TodayPRPosFrozen = x.TodayPRPosFrozen;
    y.TodaySMPos = x.TodaySMPos;
    y.TodaySMPosFrozen = x.TodaySMPosFrozen;
    y.HistoryPosPrice = x.HistoryPosPrice;
    y.TotalPosCost = x.TotalPosCost;
    y.PrePosition = x.PrePosition;
    y.AvailablePosition = x.AvailablePosition;
    y.CurrentPosition = x.CurrentPosition;
    y.OpenPosCost = x.OpenPosCost;
    y.CreditBuyPos = x.CreditBuyPos;
    y.CreditSellPos = x.CreditSellPos;
    y.TodayCreditSellPos = x.TodayCreditSellPos;
    y.CollateralOutPos = x.CollateralOutPos;
    y.RepayUntradeVolume = x.RepayUntradeVolume;
    y.RepayTransferUntradeVolume = x.RepayTransferUntradeVolume;
    y.CollateralBuyUntradeAmount = x.CollateralBuyUntradeAmount;
    y.CollateralBuyUntradeVolume = x.CollateralBuyUntradeVolume;
    y.CreditBuyAmount = x.CreditBuyAmount;
    y.CreditBuyUntradeAmount = x.CreditBuyUntradeAmount;
    y.CreditBuyFrozenMargin = x.CreditBuyFrozenMargin;
    y.CreditBuyInterestFee = x.CreditBuyInterestFee;
    y.CreditBuyUntradeVolume = x.CreditBuyUntradeVolume;
    y.CreditSellAmount = x.CreditSellAmount;
    y.CreditSellUntradeAmount = x.CreditSellUntradeAmount;
    y.CreditSellFrozenMargin = x.CreditSellFrozenMargin;
    y.CreditSellInterestFee = x.CreditSellInterestFee;
    y.CreditSellUntradeVolume = x.CreditSellUntradeVolume;
    y.CollateralInPos = x.CollateralInPos;
    y.CreditBuyFrozenCirculateMargin = x.CreditBuyFrozenCirculateMargin;
    y.CreditSellFrozenCirculateMargin = x.CreditSellFrozenCirculateMargin;
    y.CloseProfit = x.CloseProfit;
    y.TodayTotalOpenVolume = x.TodayTotalOpenVolume;
    y.TodayCommission = x.TodayCommission;
    y.TodayTotalBuyAmount = x.TodayTotalBuyAmount;
    y.TodayTotalSellAmount = x.TodayTotalSellAmount;
    y.PreFrozen = x.PreFrozen;
    y.TodayTotalCloseVolume = x.TodayTotalCloseVolume;
    return y;
}

PositionField Converter::CTORATstpPositionFieldToRust(CTORATstpPositionField* x) {
    if (x == nullptr)
        return PositionField{.is_null = true};
    PositionField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.HistoryPos = x->HistoryPos;
    y.HistoryPosFrozen = x->HistoryPosFrozen;
    y.TodayBSPos = x->TodayBSPos;
    y.TodayBSPosFrozen = x->TodayBSPosFrozen;
    y.TodayPRPos = x->TodayPRPos;
    y.TodayPRPosFrozen = x->TodayPRPosFrozen;
    y.TodaySMPos = x->TodaySMPos;
    y.TodaySMPosFrozen = x->TodaySMPosFrozen;
    y.HistoryPosPrice = x->HistoryPosPrice;
    y.TotalPosCost = x->TotalPosCost;
    y.PrePosition = x->PrePosition;
    y.AvailablePosition = x->AvailablePosition;
    y.CurrentPosition = x->CurrentPosition;
    y.OpenPosCost = x->OpenPosCost;
    y.CreditBuyPos = x->CreditBuyPos;
    y.CreditSellPos = x->CreditSellPos;
    y.TodayCreditSellPos = x->TodayCreditSellPos;
    y.CollateralOutPos = x->CollateralOutPos;
    y.RepayUntradeVolume = x->RepayUntradeVolume;
    y.RepayTransferUntradeVolume = x->RepayTransferUntradeVolume;
    y.CollateralBuyUntradeAmount = x->CollateralBuyUntradeAmount;
    y.CollateralBuyUntradeVolume = x->CollateralBuyUntradeVolume;
    y.CreditBuyAmount = x->CreditBuyAmount;
    y.CreditBuyUntradeAmount = x->CreditBuyUntradeAmount;
    y.CreditBuyFrozenMargin = x->CreditBuyFrozenMargin;
    y.CreditBuyInterestFee = x->CreditBuyInterestFee;
    y.CreditBuyUntradeVolume = x->CreditBuyUntradeVolume;
    y.CreditSellAmount = x->CreditSellAmount;
    y.CreditSellUntradeAmount = x->CreditSellUntradeAmount;
    y.CreditSellFrozenMargin = x->CreditSellFrozenMargin;
    y.CreditSellInterestFee = x->CreditSellInterestFee;
    y.CreditSellUntradeVolume = x->CreditSellUntradeVolume;
    y.CollateralInPos = x->CollateralInPos;
    y.CreditBuyFrozenCirculateMargin = x->CreditBuyFrozenCirculateMargin;
    y.CreditSellFrozenCirculateMargin = x->CreditSellFrozenCirculateMargin;
    y.CloseProfit = x->CloseProfit;
    y.TodayTotalOpenVolume = x->TodayTotalOpenVolume;
    y.TodayCommission = x->TodayCommission;
    y.TodayTotalBuyAmount = x->TodayTotalBuyAmount;
    y.TodayTotalSellAmount = x->TodayTotalSellAmount;
    y.PreFrozen = x->PreFrozen;
    y.TodayTotalCloseVolume = x->TodayTotalCloseVolume;
    return y;
}

CTORATstpQryTradingFeeField Converter::QryTradingFeeFieldToCpp(QryTradingFeeField x) {
    CTORATstpQryTradingFeeField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    return y;
}

QryTradingFeeField Converter::CTORATstpQryTradingFeeFieldToRust(CTORATstpQryTradingFeeField* x) {
    if (x == nullptr)
        return QryTradingFeeField{.is_null = true};
    QryTradingFeeField y{};
    y.ExchangeID = x->ExchangeID;
    return y;
}

CTORATstpTradingFeeField Converter::TradingFeeFieldToCpp(TradingFeeField x) {
    CTORATstpTradingFeeField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    y.ProductID = x.ProductID;
    y.SecurityType = x.SecurityType;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.BizClass = x.BizClass;
    y.StampTaxRatioByAmt = x.StampTaxRatioByAmt;
    y.StampTaxRatioByPar = x.StampTaxRatioByPar;
    y.StampTaxFeePerOrder = x.StampTaxFeePerOrder;
    y.StampTaxFeeByVolume = x.StampTaxFeeByVolume;
    y.StampTaxFeeMin = x.StampTaxFeeMin;
    y.StampTaxFeeMax = x.StampTaxFeeMax;
    y.TransferRatioByAmt = x.TransferRatioByAmt;
    y.TransferRatioByPar = x.TransferRatioByPar;
    y.TransferFeePerOrder = x.TransferFeePerOrder;
    y.TransferFeeByVolume = x.TransferFeeByVolume;
    y.TransferFeeMin = x.TransferFeeMin;
    y.TransferFeeMax = x.TransferFeeMax;
    y.HandlingRatioByAmt = x.HandlingRatioByAmt;
    y.HandlingRatioByPar = x.HandlingRatioByPar;
    y.HandlingFeePerOrder = x.HandlingFeePerOrder;
    y.HandlingFeeByVolume = x.HandlingFeeByVolume;
    y.HandlingFeeMin = x.HandlingFeeMin;
    y.HandlingFeeMax = x.HandlingFeeMax;
    y.RegulateRatioByAmt = x.RegulateRatioByAmt;
    y.RegulateRatioByPar = x.RegulateRatioByPar;
    y.RegulateFeePerOrder = x.RegulateFeePerOrder;
    y.RegulateFeeByVolume = x.RegulateFeeByVolume;
    y.RegulateFeeMin = x.RegulateFeeMin;
    y.RegulateFeeMax = x.RegulateFeeMax;
    y.SettlementRatioByAmt = x.SettlementRatioByAmt;
    y.SettlementRatioByPar = x.SettlementRatioByPar;
    y.SettlementFeePerOrder = x.SettlementFeePerOrder;
    y.SettlementFeeByVolume = x.SettlementFeeByVolume;
    y.SettlementFeeMin = x.SettlementFeeMin;
    y.SettlementFeeMax = x.SettlementFeeMax;
    return y;
}

TradingFeeField Converter::CTORATstpTradingFeeFieldToRust(CTORATstpTradingFeeField* x) {
    if (x == nullptr)
        return TradingFeeField{.is_null = true};
    TradingFeeField y{};
    y.ExchangeID = x->ExchangeID;
    y.ProductID = x->ProductID;
    y.SecurityType = x->SecurityType;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.BizClass = x->BizClass;
    y.StampTaxRatioByAmt = x->StampTaxRatioByAmt;
    y.StampTaxRatioByPar = x->StampTaxRatioByPar;
    y.StampTaxFeePerOrder = x->StampTaxFeePerOrder;
    y.StampTaxFeeByVolume = x->StampTaxFeeByVolume;
    y.StampTaxFeeMin = x->StampTaxFeeMin;
    y.StampTaxFeeMax = x->StampTaxFeeMax;
    y.TransferRatioByAmt = x->TransferRatioByAmt;
    y.TransferRatioByPar = x->TransferRatioByPar;
    y.TransferFeePerOrder = x->TransferFeePerOrder;
    y.TransferFeeByVolume = x->TransferFeeByVolume;
    y.TransferFeeMin = x->TransferFeeMin;
    y.TransferFeeMax = x->TransferFeeMax;
    y.HandlingRatioByAmt = x->HandlingRatioByAmt;
    y.HandlingRatioByPar = x->HandlingRatioByPar;
    y.HandlingFeePerOrder = x->HandlingFeePerOrder;
    y.HandlingFeeByVolume = x->HandlingFeeByVolume;
    y.HandlingFeeMin = x->HandlingFeeMin;
    y.HandlingFeeMax = x->HandlingFeeMax;
    y.RegulateRatioByAmt = x->RegulateRatioByAmt;
    y.RegulateRatioByPar = x->RegulateRatioByPar;
    y.RegulateFeePerOrder = x->RegulateFeePerOrder;
    y.RegulateFeeByVolume = x->RegulateFeeByVolume;
    y.RegulateFeeMin = x->RegulateFeeMin;
    y.RegulateFeeMax = x->RegulateFeeMax;
    y.SettlementRatioByAmt = x->SettlementRatioByAmt;
    y.SettlementRatioByPar = x->SettlementRatioByPar;
    y.SettlementFeePerOrder = x->SettlementFeePerOrder;
    y.SettlementFeeByVolume = x->SettlementFeeByVolume;
    y.SettlementFeeMin = x->SettlementFeeMin;
    y.SettlementFeeMax = x->SettlementFeeMax;
    return y;
}

CTORATstpQryInvestorTradingFeeField Converter::QryInvestorTradingFeeFieldToCpp(QryInvestorTradingFeeField x) {
    CTORATstpQryInvestorTradingFeeField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    return y;
}

QryInvestorTradingFeeField Converter::CTORATstpQryInvestorTradingFeeFieldToRust(CTORATstpQryInvestorTradingFeeField* x) {
    if (x == nullptr)
        return QryInvestorTradingFeeField{.is_null = true};
    QryInvestorTradingFeeField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExchangeID = x->ExchangeID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    return y;
}

CTORATstpInvestorTradingFeeField Converter::InvestorTradingFeeFieldToCpp(InvestorTradingFeeField x) {
    CTORATstpInvestorTradingFeeField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.ProductID = x.ProductID;
    y.SecurityType = x.SecurityType;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.BizClass = x.BizClass;
    y.BrokerageType = x.BrokerageType;
    y.RatioByAmt = x.RatioByAmt;
    y.RatioByPar = x.RatioByPar;
    y.FeePerOrder = x.FeePerOrder;
    y.FeeMin = x.FeeMin;
    y.FeeMax = x.FeeMax;
    y.FeeByVolume = x.FeeByVolume;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    y.OrderType = x.OrderType;
    return y;
}

InvestorTradingFeeField Converter::CTORATstpInvestorTradingFeeFieldToRust(CTORATstpInvestorTradingFeeField* x) {
    if (x == nullptr)
        return InvestorTradingFeeField{.is_null = true};
    InvestorTradingFeeField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExchangeID = x->ExchangeID;
    y.ProductID = x->ProductID;
    y.SecurityType = x->SecurityType;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.BizClass = x->BizClass;
    y.BrokerageType = x->BrokerageType;
    y.RatioByAmt = x->RatioByAmt;
    y.RatioByPar = x->RatioByPar;
    y.FeePerOrder = x->FeePerOrder;
    y.FeeMin = x->FeeMin;
    y.FeeMax = x->FeeMax;
    y.FeeByVolume = x->FeeByVolume;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.OrderType = x->OrderType;
    return y;
}

CTORATstpQryIPOQuotaField Converter::QryIPOQuotaFieldToCpp(QryIPOQuotaField x) {
    CTORATstpQryIPOQuotaField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    return y;
}

QryIPOQuotaField Converter::CTORATstpQryIPOQuotaFieldToRust(CTORATstpQryIPOQuotaField* x) {
    if (x == nullptr)
        return QryIPOQuotaField{.is_null = true};
    QryIPOQuotaField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    return y;
}

CTORATstpIPOQuotaField Converter::IPOQuotaFieldToCpp(IPOQuotaField x) {
    CTORATstpIPOQuotaField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.MaxVolume = x.MaxVolume;
    y.KCMaxVolume = x.KCMaxVolume;
    return y;
}

IPOQuotaField Converter::CTORATstpIPOQuotaFieldToRust(CTORATstpIPOQuotaField* x) {
    if (x == nullptr)
        return IPOQuotaField{.is_null = true};
    IPOQuotaField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.MaxVolume = x->MaxVolume;
    y.KCMaxVolume = x->KCMaxVolume;
    return y;
}

CTORATstpQryOrderFundDetailField Converter::QryOrderFundDetailFieldToCpp(QryOrderFundDetailField x) {
    CTORATstpQryOrderFundDetailField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    return y;
}

QryOrderFundDetailField Converter::CTORATstpQryOrderFundDetailFieldToRust(CTORATstpQryOrderFundDetailField* x) {
    if (x == nullptr)
        return QryOrderFundDetailField{.is_null = true};
    QryOrderFundDetailField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    return y;
}

CTORATstpOrderFundDetailField Converter::OrderFundDetailFieldToCpp(OrderFundDetailField x) {
    CTORATstpOrderFundDetailField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    strcpy(y.PbuID, x.PbuID.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.OrderAmount = x.OrderAmount;
    y.Turnover = x.Turnover;
    y.StampTaxFee = x.StampTaxFee;
    y.HandlingFee = x.HandlingFee;
    y.TransferFee = x.TransferFee;
    y.RegulateFee = x.RegulateFee;
    y.SettlementFee = x.SettlementFee;
    y.BrokerageFee = x.BrokerageFee;
    y.TotalFee = x.TotalFee;
    y.OrderCashFrozen = x.OrderCashFrozen;
    y.EstimateCashFrozen = x.EstimateCashFrozen;
    y.TotalFeeFrozen = x.TotalFeeFrozen;
    y.TotalFrozen = x.TotalFrozen;
    y.Margin = x.Margin;
    y.RepayAmount = x.RepayAmount;
    y.RepayVolume = x.RepayVolume;
    y.MarginFrozen = x.MarginFrozen;
    y.CirculateMarginFrozen = x.CirculateMarginFrozen;
    return y;
}

OrderFundDetailField Converter::CTORATstpOrderFundDetailFieldToRust(CTORATstpOrderFundDetailField* x) {
    if (x == nullptr)
        return OrderFundDetailField{.is_null = true};
    OrderFundDetailField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.PbuID = Converter::GbkToRustString(x->PbuID);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.OrderAmount = x->OrderAmount;
    y.Turnover = x->Turnover;
    y.StampTaxFee = x->StampTaxFee;
    y.HandlingFee = x->HandlingFee;
    y.TransferFee = x->TransferFee;
    y.RegulateFee = x->RegulateFee;
    y.SettlementFee = x->SettlementFee;
    y.BrokerageFee = x->BrokerageFee;
    y.TotalFee = x->TotalFee;
    y.OrderCashFrozen = x->OrderCashFrozen;
    y.EstimateCashFrozen = x->EstimateCashFrozen;
    y.TotalFeeFrozen = x->TotalFeeFrozen;
    y.TotalFrozen = x->TotalFrozen;
    y.Margin = x->Margin;
    y.RepayAmount = x->RepayAmount;
    y.RepayVolume = x->RepayVolume;
    y.MarginFrozen = x->MarginFrozen;
    y.CirculateMarginFrozen = x->CirculateMarginFrozen;
    return y;
}

CTORATstpQryFundTransferDetailField Converter::QryFundTransferDetailFieldToCpp(QryFundTransferDetailField x) {
    CTORATstpQryFundTransferDetailField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.TransferDirection = x.TransferDirection;
    return y;
}

QryFundTransferDetailField Converter::CTORATstpQryFundTransferDetailFieldToRust(CTORATstpQryFundTransferDetailField* x) {
    if (x == nullptr)
        return QryFundTransferDetailField{.is_null = true};
    QryFundTransferDetailField y{};
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.TransferDirection = x->TransferDirection;
    return y;
}

CTORATstpFundTransferDetailField Converter::FundTransferDetailFieldToCpp(FundTransferDetailField x) {
    CTORATstpFundTransferDetailField y;
    memset(&y, 0, sizeof(y));
    y.FundSerial = x.FundSerial;
    y.ApplySerial = x.ApplySerial;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.TransferDirection = x.TransferDirection;
    y.Amount = x.Amount;
    y.TransferStatus = x.TransferStatus;
    y.OperateSource = x.OperateSource;
    strcpy(y.OperatorID, x.OperatorID.c_str());
    strcpy(y.OperateDate, x.OperateDate.c_str());
    strcpy(y.OperateTime, x.OperateTime.c_str());
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    y.BankID = x.BankID;
    strcpy(y.BankAccountID, x.BankAccountID.c_str());
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.ExternalSerial, x.ExternalSerial.c_str());
    y.ExternalNodeID = x.ExternalNodeID;
    y.ForceCloseReason = x.ForceCloseReason;
    strcpy(y.CreditDebtID, x.CreditDebtID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.BizRef, x.BizRef.c_str());
    y.ExchangeRef = x.ExchangeRef;
    return y;
}

FundTransferDetailField Converter::CTORATstpFundTransferDetailFieldToRust(CTORATstpFundTransferDetailField* x) {
    if (x == nullptr)
        return FundTransferDetailField{.is_null = true};
    FundTransferDetailField y{};
    y.FundSerial = x->FundSerial;
    y.ApplySerial = x->ApplySerial;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.TransferDirection = x->TransferDirection;
    y.Amount = x->Amount;
    y.TransferStatus = x->TransferStatus;
    y.OperateSource = x->OperateSource;
    y.OperatorID = Converter::GbkToRustString(x->OperatorID);
    y.OperateDate = Converter::GbkToRustString(x->OperateDate);
    y.OperateTime = Converter::GbkToRustString(x->OperateTime);
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.BankID = x->BankID;
    y.BankAccountID = Converter::GbkToRustString(x->BankAccountID);
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExternalSerial = Converter::GbkToRustString(x->ExternalSerial);
    y.ExternalNodeID = x->ExternalNodeID;
    y.ForceCloseReason = x->ForceCloseReason;
    y.CreditDebtID = Converter::GbkToRustString(x->CreditDebtID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.BizRef = Converter::GbkToRustString(x->BizRef);
    y.ExchangeRef = x->ExchangeRef;
    return y;
}

CTORATstpQryPositionTransferDetailField Converter::QryPositionTransferDetailFieldToCpp(QryPositionTransferDetailField x) {
    CTORATstpQryPositionTransferDetailField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.TransferDirection = x.TransferDirection;
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    return y;
}

QryPositionTransferDetailField Converter::CTORATstpQryPositionTransferDetailFieldToRust(CTORATstpQryPositionTransferDetailField* x) {
    if (x == nullptr)
        return QryPositionTransferDetailField{.is_null = true};
    QryPositionTransferDetailField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TransferDirection = x->TransferDirection;
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    return y;
}

CTORATstpPositionTransferDetailField Converter::PositionTransferDetailFieldToCpp(PositionTransferDetailField x) {
    CTORATstpPositionTransferDetailField y;
    memset(&y, 0, sizeof(y));
    y.PositionSerial = x.PositionSerial;
    y.ApplySerial = x.ApplySerial;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.MarketID = x.MarketID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.TransferDirection = x.TransferDirection;
    y.TransferPositionType = x.TransferPositionType;
    y.TransferStatus = x.TransferStatus;
    y.HistoryVolume = x.HistoryVolume;
    y.TodayBSVolume = x.TodayBSVolume;
    y.TodayPRVolume = x.TodayPRVolume;
    y.TodaySMVolume = x.TodaySMVolume;
    strcpy(y.OperatorID, x.OperatorID.c_str());
    strcpy(y.OperateDate, x.OperateDate.c_str());
    strcpy(y.OperateTime, x.OperateTime.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    y.ExternalNodeID = x.ExternalNodeID;
    return y;
}

PositionTransferDetailField Converter::CTORATstpPositionTransferDetailFieldToRust(CTORATstpPositionTransferDetailField* x) {
    if (x == nullptr)
        return PositionTransferDetailField{.is_null = true};
    PositionTransferDetailField y{};
    y.PositionSerial = x->PositionSerial;
    y.ApplySerial = x->ApplySerial;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.MarketID = x->MarketID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.TransferDirection = x->TransferDirection;
    y.TransferPositionType = x->TransferPositionType;
    y.TransferStatus = x->TransferStatus;
    y.HistoryVolume = x->HistoryVolume;
    y.TodayBSVolume = x->TodayBSVolume;
    y.TodayPRVolume = x->TodayPRVolume;
    y.TodaySMVolume = x->TodaySMVolume;
    y.OperatorID = Converter::GbkToRustString(x->OperatorID);
    y.OperateDate = Converter::GbkToRustString(x->OperateDate);
    y.OperateTime = Converter::GbkToRustString(x->OperateTime);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    y.ExternalNodeID = x->ExternalNodeID;
    return y;
}

CTORATstpQryPeripheryPositionTransferDetailField Converter::QryPeripheryPositionTransferDetailFieldToCpp(QryPeripheryPositionTransferDetailField x) {
    CTORATstpQryPeripheryPositionTransferDetailField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.TransferDirection = x.TransferDirection;
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    return y;
}

QryPeripheryPositionTransferDetailField Converter::CTORATstpQryPeripheryPositionTransferDetailFieldToRust(CTORATstpQryPeripheryPositionTransferDetailField* x) {
    if (x == nullptr)
        return QryPeripheryPositionTransferDetailField{.is_null = true};
    QryPeripheryPositionTransferDetailField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TransferDirection = x->TransferDirection;
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    return y;
}

CTORATstpPeripheryPositionTransferDetailField Converter::PeripheryPositionTransferDetailFieldToCpp(PeripheryPositionTransferDetailField x) {
    CTORATstpPeripheryPositionTransferDetailField y;
    memset(&y, 0, sizeof(y));
    y.PositionSerial = x.PositionSerial;
    y.ApplySerial = x.ApplySerial;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.TransferDirection = x.TransferDirection;
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.TodayBSPos = x.TodayBSPos;
    y.TodayPRPos = x.TodayPRPos;
    y.TodaySMPos = x.TodaySMPos;
    y.HistoryPos = x.HistoryPos;
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.TransferReason, x.TransferReason.c_str());
    y.TransferStatus = x.TransferStatus;
    strcpy(y.OperateDate, x.OperateDate.c_str());
    strcpy(y.OperateTime, x.OperateTime.c_str());
    strcpy(y.RepealDate, x.RepealDate.c_str());
    strcpy(y.RepealTime, x.RepealTime.c_str());
    strcpy(y.RepealReason, x.RepealReason.c_str());
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    return y;
}

PeripheryPositionTransferDetailField Converter::CTORATstpPeripheryPositionTransferDetailFieldToRust(CTORATstpPeripheryPositionTransferDetailField* x) {
    if (x == nullptr)
        return PeripheryPositionTransferDetailField{.is_null = true};
    PeripheryPositionTransferDetailField y{};
    y.PositionSerial = x->PositionSerial;
    y.ApplySerial = x->ApplySerial;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.TransferDirection = x->TransferDirection;
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.TodayBSPos = x->TodayBSPos;
    y.TodayPRPos = x->TodayPRPos;
    y.TodaySMPos = x->TodaySMPos;
    y.HistoryPos = x->HistoryPos;
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.TransferReason = Converter::GbkToRustString(x->TransferReason);
    y.TransferStatus = x->TransferStatus;
    y.OperateDate = Converter::GbkToRustString(x->OperateDate);
    y.OperateTime = Converter::GbkToRustString(x->OperateTime);
    y.RepealDate = Converter::GbkToRustString(x->RepealDate);
    y.RepealTime = Converter::GbkToRustString(x->RepealTime);
    y.RepealReason = Converter::GbkToRustString(x->RepealReason);
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    return y;
}

CTORATstpQryPeripheryFundTransferDetailField Converter::QryPeripheryFundTransferDetailFieldToCpp(QryPeripheryFundTransferDetailField x) {
    CTORATstpQryPeripheryFundTransferDetailField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.TransferDirection = x.TransferDirection;
    return y;
}

QryPeripheryFundTransferDetailField Converter::CTORATstpQryPeripheryFundTransferDetailFieldToRust(CTORATstpQryPeripheryFundTransferDetailField* x) {
    if (x == nullptr)
        return QryPeripheryFundTransferDetailField{.is_null = true};
    QryPeripheryFundTransferDetailField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.TransferDirection = x->TransferDirection;
    return y;
}

CTORATstpPeripheryFundTransferDetailField Converter::PeripheryFundTransferDetailFieldToCpp(PeripheryFundTransferDetailField x) {
    CTORATstpPeripheryFundTransferDetailField y;
    memset(&y, 0, sizeof(y));
    y.FundSerial = x.FundSerial;
    y.ApplySerial = x.ApplySerial;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.AccountID, x.AccountID.c_str());
    y.CurrencyID = x.CurrencyID;
    y.TransferDirection = x.TransferDirection;
    y.Amount = x.Amount;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.TransferStatus = x.TransferStatus;
    strcpy(y.TransferReason, x.TransferReason.c_str());
    strcpy(y.OperateDate, x.OperateDate.c_str());
    strcpy(y.OperateTime, x.OperateTime.c_str());
    strcpy(y.RepealDate, x.RepealDate.c_str());
    strcpy(y.RepealTime, x.RepealTime.c_str());
    strcpy(y.RepealReason, x.RepealReason.c_str());
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    return y;
}

PeripheryFundTransferDetailField Converter::CTORATstpPeripheryFundTransferDetailFieldToRust(CTORATstpPeripheryFundTransferDetailField* x) {
    if (x == nullptr)
        return PeripheryFundTransferDetailField{.is_null = true};
    PeripheryFundTransferDetailField y{};
    y.FundSerial = x->FundSerial;
    y.ApplySerial = x->ApplySerial;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.AccountID = Converter::GbkToRustString(x->AccountID);
    y.CurrencyID = x->CurrencyID;
    y.TransferDirection = x->TransferDirection;
    y.Amount = x->Amount;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.TransferStatus = x->TransferStatus;
    y.TransferReason = Converter::GbkToRustString(x->TransferReason);
    y.OperateDate = Converter::GbkToRustString(x->OperateDate);
    y.OperateTime = Converter::GbkToRustString(x->OperateTime);
    y.RepealDate = Converter::GbkToRustString(x->RepealDate);
    y.RepealTime = Converter::GbkToRustString(x->RepealTime);
    y.RepealReason = Converter::GbkToRustString(x->RepealReason);
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    return y;
}

CTORATstpQryBondConversionInfoField Converter::QryBondConversionInfoFieldToCpp(QryBondConversionInfoField x) {
    CTORATstpQryBondConversionInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

QryBondConversionInfoField Converter::CTORATstpQryBondConversionInfoFieldToRust(CTORATstpQryBondConversionInfoField* x) {
    if (x == nullptr)
        return QryBondConversionInfoField{.is_null = true};
    QryBondConversionInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpBondConversionInfoField Converter::BondConversionInfoFieldToCpp(BondConversionInfoField x) {
    CTORATstpBondConversionInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ConvertOrderID, x.ConvertOrderID.c_str());
    y.ConvertPrice = x.ConvertPrice;
    y.ConvertVolUnit = x.ConvertVolUnit;
    y.ConvertVolMax = x.ConvertVolMax;
    y.ConvertVolMin = x.ConvertVolMin;
    strcpy(y.BeginDate, x.BeginDate.c_str());
    strcpy(y.EndDate, x.EndDate.c_str());
    strcpy(y.ConvertName, x.ConvertName.c_str());
    return y;
}

BondConversionInfoField Converter::CTORATstpBondConversionInfoFieldToRust(CTORATstpBondConversionInfoField* x) {
    if (x == nullptr)
        return BondConversionInfoField{.is_null = true};
    BondConversionInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ConvertOrderID = Converter::GbkToRustString(x->ConvertOrderID);
    y.ConvertPrice = x->ConvertPrice;
    y.ConvertVolUnit = x->ConvertVolUnit;
    y.ConvertVolMax = x->ConvertVolMax;
    y.ConvertVolMin = x->ConvertVolMin;
    y.BeginDate = Converter::GbkToRustString(x->BeginDate);
    y.EndDate = Converter::GbkToRustString(x->EndDate);
    y.ConvertName = Converter::GbkToRustString(x->ConvertName);
    return y;
}

CTORATstpQryBondPutbackInfoField Converter::QryBondPutbackInfoFieldToCpp(QryBondPutbackInfoField x) {
    CTORATstpQryBondPutbackInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

QryBondPutbackInfoField Converter::CTORATstpQryBondPutbackInfoFieldToRust(CTORATstpQryBondPutbackInfoField* x) {
    if (x == nullptr)
        return QryBondPutbackInfoField{.is_null = true};
    QryBondPutbackInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpBondPutbackInfoField Converter::BondPutbackInfoFieldToCpp(BondPutbackInfoField x) {
    CTORATstpBondPutbackInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.PutbackOrderID, x.PutbackOrderID.c_str());
    strcpy(y.PutbackName, x.PutbackName.c_str());
    y.PutbackPrice = x.PutbackPrice;
    y.PutbackVolUnit = x.PutbackVolUnit;
    y.PutbackVolMax = x.PutbackVolMax;
    y.PutbackVolMin = x.PutbackVolMin;
    strcpy(y.PutbackBeginDate, x.PutbackBeginDate.c_str());
    strcpy(y.PutbackEndDate, x.PutbackEndDate.c_str());
    strcpy(y.RelieveBeginDate, x.RelieveBeginDate.c_str());
    strcpy(y.RelieveEndDate, x.RelieveEndDate.c_str());
    return y;
}

BondPutbackInfoField Converter::CTORATstpBondPutbackInfoFieldToRust(CTORATstpBondPutbackInfoField* x) {
    if (x == nullptr)
        return BondPutbackInfoField{.is_null = true};
    BondPutbackInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.PutbackOrderID = Converter::GbkToRustString(x->PutbackOrderID);
    y.PutbackName = Converter::GbkToRustString(x->PutbackName);
    y.PutbackPrice = x->PutbackPrice;
    y.PutbackVolUnit = x->PutbackVolUnit;
    y.PutbackVolMax = x->PutbackVolMax;
    y.PutbackVolMin = x->PutbackVolMin;
    y.PutbackBeginDate = Converter::GbkToRustString(x->PutbackBeginDate);
    y.PutbackEndDate = Converter::GbkToRustString(x->PutbackEndDate);
    y.RelieveBeginDate = Converter::GbkToRustString(x->RelieveBeginDate);
    y.RelieveEndDate = Converter::GbkToRustString(x->RelieveEndDate);
    return y;
}

CTORATstpQryInvestorCondOrderLimitParamField Converter::QryInvestorCondOrderLimitParamFieldToCpp(QryInvestorCondOrderLimitParamField x) {
    CTORATstpQryInvestorCondOrderLimitParamField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    return y;
}

QryInvestorCondOrderLimitParamField Converter::CTORATstpQryInvestorCondOrderLimitParamFieldToRust(CTORATstpQryInvestorCondOrderLimitParamField* x) {
    if (x == nullptr)
        return QryInvestorCondOrderLimitParamField{.is_null = true};
    QryInvestorCondOrderLimitParamField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    return y;
}

CTORATstpInvestorCondOrderLimitParamField Converter::InvestorCondOrderLimitParamFieldToCpp(InvestorCondOrderLimitParamField x) {
    CTORATstpInvestorCondOrderLimitParamField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.MaxCondOrderLimitCnt = x.MaxCondOrderLimitCnt;
    y.CurrCondOrderCnt = x.CurrCondOrderCnt;
    return y;
}

InvestorCondOrderLimitParamField Converter::CTORATstpInvestorCondOrderLimitParamFieldToRust(CTORATstpInvestorCondOrderLimitParamField* x) {
    if (x == nullptr)
        return InvestorCondOrderLimitParamField{.is_null = true};
    InvestorCondOrderLimitParamField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.MaxCondOrderLimitCnt = x->MaxCondOrderLimitCnt;
    y.CurrCondOrderCnt = x->CurrCondOrderCnt;
    return y;
}

CTORATstpQryConditionOrderField Converter::QryConditionOrderFieldToCpp(QryConditionOrderField x) {
    CTORATstpQryConditionOrderField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.CondOrderID = x.CondOrderID;
    memcpy(y.InsertTimeStart, x.InsertTimeStart.data(), x.InsertTimeStart.size() * sizeof(uint8_t));
    memcpy(y.InsertTimeEnd, x.InsertTimeEnd.data(), x.InsertTimeEnd.size() * sizeof(uint8_t));
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

QryConditionOrderField Converter::CTORATstpQryConditionOrderFieldToRust(CTORATstpQryConditionOrderField* x) {
    if (x == nullptr)
        return QryConditionOrderField{.is_null = true};
    QryConditionOrderField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.CondOrderID = x->CondOrderID;
    for (int i = 0; i < 9; i++)
        y.InsertTimeStart.push_back(x->InsertTimeStart[i]);
    for (int i = 0; i < 9; i++)
        y.InsertTimeEnd.push_back(x->InsertTimeEnd[i]);
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpQryCondOrderActionField Converter::QryCondOrderActionFieldToCpp(QryCondOrderActionField x) {
    CTORATstpQryCondOrderActionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.CondOrderID = x.CondOrderID;
    y.CancelCondOrderID = x.CancelCondOrderID;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

QryCondOrderActionField Converter::CTORATstpQryCondOrderActionFieldToRust(CTORATstpQryCondOrderActionField* x) {
    if (x == nullptr)
        return QryCondOrderActionField{.is_null = true};
    QryCondOrderActionField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.CondOrderID = x->CondOrderID;
    y.CancelCondOrderID = x->CancelCondOrderID;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpCondOrderActionField Converter::CondOrderActionFieldToCpp(CondOrderActionField x) {
    CTORATstpCondOrderActionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    y.FrontID = x.FrontID;
    y.SessionID = x.SessionID;
    y.CondOrderRef = x.CondOrderRef;
    y.CondOrderID = x.CondOrderID;
    y.ActionFlag = x.ActionFlag;
    y.Operway = x.Operway;
    y.CondOrderActionRef = x.CondOrderActionRef;
    y.CancelCondOrderID = x.CancelCondOrderID;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    y.RequestID = x.RequestID;
    y.ActionFrontID = x.ActionFrontID;
    y.ActionSessionID = x.ActionSessionID;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    memcpy(y.ActionUser, x.ActionUser.data(), x.ActionUser.size() * sizeof(uint8_t));
    strcpy(y.ActionDate, x.ActionDate.c_str());
    strcpy(y.ActionTime, x.ActionTime.c_str());
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    return y;
}

CondOrderActionField Converter::CTORATstpCondOrderActionFieldToRust(CTORATstpCondOrderActionField* x) {
    if (x == nullptr)
        return CondOrderActionField{.is_null = true};
    CondOrderActionField y{};
    y.ExchangeID = x->ExchangeID;
    y.FrontID = x->FrontID;
    y.SessionID = x->SessionID;
    y.CondOrderRef = x->CondOrderRef;
    y.CondOrderID = x->CondOrderID;
    y.ActionFlag = x->ActionFlag;
    y.Operway = x->Operway;
    y.CondOrderActionRef = x->CondOrderActionRef;
    y.CancelCondOrderID = x->CancelCondOrderID;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.RequestID = x->RequestID;
    y.ActionFrontID = x->ActionFrontID;
    y.ActionSessionID = x->ActionSessionID;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    for (int i = 0; i < 16; i++)
        y.ActionUser.push_back(x->ActionUser[i]);
    y.ActionDate = Converter::GbkToRustString(x->ActionDate);
    y.ActionTime = Converter::GbkToRustString(x->ActionTime);
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    return y;
}

CTORATstpQryTradingNoticeField Converter::QryTradingNoticeFieldToCpp(QryTradingNoticeField x) {
    CTORATstpQryTradingNoticeField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    memcpy(y.InsertDateStart, x.InsertDateStart.data(), x.InsertDateStart.size() * sizeof(uint8_t));
    memcpy(y.InsertDateEnd, x.InsertDateEnd.data(), x.InsertDateEnd.size() * sizeof(uint8_t));
    memcpy(y.InsertTimeStart, x.InsertTimeStart.data(), x.InsertTimeStart.size() * sizeof(uint8_t));
    memcpy(y.InsertTimeEnd, x.InsertTimeEnd.data(), x.InsertTimeEnd.size() * sizeof(uint8_t));
    return y;
}

QryTradingNoticeField Converter::CTORATstpQryTradingNoticeFieldToRust(CTORATstpQryTradingNoticeField* x) {
    if (x == nullptr)
        return QryTradingNoticeField{.is_null = true};
    QryTradingNoticeField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    for (int i = 0; i < 9; i++)
        y.InsertDateStart.push_back(x->InsertDateStart[i]);
    for (int i = 0; i < 9; i++)
        y.InsertDateEnd.push_back(x->InsertDateEnd[i]);
    for (int i = 0; i < 9; i++)
        y.InsertTimeStart.push_back(x->InsertTimeStart[i]);
    for (int i = 0; i < 9; i++)
        y.InsertTimeEnd.push_back(x->InsertTimeEnd[i]);
    return y;
}

CTORATstpQryIPONumberResultField Converter::QryIPONumberResultFieldToCpp(QryIPONumberResultField x) {
    CTORATstpQryIPONumberResultField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    return y;
}

QryIPONumberResultField Converter::CTORATstpQryIPONumberResultFieldToRust(CTORATstpQryIPONumberResultField* x) {
    if (x == nullptr)
        return QryIPONumberResultField{.is_null = true};
    QryIPONumberResultField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    return y;
}

CTORATstpIPONumberResultField Converter::IPONumberResultFieldToCpp(IPONumberResultField x) {
    CTORATstpIPONumberResultField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.Day, x.Day.c_str());
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.SecurityType = x.SecurityType;
    strcpy(y.BeginNumberID, x.BeginNumberID.c_str());
    y.Volume = x.Volume;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    return y;
}

IPONumberResultField Converter::CTORATstpIPONumberResultFieldToRust(CTORATstpIPONumberResultField* x) {
    if (x == nullptr)
        return IPONumberResultField{.is_null = true};
    IPONumberResultField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.ExchangeID = x->ExchangeID;
    y.Day = Converter::GbkToRustString(x->Day);
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.SecurityType = x->SecurityType;
    y.BeginNumberID = Converter::GbkToRustString(x->BeginNumberID);
    y.Volume = x->Volume;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    return y;
}

CTORATstpQryIPOMatchNumberResultField Converter::QryIPOMatchNumberResultFieldToCpp(QryIPOMatchNumberResultField x) {
    CTORATstpQryIPOMatchNumberResultField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.MatchNumberID, x.MatchNumberID.c_str());
    return y;
}

QryIPOMatchNumberResultField Converter::CTORATstpQryIPOMatchNumberResultFieldToRust(CTORATstpQryIPOMatchNumberResultField* x) {
    if (x == nullptr)
        return QryIPOMatchNumberResultField{.is_null = true};
    QryIPOMatchNumberResultField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.MatchNumberID = Converter::GbkToRustString(x->MatchNumberID);
    return y;
}

CTORATstpIPOMatchNumberResultField Converter::IPOMatchNumberResultFieldToCpp(IPOMatchNumberResultField x) {
    CTORATstpIPOMatchNumberResultField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.MatchNumberID, x.MatchNumberID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.Day, x.Day.c_str());
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.SecurityType = x.SecurityType;
    y.Volume = x.Volume;
    y.Price = x.Price;
    y.Amout = x.Amout;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    return y;
}

IPOMatchNumberResultField Converter::CTORATstpIPOMatchNumberResultFieldToRust(CTORATstpIPOMatchNumberResultField* x) {
    if (x == nullptr)
        return IPOMatchNumberResultField{.is_null = true};
    IPOMatchNumberResultField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.MatchNumberID = Converter::GbkToRustString(x->MatchNumberID);
    y.ExchangeID = x->ExchangeID;
    y.Day = Converter::GbkToRustString(x->Day);
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.SecurityType = x->SecurityType;
    y.Volume = x->Volume;
    y.Price = x->Price;
    y.Amout = x->Amout;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    return y;
}

CTORATstpQryShareholderSpecPrivilegeField Converter::QryShareholderSpecPrivilegeFieldToCpp(QryShareholderSpecPrivilegeField x) {
    CTORATstpQryShareholderSpecPrivilegeField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.SpecPrivilegeType = x.SpecPrivilegeType;
    y.Direction = x.Direction;
    y.MarketID = x.MarketID;
    return y;
}

QryShareholderSpecPrivilegeField Converter::CTORATstpQryShareholderSpecPrivilegeFieldToRust(CTORATstpQryShareholderSpecPrivilegeField* x) {
    if (x == nullptr)
        return QryShareholderSpecPrivilegeField{.is_null = true};
    QryShareholderSpecPrivilegeField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SpecPrivilegeType = x->SpecPrivilegeType;
    y.Direction = x->Direction;
    y.MarketID = x->MarketID;
    return y;
}

CTORATstpShareholderSpecPrivilegeField Converter::ShareholderSpecPrivilegeFieldToCpp(ShareholderSpecPrivilegeField x) {
    CTORATstpShareholderSpecPrivilegeField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.MarketID = x.MarketID;
    y.SpecPrivilegeType = x.SpecPrivilegeType;
    y.Direction = x.Direction;
    y.bForbidden = x.bForbidden;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    return y;
}

ShareholderSpecPrivilegeField Converter::CTORATstpShareholderSpecPrivilegeFieldToRust(CTORATstpShareholderSpecPrivilegeField* x) {
    if (x == nullptr)
        return ShareholderSpecPrivilegeField{.is_null = true};
    ShareholderSpecPrivilegeField y{};
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.MarketID = x->MarketID;
    y.SpecPrivilegeType = x->SpecPrivilegeType;
    y.Direction = x->Direction;
    y.bForbidden = x->bForbidden;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    return y;
}

CTORATstpQryMarketField Converter::QryMarketFieldToCpp(QryMarketField x) {
    CTORATstpQryMarketField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    return y;
}

QryMarketField Converter::CTORATstpQryMarketFieldToRust(CTORATstpQryMarketField* x) {
    if (x == nullptr)
        return QryMarketField{.is_null = true};
    QryMarketField y{};
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    return y;
}

CTORATstpMarketField Converter::MarketFieldToCpp(MarketField x) {
    CTORATstpMarketField y;
    memset(&y, 0, sizeof(y));
    y.MarketID = x.MarketID;
    strcpy(y.MarketName, x.MarketName.c_str());
    y.ExchangeID = x.ExchangeID;
    y.MarketStatus = x.MarketStatus;
    return y;
}

MarketField Converter::CTORATstpMarketFieldToRust(CTORATstpMarketField* x) {
    if (x == nullptr)
        return MarketField{.is_null = true};
    MarketField y{};
    y.MarketID = x->MarketID;
    y.MarketName = Converter::GbkToRustString(x->MarketName);
    y.ExchangeID = x->ExchangeID;
    y.MarketStatus = x->MarketStatus;
    return y;
}

CTORATstpQryETFFileField Converter::QryETFFileFieldToCpp(QryETFFileField x) {
    CTORATstpQryETFFileField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ETFSecurityID, x.ETFSecurityID.c_str());
    strcpy(y.ETFCreRedSecurityID, x.ETFCreRedSecurityID.c_str());
    return y;
}

QryETFFileField Converter::CTORATstpQryETFFileFieldToRust(CTORATstpQryETFFileField* x) {
    if (x == nullptr)
        return QryETFFileField{.is_null = true};
    QryETFFileField y{};
    y.ExchangeID = x->ExchangeID;
    y.ETFSecurityID = Converter::GbkToRustString(x->ETFSecurityID);
    y.ETFCreRedSecurityID = Converter::GbkToRustString(x->ETFCreRedSecurityID);
    return y;
}

CTORATstpETFFileField Converter::ETFFileFieldToCpp(ETFFileField x) {
    CTORATstpETFFileField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ETFSecurityID, x.ETFSecurityID.c_str());
    strcpy(y.ETFCreRedSecurityID, x.ETFCreRedSecurityID.c_str());
    y.CreationRedemptionUnit = x.CreationRedemptionUnit;
    y.Maxcashratio = x.Maxcashratio;
    y.EstimateCashComponent = x.EstimateCashComponent;
    y.CashComponent = x.CashComponent;
    y.NAV = x.NAV;
    y.NAVperCU = x.NAVperCU;
    y.DividendPerCU = x.DividendPerCU;
    y.ETFCreRedType = x.ETFCreRedType;
    strcpy(y.ETFSecurityName, x.ETFSecurityName.c_str());
    return y;
}

ETFFileField Converter::CTORATstpETFFileFieldToRust(CTORATstpETFFileField* x) {
    if (x == nullptr)
        return ETFFileField{.is_null = true};
    ETFFileField y{};
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.ExchangeID = x->ExchangeID;
    y.ETFSecurityID = Converter::GbkToRustString(x->ETFSecurityID);
    y.ETFCreRedSecurityID = Converter::GbkToRustString(x->ETFCreRedSecurityID);
    y.CreationRedemptionUnit = x->CreationRedemptionUnit;
    y.Maxcashratio = x->Maxcashratio;
    y.EstimateCashComponent = x->EstimateCashComponent;
    y.CashComponent = x->CashComponent;
    y.NAV = x->NAV;
    y.NAVperCU = x->NAVperCU;
    y.DividendPerCU = x->DividendPerCU;
    y.ETFCreRedType = x->ETFCreRedType;
    y.ETFSecurityName = Converter::GbkToRustString(x->ETFSecurityName);
    return y;
}

CTORATstpQryETFBasketField Converter::QryETFBasketFieldToCpp(QryETFBasketField x) {
    CTORATstpQryETFBasketField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ETFSecurityID, x.ETFSecurityID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

QryETFBasketField Converter::CTORATstpQryETFBasketFieldToRust(CTORATstpQryETFBasketField* x) {
    if (x == nullptr)
        return QryETFBasketField{.is_null = true};
    QryETFBasketField y{};
    y.ExchangeID = x->ExchangeID;
    y.ETFSecurityID = Converter::GbkToRustString(x->ETFSecurityID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpETFBasketField Converter::ETFBasketFieldToCpp(ETFBasketField x) {
    CTORATstpETFBasketField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ETFSecurityID, x.ETFSecurityID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.Volume = x.Volume;
    y.ETFCurrenceReplaceStatus = x.ETFCurrenceReplaceStatus;
    y.Premium = x.Premium;
    y.CreationReplaceAmount = x.CreationReplaceAmount;
    y.RedemptionReplaceAmount = x.RedemptionReplaceAmount;
    y.MarketID = x.MarketID;
    y.ETFCreRedType = x.ETFCreRedType;
    return y;
}

ETFBasketField Converter::CTORATstpETFBasketFieldToRust(CTORATstpETFBasketField* x) {
    if (x == nullptr)
        return ETFBasketField{.is_null = true};
    ETFBasketField y{};
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.ExchangeID = x->ExchangeID;
    y.ETFSecurityID = Converter::GbkToRustString(x->ETFSecurityID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.Volume = x->Volume;
    y.ETFCurrenceReplaceStatus = x->ETFCurrenceReplaceStatus;
    y.Premium = x->Premium;
    y.CreationReplaceAmount = x->CreationReplaceAmount;
    y.RedemptionReplaceAmount = x->RedemptionReplaceAmount;
    y.MarketID = x->MarketID;
    y.ETFCreRedType = x->ETFCreRedType;
    return y;
}

CTORATstpQryInvestorPositionLimitField Converter::QryInvestorPositionLimitFieldToCpp(QryInvestorPositionLimitField x) {
    CTORATstpQryInvestorPositionLimitField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

QryInvestorPositionLimitField Converter::CTORATstpQryInvestorPositionLimitFieldToRust(CTORATstpQryInvestorPositionLimitField* x) {
    if (x == nullptr)
        return QryInvestorPositionLimitField{.is_null = true};
    QryInvestorPositionLimitField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpInvestorPositionLimitField Converter::InvestorPositionLimitFieldToCpp(InvestorPositionLimitField x) {
    CTORATstpInvestorPositionLimitField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.BuyLimit = x.BuyLimit;
    y.BuyFrozen = x.BuyFrozen;
    y.SellLimit = x.SellLimit;
    y.SellFrozen = x.SellFrozen;
    y.PurchaseLimit = x.PurchaseLimit;
    y.PurchaseFrozen = x.PurchaseFrozen;
    y.RedeemLimit = x.RedeemLimit;
    y.RedeemFrozen = x.RedeemFrozen;
    y.PledgeInLimit = x.PledgeInLimit;
    y.PledgeInFrozen = x.PledgeInFrozen;
    y.PledgeOutLimit = x.PledgeOutLimit;
    y.PledgeOutFrozen = x.PledgeOutFrozen;
    y.ConvertLimit = x.ConvertLimit;
    y.ConvertFrozen = x.ConvertFrozen;
    y.PutbackLimit = x.PutbackLimit;
    y.PutbackFrozen = x.PutbackFrozen;
    y.RationalLimit = x.RationalLimit;
    y.RationalFrozen = x.RationalFrozen;
    y.TotalPositionLimit = x.TotalPositionLimit;
    y.TotalPositionFrozen = x.TotalPositionFrozen;
    y.SplitLimit = x.SplitLimit;
    y.SplitFrozen = x.SplitFrozen;
    y.MergeLimit = x.MergeLimit;
    y.MergeFrozen = x.MergeFrozen;
    memcpy(y.UUPIC, x.UUPIC.data(), x.UUPIC.size() * sizeof(uint8_t));
    return y;
}

InvestorPositionLimitField Converter::CTORATstpInvestorPositionLimitFieldToRust(CTORATstpInvestorPositionLimitField* x) {
    if (x == nullptr)
        return InvestorPositionLimitField{.is_null = true};
    InvestorPositionLimitField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.BuyLimit = x->BuyLimit;
    y.BuyFrozen = x->BuyFrozen;
    y.SellLimit = x->SellLimit;
    y.SellFrozen = x->SellFrozen;
    y.PurchaseLimit = x->PurchaseLimit;
    y.PurchaseFrozen = x->PurchaseFrozen;
    y.RedeemLimit = x->RedeemLimit;
    y.RedeemFrozen = x->RedeemFrozen;
    y.PledgeInLimit = x->PledgeInLimit;
    y.PledgeInFrozen = x->PledgeInFrozen;
    y.PledgeOutLimit = x->PledgeOutLimit;
    y.PledgeOutFrozen = x->PledgeOutFrozen;
    y.ConvertLimit = x->ConvertLimit;
    y.ConvertFrozen = x->ConvertFrozen;
    y.PutbackLimit = x->PutbackLimit;
    y.PutbackFrozen = x->PutbackFrozen;
    y.RationalLimit = x->RationalLimit;
    y.RationalFrozen = x->RationalFrozen;
    y.TotalPositionLimit = x->TotalPositionLimit;
    y.TotalPositionFrozen = x->TotalPositionFrozen;
    y.SplitLimit = x->SplitLimit;
    y.SplitFrozen = x->SplitFrozen;
    y.MergeLimit = x->MergeLimit;
    y.MergeFrozen = x->MergeFrozen;
    for (int i = 0; i < 16; i++)
        y.UUPIC.push_back(x->UUPIC[i]);
    return y;
}

CTORATstpQryImcParamsField Converter::QryImcParamsFieldToCpp(QryImcParamsField x) {
    CTORATstpQryImcParamsField y;
    memset(&y, 0, sizeof(y));
    y.MarketID = x.MarketID;
    return y;
}

QryImcParamsField Converter::CTORATstpQryImcParamsFieldToRust(CTORATstpQryImcParamsField* x) {
    if (x == nullptr)
        return QryImcParamsField{.is_null = true};
    QryImcParamsField y{};
    y.MarketID = x->MarketID;
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

CTORATstpQryImcExchangeRateField Converter::QryImcExchangeRateFieldToCpp(QryImcExchangeRateField x) {
    CTORATstpQryImcExchangeRateField y;
    memset(&y, 0, sizeof(y));
    y.FromCurrency = x.FromCurrency;
    y.ToCurrency = x.ToCurrency;
    y.MarketID = x.MarketID;
    return y;
}

QryImcExchangeRateField Converter::CTORATstpQryImcExchangeRateFieldToRust(CTORATstpQryImcExchangeRateField* x) {
    if (x == nullptr)
        return QryImcExchangeRateField{.is_null = true};
    QryImcExchangeRateField y{};
    y.FromCurrency = x->FromCurrency;
    y.ToCurrency = x->ToCurrency;
    y.MarketID = x->MarketID;
    return y;
}

CTORATstpImcExchangeRateField Converter::ImcExchangeRateFieldToCpp(ImcExchangeRateField x) {
    CTORATstpImcExchangeRateField y;
    memset(&y, 0, sizeof(y));
    y.FromCurrency = x.FromCurrency;
    y.ToCurrency = x.ToCurrency;
    y.BidRate = x.BidRate;
    y.OfferRate = x.OfferRate;
    y.MidPointRate = x.MidPointRate;
    y.MarketID = x.MarketID;
    return y;
}

ImcExchangeRateField Converter::CTORATstpImcExchangeRateFieldToRust(CTORATstpImcExchangeRateField* x) {
    if (x == nullptr)
        return ImcExchangeRateField{.is_null = true};
    ImcExchangeRateField y{};
    y.FromCurrency = x->FromCurrency;
    y.ToCurrency = x->ToCurrency;
    y.BidRate = x->BidRate;
    y.OfferRate = x->OfferRate;
    y.MidPointRate = x->MidPointRate;
    y.MarketID = x->MarketID;
    return y;
}

CTORATstpQryHKPriceTickInfoField Converter::QryHKPriceTickInfoFieldToCpp(QryHKPriceTickInfoField x) {
    CTORATstpQryHKPriceTickInfoField y;
    memset(&y, 0, sizeof(y));
    y.PriceTickID = x.PriceTickID;
    y.MarketID = x.MarketID;
    return y;
}

QryHKPriceTickInfoField Converter::CTORATstpQryHKPriceTickInfoFieldToRust(CTORATstpQryHKPriceTickInfoField* x) {
    if (x == nullptr)
        return QryHKPriceTickInfoField{.is_null = true};
    QryHKPriceTickInfoField y{};
    y.PriceTickID = x->PriceTickID;
    y.MarketID = x->MarketID;
    return y;
}

CTORATstpHKPriceTickInfoField Converter::HKPriceTickInfoFieldToCpp(HKPriceTickInfoField x) {
    CTORATstpHKPriceTickInfoField y;
    memset(&y, 0, sizeof(y));
    y.PriceTickID = x.PriceTickID;
    y.PriceTickGroupID = x.PriceTickGroupID;
    y.PriceTickType = x.PriceTickType;
    y.BeginPrice = x.BeginPrice;
    y.EndPrice = x.EndPrice;
    y.PriceTick = x.PriceTick;
    y.MarketID = x.MarketID;
    return y;
}

HKPriceTickInfoField Converter::CTORATstpHKPriceTickInfoFieldToRust(CTORATstpHKPriceTickInfoField* x) {
    if (x == nullptr)
        return HKPriceTickInfoField{.is_null = true};
    HKPriceTickInfoField y{};
    y.PriceTickID = x->PriceTickID;
    y.PriceTickGroupID = x->PriceTickGroupID;
    y.PriceTickType = x->PriceTickType;
    y.BeginPrice = x->BeginPrice;
    y.EndPrice = x->EndPrice;
    y.PriceTick = x->PriceTick;
    y.MarketID = x->MarketID;
    return y;
}

CTORATstpQryLofFundInfoField Converter::QryLofFundInfoFieldToCpp(QryLofFundInfoField x) {
    CTORATstpQryLofFundInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.FundID, x.FundID.c_str());
    strcpy(y.MainFundID, x.MainFundID.c_str());
    return y;
}

QryLofFundInfoField Converter::CTORATstpQryLofFundInfoFieldToRust(CTORATstpQryLofFundInfoField* x) {
    if (x == nullptr)
        return QryLofFundInfoField{.is_null = true};
    QryLofFundInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.FundID = Converter::GbkToRustString(x->FundID);
    y.MainFundID = Converter::GbkToRustString(x->MainFundID);
    return y;
}

CTORATstpLofFundInfoField Converter::LofFundInfoFieldToCpp(LofFundInfoField x) {
    CTORATstpLofFundInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.FundID, x.FundID.c_str());
    strcpy(y.MainFundID, x.MainFundID.c_str());
    y.FundType = x.FundType;
    y.SplitUnit = x.SplitUnit;
    y.SplitMinVol = x.SplitMinVol;
    y.MergeUnit = x.MergeUnit;
    y.MergeMinVol = x.MergeMinVol;
    y.FundRatio = x.FundRatio;
    return y;
}

LofFundInfoField Converter::CTORATstpLofFundInfoFieldToRust(CTORATstpLofFundInfoField* x) {
    if (x == nullptr)
        return LofFundInfoField{.is_null = true};
    LofFundInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.FundID = Converter::GbkToRustString(x->FundID);
    y.MainFundID = Converter::GbkToRustString(x->MainFundID);
    y.FundType = x->FundType;
    y.SplitUnit = x->SplitUnit;
    y.SplitMinVol = x->SplitMinVol;
    y.MergeUnit = x->MergeUnit;
    y.MergeMinVol = x->MergeMinVol;
    y.FundRatio = x->FundRatio;
    return y;
}

CTORATstpQryPledgePositionField Converter::QryPledgePositionFieldToCpp(QryPledgePositionField x) {
    CTORATstpQryPledgePositionField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    return y;
}

QryPledgePositionField Converter::CTORATstpQryPledgePositionFieldToRust(CTORATstpQryPledgePositionField* x) {
    if (x == nullptr)
        return QryPledgePositionField{.is_null = true};
    QryPledgePositionField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    return y;
}

CTORATstpPledgePositionField Converter::PledgePositionFieldToCpp(PledgePositionField x) {
    CTORATstpPledgePositionField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.HisPledgePos = x.HisPledgePos;
    y.HisPledgePosFrozen = x.HisPledgePosFrozen;
    y.TodayPledgePos = x.TodayPledgePos;
    y.TodayPledgePosFrozen = x.TodayPledgePosFrozen;
    y.PreTotalPledgePos = x.PreTotalPledgePos;
    y.PreAvailablePledgePos = x.PreAvailablePledgePos;
    return y;
}

PledgePositionField Converter::CTORATstpPledgePositionFieldToRust(CTORATstpPledgePositionField* x) {
    if (x == nullptr)
        return PledgePositionField{.is_null = true};
    PledgePositionField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.HisPledgePos = x->HisPledgePos;
    y.HisPledgePosFrozen = x->HisPledgePosFrozen;
    y.TodayPledgePos = x->TodayPledgePos;
    y.TodayPledgePosFrozen = x->TodayPledgePosFrozen;
    y.PreTotalPledgePos = x->PreTotalPledgePos;
    y.PreAvailablePledgePos = x->PreAvailablePledgePos;
    return y;
}

CTORATstpQryPledgeInfoField Converter::QryPledgeInfoFieldToCpp(QryPledgeInfoField x) {
    CTORATstpQryPledgeInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

QryPledgeInfoField Converter::CTORATstpQryPledgeInfoFieldToRust(CTORATstpQryPledgeInfoField* x) {
    if (x == nullptr)
        return QryPledgeInfoField{.is_null = true};
    QryPledgeInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpPledgeInfoField Converter::PledgeInfoFieldToCpp(PledgeInfoField x) {
    CTORATstpPledgeInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.PledgeOrderID, x.PledgeOrderID.c_str());
    strcpy(y.PledgeName, x.PledgeName.c_str());
    strcpy(y.StandardBondID, x.StandardBondID.c_str());
    y.ConversionRate = x.ConversionRate;
    y.PledgeInTradingUnit = x.PledgeInTradingUnit;
    y.PledgeOutTradingUnit = x.PledgeOutTradingUnit;
    y.PledgeInVolMax = x.PledgeInVolMax;
    y.PledgeInVolMin = x.PledgeInVolMin;
    y.PledgeOutVolMax = x.PledgeOutVolMax;
    y.PledgeOutVolMin = x.PledgeOutVolMin;
    return y;
}

PledgeInfoField Converter::CTORATstpPledgeInfoFieldToRust(CTORATstpPledgeInfoField* x) {
    if (x == nullptr)
        return PledgeInfoField{.is_null = true};
    PledgeInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.PledgeOrderID = Converter::GbkToRustString(x->PledgeOrderID);
    y.PledgeName = Converter::GbkToRustString(x->PledgeName);
    y.StandardBondID = Converter::GbkToRustString(x->StandardBondID);
    y.ConversionRate = x->ConversionRate;
    y.PledgeInTradingUnit = x->PledgeInTradingUnit;
    y.PledgeOutTradingUnit = x->PledgeOutTradingUnit;
    y.PledgeInVolMax = x->PledgeInVolMax;
    y.PledgeInVolMin = x->PledgeInVolMin;
    y.PledgeOutVolMax = x->PledgeOutVolMax;
    y.PledgeOutVolMin = x->PledgeOutVolMin;
    return y;
}

CTORATstpQrySystemNodeInfoField Converter::QrySystemNodeInfoFieldToCpp(QrySystemNodeInfoField x) {
    CTORATstpQrySystemNodeInfoField y;
    memset(&y, 0, sizeof(y));
    y.NodeID = x.NodeID;
    return y;
}

QrySystemNodeInfoField Converter::CTORATstpQrySystemNodeInfoFieldToRust(CTORATstpQrySystemNodeInfoField* x) {
    if (x == nullptr)
        return QrySystemNodeInfoField{.is_null = true};
    QrySystemNodeInfoField y{};
    y.NodeID = x->NodeID;
    return y;
}

CTORATstpSystemNodeInfoField Converter::SystemNodeInfoFieldToCpp(SystemNodeInfoField x) {
    CTORATstpSystemNodeInfoField y;
    memset(&y, 0, sizeof(y));
    y.NodeID = x.NodeID;
    strcpy(y.NodeInfo, x.NodeInfo.c_str());
    y.bCurrent = x.bCurrent;
    return y;
}

SystemNodeInfoField Converter::CTORATstpSystemNodeInfoFieldToRust(CTORATstpSystemNodeInfoField* x) {
    if (x == nullptr)
        return SystemNodeInfoField{.is_null = true};
    SystemNodeInfoField y{};
    y.NodeID = x->NodeID;
    y.NodeInfo = Converter::GbkToRustString(x->NodeInfo);
    y.bCurrent = x->bCurrent;
    return y;
}

CTORATstpQryStandardBondPositionField Converter::QryStandardBondPositionFieldToCpp(QryStandardBondPositionField x) {
    CTORATstpQryStandardBondPositionField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    return y;
}

QryStandardBondPositionField Converter::CTORATstpQryStandardBondPositionFieldToRust(CTORATstpQryStandardBondPositionField* x) {
    if (x == nullptr)
        return QryStandardBondPositionField{.is_null = true};
    QryStandardBondPositionField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    return y;
}

CTORATstpStandardBondPositionField Converter::StandardBondPositionFieldToCpp(StandardBondPositionField x) {
    CTORATstpStandardBondPositionField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.TradingDay, x.TradingDay.c_str());
    y.AvailablePosition = x.AvailablePosition;
    y.AvailablePosFrozen = x.AvailablePosFrozen;
    y.TotalPosition = x.TotalPosition;
    return y;
}

StandardBondPositionField Converter::CTORATstpStandardBondPositionFieldToRust(CTORATstpStandardBondPositionField* x) {
    if (x == nullptr)
        return StandardBondPositionField{.is_null = true};
    StandardBondPositionField y{};
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.AvailablePosition = x->AvailablePosition;
    y.AvailablePosFrozen = x->AvailablePosFrozen;
    y.TotalPosition = x->TotalPosition;
    return y;
}

CTORATstpQryPrematurityRepoOrderField Converter::QryPrematurityRepoOrderFieldToCpp(QryPrematurityRepoOrderField x) {
    CTORATstpQryPrematurityRepoOrderField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    y.ProductID = x.ProductID;
    y.SecurityType = x.SecurityType;
    y.Direction = x.Direction;
    strcpy(y.TradeID, x.TradeID.c_str());
    return y;
}

QryPrematurityRepoOrderField Converter::CTORATstpQryPrematurityRepoOrderFieldToRust(CTORATstpQryPrematurityRepoOrderField* x) {
    if (x == nullptr)
        return QryPrematurityRepoOrderField{.is_null = true};
    QryPrematurityRepoOrderField y{};
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.ProductID = x->ProductID;
    y.SecurityType = x->SecurityType;
    y.Direction = x->Direction;
    y.TradeID = Converter::GbkToRustString(x->TradeID);
    return y;
}

CTORATstpPrematurityRepoOrderField Converter::PrematurityRepoOrderFieldToCpp(PrematurityRepoOrderField x) {
    CTORATstpPrematurityRepoOrderField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    y.MarketID = x.MarketID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.TradeDay, x.TradeDay.c_str());
    strcpy(y.ExpireDay, x.ExpireDay.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.ProductID = x.ProductID;
    y.SecurityType = x.SecurityType;
    y.Direction = x.Direction;
    y.VolumeTraded = x.VolumeTraded;
    y.Price = x.Price;
    y.Turnover = x.Turnover;
    strcpy(y.TradeID, x.TradeID.c_str());
    y.RepoTotalMoney = x.RepoTotalMoney;
    y.InterestAmount = x.InterestAmount;
    return y;
}

PrematurityRepoOrderField Converter::CTORATstpPrematurityRepoOrderFieldToRust(CTORATstpPrematurityRepoOrderField* x) {
    if (x == nullptr)
        return PrematurityRepoOrderField{.is_null = true};
    PrematurityRepoOrderField y{};
    y.ExchangeID = x->ExchangeID;
    y.MarketID = x->MarketID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.TradeDay = Converter::GbkToRustString(x->TradeDay);
    y.ExpireDay = Converter::GbkToRustString(x->ExpireDay);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.ProductID = x->ProductID;
    y.SecurityType = x->SecurityType;
    y.Direction = x->Direction;
    y.VolumeTraded = x->VolumeTraded;
    y.Price = x->Price;
    y.Turnover = x->Turnover;
    y.TradeID = Converter::GbkToRustString(x->TradeID);
    y.RepoTotalMoney = x->RepoTotalMoney;
    y.InterestAmount = x->InterestAmount;
    return y;
}

CTORATstpQryNegoOrderField Converter::QryNegoOrderFieldToCpp(QryNegoOrderField x) {
    CTORATstpQryNegoOrderField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    memcpy(y.InsertTimeStart, x.InsertTimeStart.data(), x.InsertTimeStart.size() * sizeof(uint8_t));
    memcpy(y.InsertTimeEnd, x.InsertTimeEnd.data(), x.InsertTimeEnd.size() * sizeof(uint8_t));
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

QryNegoOrderField Converter::CTORATstpQryNegoOrderFieldToRust(CTORATstpQryNegoOrderField* x) {
    if (x == nullptr)
        return QryNegoOrderField{.is_null = true};
    QryNegoOrderField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    for (int i = 0; i < 9; i++)
        y.InsertTimeStart.push_back(x->InsertTimeStart[i]);
    for (int i = 0; i < 9; i++)
        y.InsertTimeEnd.push_back(x->InsertTimeEnd[i]);
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpQryNegoOrderActionField Converter::QryNegoOrderActionFieldToCpp(QryNegoOrderActionField x) {
    CTORATstpQryNegoOrderActionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    strcpy(y.CancelOrderLocalID, x.CancelOrderLocalID.c_str());
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    return y;
}

QryNegoOrderActionField Converter::CTORATstpQryNegoOrderActionFieldToRust(CTORATstpQryNegoOrderActionField* x) {
    if (x == nullptr)
        return QryNegoOrderActionField{.is_null = true};
    QryNegoOrderActionField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.CancelOrderLocalID = Converter::GbkToRustString(x->CancelOrderLocalID);
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    return y;
}

CTORATstpNegoOrderActionField Converter::NegoOrderActionFieldToCpp(NegoOrderActionField x) {
    CTORATstpNegoOrderActionField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.ActionFlag = x.ActionFlag;
    strcpy(y.CancelOrderLocalID, x.CancelOrderLocalID.c_str());
    strcpy(y.CancelOrderSysID, x.CancelOrderSysID.c_str());
    strcpy(y.OrderSysID, x.OrderSysID.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    y.Operway = x.Operway;
    strcpy(y.SInfo, x.SInfo.c_str());
    y.IInfo = x.IInfo;
    strcpy(y.DepartmentID, x.DepartmentID.c_str());
    memcpy(y.ActionUser, x.ActionUser.data(), x.ActionUser.size() * sizeof(uint8_t));
    strcpy(y.TradingDay, x.TradingDay.c_str());
    strcpy(y.ActionDate, x.ActionDate.c_str());
    strcpy(y.ActionTime, x.ActionTime.c_str());
    y.CancelOrderStatus = x.CancelOrderStatus;
    strcpy(y.StatusMsg, x.StatusMsg.c_str());
    y.RequestID = x.RequestID;
    y.ActionFrontID = x.ActionFrontID;
    y.ActionSessionID = x.ActionSessionID;
    strcpy(y.PbuID, x.PbuID.c_str());
    strcpy(y.IPAddress, x.IPAddress.c_str());
    strcpy(y.MacAddress, x.MacAddress.c_str());
    return y;
}

NegoOrderActionField Converter::CTORATstpNegoOrderActionFieldToRust(CTORATstpNegoOrderActionField* x) {
    if (x == nullptr)
        return NegoOrderActionField{.is_null = true};
    NegoOrderActionField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.ActionFlag = x->ActionFlag;
    y.CancelOrderLocalID = Converter::GbkToRustString(x->CancelOrderLocalID);
    y.CancelOrderSysID = Converter::GbkToRustString(x->CancelOrderSysID);
    y.OrderSysID = Converter::GbkToRustString(x->OrderSysID);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.Operway = x->Operway;
    y.SInfo = Converter::GbkToRustString(x->SInfo);
    y.IInfo = x->IInfo;
    y.DepartmentID = Converter::GbkToRustString(x->DepartmentID);
    for (int i = 0; i < 16; i++)
        y.ActionUser.push_back(x->ActionUser[i]);
    y.TradingDay = Converter::GbkToRustString(x->TradingDay);
    y.ActionDate = Converter::GbkToRustString(x->ActionDate);
    y.ActionTime = Converter::GbkToRustString(x->ActionTime);
    y.CancelOrderStatus = x->CancelOrderStatus;
    y.StatusMsg = Converter::GbkToRustString(x->StatusMsg);
    y.RequestID = x->RequestID;
    y.ActionFrontID = x->ActionFrontID;
    y.ActionSessionID = x->ActionSessionID;
    y.PbuID = Converter::GbkToRustString(x->PbuID);
    y.IPAddress = Converter::GbkToRustString(x->IPAddress);
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    return y;
}

CTORATstpQryNegoTradeField Converter::QryNegoTradeFieldToCpp(QryNegoTradeField x) {
    CTORATstpQryNegoTradeField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.InvestorID, x.InvestorID.c_str());
    strcpy(y.BusinessUnitID, x.BusinessUnitID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.TradeID, x.TradeID.c_str());
    memcpy(y.TradeTimeStart, x.TradeTimeStart.data(), x.TradeTimeStart.size() * sizeof(uint8_t));
    memcpy(y.TradeTimeEnd, x.TradeTimeEnd.data(), x.TradeTimeEnd.size() * sizeof(uint8_t));
    return y;
}

QryNegoTradeField Converter::CTORATstpQryNegoTradeFieldToRust(CTORATstpQryNegoTradeField* x) {
    if (x == nullptr)
        return QryNegoTradeField{.is_null = true};
    QryNegoTradeField y{};
    y.ExchangeID = x->ExchangeID;
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.BusinessUnitID = Converter::GbkToRustString(x->BusinessUnitID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.TradeID = Converter::GbkToRustString(x->TradeID);
    for (int i = 0; i < 9; i++)
        y.TradeTimeStart.push_back(x->TradeTimeStart[i]);
    for (int i = 0; i < 9; i++)
        y.TradeTimeEnd.push_back(x->TradeTimeEnd[i]);
    return y;
}

CTORATstpQryNegotiationParamField Converter::QryNegotiationParamFieldToCpp(QryNegotiationParamField x) {
    CTORATstpQryNegotiationParamField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

QryNegotiationParamField Converter::CTORATstpQryNegotiationParamFieldToRust(CTORATstpQryNegotiationParamField* x) {
    if (x == nullptr)
        return QryNegotiationParamField{.is_null = true};
    QryNegotiationParamField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpNegotiationParamField Converter::NegotiationParamFieldToCpp(NegotiationParamField x) {
    CTORATstpNegotiationParamField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    y.BuyTradingUnit = x.BuyTradingUnit;
    y.SellTradingUnit = x.SellTradingUnit;
    y.MinOrderVolume = x.MinOrderVolume;
    y.MinOrderAmt = x.MinOrderAmt;
    y.PriceTick = x.PriceTick;
    y.UpperLimitPrice = x.UpperLimitPrice;
    y.LowerLimitPrice = x.LowerLimitPrice;
    y.bMarketMaker = x.bMarketMaker;
    return y;
}

NegotiationParamField Converter::CTORATstpNegotiationParamFieldToRust(CTORATstpNegotiationParamField* x) {
    if (x == nullptr)
        return NegotiationParamField{.is_null = true};
    NegotiationParamField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.BuyTradingUnit = x->BuyTradingUnit;
    y.SellTradingUnit = x->SellTradingUnit;
    y.MinOrderVolume = x->MinOrderVolume;
    y.MinOrderAmt = x->MinOrderAmt;
    y.PriceTick = x->PriceTick;
    y.UpperLimitPrice = x->UpperLimitPrice;
    y.LowerLimitPrice = x->LowerLimitPrice;
    y.bMarketMaker = x->bMarketMaker;
    return y;
}

CTORATstpQryPublicOfferedFundInfoField Converter::QryPublicOfferedFundInfoFieldToCpp(QryPublicOfferedFundInfoField x) {
    CTORATstpQryPublicOfferedFundInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ManagerID, x.ManagerID.c_str());
    return y;
}

QryPublicOfferedFundInfoField Converter::CTORATstpQryPublicOfferedFundInfoFieldToRust(CTORATstpQryPublicOfferedFundInfoField* x) {
    if (x == nullptr)
        return QryPublicOfferedFundInfoField{.is_null = true};
    QryPublicOfferedFundInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ManagerID = Converter::GbkToRustString(x->ManagerID);
    return y;
}

CTORATstpPublicOfferedFundInfoField Converter::PublicOfferedFundInfoFieldToCpp(PublicOfferedFundInfoField x) {
    CTORATstpPublicOfferedFundInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ManagerID, x.ManagerID.c_str());
    strcpy(y.ForwardPbuID, x.ForwardPbuID.c_str());
    strcpy(y.ForwardShareholderID, x.ForwardShareholderID.c_str());
    return y;
}

PublicOfferedFundInfoField Converter::CTORATstpPublicOfferedFundInfoFieldToRust(CTORATstpPublicOfferedFundInfoField* x) {
    if (x == nullptr)
        return PublicOfferedFundInfoField{.is_null = true};
    PublicOfferedFundInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ManagerID = Converter::GbkToRustString(x->ManagerID);
    y.ForwardPbuID = Converter::GbkToRustString(x->ForwardPbuID);
    y.ForwardShareholderID = Converter::GbkToRustString(x->ForwardShareholderID);
    return y;
}

CTORATstpQryPublicOfferedFundTradeDetailField Converter::QryPublicOfferedFundTradeDetailFieldToCpp(QryPublicOfferedFundTradeDetailField x) {
    CTORATstpQryPublicOfferedFundTradeDetailField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.FundSecurityID, x.FundSecurityID.c_str());
    strcpy(y.ManagerID, x.ManagerID.c_str());
    y.IndexStart = x.IndexStart;
    y.IndexEnd = x.IndexEnd;
    return y;
}

QryPublicOfferedFundTradeDetailField Converter::CTORATstpQryPublicOfferedFundTradeDetailFieldToRust(CTORATstpQryPublicOfferedFundTradeDetailField* x) {
    if (x == nullptr)
        return QryPublicOfferedFundTradeDetailField{.is_null = true};
    QryPublicOfferedFundTradeDetailField y{};
    y.ExchangeID = x->ExchangeID;
    y.FundSecurityID = Converter::GbkToRustString(x->FundSecurityID);
    y.ManagerID = Converter::GbkToRustString(x->ManagerID);
    y.IndexStart = x->IndexStart;
    y.IndexEnd = x->IndexEnd;
    return y;
}

CTORATstpPublicOfferedFundTradeDetailField Converter::PublicOfferedFundTradeDetailFieldToCpp(PublicOfferedFundTradeDetailField x) {
    CTORATstpPublicOfferedFundTradeDetailField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    y.Direction = x.Direction;
    strcpy(y.FundSecurityID, x.FundSecurityID.c_str());
    strcpy(y.BasketSecurityID, x.BasketSecurityID.c_str());
    y.TradeReportType = x.TradeReportType;
    strcpy(y.TradeID, x.TradeID.c_str());
    strcpy(y.PbuID, x.PbuID.c_str());
    strcpy(y.OrderLocalID, x.OrderLocalID.c_str());
    strcpy(y.ExchOrderID, x.ExchOrderID.c_str());
    y.TradeReportNums = x.TradeReportNums;
    y.DeliveryVolume = x.DeliveryVolume;
    y.TotalSubsCash = x.TotalSubsCash;
    y.SSESubsCash = x.SSESubsCash;
    y.SZSESubsCash = x.SZSESubsCash;
    y.HKSubsCash = x.HKSubsCash;
    y.OtherSubsCash = x.OtherSubsCash;
    strcpy(y.TradeDate, x.TradeDate.c_str());
    strcpy(y.TradeTime, x.TradeTime.c_str());
    strcpy(y.ManagerID, x.ManagerID.c_str());
    strcpy(y.ManagerPbuID, x.ManagerPbuID.c_str());
    strcpy(y.ManagerShareholderID, x.ManagerShareholderID.c_str());
    y.DataIndex = x.DataIndex;
    y.BasketMarketID = x.BasketMarketID;
    strcpy(y.AffiliatedShareholderID, x.AffiliatedShareholderID.c_str());
    strcpy(y.AffiliatedPbuID, x.AffiliatedPbuID.c_str());
    return y;
}

PublicOfferedFundTradeDetailField Converter::CTORATstpPublicOfferedFundTradeDetailFieldToRust(CTORATstpPublicOfferedFundTradeDetailField* x) {
    if (x == nullptr)
        return PublicOfferedFundTradeDetailField{.is_null = true};
    PublicOfferedFundTradeDetailField y{};
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.Direction = x->Direction;
    y.FundSecurityID = Converter::GbkToRustString(x->FundSecurityID);
    y.BasketSecurityID = Converter::GbkToRustString(x->BasketSecurityID);
    y.TradeReportType = x->TradeReportType;
    y.TradeID = Converter::GbkToRustString(x->TradeID);
    y.PbuID = Converter::GbkToRustString(x->PbuID);
    y.OrderLocalID = Converter::GbkToRustString(x->OrderLocalID);
    y.ExchOrderID = Converter::GbkToRustString(x->ExchOrderID);
    y.TradeReportNums = x->TradeReportNums;
    y.DeliveryVolume = x->DeliveryVolume;
    y.TotalSubsCash = x->TotalSubsCash;
    y.SSESubsCash = x->SSESubsCash;
    y.SZSESubsCash = x->SZSESubsCash;
    y.HKSubsCash = x->HKSubsCash;
    y.OtherSubsCash = x->OtherSubsCash;
    y.TradeDate = Converter::GbkToRustString(x->TradeDate);
    y.TradeTime = Converter::GbkToRustString(x->TradeTime);
    y.ManagerID = Converter::GbkToRustString(x->ManagerID);
    y.ManagerPbuID = Converter::GbkToRustString(x->ManagerPbuID);
    y.ManagerShareholderID = Converter::GbkToRustString(x->ManagerShareholderID);
    y.DataIndex = x->DataIndex;
    y.BasketMarketID = x->BasketMarketID;
    y.AffiliatedShareholderID = Converter::GbkToRustString(x->AffiliatedShareholderID);
    y.AffiliatedPbuID = Converter::GbkToRustString(x->AffiliatedPbuID);
    return y;
}

CTORATstpQryTenderInfoField Converter::QryTenderInfoFieldToCpp(QryTenderInfoField x) {
    CTORATstpQryTenderInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.TenderSecurityID, x.TenderSecurityID.c_str());
    strcpy(y.TendererID, x.TendererID.c_str());
    strcpy(y.UnderlyingSecurityID, x.UnderlyingSecurityID.c_str());
    return y;
}

QryTenderInfoField Converter::CTORATstpQryTenderInfoFieldToRust(CTORATstpQryTenderInfoField* x) {
    if (x == nullptr)
        return QryTenderInfoField{.is_null = true};
    QryTenderInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.TenderSecurityID = Converter::GbkToRustString(x->TenderSecurityID);
    y.TendererID = Converter::GbkToRustString(x->TendererID);
    y.UnderlyingSecurityID = Converter::GbkToRustString(x->UnderlyingSecurityID);
    return y;
}

CTORATstpTenderInfoField Converter::TenderInfoFieldToCpp(TenderInfoField x) {
    CTORATstpTenderInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.TenderSecurityID, x.TenderSecurityID.c_str());
    strcpy(y.TendererID, x.TendererID.c_str());
    strcpy(y.TendererName, x.TendererName.c_str());
    strcpy(y.UnderlyingSecurityID, x.UnderlyingSecurityID.c_str());
    strcpy(y.UnderlyingSecurityName, x.UnderlyingSecurityName.c_str());
    y.ProductID = x.ProductID;
    y.SecurityType = x.SecurityType;
    y.OfferingPrice = x.OfferingPrice;
    y.MinOrderVol = x.MinOrderVol;
    y.MaxOrderVol = x.MaxOrderVol;
    y.OrderUnit = x.OrderUnit;
    strcpy(y.BeginDate, x.BeginDate.c_str());
    strcpy(y.EndDate, x.EndDate.c_str());
    return y;
}

TenderInfoField Converter::CTORATstpTenderInfoFieldToRust(CTORATstpTenderInfoField* x) {
    if (x == nullptr)
        return TenderInfoField{.is_null = true};
    TenderInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.TenderSecurityID = Converter::GbkToRustString(x->TenderSecurityID);
    y.TendererID = Converter::GbkToRustString(x->TendererID);
    y.TendererName = Converter::GbkToRustString(x->TendererName);
    y.UnderlyingSecurityID = Converter::GbkToRustString(x->UnderlyingSecurityID);
    y.UnderlyingSecurityName = Converter::GbkToRustString(x->UnderlyingSecurityName);
    y.ProductID = x->ProductID;
    y.SecurityType = x->SecurityType;
    y.OfferingPrice = x->OfferingPrice;
    y.MinOrderVol = x->MinOrderVol;
    y.MaxOrderVol = x->MaxOrderVol;
    y.OrderUnit = x->OrderUnit;
    y.BeginDate = Converter::GbkToRustString(x->BeginDate);
    y.EndDate = Converter::GbkToRustString(x->EndDate);
    return y;
}

CTORATstpQryAdditionalOfferingInfoField Converter::QryAdditionalOfferingInfoFieldToCpp(QryAdditionalOfferingInfoField x) {
    CTORATstpQryAdditionalOfferingInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    return y;
}

QryAdditionalOfferingInfoField Converter::CTORATstpQryAdditionalOfferingInfoFieldToRust(CTORATstpQryAdditionalOfferingInfoField* x) {
    if (x == nullptr)
        return QryAdditionalOfferingInfoField{.is_null = true};
    QryAdditionalOfferingInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    return y;
}

CTORATstpAdditionalOfferingInfoField Converter::AdditionalOfferingInfoFieldToCpp(AdditionalOfferingInfoField x) {
    CTORATstpAdditionalOfferingInfoField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.SecurityName, x.SecurityName.c_str());
    y.ProductID = x.ProductID;
    y.SecurityType = x.SecurityType;
    y.MinPrice = x.MinPrice;
    y.MaxPrice = x.MaxPrice;
    y.MinVolume = x.MinVolume;
    y.MaxVolume = x.MaxVolume;
    y.VolumeUnit = x.VolumeUnit;
    strcpy(y.BeginDate, x.BeginDate.c_str());
    strcpy(y.EndDate, x.EndDate.c_str());
    y.Remark = x.Remark;
    return y;
}

AdditionalOfferingInfoField Converter::CTORATstpAdditionalOfferingInfoFieldToRust(CTORATstpAdditionalOfferingInfoField* x) {
    if (x == nullptr)
        return AdditionalOfferingInfoField{.is_null = true};
    AdditionalOfferingInfoField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.SecurityName = Converter::GbkToRustString(x->SecurityName);
    y.ProductID = x->ProductID;
    y.SecurityType = x->SecurityType;
    y.MinPrice = x->MinPrice;
    y.MaxPrice = x->MaxPrice;
    y.MinVolume = x->MinVolume;
    y.MaxVolume = x->MaxVolume;
    y.VolumeUnit = x->VolumeUnit;
    y.BeginDate = Converter::GbkToRustString(x->BeginDate);
    y.EndDate = Converter::GbkToRustString(x->EndDate);
    y.Remark = x->Remark;
    return y;
}

CTORATstpQryAdditionalOfferingQuotaField Converter::QryAdditionalOfferingQuotaFieldToCpp(QryAdditionalOfferingQuotaField x) {
    CTORATstpQryAdditionalOfferingQuotaField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    return y;
}

QryAdditionalOfferingQuotaField Converter::CTORATstpQryAdditionalOfferingQuotaFieldToRust(CTORATstpQryAdditionalOfferingQuotaField* x) {
    if (x == nullptr)
        return QryAdditionalOfferingQuotaField{.is_null = true};
    QryAdditionalOfferingQuotaField y{};
    y.ExchangeID = x->ExchangeID;
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    return y;
}

CTORATstpAdditionalOfferingQuotaField Converter::AdditionalOfferingQuotaFieldToCpp(AdditionalOfferingQuotaField x) {
    CTORATstpAdditionalOfferingQuotaField y;
    memset(&y, 0, sizeof(y));
    y.ExchangeID = x.ExchangeID;
    strcpy(y.ShareholderID, x.ShareholderID.c_str());
    strcpy(y.SecurityID, x.SecurityID.c_str());
    strcpy(y.InvestorID, x.InvestorID.c_str());
    y.MaxVolume = x.MaxVolume;
    y.FrzVolume = x.FrzVolume;
    return y;
}

AdditionalOfferingQuotaField Converter::CTORATstpAdditionalOfferingQuotaFieldToRust(CTORATstpAdditionalOfferingQuotaField* x) {
    if (x == nullptr)
        return AdditionalOfferingQuotaField{.is_null = true};
    AdditionalOfferingQuotaField y{};
    y.ExchangeID = x->ExchangeID;
    y.ShareholderID = Converter::GbkToRustString(x->ShareholderID);
    y.SecurityID = Converter::GbkToRustString(x->SecurityID);
    y.InvestorID = Converter::GbkToRustString(x->InvestorID);
    y.MaxVolume = x->MaxVolume;
    y.FrzVolume = x->FrzVolume;
    return y;
}

CTORATstpForceUserLogoutField Converter::ForceUserLogoutFieldToCpp(ForceUserLogoutField x) {
    CTORATstpForceUserLogoutField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.UserID, x.UserID.c_str());
    y.UserRequestID = x.UserRequestID;
    return y;
}

ForceUserLogoutField Converter::CTORATstpForceUserLogoutFieldToRust(CTORATstpForceUserLogoutField* x) {
    if (x == nullptr)
        return ForceUserLogoutField{.is_null = true};
    ForceUserLogoutField y{};
    y.UserID = Converter::GbkToRustString(x->UserID);
    y.UserRequestID = x->UserRequestID;
    return y;
}

CTORATstpActivateUserField Converter::ActivateUserFieldToCpp(ActivateUserField x) {
    CTORATstpActivateUserField y;
    memset(&y, 0, sizeof(y));
    strcpy(y.UserID, x.UserID.c_str());
    y.UserRequestID = x.UserRequestID;
    return y;
}

ActivateUserField Converter::CTORATstpActivateUserFieldToRust(CTORATstpActivateUserField* x) {
    if (x == nullptr)
        return ActivateUserField{.is_null = true};
    ActivateUserField y{};
    y.UserID = Converter::GbkToRustString(x->UserID);
    y.UserRequestID = x->UserRequestID;
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
    y.UserRequestID = x.UserRequestID;
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
    y.UserRequestID = x->UserRequestID;
    y.InnerIPAddress = Converter::GbkToRustString(x->InnerIPAddress);
    y.InnerPort = x->InnerPort;
    y.OuterIPAddress = Converter::GbkToRustString(x->OuterIPAddress);
    y.OuterPort = x->OuterPort;
    y.MacAddress = Converter::GbkToRustString(x->MacAddress);
    return y;
}

} // namespace tora_trader
