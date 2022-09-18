#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWClass)
#endif

struct CNWClass_Feat;
struct CNWClass_Skill;
struct CNWRules;


typedef int BOOL;


struct CNWClass
{
    uint32_t m_nName;
    uint32_t m_nShort;
    uint32_t m_nNameLower;
    uint32_t m_nNamePlural;
    uint32_t m_nDescription;
    CExoString m_sIcon;
    CExoString m_sPreReqTable;
    uint8_t m_lstBaseAttackBonus[60];
    uint8_t m_nHitDie;
    uint8_t m_nSkillPointBase;
    uint8_t m_lstFortificationSaveThrowBonus[60];
    uint8_t m_lstWillSaveThrowBonus[60];
    uint8_t m_lstReflexSaveThrowBonus[60];
    uint8_t * * m_lstSpellKnownTable;
    uint8_t m_lstSpellLevelsPerLevel[40];
    uint8_t * m_lstSpellGainTable[40];
    CNWClass_Skill * m_lstSkillTable;
    uint16_t m_nNumSkills;
    CNWClass_Feat * m_lstFeatTable;
    uint16_t m_nNumFeats;
    uint8_t m_lstBonusFeatsTable[60];
    int8_t m_lstAbilityGainTable[60][6];
    int8_t m_lstNaturalACGainTable[60];
    uint8_t m_nPrimaryAbility;
    uint8_t m_pnRecommendedAbilities[6];
    uint8_t m_nClassRestrictions;
    uint8_t m_nClassRestrictionType;
    BOOL m_nClassRestrictionsInversed;
    uint8_t m_pnEffectiveCRForLevel[40+1];
    BOOL m_bIsPlayerClass;
    BOOL m_bIsSpellCasterClass;
    uint8_t m_nMaxLevel;
    BOOL m_bXPPenalty;
    uint32_t m_nDefaultPackage;
    uint8_t m_nSpellcastingAbility;
    BOOL m_bNeedsToMemorizeSpells;
    BOOL m_bSpellbookRestricted;
    BOOL m_bHasDomains;
    BOOL m_bHasSpecialization;
    BOOL m_bCanLearnFromScrolls;
    BOOL m_bIsArcane;
    BOOL m_bSuffersArcaneSpellFailure;
    CExoString m_sSpellsTableColumn;
    float m_fCasterLevelMultiplier;
    int32_t m_nMinCastingLevel;
    BOOL m_bCanCastSpontaneously;
    uint8_t m_nMinAssociateLevel;
    uint8_t m_nArcSpellUsePerDayLevel;
    uint8_t m_nDivSpellUsePerDayLevel;
    uint8_t m_nEpicLevel;
    BOOL m_bSkipSpellSelection;

    CNWClass();
    ~CNWClass();
    CExoString GetNameText();
    CExoString GetShortNameText();
    CExoString GetNameLowerText();
    CExoString GetNamePluralText();
    CExoString GetDescriptionText();
    uint8_t GetAttackBonus(uint8_t nLevel);
    uint8_t GetBonusFeats(uint8_t nLevel);
    uint8_t GetFortSaveBonus(uint8_t nLevel);
    uint8_t GetRefSaveBonus(uint8_t nLevel);
    uint8_t GetWillSaveBonus(uint8_t nLevel);
    uint8_t GetSpellGain(uint8_t nLevel, uint8_t nSpellLevel);
    uint8_t GetSpellsKnownPerLevel(uint8_t nLevel, uint8_t nSpellLevel, uint8_t nClass, uint16_t nRace, uint8_t nCastingAbilityBase);
    void LoadAttackBonusTable(CExoString sTable);
    void LoadFeatsTable(CExoString sTable, CNWRules * pRules);
    void LoadSavingThrowTable(CExoString sTable);
    void LoadSkillsTable(CExoString sTable);
    void LoadBonusFeatsTable(CExoString sTable);
    void LoadSpellGainTable(CExoString sTable);
    void LoadSpellKnownTable(CExoString sTable);
    void LoadStatGainTable(CExoString sTable);
    BOOL IsSkillUseable(uint16_t nSkill);
    BOOL IsSkillClassSkill(uint16_t nSkill);
    BOOL GetIsAlignmentAllowed(uint8_t nGoodEvilConst, uint8_t nLawChaosConst);
    uint8_t GetLevelFeatGranted(uint16_t nFeat);
    CNWClass_Feat * GetClassFeat(uint16_t nFeat);
    BOOL IsBonusFeat(uint16_t nFeat);
    BOOL IsNormalFeat(uint16_t nFeat);
    BOOL IsGrantedFeat(uint16_t nFeat, uint8_t & nLevelGranted);
    BOOL IsFeatUseable(uint16_t nFeat);
    uint8_t GetLevelGranted(uint16_t nFeat);
    int8_t GetAbilityGainForSingleLevel(int ability, int level);
    int8_t GetAbilityGainForLevel(int ability, int level);
    int8_t GetNaturalACGainForLevel(int level);


#ifdef NWN_CLASS_EXTENSION_CNWClass
    NWN_CLASS_EXTENSION_CNWClass
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWClass)
#endif

