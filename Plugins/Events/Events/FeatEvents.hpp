#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"
#include "API/CNWSCreature.hpp"

namespace Events {

class FeatEvents
{
public:
    FeatEvents();

private:
        static int32_t UseFeatHook(CNWSCreature*, uint16_t, uint16_t, ObjectID, ObjectID, Vector*);
        static int32_t HasFeatHook(CNWSCreatureStats*, uint16_t);
};

}
