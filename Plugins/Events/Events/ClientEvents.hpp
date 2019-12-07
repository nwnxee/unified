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
    static void RemovePCFromWorldHook(bool, CServerExoAppInternal*, CNWSPlayer*);
    static int32_t SendServerToPlayerCharListHook(CNWSMessage*, CNWSPlayer*);
    static int32_t CheckStickyPlayerNameReservedHook(
            CServerExoApp*,
            CExoString*,
            CExoString*,
            CExoString*,
            int32_t);
};

}
