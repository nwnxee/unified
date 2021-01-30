#pragma once

#include "nwnx.hpp"

namespace Events {

class PartyEvents
{
public:
    PartyEvents();

private:
    static int32_t HandlePartyMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
