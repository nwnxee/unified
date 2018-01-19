#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWCreatureStatsUpdate;
struct CNWSPlayer;

struct CNWSPlayerCharSheetGUI
{
    uint32_t m_oidCreatureDisplayed;
    char m_nActivePanel;
    CNWCreatureStatsUpdate* m_pLastStatsUpdate;
    int32_t m_bForceInitialCharSheetUpdate;

    uint32_t ComputeCharacterSheetUpdateRequired(CNWSPlayer*);
    void SetCreatureDisplayed(uint32_t);
};

uint32_t CNWSPlayerCharSheetGUI__ComputeCharacterSheetUpdateRequired(CNWSPlayerCharSheetGUI* thisPtr, CNWSPlayer*);
void CNWSPlayerCharSheetGUI__SetCreatureDisplayed(CNWSPlayerCharSheetGUI* thisPtr, uint32_t);

}

}
