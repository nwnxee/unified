#include "Events/TimingBarEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_SendServerToPlayerGuiTimingEventHook;
static Hooks::Hook s_HandlePlayerToServerInputCancelGuiTimingEventHook;

TimingBarEvents::TimingBarEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_TIMING_BAR_.*", []() {
        s_SendServerToPlayerGuiTimingEventHook = Hooks::HookFunction(API::Functions::_ZN11CNWSMessage32SendServerToPlayerGuiTimingEventEP10CNWSPlayerihj,
                                                              (void*)&SendServerToPlayerGuiTimingEventHook, Hooks::Order::Earliest);
        s_HandlePlayerToServerInputCancelGuiTimingEventHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage45HandlePlayerToServerInputCancelGuiTimingEventEP10CNWSPlayer,
                (void*)&HandlePlayerToServerInputCancelGuiTimingEventHook, Hooks::Order::Earliest);
    });
}

int32_t TimingBarEvents::SendServerToPlayerGuiTimingEventHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, int32_t bStarting,
                                                           uint8_t nGuiTimingEventID, uint32_t nDuration)
{
    int32_t retVal;
    if (bStarting)
    {
        Events::PushEventData("EVENT_ID", std::to_string(nGuiTimingEventID));
        Events::PushEventData("DURATION", std::to_string(nDuration));
        Events::SignalEvent("NWNX_ON_TIMING_BAR_START_BEFORE", pPlayer->m_oidNWSObject);
        retVal = s_SendServerToPlayerGuiTimingEventHook->CallOriginal<int32_t>(pMessage, pPlayer, bStarting, nGuiTimingEventID, nDuration);
        Events::PushEventData("EVENT_ID", std::to_string(nGuiTimingEventID));
        Events::PushEventData("DURATION", std::to_string(nDuration));
        Events::SignalEvent("NWNX_ON_TIMING_BAR_START_AFTER", pPlayer->m_oidNWSObject);
    }
    else
    {
        Events::SignalEvent("NWNX_ON_TIMING_BAR_STOP_BEFORE", pPlayer->m_oidNWSObject);
        retVal = s_SendServerToPlayerGuiTimingEventHook->CallOriginal<int32_t>(pMessage, pPlayer, bStarting, nGuiTimingEventID, nDuration);
        Events::SignalEvent("NWNX_ON_TIMING_BAR_STOP_AFTER", pPlayer->m_oidNWSObject);
    }

    return retVal;
}

int32_t TimingBarEvents::HandlePlayerToServerInputCancelGuiTimingEventHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer)
{
    Events::SignalEvent("NWNX_ON_TIMING_BAR_CANCEL_BEFORE", pPlayer->m_oidNWSObject);
    auto retVal = s_HandlePlayerToServerInputCancelGuiTimingEventHook->CallOriginal<int32_t>(pMessage, pPlayer);
    Events::SignalEvent("NWNX_ON_TIMING_BAR_CANCEL_AFTER",pPlayer->m_oidNWSObject);
    return retVal;
}

}
