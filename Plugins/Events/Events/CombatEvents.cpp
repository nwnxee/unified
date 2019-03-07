
#include "Events/CombatEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/CNWSCombatRound.hpp"
#include "Events.hpp"
#include "Utils.hpp"
#include "ViewPtr.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

CombatEvents::CombatEvents(ViewPtr<HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_START_COMBAT_ROUND_.*", [hooker]() {
        hooker->RequestSharedHook<
            API::Functions::CNWSCombatRound__StartCombatRound,
            int32_t,
            API::CNWSCombatRound*,
            uint32_t>
            (
                &StartCombatRoundHook
            );
    });
    Events::InitOnFirstSubscribe("NWNX_ON_ATTACK_.*", [hooker]() {
        hooker->RequestSharedHook<
            API::Functions::CNWSCombatRound__SetCurrentAttack,
            int32_t,
            API::CNWSCombatRound*,
            uint8_t>
            (
                &AttackHook
            );
    });
}

void CombatEvents::StartCombatRoundHook(
    Hooks::CallType type,
    API::CNWSCombatRound* thisPtr,
    uint32_t oidTarget)
{
    const bool before = type == Hooks::CallType::BEFORE_ORIGINAL;


    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
    Events::SignalEvent(before ? "NWNX_ON_START_COMBAT_ROUND_BEFORE" : "NWNX_ON_START_COMBAT_ROUND_AFTER" , thisPtr->m_pBaseCreature->m_idSelf);
}

void CombatEvents::AttackHook(
    Hooks::CallType type,
    API::CNWSCombatRound* thisPtr,
    uint8_t attackNumber)
{
    const bool before = type == Hooks::CallType::BEFORE_ORIGINAL;
    std::string sEventResult;

    // SetCurrentAttack is 1-based, GetAttack is 0-based
    CNWSCombatAttackData* combatAttackData = thisPtr->GetAttack(attackNumber - 1);
    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(thisPtr->m_pBaseCreature->m_oidAttackTarget));
    Events::PushEventData("ATTACK_NUMBER", std::to_string(attackNumber));
    Events::PushEventData("ATTACK_BASE_DAMAGE", std::to_string(combatAttackData->m_nDamage[12]));
    Events::PushEventData("ATTACK_RESULT", std::to_string(combatAttackData->m_nAttackResult));
    Events::PushEventData("IS_SNEAK_ATTACK", std::to_string(combatAttackData->m_bSneakAttack || combatAttackData->m_bDeathAttack));
    Events::PushEventData("IS_OFFHAND_ATTACK", std::to_string(combatAttackData->m_nWeaponAttackType == 2));

    Events::SignalEvent(before ? "NWNX_ON_ATTACK_BEFORE" : "NWNX_ON_ATTACK_AFTER", thisPtr->m_pBaseCreature->m_idSelf, &sEventResult);
    if ( !sEventResult.empty() )
    {
        int32_t result = stoi(sEventResult);
        combatAttackData->SetBaseDamage(result);
    }
}

}
