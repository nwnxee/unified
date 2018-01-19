#include "CExoArrayListTemplatedCWorldJournalEntry.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CWorldJournalEntry.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCWorldJournalEntry::~CExoArrayListTemplatedCWorldJournalEntry()
{
    CExoArrayListTemplatedCWorldJournalEntry__CExoArrayListTemplatedCWorldJournalEntryDtor(this);
}

void CExoArrayListTemplatedCWorldJournalEntry::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCWorldJournalEntry__Allocate(this, a0);
}

void CExoArrayListTemplatedCWorldJournalEntry::SetSize(int32_t a0)
{
    return CExoArrayListTemplatedCWorldJournalEntry__SetSize(this, a0);
}

void CExoArrayListTemplatedCWorldJournalEntry__CExoArrayListTemplatedCWorldJournalEntryDtor(CExoArrayListTemplatedCWorldJournalEntry* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCWorldJournalEntry*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCWorldJournalEntry__CExoArrayListTemplatedCWorldJournalEntryDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoArrayListTemplatedCWorldJournalEntry__Allocate(CExoArrayListTemplatedCWorldJournalEntry* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCWorldJournalEntry*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCWorldJournalEntry__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedCWorldJournalEntry__SetSize(CExoArrayListTemplatedCWorldJournalEntry* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCWorldJournalEntry*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCWorldJournalEntry__SetSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
