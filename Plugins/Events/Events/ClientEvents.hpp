#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class ClientEvents
{
public:
    ClientEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void RemovePCFromWorldHook(bool, CServerExoAppInternal*, CNWSPlayer*);
    static int32_t SendServerToPlayerCharListHook(CNWSMessage*, CNWSPlayer*);
    static int32_t OnServerCharacterSave(CNWSPlayer*, int32_t);
    static int32_t CheckStickyPlayerNameReservedHook(
            CServerExoApp*,
            CExoString*,
            CExoString*,
            CExoString*,
            int32_t);
};

}
