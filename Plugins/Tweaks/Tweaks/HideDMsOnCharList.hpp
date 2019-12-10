#pragma once

#include "API/Types.hpp"
#include "Common.hpp"

namespace Tweaks {

class HideDMsOnCharList
{
public:
    HideDMsOnCharList(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerPlayModuleCharacterList_StartHook(
        CNWSMessage*, CNWSPlayer*);
};

}
