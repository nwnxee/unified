#include "Experimentals/RemoveACABModifiersFromExpertise.hpp"

#include "Services/Hooks/Hooks.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooking::FunctionHook* m_GetArmorClassVersusHook;
static NWNXLib::Hooking::FunctionHook* m_GetAttackModifierVersusHook;

RemoveACABModifiersFromExpertise::RemoveACABModifiersFromExpertise(ViewPtr<Services::HooksProxy> hooker)
{
    /* TODO-64: Remove, this is done in base game ruleset.2da now
    hooker->RequestExclusiveHook<Functions::CNWSCreatureStats__GetArmorClassVersus>(
            +[](CNWSCreatureStats *pThis, CNWSCreature *pAttacker, int32_t bVsTouchAttack) -> int16_t
            {
                // Let the server calculate the full value..
                int16_t ret = m_GetArmorClassVersusHook->CallOriginal<int16_t>(pThis, pAttacker, bVsTouchAttack);
                // Then undo expertise if needed
                if (pThis->m_pBaseCreature->m_nCombatMode == Constants::CombatMode::Expertise)
                    ret -= 5;
                else if (pThis->m_pBaseCreature->m_nCombatMode == Constants::CombatMode::ImprovedExpertise)
                    ret -= 10;

                return ret;
            });
    m_GetArmorClassVersusHook = hooker->FindHookByAddress(Functions::CNWSCreatureStats__GetArmorClassVersus);

    hooker->RequestExclusiveHook<Functions::CNWSCreatureStats__GetAttackModifierVersus>(
            +[](CNWSCreatureStats *pThis, CNWSCreature *pTargetCreature) -> int32_t
            {
                // Let the server calculate the full value..
                int32_t ret = m_GetAttackModifierVersusHook->CallOriginal<int32_t>(pThis, pTargetCreature);
                // Then undo expertise if needed
                if (pThis->m_pBaseCreature->m_nCombatMode == Constants::CombatMode::Expertise)
                    ret += 5;
                else if (pThis->m_pBaseCreature->m_nCombatMode == Constants::CombatMode::ImprovedExpertise)
                    ret += 10;

                return ret;
            });
    m_GetAttackModifierVersusHook = hooker->FindHookByAddress(Functions::CNWSCreatureStats__GetAttackModifierVersus);
    */
}

}
