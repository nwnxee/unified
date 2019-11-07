#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CWorldJournalEntry)
#endif



typedef uint32_t STRREF;
typedef int BOOL;


struct CWorldJournalEntry
{
    CExoString szText;
    CExoString szName;
    uint32_t nCalendarDay;
    uint32_t nTimeOfDay;
    STRREF nName;
    uint32_t nID;
    BOOL bIdIsStrref;



#ifdef NWN_CLASS_EXTENSION_CWorldJournalEntry
    NWN_CLASS_EXTENSION_CWorldJournalEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CWorldJournalEntry)
#endif

