#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class SkillEvents
{
public:
    SkillEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t UseSkillHook(NWNXLib::API::CNWSCreature*, uint8_t, uint8_t, NWNXLib::API::Types::ObjectID, NWNXLib::API::Vector, 
        NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID, int32_t);
};

}
