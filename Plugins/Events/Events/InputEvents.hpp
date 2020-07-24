#pragma once

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
    static int32_t AddAttackActionsHook(CNWSCreature*, ObjectID, int32_t, int32_t, int32_t);
    static void AddMoveToPointActionToFrontHook(bool, CNWSCreature*, uint16_t,
            Vector, ObjectID, ObjectID, int32_t, float, float,
            int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    static int32_t AddCastSpellActionsHook(CNWSCreature*, uint32_t, int32_t, int32_t, int32_t, int32_t,
            Vector, ObjectID, int32_t, int32_t, int32_t, uint8_t, int32_t, int32_t, int32_t, uint8_t);
    static int32_t HandlePlayerToServerInputMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
