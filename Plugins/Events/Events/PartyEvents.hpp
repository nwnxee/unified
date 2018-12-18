#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class PartyEvents
{
public:
    PartyEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t HandlePartyMessageHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, uint8_t);
};

}
