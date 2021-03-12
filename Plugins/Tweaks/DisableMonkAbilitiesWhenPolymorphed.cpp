#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void DisableMonkAbilitiesWhenPolymorphed() __attribute__((constructor));
void DisableMonkAbilitiesWhenPolymorphed()
{
    if (!Config::Get<bool>("DISABLE_MONK_ABILITIES_WHEN_POLYMORPHED", false))
        return;

    LOG_INFO("Monk abilities (ac, speed, attacks) will be disabled during polymorph");

    static Hooks::Hook s_GetUseMonkAbilitiesHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature19GetUseMonkAbilitiesEv,
        (void*)+[](CNWSCreature *pThis) -> int32_t
        {
            if ( pThis->m_bIsPolymorphed )
                return false;
            return s_GetUseMonkAbilitiesHook->CallOriginal<int32_t>(pThis);
        }, Hooks::Order::Early);
}

}
