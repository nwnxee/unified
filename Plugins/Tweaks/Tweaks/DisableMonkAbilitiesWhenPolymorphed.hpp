#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class DisableMonkAbilitiesWhenPolymorphed
{
public:
    DisableMonkAbilitiesWhenPolymorphed(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CNWSCreature__GetUseMonkAbilities_hook(CNWSCreature*);
    static NWNXLib::Hooking::FunctionHook* pGetUseMonkAbilities_hook;
};

}
