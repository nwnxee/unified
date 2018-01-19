#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CGameEffect;
struct CNWSItem;

struct CNWSCreRestorePolymorphData
{
    int32_t nCurrentHitPoints;
    int32_t nTemporaryHitPoints;
    CGameEffect* effect;
    CNWSItem* pItemCreatureHide;
    CNWSItem* pItemCreatureWeapon;
    int32_t bTemporaryEffect;
    uint32_t nExpiryDate;
    uint32_t nExpiryTime;
};

}

}
