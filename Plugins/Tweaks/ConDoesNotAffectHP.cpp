#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void ConDoesNotAffectHP() __attribute__((constructor));
void ConDoesNotAffectHP()
{
    if (!Config::Get<bool>("CON_DOES_NOT_AFFECT_HP", false)) return;

    LOG_INFO("Constitution does not affect creature HP.");

    static Hooks::Hook s_CNWSCreatureGetMaxHitPointsHook = Hooks::HookFunction(
        Functions::_ZN12CNWSCreature15GetMaxHitPointsEi,
        +[](CNWSCreature *pThis, BOOL bIncludeToughness) -> int16_t
        {
            int16_t maxHP = s_CNWSCreatureGetMaxHitPointsHook->CallOriginal<int16_t>(pThis, bIncludeToughness);

            return maxHP - pThis->m_pStats->GetLevel() * pThis->m_pStats->m_nConstitutionModifier;
        },
        Hooks::Order::Late);
}

}
