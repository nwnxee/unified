#pragma once

#include "nwnx.hpp"
#include "API/Constants/Misc.hpp"
using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Chat {

class Chat : public NWNXLib::Plugin
{
public:
    Chat(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Chat();

private:
    NWNXLib::Hooks::Hook m_hook;

    uint8_t m_activeChannel;
    std::string m_activeMessage;
    ObjectID m_activeSenderObjectId;
    ObjectID m_activeTargetObjectId;

    std::string m_chatScript;
    bool m_skipMessage;
    bool m_customHearingDistances;
    std::unordered_map<uint8_t, float> m_hearingDistances;
    uint32_t m_depth;

    static int32_t SendServerToPlayerChatMessage(CNWSMessage*, uint8_t, ObjectID, CExoString, ObjectID, const CExoString&);

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
