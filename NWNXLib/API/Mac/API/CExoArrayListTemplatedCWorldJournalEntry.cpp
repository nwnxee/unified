#include "CExoArrayListTemplatedCWorldJournalEntry.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CWorldJournalEntry.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCWorldJournalEntry::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCWorldJournalEntry__Allocate(this, a0);
}

void CExoArrayListTemplatedCWorldJournalEntry__Allocate(CExoArrayListTemplatedCWorldJournalEntry* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCWorldJournalEntry*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCWorldJournalEntry__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
