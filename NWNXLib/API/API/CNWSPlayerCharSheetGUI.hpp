#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerCharSheetGUI)
#endif

struct CNWSPlayer;
struct CNWCreatureStatsUpdate;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSPlayerCharSheetGUI
{
    OBJECT_ID m_oidCreatureDisplayed;
    char m_nActivePanel;
    CNWCreatureStatsUpdate * m_pLastStatsUpdate;
    BOOL m_bForceInitialCharSheetUpdate;

    uint32_t ComputeCharacterSheetUpdateRequired(CNWSPlayer * pPlayer);
    void SetCreatureDisplayed(OBJECT_ID oidCreature);


#ifdef NWN_CLASS_EXTENSION_CNWSPlayerCharSheetGUI
    NWN_CLASS_EXTENSION_CNWSPlayerCharSheetGUI
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerCharSheetGUI)
#endif

