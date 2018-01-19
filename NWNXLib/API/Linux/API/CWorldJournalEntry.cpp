#include "CWorldJournalEntry.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CWorldJournalEntry::~CWorldJournalEntry()
{
    CWorldJournalEntry__CWorldJournalEntryDtor(this);
}

void CWorldJournalEntry__CWorldJournalEntryDtor(CWorldJournalEntry* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldJournalEntry*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldJournalEntry__CWorldJournalEntryDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
