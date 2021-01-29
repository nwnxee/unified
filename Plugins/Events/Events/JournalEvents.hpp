#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class JournalEvents
{
public:
    JournalEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerJournalMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
