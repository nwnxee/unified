#pragma once

#include <cstdint>

#include "SJournalEntry.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedSJournalEntry
{
    SJournalEntry* element;
    int32_t num;
    int32_t array_size;

    void Add(SJournalEntry);
    void Allocate(int32_t);
};

void CExoArrayListTemplatedSJournalEntry__Add(CExoArrayListTemplatedSJournalEntry* thisPtr, SJournalEntry);
void CExoArrayListTemplatedSJournalEntry__Allocate(CExoArrayListTemplatedSJournalEntry* thisPtr, int32_t);

}

}
