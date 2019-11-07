
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

NWNXLib::ViewPtr<NWNXLib::Hooking::FunctionHook> CombatEvents::m_hook;

CombatEvents::CombatEvents(ViewPtr<HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_START_COMBAT_ROUND_.*", [hooker]() {
        hooker->RequestSharedHook<
            API::Functions::_ZN15CNWSCombatRound16StartCombatRoundEj,
            int32_t,
            CNWSCombatRound*,
            uint32_t>
            (
                &StartCombatRoundHook
            );
    });
}

void CombatEvents::StartCombatRoundHook(
    Hooks::CallType type,
    CNWSCombatRound* thisPtr,
    uint32_t oidTarget)
{
    const bool before = type == Hooks::CallType::BEFORE_ORIGINAL;


    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
    Events::SignalEvent(before ? "NWNX_ON_START_COMBAT_ROUND_BEFORE" : "NWNX_ON_START_COMBAT_ROUND_AFTER" , thisPtr->m_pBaseCreature->m_idSelf);
}

}
