#include "tora-rs/wrapper/include/CXMdSpi.h"
#include "tora-rs/wrapper/include/XMdConverter.h"

namespace tora_xmd {
using namespace TORALEV1API;

CXMdSpi::CXMdSpi(rust::Box<XMdSpi> gateway) : gateway(std::move(gateway)) { }

void CXMdSpi::OnFrontConnected() {
    this->gateway->OnFrontConnected(
    );
}

void CXMdSpi::OnFrontDisconnected(int32_t nReason) {
    this->gateway->OnFrontDisconnected(
        nReason
    );
}

void CXMdSpi::OnRspGetConnectionInfo(CTORATstpConnectionInfoField* pConnectionInfoField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspGetConnectionInfo(
        Converter::CTORATstpConnectionInfoFieldToRust(pConnectionInfoField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CXMdSpi::OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLoginField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspUserLogin(
        Converter::CTORATstpRspUserLoginFieldToRust(pRspUserLoginField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CXMdSpi::OnRspUserLogout(CTORATstpUserLogoutField* pUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID) {
    this->gateway->OnRspUserLogout(
        Converter::CTORATstpUserLogoutFieldToRust(pUserLogoutField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID
    );
}

void CXMdSpi::OnRspSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubPHMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubPHMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubSpecialMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubSpecialMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubSpecialMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubSpecialMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubSimplifyMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubSimplifyMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubIOPV(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubIOPV(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubIOPV(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubIOPV(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubSecurityStatus(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubSecurityStatus(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubMarketStatus(
        Converter::CTORATstpSpecificMarketFieldToRust(pSpecificMarketField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubMarketStatus(
        Converter::CTORATstpSpecificMarketFieldToRust(pSpecificMarketField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubImcParams(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubImcParams(
        Converter::CTORATstpSpecificMarketFieldToRust(pSpecificMarketField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubImcParams(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubImcParams(
        Converter::CTORATstpSpecificMarketFieldToRust(pSpecificMarketField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspInquiryMarketDataMirror(CTORATstpMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspInquiryMarketDataMirror(
        Converter::CTORATstpMarketDataFieldToRust(pMarketDataField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CXMdSpi::OnRspInquiryPHMarketDataMirror(CTORATstpPHMarketDataField* pPHMarketDataField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspInquiryPHMarketDataMirror(
        Converter::CTORATstpPHMarketDataFieldToRust(pPHMarketDataField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CXMdSpi::OnRspInquirySpecialMarketDataMirror(CTORATstpSpecialMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspInquirySpecialMarketDataMirror(
        Converter::CTORATstpSpecialMarketDataFieldToRust(pMarketDataField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CXMdSpi::OnRspSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubSPMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubSPMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubSPSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubSPSimplifyMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubSPSimplifyMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubSPSimplifyMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubSPSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubSPSecurityStatus(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubSPSecurityStatus(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubSPSecurityStatus(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspSubSPMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubSPMarketStatus(
        Converter::CTORATstpSpecificMarketFieldToRust(pSpecificMarketField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubSPMarketStatus(CTORATstpSpecificMarketField* pSpecificMarketField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubSPMarketStatus(
        Converter::CTORATstpSpecificMarketFieldToRust(pSpecificMarketField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspInquirySPMarketDataMirror(CTORATstpMarketDataField* pMarketDataField, CTORATstpRspInfoField* pRspInfoField, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspInquirySPMarketDataMirror(
        Converter::CTORATstpMarketDataFieldToRust(pMarketDataField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField),
        nRequestID,
        bIsLast
    );
}

void CXMdSpi::OnRtnMarketData(CTORATstpMarketDataField* pMarketDataField) {
    this->gateway->OnRtnMarketData(
        Converter::CTORATstpMarketDataFieldToRust(pMarketDataField)
    );
}

void CXMdSpi::OnRtnPHMarketData(CTORATstpPHMarketDataField* pPHMarketDataField) {
    this->gateway->OnRtnPHMarketData(
        Converter::CTORATstpPHMarketDataFieldToRust(pPHMarketDataField)
    );
}

void CXMdSpi::OnRtnSpecialMarketData(CTORATstpSpecialMarketDataField* pSpecialMarketDataField) {
    this->gateway->OnRtnSpecialMarketData(
        Converter::CTORATstpSpecialMarketDataFieldToRust(pSpecialMarketDataField)
    );
}

void CXMdSpi::OnRtnSimplifyMarketData(CTORATstpSimplifyMarketDataField* pSimplifyMarketDataField) {
    this->gateway->OnRtnSimplifyMarketData(
        Converter::CTORATstpSimplifyMarketDataFieldToRust(pSimplifyMarketDataField)
    );
}

void CXMdSpi::OnRtnIOPV(CTORATstpIOPVField* pIOPVField) {
    this->gateway->OnRtnIOPV(
        Converter::CTORATstpIOPVFieldToRust(pIOPVField)
    );
}

void CXMdSpi::OnRtnSecurityStatus(CTORATstpSecurityStatusField* pSecurityStatusField) {
    this->gateway->OnRtnSecurityStatus(
        Converter::CTORATstpSecurityStatusFieldToRust(pSecurityStatusField)
    );
}

void CXMdSpi::OnRtnMarketStatus(CTORATstpMarketStatusField* pMarketStatusField) {
    this->gateway->OnRtnMarketStatus(
        Converter::CTORATstpMarketStatusFieldToRust(pMarketStatusField)
    );
}

void CXMdSpi::OnRtnImcParams(CTORATstpImcParamsField* pImcParamsField) {
    this->gateway->OnRtnImcParams(
        Converter::CTORATstpImcParamsFieldToRust(pImcParamsField)
    );
}

void CXMdSpi::OnRtnSPMarketData(CTORATstpMarketDataField* pMarketDataField) {
    this->gateway->OnRtnSPMarketData(
        Converter::CTORATstpMarketDataFieldToRust(pMarketDataField)
    );
}

void CXMdSpi::OnRtnSPSimplifyMarketData(CTORATstpSimplifyMarketDataField* pSimplifyMarketDataField) {
    this->gateway->OnRtnSPSimplifyMarketData(
        Converter::CTORATstpSimplifyMarketDataFieldToRust(pSimplifyMarketDataField)
    );
}

void CXMdSpi::OnRtnSPSecurityStatus(CTORATstpSecurityStatusField* pSecurityStatusField) {
    this->gateway->OnRtnSPSecurityStatus(
        Converter::CTORATstpSecurityStatusFieldToRust(pSecurityStatusField)
    );
}

void CXMdSpi::OnRtnSPMarketStatus(CTORATstpMarketStatusField* pMarketStatusField) {
    this->gateway->OnRtnSPMarketStatus(
        Converter::CTORATstpMarketStatusFieldToRust(pMarketStatusField)
    );
}

void CXMdSpi::OnRspSubRapidMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspSubRapidMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRspUnSubRapidMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField) {
    this->gateway->OnRspUnSubRapidMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurityField),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfoField)
    );
}

void CXMdSpi::OnRtnRapidMarketData(CTORATstpRapidMarketDataField* pRapidMarketDataField) {
    this->gateway->OnRtnRapidMarketData(
        Converter::CTORATstpRapidMarketDataFieldToRust(pRapidMarketDataField)
    );
}

} // namespace tora_xmd
