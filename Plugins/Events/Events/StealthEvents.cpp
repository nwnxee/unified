#include "Events/StealthEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;

StealthEvents::StealthEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestSharedHook<API::Functions::CNWSCreature__SetStealthMode, void, API::CNWSCreature*, uint8_t>(&SetStealthModeHook);
}

void StealthEvents::SetStealthModeHook(Services::Hooks::CallType type, API::CNWSCreature* thisPtr, uint8_t mode)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    const bool willBeStealthed = mode != 0;

    static bool currentlyStealthed;
    currentlyStealthed = before ? thisPtr->m_nStealthMode != 0 : currentlyStealthed;

    if (!currentlyStealthed && willBeStealthed)
    {
        Events::SignalEvent(before ? "NWNX_ON_ENTER_STEALTH_BEFORE" : "NWNX_ON_ENTER_STEALTH_AFTER", thisPtr->m_idSelf);
    }
    else
    {
        Events::SignalEvent(before ? "NWNX_ON_EXIT_STEALTH_BEFORE" : "NWNX_ON_EXIT_STEALTH_AFTER", thisPtr->m_idSelf);
    }
}

}
