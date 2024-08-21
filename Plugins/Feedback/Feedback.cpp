#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWCCMessageData.hpp"
#include <set>


using namespace NWNXLib;
using namespace NWNXLib::API;

static std::set<int32_t> s_GlobalHiddenMessageSet;
static bool s_FeedbackMessageWhitelist = false;
static bool s_CombatMessageWhitelist = false;
constexpr int32_t FEEDBACK_MESSAGE = 0;
constexpr int32_t COMBATLOG_MESSAGE = 1;
constexpr int32_t JOURNALUPDATED_MESSAGE = 2;

static bool GetGlobalState(int32_t, int32_t);
static int32_t GetPersonalState(ObjectID, int32_t, int32_t);
static void SendFeedbackMessageHook(CNWSCreature*, uint16_t, CNWCCMessageData*, CNWSPlayer*);
static int32_t SendServerToPlayerCCMessageHook(CNWSMessage*, uint32_t, uint8_t, CNWCCMessageData*, CNWSCombatAttackData*);
static int32_t SendServerToPlayerJournalUpdatedHook(CNWSMessage*, CNWSPlayer*, int32_t, int32_t, CExoLocString);


static NWNXLib::Hooks::Hook s_SendFeedbackMessageHook = Hooks::HookFunction(
    &CNWSCreature::SendFeedbackMessage,
    &SendFeedbackMessageHook, Hooks::Order::Late);

static NWNXLib::Hooks::Hook s_SendServerToPlayerCCMessageHook = Hooks::HookFunction(
    &CNWSMessage::SendServerToPlayerCCMessage,
    &SendServerToPlayerCCMessageHook, Hooks::Order::Late);

static NWNXLib::Hooks::Hook s_SendServerToPlayerJournalUpdatedHook = Hooks::HookFunction(
     &CNWSMessage::SendServerToPlayerJournalUpdated,
     &SendServerToPlayerJournalUpdatedHook, Hooks::Order::Late);


static void SendFeedbackMessageHook(CNWSCreature *pCreature, uint16_t nFeedbackID, CNWCCMessageData *pMessageData , CNWSPlayer *pFeedbackPlayer)
{
    auto personalState = GetPersonalState(pCreature->m_idSelf, FEEDBACK_MESSAGE, nFeedbackID);
    auto bSuppressFeedback = (personalState == -1) ? GetGlobalState(FEEDBACK_MESSAGE, nFeedbackID) : personalState;

    if (s_FeedbackMessageWhitelist == bSuppressFeedback)
    {
        s_SendFeedbackMessageHook->CallOriginal<void>(pCreature, nFeedbackID, pMessageData, pFeedbackPlayer);
    }
    else
    {
        // SendFeedbackMessage passes ownership of pData
        delete pMessageData;
    }
}

static int32_t SendServerToPlayerCCMessageHook(CNWSMessage *pMessage, uint32_t nPlayerId, uint8_t nMinor, CNWCCMessageData *pMessageData, CNWSCombatAttackData *pAttackData)
{
    auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayerId);
    if (!pPlayer)
        return s_SendServerToPlayerCCMessageHook->CallOriginal<int32_t>(pMessage, nPlayerId, nMinor, pMessageData, pAttackData);

    auto personalState = GetPersonalState(pPlayer->m_oidPCObject, COMBATLOG_MESSAGE, nMinor);
    auto bSuppressFeedback = (personalState == -1) ? GetGlobalState(COMBATLOG_MESSAGE, nMinor) : personalState;

    return s_CombatMessageWhitelist != bSuppressFeedback ? false : s_SendServerToPlayerCCMessageHook->CallOriginal<int32_t>(pMessage, nPlayerId, nMinor, pMessageData, pAttackData);
}

static int32_t SendServerToPlayerJournalUpdatedHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, int32_t bQuest, int32_t bCompleted, CExoLocString locName)
{
    auto personalState = GetPersonalState(pPlayer->m_oidNWSObject, JOURNALUPDATED_MESSAGE, 0);
    auto bSuppressFeedback = (personalState == -1) ? GetGlobalState(JOURNALUPDATED_MESSAGE, 0) : personalState;

    return bSuppressFeedback ? false : s_SendServerToPlayerJournalUpdatedHook->CallOriginal<int32_t>(pMessage, pPlayer, bQuest, bCompleted, locName);
}

static bool GetGlobalState(int32_t messageType, int32_t messageId)
{
    int32_t realMessageId = messageType * 10000 + messageId;

    return s_GlobalHiddenMessageSet.find(realMessageId) != s_GlobalHiddenMessageSet.end();
}

static int32_t GetPersonalState(ObjectID playerId, int32_t messageType, int32_t messageId)
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


NWNX_EXPORT ArgumentStack GetMessageHidden(ArgumentStack&& args)
{
    const auto playerId = args.extract<ObjectID>();
    const auto messageType = args.extract<int32_t>();
    const auto messageId = args.extract<int32_t>();

    int32_t retVal = (playerId == Constants::OBJECT_INVALID) ? GetGlobalState(messageType, messageId) :
                                                               GetPersonalState(playerId, messageType, messageId);

    return retVal;
}

NWNX_EXPORT ArgumentStack SetMessageHidden(ArgumentStack&& args)
{
    const auto playerId = args.extract<ObjectID>();
    const auto messageType = args.extract<int32_t>();
    const auto messageId = args.extract<int32_t>();
      ASSERT_OR_THROW(messageId >= 0);
    const auto state = args.extract<int32_t>();

    if (playerId == Constants::OBJECT_INVALID)
    {
        int32_t realMessageId = messageType * 10000 + messageId;

        if (!!state)
        {
            s_GlobalHiddenMessageSet.insert(realMessageId);
        }
        else
        {
            auto index = s_GlobalHiddenMessageSet.find(realMessageId);
            if (index != s_GlobalHiddenMessageSet.end())
            {
                s_GlobalHiddenMessageSet.erase(index);
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
    return {};
}

NWNX_EXPORT ArgumentStack SetFeedbackMode(ArgumentStack&& args)
{
    const auto messageType = args.extract<int32_t>();
    const auto state = args.extract<int32_t>();

    if (!messageType)
        s_FeedbackMessageWhitelist = !!state;
    else
        s_CombatMessageWhitelist = !!state;

    return {};
}
