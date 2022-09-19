#include "Events.hpp"
#include "API/CNWSPlayer.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_HandlePlayerToServerQuickChatMessageHook = nullptr;

static int32_t HandlePlayerToServerQuickChatMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);

void QuickChatEvents() __attribute__((constructor));
void QuickChatEvents()
{
    InitOnFirstSubscribe("NWNX_ON_QUICKCHAT_.*", []() {
        s_HandlePlayerToServerQuickChatMessageHook = Hooks::HookFunction(
                &CNWSMessage::HandlePlayerToServerQuickChatMessage,
                &HandlePlayerToServerQuickChatMessageHook, Hooks::Order::Early);
    });
}

int32_t HandlePlayerToServerQuickChatMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;
    ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;
    std::string quickChatCommand = std::to_string(Utils::PeekMessage<int16_t>(thisPtr, 0));

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("QUICKCHAT_COMMAND", quickChatCommand);

        return SignalEvent(ev, oidPlayer);
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
