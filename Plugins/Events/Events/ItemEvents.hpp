#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class ItemEvents
{
public:
    ItemEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void UseItemHook(NWNXLib::API::CNWSCreature*, NWNXLib::API::Types::ObjectID, uint8_t,
        uint8_t, NWNXLib::API::Types::ObjectID, NWNXLib::API::Vector, NWNXLib::API::Types::ObjectID);
};

}
