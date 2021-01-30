#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class JournalEvents
{
public:
    JournalEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerJournalMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
