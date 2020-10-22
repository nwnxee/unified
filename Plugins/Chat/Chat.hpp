#pragma once

#include "Common.hpp"
#include "Plugin.hpp"
#include "API/Constants/Misc.hpp"
#include "Services/Events/Events.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace NWNXLib::Hooking { class FunctionHook; }

namespace Chat {

class Chat : public NWNXLib::Plugin
{
public:
    Chat(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Chat();

private:
    NWNXLib::Hooking::FunctionHook* m_hook;

    NWNXLib::API::Constants::ChatChannel::TYPE m_activeChannel;
    std::string m_activeMessage;
    ObjectID m_activeSenderObjectId;
    ObjectID m_activeTargetObjectId;

    std::string m_chatScript;
    bool m_skipMessage;
    bool m_customHearingDistances;
    std::unordered_map<NWNXLib::API::Constants::ChatChannel::TYPE, float> m_hearingDistances;
    uint32_t m_depth;

    static void SendServerToPlayerChatMessage(CNWSMessage* thisPtr, NWNXLib::API::Constants::ChatChannel::TYPE channel, ObjectID sender,
        CExoString message, ObjectID target, CExoString* tellName);

    ArgumentStack SendMessage               (ArgumentStack&& args);
    ArgumentStack RegisterChatScript        (ArgumentStack&& args);
    ArgumentStack SkipMessage               (ArgumentStack&& args);
    ArgumentStack GetChannel                (ArgumentStack&& args);
    ArgumentStack GetMessage                (ArgumentStack&& args);
    ArgumentStack GetSender                 (ArgumentStack&& args);
    ArgumentStack GetTarget                 (ArgumentStack&& args);
    ArgumentStack SetChatHearingDistance    (ArgumentStack&& args);
    ArgumentStack GetChatHearingDistance    (ArgumentStack&& args);
};

}
