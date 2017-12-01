#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class AssociateEvents
{
public:
    AssociateEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void AddAssociateHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*, NWNXLib::API::Types::ObjectID, uint16_t);
    static void RemoveAssociateHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*, NWNXLib::API::Types::ObjectID);
};

}
