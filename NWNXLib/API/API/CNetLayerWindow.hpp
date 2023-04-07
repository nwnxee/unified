#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNetLayerWindow)
#endif

struct CNetLayerInternal;
struct z_stream;


typedef int BOOL;


struct CNetLayerWindow
{
    BOOL m_bInitialized;
    CNetLayerInternal * m_pNetLayer;
    BOOL m_bWindowInUse;
    uint32_t m_nPlayerId;
    uint32_t m_nConnectionId;
    uint32_t m_nAckExpected;
    uint32_t m_nNextFrameToSend;
    uint32_t m_nFrameExpected;
    uint32_t m_nTooFar;
    uint32_t m_nNumBuffered;
    BOOL m_bNoNak;
    uint32_t m_nPacketTimeOut;
    uint32_t m_nAckTimeOut;
    uint32_t m_nInFrameTimeOut;
    uint32_t m_nFauxNagleTimeOut;
    uint32_t m_nAckTimer;
    BOOL m_bAckTimerSet;
    uint32_t m_nFauxNagleRuns;
    uint32_t m_nFauxNagleTimer;
    BOOL m_bFauxNagleTimerSet;
    uint32_t m_nInFrameBaseTime;
    uint32_t m_nInFrameTimer;
    BOOL m_bInFrameTimerSet;
    uint16_t m_pOutgoingBuffers[16];
    BOOL m_pbTimeOutSet[16];
    uint32_t m_pnTimeOut[16];
    uint16_t m_pIncomingBuffers[16];
    BOOL m_pbArrived[16];
    CExoArrayList<uint16_t> m_lQueueOutgoingHiFrames;
    CExoArrayList<uint16_t> m_lQueueOutgoingLoFrames;
    CExoArrayList<uint16_t> m_lQueueIncomingHiFrames;
    CExoArrayList<uint16_t> m_lQueueIncomingLoFrames;
    uint8_t m_pLowPriorityHoldBuffer[960];
    uint8_t m_pHighPriorityHoldBuffer[960];
    uint32_t m_nLowPriorityHoldBufferSize;
    uint32_t m_nHighPriorityHoldBufferSize;
    uint32_t m_nOutgoingNumBuffers;
    uint32_t m_nIncomingNumBuffers;
    uint32_t m_nOutgoingPacketsSinceResend;
    uint32_t m_nOutgoingPacketsTimedOut;
    BOOL m_bCutOutgoingNumBuffers;
    BOOL m_bReceivedPacket;
    BOOL m_bAcknowledgeImmediately;
    z_stream * m_pCompressionStream;
    z_stream * m_pDecompressionStream;

    CNetLayerWindow();
    ~CNetLayerWindow();
    void Initialize(CNetLayerInternal * pNetLayer);
    void ShutDown();
    void InitializeCompressionBuffers();
    BOOL AddToHighOutgoingQueue(uint16_t nFrame);
    BOOL AddToLowOutgoingQueue(uint16_t nFrame);
    void LoadWindowWithFrames();
    void PlaceFrameInOutgoingBuffers(uint16_t nFrame);
    void FrameSend(uint8_t nMessageType, uint16_t nFrameWindowNumber, uint16_t nFrameReference);
    BOOL FrameNumberBetween(uint32_t a, uint32_t b, uint32_t c);
    BOOL FrameReceive(uint8_t * pData, uint32_t dwSize);
    BOOL FrameTimeout(uint32_t nApplicationType);
    void SetOutFrameTimer(uint32_t nBuffer);
    BOOL TestOutFrameTimer(uint32_t nBuffer, uint32_t nCurrentTime);
    void SetAckTimer();
    BOOL TestAckTimer(uint32_t nCurrentTime);
    void SetFauxNagleTimer();
    BOOL TestFauxNagleTimer(uint32_t nCurrentTime);
    BOOL FauxNagle();
    void SetInFrameTimer();
    BOOL TestInFrameTimer(uint32_t nCurrentTime);
    BOOL UnpacketizeFullMessages(BOOL bHighPriority);
    void DoubleOutgoingBufferSize();
    void CutOutgoingBufferSize();


#ifdef NWN_CLASS_EXTENSION_CNetLayerWindow
    NWN_CLASS_EXTENSION_CNetLayerWindow
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNetLayerWindow)
#endif

