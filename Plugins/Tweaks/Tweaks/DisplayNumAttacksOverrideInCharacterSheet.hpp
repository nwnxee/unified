#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class DisplayNumAttacksOverrideInCharacterSheet
{
public:
    DisplayNumAttacksOverrideInCharacterSheet();

private:
    static uint8_t GetAttacksPerRoundHook(CNWSCreatureStats*);
};

}
