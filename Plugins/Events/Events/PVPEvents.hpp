#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class PVPEvents
{
public:
    PVPEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerPVPListOperationsHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
