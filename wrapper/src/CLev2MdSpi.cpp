#include "tora-rs/wrapper/include/CLev2MdSpi.h"
#include "tora-rs/wrapper/include/Lev2MdConverter.h"

namespace tora_lev2md {
using namespace TORALEV2API;

CLev2MdSpi::CLev2MdSpi(rust::Box<Lev2MdSpi> gateway) : gateway(std::move(gateway)) { }

void CLev2MdSpi::OnFrontConnected() {
    this->gateway->OnFrontConnected(
    );
}

void CLev2MdSpi::OnFrontDisconnected(int32_t nReason) {
    this->gateway->OnFrontDisconnected(
        nReason
    );
}

void CLev2MdSpi::OnRspError(CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspError(
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLogin, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUserLogin(
        Converter::CTORATstpRspUserLoginFieldToRust(pRspUserLogin),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUserLogout(CTORATstpUserLogoutField* pUserLogout, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUserLogout(
        Converter::CTORATstpUserLogoutFieldToRust(pUserLogout),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubIndex(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubIndex(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubIndex(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubIndex(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubTransaction(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubTransaction(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubOrderDetail(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubOrderDetail(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubPHMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubPHMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubPHTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubPHTransaction(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubPHTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubPHTransaction(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubResendTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubResendTransaction(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubResendTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubResendTransaction(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubResendOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubResendOrderDetail(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubResendOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubResendOrderDetail(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubXTSMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubXTSMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubXTSMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubXTSMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubXTSTick(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubXTSTick(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubXTSTick(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubXTSTick(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubNGTSTick(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubNGTSTick(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubNGTSTick(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubNGTSTick(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubBondMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubBondMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubBondMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubBondMarketData(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubBondTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubBondTransaction(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubBondTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubBondTransaction(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubBondOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubBondOrderDetail(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubBondOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubBondOrderDetail(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspSubIOPV(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspSubIOPV(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRspUnSubIOPV(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) {
    this->gateway->OnRspUnSubIOPV(
        Converter::CTORATstpSpecificSecurityFieldToRust(pSpecificSecurity),
        Converter::CTORATstpRspInfoFieldToRust(pRspInfo),
        nRequestID,
        bIsLast
    );
}

void CLev2MdSpi::OnRtnMarketData(CTORATstpLev2MarketDataField* pMarketData, int32_t FirstLevelBuyNum, const int FirstLevelBuyOrderVolumes[], int32_t FirstLevelSellNum, const int FirstLevelSellOrderVolumes[]) {
    rust::Vec<int32_t> FirstLevelBuyOrderVolumes_vec;
    for (int i = 0; i < FirstLevelBuyNum; i++)
        FirstLevelBuyOrderVolumes_vec.push_back(FirstLevelBuyOrderVolumes[i]);
    rust::Vec<int32_t> FirstLevelSellOrderVolumes_vec;
    for (int i = 0; i < FirstLevelSellNum; i++)
        FirstLevelSellOrderVolumes_vec.push_back(FirstLevelSellOrderVolumes[i]);
    this->gateway->OnRtnMarketData(
        Converter::CTORATstpLev2MarketDataFieldToRust(pMarketData),
        FirstLevelBuyNum,
        FirstLevelBuyOrderVolumes_vec,
        FirstLevelSellNum,
        FirstLevelSellOrderVolumes_vec
    );
}

void CLev2MdSpi::OnRtnIndex(CTORATstpLev2IndexField* pIndex) {
    this->gateway->OnRtnIndex(
        Converter::CTORATstpLev2IndexFieldToRust(pIndex)
    );
}

void CLev2MdSpi::OnRtnTransaction(CTORATstpLev2TransactionField* pTransaction) {
    this->gateway->OnRtnTransaction(
        Converter::CTORATstpLev2TransactionFieldToRust(pTransaction)
    );
}

void CLev2MdSpi::OnRtnOrderDetail(CTORATstpLev2OrderDetailField* pOrderDetail) {
    this->gateway->OnRtnOrderDetail(
        Converter::CTORATstpLev2OrderDetailFieldToRust(pOrderDetail)
    );
}

void CLev2MdSpi::OnRtnPHMarketData(CTORATstpLev2PHMarketDataField* pPHMarketData, int32_t FirstLevelBuyNum, const int FirstLevelBuyOrderVolumes[], int32_t FirstLevelSellNum, const int FirstLevelSellOrderVolumes[]) {
    rust::Vec<int32_t> FirstLevelBuyOrderVolumes_vec;
    for (int i = 0; i < FirstLevelBuyNum; i++)
        FirstLevelBuyOrderVolumes_vec.push_back(FirstLevelBuyOrderVolumes[i]);
    rust::Vec<int32_t> FirstLevelSellOrderVolumes_vec;
    for (int i = 0; i < FirstLevelSellNum; i++)
        FirstLevelSellOrderVolumes_vec.push_back(FirstLevelSellOrderVolumes[i]);
    this->gateway->OnRtnPHMarketData(
        Converter::CTORATstpLev2PHMarketDataFieldToRust(pPHMarketData),
        FirstLevelBuyNum,
        FirstLevelBuyOrderVolumes_vec,
        FirstLevelSellNum,
        FirstLevelSellOrderVolumes_vec
    );
}

void CLev2MdSpi::OnRtnPHTransaction(CTORATstpLev2PHTransactionField* pTransaction) {
    this->gateway->OnRtnPHTransaction(
        Converter::CTORATstpLev2PHTransactionFieldToRust(pTransaction)
    );
}

void CLev2MdSpi::OnRtnResendTransaction(CTORATstpLev2ResendTransactionField* pTransaction) {
    this->gateway->OnRtnResendTransaction(
        Converter::CTORATstpLev2ResendTransactionFieldToRust(pTransaction)
    );
}

void CLev2MdSpi::OnRtnResendOrderDetail(CTORATstpLev2ResendOrderDetailField* pOrderDetail) {
    this->gateway->OnRtnResendOrderDetail(
        Converter::CTORATstpLev2ResendOrderDetailFieldToRust(pOrderDetail)
    );
}

void CLev2MdSpi::OnRtnXTSMarketData(CTORATstpLev2XTSMarketDataField* pMarketData, int32_t FirstLevelBuyNum, const int FirstLevelBuyOrderVolumes[], int32_t FirstLevelSellNum, const int FirstLevelSellOrderVolumes[]) {
    rust::Vec<int32_t> FirstLevelBuyOrderVolumes_vec;
    for (int i = 0; i < FirstLevelBuyNum; i++)
        FirstLevelBuyOrderVolumes_vec.push_back(FirstLevelBuyOrderVolumes[i]);
    rust::Vec<int32_t> FirstLevelSellOrderVolumes_vec;
    for (int i = 0; i < FirstLevelSellNum; i++)
        FirstLevelSellOrderVolumes_vec.push_back(FirstLevelSellOrderVolumes[i]);
    this->gateway->OnRtnXTSMarketData(
        Converter::CTORATstpLev2XTSMarketDataFieldToRust(pMarketData),
        FirstLevelBuyNum,
        FirstLevelBuyOrderVolumes_vec,
        FirstLevelSellNum,
        FirstLevelSellOrderVolumes_vec
    );
}

void CLev2MdSpi::OnRtnXTSTick(CTORATstpLev2XTSTickField* pTick) {
    this->gateway->OnRtnXTSTick(
        Converter::CTORATstpLev2XTSTickFieldToRust(pTick)
    );
}

void CLev2MdSpi::OnRtnNGTSTick(CTORATstpLev2NGTSTickField* pTick) {
    this->gateway->OnRtnNGTSTick(
        Converter::CTORATstpLev2NGTSTickFieldToRust(pTick)
    );
}

void CLev2MdSpi::OnRtnBondMarketData(CTORATstpLev2BondMarketDataField* pMarketData, int32_t FirstLevelBuyNum, const int FirstLevelBuyOrderVolumes[], int32_t FirstLevelSellNum, const int FirstLevelSellOrderVolumes[]) {
    rust::Vec<int32_t> FirstLevelBuyOrderVolumes_vec;
    for (int i = 0; i < FirstLevelBuyNum; i++)
        FirstLevelBuyOrderVolumes_vec.push_back(FirstLevelBuyOrderVolumes[i]);
    rust::Vec<int32_t> FirstLevelSellOrderVolumes_vec;
    for (int i = 0; i < FirstLevelSellNum; i++)
        FirstLevelSellOrderVolumes_vec.push_back(FirstLevelSellOrderVolumes[i]);
    this->gateway->OnRtnBondMarketData(
        Converter::CTORATstpLev2BondMarketDataFieldToRust(pMarketData),
        FirstLevelBuyNum,
        FirstLevelBuyOrderVolumes_vec,
        FirstLevelSellNum,
        FirstLevelSellOrderVolumes_vec
    );
}

void CLev2MdSpi::OnRtnBondTransaction(CTORATstpLev2BondTransactionField* pTransaction) {
    this->gateway->OnRtnBondTransaction(
        Converter::CTORATstpLev2BondTransactionFieldToRust(pTransaction)
    );
}

void CLev2MdSpi::OnRtnBondOrderDetail(CTORATstpLev2BondOrderDetailField* pOrderDetail) {
    this->gateway->OnRtnBondOrderDetail(
        Converter::CTORATstpLev2BondOrderDetailFieldToRust(pOrderDetail)
    );
}

void CLev2MdSpi::OnRtnIOPV(CTORATstpLev2IOPVField* pIOPV) {
    this->gateway->OnRtnIOPV(
        Converter::CTORATstpLev2IOPVFieldToRust(pIOPV)
    );
}

} // namespace tora_lev2md
