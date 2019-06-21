#include "Events/LevelEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

LevelEvents::LevelEvents(ViewPtr<HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_LEVEL_UP_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::CNWSCreatureStats__LevelUp, int32_t,
                CNWSCreatureStats*, CNWLevelStats*, uint8_t, uint8_t, uint8_t, int32_t>(&LevelUpHook);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_LEVEL_UP_AUTOMATIC_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::CNWSCreatureStats__LevelUpAutomatic, int32_t,
                CNWSCreatureStats*, uint8_t, int32_t, uint8_t>(&LevelUpAutomaticHook);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_LEVEL_DOWN_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::CNWSCreatureStats__LevelDown, int32_t,
                CNWSCreatureStats*, CNWLevelStats*>(&LevelDownHook);
    });
}

void LevelEvents::LevelUpHook(
        NWNXLib::Services::Hooks::CallType type,
        NWNXLib::API::CNWSCreatureStats* thisPtr,
        NWNXLib::API::CNWLevelStats*,
        uint8_t, uint8_t, uint8_t, int32_t)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;

    Events::SignalEvent(before ? "NWNX_ON_LEVEL_UP_BEFORE" : "NWNX_ON_LEVEL_UP_AFTER",
                        thisPtr->m_pBaseCreature->m_idSelf);
}

void LevelEvents::LevelUpAutomaticHook(
        NWNXLib::Services::Hooks::CallType type,
        NWNXLib::API::CNWSCreatureStats* thisPtr,
        uint8_t, int32_t, uint8_t)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;

    Events::SignalEvent(before ? "NWNX_ON_LEVEL_UP_AUTOMATIC_BEFORE" : "NWNX_ON_LEVEL_UP_AUTOMATIC_AFTER",
                        thisPtr->m_pBaseCreature->m_idSelf);
}

void LevelEvents::LevelDownHook(
            NWNXLib::Services::Hooks::CallType type,
            NWNXLib::API::CNWSCreatureStats* thisPtr,
            NWNXLib::API::CNWLevelStats*)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;

    Events::SignalEvent(before ? "NWNX_ON_LEVEL_DOWN_BEFORE" : "NWNX_ON_LEVEL_DOWN_AFTER",
                        thisPtr->m_pBaseCreature->m_idSelf);
}

}
