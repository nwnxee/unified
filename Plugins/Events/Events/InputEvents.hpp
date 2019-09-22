#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class InputEvents
{
public:
    InputEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void HandlePlayerToServerInputWalkToWaypointHook(NWNXLib::Services::Hooks::CallType,
            NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*);
    static void AddAttackActionsHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*,
            NWNXLib::API::Types::ObjectID, int32_t, int32_t, int32_t);
    static void AddMoveToPointActionToFrontHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*, uint16_t,
            NWNXLib::API::Vector, NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID, int32_t, float, float,
            int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
};

}
