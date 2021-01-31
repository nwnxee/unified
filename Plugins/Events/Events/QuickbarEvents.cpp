#include "Events/QuickbarEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "Events.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_HandlePlayerToServerGuiQuickbar_SetButtonHook = nullptr;

QuickbarEvents::QuickbarEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_QUICKBAR_SET_BUTTON_.*", []() {
        s_HandlePlayerToServerGuiQuickbar_SetButtonHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage41HandlePlayerToServerGuiQuickbar_SetButtonEP10CNWSPlayerhh,
                (void*)&HandlePlayerToServerGuiQuickbar_SetButtonHook, Hooks::Order::Early);
    });
}

int32_t QuickbarEvents::HandlePlayerToServerGuiQuickbar_SetButtonHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nButton, uint8_t nObjectType)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string &ev) -> bool {
        Events::PushEventData("BUTTON", std::to_string(nButton));
        Events::PushEventData("TYPE", std::to_string(nObjectType));

        return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
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
