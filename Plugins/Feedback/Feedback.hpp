#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <set>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Feedback {

class Feedback : public NWNXLib::Plugin
{
public:
    Feedback(const Plugin::CreateParams& params);
    virtual ~Feedback();

private:
    ArgumentStack GetMessageHidden          (ArgumentStack&& args);
    ArgumentStack SetMessageHidden          (ArgumentStack&& args);

    static void SendFeedbackMessageHook(
        NWNXLib::API::CNWSCreature* pCreature, 
        uint16_t nFeedbackID, 
        NWNXLib::API::CNWCCMessageData* pData, 
        NWNXLib::API::CNWSPlayer* pPlayer); 
    
    NWNXLib::Hooking::FunctionHook* m_SendFeedbackMessageHook;
    std::set<int32_t> m_GlobalHiddenMessageStateSet;     
};

}
