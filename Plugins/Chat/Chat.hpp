#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Plugin.hpp"
#include "API/Constants/Misc.hpp"
#include "Services/Events/Events.hpp"

namespace NWNXLib::Hooking { class FunctionHook; }

namespace Chat {

class Chat : public NWNXLib::Plugin
{
public:
    Chat(const Plugin::CreateParams& params);
    virtual ~Chat();

private:
    NWNXLib::Hooking::FunctionHook* m_hook;

    NWNXLib::API::Constants::ChatChannel::TYPE m_activeChannel;
    std::string m_activeMessage;
    NWNXLib::API::Types::ObjectID m_activeSenderObjectId;
    NWNXLib::API::Types::ObjectID m_activeTargetObjectId;

    std::string m_chatScript;
    bool m_skipMessage;
    bool m_customHearingDistances;
    std::unordered_map<NWNXLib::API::Constants::ChatChannel::TYPE, float> m_hearingDistances;
    uint32_t m_depth;

    static void SendServerToPlayerChatMessage(NWNXLib::API::CNWSMessage* thisPtr, NWNXLib::API::Constants::ChatChannel::TYPE channel, NWNXLib::API::Types::ObjectID sender,
        NWNXLib::API::CExoString message, NWNXLib::API::Types::ObjectID target, NWNXLib::API::CExoString* tellName);

    NWNXLib::Services::Events::ArgumentStack OnSendMessage(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnRegisterChatScript(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSkipMessage(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetChannel(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetMessage(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetSender(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetTarget(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSetChatHearingDistance(NWNXLib::Services::Events::ArgumentStack&& args);
};

}
