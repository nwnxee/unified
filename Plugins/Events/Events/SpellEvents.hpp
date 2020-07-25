#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class SpellEvents
{
public:
    SpellEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CastSpellHook
    (
        CNWSObject*,
        uint32_t,
        Vector,
        ObjectID,
        int8_t,
        ObjectID,
        bool,
        bool,
        int8_t,
        bool
    );
    static int32_t SetMemorizedSpellSlotHook
    (
        CNWSCreatureStats*,
        uint8_t,
        uint8_t,
        uint32_t,
        uint8_t,
        uint8_t,
        int32_t
    );
    static void ClearMemorizedSpellSlotHook(CNWSCreatureStats*, uint8_t, uint8_t, uint8_t);
    static void BroadcastSpellCastHook(CNWSCreature*, uint32_t, uint8_t, uint16_t);
};

}
