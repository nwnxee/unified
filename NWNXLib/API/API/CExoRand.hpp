#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoRand)
#endif

class CExoRandInternal;




class CExoRand
{
public:
    CExoRandInternal * m_pcExoRandInternal;

    CExoRand();
    ~CExoRand();
    uint32_t Rand();
    CExoString GetString(uint16_t nLength);
    void SignalEvent();
    void SignalEvent(uint32_t nTimeStamp);


#ifdef NWN_CLASS_EXTENSION_CExoRand
    NWN_CLASS_EXTENSION_CExoRand
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoRand)
#endif

