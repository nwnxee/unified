#pragma once

#include "nwnx.hpp"

namespace Events {

class AssociateEvents
{
public:
    AssociateEvents();

private:
    static void AddAssociateHook(CNWSCreature*, ObjectID, uint16_t);
    static void RemoveAssociateHook(CNWSCreature*, ObjectID);
    static void UnpossessFamiliarHook(CNWSCreature*);
};

}
