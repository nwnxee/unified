#include "Tweaks/DisableMonkAbilitiesWhenPolymorphed.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"

#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* DisableMonkAbilitiesWhenPolymorphed::pGetUseMonkAbilities_hook;

DisableMonkAbilitiesWhenPolymorphed::DisableMonkAbilitiesWhenPolymorphed(Services::HooksProxy* hooker)
{
    pGetUseMonkAbilities_hook = hooker->RequestExclusiveHook
        <Functions::_ZN12CNWSCreature19GetUseMonkAbilitiesEv>(&CNWSCreature__GetUseMonkAbilities_hook);
}

int32_t DisableMonkAbilitiesWhenPolymorphed::CNWSCreature__GetUseMonkAbilities_hook(CNWSCreature *pThis)
{
    if ( pThis->m_bIsPolymorphed )
        return false;
    return pGetUseMonkAbilities_hook->CallOriginal<int32_t>(pThis);
}

}
