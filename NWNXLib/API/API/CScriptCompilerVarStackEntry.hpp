#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompilerVarStackEntry)
#endif





class CScriptCompilerVarStackEntry
{
    CExoString m_psVarName;
    int32_t m_nVarType;
    int32_t m_nVarLevel;
    int32_t m_nVarRunTimeLocation;
    CExoString m_sVarStructureName;



#ifdef NWN_CLASS_EXTENSION_CScriptCompilerVarStackEntry
    NWN_CLASS_EXTENSION_CScriptCompilerVarStackEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompilerVarStackEntry)
#endif

