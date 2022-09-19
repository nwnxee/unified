#include "Events.hpp"
#include "API/CNWSPlayer.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_SendServerToPlayerGuiTimingEventHook;
static Hooks::Hook s_HandlePlayerToServerInputCancelGuiTimingEventHook;

static int32_t SendServerToPlayerGuiTimingEventHook(CNWSMessage*, CNWSPlayer*, int32_t, uint8_t, uint32_t);
static int32_t HandlePlayerToServerInputCancelGuiTimingEventHook(CNWSMessage*, CNWSPlayer*);

void TimingBarEvents() __attribute__((constructor));
void TimingBarEvents()
{
    InitOnFirstSubscribe("NWNX_ON_TIMING_BAR_.*", []() {
        s_SendServerToPlayerGuiTimingEventHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerGuiTimingEvent,
                                                              &SendServerToPlayerGuiTimingEventHook, Hooks::Order::Earliest);
        s_HandlePlayerToServerInputCancelGuiTimingEventHook = Hooks::HookFunction(
                &CNWSMessage::HandlePlayerToServerInputCancelGuiTimingEvent,
                (void*)&HandlePlayerToServerInputCancelGuiTimingEventHook, Hooks::Order::Earliest);
    });
}

int32_t SendServerToPlayerGuiTimingEventHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, int32_t bStarting,
                                                           uint8_t nGuiTimingEventID, uint32_t nDuration)
{
    int32_t retVal;
    if (bStarting)
    {
        PushEventData("EVENT_ID", std::to_string(nGuiTimingEventID));
        PushEventData("DURATION", std::to_string(nDuration));
        SignalEvent("NWNX_ON_TIMING_BAR_START_BEFORE", pPlayer->m_oidNWSObject);
        retVal = s_SendServerToPlayerGuiTimingEventHook->CallOriginal<int32_t>(pMessage, pPlayer, bStarting, nGuiTimingEventID, nDuration);
        PushEventData("EVENT_ID", std::to_string(nGuiTimingEventID));
        PushEventData("DURATION", std::to_string(nDuration));
        SignalEvent("NWNX_ON_TIMING_BAR_START_AFTER", pPlayer->m_oidNWSObject);
    }
    else
    {
        SignalEvent("NWNX_ON_TIMING_BAR_STOP_BEFORE", pPlayer->m_oidNWSObject);
        retVal = s_SendServerToPlayerGuiTimingEventHook->CallOriginal<int32_t>(pMessage, pPlayer, bStarting, nGuiTimingEventID, nDuration);
        SignalEvent("NWNX_ON_TIMING_BAR_STOP_AFTER", pPlayer->m_oidNWSObject);
    }

    return retVal;
}

int32_t HandlePlayerToServerInputCancelGuiTimingEventHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer)
{
    SignalEvent("NWNX_ON_TIMING_BAR_CANCEL_BEFORE", pPlayer->m_oidNWSObject);
    auto retVal = s_HandlePlayerToServerInputCancelGuiTimingEventHook->CallOriginal<int32_t>(pMessage, pPlayer);
    SignalEvent("NWNX_ON_TIMING_BAR_CANCEL_AFTER",pPlayer->m_oidNWSObject);
    return retVal;
}

}
