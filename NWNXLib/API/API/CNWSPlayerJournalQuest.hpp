#pragma once
#include "nwn_api.hpp"

#include "CNWSPlayerJournalQuestUpdates.hpp"
#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerJournalQuest)
#endif



typedef int BOOL;


struct CNWSPlayerJournalQuest
{
    BOOL m_bOpen;
    CExoArrayList<CNWSPlayerJournalQuestUpdates> m_lstModifications;
    BOOL m_bFullUpdateNeeded;



#ifdef NWN_CLASS_EXTENSION_CNWSPlayerJournalQuest
    NWN_CLASS_EXTENSION_CNWSPlayerJournalQuest
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerJournalQuest)
#endif

