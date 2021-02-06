#include "Feedback.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Feedback::Feedback* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Feedback::Feedback(services);
    return g_plugin;
}


namespace Feedback {

static NWNXLib::Hooks::Hook s_SendFeedbackMessageHook = nullptr;
static NWNXLib::Hooks::Hook s_SendServerToPlayerCCMessageHook = nullptr;
static NWNXLib::Hooks::Hook s_SendServerToPlayerJournalUpdatedHook = nullptr;

const int32_t FEEDBACK_MESSAGE = 0;
const int32_t COMBATLOG_MESSAGE = 1;
const int32_t JOURNALUPDATED_MESSAGE = 2;

Feedback::Feedback(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetMessageHidden);
    REGISTER(SetMessageHidden);
    REGISTER(SetFeedbackMode);

#undef REGISTER

    s_SendFeedbackMessageHook = Hooks::HookFunction(
            API::Functions::_ZN12CNWSCreature19SendFeedbackMessageEtP16CNWCCMessageDataP10CNWSPlayer,
            (void*)&SendFeedbackMessageHook, Hooks::Order::Late);

    s_SendServerToPlayerCCMessageHook = Hooks::HookFunction(
            API::Functions::_ZN11CNWSMessage27SendServerToPlayerCCMessageEjhP16CNWCCMessageDataP20CNWSCombatAttackData,
            (void*)&SendServerToPlayerCCMessageHook, Hooks::Order::Late);

    s_SendServerToPlayerJournalUpdatedHook = Hooks::HookFunction(
            API::Functions::_ZN11CNWSMessage32SendServerToPlayerJournalUpdatedEP10CNWSPlayerii13CExoLocString,
            (void*)&SendServerToPlayerJournalUpdatedHook, Hooks::Order::Late);
}

Feedback::~Feedback()
{
}

void Feedback::SendFeedbackMessageHook(CNWSCreature *pCreature, uint16_t nFeedbackID, CNWCCMessageData *pMessageData , CNWSPlayer *pFeedbackPlayer)
{
    auto personalState = GetPersonalState(pCreature->m_idSelf, FEEDBACK_MESSAGE, nFeedbackID);
    auto bSuppressFeedback = (personalState == -1) ? GetGlobalState(FEEDBACK_MESSAGE, nFeedbackID) : personalState;

    if (g_plugin->m_FeedbackMessageWhitelist == bSuppressFeedback)
    {
        s_SendFeedbackMessageHook->CallOriginal<void>(pCreature, nFeedbackID, pMessageData, pFeedbackPlayer);
    }
    else
    {
        // SendFeedbackMessage passes ownership of pData
        delete pMessageData;
    }
}

int32_t Feedback::SendServerToPlayerCCMessageHook(CNWSMessage *pMessage, uint32_t nPlayerId, uint8_t nMinor, CNWCCMessageData *pMessageData, CNWSCombatAttackData *pAttackData)
{
    uint32_t oidPlayer = static_cast<CNWSPlayer*>(Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayerId, 0))->m_oidPCObject;

    auto personalState = GetPersonalState(oidPlayer, COMBATLOG_MESSAGE, nMinor);
    auto bSuppressFeedback = (personalState == -1) ? GetGlobalState(COMBATLOG_MESSAGE, nMinor) : personalState;

    return g_plugin->m_CombatMessageWhitelist != bSuppressFeedback ? false : s_SendServerToPlayerCCMessageHook->CallOriginal<int32_t>(pMessage, nPlayerId, nMinor, pMessageData, pAttackData);
}

int32_t Feedback::SendServerToPlayerJournalUpdatedHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, int32_t bQuest, int32_t bCompleted, CExoLocString locName)
{
    auto personalState = GetPersonalState(pPlayer->m_oidNWSObject, JOURNALUPDATED_MESSAGE, 0);
    auto bSuppressFeedback = (personalState == -1) ? GetGlobalState(JOURNALUPDATED_MESSAGE, 0) : personalState;

    return bSuppressFeedback ? false : s_SendServerToPlayerJournalUpdatedHook->CallOriginal<int32_t>(pMessage, pPlayer, bQuest, bCompleted, locName);
}

bool Feedback::GetGlobalState(int32_t messageType, int32_t messageId)
{
    int32_t realMessageId = messageType * 10000 + messageId;

    return g_plugin->m_GlobalHiddenMessageSet.find(realMessageId) != g_plugin->m_GlobalHiddenMessageSet.end();
}

int32_t Feedback::GetPersonalState(ObjectID playerId, int32_t messageType, int32_t messageId)
{
    int32_t value = -1;

    std::string varName = std::to_string(messageType) + ":" + std::to_string(messageId);

    auto playerObj = Utils::GetGameObject(playerId);
    if (auto personalState = playerObj->nwnxGet<int>(varName))
    {
        value = !!*personalState;
    }

    return value;
}

ArgumentStack Feedback::GetMessageHidden(ArgumentStack&& args)
{
    const auto playerId = Events::ExtractArgument<ObjectID>(args);
    const auto messageType = Events::ExtractArgument<int32_t>(args);
    const auto messageId = Events::ExtractArgument<int32_t>(args);

    int32_t retVal = (playerId == Constants::OBJECT_INVALID) ? GetGlobalState(messageType, messageId) :
                                                               GetPersonalState(playerId, messageType, messageId);

    return Events::Arguments(retVal);
}

ArgumentStack Feedback::SetMessageHidden(ArgumentStack&& args)
{
    const auto playerId = Events::ExtractArgument<ObjectID>(args);
    const auto messageType = Events::ExtractArgument<int32_t>(args);
    const auto messageId = Events::ExtractArgument<int32_t>(args);
    const auto state = Events::ExtractArgument<int32_t>(args);

    ASSERT_OR_THROW(messageId >= 0);

    if (playerId == Constants::OBJECT_INVALID)
    {
        int32_t realMessageId = messageType * 10000 + messageId;

        if (!!state)
        {
            g_plugin->m_GlobalHiddenMessageSet.insert(realMessageId);
        }
        else
        {
            auto index = g_plugin->m_GlobalHiddenMessageSet.find(realMessageId);
            if (index != g_plugin->m_GlobalHiddenMessageSet.end())
            {
                g_plugin->m_GlobalHiddenMessageSet.erase(index);
            }
        }
    }
    else
    {
        std::string varName = std::to_string(messageType) + ":" + std::to_string(messageId);
        auto playerObj = Utils::GetGameObject(playerId);
        if (state == -1)
        {
            playerObj->nwnxRemove(varName);
        }
        else
        {
            playerObj->nwnxSet(varName, !!state, true);
        }
    }
    return Events::Arguments();
}

ArgumentStack Feedback::SetFeedbackMode(ArgumentStack&& args)
{
    const auto messageType = Events::ExtractArgument<int32_t>(args);
    const auto state = Events::ExtractArgument<int32_t>(args);

    if (!messageType)
    {
        g_plugin->m_FeedbackMessageWhitelist = !!state;
    }
    else
    {
        g_plugin->m_CombatMessageWhitelist = !!state;
    }

    return Events::Arguments();
}

}
