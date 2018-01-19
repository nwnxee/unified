#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CWorldJournalEntry;

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
    void Allocate(int32_t);
    void SetSize(int32_t);
};

void CExoArrayListTemplatedCWorldJournalEntry__CExoArrayListTemplatedCWorldJournalEntryDtor(CExoArrayListTemplatedCWorldJournalEntry* thisPtr);
void CExoArrayListTemplatedCWorldJournalEntry__Allocate(CExoArrayListTemplatedCWorldJournalEntry* thisPtr, int32_t);
void CExoArrayListTemplatedCWorldJournalEntry__SetSize(CExoArrayListTemplatedCWorldJournalEntry* thisPtr, int32_t);

}

}
