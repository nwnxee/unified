#pragma once

#include "nwnx.hpp"

namespace Events {

class StealthEvents
{
public:
    StealthEvents();

private:
    static void SetStealthModeHook(CNWSCreature*, uint8_t);
    static void SetDetectModeHook(CNWSCreature*, uint8_t);
    static int32_t HandleDetectionHook(const std::string&, NWNXLib::Hooks::FunctionHook*, CNWSCreature*, CNWSCreature*, int32_t);
    static int32_t DoListenDetectionHook(CNWSCreature*, CNWSCreature*, int32_t);
    static int32_t DoSpotDetectionHook(CNWSCreature*, CNWSCreature*, int32_t);
};

}
