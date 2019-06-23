#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWRules)
#endif

struct CNWDomain;
struct CTwoDimArrays;
struct CNWClass;
struct CNWFeat;
struct CNWBaseItemArray;
struct CNWRace;
struct CNWSkill;
struct CNWSpellArray;


typedef int BOOL;


struct CNWRules
{
    float m_fRangeTypes[5];
    CNWBaseItemArray * m_pBaseItemArray;
    uint32_t m_nExperienceTable[40+1];
    CNWSpellArray * m_pSpellArray;
    CNWFeat * m_lstFeats;
    uint32_t * m_lstMasterFeats;
    uint32_t * m_lstMasterFeatDescriptions;
    CResRef * m_lstMasterFeatIcons;
    uint16_t * m_lstSortedFeatIDs;
    uint16_t m_nNumFeats;
    uint16_t m_nNumSortedFeats;
    char m_nNumMasterFeats;
    uint8_t m_nNumClasses;
    uint8_t m_nNumRaces;
    uint8_t m_nNumSkills;
    uint8_t m_nNumDomains;
    CNWClass * m_lstClasses;
    CNWRace * m_lstRaces;
    CNWSkill * m_lstSkills;
    CNWDomain * m_lstDomains;
    CTwoDimArrays * m_p2DArrays;
    uint8_t m_nDifficultyOptions[1];

    CNWRules();
    virtual ~CNWRules();
    CNWDomain * GetDomain(uint16_t nDomain);
    BOOL IsArcaneClass(uint8_t nClass);
    uint8_t GetFeatExpansionLevel(uint16_t nFeat);
    uint8_t GetSkillExpansionLevel(uint16_t nSkill);
    uint8_t GetClassExpansionLevel(uint8_t nClass);
    uint8_t GetSpellExpansionLevel(uint32_t nSpellId);
    uint8_t GetFamiliarExpansionLevel(uint8_t nFamiliar, BOOL bAnimalCompanion);
    CNWFeat * GetFeat(uint16_t nFeat);
    CExoString GetMasterFeatNameText(char nMasterFeat);
    CExoString GetMasterFeatDescriptionText(char nMasterFeat);
    CResRef GetMasterFeatIcon(char nMasterFeat);
    void SortFeats();
    uint8_t GetMetaMagicLevelCost(uint8_t nMetaType);
    BOOL IsFeatUseable(uint8_t nWISBase, uint16_t nFeat);
    uint16_t RollDice(uint8_t nNumberOfDice, uint8_t nSides);
    int32_t GetDifficultyOption(int32_t nOption, int32_t nDifficultyLevel);
    int32_t GetWeightedDamageAmount(int32_t nDamageDealt, int32_t nMaxPossibleDamage, BOOL bPCvsNPC, BOOL bNPCvsPC, int32_t nDamageWeight);
    int32_t GetDamageIndexFromFlags(uint32_t nDamageFlags);
    void ReloadAll();
    void UnloadAll();
    void LoadFeatInfo();
    void LoadClassInfo();
    void LoadRaceInfo();
    void LoadSkillInfo();
    void LoadDomainInfo();
    void LoadDifficultyInfo();


#ifdef NWN_CLASS_EXTENSION_CNWRules
    NWN_CLASS_EXTENSION_CNWRules
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWRules)
#endif

