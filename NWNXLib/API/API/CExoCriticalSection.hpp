#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoCriticalSection)
#endif

class CExoCriticalSectionInternal;




class CExoCriticalSection
{
    CExoCriticalSectionInternal * m_pcExoCriticalSectionInternal;

    CExoCriticalSection();
    ~CExoCriticalSection();
    void EnterCriticalSection();
    void LeaveCriticalSection();


#ifdef NWN_CLASS_EXTENSION_CExoCriticalSection
    NWN_CLASS_EXTENSION_CExoCriticalSection
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoCriticalSection)
#endif

