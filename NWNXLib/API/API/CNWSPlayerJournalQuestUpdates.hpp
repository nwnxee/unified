#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerJournalQuestUpdates)
#endif





class CNWSPlayerJournalQuestUpdates
{
    uint16_t flags;
    CExoString szPlot_Id;



#ifdef NWN_CLASS_EXTENSION_CNWSPlayerJournalQuestUpdates
    NWN_CLASS_EXTENSION_CNWSPlayerJournalQuestUpdates
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerJournalQuestUpdates)
#endif

