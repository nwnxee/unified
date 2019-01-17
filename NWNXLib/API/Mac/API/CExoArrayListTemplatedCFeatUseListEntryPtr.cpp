#include "CExoArrayListTemplatedCFeatUseListEntryPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CFeatUseListEntry.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCFeatUseListEntryPtr::~CExoArrayListTemplatedCFeatUseListEntryPtr()
{
    CExoArrayListTemplatedCFeatUseListEntryPtr__CExoArrayListTemplatedCFeatUseListEntryPtrDtor(this);
}

void CExoArrayListTemplatedCFeatUseListEntryPtr__CExoArrayListTemplatedCFeatUseListEntryPtrDtor(CExoArrayListTemplatedCFeatUseListEntryPtr* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCFeatUseListEntryPtr*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCFeatUseListEntryPtr__CExoArrayListTemplatedCFeatUseListEntryPtrDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
