#pragma once

#include <cstdint>

#include "CExoLocString.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct SJournalEntry
{
    CExoLocString szName;
    CExoLocString szText;
    uint32_t nCalendarDay;
    uint32_t nTimeOfDay;
    CExoString szPlot_Id;
    uint32_t nState;
    uint32_t nPriority;
    uint16_t nPictureIndex;
    int32_t bQuestCompleted;
    int32_t bQuestDisplayed;
    int32_t bUpdated;

    // The below are auto generated stubs.
    SJournalEntry();
    SJournalEntry(const SJournalEntry&);
    SJournalEntry& operator=(const SJournalEntry&);

    ~SJournalEntry();
};

void SJournalEntry__SJournalEntryDtor(SJournalEntry* thisPtr);

}

}
