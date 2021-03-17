#pragma once

#include "nwnx.hpp"

namespace Events {

class LevelEvents
{
public:
    LevelEvents();

private:
    static void LevelUpHook(CNWSCreatureStats*, CNWLevelStats*, uint8_t, uint8_t, uint8_t, int32_t);
    static int32_t LevelUpAutomaticHook(CNWSCreatureStats*, uint8_t, int32_t, uint8_t);
    static void LevelDownHook(CNWSCreatureStats*, CNWLevelStats*);
    static int32_t HandlePlayerToServerLevelUpMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
