#pragma once

#include "nwnx.hpp"

namespace Events {

class StoreEvents
{
public:
    StoreEvents();

private:
    static int32_t RequestBuyHook(CNWSCreature*, ObjectID, ObjectID, ObjectID);
    static int32_t RequestSellHook(CNWSCreature*, ObjectID, ObjectID);
};

}
