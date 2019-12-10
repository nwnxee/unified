
#include "Events/CombatEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/CNWSCombatRound.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

NWNXLib::Hooking::FunctionHook* CombatEvents::m_hook;

CombatEvents::CombatEvents(HooksProxy* hooker)
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

void CombatEvents::StartCombatRoundHook(bool before, CNWSCombatRound* thisPtr, uint32_t oidTarget)
{
    Events::PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
    Events::SignalEvent(before ? "NWNX_ON_START_COMBAT_ROUND_BEFORE" : "NWNX_ON_START_COMBAT_ROUND_AFTER" , thisPtr->m_pBaseCreature->m_idSelf);
}

}
