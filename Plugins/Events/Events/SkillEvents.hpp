#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class SkillEvents
{
public:
    SkillEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t UseSkillHook(CNWSCreature*, uint8_t, uint8_t, ObjectID, Vector,
        ObjectID, ObjectID, int32_t);
};

}
