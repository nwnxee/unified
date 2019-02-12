#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class ClientEvents
{
public:
    ClientEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void RemovePCFromWorldHook(NWNXLib::Services::Hooks::CallType type,
        NWNXLib::API::CServerExoAppInternal*,
        NWNXLib::API::CNWSPlayer*);
    static int32_t SendServerToPlayerCharListHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*);
};

}
