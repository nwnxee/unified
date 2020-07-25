#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class CalendarEvents
{
public:
    CalendarEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void HandleUpdateTimeHook(bool, CNWSModule*, uint32_t, uint32_t, uint32_t);
};

}
