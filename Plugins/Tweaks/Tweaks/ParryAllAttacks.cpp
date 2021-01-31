#include "Tweaks/ParryAllAttacks.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"



namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_ResolveAttackRoll_hook;
ParryAllAttacks::ParryAllAttacks()
{
    s_ResolveAttackRoll_hook = Hooks::HookFunction(Functions::_ZN12CNWSCreature17ResolveAttackRollEP10CNWSObject,
                                            (void*)&CNWSCreature__ResolveAttackRoll_hook, Hooks::Order::Late);
}


void ParryAllAttacks::CNWSCreature__ResolveAttackRoll_hook(CNWSCreature *pThis, CNWSObject *pTarget)
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
    s_ResolveAttackRoll_hook->CallOriginal<void>(pThis, pTarget);
    if (bRoundPaused)
        Utils::AsNWSCreature(pTarget)->m_pcCombatRound->m_bRoundPaused = true;
}


}
