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
    static void SetStealthModeHook(CNWSCreature*, uint8_t);
    static int32_t HandleDetectionHook(const std::string&, NWNXLib::Hooking::FunctionHook*, CNWSCreature*, CNWSCreature*, int32_t);
    static int32_t DoListenDetectionHook(CNWSCreature*, CNWSCreature*, int32_t);
    static int32_t DoSpotDetectionHook(CNWSCreature*, CNWSCreature*, int32_t);
};

}
