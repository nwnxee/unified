#pragma once
#include "nwn_api.hpp"

#include "CExoLocString.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(SJournalEntry)
#endif



typedef int BOOL;


class SJournalEntry
{
    CExoLocString szName;
    CExoLocString szText;
    uint32_t nCalendarDay;
    uint32_t nTimeOfDay;
    CExoString szPlot_Id;
    uint32_t nState;
    uint32_t nPriority;
    uint16_t nPictureIndex;
    BOOL bQuestCompleted;
    BOOL bQuestDisplayed;
    BOOL bUpdated;



#ifdef NWN_CLASS_EXTENSION_SJournalEntry
    NWN_CLASS_EXTENSION_SJournalEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SJournalEntry)
#endif

