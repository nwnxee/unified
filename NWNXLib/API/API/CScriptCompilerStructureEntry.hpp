#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompilerStructureEntry)
#endif





class CScriptCompilerStructureEntry
{
public:
    CExoString m_psName;
    int32_t m_nFieldStart;
    int32_t m_nFieldEnd;
    int32_t m_nByteSize;



#ifdef NWN_CLASS_EXTENSION_CScriptCompilerStructureEntry
    NWN_CLASS_EXTENSION_CScriptCompilerStructureEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompilerStructureEntry)
#endif

