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
    static void HandlePlayerToServerJournalMessageHook(bool, CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
