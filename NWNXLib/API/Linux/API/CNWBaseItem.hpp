#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

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
    char m_ItemClassResRefChunk[11];
    int32_t m_bPartEnvMap[3];
    CResRef m_DefaultIconResRef;
    CResRef m_DefaultModelResRef;
    int32_t m_bCanRotateIcon;
    int32_t m_bContainer;
    int32_t m_bGenderSpecific;
    uint8_t m_InventorySoundType;
    uint16_t* m_pRequiredFeats;
    uint8_t m_nRequiredFeatCount;
    uint32_t m_nStatsString;
    uint8_t m_nRotateOnGround;
    int32_t m_nWeight;
    uint8_t m_nBaseAC;
    uint8_t m_nACEnchantmentType;
    uint8_t m_nWeaponMaterialType;
    char m_nArmorCheckPenalty;
    char m_nAmmunitionType;
    uint8_t m_nQBBehaviourType;
    uint8_t m_nArcaneSpellFailure;

    // The below are auto generated stubs.
    CNWBaseItem(const CNWBaseItem&) = default;
    CNWBaseItem& operator=(const CNWBaseItem&) = default;

    CNWBaseItem();
    ~CNWBaseItem();
    CResRef GetIconResRef(unsigned char, int16_t, char);
    CResRef GetModelResRef(unsigned char, int16_t, char);
    CExoString GetNameText();
    uint16_t GetRequiredFeat(unsigned char);
    void SetRequiredFeat(unsigned char, uint16_t);
    void SetRequiredFeatCount(unsigned char);
};

void CNWBaseItem__CNWBaseItemCtor(CNWBaseItem* thisPtr);
void CNWBaseItem__CNWBaseItemDtor(CNWBaseItem* thisPtr);
CResRef CNWBaseItem__GetIconResRef(CNWBaseItem* thisPtr, unsigned char, int16_t, char);
CResRef CNWBaseItem__GetModelResRef(CNWBaseItem* thisPtr, unsigned char, int16_t, char);
CExoString CNWBaseItem__GetNameText(CNWBaseItem* thisPtr);
uint16_t CNWBaseItem__GetRequiredFeat(CNWBaseItem* thisPtr, unsigned char);
void CNWBaseItem__SetRequiredFeat(CNWBaseItem* thisPtr, unsigned char, uint16_t);
void CNWBaseItem__SetRequiredFeatCount(CNWBaseItem* thisPtr, unsigned char);

}

}
