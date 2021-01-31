#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class HidePlayersOnCharList
{
public:
    HidePlayersOnCharList(int mode);

private:
    static int s_hideCharBehavior;

    static int32_t HandlePlayerToServerPlayModuleCharacterList_StartHook(
        CNWSMessage*, CNWSPlayer*);
};

}
