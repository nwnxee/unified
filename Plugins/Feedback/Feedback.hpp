#pragma once

#include "nwnx.hpp"
#include <set>

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Feedback {

class Feedback : public NWNXLib::Plugin
{
public:
    Feedback(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Feedback();

private:
    ArgumentStack GetMessageHidden          (ArgumentStack&& args);
    ArgumentStack SetMessageHidden          (ArgumentStack&& args);
    ArgumentStack SetFeedbackMode           (ArgumentStack&& args);

    static void SendFeedbackMessageHook(
        CNWSCreature* pCreature,
        uint16_t nFeedbackID,
        CNWCCMessageData* pData,
        CNWSPlayer* pPlayer);

    static int32_t SendServerToPlayerCCMessageHook(
        CNWSMessage* pMessage,
        uint32_t nPlayerId,
        uint8_t nMinor,
        CNWCCMessageData* pMessageData,
        CNWSCombatAttackData* pAttackData);

    static int32_t SendServerToPlayerJournalUpdatedHook(
        CNWSMessage* pMessage,
        CNWSPlayer* pPlayer,
        int32_t bQuest,
        int32_t bCompleted,
        CExoLocString locName);

    static bool GetGlobalState(int32_t messageType, int32_t messageId);
    static int32_t GetPersonalState(ObjectID playerId, int32_t messageType, int32_t messageId);

    std::set<int32_t> m_GlobalHiddenMessageSet;
    bool m_FeedbackMessageWhitelist = false;
    bool m_CombatMessageWhitelist = false;
};

}
