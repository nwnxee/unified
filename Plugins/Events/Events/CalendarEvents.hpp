#pragma once

#include "nwnx.hpp"

namespace Events {

class CalendarEvents
{
public:
    CalendarEvents();

private:
    static void HandleUpdateTimeHook(CNWSModule*, uint32_t, uint32_t, uint32_t);
};

}
