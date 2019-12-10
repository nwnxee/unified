#pragma once

#include "API/Types.hpp"
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
        NWNXLib::API::Types::ObjectID,
        int8_t,
        NWNXLib::API::Types::ObjectID,
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
};

}
