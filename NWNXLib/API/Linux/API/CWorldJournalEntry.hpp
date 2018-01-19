#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CWorldJournalEntry
{
    CExoString szText;
    CExoString szName;
    uint32_t nCalendarDay;
    uint32_t nTimeOfDay;
    uint32_t nName;
    uint32_t nID;
    int32_t bIdIsStrref;

    // The below are auto generated stubs.
    CWorldJournalEntry() = default;
    CWorldJournalEntry(const CWorldJournalEntry&) = default;
    CWorldJournalEntry& operator=(const CWorldJournalEntry&) = default;

    ~CWorldJournalEntry();
};

void CWorldJournalEntry__CWorldJournalEntryDtor(CWorldJournalEntry* thisPtr);

}

}
