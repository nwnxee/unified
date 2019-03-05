
#include "Events/CombatEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/CNWSCombatRound.hpp"
#include "Events.hpp"
#include "Utils.hpp"
#include "ViewPtr.hpp"

static NWNXLib::ViewPtr<Events::CombatEvents> g_combatEvents;

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

CombatEvents::CombatEvents(ViewPtr<HooksProxy> hooker, ViewPtr<EventsProxy> eve)
{
    if (g_combatEvents == nullptr)
        g_combatEvents = this;

#define REGISTER(func) \
    eve->RegisterEvent(#func, std::bind(&CombatEvents::func, this, std::placeholders::_1))

    REGISTER(AddAttackDamage);
    REGISTER(SetAttackDamage);

#undef REGISTER

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
    Events::InitOnFirstSubscribe("NWNX_ON_ATTACK", [hooker]() {
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
    if ( type == Hooks::CallType::AFTER_ORIGINAL )
    {
        // SetCurrentAttack is 1-based, GetAttack is 0-based
        CNWSCombatAttackData* combatAttackData = g_combatEvents->m_combatAttackData = thisPtr->GetAttack(attackNumber - 1);
        Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(thisPtr->m_pBaseCreature->m_oidAttackTarget));
        Events::PushEventData("ATTACK_NUMBER", std::to_string(attackNumber));
        for ( int i = 0; i < 13; i++ )
        {
            int16_t nDamage = combatAttackData->m_nDamage[i];
            Events::PushEventData("ATTACK_DAMAGE_" + std::to_string(i), std::to_string(nDamage));
        }
        Events::PushEventData("ATTACK_RESULT", std::to_string(combatAttackData->m_nAttackResult));
        Events::PushEventData("IS_SNEAK_ATTACK", std::to_string(combatAttackData->m_bSneakAttack || combatAttackData->m_bDeathAttack));
        Events::PushEventData("IS_OFFHAND_ATTACK", std::to_string(combatAttackData->m_nWeaponAttackType == 2));
        Events::SignalEvent("NWNX_ON_ATTACK", thisPtr->m_pBaseCreature->m_idSelf);
        g_combatEvents->m_combatAttackData = nullptr;
    }
}

ArgumentStack CombatEvents::AddAttackDamage(ArgumentStack&& args)
{
    ArgumentStack stack;

    if ( g_combatEvents->m_combatAttackData )
    {
        uint16_t damageType = Services::Events::ExtractArgument<int32_t>(args);
        int32_t damageAmount = Services::Events::ExtractArgument<int32_t>(args);
        g_combatEvents->m_combatAttackData->AddDamage(damageType, damageAmount);
    }

    return stack;
}

ArgumentStack CombatEvents::SetAttackDamage(ArgumentStack&& args)
{
    ArgumentStack stack;

    if ( g_combatEvents->m_combatAttackData )
    {
        uint16_t damageType = Services::Events::ExtractArgument<int32_t>(args);
        int32_t damageAmount = Services::Events::ExtractArgument<int32_t>(args);
        g_combatEvents->m_combatAttackData->SetDamage(damageType, damageAmount);
    }

    return stack;
}

}
