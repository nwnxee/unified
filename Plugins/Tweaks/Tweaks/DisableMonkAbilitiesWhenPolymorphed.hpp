#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class DisableMonkAbilitiesWhenPolymorphed
{
public:
    DisableMonkAbilitiesWhenPolymorphed(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t CNWSCreature__GetUseMonkAbilities_hook(NWNXLib::API::CNWSCreature*);
    static NWNXLib::Hooking::FunctionHook* pGetUseMonkAbilities_hook;
};

}
