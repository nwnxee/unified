#include "Events.hpp"
#include "API/CNWSPlayer.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_HandlePlayerToServerGuiQuickbar_SetButtonHook = nullptr;

static int32_t HandlePlayerToServerGuiQuickbar_SetButtonHook(CNWSMessage*, CNWSPlayer*, uint8_t, uint8_t);

void QuickbarEvents() __attribute__((constructor));
void QuickbarEvents()
{
    InitOnFirstSubscribe("NWNX_ON_QUICKBAR_SET_BUTTON_.*", []() {
        s_HandlePlayerToServerGuiQuickbar_SetButtonHook = Hooks::HookFunction(
                &CNWSMessage::HandlePlayerToServerGuiQuickbar_SetButton,
                &HandlePlayerToServerGuiQuickbar_SetButtonHook, Hooks::Order::Early);
    });
}

int32_t HandlePlayerToServerGuiQuickbar_SetButtonHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nButton, uint8_t nObjectType)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string &ev) -> bool {
        PushEventData("BUTTON", std::to_string(nButton));
        PushEventData("TYPE", std::to_string(nObjectType));

        return SignalEvent(ev, pPlayer->m_oidNWSObject);
    };

    if (PushAndSignal("NWNX_ON_QUICKBAR_SET_BUTTON_BEFORE"))
    {
        retVal = s_HandlePlayerToServerGuiQuickbar_SetButtonHook->CallOriginal<int32_t>(thisPtr, pPlayer, nButton, nObjectType);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_QUICKBAR_SET_BUTTON_AFTER");

    return retVal;
}

}
