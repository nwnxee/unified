#include "Events/ChatEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooking::FunctionHook* s_HandlePlayerToServerChatMessageHook;

ChatEvents::ChatEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_CHAT_SEND_.*", [hooker]() {
        s_HandlePlayerToServerChatMessageHook = hooker->RequestExclusiveHook<
                API::Functions::_ZN11CNWSMessage31HandlePlayerToServerChatMessageEP10CNWSPlayerh>(&ChatEvents::HandlePlayerToServerChatMessageHook);
    });
}

int32_t ChatEvents::HandlePlayerToServerChatMessageHook(CNWSMessage* pMessage, CNWSPlayer* pPlayer, uint8_t nMinor)
{
    int32_t retVal = 0;

    auto channel = nMinor;
    std::string sMessage;
    if (nMinor != ChatChannel::PlayerTell)
    {
        sMessage = Utils::PeekMessage<std::string>(pMessage, 0);
    }

    ObjectID senderOid = API::Constants::OBJECT_INVALID;
    if (pPlayer != nullptr)
    {
        if (pPlayer->GetIsDM())
            channel |= 16;
        senderOid = pPlayer->m_oidNWSObject;
    }

    Events::PushEventData("CHANNEL", std::to_string(channel));

    // We only send the fact that a player sent a tell, we don't include the message nor recipient for privacy reasons
    if (channel != Constants::ChatChannel::PlayerTell && channel != Constants::ChatChannel::DmTell)
    {
        Events::PushEventData("MESSAGE", sMessage);
    }

    if (Events::SignalEvent("NWNX_ON_CHAT_SEND_BEFORE", senderOid))
    {
        retVal = s_HandlePlayerToServerChatMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
    }
    else
    {
        retVal = 0;
    }

    Events::SignalEvent("NWNX_ON_CHAT_SEND_AFTER", senderOid);
    return retVal;
}

}
