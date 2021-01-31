#include "Events/QuickChatEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include <cstring>


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_HandlePlayerToServerQuickChatMessageHook = nullptr;

QuickChatEvents::QuickChatEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_QUICKCHAT_.*", []() {
        s_HandlePlayerToServerQuickChatMessageHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage36HandlePlayerToServerQuickChatMessageEP10CNWSPlayerh,
                (void*)&HandlePlayerToServerQuickChatMessageHook, Hooks::Order::Early);
    });
}

int32_t QuickChatEvents::HandlePlayerToServerQuickChatMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;
    ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;
    std::string quickChatCommand = std::to_string(Utils::PeekMessage<int16_t>(thisPtr, 0));

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("QUICKCHAT_COMMAND", quickChatCommand);

        return Events::SignalEvent(ev, oidPlayer);
    };

    if (PushAndSignal("NWNX_ON_QUICKCHAT_BEFORE"))
    {
        retVal = s_HandlePlayerToServerQuickChatMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_QUICKCHAT_AFTER");

    return retVal;
}

}
