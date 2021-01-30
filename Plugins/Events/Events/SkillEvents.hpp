#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class SkillEvents
{
public:
    SkillEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t UseSkillHook(CNWSCreature*, uint8_t, uint8_t, ObjectID, Vector, ObjectID, ObjectID, int32_t);
};

}
