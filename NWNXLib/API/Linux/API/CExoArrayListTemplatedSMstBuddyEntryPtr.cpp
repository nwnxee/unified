#include "CExoArrayListTemplatedSMstBuddyEntryPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "SMstBuddyEntry.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedSMstBuddyEntryPtr::Add(SMstBuddyEntry* a0)
{
    return CExoArrayListTemplatedSMstBuddyEntryPtr__Add(this, a0);
}

void CExoArrayListTemplatedSMstBuddyEntryPtr__Add(CExoArrayListTemplatedSMstBuddyEntryPtr* thisPtr, SMstBuddyEntry* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedSMstBuddyEntryPtr*, SMstBuddyEntry*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedSMstBuddyEntryPtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
