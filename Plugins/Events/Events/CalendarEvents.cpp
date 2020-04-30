#include "Events/CalendarEvents.hpp"
#include "API/CNWSModule.hpp"
#include "Events.hpp"
#include "Utils.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;



CalendarEvents::CalendarEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_CALENDAR_.*", [hooker]() {
        hooker->RequestSharedHook<Functions::_ZN10CNWSModule10UpdateTimeEjjj, void>(&HandleUpdateTimeHook);
    });
}


void CalendarEvents::HandleUpdateTimeHook(bool before, CNWSModule *thisPtr, uint32_t, uint32_t, uint32_t)
{
    static uint32_t s_nHour, s_nDay, s_nMonth, s_nYear, s_nDayState;

    if (before)
    {
        s_nHour = thisPtr->m_nCurrentHour;
        s_nDay = thisPtr->m_nCurrentDay;
        s_nMonth = thisPtr->m_nCurrentMonth;
        s_nYear = thisPtr->m_nCurrentYear;
        s_nDayState = thisPtr->m_nTimeOfDayState;
    }
    else
    {
        if (s_nHour != thisPtr->m_nCurrentHour)
        {
            Events::PushEventData("OLD", std::to_string(s_nHour));
            Events::PushEventData("NEW", std::to_string(thisPtr->m_nCurrentHour));
            Events::SignalEvent("NWNX_ON_CALENDAR_HOUR", thisPtr->m_idSelf);
        }
        if (s_nDay != thisPtr->m_nCurrentDay)
        {
            Events::PushEventData("OLD", std::to_string(s_nDay));
            Events::PushEventData("NEW", std::to_string(thisPtr->m_nCurrentDay));
            Events::SignalEvent("NWNX_ON_CALENDAR_DAY", thisPtr->m_idSelf);
        }
        if (s_nMonth != thisPtr->m_nCurrentMonth)
        {
            Events::PushEventData("OLD", std::to_string(s_nMonth));
            Events::PushEventData("NEW", std::to_string(thisPtr->m_nCurrentMonth));
            Events::SignalEvent("NWNX_ON_CALENDAR_MONTH", thisPtr->m_idSelf);
        }
        if (s_nYear != thisPtr->m_nCurrentYear)
        {
            Events::PushEventData("OLD", std::to_string(s_nYear));
            Events::PushEventData("NEW", std::to_string(thisPtr->m_nCurrentYear));
            Events::SignalEvent("NWNX_ON_CALENDAR_YEAR", thisPtr->m_idSelf);
        }
        if (s_nDayState != thisPtr->m_nTimeOfDayState)
        {
            if (thisPtr->m_nTimeOfDayState == 3)
                Events::SignalEvent("NWNX_ON_CALENDAR_DAWN", thisPtr->m_idSelf);
            else if (thisPtr->m_nTimeOfDayState == 4)
                Events::SignalEvent("NWNX_ON_CALENDAR_DUSK", thisPtr->m_idSelf);
        }
    }
}

}
