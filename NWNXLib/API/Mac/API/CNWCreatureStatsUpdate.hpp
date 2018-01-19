#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCEffectIconObjectPtr.hpp"
#include "CExoArrayListTemplatedshortunsignedint.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CCombatInformation;

struct CNWCreatureStatsUpdate
{
    CExoArrayListTemplatedshortunsignedint m_lstFeats;
    CExoArrayListTemplatedshortunsignedint m_lstBonusFeats;
    uint32_t m_oidFeatUpdated;
    uint32_t m_nSkillUpdateFlag;
    CExoArrayListTemplatedCEffectIconObjectPtr m_aLastUpdateEffectArray;
    uint8_t m_nSTRStat;
    uint8_t m_nDEXStat;
    uint8_t m_nCONStat;
    uint8_t m_nINTStat;
    uint8_t m_nWISStat;
    uint8_t m_nCHAStat;
    uint8_t m_nSTRBase;
    uint8_t m_nDEXBase;
    uint8_t m_nCONBase;
    uint8_t m_nINTBase;
    uint8_t m_nWISBase;
    uint8_t m_nCHABase;
    char m_nSTRBonus;
    char m_nDEXBonus;
    char m_nCONBonus;
    char m_nINTBonus;
    char m_nWISBonus;
    char m_nCHABonus;
    char m_nDEXACModifier;
    char m_nFortSave;
    char m_nWillSave;
    char m_nReflexSave;
    char m_nNegativeLevels[3];
    int16_t m_nCurrentHP;
    int16_t m_nMaxHP;
    uint32_t m_nCurrentXP;
    int32_t m_bUseMonkAttackTable;
    uint8_t m_nBaseAttackBonus;
    char m_nBaseFortSavingThrow;
    char m_nBaseWillSavingThrow;
    char m_nBaseReflexSavingThrow;
    int16_t m_nArmorClass;
    CCombatInformation* m_pCombatInformation;
    char* m_lstSkillRanks;

    // The below are auto generated stubs.
    CNWCreatureStatsUpdate(const CNWCreatureStatsUpdate&) = default;
    CNWCreatureStatsUpdate& operator=(const CNWCreatureStatsUpdate&) = default;

    CNWCreatureStatsUpdate();
    ~CNWCreatureStatsUpdate();
    void ClearEffectIcons();
    void SetCombatInformation(CCombatInformation*);
};

void CNWCreatureStatsUpdate__CNWCreatureStatsUpdateCtor__0(CNWCreatureStatsUpdate* thisPtr);
void CNWCreatureStatsUpdate__CNWCreatureStatsUpdateDtor__0(CNWCreatureStatsUpdate* thisPtr);
void CNWCreatureStatsUpdate__ClearEffectIcons(CNWCreatureStatsUpdate* thisPtr);
void CNWCreatureStatsUpdate__SetCombatInformation(CNWCreatureStatsUpdate* thisPtr, CCombatInformation*);

}

}
