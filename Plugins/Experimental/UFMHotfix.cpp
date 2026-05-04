//
// This implements a hotfix for the mythical UnpacketizeFullMessages->fmtStr server hang
// that community servers have seen.
//
// This is *entirely theoretical so far* and has not been verified to actually WAR it.
// Even if it DOES address the hang, then this may not be a fully mergeable upstream fix.
// (The game might need a punchthrough to detect sliding window dtoring).
//
// This plugin is a minimal attack surface, hopefully, and addresses both:
// 1. the packets=1 case where the original function is re-entrant if the actual frame has
//    multiple messages packed into it; and
// 2. the packets!=1 path where the original code trusts fragmented-frame queue state too much
//    and can hand obviously invalid reconstructed data to UncompressMessage().
//
// Also see nwn/issues#4398
//
// Version: 1.1, 2026-05-04
//

#include "nwn_api.hpp"
#include "nwnx.hpp"

#include <cstddef>
#include <cstdint>

#include "API/CExoString.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNetLayerWindow.hpp"

using namespace NWNXLib;

static Hooks::Hook ufmHook;

#define INVALID_FRAME                65535
#define TRUE                         1
#define FALSE                        0
#define NWN_MAX_PLAYERS              0xff
#define FRAME_HEADER_LENGTH          12
#define MAX_MESSAGE_LENGTH           960
#define COMPRESS_BUFFERSIZE          (20 * 1024 * 1024)
#define MAX_REASSEMBLED_MESSAGE_SIZE (FRAME_HEADER_LENGTH + COMPRESS_BUFFERSIZE)
#define MAX_PAYLOAD_LENGTH           (MAX_MESSAGE_LENGTH - FRAME_HEADER_LENGTH)
#define MAX_REASSEMBLED_PACKET_COUNT \
    ((MAX_REASSEMBLED_MESSAGE_SIZE + MAX_PAYLOAD_LENGTH - 1) / MAX_PAYLOAD_LENGTH)

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

struct QueuedIncomingFrameView
{
    uint16_t m_nFrame = INVALID_FRAME;
    uint8_t* m_pData = NULL;
    uint32_t m_nDataSize = 0;
    CNetConnectionId m_nConnectionId = CNetConnectionId::INVALID;
    uint16_t m_nNextFrame = INVALID_FRAME;
};

static inline CNetConnectionId GetWindowConnectionId(CNetLayerWindow* thisPtr)
{ return CNetConnectionId(thisPtr->m_nConnectionId); }

static inline uint16_t GetFrameNumPackets(uint8_t* pData)
{ return (uint16_t)((((uint16_t)pData[8]) << 8) + pData[9]); }

static inline uint16_t GetFrameSeqNum(uint8_t* pData)
{ return (uint16_t)((((uint16_t)pData[3]) << 8) + pData[4]); }

static inline BOOL GetFrameDeflated(uint8_t* pData)
{ return (BOOL)(pData[7] & 0x01); }

static inline BOOL GetFrameFlagFirstMessage(uint8_t* pData)
{ return (BOOL)((pData[7] & 0x02) >> 1); }

static inline BOOL GetFrameFlagCompression(uint8_t* pData)
{ return (BOOL)((pData[7] & 0x04) >> 2); }

static inline BOOL GetFrameFlagHighPriority(uint8_t* pData)
{ return (BOOL)((pData[7] & 0x08) >> 3); }

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

static inline BOOL ValidateCompressedMessageHeader(uint8_t* pData, uint32_t nDataSize)
{
    if (GetFrameFlagCompression(pData) == FALSE)
    {
        return TRUE;
    }

    if (nDataSize < FRAME_HEADER_LENGTH + sizeof(uint32_t))
    {
        return FALSE;
    }

    uint32_t nUncompressedDataSize = pData[FRAME_HEADER_LENGTH];
    nUncompressedDataSize += (pData[FRAME_HEADER_LENGTH + 1] << 8);
    nUncompressedDataSize += (pData[FRAME_HEADER_LENGTH + 2] << 16);
    nUncompressedDataSize += (pData[FRAME_HEADER_LENGTH + 3] << 24);

    return nUncompressedDataSize <= COMPRESS_BUFFERSIZE;
}

static BOOL ReadQueuedIncomingFrame(CNetLayerWindow* thisPtr, BOOL bHighPriority,
    uint16_t nQueueIndex, QueuedIncomingFrameView* pFrameView)
{
    if (pFrameView == NULL)
    {
        return FALSE;
    }

    uint32_t nFramesAvailable = bHighPriority ? thisPtr->m_lQueueIncomingHiFrames.num
                                              : thisPtr->m_lQueueIncomingLoFrames.num;
    if (nQueueIndex >= nFramesAvailable)
    {
        return FALSE;
    }

    pFrameView->m_nFrame = bHighPriority ? thisPtr->m_lQueueIncomingHiFrames[nQueueIndex]
                                         : thisPtr->m_lQueueIncomingLoFrames[nQueueIndex];
    pFrameView->m_pData = NULL;
    pFrameView->m_nDataSize = 0;
    pFrameView->m_nConnectionId = CNetConnectionId::INVALID;
    pFrameView->m_nNextFrame = INVALID_FRAME;

    thisPtr->m_pNetLayer->m_pebFrameStorage->GetFrameData(pFrameView->m_nFrame,
        &pFrameView->m_pData, &pFrameView->m_nDataSize, &pFrameView->m_nConnectionId,
        &pFrameView->m_nNextFrame);
    return pFrameView->m_pData != NULL;
}

static inline BOOL ValidateQueuedIncomingFrameMetadata(CNetLayerWindow* thisPtr, BOOL bHighPriority,
    const QueuedIncomingFrameView* pFrameView)
{
    //
    // Frame storage is global and keeps ownership metadata alongside the payload bytes.
    // A mismatch indicates a real mess in the frame queue state, and all we can do is
    // drop it (loudly). It should never happen in prod.
    //
    return pFrameView != NULL && pFrameView->m_pData != NULL &&
        pFrameView->m_nDataSize >= FRAME_HEADER_LENGTH &&
        pFrameView->m_nConnectionId == GetWindowConnectionId(thisPtr) &&
        GetFrameFlagHighPriority(pFrameView->m_pData) == bHighPriority;
}

static void DropIncomingFrames(CNetLayerWindow* thisPtr, BOOL bHighPriority, uint16_t nFrameCount)
{
    while (nFrameCount > 0)
    {
        uint16_t nFrame = INVALID_FRAME;

        if (bHighPriority)
        {
            if (thisPtr->m_lQueueIncomingHiFrames.num <= 0)
            {
                break;
            }

            nFrame = thisPtr->m_lQueueIncomingHiFrames[0];
            thisPtr->m_lQueueIncomingHiFrames.DelIndex(0);
        }
        else
        {
            if (thisPtr->m_lQueueIncomingLoFrames.num <= 0)
            {
                break;
            }

            nFrame = thisPtr->m_lQueueIncomingLoFrames[0];
            thisPtr->m_lQueueIncomingLoFrames.DelIndex(0);
        }

        if (nFrame != INVALID_FRAME)
        {
            thisPtr->m_pNetLayer->m_pebFrameStorage->ChangeFrameReference(nFrame, -1);
        }

        --nFrameCount;
    }
}

static BOOL ufmImpl(CNetLayerWindow* thisPtr, BOOL bHighPriority)
{
    uint16_t nFrame;
    uint8_t* pData;
    uint32_t nDataSize;
    QueuedIncomingFrameView cHeadFrame;

    static_assert(sizeof(CNetInstance) == 4, "Need API fix @Daz");
    static_assert(offsetof(CNetLayer, m_nInstance) == 0x0, "Need API fix @Daz");
    static_assert(offsetof(CNetLayerWindow, m_nInstance) == 0x0, "Need API fix @Daz");
    static_assert(offsetof(CNetLayerInternal, m_nInstance) == 0x0, "Need API fix @Daz");
    static_assert(offsetof(CNetLayerInternal, m_aWindows) == 0x68, "Need API fix @Daz");

    if (ReadQueuedIncomingFrame(thisPtr, bHighPriority, 0, &cHeadFrame) == FALSE)
    {
        return FALSE;
    }

    nFrame = cHeadFrame.m_nFrame;
    pData = cHeadFrame.m_pData;
    nDataSize = cHeadFrame.m_nDataSize;

    ASSERT_OR_RETURN(nFrame != INVALID_FRAME, FALSE);

    if (ValidateQueuedIncomingFrameMetadata(thisPtr, bHighPriority, &cHeadFrame) == FALSE)
    {
        LOG_WARNING("dropping malformed incoming frame metadata: player=%u frame=%u size=%u",
            thisPtr->m_nPlayerId, nFrame, nDataSize);
        DropIncomingFrames(thisPtr, bHighPriority, 1);
        return TRUE;
    }

    uint16_t nPacketsRequired = GetFrameNumPackets(pData);

    if (GetFrameFlagFirstMessage(pData) == FALSE || nPacketsRequired == 0)
    {
        LOG_WARNING(
            "dropping orphaned fragment head: player=%u frame=%u packets=%u "
            "flags=0x%02x",
            thisPtr->m_nPlayerId, nFrame, nPacketsRequired, pData[7]);
        DropIncomingFrames(thisPtr, bHighPriority, 1);
        return TRUE;
    }

    if (ValidateCompressedMessageHeader(pData, nDataSize) == FALSE)
    {
        LOG_WARNING(
            "dropping malformed compressed message head: player=%u frame=%u packets=%u "
            "size=%u flags=0x%02x",
            thisPtr->m_nPlayerId, nFrame, nPacketsRequired, nDataSize, pData[7]);
        DropIncomingFrames(thisPtr, bHighPriority, 1);
        return TRUE;
    }

    if (nPacketsRequired == 1)
    {
        //
        // Decompose the messages that share this packet.
        // We must not walk the live frame-storage buffer directly because
        // HandleMessage() can disconnect the player re-entrantly and tear the
        // current window down, which frees queued incoming frames underneath us.
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

            if (GetFrameFlagFirstMessage(pCurrentMessage) == FALSE ||
                GetFrameNumPackets(pCurrentMessage) != 1)
            {
                LOG_WARNING(
                    "dropping malformed packed frame: player=%u packet=%u remaining=%u "
                    "flags=0x%02x",
                    thisPtr->m_nPlayerId, nDataSize, nRemainingSize, pCurrentMessage[7]);
                bPacketWellFormed = FALSE;
                break;
            }

            if (nPayloadSize > nRemainingSize - FRAME_HEADER_LENGTH)
            {
                LOG_WARNING(
                    "Packet not wellformed; sliding window gone? This would have hung the server! "
                    "player=%u packet=%u remaining=%u payload=%u flags=0x%02x",
                    thisPtr->m_nPlayerId, nDataSize, nRemainingSize, nPayloadSize,
                    pCurrentMessage[7]);
                bPacketWellFormed = FALSE;
                break;
            }

            uint32_t nMessageDataSize = nPayloadSize + FRAME_HEADER_LENGTH;

            if (ValidateCompressedMessageHeader(pCurrentMessage, nMessageDataSize) == FALSE)
            {
                LOG_WARNING(
                    "dropping malformed packed compressed frame: player=%u packet=%u "
                    "message=%u flags=0x%02x",
                    thisPtr->m_nPlayerId, nDataSize, nMessageDataSize, pCurrentMessage[7]);
                bPacketWellFormed = FALSE;
                break;
            }

            if (!thisPtr->m_pNetLayer->UncompressMessage(thisPtr->m_nPlayerId, pCurrentMessage,
                    nMessageDataSize))
            {
                bPacketWellFormed = FALSE;
                break;
            }

            nRemainingSize -= nMessageDataSize;
        }

        if (bPacketWellFormed && nRemainingSize != 0)
        {
            LOG_WARNING(
                "Packet has trailing data after unpacketization! "
                "player=%u packet=%u trailing=%u",
                thisPtr->m_nPlayerId, nDataSize, nRemainingSize);
        }

        DropIncomingFrames(thisPtr, bHighPriority, 1);
        return TRUE;
    }

    if (nPacketsRequired > MAX_REASSEMBLED_PACKET_COUNT)
    {
        LOG_WARNING("dropping absurd fragment count: player=%u frame=%u packets=%u",
            thisPtr->m_nPlayerId, nFrame, nPacketsRequired);
        DropIncomingFrames(thisPtr, bHighPriority, 1);
        return TRUE;
    }

    uint32_t nFramesAvailable = (bHighPriority) ? thisPtr->m_lQueueIncomingHiFrames.num
                                                : thisPtr->m_lQueueIncomingLoFrames.num;
    if (nFramesAvailable < nPacketsRequired)
    {
        return FALSE;
    }

    QueuedIncomingFrameView* pFragments = new QueuedIncomingFrameView[nPacketsRequired];
    SCOPEGUARD(delete[] pFragments);

    uint32_t nMessageDataSize = 0;
    uint16_t nExpectedSeq = 0;
    BOOL bMessageWellFormed = TRUE;

    for (uint16_t nPacket = 0; nPacket < nPacketsRequired; ++nPacket)
    {
        if (ReadQueuedIncomingFrame(thisPtr, bHighPriority, nPacket, &pFragments[nPacket]) ==
                FALSE ||
            ValidateQueuedIncomingFrameMetadata(thisPtr, bHighPriority, &pFragments[nPacket]) ==
                FALSE)
        {
            LOG_WARNING("dropping malformed fragment metadata: player=%u packets=%u fragment=%u",
                thisPtr->m_nPlayerId, nPacketsRequired, nPacket + 1);
            bMessageWellFormed = FALSE;
            break;
        }

        uint8_t* pFragmentData = pFragments[nPacket].m_pData;
        uint32_t nFragmentSize = pFragments[nPacket].m_nDataSize;

        if (nPacket == 0)
        {
            if (GetFrameFlagFirstMessage(pFragmentData) == FALSE ||
                GetFrameNumPackets(pFragmentData) != nPacketsRequired)
            {
                LOG_WARNING(
                    "dropping malformed fragmented message head: player=%u packets=%u "
                    "flags=0x%02x",
                    thisPtr->m_nPlayerId, nPacketsRequired, pFragmentData[7]);
                bMessageWellFormed = FALSE;
                break;
            }

            nMessageDataSize = nFragmentSize;
        }
        else
        {
            uint16_t nSeqNum = GetFrameSeqNum(pFragmentData);

            if (nSeqNum != static_cast<uint16_t>(nExpectedSeq + 1) ||
                GetFrameFlagFirstMessage(pFragmentData) || GetFrameNumPackets(pFragmentData) != 0 ||
                GetFrameFlagCompression(pFragmentData) || GetFrameDeflated(pFragmentData))
            {
                LOG_WARNING(
                    "dropping malformed fragment run: player=%u packets=%u fragment=%u "
                    "seq=%u expected=%u flags=0x%02x",
                    thisPtr->m_nPlayerId, nPacketsRequired, nPacket + 1, nSeqNum,
                    static_cast<uint16_t>(nExpectedSeq + 1), pFragmentData[7]);
                bMessageWellFormed = FALSE;
                break;
            }

            uint32_t nPayloadSize = nFragmentSize - FRAME_HEADER_LENGTH;
            if (nMessageDataSize > MAX_REASSEMBLED_MESSAGE_SIZE - nPayloadSize)
            {
                LOG_WARNING("dropping oversized fragment run: player=%u packets=%u fragment=%u",
                    thisPtr->m_nPlayerId, nPacketsRequired, nPacket + 1);
                bMessageWellFormed = FALSE;
                break;
            }

            nMessageDataSize += nPayloadSize;
        }

        nExpectedSeq = GetFrameSeqNum(pFragmentData);
    }

    if (bMessageWellFormed == FALSE)
    {
        DropIncomingFrames(thisPtr, bHighPriority, 1);
        return TRUE;
    }

    uint8_t* pMessageData = new uint8_t[nMessageDataSize];
    SCOPEGUARD(delete[] pMessageData);

    uint32_t nCopiedSize = 0;
    for (uint16_t nPacket = 0; nPacket < nPacketsRequired; ++nPacket)
    {
        uint8_t* pFragmentData = pFragments[nPacket].m_pData;
        uint32_t nFragmentSize = pFragments[nPacket].m_nDataSize;
        ASSERT_OR_RETURN(pFragmentData != NULL, FALSE);

        if (nPacket == 0)
        {
            memcpy(pMessageData, pFragmentData, nFragmentSize);
            nCopiedSize = nFragmentSize;
        }
        else
        {
            uint32_t nPayloadSize = nFragmentSize - FRAME_HEADER_LENGTH;
            memcpy(pMessageData + nCopiedSize, pFragmentData + FRAME_HEADER_LENGTH, nPayloadSize);
            nCopiedSize += nPayloadSize;
        }
    }

    DropIncomingFrames(thisPtr, bHighPriority, nPacketsRequired);

    thisPtr->m_pNetLayer->UncompressMessage(thisPtr->m_nPlayerId, pMessageData, nCopiedSize);

    return TRUE;
}

static void UFM_HotfixCtor() __attribute__((constructor));
static void UFM_HotfixCtor()
{
    if (!Config::Get<bool>("UFM_HOTFIX", false))
        return;

    LOG_INFO(
        "EXPERIMENTAL: Attempting to resolve server hangs in "
        "CNetLayerWindow::UnpacketizeFullMessages.");

    ufmHook = Hooks::HookFunction(&CNetLayerWindow::UnpacketizeFullMessages, ufmImpl,
        Hooks::Order::Earliest);
}
