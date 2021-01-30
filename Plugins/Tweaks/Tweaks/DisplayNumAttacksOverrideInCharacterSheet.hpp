#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class DisplayNumAttacksOverrideInCharacterSheet
{
public:
    DisplayNumAttacksOverrideInCharacterSheet(NWNXLib::Services::HooksProxy* hooker);

private:
    static uint8_t GetAttacksPerRoundHook(CNWSCreatureStats*);
};

}
