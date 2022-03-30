#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWBaseItem)
#endif



typedef int BOOL;
typedef uint32_t STRREF;


struct CNWBaseItem
{
    uint32_t m_nName;
    uint32_t m_nEquipableSlots;
    uint8_t m_nWeaponWield;
    uint8_t m_nWeaponType;
    uint32_t m_nMinRange;
    uint32_t m_nMaxRange;
    uint8_t m_nInvSlotWidth;
    uint8_t m_nInvSlotHeight;
    uint8_t m_nModelType;
    uint8_t m_nStartingCharges;
    uint8_t m_nWeaponRanged;
    uint8_t m_nWeaponSize;
    uint8_t m_nNumDice;
    uint8_t m_nDieToRoll;
    uint8_t m_nCritThreat;
    uint8_t m_nCritMult;
    uint8_t m_nCategory;
    float m_nBaseCost;
    uint16_t m_nStackSize;
    float m_nCostMultiplier;
    uint32_t m_nDescription;
    uint8_t m_nMinProperties;
    uint8_t m_nMaxProperties;
    uint8_t m_nPropColumn;
    uint8_t m_nStorePanel;
    uint8_t m_nStorePanelSort;
    uint8_t m_nPercentageSlashL;
    uint8_t m_nPercentageSlashR;
    uint8_t m_nPercentageSlashS;
    uint8_t m_nILRStackSize;
    float m_fPreferredAttackDist;
    char m_ItemClassResRefChunk[10+1];
    BOOL m_bPartEnvMap[3];
    CResRef m_DefaultIconResRef;
    CResRef m_DefaultModelResRef;
    BOOL m_bCanRotateIcon;
    BOOL m_bContainer;
    BOOL m_bGenderSpecific;
    uint8_t m_InventorySoundType;
    uint16_t * m_pRequiredFeats;
    uint8_t m_nRequiredFeatCount;
    STRREF m_nStatsString;
    uint8_t m_nRotateOnGround;
    int32_t m_nWeight;
    uint8_t m_nBaseAC;
    uint8_t m_nACEnchantmentType;
    uint8_t m_nWeaponMaterialType;
    char m_nArmorCheckPenalty;
    char m_nAmmunitionType;
    uint8_t m_nQBBehaviourType;
    uint8_t m_nArcaneSpellFailure;
    uint16_t m_nWeaponFocusFeat;
    uint16_t m_nEpicWeaponFocusFeat;
    uint16_t m_nWeaponSpecializationFeat;
    uint16_t m_nEpicWeaponSpecializationFeat;
    uint16_t m_nWeaponImprovedCriticalFeat;
    uint16_t m_nEpicWeaponOverwhelmingCriticalFeat;
    uint16_t m_nEpicWeaponDevastatingCriticalFeat;
    uint16_t m_nWeaponOfChoiceFeat;
    BOOL m_bIsMonkWeapon;
    uint8_t m_nWeaponFinesseMinimumCreatureSize;

    CNWBaseItem();
    ~CNWBaseItem();
    CExoString GetNameText();
    CResRef GetModelResRef(uint8_t nPart, int16_t nModelNumber, char nGender = 'm');
    CResRef GetIconResRef(uint8_t nPart, int16_t nModelNumber, char nGender = 'm');
    uint16_t GetRequiredFeat(uint8_t nReqFeatIndex);
    void SetRequiredFeat(uint8_t nReqFeatIndex, uint16_t nFeat);
    void SetRequiredFeatCount(uint8_t nReqFeatCount);


#ifdef NWN_CLASS_EXTENSION_CNWBaseItem
    NWN_CLASS_EXTENSION_CNWBaseItem
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWBaseItem)
#endif

