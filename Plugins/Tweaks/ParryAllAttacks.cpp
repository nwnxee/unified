#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSCombatRound.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void ParryAllAttacks() __attribute__((constructor));
void ParryAllAttacks()
{
    if (!Config::Get<bool>("PARRY_ALL_ATTACKS", false))
        return;

    LOG_INFO("Parry will no longer be limited to one attack per flurry");

    static Hooks::Hook s_ResolveAttackRollHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature17ResolveAttackRollEP10CNWSObject,
        (void*)+[](CNWSCreature *pThis, CNWSObject *pTarget) -> void
        {
            int32_t bRoundPaused = false;
            if (auto *pCreature = Utils::AsNWSCreature(pTarget))
            {
                if (pCreature->m_nCombatMode == Constants::CombatMode::Parry &&
                    pCreature->m_pcCombatRound->m_nParryActions > 0 &&
                    !pCreature->GetRangeWeaponEquipped())
                {
                    bRoundPaused = pCreature->m_pcCombatRound->m_bRoundPaused;
                    pCreature->m_pcCombatRound->m_bRoundPaused = false;
                }
            }
            s_ResolveAttackRollHook->CallOriginal<void>(pThis, pTarget);
            if (bRoundPaused)
                Utils::AsNWSCreature(pTarget)->m_pcCombatRound->m_bRoundPaused = true;
        }, Hooks::Order::Late);
}

}
