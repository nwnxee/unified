#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class StoreEvents
{
public:
    StoreEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t RequestBuyHook(CNWSCreature*, ObjectID, ObjectID, ObjectID);
    static int32_t RequestSellHook(CNWSCreature*, ObjectID, ObjectID);
};

}
