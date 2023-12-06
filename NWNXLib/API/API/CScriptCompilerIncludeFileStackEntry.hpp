#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompilerIncludeFileStackEntry)
#endif





struct CScriptCompilerIncludeFileStackEntry
{
    CExoString m_sCompiledScriptName;
    CExoString m_sSourceScript;
    int32_t m_nLine;
    int32_t m_nCharacterOnLine;
    int32_t m_nTokenStatus;
    int32_t m_nTokenCharacters;



#ifdef NWN_CLASS_EXTENSION_CScriptCompilerIncludeFileStackEntry
    NWN_CLASS_EXTENSION_CScriptCompilerIncludeFileStackEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompilerIncludeFileStackEntry)
#endif

