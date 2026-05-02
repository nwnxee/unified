//
// This implements a hotfix for the mythical UnpacketizeFullMessages->fmtStr server hang
// that community servers have seen.
//
// This is *entirely theoretical so far* and has not been verified to actually WAR it.
// Even if it DOES address the hang, then this may not be a fully mergeable upstream fix.
// (The game might need a punchthrough to detect sliding window dtoring).
//
// This plugin is a minimal attack surface, hopefully, and ONLY addresses the packets=1
// case where the original function is re-entrant if the actual frame has multiple
// messages packed into it. If one of the earlier messages is a "disconnect player and kill
// sliding window" message, then the later messages will read invalid data and go into
// a ~infinite loop on the frame counter.
//
// Also see nwn/issues#4398
//
// Version: 1.0, 2026-05-02, niv
//

#include "nwn_api.hpp"
#include "nwnx.hpp"

#include <cstddef>
#include <cstdint>

#include "API/CNetLayer.hpp"
#include "API/CExoString.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNetLayerWindow.hpp"

using namespace NWNXLib;

static Hooks::Hook ufmHook;

#define INVALID_FRAME       65535
#define TRUE                1
#define FALSE               0
#define NWN_MAX_PLAYERS     0xff
#define FRAME_HEADER_LENGTH 12

struct CExoNetExtendableBuffer
{
    BOOL GetFrameData(uint16_t nFrameIndex, uint8_t** pData, uint32_t* nFrameSize,
        CNetConnectionId* nConnectionId, uint16_t* nNextFrame);
    uint32_t ChangeFrameReference(uint16_t nFrameIndex, int32_t nIncrement);
};

struct CNetLayerInternal
{
    BOOL UncompressMessage(uint32_t nPlayerId, uint8_t* pData, uint32_t nSize);

    struct IntendedConnectionData
    {
        uint8_t m_nConnectionType;
        int32_t m_nPlayerLanguage;
        CExoString m_sPlayerName;
        CExoString m_sCDKey;
        CExoString m_sLegacyCDKey;
    };

    CNetInstance m_nInstance;
    IntendedConnectionData m_pConnectData;
    CExoString m_sConnectExpectCryptoPublicKeyBase64;
    CBaseExoApp* m_pcExoApp;
    struct CExoNet* m_pcExoNet;
    BOOL m_bInitialized;
    CNetLayerWindow m_aWindows[NWN_MAX_PLAYERS];
    CNetLayerPlayerInfo m_pcPlayerInfo[NWN_MAX_PLAYERS];
    CExoNetExtendableBuffer* m_pebFrameStorage; // offset verified OK
};

static inline uint16_t GetFrameNumPackets(uint8_t* pData)
{
    return (uint16_t)((((uint16_t)pData[8]) << 8) + pData[9]);
}

static inline uint32_t GetFrameMessageSize(uint8_t* pData)
{
    if (pData[7] & 0x80)
    {
        return ((uint32_t)(pData[10] << 8) + (uint32_t)(pData[11]) + (uint32_t)(pData[12] << 24) +
            (uint32_t)(pData[13] << 16));
    }
    else
    {
        return ((uint32_t)(pData[10] << 8) + (uint32_t)(pData[11]));
    }
}

static BOOL ufmImpl(CNetLayerWindow* thisPtr, BOOL bHighPriority)
{
    uint16_t nFrame;
    uint8_t* pData;
    uint32_t nDataSize;
    uint16_t nNextFrame;
    CNetConnectionId nConnectionId;

    static_assert(sizeof(CNetInstance) == 4, "Need API fix @Daz");
    static_assert(offsetof(CNetLayer, m_nInstance) == 0x0, "Need API fix @Daz");
    static_assert(offsetof(CNetLayerWindow, m_nInstance) == 0x0, "Need API fix @Daz");
    static_assert(offsetof(CNetLayerInternal, m_nInstance) == 0x0, "Need API fix @Daz");
    static_assert(offsetof(CNetLayerInternal, m_aWindows) == 0x68, "Need API fix @Daz");

    nFrame = INVALID_FRAME;

    if (bHighPriority == TRUE && thisPtr->m_lQueueIncomingHiFrames.num > 0)
    {
        nFrame = thisPtr->m_lQueueIncomingHiFrames[0];
    }
    else if (bHighPriority == FALSE && thisPtr->m_lQueueIncomingLoFrames.num > 0)
    {
        nFrame = thisPtr->m_lQueueIncomingLoFrames[0];
    }
    else
    {
        return FALSE;
    }

    ASSERT_OR_RETURN(nFrame != INVALID_FRAME, FALSE);

    pData = NULL;

    thisPtr->m_pNetLayer->m_pebFrameStorage->GetFrameData(nFrame, &pData, &nDataSize,
        &nConnectionId, &nNextFrame);

    ASSERT_OR_RETURN(pData != NULL, FALSE);

    uint16_t nPacketsRequired = GetFrameNumPackets(pData);

    if (nPacketsRequired != 1)
    {
        return ufmHook->CallOriginal<BOOL>(thisPtr, bHighPriority);
    }

    //
    // Potential sporadic server hang fix that has been plagueing PWs:
    //
    // Decompose the messages that share this packet.
    // We must not walk the live frame-storage buffer directly because
    // HandleMessage() can disconnect the player re-entrantly and tear the
    // current window down, which frees queued incoming frames underneath us.
    //
    // This hang is hard to chase and harder to repro in production and likely
    // has been around since 1.69; but EE has started sending larger C2S packets
    // and is seeing more player traffic, so the case where clients frame-pack messages
    // has become more common.
    //
    uint8_t* pMessageData = new uint8_t[nDataSize];
    SCOPEGUARD(delete[] pMessageData);
    memcpy(pMessageData, pData, nDataSize);

    uint32_t nRemainingSize = nDataSize;
    BOOL bPacketWellFormed = TRUE;

    while (nRemainingSize >= FRAME_HEADER_LENGTH)
    {
        uint8_t* pCurrentMessage = pMessageData + nDataSize - nRemainingSize;
        uint32_t nPayloadSize = GetFrameMessageSize(pCurrentMessage);

        if (nPayloadSize > nRemainingSize - FRAME_HEADER_LENGTH)
        {
            LOG_WARNING(
                "Packet not wellformed; sliding window gone? This would have hung the server! "
                "player=%u packet=%u remaining=%u payload=%u flags=0x%02x",
                thisPtr->m_nPlayerId, nDataSize, nRemainingSize, nPayloadSize, pCurrentMessage[7]);
            bPacketWellFormed = FALSE;
            break;
        }

        uint32_t nMessageDataSize = nPayloadSize + FRAME_HEADER_LENGTH;

        if (!thisPtr->m_pNetLayer->UncompressMessage(thisPtr->m_nPlayerId, pCurrentMessage,
                nMessageDataSize))
        {
            bPacketWellFormed = FALSE;
            break;
        }

        nRemainingSize -= nMessageDataSize;
    }

    if (bPacketWellFormed == TRUE && nRemainingSize != 0)
    {
        LOG_WARNING(
            "Packet has trailing data after unpacketization! "
            "player=%u packet=%u trailing=%u",
            thisPtr->m_nPlayerId, nDataSize, nRemainingSize);
    }

    if (bHighPriority == TRUE)
    {
        nFrame = thisPtr->m_lQueueIncomingHiFrames[0];
        thisPtr->m_lQueueIncomingHiFrames.DelIndex(0);
    }
    else
    {
        nFrame = thisPtr->m_lQueueIncomingLoFrames[0];
        thisPtr->m_lQueueIncomingLoFrames.DelIndex(0);
    }

    thisPtr->m_pNetLayer->m_pebFrameStorage->ChangeFrameReference(nFrame, -1);

    return TRUE;
}

static void UFM_HotfixCtor() __attribute__((constructor));
static void UFM_HotfixCtor()
{
    if (!Config::Get<bool>("UFM_HOTFIX", false))
        return;

    LOG_INFO("EXPERIMENTAL: Attempting to resolve a server hang in CNetLayerWindow::UnpacketizeFullMessages.");

    ufmHook = Hooks::HookFunction(&CNetLayerWindow::UnpacketizeFullMessages, ufmImpl, Hooks::Order::Earliest);
}
