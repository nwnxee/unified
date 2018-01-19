#include "SJournalEntry.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

SJournalEntry::SJournalEntry()
{
    SJournalEntry__SJournalEntryCtor(this);
}

void SJournalEntry__SJournalEntryCtor(SJournalEntry* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(SJournalEntry*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::SJournalEntry__SJournalEntryCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

}

}
