#include "Events/LevelEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_LevelUpHook;
static Hooks::Hook s_LevelUpAutomaticHook;
static Hooks::Hook s_LevelDownHook;
static Hooks::Hook s_HandlePlayerToServerLevelUpMessageHook;

LevelEvents::LevelEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_LEVEL_UP_.*", []() {
        s_LevelUpHook = Hooks::HookFunction(API::Functions::_ZN17CNWSCreatureStats7LevelUpEP13CNWLevelStatshhhi,
                                     (void*)&LevelUpHook, Hooks::Order::Earliest);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_LEVEL_UP_AUTOMATIC_.*", []() {
        s_LevelUpAutomaticHook= Hooks::HookFunction(API::Functions::_ZN17CNWSCreatureStats16LevelUpAutomaticEhih,
                                             (void*)&LevelUpAutomaticHook, Hooks::Order::Earliest);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_LEVEL_DOWN_.*", []() {
        s_LevelDownHook = Hooks::HookFunction(API::Functions::_ZN17CNWSCreatureStats9LevelDownEP13CNWLevelStats,
                                       (void*)&LevelDownHook, Hooks::Order::Earliest);
    });
    Events::InitOnFirstSubscribe("NWNX_ON_CLIENT_LEVEL_UP_BEGIN_.*", []() {
        s_HandlePlayerToServerLevelUpMessageHook = Hooks::HookFunction(API::Functions::_ZN11CNWSMessage34HandlePlayerToServerLevelUpMessageEP10CNWSPlayerh,
                                                                       (void*)&HandlePlayerToServerLevelUpMessageHook, Hooks::Order::Early);
    });
}

void LevelEvents::LevelUpHook(CNWSCreatureStats *thisPtr, CNWLevelStats *pLevelUpStats, uint8_t nDomain1, uint8_t nDomain2,
                              uint8_t nSchool, int32_t bAddStatsToList)
{
    Events::SignalEvent("NWNX_ON_LEVEL_UP_BEFORE", thisPtr->m_pBaseCreature->m_idSelf);
    s_LevelUpHook->CallOriginal<void>(thisPtr, pLevelUpStats, nDomain1, nDomain2, nSchool, bAddStatsToList);
    Events::SignalEvent("NWNX_ON_LEVEL_UP_AFTER", thisPtr->m_pBaseCreature->m_idSelf);
}

int32_t LevelEvents::LevelUpAutomaticHook(CNWSCreatureStats *thisPtr, uint8_t nClass, int32_t bReadyAllSpells, uint8_t nPackage)
{
    Events::SignalEvent("NWNX_ON_LEVEL_UP_AUTOMATIC_BEFORE", thisPtr->m_pBaseCreature->m_idSelf);
    auto retVal = s_LevelUpAutomaticHook->CallOriginal<int32_t>(thisPtr, nClass, bReadyAllSpells, nPackage);
    Events::SignalEvent("NWNX_ON_LEVEL_UP_AUTOMATIC_AFTER", thisPtr->m_pBaseCreature->m_idSelf);
    return retVal;
}

void LevelEvents::LevelDownHook(CNWSCreatureStats *thisPtr, CNWLevelStats *pLevelUpStats)
{
    Events::SignalEvent("NWNX_ON_LEVEL_DOWN_BEFORE", thisPtr->m_pBaseCreature->m_idSelf);
    s_LevelDownHook->CallOriginal<void>(thisPtr, pLevelUpStats);
    Events::SignalEvent("NWNX_ON_LEVEL_DOWN_AFTER", thisPtr->m_pBaseCreature->m_idSelf);
}

int32_t LevelEvents::HandlePlayerToServerLevelUpMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    if (nMinor == Constants::MessageLevelUpMinor::Begin)
    {
        int32_t retVal = false;
        if (Events::SignalEvent("NWNX_ON_CLIENT_LEVEL_UP_BEGIN_BEFORE", pPlayer->m_oidNWSObject))
        {
            retVal = s_HandlePlayerToServerLevelUpMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
        }

        Events::SignalEvent("NWNX_ON_CLIENT_LEVEL_UP_BEGIN_AFTER", pPlayer->m_oidNWSObject);

        return retVal;
    }
    else
        return s_HandlePlayerToServerLevelUpMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
}

}
