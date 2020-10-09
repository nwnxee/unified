#include "CombatModes.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Utils.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static CombatModes::CombatModes* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new CombatModes::CombatModes(services);
    return g_plugin;
}

namespace CombatModes {

static Hooking::FunctionHook* s_SetCombatModeHook;

CombatModes::CombatModes(Services::ProxyServiceList* services)
    : Plugin(services), m_Skipped(false), m_FlurryOfBlows(false)
{
    s_SetCombatModeHook = GetServices()->m_hooks->RequestExclusiveHook<API::Functions::_ZN12CNWSCreature13SetCombatModeEhi, void, CNWSCreature*, uint8_t, int32_t>(&SetCombatModeHook);

    GetServices()->m_messaging->SubscribeMessage("NWNX_EVENT_SIGNAL_EVENT_SKIPPED",
        [this](const std::vector<std::string>& message)
        {
            if (message[0] == "NWNX_ON_COMBAT_MODE_ON" || message[0] == "NWNX_ON_COMBAT_MODE_OFF")
                this->m_Skipped = std::strtoul(message[1].c_str(), NULL, 0) == 1;
        });

    GetServices()->m_messaging->SubscribeMessage("NWNX_WEAPON_SIGNAL",
        [this](const std::vector<std::string>& message)
        {
            if (message[0] == "FLURRY_OF_BLOWS_REQUIRED")
                this->m_FlurryOfBlows = true;
        });
}

CombatModes::~CombatModes()
{
}

void CombatModes::SetCombatModeHook(CNWSCreature* thisPtr, uint8_t nNewMode, int32_t bForceNewMode)
{
    //If Weapon plugin recquires flurry of blows
    if(g_plugin->m_FlurryOfBlows)
    {
        //flurry of blows automatic cancel
        if(nNewMode == CombatMode::None && bForceNewMode && thisPtr->m_nCombatMode == CombatMode::FlurryOfBlows)
        {
            if(thisPtr->m_pStats->GetUseMonkAttackTables(0))
            {
                return;
            }
        }

        //flurry of blows manual cancel
        if(nNewMode == CombatMode::FlurryOfBlows && !bForceNewMode)
        {
            nNewMode = CombatMode::None;
            bForceNewMode = 1;
        }
    }

    if (thisPtr->m_bPlayerCharacter)
    {
        const uint8_t nCurrentMode = thisPtr->m_nCombatMode;

        if( nCurrentMode != nNewMode)
        {
            auto messaging = g_plugin->GetServices()->m_messaging.get();

            if (nCurrentMode != CombatMode::None)
            {
                 messaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", { "COMBAT_MODE_ID", std::to_string(nCurrentMode) } );
                 messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT", { "NWNX_ON_COMBAT_MODE_OFF", NWNXLib::Utils::ObjectIDToString(thisPtr->m_idSelf) });
            }

            if (nNewMode != CombatMode::None)
            {
                messaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", { "COMBAT_MODE_ID", std::to_string(nNewMode) } );
                messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT", { "NWNX_ON_COMBAT_MODE_ON", NWNXLib::Utils::ObjectIDToString(thisPtr->m_idSelf) });
            }
        }
    }

    if (!g_plugin->m_Skipped)
    {
        //flurry of blows manual activation
        if(g_plugin->m_FlurryOfBlows && nNewMode == CombatMode::FlurryOfBlows && bForceNewMode)
        {
            if(thisPtr->m_pStats->GetUseMonkAttackTables(0))
            {
                thisPtr->m_nCombatMode = CombatMode::FlurryOfBlows;
                thisPtr->SetActivity(0x4000,1);
                return;
            }
        }
        return s_SetCombatModeHook->CallOriginal<void>(thisPtr, nNewMode, bForceNewMode);
    }
}

}
