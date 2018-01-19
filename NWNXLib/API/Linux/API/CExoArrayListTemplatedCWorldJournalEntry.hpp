#pragma once

#include <cstdint>

#include "CWorldJournalEntry.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedCWorldJournalEntry
{
    CWorldJournalEntry* element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCWorldJournalEntry() = default;
    CExoArrayListTemplatedCWorldJournalEntry(const CExoArrayListTemplatedCWorldJournalEntry&) = default;
    CExoArrayListTemplatedCWorldJournalEntry& operator=(const CExoArrayListTemplatedCWorldJournalEntry&) = default;

    ~CExoArrayListTemplatedCWorldJournalEntry();
    void Add(CWorldJournalEntry);
    void Allocate(int32_t);
};

void CExoArrayListTemplatedCWorldJournalEntry__CExoArrayListTemplatedCWorldJournalEntryDtor(CExoArrayListTemplatedCWorldJournalEntry* thisPtr);
void CExoArrayListTemplatedCWorldJournalEntry__Add(CExoArrayListTemplatedCWorldJournalEntry* thisPtr, CWorldJournalEntry);
void CExoArrayListTemplatedCWorldJournalEntry__Allocate(CExoArrayListTemplatedCWorldJournalEntry* thisPtr, int32_t);

}

}
