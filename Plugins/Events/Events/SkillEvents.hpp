#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class SkillEvents
{
public:
    SkillEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t UseSkillHook(CNWSCreature*, uint8_t, uint8_t, NWNXLib::API::Types::ObjectID, Vector,
        NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID, int32_t);
};

}
