#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class TimingBarEvents
{
public:
    TimingBarEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void HandlePlayerToServerInputCancelGuiTimingEventHook(bool, CNWSMessage*, CNWSPlayer*);
    static void SendServerToPlayerGuiTimingEventHook(bool, CNWSMessage*, CNWSPlayer*, int32_t, uint8_t, uint32_t);
};

}
