#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Plugin.hpp"
#include "Services/Events/Events.hpp"

namespace NWNXLib { namespace Hooking { class FunctionHook; } }

namespace Chat {

enum class ChatChannel
{
    PLAYER_TALK     = 1,
    PLAYER_SHOUT    = 2,
    PLAYER_WHISPER  = 3,
    PLAYER_TELL     = 4,
    SERVER_MSG      = 5,
    PLAYER_PARTY    = 6,
    PLAYER_DM       = 14,
    DM_TALK         = 17,
    DM_SHOUT        = 18,
    DM_WHISPER      = 19,
    DM_TELL         = 20,
    DM_PARTY        = 22,
    DM_DM           = 30
};

class Chat : public NWNXLib::Plugin
{
public:
    Chat(const Plugin::CreateParams& params);
    virtual ~Chat();

private:
    NWNXLib::Hooking::FunctionHook* m_hook;

    ChatChannel m_activeChannel;
    std::string m_activeMessage;
    NWNXLib::API::Types::ObjectID m_activeSenderObjectId;
    NWNXLib::API::Types::ObjectID m_activeTargetObjectId;

    std::string m_chatScript;
    bool m_skipMessage;
    uint32_t m_depth;

    static void SendServerToPlayerChatMessage(NWNXLib::API::CNWSMessage* thisPtr, ChatChannel channel, NWNXLib::API::Types::ObjectID sender,
        NWNXLib::API::CExoString message, NWNXLib::API::Types::ObjectID target, NWNXLib::API::CExoString* tellName);

    NWNXLib::Services::Events::ArgumentStack OnSendMessage(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnRegisterChatScript(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSkipMessage(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetChannel(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetMessage(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetSender(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetTarget(NWNXLib::Services::Events::ArgumentStack&& args);
};

}
