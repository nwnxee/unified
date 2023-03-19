#include "nwnx.hpp"

#include "API/CServerExoAppInternal.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void DisablePause() __attribute__((constructor));
void DisablePause()
{
    if (!Config::Get<bool>("DISABLE_PAUSE", false))
        return;

    LOG_INFO("Disabling pausing of the server");

    static Hooks::Hook s_SetPauseState_hook = Hooks::HookFunction(&CServerExoAppInternal::SetPauseState,
        +[](CServerExoAppInternal* thisPtr, uint8_t nState, int32_t bPause) -> void
        {
            // nState=1 - timestop
            // nState=2 - DM pause
            if (nState != 2)
                s_SetPauseState_hook->CallOriginal<void>(thisPtr, nState, bPause);
        }, Hooks::Order::Latest);
}

}
