#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWBaseItemArray;
struct CNWClass;
struct CNWDomain;
struct CNWFeat;
struct CNWRace;
struct CNWSkill;
struct CNWSpellArray;
struct CTwoDimArrays;

struct CNWRules
{
    void** m_vtable;
    float m_fRangeTypes[5];
    CNWBaseItemArray* m_pBaseItemArray;
    uint32_t m_nExperienceTable[41];
    CNWSpellArray* m_pSpellArray;
    CNWFeat* m_lstFeats;
    uint32_t* m_lstMasterFeats;
    uint32_t* m_lstMasterFeatDescriptions;
    CResRef* m_lstMasterFeatIcons;
    uint16_t* m_lstSortedFeatIDs;
    uint16_t m_nNumFeats;
    uint16_t m_nNumSortedFeats;
    char m_nNumMasterFeats;
    uint8_t m_nNumClasses;
    uint8_t m_nNumRaces;
    uint8_t m_nNumSkills;
    uint8_t m_nNumDomains;
    CNWClass* m_lstClasses;
    CNWRace* m_lstRaces;
    CNWSkill* m_lstSkills;
    CNWDomain* m_lstDomains;
    CTwoDimArrays* m_p2DArrays;
    uint8_t m_nDifficultyOptions[5][7];

    // The below are auto generated stubs.
    CNWRules(const CNWRules&) = default;
    CNWRules& operator=(const CNWRules&) = default;

    CNWRules();
    ~CNWRules();
    static int32_t CompareFeatName(const void*, const void*);
    unsigned char GetClassExpansionLevel(unsigned char);
    int32_t GetDamageIndexFromFlags(uint32_t);
    int32_t GetDifficultyOption(int32_t, int32_t);
    CNWDomain* GetDomain(uint16_t);
    unsigned char GetFamiliarExpansionLevel(unsigned char, int32_t);
    CNWFeat* GetFeat(uint16_t);
    unsigned char GetFeatExpansionLevel(uint16_t);
    CExoString GetMasterFeatDescriptionText(char);
    CResRef GetMasterFeatIcon(char);
    CExoString GetMasterFeatNameText(char);
    unsigned char GetMetaMagicLevelCost(unsigned char);
    unsigned char GetSkillExpansionLevel(uint16_t);
    unsigned char GetSpellExpansionLevel(uint32_t);
    int32_t GetWeightedDamageAmount(int32_t, int32_t, int32_t, int32_t, int32_t);
    int32_t IsArcaneClass(unsigned char);
    int32_t IsFeatUseable(unsigned char, uint16_t);
    void LoadClassInfo();
    void LoadDifficultyInfo();
    void LoadDomainInfo();
    void LoadFeatInfo();
    void LoadRaceInfo();
    void LoadSkillInfo();
    void ReloadAll();
    uint16_t RollDice(unsigned char, unsigned char);
    void SortFeats();
    void UnloadAll();
};

void CNWRules__CNWRulesCtor__0(CNWRules* thisPtr);
void CNWRules__CNWRulesDtor__0(CNWRules* thisPtr);
int32_t CNWRules__CompareFeatName(const void*, const void*);
unsigned char CNWRules__GetClassExpansionLevel(CNWRules* thisPtr, unsigned char);
int32_t CNWRules__GetDamageIndexFromFlags(CNWRules* thisPtr, uint32_t);
int32_t CNWRules__GetDifficultyOption(CNWRules* thisPtr, int32_t, int32_t);
CNWDomain* CNWRules__GetDomain(CNWRules* thisPtr, uint16_t);
unsigned char CNWRules__GetFamiliarExpansionLevel(CNWRules* thisPtr, unsigned char, int32_t);
CNWFeat* CNWRules__GetFeat(CNWRules* thisPtr, uint16_t);
unsigned char CNWRules__GetFeatExpansionLevel(CNWRules* thisPtr, uint16_t);
CExoString CNWRules__GetMasterFeatDescriptionText(CNWRules* thisPtr, char);
CResRef CNWRules__GetMasterFeatIcon(CNWRules* thisPtr, char);
CExoString CNWRules__GetMasterFeatNameText(CNWRules* thisPtr, char);
unsigned char CNWRules__GetMetaMagicLevelCost(CNWRules* thisPtr, unsigned char);
unsigned char CNWRules__GetSkillExpansionLevel(CNWRules* thisPtr, uint16_t);
unsigned char CNWRules__GetSpellExpansionLevel(CNWRules* thisPtr, uint32_t);
int32_t CNWRules__GetWeightedDamageAmount(CNWRules* thisPtr, int32_t, int32_t, int32_t, int32_t, int32_t);
int32_t CNWRules__IsArcaneClass(CNWRules* thisPtr, unsigned char);
int32_t CNWRules__IsFeatUseable(CNWRules* thisPtr, unsigned char, uint16_t);
void CNWRules__LoadClassInfo(CNWRules* thisPtr);
void CNWRules__LoadDifficultyInfo(CNWRules* thisPtr);
void CNWRules__LoadDomainInfo(CNWRules* thisPtr);
void CNWRules__LoadFeatInfo(CNWRules* thisPtr);
void CNWRules__LoadRaceInfo(CNWRules* thisPtr);
void CNWRules__LoadSkillInfo(CNWRules* thisPtr);
void CNWRules__ReloadAll(CNWRules* thisPtr);
uint16_t CNWRules__RollDice(CNWRules* thisPtr, unsigned char, unsigned char);
void CNWRules__SortFeats(CNWRules* thisPtr);
void CNWRules__UnloadAll(CNWRules* thisPtr);

}

}
