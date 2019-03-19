#include "Tweaks/DisablePolymorphedMonks.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"

#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* DisablePolymorphedMonks::pGetUseMonkAbilities_hook;

DisablePolymorphedMonks::DisablePolymorphedMonks(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWSCreature__GetUseMonkAbilities>(&CNWSCreature__GetUseMonkAbilities_hook);
    pGetUseMonkAbilities_hook = hooker->FindHookByAddress(Functions::CNWSCreature__GetUseMonkAbilities);
}

int32_t DisablePolymorphedMonks::CNWSCreature__GetUseMonkAbilities_hook(CNWSCreature *pThis)
{
    if ( pThis->m_bIsPolymorphed )
        return false;
    return pGetUseMonkAbilities_hook->CallOriginal<int32_t>(pThis);
}

}
