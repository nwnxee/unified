#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CGameObjectArray.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CWorldTimer.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoTimers.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNWSMessage.hpp"

#include <queue>

namespace Optimizations
{

using namespace NWNXLib;
using namespace NWNXLib::API;

struct CServerAIEventNodeComparator
{
    bool operator()(const CServerAIEventNode& lhs, const CServerAIEventNode& rhs) const
    {
        return (lhs.m_nCalendarDay == rhs.m_nCalendarDay) ? (lhs.m_nTimeOfDay > rhs.m_nTimeOfDay) : (lhs.m_nCalendarDay > rhs.m_nCalendarDay);
    }
};

static std::priority_queue<CServerAIEventNode, std::vector<CServerAIEventNode>, CServerAIEventNodeComparator> s_event_queue;

static void ClearEventQueue(CServerAIMaster*)
{
    s_event_queue = {};
}

static BOOL AddEventAbsoluteTime(CServerAIMaster*, uint32_t nCalendarDay, uint32_t nTimeOfDay, OBJECT_ID nCallerObjectId, OBJECT_ID nObjectId, uint32_t nEventId, void *pEventData)
{
    s_event_queue.emplace(CServerAIEventNode { nCalendarDay, nTimeOfDay, nCallerObjectId, nObjectId, nEventId, pEventData });
    return true;
}

static BOOL EventPending(CServerAIMaster* ai, uint32_t nCalendarDay, uint32_t nTimeOfDay)
{
    if (s_event_queue.empty()) return false;

    const CServerAIEventNode& eventNode = s_event_queue.top();
    return ai->m_pExoAppInternal->m_pWorldTimer->CompareWorldTimes(eventNode.m_nCalendarDay, eventNode.m_nTimeOfDay, nCalendarDay, nTimeOfDay) <= 0;
}

static BOOL GetPendingEvent(CServerAIMaster*, uint32_t *nCalendarDay, uint32_t *nTimeOfDay, OBJECT_ID *nCallerObjectId, OBJECT_ID *nObjectId, uint32_t *nEventId, void **pEventData)
{
    if (s_event_queue.empty()) return false;

    const CServerAIEventNode& eventNode = s_event_queue.top();

    *nCalendarDay     = eventNode.m_nCalendarDay;
    *nTimeOfDay       = eventNode.m_nTimeOfDay;
    *nCallerObjectId  = eventNode.m_nCallerObjectId;
    *nObjectId        = eventNode.m_nObjectId;
    *nEventId         = eventNode.m_nEventId;
    *pEventData       = eventNode.m_pEventData;

    s_event_queue.pop();
    return true; 
}

void EventMasterPriorityQueue() __attribute__((constructor));

void EventMasterPriorityQueue()
{
    // Replace:
    // 
    // * CServerAIMaster::ClearEventQueue()
    // * CServerAIMaster::AddEventAbsoluteTime()
    // * CServerAIMaster::AddEventAbsoluteTimeViaTail()
    // * CServerAIMaster::EventPending()
    // * CServerAIMaster::GetPendingEvent()
    // 
    // Don't care about save/load event queue.

    if (Config::Get<bool>("EVENT_MASTER_PRIORITY_QUEUE", false))
    {
        static Hooks::Hook _0 = Hooks::HookFunction(API::Functions::_ZN15CServerAIMaster15ClearEventQueueEv, (void*)&ClearEventQueue, Hooks::Order::Final);
        static Hooks::Hook _1 = Hooks::HookFunction(API::Functions::_ZN15CServerAIMaster20AddEventAbsoluteTimeEjjjjjPv, (void*)&AddEventAbsoluteTime, Hooks::Order::Final);
        static Hooks::Hook _2 = Hooks::HookFunction(API::Functions::_ZN15CServerAIMaster27AddEventAbsoluteTimeViaTailEjjjjjPv, (void*)&AddEventAbsoluteTime, Hooks::Order::Final);
        static Hooks::Hook _3 = Hooks::HookFunction(API::Functions::_ZN15CServerAIMaster12EventPendingEjj, (void*)&EventPending, Hooks::Order::Final);
        static Hooks::Hook _4 = Hooks::HookFunction(API::Functions::_ZN15CServerAIMaster15GetPendingEventEPjS0_S0_S0_S0_PPv, (void*)&GetPendingEvent, Hooks::Order::Final);
    }
}

}
