#include "Feedback.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "Services/Events/Events.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "ViewPtr.hpp"
#include <set>
#include <string>


using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Feedback::Feedback> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Feedback",
        "Allows feedback messages to be hidden globally or per player",
        "Daz",
        "daztek@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Feedback::Feedback(params);
    return g_plugin;
}


namespace Feedback {

Feedback::Feedback(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Feedback::func, this, std::placeholders::_1))

    REGISTER(GetMessageHidden);
    REGISTER(SetMessageHidden);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CNWSCreature__SendFeedbackMessage>(&Feedback::SendFeedbackMessageHook);
    m_SendFeedbackMessageHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSCreature__SendFeedbackMessage);
}

Feedback::~Feedback()
{
}

void Feedback::SendFeedbackMessageHook(
    CNWSCreature* pCreature, 
    uint16_t nFeedbackID, 
    CNWCCMessageData* pData, 
    CNWSPlayer* pPlayer)
{
    Feedback& plugin = *g_plugin;
    bool bSuppressFeedback = false;
    
    std::string personalStateKeyName = std::string("HIDE_FEEDBACK_MESSAGE:") + std::to_string(nFeedbackID);
    auto personalState = plugin.GetServices()->m_perObjectStorage->Get<int>(pCreature->m_idSelf, personalStateKeyName);

    if (*personalState)
    {// Player has personal state
        bSuppressFeedback = !!personalState;
    }
    else
    {// Check global state
        auto index = plugin.m_GlobalHiddenMessageStateSet.find(nFeedbackID);
        if (index != plugin.m_GlobalHiddenMessageStateSet.end())
        {
            bSuppressFeedback = true;
        }
    }

    if (!bSuppressFeedback)
    {
        plugin.m_SendFeedbackMessageHook->CallOriginal<void>(pCreature, nFeedbackID, pData, pPlayer);
    }
}

ArgumentStack Feedback::GetMessageHidden(ArgumentStack&& args)
{
    ArgumentStack stack;
    Feedback& plugin = *g_plugin;
    int32_t retVal = 0;

    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto messageId = Services::Events::ExtractArgument<int32_t>(args);    
    
    if (playerId == Constants::OBJECT_INVALID)
    {
        auto index = plugin.m_GlobalHiddenMessageStateSet.find(messageId);
        if (index != plugin.m_GlobalHiddenMessageStateSet.end())
        {
            retVal = 1;
        }
    }
    else
    {
        std::string personalStateKeyName = std::string("HIDE_FEEDBACK_MESSAGE:") + std::to_string(messageId);
        auto personalState = plugin.GetServices()->m_perObjectStorage->Get<int>(playerId, personalStateKeyName);
        
        if (*personalState)
        {
            retVal = !!personalState;
        }
        else
        {
            retVal = -1;
        }        
    }

    Services::Events::InsertArgument(stack, retVal);
    
    return stack;
}

ArgumentStack Feedback::SetMessageHidden(ArgumentStack&& args)
{
    ArgumentStack stack;
    Feedback& plugin = *g_plugin;

    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto messageId = Services::Events::ExtractArgument<int32_t>(args);
    const auto hide = Services::Events::ExtractArgument<int32_t>(args);

    if (playerId == Constants::OBJECT_INVALID)
    {
        if (!!hide)
        {
            plugin.m_GlobalHiddenMessageStateSet.insert(messageId);    
        }
        else
        {
            auto index = plugin.m_GlobalHiddenMessageStateSet.find(messageId);
            if (index != plugin.m_GlobalHiddenMessageStateSet.end())
            {
                plugin.m_GlobalHiddenMessageStateSet.erase(index);
            }
        }
    }
    else
    {
        std::string personalStateKeyName = std::string("HIDE_FEEDBACK_MESSAGE:") + std::to_string(messageId);

        if (hide == -1)
        {
            plugin.GetServices()->m_perObjectStorage->Remove(playerId, personalStateKeyName);
        }
        else
        {            
            plugin.GetServices()->m_perObjectStorage->Set(playerId, personalStateKeyName, !!hide);
        }
    }       

    return stack;
}

}
