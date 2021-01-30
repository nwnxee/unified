#pragma once

#include "nwnx.hpp"

namespace Events {

class DebugEvents
{
public:
    DebugEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerCheatMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}

