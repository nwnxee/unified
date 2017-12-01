#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class StealthEvents
{
public:
    StealthEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void SetStealthModeHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*, uint8_t);
};

}
