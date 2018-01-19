#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CJoiningRestrictions
{
    int32_t bAllowLocal;
    int32_t bAllowServer;
    int32_t bAllowVault;
    int32_t bFixedParties;
    int32_t bAllowFighter;
    int32_t bAllowBarbarian;
    int32_t bAllowRanger;
    int32_t bAllowPaladin;
    int32_t bAllowWizard;
    int32_t bAllowSorcerer;
    int32_t bAllowCleric;
    int32_t bAllowDruid;
    int32_t bAllowRogue;
    int32_t bAllowBard;
    int32_t bAllowMonk;
    int32_t bAllowHuman;
    int32_t bAllowElf;
    int32_t bAllowDwarf;
    int32_t bAllowGnome;
    int32_t bAllowHalfling;
    int32_t bAllowHalfOrc;
    int32_t bAllowHalfElf;
    int32_t nMaxPlayers;
    int32_t nMaxParties;
    int32_t nMaxItemPoints;
    int32_t nMaxStatTotal;
    int32_t nMinLevel;
    int32_t nMaxLevel;
    int32_t bAllowLocalVaultChars;
};

}

}
