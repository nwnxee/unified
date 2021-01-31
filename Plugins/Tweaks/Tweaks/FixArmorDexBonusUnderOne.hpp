#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class FixArmorDexBonusUnderOne
{
public:
    FixArmorDexBonusUnderOne();

private:
    static uint8_t CNWSCreatureStats__GetDEXMod_hook(CNWSCreatureStats *pThis, int32_t bArmorDexCap);
};

}
