#include "Feedback.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSCombatAttackData.hpp"
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
        "Allows combatlog and feedback messages to be hidden globally or per player",
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

const int32_t FEEDBACK_MESSAGE = 0;
const int32_t COMBATLOG_MESSAGE = 1;
const int32_t JOURNALUPDATED_MESSAGE = 2;

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

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CNWSMessage__SendServerToPlayerCCMessage>(&Feedback::SendServerToPlayerCCMessageHook);
    m_SendServerToPlayerCCMessageHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSMessage__SendServerToPlayerCCMessage);

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CNWSMessage__SendServerToPlayerJournalUpdated>(&Feedback::SendServerToPlayerJournalUpdatedHook);
    m_SendServerToPlayerJournalUpdatedHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSMessage__SendServerToPlayerJournalUpdated);
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
    auto personalState = plugin.GetPersonalState(pCreature->m_idSelf, FEEDBACK_MESSAGE, nFeedbackID);
    bool bSuppressFeedback = (personalState == -1) ? plugin.GetGlobalState(FEEDBACK_MESSAGE, nFeedbackID) : personalState;

    if (!bSuppressFeedback)
    {
        plugin.m_SendFeedbackMessageHook->CallOriginal<void>(pCreature, nFeedbackID, pData, pPlayer);
    }
}

int32_t Feedback::SendServerToPlayerCCMessageHook(
    CNWSMessage* pMessage,
    uint32_t nPlayerId,
    uint8_t nMinor,
    CNWCCMessageData* pMessageData,
    CNWSCombatAttackData* pAttackData)
{
    Feedback& plugin = *g_plugin;
    uint32_t oidPlayer = static_cast<CNWSPlayer*>(Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayerId, 0))->m_oidPCObject;

    auto personalState = plugin.GetPersonalState(oidPlayer, COMBATLOG_MESSAGE, nMinor);
    bool bSuppressFeedback = (personalState == -1) ? plugin.GetGlobalState(COMBATLOG_MESSAGE, nMinor) : personalState;

    return bSuppressFeedback ? false :
                    plugin.m_SendServerToPlayerCCMessageHook->CallOriginal<int32_t>(pMessage, nPlayerId, nMinor, pMessageData, pAttackData);
}

int32_t Feedback::SendServerToPlayerJournalUpdatedHook(
    CNWSMessage* pMessage,
    CNWSPlayer* pPlayer,
    int32_t bQuest,
    int32_t bCompleted,
    CExoLocString* p_locName)
{
   Feedback& plugin = *g_plugin;

    auto personalState = plugin.GetPersonalState(pPlayer->m_oidNWSObject, JOURNALUPDATED_MESSAGE, 0);
    bool bSuppressFeedback = (personalState == -1) ? plugin.GetGlobalState(JOURNALUPDATED_MESSAGE, 0) : personalState;

    return bSuppressFeedback ? false :
                    plugin.m_SendServerToPlayerJournalUpdatedHook->CallOriginal<int32_t>(pMessage, pPlayer, bQuest, bCompleted, p_locName);
}

bool Feedback::GetGlobalState(int32_t messageType, int32_t messageId)
{
    Feedback& plugin = *g_plugin;
    std::set<int32_t>* hiddenMessageSet;
    if (messageType == JOURNALUPDATED_MESSAGE)
        hiddenMessageSet = &plugin.m_GlobalHiddenJournalUpdatedMessageSet;
    else if(messageType == COMBATLOG_MESSAGE)
        hiddenMessageSet = &plugin.m_GlobalHiddenCombatLogMessageSet;
    else
        hiddenMessageSet = &plugin.m_GlobalHiddenFeedbackMessageSet;

    return hiddenMessageSet->find(messageId) != hiddenMessageSet->end();
}

int32_t Feedback::GetPersonalState(Types::ObjectID playerId, int32_t messageType, int32_t messageId)
{
    Feedback& plugin = *g_plugin;
    int32_t value = -1;

    std::string varName = std::to_string(messageType) + ":" + std::to_string(messageId);

    if (auto personalState = plugin.GetServices()->m_perObjectStorage->Get<int>(playerId, varName))
    {
        value = !!*personalState;
    }

    return value;
}

ArgumentStack Feedback::GetMessageHidden(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto messageType = Services::Events::ExtractArgument<int32_t>(args);
    const auto messageId = Services::Events::ExtractArgument<int32_t>(args);

    int32_t retVal = (playerId == Constants::OBJECT_INVALID) ? GetGlobalState(messageType, messageId) :
                                                               GetPersonalState(playerId, messageType, messageId);

    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Feedback::SetMessageHidden(ArgumentStack&& args)
{
    ArgumentStack stack;
    Feedback& plugin = *g_plugin;

    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto messageType = Services::Events::ExtractArgument<int32_t>(args);
    const auto messageId = Services::Events::ExtractArgument<int32_t>(args);
    const auto state = Services::Events::ExtractArgument<int32_t>(args);

    ASSERT_OR_THROW(messageId >= 0);

    if (playerId == Constants::OBJECT_INVALID)
    {
        std::set<int32_t>* hiddenMessageSet;
        if (messageType == JOURNALUPDATED_MESSAGE)
            hiddenMessageSet = &plugin.m_GlobalHiddenJournalUpdatedMessageSet;
        else if(messageType == COMBATLOG_MESSAGE)
            hiddenMessageSet = &plugin.m_GlobalHiddenCombatLogMessageSet;
        else
            hiddenMessageSet = &plugin.m_GlobalHiddenFeedbackMessageSet;

        if (!!state)
        {
            hiddenMessageSet->insert(messageId);
        }
        else
        {
            auto index = hiddenMessageSet->find(messageId);
            if (index != hiddenMessageSet->end())
            {
                hiddenMessageSet->erase(index);
            }
        }
    }
    else
    {
        std::string varName = std::to_string(messageType) + ":" + std::to_string(messageId);

        if (state == -1)
        {
            plugin.GetServices()->m_perObjectStorage->Remove(playerId, varName);
        }
        else
        {
            plugin.GetServices()->m_perObjectStorage->Set(playerId, varName, !!state);
        }
    }

    return stack;
}

}
