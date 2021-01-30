#pragma once

#include "API/Vector.hpp"
#include "API/CNWSCreature.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class FeatEvents
{
public:
    FeatEvents(NWNXLib::Services::HooksProxy* hooker);

private:
        static int32_t UseFeatHook(CNWSCreature*, uint16_t, uint16_t, ObjectID, ObjectID, Vector*);
        static int32_t HasFeatHook(CNWSCreatureStats*, uint16_t);
};

}
