#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class DisablePause
{
public:
    DisablePause(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CServerExoAppInternal__SetPauseState_hook(CServerExoAppInternal*, uint8_t, int32_t);
    static NWNXLib::Hooking::FunctionHook* pSetPauseState_hook;
};

}
