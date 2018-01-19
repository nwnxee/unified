#include "CExoArrayListTemplatedCFeatUseListEntryPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CFeatUseListEntry.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCFeatUseListEntryPtr::Add(CFeatUseListEntry* a0)
{
    return CExoArrayListTemplatedCFeatUseListEntryPtr__Add(this, a0);
}

void CExoArrayListTemplatedCFeatUseListEntryPtr__Add(CExoArrayListTemplatedCFeatUseListEntryPtr* thisPtr, CFeatUseListEntry* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCFeatUseListEntryPtr*, CFeatUseListEntry*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCFeatUseListEntryPtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
