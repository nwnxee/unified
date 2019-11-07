#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class FixGreaterSanctuaryBug
{
public:
    FixGreaterSanctuaryBug(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void CNWSCreature__RemoveCombatInvisibilityEffects_hook(CNWSCreature *);
};

}
