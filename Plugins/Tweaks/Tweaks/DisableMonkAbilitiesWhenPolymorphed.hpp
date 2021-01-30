#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class DisableMonkAbilitiesWhenPolymorphed
{
public:
    DisableMonkAbilitiesWhenPolymorphed();

private:
    static int32_t CNWSCreature__GetUseMonkAbilities_hook(CNWSCreature*);
};

}
