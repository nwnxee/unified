#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CScriptCompilerIdListEntry
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
    char* m_pchParameters;
    CExoString* m_psStructureParameterNames;
    int32_t* m_pbOptionalParameters;
    int32_t* m_pnOptionalParameterIntegerData;
    float* m_pfOptionalParameterFloatData;
    CExoString* m_psOptionalParameterStringData;
    uint32_t* m_poidOptionalParameterObjectData;
    float* m_pfOptionalParameterVectorData;
    int32_t m_nBinarySourceStart;
    int32_t m_nBinarySourceFinish;
    int32_t m_nBinaryDestinationStart;
    int32_t m_nBinaryDestinationFinish;

    // The below are auto generated stubs.
    CScriptCompilerIdListEntry(const CScriptCompilerIdListEntry&) = default;
    CScriptCompilerIdListEntry& operator=(const CScriptCompilerIdListEntry&) = default;

    CScriptCompilerIdListEntry();
    ~CScriptCompilerIdListEntry();
    int32_t ExpandParameterSpace();
};

void CScriptCompilerIdListEntry__CScriptCompilerIdListEntryCtor__0(CScriptCompilerIdListEntry* thisPtr);
void CScriptCompilerIdListEntry__CScriptCompilerIdListEntryDtor__0(CScriptCompilerIdListEntry* thisPtr);
int32_t CScriptCompilerIdListEntry__ExpandParameterSpace(CScriptCompilerIdListEntry* thisPtr);

}

}
