#pragma once
#include "tora-rs/src/lev2md.rs.h"
#include "TORATstpLev2MdApi.h"
#include "rust/cxx.h"
#include <cstdint>

namespace tora_lev2md {
using namespace TORALEV2API;

class CLev2MdSpi : public CTORATstpLev2MdSpi
{
public:
    explicit CLev2MdSpi(rust::Box<Lev2MdSpi> gateway);
    void OnFrontConnected() override;
    void OnFrontDisconnected(int32_t nReason) override;
    void OnRspError(CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLogin, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUserLogout(CTORATstpUserLogoutField* pUserLogout, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubIndex(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubIndex(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubPHMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubPHTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubPHTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubResendTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubResendTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubResendOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubResendOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubXTSMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubXTSMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubXTSTick(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubXTSTick(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubNGTSTick(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubNGTSTick(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubBondMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubBondMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubBondTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubBondTransaction(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubBondOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubBondOrderDetail(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspSubIOPV(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRspUnSubIOPV(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo, int32_t nRequestID, bool bIsLast) override;
    void OnRtnMarketData(CTORATstpLev2MarketDataField* pMarketData, int32_t FirstLevelBuyNum, const int FirstLevelBuyOrderVolumes[], int32_t FirstLevelSellNum, const int FirstLevelSellOrderVolumes[]) override;
    void OnRtnIndex(CTORATstpLev2IndexField* pIndex) override;
    void OnRtnTransaction(CTORATstpLev2TransactionField* pTransaction) override;
    void OnRtnOrderDetail(CTORATstpLev2OrderDetailField* pOrderDetail) override;
    void OnRtnPHMarketData(CTORATstpLev2PHMarketDataField* pPHMarketData, int32_t FirstLevelBuyNum, const int FirstLevelBuyOrderVolumes[], int32_t FirstLevelSellNum, const int FirstLevelSellOrderVolumes[]) override;
    void OnRtnPHTransaction(CTORATstpLev2PHTransactionField* pTransaction) override;
    void OnRtnResendTransaction(CTORATstpLev2ResendTransactionField* pTransaction) override;
    void OnRtnResendOrderDetail(CTORATstpLev2ResendOrderDetailField* pOrderDetail) override;
    void OnRtnXTSMarketData(CTORATstpLev2XTSMarketDataField* pMarketData, int32_t FirstLevelBuyNum, const int FirstLevelBuyOrderVolumes[], int32_t FirstLevelSellNum, const int FirstLevelSellOrderVolumes[]) override;
    void OnRtnXTSTick(CTORATstpLev2XTSTickField* pTick) override;
    void OnRtnNGTSTick(CTORATstpLev2NGTSTickField* pTick) override;
    void OnRtnBondMarketData(CTORATstpLev2BondMarketDataField* pMarketData, int32_t FirstLevelBuyNum, const int FirstLevelBuyOrderVolumes[], int32_t FirstLevelSellNum, const int FirstLevelSellOrderVolumes[]) override;
    void OnRtnBondTransaction(CTORATstpLev2BondTransactionField* pTransaction) override;
    void OnRtnBondOrderDetail(CTORATstpLev2BondOrderDetailField* pOrderDetail) override;
    void OnRtnIOPV(CTORATstpLev2IOPVField* pIOPV) override;

private:
    rust::Box<Lev2MdSpi> gateway;
};
} // namespace tora_lev2md
