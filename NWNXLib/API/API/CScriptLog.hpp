#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptLog)
#endif





class CScriptLog
{
public:
    CExoString m_sScriptName;
    int32_t m_nTimesRun;
    uint32_t m_nTotalTime;



#ifdef NWN_CLASS_EXTENSION_CScriptLog
    NWN_CLASS_EXTENSION_CScriptLog
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptLog)
#endif

