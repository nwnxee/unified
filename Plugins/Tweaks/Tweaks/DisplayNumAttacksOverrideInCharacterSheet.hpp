#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class DisplayNumAttacksOverrideInCharacterSheet
{
public:
    DisplayNumAttacksOverrideInCharacterSheet(NWNXLib::Services::HooksProxy* hooker);

private:
    static uint8_t GetAttacksPerRoundHook(CNWSCreatureStats*);
};

}
