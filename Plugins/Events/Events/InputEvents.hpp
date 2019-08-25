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
};

}
