#include "Events.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_LevelUpHook;
static Hooks::Hook s_LevelUpAutomaticHook;
static Hooks::Hook s_LevelDownHook;
static Hooks::Hook s_HandlePlayerToServerLevelUpMessageHook;

static void LevelUpHook(CNWSCreatureStats*, CNWLevelStats*, uint8_t, uint8_t, uint8_t, int32_t);
static int32_t LevelUpAutomaticHook(CNWSCreatureStats*, uint8_t, int32_t, uint8_t);
static void LevelDownHook(CNWSCreatureStats*, CNWLevelStats*);
static int32_t HandlePlayerToServerLevelUpMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);

void LevelEvents() __attribute__((constructor));
void LevelEvents()
{
    InitOnFirstSubscribe("NWNX_ON_LEVEL_UP_.*", []() {
        s_LevelUpHook = Hooks::HookFunction(&CNWSCreatureStats::LevelUp,
                                     &LevelUpHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_LEVEL_UP_AUTOMATIC_.*", []() {
        s_LevelUpAutomaticHook= Hooks::HookFunction(&CNWSCreatureStats::LevelUpAutomatic,
                                             &LevelUpAutomaticHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_LEVEL_DOWN_.*", []() {
        s_LevelDownHook = Hooks::HookFunction(&CNWSCreatureStats::LevelDown,
                                       &LevelDownHook, Hooks::Order::Earliest);
    });
    InitOnFirstSubscribe("NWNX_ON_CLIENT_LEVEL_UP_BEGIN_.*", []() {
        s_HandlePlayerToServerLevelUpMessageHook = Hooks::HookFunction(&CNWSMessage::HandlePlayerToServerLevelUpMessage,
                                                                       &HandlePlayerToServerLevelUpMessageHook, Hooks::Order::Early);
    });
}

void LevelUpHook(CNWSCreatureStats *thisPtr, CNWLevelStats *pLevelUpStats, uint8_t nDomain1, uint8_t nDomain2,
                              uint8_t nSchool, int32_t bAddStatsToList)
{
    SignalEvent("NWNX_ON_LEVEL_UP_BEFORE", thisPtr->m_pBaseCreature->m_idSelf);
    s_LevelUpHook->CallOriginal<void>(thisPtr, pLevelUpStats, nDomain1, nDomain2, nSchool, bAddStatsToList);
    SignalEvent("NWNX_ON_LEVEL_UP_AFTER", thisPtr->m_pBaseCreature->m_idSelf);
}

int32_t LevelUpAutomaticHook(CNWSCreatureStats *thisPtr, uint8_t nClass, int32_t bReadyAllSpells, uint8_t nPackage)
{
    SignalEvent("NWNX_ON_LEVEL_UP_AUTOMATIC_BEFORE", thisPtr->m_pBaseCreature->m_idSelf);
    auto retVal = s_LevelUpAutomaticHook->CallOriginal<int32_t>(thisPtr, nClass, bReadyAllSpells, nPackage);
    SignalEvent("NWNX_ON_LEVEL_UP_AUTOMATIC_AFTER", thisPtr->m_pBaseCreature->m_idSelf);
    return retVal;
}

void LevelDownHook(CNWSCreatureStats *thisPtr, CNWLevelStats *pLevelUpStats)
{
    SignalEvent("NWNX_ON_LEVEL_DOWN_BEFORE", thisPtr->m_pBaseCreature->m_idSelf);
    s_LevelDownHook->CallOriginal<void>(thisPtr, pLevelUpStats);
    SignalEvent("NWNX_ON_LEVEL_DOWN_AFTER", thisPtr->m_pBaseCreature->m_idSelf);
}

int32_t HandlePlayerToServerLevelUpMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    if (nMinor == Constants::MessageLevelUpMinor::Begin)
    {
        int32_t retVal = false;
        if (SignalEvent("NWNX_ON_CLIENT_LEVEL_UP_BEGIN_BEFORE", pPlayer->m_oidNWSObject))
        {
            retVal = s_HandlePlayerToServerLevelUpMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
        }

        SignalEvent("NWNX_ON_CLIENT_LEVEL_UP_BEGIN_AFTER", pPlayer->m_oidNWSObject);

        return retVal;
    }
    else
        return s_HandlePlayerToServerLevelUpMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
}

}
