#pragma once

#include "Common.hpp"

namespace Tweaks {

class HidePlayersOnCharList
{
public:
    HidePlayersOnCharList(NWNXLib::Services::HooksProxy* hooker, int mode);

private:
    static int s_hideCharBehavior;

    static int32_t HandlePlayerToServerPlayModuleCharacterList_StartHook(
        CNWSMessage*, CNWSPlayer*);
};

}
