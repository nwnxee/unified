#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Experimental {

class SuppressPlayerLoginInfo
{
public:
    SuppressPlayerLoginInfo(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t SendServerToPlayerPlayerList_AddHook(CNWSMessage*, uint32_t, CNWSPlayer*);
    static int32_t SendServerToPlayerPlayerList_AllHook(CNWSMessage*, CNWSPlayer*);
    static int32_t SendServerToPlayerPlayerList_DeleteHook(CNWSMessage*, uint32_t, CNWSPlayer*);
    static int32_t HandlePlayerToServerPlayModuleCharacterList_StartHook(CNWSMessage*, CNWSPlayer*);
};

}
