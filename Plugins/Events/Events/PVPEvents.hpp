#pragma once

#include "nwnx.hpp"

namespace Events {

class PVPEvents
{
public:
    PVPEvents();

private:
    static int32_t HandlePlayerToServerPVPListOperationsHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
