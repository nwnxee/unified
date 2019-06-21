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
    static int32_t HandleDetectionHook(const std::string&, NWNXLib::Hooking::FunctionHook*, NWNXLib::API::CNWSCreature*, NWNXLib::API::CNWSCreature*, int32_t);
    static int32_t DoListenDetectionHook(NWNXLib::API::CNWSCreature*, NWNXLib::API::CNWSCreature*, int32_t);
    static int32_t DoSpotDetectionHook(NWNXLib::API::CNWSCreature*, NWNXLib::API::CNWSCreature*, int32_t);
};

}
