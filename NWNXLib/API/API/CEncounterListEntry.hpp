#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CEncounterListEntry)
#endif



typedef int BOOL;


class CEncounterListEntry
{
public:
    CResRef m_cCreatureResRef;
    float m_fCR;
    float m_fCreaturePoints;
    BOOL m_bAlreadyUsed;
    BOOL m_bAlreadyChecked;
    BOOL m_bUnique;



#ifdef NWN_CLASS_EXTENSION_CEncounterListEntry
    NWN_CLASS_EXTENSION_CEncounterListEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CEncounterListEntry)
#endif

