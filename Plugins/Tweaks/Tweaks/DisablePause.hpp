#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class DisablePause
{
public:
    DisablePause();

private:
    static void CServerExoAppInternal__SetPauseState_hook(CServerExoAppInternal*, uint8_t, int32_t);
};

}
