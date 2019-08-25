#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class PVPEvents
{
public:
    PVPEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t HandlePlayerToServerPVPListOperationsHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, uint8_t);
};

}
