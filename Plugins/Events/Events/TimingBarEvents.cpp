#include "Events/TimingBarEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

TimingBarEvents::TimingBarEvents(ViewPtr<HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_TIMING_BAR_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage32SendServerToPlayerGuiTimingEventEP10CNWSPlayerihj, int32_t,
                CNWSMessage*, CNWSPlayer*, int32_t, uint8_t, uint32_t>(&SendServerToPlayerGuiTimingEventHook);
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage45HandlePlayerToServerInputCancelGuiTimingEventEP10CNWSPlayer, int32_t,
                CNWSMessage*, CNWSPlayer*>(&HandlePlayerToServerInputCancelGuiTimingEventHook);
    });
}

void TimingBarEvents::SendServerToPlayerGuiTimingEventHook(
        Hooks::CallType type,
        CNWSMessage*,
        CNWSPlayer* player,
        int32_t starting,
        uint8_t eventId,
        uint32_t duration)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;

    if (starting)
    {
        Events::PushEventData("EVENT_ID", std::to_string(eventId));
        Events::PushEventData("DURATION", std::to_string(duration));
        Events::SignalEvent(before ? "NWNX_ON_TIMING_BAR_START_BEFORE" : "NWNX_ON_TIMING_BAR_START_AFTER",
                            player->m_oidNWSObject);
    }
    else
    {
        Events::SignalEvent(before ? "NWNX_ON_TIMING_BAR_STOP_BEFORE" : "NWNX_ON_TIMING_BAR_STOP_AFTER",
                            player->m_oidNWSObject);
    }
}

void TimingBarEvents::HandlePlayerToServerInputCancelGuiTimingEventHook(
        Hooks::CallType type,
        CNWSMessage*,
        CNWSPlayer* player)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;

    Events::SignalEvent(before ? "NWNX_ON_TIMING_BAR_CANCEL_BEFORE" : "NWNX_ON_TIMING_BAR_CANCEL_AFTER",
                        player->m_oidNWSObject);
}

}
