#pragma once
#include "nwn_api.hpp"

#include "ObjectVisualTransformData.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSCreatureAppearanceInfo)
#endif



typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSCreatureAppearanceInfo
{
    OBJECT_ID m_oidLeftHandItem;
    OBJECT_ID m_oidRightHandItem;
    uint8_t m_nRightHandItemVFX;
    uint8_t m_nLeftHandItemVFX;
    OBJECT_ID m_oidChestItem;
    OBJECT_ID m_oidHeadItem;
    uint16_t m_nAppearanceType;
    uint8_t m_nPhenoType;
    uint8_t m_nGender;
    uint8_t m_nSkinColor;
    uint8_t m_nHairColor;
    uint8_t m_nTattooColor1;
    uint8_t m_nTattooColor2;
    uint16_t m_pPartVariation[19];
    uint16_t m_nHeadVariation;
    uint32_t m_nTailVariation;
    uint32_t m_nWingVariation;
    BOOL m_bForceArmorAppearanceUpdate;
    OBJECT_ID m_oidCloakItem;
    ObjectVisualTransformData m_pRightHandItemVisualTransform;
    ObjectVisualTransformData m_pLeftHandItemVisualTransform;

    CNWSCreatureAppearanceInfo();
    void Clear();


#ifdef NWN_CLASS_EXTENSION_CNWSCreatureAppearanceInfo
    NWN_CLASS_EXTENSION_CNWSCreatureAppearanceInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSCreatureAppearanceInfo)
#endif

