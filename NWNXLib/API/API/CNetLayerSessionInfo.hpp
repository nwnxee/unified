#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "NWSyncAdvertisement.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNetLayerSessionInfo)
#endif

struct CExtendedServerInfo;


typedef int BOOL;


struct CNetLayerSessionInfo
{
    uint32_t m_nConnectionId;
    CExoString m_sSessionName;
    uint32_t m_nProtocol;
    uint32_t m_nPort;
    uint32_t m_nPingPacketSent[4];
    uint32_t m_nPingPacketReceived[4];
    uint32_t m_nPingTotalTime;
    uint32_t m_nPingNumPackets;
    BOOL m_bPingActive;
    uint32_t m_nPingPacketTimeout;
    CExtendedServerInfo * m_pExtendedInfo;
    BOOL m_bHasChanged;
    BOOL m_bServerDetailsChanged;
    BOOL m_bRecievedBNXR;
    uint32_t m_nLastUpdate;
    CExoString m_sVisibleAddress;
    NWSyncAdvertisement m_nwsyncData;

    CNetLayerSessionInfo();
    ~CNetLayerSessionInfo();
    void Clean();


#ifdef NWN_CLASS_EXTENSION_CNetLayerSessionInfo
    NWN_CLASS_EXTENSION_CNetLayerSessionInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNetLayerSessionInfo)
#endif

