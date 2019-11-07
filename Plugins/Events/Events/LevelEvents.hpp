#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class LevelEvents
{
public:
    LevelEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void LevelUpHook(
            NWNXLib::Services::Hooks::CallType,
            CNWSCreatureStats*,
            CNWLevelStats*,
            uint8_t, uint8_t, uint8_t, int32_t);
    static void LevelUpAutomaticHook(
            NWNXLib::Services::Hooks::CallType,
            CNWSCreatureStats*,
            uint8_t, int32_t, uint8_t);
    static void LevelDownHook(
            NWNXLib::Services::Hooks::CallType,
            CNWSCreatureStats*,
            CNWLevelStats*);
};

}