#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedshortunsignedint.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNetLayerInternal;
struct z_stream;

struct CNetLayerWindow
{
    int32_t m_bInitialized;
    CNetLayerInternal* m_pNetLayer;
    int32_t m_bWindowInUse;
    uint32_t m_nPlayerId;
    uint32_t m_nReceiveConnectionId;
    uint32_t m_nSendConnectionId;
    uint32_t m_nAckExpected;
    uint32_t m_nNextFrameToSend;
    uint32_t m_nFrameExpected;
    uint32_t m_nTooFar;
    uint32_t m_nNumBuffered;
    int32_t m_bNoNak;
    uint32_t m_nPacketTimeOut;
    uint32_t m_nAckTimeOut;
    uint32_t m_nInFrameTimeOut;
    uint32_t m_nFauxNagleTimeOut;
    uint32_t m_nAckTimer;
    int32_t m_bAckTimerSet;
    uint32_t m_nFauxNagleRuns;
    uint32_t m_nFauxNagleTimer;
    int32_t m_bFauxNagleTimerSet;
    uint32_t m_nInFrameBaseTime;
    uint32_t m_nInFrameTimer;
    int32_t m_bInFrameTimerSet;
    uint16_t m_pOutgoingBuffers[16];
    int32_t m_pbTimeOutSet[16];
    uint32_t m_pnTimeOut[16];
    uint16_t m_pIncomingBuffers[16];
    int32_t m_pbArrived[16];
    CExoLinkedListTemplatedshortunsignedint m_lQueueOutgoingHiFrames;
    CExoLinkedListTemplatedshortunsignedint m_lQueueOutgoingLoFrames;
    CExoLinkedListTemplatedshortunsignedint m_lQueueIncomingHiFrames;
    CExoLinkedListTemplatedshortunsignedint m_lQueueIncomingLoFrames;
    uint8_t m_pLowPriorityHoldBuffer[960];
    uint8_t m_pHighPriorityHoldBuffer[960];
    uint32_t m_nLowPriorityHoldBufferSize;
    uint32_t m_nHighPriorityHoldBufferSize;
    uint32_t m_nOutgoingNumBuffers;
    uint32_t m_nIncomingNumBuffers;
    uint32_t m_nOutgoingPacketsSinceResend;
    uint32_t m_nOutgoingPacketsTimedOut;
    int32_t m_bCutOutgoingNumBuffers;
    int32_t m_bReceivedPacket;
    int32_t m_bAcknowledgeImmediately;
    z_stream* m_pCompressionStream;
    z_stream* m_pDecompressionStream;

    // The below are auto generated stubs.
    CNetLayerWindow(const CNetLayerWindow&) = default;
    CNetLayerWindow& operator=(const CNetLayerWindow&) = default;

    CNetLayerWindow();
    ~CNetLayerWindow();
    int32_t AddToHighOutgoingQueue(uint16_t);
    int32_t AddToLowOutgoingQueue(uint16_t);
    void CutOutgoingBufferSize();
    void DoubleOutgoingBufferSize();
    int32_t FauxNagle();
    int32_t FrameNumberBetween(uint32_t, uint32_t, uint32_t);
    int32_t FrameReceive(unsigned char*, uint32_t);
    void FrameSend(unsigned char, uint16_t, uint16_t);
    int32_t FrameTimeout(uint32_t);
    void Initialize(CNetLayerInternal*);
    void InitializeCompressionBuffers();
    void LoadWindowWithFrames();
    void PlaceFrameInOutgoingBuffers(uint16_t);
    void SetAckTimer();
    void SetFauxNagleTimer();
    void SetInFrameTimer();
    void SetOutFrameTimer(uint32_t);
    void ShutDown();
    int32_t TestAckTimer(uint32_t);
    int32_t TestFauxNagleTimer(uint32_t);
    int32_t TestInFrameTimer(uint32_t);
    int32_t TestOutFrameTimer(uint32_t, uint32_t);
    int32_t UnpacketizeFullMessages(int32_t);
};

void CNetLayerWindow__CNetLayerWindowCtor__0(CNetLayerWindow* thisPtr);
void CNetLayerWindow__CNetLayerWindowDtor__0(CNetLayerWindow* thisPtr);
int32_t CNetLayerWindow__AddToHighOutgoingQueue(CNetLayerWindow* thisPtr, uint16_t);
int32_t CNetLayerWindow__AddToLowOutgoingQueue(CNetLayerWindow* thisPtr, uint16_t);
void CNetLayerWindow__CutOutgoingBufferSize(CNetLayerWindow* thisPtr);
void CNetLayerWindow__DoubleOutgoingBufferSize(CNetLayerWindow* thisPtr);
int32_t CNetLayerWindow__FauxNagle(CNetLayerWindow* thisPtr);
int32_t CNetLayerWindow__FrameNumberBetween(CNetLayerWindow* thisPtr, uint32_t, uint32_t, uint32_t);
int32_t CNetLayerWindow__FrameReceive(CNetLayerWindow* thisPtr, unsigned char*, uint32_t);
void CNetLayerWindow__FrameSend(CNetLayerWindow* thisPtr, unsigned char, uint16_t, uint16_t);
int32_t CNetLayerWindow__FrameTimeout(CNetLayerWindow* thisPtr, uint32_t);
void CNetLayerWindow__Initialize(CNetLayerWindow* thisPtr, CNetLayerInternal*);
void CNetLayerWindow__InitializeCompressionBuffers(CNetLayerWindow* thisPtr);
void CNetLayerWindow__LoadWindowWithFrames(CNetLayerWindow* thisPtr);
void CNetLayerWindow__PlaceFrameInOutgoingBuffers(CNetLayerWindow* thisPtr, uint16_t);
void CNetLayerWindow__SetAckTimer(CNetLayerWindow* thisPtr);
void CNetLayerWindow__SetFauxNagleTimer(CNetLayerWindow* thisPtr);
void CNetLayerWindow__SetInFrameTimer(CNetLayerWindow* thisPtr);
void CNetLayerWindow__SetOutFrameTimer(CNetLayerWindow* thisPtr, uint32_t);
void CNetLayerWindow__ShutDown(CNetLayerWindow* thisPtr);
int32_t CNetLayerWindow__TestAckTimer(CNetLayerWindow* thisPtr, uint32_t);
int32_t CNetLayerWindow__TestFauxNagleTimer(CNetLayerWindow* thisPtr, uint32_t);
int32_t CNetLayerWindow__TestInFrameTimer(CNetLayerWindow* thisPtr, uint32_t);
int32_t CNetLayerWindow__TestOutFrameTimer(CNetLayerWindow* thisPtr, uint32_t, uint32_t);
int32_t CNetLayerWindow__UnpacketizeFullMessages(CNetLayerWindow* thisPtr, int32_t);

}

}
