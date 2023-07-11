#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWCreatureStatsUpdate)
#endif

class CCombatInformation;
class CEffectIconObject;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWCreatureStatsUpdate
{
    CExoArrayList<uint16_t> m_lstFeats;
    CExoArrayList<uint16_t> m_lstBonusFeats;
    OBJECT_ID m_oidFeatUpdated;
    uint32_t m_nSkillUpdateFlag;
    CExoArrayList<CEffectIconObject *> m_aLastUpdateEffectArray;
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
    BOOL m_bUseMonkAttackTable;
    uint8_t m_nBaseAttackBonus;
    char m_nBaseFortSavingThrow;
    char m_nBaseWillSavingThrow;
    char m_nBaseReflexSavingThrow;
    int16_t m_nArmorClass;
    CCombatInformation * m_pCombatInformation;
    char * m_lstSkillRanks;

    CNWCreatureStatsUpdate();
    ~CNWCreatureStatsUpdate();
    void SetCombatInformation(CCombatInformation * pData);
    void ClearEffectIcons();


#ifdef NWN_CLASS_EXTENSION_CNWCreatureStatsUpdate
    NWN_CLASS_EXTENSION_CNWCreatureStatsUpdate
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWCreatureStatsUpdate)
#endif

