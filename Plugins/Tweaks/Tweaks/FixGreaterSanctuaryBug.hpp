#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class FixGreaterSanctuaryBug
{
public:
    FixGreaterSanctuaryBug(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CNWSCreature__RemoveCombatInvisibilityEffects_hook(CNWSCreature *);
};

}
