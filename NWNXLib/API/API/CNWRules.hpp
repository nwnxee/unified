#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResRef.hpp"
#include "CachedRulesetEntry.hpp"
#include <string>
#include <unordered_map>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWRules)
#endif

struct CNWBaseItemArray;
struct CNWClass;
struct CNWDomain;
struct CNWFeat;
struct CNWRace;
struct CNWSkill;
struct CNWSpellArray;
struct CTwoDimArrays;


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
    uint8_t m_nDifficultyOptions[5][7];
    std::unordered_map<uint64_t, CachedRulesetEntry> m_ruleset_2da_cache;

    CNWRules();
    virtual ~CNWRules();
    CNWDomain * GetDomain(uint16_t nDomain);
    BOOL IsArcaneClass(uint8_t nClass);
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
    uint32_t GetHighestDamageTypeFlag();
    CExoString GetRulesetStringEntry(uint64_t hashedLabel, const char* whenMissing);
    int32_t GetRulesetIntEntry(uint64_t hashedLabel, int32_t whenMissing);
    float GetRulesetFloatEntry(uint64_t hashedLabel, float whenMissing);
    void LoadFeatInfo();
    void LoadClassInfo();
    void LoadRaceInfo();
    void LoadSkillInfo();
    void LoadDomainInfo();
    void InitLegacyClassDefaults(uint8_t nClass);
    void InitLegacyRaceDefaults(uint8_t nRace);
    void LoadDifficultyInfo();
    void LoadEncodingInfo();
    void LoadRulesetInfo();


    #define CRULES_HASHEDSTR(lbl) CNWRules::fnv1a(lbl, sizeof(lbl)-1)
    inline static constexpr uint64_t fnv1a(const char *s, size_t l, uint64_t partial = 14695981039346656037ull) noexcept
    {
        return l == 0 ? partial : fnv1a(s+1, l-1, (partial^s[0])*1099511628211ull);
    }

#ifdef NWN_CLASS_EXTENSION_CNWRules
    NWN_CLASS_EXTENSION_CNWRules
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWRules)
#endif

