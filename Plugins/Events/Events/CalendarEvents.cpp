#include "Events.hpp"
#include "API/CNWSModule.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_UpdateTimeHook;

static void HandleUpdateTimeHook(CNWSModule*, uint32_t, uint32_t, uint32_t);

void CalendarEvents() __attribute__((constructor));
void CalendarEvents()
{
    InitOnFirstSubscribe("NWNX_ON_CALENDAR_.*", []() {
        s_UpdateTimeHook = Hooks::HookFunction(&CNWSModule::UpdateTime, &HandleUpdateTimeHook, Hooks::Order::Earliest);
    });
}

void HandleUpdateTimeHook(CNWSModule *thisPtr, uint32_t nCalendarDay, uint32_t nTimeOfDay, uint32_t nUpdateDifference)
{
    uint32_t nHour = thisPtr->m_nCurrentHour;
    uint32_t nDay = thisPtr->m_nCurrentDay;
    uint32_t nMonth = thisPtr->m_nCurrentMonth;
    uint32_t nYear = thisPtr->m_nCurrentYear;
    uint32_t nDayState = thisPtr->m_nTimeOfDayState;

    s_UpdateTimeHook->CallOriginal<void>(thisPtr, nCalendarDay, nTimeOfDay, nUpdateDifference);

    if (nHour != thisPtr->m_nCurrentHour)
    {
        PushEventData("OLD", std::to_string(nHour));
        PushEventData("NEW", std::to_string(thisPtr->m_nCurrentHour));
        SignalEvent("NWNX_ON_CALENDAR_HOUR", thisPtr->m_idSelf);
    }
    if (nDay != thisPtr->m_nCurrentDay)
    {
        PushEventData("OLD", std::to_string(nDay));
        PushEventData("NEW", std::to_string(thisPtr->m_nCurrentDay));
        SignalEvent("NWNX_ON_CALENDAR_DAY", thisPtr->m_idSelf);
    }
    if (nMonth != thisPtr->m_nCurrentMonth)
    {
        PushEventData("OLD", std::to_string(nMonth));
        PushEventData("NEW", std::to_string(thisPtr->m_nCurrentMonth));
        SignalEvent("NWNX_ON_CALENDAR_MONTH", thisPtr->m_idSelf);
    }
    if (nYear != thisPtr->m_nCurrentYear)
    {
        PushEventData("OLD", std::to_string(nYear));
        PushEventData("NEW", std::to_string(thisPtr->m_nCurrentYear));
        SignalEvent("NWNX_ON_CALENDAR_YEAR", thisPtr->m_idSelf);
    }
    if (nDayState != thisPtr->m_nTimeOfDayState)
    {
        if (thisPtr->m_nTimeOfDayState == 3)
            SignalEvent("NWNX_ON_CALENDAR_DAWN", thisPtr->m_idSelf);
        else if (thisPtr->m_nTimeOfDayState == 4)
            SignalEvent("NWNX_ON_CALENDAR_DUSK", thisPtr->m_idSelf);
    }
}

}
