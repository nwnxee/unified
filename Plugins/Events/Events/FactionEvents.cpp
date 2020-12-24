#include "Events/FactionEvents.hpp"
#include "API/CNWSModule.hpp"
#include "API/CFactionManager.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

    using namespace NWNXLib;
    using namespace NWNXLib::API;

    static NWNXLib::Hooking::FunctionHook* s_HandleSetNPCFactionReputationHook;

    FactionEvents::FactionEvents(Services::HooksProxy* hooker)
    {
        Events::InitOnFirstSubscribe("NWNX_ON_SET_NPC_FACTION_REPUTATION_.*", [hooker]() {
            s_HandleSetNPCFactionReputationHook = hooker->RequestExclusiveHook
                <API::Functions::_ZN15CFactionManager23SetNPCFactionReputationEiii>
                (&HandleSetNPCFactionReputationHook);
            });
    }

    void FactionEvents::HandleSetNPCFactionReputationHook(CFactionManager* thisPtr, int32_t nFactionId, int32_t nSubjectFactionId, int32_t nReputation)
    {
        int32_t previousReputation = thisPtr->GetNPCFactionReputation(nSubjectFactionId, nFactionId);

        auto PushAndSignalEvent = [&](const std::string& env, std::string* envResult) -> bool {
            Events::PushEventData("FACTION_ID", std::to_string(nFactionId));
            Events::PushEventData("SUBJECT_FACTION_ID", std::to_string(nSubjectFactionId));
            Events::PushEventData("PREVIOUS_REPUTATION", std::to_string(previousReputation));
            Events::PushEventData("NEW_REPUTATION", std::to_string(nReputation));

            return Events::SignalEvent(env, Utils::GetModule()->m_idSelf, envResult);
        };

        std::string result;
        if (PushAndSignalEvent("NWNX_ON_SET_NPC_FACTION_REPUTATION_BEFORE", &result))
        {
            s_HandleSetNPCFactionReputationHook->CallOriginal<void>(thisPtr, nFactionId, nSubjectFactionId, nReputation);
        }
        else if (auto nResult = Utils::from_string<int32_t>(result))
        {
            nReputation = nResult.value();
            s_HandleSetNPCFactionReputationHook->CallOriginal<void>(thisPtr, nFactionId, nSubjectFactionId, nReputation);
        }

        PushAndSignalEvent("NWNX_ON_SET_NPC_FACTION_REPUTATION_AFTER", nullptr);
    }
}
