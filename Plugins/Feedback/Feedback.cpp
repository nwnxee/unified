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

    REGISTER(GetFeedbackMessageHidden);
    REGISTER(SetFeedbackMessageHidden);

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
    auto personalState = plugin.GetPersonalState(pCreature->m_idSelf, nFeedbackID);
    bool bSuppressFeedback = (personalState == -1) ? plugin.GetGlobalState(nFeedbackID) : personalState;
    
    if (!bSuppressFeedback)
    {
        plugin.m_SendFeedbackMessageHook->CallOriginal<void>(pCreature, nFeedbackID, pData, pPlayer);
    }
}

bool Feedback::GetGlobalState(int32_t messageId)
{
    Feedback& plugin = *g_plugin;

    return plugin.m_GlobalHiddenMessageStateSet.find(messageId) != plugin.m_GlobalHiddenMessageStateSet.end();
}

int32_t Feedback::GetPersonalState(Types::ObjectID playerId, int32_t messageId)
{
    Feedback& plugin = *g_plugin;
    int32_t value = -1;

    if (auto personalState = plugin.GetServices()->m_perObjectStorage->Get<int>(playerId, std::to_string(messageId)))
        value = !!*personalState;

    return value;    
}

ArgumentStack Feedback::GetFeedbackMessageHidden(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto messageId = Services::Events::ExtractArgument<int32_t>(args);    
    
    int32_t retVal = (playerId == Constants::OBJECT_INVALID) ? GetGlobalState(messageId) : GetPersonalState(playerId, messageId);

    Services::Events::InsertArgument(stack, retVal);
    
    return stack;
}

ArgumentStack Feedback::SetFeedbackMessageHidden(ArgumentStack&& args)
{
    ArgumentStack stack;
    Feedback& plugin = *g_plugin;

    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto messageId = Services::Events::ExtractArgument<int32_t>(args);
    const auto state = Services::Events::ExtractArgument<int32_t>(args);

    if (playerId == Constants::OBJECT_INVALID)
    {
        if (!!state)
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
        if (state == -1)
        {
            plugin.GetServices()->m_perObjectStorage->Remove(playerId, std::to_string(messageId));
        }
        else
        {            
            plugin.GetServices()->m_perObjectStorage->Set(playerId, std::to_string(messageId), !!state);
        }
    }       

    return stack;
}

}
