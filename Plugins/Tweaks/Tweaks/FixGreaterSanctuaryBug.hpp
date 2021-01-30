#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class FixGreaterSanctuaryBug
{
public:
    FixGreaterSanctuaryBug();

private:
    static void CNWSCreature__RemoveCombatInvisibilityEffects_hook(CNWSCreature *);
};

}
