#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoTimers)
#endif

struct CExoTimersInternal;


typedef int BOOL;


struct CExoTimers
{
    CExoTimersInternal * m_pcExoTimersInternal;

    CExoTimers();
    ~CExoTimers();
    uint32_t GetLowResolutionTimer(BOOL bForceSyncTimer = false);
    uint64_t GetHighResolutionTimer(BOOL bForceSyncTimer = false);


#ifdef NWN_CLASS_EXTENSION_CExoTimers
    NWN_CLASS_EXTENSION_CExoTimers
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoTimers)
#endif

