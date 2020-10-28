#include "Events/ChatEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
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
    CExoString sMessage;

    ObjectID oidTarget = Constants::OBJECT_INVALID;

    if (nMinor == ChatChannel::PlayerTell)
    {
        auto nID = Utils::PeekMessage<uint32_t>(pMessage, 0);
        sMessage = Utils::PeekMessage<std::string>(pMessage, 4);

        if (auto *pClient = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nID, 0))
        {
            oidTarget = static_cast<CNWSPlayer*>(pClient)->m_oidPCObject;
        }
    }
    else
    {
        sMessage = Utils::PeekMessage<std::string>(pMessage, 0);
    }

    Globals::AppManager()->m_pServerExoApp->StripColorTokens(sMessage);

    ObjectID senderOid = API::Constants::OBJECT_INVALID;
    if (pPlayer != nullptr)
    {
        if (pPlayer->GetIsDM())
            channel |= 16;
        senderOid = pPlayer->m_oidNWSObject;
    }

    Events::PushEventData("TARGET", Utils::ObjectIDToString(oidTarget));
    Events::PushEventData("CHANNEL", std::to_string(channel));

    // Hide the message from appearing in the log if the target is valid to keep tell content out of logs
    Events::PushEventData("MESSAGE", sMessage.CStr(), oidTarget != OBJECT_INVALID);

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
