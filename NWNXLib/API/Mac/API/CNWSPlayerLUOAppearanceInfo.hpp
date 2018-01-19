#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSPlayerLUOAppearanceInfo
{
    uint32_t m_oidLeftHandItem;
    uint32_t m_oidRightHandItem;
    uint8_t m_nRightHandItemVFX;
    uint8_t m_nLeftHandItemVFX;
    uint32_t m_oidChestItem;
    uint32_t m_oidHeadItem;
    uint16_t m_nAppearanceType;
    uint8_t m_nPhenoType;
    uint8_t m_nGender;
    uint8_t m_nSkinColor;
    uint8_t m_nHairColor;
    uint8_t m_nTattooColor1;
    uint8_t m_nTattooColor2;
    uint8_t m_pPartVariation[19];
    uint8_t m_nHeadVariation;
    uint32_t m_nTailVariation;
    uint32_t m_nWingVariation;
    int32_t m_bForceArmorAppearanceUpdate;
    uint32_t m_oidCloakItem;
};

}

}
