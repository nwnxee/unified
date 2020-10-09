#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class FixArmorDexBonusUnderOne
{
public:
    FixArmorDexBonusUnderOne(NWNXLib::Services::HooksProxy* hooker);

private:
    static uint8_t CNWSCreatureStats__GetDEXMod_hook(CNWSCreature *pThis, int32_t bArmorDexCap);
};

}
