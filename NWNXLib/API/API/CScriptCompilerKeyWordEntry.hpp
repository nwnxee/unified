#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompilerKeyWordEntry)
#endif





class CScriptCompilerKeyWordEntry
{
public:
    CExoString m_sAlphanumericName;
    uint32_t m_nHashValue;
    uint32_t m_nNameLength;
    int32_t m_nTokenToTranslate;



#ifdef NWN_CLASS_EXTENSION_CScriptCompilerKeyWordEntry
    NWN_CLASS_EXTENSION_CScriptCompilerKeyWordEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompilerKeyWordEntry)
#endif

