#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class InputEvents
{
public:
    InputEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerInputWalkToWaypointHook(CNWSMessage*, CNWSPlayer*);
    static int32_t AddAttackActionsHook(CNWSCreature*, NWNXLib::API::Types::ObjectID, int32_t, int32_t, int32_t);
    static void AddMoveToPointActionToFrontHook(bool, CNWSCreature*, uint16_t,
            Vector, NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID, int32_t, float, float,
            int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    static int32_t AddCastSpellActionsHook(CNWSCreature*, uint32_t, int32_t, int32_t, int32_t, int32_t,
            Vector, NWNXLib::API::Types::ObjectID, int32_t, int32_t, int32_t, uint8_t, int32_t, int32_t, int32_t, uint8_t);
};

}
