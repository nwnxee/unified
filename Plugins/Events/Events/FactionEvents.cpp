#include "Events.hpp"
#include "API/CNWSModule.hpp"
#include "API/CFactionManager.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooks::Hook s_HandleSetNPCFactionReputationHook;

static void HandleSetNPCFactionReputationHook(CFactionManager*, int32_t, int32_t, int32_t);

void FactionEvents() __attribute__((constructor));
void FactionEvents()
{
    InitOnFirstSubscribe("NWNX_ON_SET_NPC_FACTION_REPUTATION_.*", []() {
        s_HandleSetNPCFactionReputationHook = Hooks::HookFunction(API::Functions::_ZN15CFactionManager23SetNPCFactionReputationEiii,
                                                           (void*)&HandleSetNPCFactionReputationHook, Hooks::Order::Early);
        });
}

void HandleSetNPCFactionReputationHook(CFactionManager* thisPtr, int32_t nFactionId, int32_t nSubjectFactionId, int32_t nReputation)
{
    int32_t previousReputation = thisPtr->GetNPCFactionReputation(nSubjectFactionId, nFactionId);

    auto PushAndSignalEvent = [&](const std::string& env, std::string* envResult) -> bool {
        PushEventData("FACTION_ID", std::to_string(nFactionId));
        PushEventData("SUBJECT_FACTION_ID", std::to_string(nSubjectFactionId));
        PushEventData("PREVIOUS_REPUTATION", std::to_string(previousReputation));
        PushEventData("NEW_REPUTATION", std::to_string(nReputation));

        return SignalEvent(env, Utils::GetModule()->m_idSelf, envResult);
    };

    std::string result;
    if (PushAndSignalEvent("NWNX_ON_SET_NPC_FACTION_REPUTATION_BEFORE", &result))
    {
        s_HandleSetNPCFactionReputationHook->CallOriginal<void>(thisPtr, nFactionId, nSubjectFactionId, nReputation);
    }
    else if (auto nResult = String::FromString<int32_t>(result))
    {
        nReputation = nResult.value();
        s_HandleSetNPCFactionReputationHook->CallOriginal<void>(thisPtr, nFactionId, nSubjectFactionId, nReputation);
    }

    PushAndSignalEvent("NWNX_ON_SET_NPC_FACTION_REPUTATION_AFTER", nullptr);
}

}
