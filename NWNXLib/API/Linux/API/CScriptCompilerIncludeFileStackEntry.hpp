#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CScriptSourceFile.hpp"

namespace NWNXLib {

namespace API {

struct CScriptCompilerIncludeFileStackEntry
{
    CExoString m_sCompiledScriptName;
    CScriptSourceFile m_cSourceScript;
    int32_t m_nLine;
    int32_t m_nCharacterOnLine;
    int32_t m_nTokenStatus;
    int32_t m_nTokenCharacters;

    // The below are auto generated stubs.
    CScriptCompilerIncludeFileStackEntry() = default;
    CScriptCompilerIncludeFileStackEntry(const CScriptCompilerIncludeFileStackEntry&) = default;
    CScriptCompilerIncludeFileStackEntry& operator=(const CScriptCompilerIncludeFileStackEntry&) = default;

    ~CScriptCompilerIncludeFileStackEntry();
};

void CScriptCompilerIncludeFileStackEntry__CScriptCompilerIncludeFileStackEntryDtor(CScriptCompilerIncludeFileStackEntry* thisPtr);

}

}
