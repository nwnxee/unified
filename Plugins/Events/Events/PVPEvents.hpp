#pragma once

#include "nwnx.hpp"

namespace Events {

class PVPEvents
{
public:
    PVPEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerPVPListOperationsHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
