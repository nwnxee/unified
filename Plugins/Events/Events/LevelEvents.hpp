#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class LevelEvents
{
public:
    LevelEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void LevelUpHook(CNWSCreatureStats*, CNWLevelStats*, uint8_t, uint8_t, uint8_t, int32_t);
    static int32_t LevelUpAutomaticHook(CNWSCreatureStats*, uint8_t, int32_t, uint8_t);
    static void LevelDownHook(CNWSCreatureStats*, CNWLevelStats*);
};

}
