#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"
#include "SJournalEntry.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSJournal)
#endif

class CNWSCreature;


typedef int BOOL;


class CNWSJournal
{
public:
    CExoArrayList<SJournalEntry> m_lstEntries;
    CNWSCreature * m_pCreature;

    CNWSJournal();
    ~CNWSJournal();
    void SetState(CExoString szPlot_Id, uint32_t nState, BOOL bLoading = false);
    void SetDate(CExoString szPlot_Id, uint32_t nCalendarDay, BOOL bLoading = false);
    void SetTime(CExoString szPlot_Id, uint32_t nTimeOfDay, BOOL bLoading = false);
    void SetPicture(CExoString szPlot_Id, int32_t nPictureIndex, BOOL bLoading = false);
    void Destroy(CExoString szPlot_Id);


#ifdef NWN_CLASS_EXTENSION_CNWSJournal
    NWN_CLASS_EXTENSION_CNWSJournal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSJournal)
#endif

