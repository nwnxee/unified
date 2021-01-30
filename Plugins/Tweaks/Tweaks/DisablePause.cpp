#include "Tweaks/DisablePause.hpp"


#include "API/CAppManager.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_SetPauseState_hook;

DisablePause::DisablePause()
{
    s_SetPauseState_hook = Hooks::HookFunction(Functions::_ZN21CServerExoAppInternal13SetPauseStateEhi,
                                        (void*)&CServerExoAppInternal__SetPauseState_hook, Hooks::Order::Latest);
}

void DisablePause::CServerExoAppInternal__SetPauseState_hook(CServerExoAppInternal* thisPtr, uint8_t nState, int32_t bPause)
{
    // nState=1 - timestop
    // nState=2 - DM pause
    if (nState != 2)
        s_SetPauseState_hook->CallOriginal<void>(thisPtr, nState, bPause);
}

}
