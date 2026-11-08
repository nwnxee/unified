#include "Events.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/Functions.hpp"

#include <vector>

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_SpawnIfAppropriateHook;
static Hooks::Hook s_SpawnEncounterCreaturesHook;
static Hooks::Hook s_EncounterAIUpdateHook;

static void SpawnIfAppropriateHook(CNWSEncounter*, ObjectID, float);
static void SpawnEncounterCreaturesHook(CNWSEncounter*);
static void EncounterAIUpdateHook(CNWSEncounter*);

void EncounterEvents() __attribute__((constructor));
void EncounterEvents()
{
    // An object entered the encounter area; the engine is about to decide whether to spawn.
    InitOnFirstSubscribe("NWNX_ON_ENCOUNTER_TRIGGER_.*", []() {
        s_SpawnIfAppropriateHook = Hooks::HookFunction(&CNWSEncounter::SpawnIfAppropriate,
                                                       &SpawnIfAppropriateHook, Hooks::Order::Early);
    });

    // The engine has decided to spawn: fires for the first spawn and for every respawn.
    InitOnFirstSubscribe("NWNX_ON_ENCOUNTER_SPAWN_.*", []() {
        s_SpawnEncounterCreaturesHook = Hooks::HookFunction(&CNWSEncounter::SpawnEncounterCreatures,
                                                            &SpawnEncounterCreaturesHook, Hooks::Order::Early);
    });

    // The encounter has been reset (re-armed) after its reset time elapsed.
    // There is no dedicated engine function for this: it happens inside AIUpdate, so we diff the state.
    InitOnFirstSubscribe("NWNX_ON_ENCOUNTER_RESET_.*", []() {
        s_EncounterAIUpdateHook = Hooks::HookFunction(API::Functions::_ZN13CNWSEncounter8AIUpdateEv,
                                                      (void*)&EncounterAIUpdateHook, Hooks::Order::Early);
    });
}

void SpawnIfAppropriateHook(CNWSEncounter *pThis, ObjectID oidEntered, float fFakeEnemyRadiusLevels)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("ENTERED", Utils::ObjectIDToString(oidEntered));
        PushEventData("ACTIVE", std::to_string(pThis->m_bActive));
        PushEventData("STARTED", std::to_string(pThis->m_bEncounterStarted));
        PushEventData("EXHAUSTED", std::to_string(pThis->m_bEncounterExhausted));
        PushEventData("NUM_SPAWNED", std::to_string(pThis->m_nNumSpawnedCreatures));
        return SignalEvent(ev, pThis->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ENCOUNTER_TRIGGER_BEFORE"))
        s_SpawnIfAppropriateHook->CallOriginal<void>(pThis, oidEntered, fFakeEnemyRadiusLevels);

    PushAndSignal("NWNX_ON_ENCOUNTER_TRIGGER_AFTER");
}

void SpawnEncounterCreaturesHook(CNWSEncounter *pThis)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("LAST_ENTERED", Utils::ObjectIDToString(pThis->m_oidLastEntered));
        PushEventData("RESPAWNS_CURRENT", std::to_string(pThis->m_nRespawnsCurrent));
        PushEventData("RESPAWNS_MAX", std::to_string(pThis->m_nRespawnsMax));
        PushEventData("NUM_SPAWNED", std::to_string(pThis->m_nNumSpawnedCreatures));
        return SignalEvent(ev, pThis->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_ENCOUNTER_SPAWN_BEFORE"))
        s_SpawnEncounterCreaturesHook->CallOriginal<void>(pThis);

    PushAndSignal("NWNX_ON_ENCOUNTER_SPAWN_AFTER");
}

// State touched by an encounter reset. The reset happens inside AIUpdate, so it is
// detected by comparing a snapshot taken before and after the call.
struct EncounterResetState
{
    BOOL bActive;
    BOOL bStarted;
    BOOL bExhausted;
    int32_t nRespawnsCurrent;
    int32_t nNumSpawnedCreatures;
    float fSpawnPool;
    float fSpawnPoolActive;
    std::vector<BOOL> vAlreadyUsed;

    void Save(const CNWSEncounter *pEncounter)
    {
        bActive = pEncounter->m_bActive;
        bStarted = pEncounter->m_bEncounterStarted;
        bExhausted = pEncounter->m_bEncounterExhausted;
        nRespawnsCurrent = pEncounter->m_nRespawnsCurrent;
        nNumSpawnedCreatures = pEncounter->m_nNumSpawnedCreatures;
        fSpawnPool = pEncounter->m_fSpawnPool;
        fSpawnPoolActive = pEncounter->m_fSpawnPoolActive;
        vAlreadyUsed.clear();
        for (int32_t i = 0; i < pEncounter->m_nNumEncounterListEntries; i++)
            vAlreadyUsed.push_back(pEncounter->m_pEncounterList[i].m_bAlreadyUsed);
    }

    // Write to pEncounter only the fields where `this` differs from `other`.
    void ApplyChanges(CNWSEncounter *pEncounter, const EncounterResetState& other) const
    {
        if (bActive != other.bActive) pEncounter->m_bActive = bActive;
        if (bStarted != other.bStarted) pEncounter->m_bEncounterStarted = bStarted;
        if (bExhausted != other.bExhausted) pEncounter->m_bEncounterExhausted = bExhausted;
        if (nRespawnsCurrent != other.nRespawnsCurrent) pEncounter->m_nRespawnsCurrent = nRespawnsCurrent;
        if (nNumSpawnedCreatures != other.nNumSpawnedCreatures) pEncounter->m_nNumSpawnedCreatures = nNumSpawnedCreatures;
        if (fSpawnPool != other.fSpawnPool) pEncounter->m_fSpawnPool = fSpawnPool;
        if (fSpawnPoolActive != other.fSpawnPoolActive) pEncounter->m_fSpawnPoolActive = fSpawnPoolActive;
        const auto nEntries = std::min<size_t>({vAlreadyUsed.size(), other.vAlreadyUsed.size(), (size_t)pEncounter->m_nNumEncounterListEntries});
        for (size_t i = 0; i < nEntries; i++)
            if (vAlreadyUsed[i] != other.vAlreadyUsed[i])
                pEncounter->m_pEncounterList[i].m_bAlreadyUsed = vAlreadyUsed[i];
    }

    bool IsResetFrom(const EncounterResetState& before) const
    {
        return (before.bStarted && !bStarted) ||
               (before.bExhausted && !bExhausted) ||
               (!before.bActive && bActive);
    }
};

void EncounterAIUpdateHook(CNWSEncounter *pThis)
{
    EncounterResetState before, after;
    before.Save(pThis);

    s_EncounterAIUpdateHook->CallOriginal<void>(pThis);

    after.Save(pThis);
    if (!after.IsResetFrom(before))
        return;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("RESPAWNS_CURRENT", std::to_string(pThis->m_nRespawnsCurrent));
        PushEventData("RESPAWNS_MAX", std::to_string(pThis->m_nRespawnsMax));
        return SignalEvent(ev, pThis->m_idSelf);
    };

    // Roll back so the _BEFORE event sees the encounter as it was before the reset.
    before.ApplyChanges(pThis, after);

    if (PushAndSignal("NWNX_ON_ENCOUNTER_RESET_BEFORE"))
    {
        // Re-apply only what the reset changed, keeping any change made by the _BEFORE script.
        after.ApplyChanges(pThis, before);
    }

    PushAndSignal("NWNX_ON_ENCOUNTER_RESET_AFTER");
}

}
