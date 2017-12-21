#include "SJournalEntry.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

SJournalEntry::SJournalEntry()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

SJournalEntry::SJournalEntry(const SJournalEntry&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

SJournalEntry& SJournalEntry::operator=(const SJournalEntry&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

SJournalEntry::~SJournalEntry()
{
    SJournalEntry__SJournalEntryDtor(this);
}

void SJournalEntry__SJournalEntryDtor(SJournalEntry* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(SJournalEntry*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::SJournalEntry__SJournalEntryDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
