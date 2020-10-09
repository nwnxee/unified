#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class AssociateEvents
{
public:
    AssociateEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void AddAssociateHook(bool, CNWSCreature*, ObjectID, uint16_t);
    static void RemoveAssociateHook(bool, CNWSCreature*, ObjectID);
};

}
