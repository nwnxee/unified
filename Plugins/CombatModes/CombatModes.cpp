#include "CombatModes.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "API/Types.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "ViewPtr.hpp"
#include "Utils.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<CombatModes::CombatModes> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "CombatModes",
        "Dispatches Combat Mode toggle events.",
        "Daz",
        "daztek@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new CombatModes::CombatModes(params);
    return g_plugin;
}

namespace CombatModes {

static Hooking::FunctionHook* g_SetCombatModeHook = nullptr;

CombatModes::CombatModes(const Plugin::CreateParams& params)
    : Plugin(params)
{
    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CNWSCreature__SetCombatMode, void, API::CNWSCreature*, uint8_t, int32_t>(&SetCombatModeHook);
    g_SetCombatModeHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSCreature__SetCombatMode);
}

CombatModes::~CombatModes()
{
}

void CombatModes::SetCombatModeHook(API::CNWSCreature* thisPtr, uint8_t nNewMode, int32_t bForceNewMode)
{
    if (thisPtr->m_bPlayerCharacter) 
    {
        const uint8_t nCurrentMode = thisPtr->m_nCombatMode;

        if( nCurrentMode != nNewMode)
        {
            auto messaging = g_plugin->GetServices()->m_messaging.get();
            
            if (nCurrentMode != 0)
            {
                 messaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", { "MODE", std::to_string(nCurrentMode) } );
                 messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT", { "NWNX_ON_MODE_OFF", NWNXLib::Utils::ObjectIDToString(thisPtr->m_idSelf) });
            }

            if (nNewMode != 0)
            {
                messaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", { "MODE", std::to_string(nNewMode) } );
                messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT", { "NWNX_ON_MODE_ON", NWNXLib::Utils::ObjectIDToString(thisPtr->m_idSelf) });
            }
        }
    }

    return g_SetCombatModeHook->CallOriginal<void>(thisPtr, nNewMode, bForceNewMode);
}

}