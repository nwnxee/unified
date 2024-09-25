#include "nwnx.hpp"

#include "API/CNWSModule.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_CutsceneModeNoTURD;

void CutsceneModeNoTURD() __attribute__((constructor));
void CutsceneModeNoTURD()
{
    if (!Config::Get<bool>("CUTSCENE_MODE_NO_TURD", false))
        return;

    LOG_INFO("SetCutsceneMode() will not drop a TURD.");

    static Hooks::Hook s_ExecuteCommandSetCutsceneModeHook = Hooks::HookFunction(&CNWSVirtualMachineCommands::ExecuteCommandSetCutsceneMode,
        +[](CNWSVirtualMachineCommands *thisPtr, int32_t nCommandId, int32_t nParameters) -> int32_t
        {
            s_CutsceneModeNoTURD = true;
            auto retVal = s_ExecuteCommandSetCutsceneModeHook->CallOriginal<int32_t>(thisPtr, nCommandId, nParameters);
            s_CutsceneModeNoTURD = false;
            return retVal;
        }, Hooks::Order::Early);

    static Hooks::Hook s_DropTURDHook = Hooks::HookFunction(&CNWSPlayer::DropTURD,
        +[](CNWSPlayer *pPlayer) -> void
        {
            if (!s_CutsceneModeNoTURD)
                s_DropTURDHook->CallOriginal<void>(pPlayer);
        }, Hooks::Order::Earliest);

    static Hooks::Hook s_CleanMyTURDsHook = Hooks::HookFunction(&CNWSPlayer::CleanMyTURDs,
        +[](CNWSPlayer *pPlayer) -> void
        {
            if (!s_CutsceneModeNoTURD)
                s_CleanMyTURDsHook->CallOriginal<void>(pPlayer);
        }, Hooks::Order::Earliest);
}

}
