#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class PartyEvents
{
public:
    PartyEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePartyMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
