#pragma once

#include "nwnx.hpp"

namespace Events {

class TimingBarEvents
{
public:
    TimingBarEvents();

private:
    static int32_t SendServerToPlayerGuiTimingEventHook(CNWSMessage*, CNWSPlayer*, int32_t, uint8_t, uint32_t);
    static int32_t HandlePlayerToServerInputCancelGuiTimingEventHook(CNWSMessage*, CNWSPlayer*);
};

}
