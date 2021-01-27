#include "Tweaks/DisableMonkAbilitiesWhenPolymorphed.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"

#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooking::FunctionHook *s_GetUseMonkAbilities_hook;

DisableMonkAbilitiesWhenPolymorphed::DisableMonkAbilitiesWhenPolymorphed(Services::HooksProxy* hooker)
{
    s_GetUseMonkAbilities_hook = hooker->Hook(Functions::_ZN12CNWSCreature19GetUseMonkAbilitiesEv,
                                              (void*)&CNWSCreature__GetUseMonkAbilities_hook, Hooking::Order::Early);
}

int32_t DisableMonkAbilitiesWhenPolymorphed::CNWSCreature__GetUseMonkAbilities_hook(CNWSCreature *pThis)
{
    if ( pThis->m_bIsPolymorphed )
        return false;
    return s_GetUseMonkAbilities_hook->CallOriginal<int32_t>(pThis);
}

}
