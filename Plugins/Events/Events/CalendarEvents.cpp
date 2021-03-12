#include "Events/CalendarEvents.hpp"
#include "API/CNWSModule.hpp"
#include "Events.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_UpdateTimeHook;

CalendarEvents::CalendarEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_CALENDAR_.*", []() {
        s_UpdateTimeHook = Hooks::HookFunction(Functions::_ZN10CNWSModule10UpdateTimeEjjj, (void*)&HandleUpdateTimeHook, Hooks::Order::Earliest);
    });
}

void CalendarEvents::HandleUpdateTimeHook(CNWSModule *thisPtr, uint32_t nCalendarDay, uint32_t nTimeOfDay, uint32_t nUpdateDifference)
{
    uint32_t nHour = thisPtr->m_nCurrentHour;
    uint32_t nDay = thisPtr->m_nCurrentDay;
    uint32_t nMonth = thisPtr->m_nCurrentMonth;
    uint32_t nYear = thisPtr->m_nCurrentYear;
    uint32_t nDayState = thisPtr->m_nTimeOfDayState;

    s_UpdateTimeHook->CallOriginal<void>(thisPtr, nCalendarDay, nTimeOfDay, nUpdateDifference);

    if (nHour != thisPtr->m_nCurrentHour)
    {
        Events::PushEventData("OLD", std::to_string(nHour));
        Events::PushEventData("NEW", std::to_string(thisPtr->m_nCurrentHour));
        Events::SignalEvent("NWNX_ON_CALENDAR_HOUR", thisPtr->m_idSelf);
    }
    if (nDay != thisPtr->m_nCurrentDay)
    {
        Events::PushEventData("OLD", std::to_string(nDay));
        Events::PushEventData("NEW", std::to_string(thisPtr->m_nCurrentDay));
        Events::SignalEvent("NWNX_ON_CALENDAR_DAY", thisPtr->m_idSelf);
    }
    if (nMonth != thisPtr->m_nCurrentMonth)
    {
        Events::PushEventData("OLD", std::to_string(nMonth));
        Events::PushEventData("NEW", std::to_string(thisPtr->m_nCurrentMonth));
        Events::SignalEvent("NWNX_ON_CALENDAR_MONTH", thisPtr->m_idSelf);
    }
    if (nYear != thisPtr->m_nCurrentYear)
    {
        Events::PushEventData("OLD", std::to_string(nYear));
        Events::PushEventData("NEW", std::to_string(thisPtr->m_nCurrentYear));
        Events::SignalEvent("NWNX_ON_CALENDAR_YEAR", thisPtr->m_idSelf);
    }
    if (nDayState != thisPtr->m_nTimeOfDayState)
    {
        if (thisPtr->m_nTimeOfDayState == 3)
            Events::SignalEvent("NWNX_ON_CALENDAR_DAWN", thisPtr->m_idSelf);
        else if (thisPtr->m_nTimeOfDayState == 4)
            Events::SignalEvent("NWNX_ON_CALENDAR_DUSK", thisPtr->m_idSelf);
    }
}

}
