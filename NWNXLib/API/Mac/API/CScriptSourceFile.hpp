#pragma once

#include <cstdint>

#include "CResHelperTemplatedCResNSS2009u.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoString;

struct CScriptSourceFile
    : CResHelperTemplatedCResNSS2009u
{

    // The below are auto generated stubs.
    CScriptSourceFile(const CScriptSourceFile&) = default;
    CScriptSourceFile& operator=(const CScriptSourceFile&) = default;

    CScriptSourceFile();
    ~CScriptSourceFile();
    int32_t LoadScript(const CExoString&, char**, uint32_t*);
    void UnloadScript();
};

void CScriptSourceFile__CScriptSourceFileCtor__0(CScriptSourceFile* thisPtr);
void CScriptSourceFile__CScriptSourceFileDtor__0(CScriptSourceFile* thisPtr);
int32_t CScriptSourceFile__LoadScript(CScriptSourceFile* thisPtr, const CExoString&, char**, uint32_t*);
void CScriptSourceFile__UnloadScript(CScriptSourceFile* thisPtr);

}

}
