#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class SpellEvents
{
public:
    SpellEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void CastSpellHook
    (
        NWNXLib::API::CNWSObject*,
        uint32_t,
        NWNXLib::API::Vector,
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
        NWNXLib::API::CNWSCreatureStats*,
        uint8_t,
        uint8_t,
        uint32_t,
        uint8_t,
        uint8_t,
        int32_t
    );
    static void ClearMemorizedSpellSlotHook(NWNXLib::API::CNWSCreatureStats*, uint8_t, uint8_t, uint8_t);
};

}
