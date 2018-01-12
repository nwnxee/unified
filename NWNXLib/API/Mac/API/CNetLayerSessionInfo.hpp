#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExtendedServerInfo;

struct CNetLayerSessionInfo
{
    uint32_t m_nReceiveConnectionId;
    uint32_t m_nSendConnectionId;
    CExoString m_sSessionName;
    uint32_t m_nProtocol;
    uint32_t m_nPort;
    uint32_t m_nPingPacketSent[4];
    uint32_t m_nPingPacketReceived[4];
    uint32_t m_nPingTotalTime;
    uint32_t m_nPingNumPackets;
    int32_t m_bPingActive;
    uint32_t m_nPingPacketTimeout;
    CExtendedServerInfo* m_pExtendedInfo;
    int32_t m_bHasChanged;
    int32_t m_bServerDetailsChanged;
    int32_t m_bRecievedBNXR;
    uint32_t m_nLastUpdate;
    CExoString m_sVisibleAddress;

    // The below are auto generated stubs.
    CNetLayerSessionInfo(const CNetLayerSessionInfo&) = default;
    CNetLayerSessionInfo& operator=(const CNetLayerSessionInfo&) = default;

    CNetLayerSessionInfo();
    ~CNetLayerSessionInfo();
    void Clean();
};

void CNetLayerSessionInfo__CNetLayerSessionInfoCtor__0(CNetLayerSessionInfo* thisPtr);
void CNetLayerSessionInfo__CNetLayerSessionInfoDtor__0(CNetLayerSessionInfo* thisPtr);
void CNetLayerSessionInfo__Clean(CNetLayerSessionInfo* thisPtr);

}

}
