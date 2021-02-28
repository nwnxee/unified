#pragma once

#include "nwnx.hpp"

namespace Events {

class ClientEvents
{
public:
    ClientEvents();

private:
    static void RemovePCFromWorldHook(CServerExoAppInternal*, CNWSPlayer*);
    static int32_t SaveServerCharacterHook(CNWSPlayer*, int32_t);
    static int32_t SendServerToPlayerCharListHook(CNWSMessage*, CNWSPlayer*);
    static int32_t CheckStickyPlayerNameReservedHook(CServerExoAppInternal*, CExoString, CExoString, CExoString, int32_t);
    static int32_t SendServerToPlayerModule_ExportReplyHook(CNWSMessage*, CNWSPlayer*);
    static int32_t SendServerToPlayerArea_ClientAreaHook(CNWSMessage*, CNWSPlayer*, CNWSArea*, float, float, float, const Vector*, BOOL);
};

}
