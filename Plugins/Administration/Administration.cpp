#include "Administration.hpp"
#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Globals.hpp"
#include "API/Types.hpp"
#include "API/Version.hpp"
#include "Services/Log/Log.hpp"
#include "ViewPtr.hpp"
#include <cstdlib>

using namespace NWNXLib;

static ViewPtr<Administration::Administration> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Administration",
        "Provides functionality to administrate a server.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Administration::Administration(params);
    return g_plugin;
}

using namespace NWNXLib::API;
using namespace NWNXLib::Services;

namespace Administration {

Administration::Administration(const Plugin::CreateParams& params)
    : Plugin(params)
{

#define REGISTER(name, func) \
    GetServices()->m_events->RegisterEvent(name, std::bind(&Administration::func, this, std::placeholders::_1))

    REGISTER("GET_PLAYER_PASSWORD",   OnGetPlayerPassword);
    REGISTER("SET_PLAYER_PASSWORD",   OnSetPlayerPassword);
    REGISTER("CLEAR_PLAYER_PASSWORD", OnClearPlayerPassword);
    REGISTER("GET_DM_PASSWORD",       OnGetDMPassword);
    REGISTER("SET_DM_PASSWORD",       OnSetDMPassword);
    REGISTER("SHUTDOWN_SERVER",       OnShutdownServer);
    REGISTER("BOOT_PC_WITH_MESSAGE",  OnBootPCWithMessage);

#undef REGISTER
}

Administration::~Administration()
{
}

Events::ArgumentStack Administration::OnGetPlayerPassword(Events::ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerPassword();
    GetServices()->m_log->Debug("Returned player password '%s'.", password.m_sString);
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, std::string(password.m_sString));
    return stack;
}

Events::ArgumentStack Administration::OnSetPlayerPassword(Events::ArgumentStack&& args)
{
    const auto newPass = Events::ExtractArgument<std::string>(args);
    GetServices()->m_log->Notice("Set player password to '%s'.", newPass.c_str());
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword(newPass.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnClearPlayerPassword(Events::ArgumentStack&&)
{
    GetServices()->m_log->Notice("Cleared player password.");
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword("");
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnGetDMPassword(Events::ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetGameMasterPassword();
    GetServices()->m_log->Debug("Returned DM password '%s'.", password.m_sString);
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, std::string(password.m_sString));
    return stack;
}

Events::ArgumentStack Administration::OnSetDMPassword(Events::ArgumentStack&& args)
{
    const auto newPass = Events::ExtractArgument<std::string>(args);
    GetServices()->m_log->Notice("Set DM password to '%s'.", newPass.c_str());
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetGameMasterPassword(newPass.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnShutdownServer(Events::ArgumentStack&&)
{
    GetServices()->m_log->Notice("Shutting down the server!");
    std::quick_exit(0);
}

Events::ArgumentStack Administration::OnBootPCWithMessage(Events::ArgumentStack&& args)
{
    const auto objectId = Events::ExtractArgument<Types::ObjectID>(args);
    const auto strref = static_cast<uint32_t>(Events::ExtractArgument<int32_t>(args));

    CServerExoApp* exoApp = Globals::AppManager()->m_pServerExoApp;
    CNWSPlayer* player = exoApp->GetClientObjectByObjectId(objectId);

    if (!player)
    {
        throw std::runtime_error("Attempted to boot invalid player.");
    }

    g_plugin->GetServices()->m_log->Notice("Booting player '0x%08x' for strref '%i'.", player->m_nPlayerID, strref);
    exoApp->GetNetLayer()->DisconnectPlayer(player->m_nPlayerID, strref, 1);
    return Events::ArgumentStack();
}

}
