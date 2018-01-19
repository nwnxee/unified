#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct CNWSpell
{
    CExoString m_sLabel;
    int32_t m_strrefName;
    uint32_t m_strrefDesc;
    CResRef m_resrefIcon;
    uint8_t m_nSchool;
    CExoString m_sRange;
    CExoString m_sComponent;
    uint16_t m_nTargetType;
    CExoString m_sImpactScript;
    uint8_t m_nBardLevel;
    uint8_t m_nClericLevel;
    uint8_t m_nDruidLevel;
    uint8_t m_nPaladinLevel;
    uint8_t m_nRangerLevel;
    uint8_t m_nSorcererLevel;
    uint8_t m_nWizardLevel;
    uint8_t m_nInnateLevel;
    uint32_t m_nConjureTime;
    uint16_t m_nConjureAnimation;
    CResRef m_resrefConjureHeadVisual;
    CResRef m_resrefConjureHandVisual;
    CResRef m_resrefConjureGroundVisual;
    CResRef m_resrefConjureSoundMale;
    CResRef m_resrefConjureSoundFemale;
    CResRef m_resrefConjureSoundVFX;
    uint16_t m_nCastAnimation;
    uint32_t m_nCastTime;
    CResRef m_resrefCastHeadVisual;
    CResRef m_resrefCastHandVisual;
    CResRef m_resrefCastGroundVisual;
    CResRef m_resrefCastSound;
    int32_t m_bProjectileSpawn;
    CResRef m_resrefProjectile;
    uint32_t m_nProjectileType;
    uint8_t m_nProjectileSpawnPoint;
    CResRef m_resrefProjectileSound;
    uint8_t m_nProjectileOrientationType;
    uint8_t m_nImmunityType;
    int32_t m_bImmunityItem;
    int32_t m_nTalentCategory;
    int32_t m_nTalentMaxCR;
    uint32_t* m_pSubRadialSpell;
    uint8_t m_nSubRadialSpellCount;
    int32_t m_bUseConcentration;
    uint32_t m_nMasterSpell;
    uint32_t m_nCounterSpell1;
    uint32_t m_nCounterSpell2;
    uint8_t m_nUserType;
    int32_t m_bSpontaneouslyCast;
    uint8_t m_nAllowedMetamagic;
    uint32_t m_nAltMessage;
    int32_t m_bHostile;
    int32_t m_nFeatId;
    int32_t m_bHasProjectile;

    // The below are auto generated stubs.
    CNWSpell& operator=(const CNWSpell&) = default;

    CNWSpell();
    CNWSpell(const CNWSpell&);
    ~CNWSpell();
    int32_t GetSpellHasSomaticComponent();
    int32_t GetSpellHasVerbalComponent();
    unsigned char GetSpellLevel(unsigned char);
    CExoString GetSpellNameText();
    uint32_t GetSubRadialSpell(unsigned char);
    void SetSubRadialSpell(unsigned char, uint32_t);
    void SetSubRadialSpellCount(unsigned char);
};

void CNWSpell__CNWSpellCtor__0(CNWSpell* thisPtr);
void CNWSpell__CNWSpellCtor__2(CNWSpell* thisPtr, const CNWSpell&);
void CNWSpell__CNWSpellDtor__0(CNWSpell* thisPtr);
int32_t CNWSpell__GetSpellHasSomaticComponent(CNWSpell* thisPtr);
int32_t CNWSpell__GetSpellHasVerbalComponent(CNWSpell* thisPtr);
unsigned char CNWSpell__GetSpellLevel(CNWSpell* thisPtr, unsigned char);
CExoString CNWSpell__GetSpellNameText(CNWSpell* thisPtr);
uint32_t CNWSpell__GetSubRadialSpell(CNWSpell* thisPtr, unsigned char);
void CNWSpell__SetSubRadialSpell(CNWSpell* thisPtr, unsigned char, uint32_t);
void CNWSpell__SetSubRadialSpellCount(CNWSpell* thisPtr, unsigned char);

}

}
