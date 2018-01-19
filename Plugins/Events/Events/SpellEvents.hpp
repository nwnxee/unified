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
        NWNXLib::Services::Hooks::CallType, 
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
};

}
