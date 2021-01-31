#include "Tweaks/DisableMonkAbilitiesWhenPolymorphed.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_GetUseMonkAbilities_hook;

DisableMonkAbilitiesWhenPolymorphed::DisableMonkAbilitiesWhenPolymorphed()
{
    s_GetUseMonkAbilities_hook = Hooks::HookFunction(Functions::_ZN12CNWSCreature19GetUseMonkAbilitiesEv,
                                              (void*)&CNWSCreature__GetUseMonkAbilities_hook, Hooks::Order::Early);
}

int32_t DisableMonkAbilitiesWhenPolymorphed::CNWSCreature__GetUseMonkAbilities_hook(CNWSCreature *pThis)
{
    if ( pThis->m_bIsPolymorphed )
        return false;
    return s_GetUseMonkAbilities_hook->CallOriginal<int32_t>(pThis);
}

}
