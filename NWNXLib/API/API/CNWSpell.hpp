#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSpell)
#endif



typedef int BOOL;


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
    BOOL m_bProjectileSpawn;
    CResRef m_resrefProjectile;
    uint32_t m_nProjectileType;
    uint8_t m_nProjectileSpawnPoint;
    CResRef m_resrefProjectileSound;
    uint8_t m_nProjectileOrientationType;
    uint8_t m_nImmunityType;
    BOOL m_bImmunityItem;
    int32_t m_nTalentCategory;
    int32_t m_nTalentMaxCR;
    uint32_t * m_pSubRadialSpell;
    uint8_t m_nSubRadialSpellCount;
    BOOL m_bUseConcentration;
    uint32_t m_nMasterSpell;
    uint32_t m_nCounterSpell1;
    uint32_t m_nCounterSpell2;
    uint8_t m_nUserType;
    BOOL m_bSpontaneouslyCast;
    uint8_t m_nAllowedMetamagic;
    uint32_t m_nAltMessage;
    BOOL m_bHostile;
    int32_t m_nFeatId;
    BOOL m_bHasProjectile;
    uint32_t m_nSpellId;
    uint32_t m_nTargetShape;
    float m_nTargetSizeX;
    float m_nTargetSizeY;
    uint32_t m_nTargetFlags;

    CNWSpell();
    ~CNWSpell();
    CExoString GetSpellNameText();
    BOOL GetSpellHasVerbalComponent();
    BOOL GetSpellHasSomaticComponent();
    uint8_t GetSpellLevel(uint8_t nClass);
    uint32_t GetSubRadialSpell(uint8_t nIndex);
    void SetSubRadialSpell(uint8_t nIndex, uint32_t nSpellID);
    void SetSubRadialSpellCount(uint8_t nCount);


#ifdef NWN_CLASS_EXTENSION_CNWSpell
    NWN_CLASS_EXTENSION_CNWSpell
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSpell)
#endif

