
// Log currently generates warnings when no arguments are given to format string
// TODO: Should really clean up the log so it doesn't warn in these cases
#pragma GCC diagnostic ignored "-Wformat-security"

#include "Player.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSObject.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSScriptVar.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/CExoArrayListTemplatedCNWSScriptVar.hpp"
//#include "API/CNWSCreatureStats.hpp"
//#include "API/CNWLevelStats.hpp"
//#include "API/CNWSStats_Spell.hpp"
//#include "API/CNWSStats_SpellLikeAbility.hpp"
//#include "API/CExoArrayListTemplatedCNWSStats_SpellLikeAbility.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Log/Log.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Player::Player> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Player",
        "Functions exposing additional player properties and commands",
        "various / sherincall",
        "sherincall@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Player::Player(params);
    return g_plugin;
}


namespace Player {

Player::Player(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Player::func, this, std::placeholders::_1))

    REGISTER(ForcePlaceableExamineWindow);
    REGISTER(StartGuiTimingBar);
    REGISTER(StopGuiTimingBar);

#undef REGISTER

    GetServices()->m_hooks->RequestSharedHook
        <Functions::CNWSMessage__HandlePlayerToServerInputCancelGuiTimingEvent,
            void, CNWSMessage*, CNWSPlayer*>(&HandlePlayerToServerInputCancelGuiTimingEventHook);

}

Player::~Player()
{
}

CNWSPlayer *Player::player(ArgumentStack& args)
{
    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (playerId == Constants::OBJECT_INVALID)
    {
        GetServices()->m_log->Notice("NWNX_Player function called on OBJECT_INVALID");
        return 0;
    }

    auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(playerId);
    if (!pPlayer)
    {
        GetServices()->m_log->Notice("NWNX_Player function called on non-player object %x", playerId);
    }
    return pPlayer;
}

ArgumentStack Player::ForcePlaceableExamineWindow(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto placeableId = Services::Events::ExtractArgument<Types::ObjectID>(args);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerExamineGui_PlaceableData(pPlayer, placeableId);
        }
        else
        {
            GetServices()->m_log->Error("Unable to get CNWSMessage");
        }
    }

    return stack;
}

ArgumentStack Player::StartGuiTimingBar(ArgumentStack&& args)
{
    ArgumentStack stack;
    if(auto *pPlayer = player(args))
    {
        const float seconds = Services::Events::ExtractArgument<float>(args);
        const uint32_t milliseconds = static_cast<uint32_t>(seconds * 1000.0f); // NWN expects milliseconds.

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if(pMessage)
        {
            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, true, 10, milliseconds);
        }
        else 
        {
            GetServices()->m_log->Error("Unable to get CNWSMessage");
        }
    }

    return stack;
}

ArgumentStack Player::StopGuiTimingBar(ArgumentStack&& args)
{
    ArgumentStack stack;
    if(auto *pPlayer = player(args))
    {
        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if(pMessage)
        {
            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, false, 10, 0);
        }
        else 
        {
            GetServices()->m_log->Error("Unable to get CNWSMessage");
        }
        
    }

    return stack;
}


void Player::HandlePlayerToServerInputCancelGuiTimingEventHook(Services::Hooks::CallType type, CNWSMessage* pMessage, CNWSPlayer* pPlayer)
{
    // Before or after doesn't matter, just pick one so it happens only once
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        CNWSObject *pGameObject = static_cast<CNWSObject*>(Globals::AppManager()->m_pServerExoApp->GetGameObject(pPlayer->m_oidPCObject));

        CExoString varName = "NWNX_PLAYER_GUI_TIMING_ACTIVE";
        int32_t id = pGameObject->m_ScriptVars.GetInt(varName);

        if (id > 0)
        {
            g_plugin->GetServices()->m_log->Debug("Cancelling GUI timing event id %d...", id);
            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, false, 10, 0);
            pGameObject->m_ScriptVars.DestroyInt(varName);
        }
    }
}
}
