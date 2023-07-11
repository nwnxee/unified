#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompilerIdListEntry)
#endif



typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CScriptCompilerIdListEntry
{
    CExoString m_psIdentifier;
    uint32_t m_nIdentifierLength;
    uint32_t m_nIdentifierHash;
    int32_t m_nIdentifierType;
    int32_t m_nReturnType;
    int32_t m_bImplementationInPlace;
    CExoString m_psStructureReturnName;
    CExoString m_psStringData;
    int32_t m_nIntegerData;
    float m_fFloatData;
    float m_fVectorData[3];
    int32_t m_nIdIdentifier;
    int32_t m_nParameters;
    int32_t m_nNonOptionalParameters;
    int32_t m_nParameterSpace;
    char * m_pchParameters;
    CExoString * m_psStructureParameterNames;
    BOOL * m_pbOptionalParameters;
    int32_t * m_pnOptionalParameterIntegerData;
    float * m_pfOptionalParameterFloatData;
    CExoString * m_psOptionalParameterStringData;
    OBJECT_ID * m_poidOptionalParameterObjectData;
    float * m_pfOptionalParameterVectorData;
    int32_t m_nBinarySourceStart;
    int32_t m_nBinarySourceFinish;
    int32_t m_nBinaryDestinationStart;
    int32_t m_nBinaryDestinationFinish;

    CScriptCompilerIdListEntry();
    ~CScriptCompilerIdListEntry();
    int32_t ExpandParameterSpace();


#ifdef NWN_CLASS_EXTENSION_CScriptCompilerIdListEntry
    NWN_CLASS_EXTENSION_CScriptCompilerIdListEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompilerIdListEntry)
#endif

