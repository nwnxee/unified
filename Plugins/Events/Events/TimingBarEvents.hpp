#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class TimingBarEvents
{
public:
    TimingBarEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void HandlePlayerToServerInputCancelGuiTimingEventHook(
            NWNXLib::Services::Hooks::CallType,
            NWNXLib::API::CNWSMessage*,
            NWNXLib::API::CNWSPlayer*);
    static void SendServerToPlayerGuiTimingEventHook(
            NWNXLib::Services::Hooks::CallType,
            NWNXLib::API::CNWSMessage*,
            NWNXLib::API::CNWSPlayer*,
            int32_t, uint8_t, uint32_t);
};

}
