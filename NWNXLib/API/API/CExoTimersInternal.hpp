#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoTimersInternal)
#endif



typedef int BOOL;


struct CExoTimersInternal
{
    BOOL m_bQPCActive;
    BOOL m_bQPCAlgorithm2;
    uint64_t m_nQPFrequency;
    uint64_t m_nQPCMicroSecFrequency;
    double m_fQPCMicroSecFrequency;
    volatile uint64_t m_nUsecResTimerValue;
    volatile uint32_t m_nMsecResimerValue;
    volatile time_t m_nUnixTimestampValue;
    volatile BOOL m_bShutdown;
    void * m_pTimerThread;

    CExoTimersInternal();
    ~CExoTimersInternal();
    uint32_t GetMillisecondTimerReal();
    uint64_t GetMicrosecondTimerReal();
    time_t GetUnixTimestampReal();
    uint32_t GetMillisecondTimer();
    uint64_t GetMicrosecondTimer();
    time_t GetUnixTimestamp();


#ifdef NWN_CLASS_EXTENSION_CExoTimersInternal
    NWN_CLASS_EXTENSION_CExoTimersInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoTimersInternal)
#endif

