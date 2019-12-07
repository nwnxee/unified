#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class AssociateEvents
{
public:
    AssociateEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void AddAssociateHook(bool, CNWSCreature*, NWNXLib::API::Types::ObjectID, uint16_t);
    static void RemoveAssociateHook(bool, CNWSCreature*, NWNXLib::API::Types::ObjectID);
};

}
