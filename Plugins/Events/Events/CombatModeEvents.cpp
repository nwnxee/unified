#include "Events/CombatModeEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;

static Hooking::FunctionHook* m_SetCombatModeHook = nullptr;

CombatModeEvents::CombatModeEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<API::Functions::CNWSCreature__SetCombatMode, void, API::CNWSCreature*, uint8_t, int32_t>(&SetCombatModeHook);

    m_SetCombatModeHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__SetCombatMode);
}

void CombatModeEvents::SetCombatModeHook(API::CNWSCreature* thisPtr, uint8_t nMode, int32_t bForceMode)
{
    if (thisPtr->m_bPlayerCharacter && nMode != thisPtr->m_nCombatMode)
    {        
        Events::PushEventData("COMBAT_MODE_ID", std::to_string(nMode));

        if (Events::SignalEvent("NWNX_ON_COMBAT_MODE_BEFORE", thisPtr->m_idSelf))
        {
            m_SetCombatModeHook->CallOriginal<void>(thisPtr, nMode, bForceMode);
        }

        Events::PushEventData("COMBAT_MODE_ID", std::to_string(nMode));
        
        Events::SignalEvent("NWNX_ON_COMBAT_MODE_AFTER", thisPtr->m_idSelf);
    }
}

}
