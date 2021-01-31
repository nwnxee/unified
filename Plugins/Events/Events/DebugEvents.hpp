#pragma once

#include "nwnx.hpp"

namespace Events {

class DebugEvents
{
public:
    DebugEvents();

private:
    static int32_t HandlePlayerToServerCheatMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}

