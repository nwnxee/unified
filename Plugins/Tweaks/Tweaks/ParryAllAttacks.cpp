#include "Tweaks/ParryAllAttacks.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "API/Constants.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* ParryAllAttacks::pResolveAttackRoll_hook;
ParryAllAttacks::ParryAllAttacks(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::_ZN12CNWSCreature17ResolveAttackRollEP10CNWSObject>
                                    (&CNWSCreature__ResolveAttackRoll_hook);

    pResolveAttackRoll_hook = hooker->FindHookByAddress(Functions::_ZN12CNWSCreature17ResolveAttackRollEP10CNWSObject);
}


void ParryAllAttacks::CNWSCreature__ResolveAttackRoll_hook(CNWSCreature *pThis, CNWSObject *pTarget)
{
    int32_t bRoundPaused = false;
    if (auto *pCreature = pTarget->AsNWSCreature())
    {
        if (pCreature->m_nCombatMode == Constants::CombatMode::Parry &&
            pCreature->m_pcCombatRound->m_nParryActions > 0 &&
            !pCreature->GetRangeWeaponEquipped())
        {
            bRoundPaused = pCreature->m_pcCombatRound->m_bRoundPaused;
            pCreature->m_pcCombatRound->m_bRoundPaused = false;
        }
    }
    pResolveAttackRoll_hook->CallOriginal<void>(pThis, pTarget);
    if (bRoundPaused)
        pTarget->AsNWSCreature()->m_pcCombatRound->m_bRoundPaused = true;
}


}
