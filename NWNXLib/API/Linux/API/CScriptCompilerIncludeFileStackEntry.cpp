#include "CScriptCompilerIncludeFileStackEntry.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CScriptCompilerIncludeFileStackEntry::CScriptCompilerIncludeFileStackEntry()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CScriptCompilerIncludeFileStackEntry::CScriptCompilerIncludeFileStackEntry(const CScriptCompilerIncludeFileStackEntry&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CScriptCompilerIncludeFileStackEntry& CScriptCompilerIncludeFileStackEntry::operator=(const CScriptCompilerIncludeFileStackEntry&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

CScriptCompilerIncludeFileStackEntry::~CScriptCompilerIncludeFileStackEntry()
{
    CScriptCompilerIncludeFileStackEntry__CScriptCompilerIncludeFileStackEntryDtor(this);
}

void CScriptCompilerIncludeFileStackEntry__CScriptCompilerIncludeFileStackEntryDtor(CScriptCompilerIncludeFileStackEntry* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompilerIncludeFileStackEntry*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompilerIncludeFileStackEntry__CScriptCompilerIncludeFileStackEntryDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
