#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWClass_Feat;
struct CNWClass__CNWClass_Skill;
struct CNWRules;

struct CNWClass
{
    uint32_t m_nName;
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
    uint8_t** m_lstSpellKnownTable;
    uint8_t m_lstSpellLevelsPerLevel[40];
    uint8_t* m_lstSpellGainTable[40];
    CNWClass__CNWClass_Skill* m_lstSkillTable;
    uint16_t m_nNumSkills;
    CNWClass_Feat* m_lstFeatTable;
    uint16_t m_nNumFeats;
    uint8_t m_lstBonusFeatsTable[60];
    uint8_t m_nPrimaryAbility;
    uint8_t m_pnRecommendedAbilities[6];
    uint8_t m_nClassRestrictions;
    uint8_t m_nClassRestrictionType;
    int32_t m_nClassRestrictionsInversed;
    uint8_t m_pnEffectiveCRForLevel[41];
    int32_t m_bIsPlayerClass;
    int32_t m_bIsSpellCasterClass;
    uint8_t m_nMaxLevel;
    int32_t m_bXPPenalty;
    uint32_t m_nDefaultPackage;
    uint8_t m_nArcSpellUsePerDayLevel;
    uint8_t m_nDivSpellUsePerDayLevel;
    uint8_t m_nEpicLevel;

    // The below are auto generated stubs.
    CNWClass(const CNWClass&) = default;
    CNWClass& operator=(const CNWClass&) = default;

    CNWClass();
    ~CNWClass();
    unsigned char GetAttackBonus(unsigned char);
    unsigned char GetBonusFeats(unsigned char);
    CNWClass_Feat* GetClassFeat(uint16_t);
    CExoString GetDescriptionText();
    unsigned char GetFortSaveBonus(unsigned char);
    int32_t GetIsAlignmentAllowed(unsigned char, unsigned char);
    unsigned char GetLevelFeatGranted(uint16_t);
    unsigned char GetLevelGranted(uint16_t);
    CExoString GetNameLowerText();
    CExoString GetNamePluralText();
    CExoString GetNameText();
    unsigned char GetRefSaveBonus(unsigned char);
    unsigned char GetSpellGain(unsigned char, unsigned char);
    unsigned char GetSpellsKnownPerLevel(unsigned char, unsigned char, unsigned char, uint16_t, unsigned char);
    unsigned char GetWillSaveBonus(unsigned char);
    int32_t IsBonusFeat(uint16_t);
    int32_t IsFeatUseable(uint16_t);
    int32_t IsGrantedFeat(uint16_t, unsigned char&);
    int32_t IsNormalFeat(uint16_t);
    int32_t IsSkillClassSkill(uint16_t);
    int32_t IsSkillUseable(uint16_t);
    void LoadAttackBonusTable(CExoString);
    void LoadBonusFeatsTable(CExoString);
    void LoadFeatsTable(CExoString, CNWRules*);
    void LoadSavingThrowTable(CExoString);
    void LoadSkillsTable(CExoString);
    void LoadSpellGainTable(CExoString);
    void LoadSpellKnownTable(CExoString);
};

void CNWClass__CNWClassCtor__0(CNWClass* thisPtr);
void CNWClass__CNWClassDtor__0(CNWClass* thisPtr);
unsigned char CNWClass__GetAttackBonus(CNWClass* thisPtr, unsigned char);
unsigned char CNWClass__GetBonusFeats(CNWClass* thisPtr, unsigned char);
CNWClass_Feat* CNWClass__GetClassFeat(CNWClass* thisPtr, uint16_t);
CExoString CNWClass__GetDescriptionText(CNWClass* thisPtr);
unsigned char CNWClass__GetFortSaveBonus(CNWClass* thisPtr, unsigned char);
int32_t CNWClass__GetIsAlignmentAllowed(CNWClass* thisPtr, unsigned char, unsigned char);
unsigned char CNWClass__GetLevelFeatGranted(CNWClass* thisPtr, uint16_t);
unsigned char CNWClass__GetLevelGranted(CNWClass* thisPtr, uint16_t);
CExoString CNWClass__GetNameLowerText(CNWClass* thisPtr);
CExoString CNWClass__GetNamePluralText(CNWClass* thisPtr);
CExoString CNWClass__GetNameText(CNWClass* thisPtr);
unsigned char CNWClass__GetRefSaveBonus(CNWClass* thisPtr, unsigned char);
unsigned char CNWClass__GetSpellGain(CNWClass* thisPtr, unsigned char, unsigned char);
unsigned char CNWClass__GetSpellsKnownPerLevel(CNWClass* thisPtr, unsigned char, unsigned char, unsigned char, uint16_t, unsigned char);
unsigned char CNWClass__GetWillSaveBonus(CNWClass* thisPtr, unsigned char);
int32_t CNWClass__IsBonusFeat(CNWClass* thisPtr, uint16_t);
int32_t CNWClass__IsFeatUseable(CNWClass* thisPtr, uint16_t);
int32_t CNWClass__IsGrantedFeat(CNWClass* thisPtr, uint16_t, unsigned char&);
int32_t CNWClass__IsNormalFeat(CNWClass* thisPtr, uint16_t);
int32_t CNWClass__IsSkillClassSkill(CNWClass* thisPtr, uint16_t);
int32_t CNWClass__IsSkillUseable(CNWClass* thisPtr, uint16_t);
void CNWClass__LoadAttackBonusTable(CNWClass* thisPtr, CExoString);
void CNWClass__LoadBonusFeatsTable(CNWClass* thisPtr, CExoString);
void CNWClass__LoadFeatsTable(CNWClass* thisPtr, CExoString, CNWRules*);
void CNWClass__LoadSavingThrowTable(CNWClass* thisPtr, CExoString);
void CNWClass__LoadSkillsTable(CNWClass* thisPtr, CExoString);
void CNWClass__LoadSpellGainTable(CNWClass* thisPtr, CExoString);
void CNWClass__LoadSpellKnownTable(CNWClass* thisPtr, CExoString);

}

}
