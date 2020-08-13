#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class DebugEvents
{
public:
    DebugEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerCheatMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}

