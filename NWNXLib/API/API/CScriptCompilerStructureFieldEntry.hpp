#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompilerStructureFieldEntry)
#endif





class CScriptCompilerStructureFieldEntry
{
public:
    uint8_t m_pchType;
    CExoString m_psStructureName;
    CExoString m_psVarName;
    int32_t m_nLocation;



#ifdef NWN_CLASS_EXTENSION_CScriptCompilerStructureFieldEntry
    NWN_CLASS_EXTENSION_CScriptCompilerStructureFieldEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompilerStructureFieldEntry)
#endif

