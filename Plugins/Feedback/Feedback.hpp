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
    ArgumentStack SetFeedbackMode           (ArgumentStack&& args);

    static void SendFeedbackMessageHook(
        NWNXLib::API::CNWSCreature* pCreature,
        uint16_t nFeedbackID,
        NWNXLib::API::CNWCCMessageData* pData,
        NWNXLib::API::CNWSPlayer* pPlayer);

    static int32_t SendServerToPlayerCCMessageHook(
        NWNXLib::API::CNWSMessage* pMessage,
        uint32_t nPlayerId,
        uint8_t nMinor,
        NWNXLib::API::CNWCCMessageData* pMessageData,
        NWNXLib::API::CNWSCombatAttackData* pAttackData);

    static int32_t SendServerToPlayerJournalUpdatedHook(
        NWNXLib::API::CNWSMessage* pMessage,
        NWNXLib::API::CNWSPlayer* pPlayer,
        int32_t bQuest,
        int32_t bCompleted,
        NWNXLib::API::CExoLocString* p_locName);

    static bool GetGlobalState(int32_t messageType, int32_t messageId);
    static int32_t GetPersonalState(NWNXLib::API::Types::ObjectID playerId, int32_t messageType, int32_t messageId);

    std::set<int32_t> m_GlobalHiddenMessageSet;
    bool m_FeedbackMessageWhitelist = false;
    bool m_CombatMessageWhitelist = false;
};

}
