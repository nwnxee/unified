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
    static void HandlePartyMessageHook(NWNXLib::Services::Hooks::CallType, 
        NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, uint8_t);
};

}
