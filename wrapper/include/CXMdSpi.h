#pragma once
#include "tora-rs/src/xmd.rs.h"
#include "TORATstpXMdApi.h"
#include "rust/cxx.h"
#include <cstdint>

namespace tora_xmd {
using namespace TORALEV1API;

class CXMdSpi : public CTORATstpXMdSpi
{
public:
    explicit CXMdSpi(rust::Box<XMdSpi> gateway);
    void OnFrontConnected() override;
    void OnFrontDisconnected(int32_t nReason) override;
    void OnRspGetConnectionInfo(CTORATstpConnectionInfoField* pConnectionInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLoginField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspUserLogout(CTORATstpUserLogoutField* pUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) override;
    void OnRspSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubSpecialMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubSpecialMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubIOPV(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubIOPV(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubImcParams(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubImcParams(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspInquiryMarketDataMirror(CTORATstpMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspInquiryPHMarketDataMirror(CTORATstpPHMarketDataField* pPHMarketDataField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspInquirySpecialMarketDataMirror(CTORATstpSpecialMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubSPSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubSPSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubSPSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubSPSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspSubSPMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubSPMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspInquirySPMarketDataMirror(CTORATstpMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) override;
    void OnRtnMarketData(CTORATstpMarketDataField* pMarketDataField) override;
    void OnRtnPHMarketData(CTORATstpPHMarketDataField* pPHMarketDataField) override;
    void OnRtnSpecialMarketData(CTORATstpSpecialMarketDataField* pSpecialMarketDataField) override;
    void OnRtnSimplifyMarketData(CTORATstpSimplifyMarketDataField* pSimplifyMarketDataField) override;
    void OnRtnIOPV(CTORATstpIOPVField* pIOPVField) override;
    void OnRtnSecurityStatus(CTORATstpSecurityStatusField* pSecurityStatusField) override;
    void OnRtnMarketStatus(CTORATstpMarketStatusField* pMarketStatusField) override;
    void OnRtnImcParams(CTORATstpImcParamsField* pImcParamsField) override;
    void OnRtnSPMarketData(CTORATstpMarketDataField* pMarketDataField) override;
    void OnRtnSPSimplifyMarketData(CTORATstpSimplifyMarketDataField* pSimplifyMarketDataField) override;
    void OnRtnSPSecurityStatus(CTORATstpSecurityStatusField* pSecurityStatusField) override;
    void OnRtnSPMarketStatus(CTORATstpMarketStatusField* pMarketStatusField) override;
    void OnRspSubRapidMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRspUnSubRapidMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) override;
    void OnRtnRapidMarketData(CTORATstpRapidMarketDataField* pRapidMarketDataField) override;

private:
    rust::Box<XMdSpi> gateway;
};
} // namespace tora_xmd
