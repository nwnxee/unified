#include "CScriptCompilerIdListEntry.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CScriptCompilerIdListEntry::CScriptCompilerIdListEntry()
{
    CScriptCompilerIdListEntry__CScriptCompilerIdListEntryCtor__0(this);
}

CScriptCompilerIdListEntry::~CScriptCompilerIdListEntry()
{
    CScriptCompilerIdListEntry__CScriptCompilerIdListEntryDtor__0(this);
}

int32_t CScriptCompilerIdListEntry::ExpandParameterSpace()
{
    return CScriptCompilerIdListEntry__ExpandParameterSpace(this);
}

void CScriptCompilerIdListEntry__CScriptCompilerIdListEntryCtor__0(CScriptCompilerIdListEntry* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompilerIdListEntry*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompilerIdListEntry__CScriptCompilerIdListEntryCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CScriptCompilerIdListEntry__CScriptCompilerIdListEntryDtor__0(CScriptCompilerIdListEntry* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptCompilerIdListEntry*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompilerIdListEntry__CScriptCompilerIdListEntryDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CScriptCompilerIdListEntry__ExpandParameterSpace(CScriptCompilerIdListEntry* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptCompilerIdListEntry*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptCompilerIdListEntry__ExpandParameterSpace);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
