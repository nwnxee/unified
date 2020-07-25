#include "Events/QuickChatEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Utils.hpp"
#include <cstring>


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooking::FunctionHook* m_HandlePlayerToServerQuickChatMessageHook = nullptr;

QuickChatEvents::QuickChatEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_QUICKCHAT_.*", [hooker]() {
        m_HandlePlayerToServerQuickChatMessageHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN11CNWSMessage36HandlePlayerToServerQuickChatMessageEP10CNWSPlayerh>
            (&HandlePlayerToServerQuickChatMessageHook);
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
        retVal = m_HandlePlayerToServerQuickChatMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_QUICKCHAT_AFTER");

    return retVal;
}

}
