#pragma once

#include "nwnx.hpp"

namespace Experimental {

class SuppressPlayerLoginInfo
{
public:
    SuppressPlayerLoginInfo();

private:
    static int32_t SendServerToPlayerPlayerList_AddHook(CNWSMessage*, uint32_t, CNWSPlayer*);
    static int32_t SendServerToPlayerPlayerList_AllHook(CNWSMessage*, CNWSPlayer*);
    static int32_t SendServerToPlayerPlayerList_DeleteHook(CNWSMessage*, uint32_t, CNWSPlayer*);
    static int32_t HandlePlayerToServerPlayModuleCharacterList_StartHook(CNWSMessage*, CNWSPlayer*);
};

}
