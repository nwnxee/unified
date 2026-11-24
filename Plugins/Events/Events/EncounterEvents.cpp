#include "Events.hpp"
#include "API/CNWSEncounter.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_SpawnIfAppropriateHook;
static Hooks::Hook s_SpawnEncounterCreaturesHook;

static void SpawnIfAppropriateHook(CNWSEncounter*, ObjectID, float);
static void SpawnEncounterCreaturesHook(CNWSEncounter*);

void EncounterEvents() __attribute__((constructor));
void EncounterEvents()
{
    // The engine is about to decide whether to spawn: an object entered the encounter area, or the
    // encounter was (re)activated or DM-spawned, in which case there is no entering object.
    InitOnFirstSubscribe("NWNX_ON_ENCOUNTER_TRIGGER_.*", []() {
        s_SpawnIfAppropriateHook = Hooks::HookFunction(&CNWSEncounter::SpawnIfAppropriate,
                                                       &SpawnIfAppropriateHook, Hooks::Order::Early);
    });

    // The engine has decided to spawn: fires for the first spawn and for every respawn.
    InitOnFirstSubscribe("NWNX_ON_ENCOUNTER_SPAWN_.*", []() {
        s_SpawnEncounterCreaturesHook = Hooks::HookFunction(&CNWSEncounter::SpawnEncounterCreatures,
                                                            &SpawnEncounterCreaturesHook, Hooks::Order::Early);
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
    else
    {
        // Nothing spawned, so nothing will die to clear the flag: clear it so the next entry gets another try.
        pThis->m_bEncounterStarted = false;
    }

    PushAndSignal("NWNX_ON_ENCOUNTER_SPAWN_AFTER");
}

}
