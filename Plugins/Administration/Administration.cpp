#include "Administration.hpp"
#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CResRef.hpp"
#include "API/Globals.hpp"
#include "API/Types.hpp"
#include "API/Version.hpp"
#include "ViewPtr.hpp"
#include "Platform/FileSystem.hpp"
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

    REGISTER("GET_PLAYER_PASSWORD",           OnGetPlayerPassword);
    REGISTER("SET_PLAYER_PASSWORD",           OnSetPlayerPassword);
    REGISTER("CLEAR_PLAYER_PASSWORD",         OnClearPlayerPassword);
    REGISTER("GET_DM_PASSWORD",               OnGetDMPassword);
    REGISTER("SET_DM_PASSWORD",               OnSetDMPassword);
    REGISTER("SHUTDOWN_SERVER",               OnShutdownServer);
    REGISTER("DELETE_PLAYER_CHARACTER",       OnDeletePlayerCharacter);

#undef REGISTER
}

Administration::~Administration()
{
}

Events::ArgumentStack Administration::OnGetPlayerPassword(Events::ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerPassword();
    TRACE_DEBUG("Returned player password '%s'.", password.m_sString);
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, std::string(password.m_sString));
    return stack;
}

Events::ArgumentStack Administration::OnSetPlayerPassword(Events::ArgumentStack&& args)
{
    const auto newPass = Events::ExtractArgument<std::string>(args);
    TRACE_NOTICE("Set player password to '%s'.", newPass.c_str());
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword(newPass.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnClearPlayerPassword(Events::ArgumentStack&&)
{
    TRACE_NOTICE("Cleared player password.");
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword("");
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnGetDMPassword(Events::ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetGameMasterPassword();
    TRACE_DEBUG("Returned DM password '%s'.", password.m_sString);
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, std::string(password.m_sString));
    return stack;
}

Events::ArgumentStack Administration::OnSetDMPassword(Events::ArgumentStack&& args)
{
    const auto newPass = Events::ExtractArgument<std::string>(args);
    TRACE_NOTICE("Set DM password to '%s'.", newPass.c_str());
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetGameMasterPassword(newPass.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnShutdownServer(Events::ArgumentStack&&)
{
    TRACE_NOTICE("Shutting down the server!");
    std::quick_exit(0);
}

Events::ArgumentStack Administration::OnDeletePlayerCharacter(Events::ArgumentStack&& args)
{
    const auto objectId = Events::ExtractArgument<Types::ObjectID>(args);
    const auto bPreserveBackup = static_cast<bool>(Events::ExtractArgument<int32_t>(args));

    CServerExoApp* exoApp = Globals::AppManager()->m_pServerExoApp;
    CNWSPlayer* player = exoApp->GetClientObjectByObjectId(objectId);

    if (!player)
    {
        TRACE_ERROR("Attempted to delete invalid player");
        return Events::ArgumentStack();
    }
    std::string bicname     = player->m_resFileName.GetResRefStr();
    std::string servervault = CExoString(Globals::ExoBase()->m_pcExoAliasList->GetAliasPath("SERVERVAULT", 0)).CStr();
    std::string cdkey       = exoApp->GetNetLayer()->GetPlayerInfo(player->m_nPlayerID)->GetPublicCDKey(0).CStr();

    std::string filename = servervault + cdkey + "/" + bicname + ".bic";

    TRACE_NOTICE("Deleting %s %s", filename.c_str(), bPreserveBackup ? "(backed up)" : "(no backup)");

    // Will show "Delete Character" message to PC. Best match from dialog.tlk
    exoApp->GetNetLayer()->DisconnectPlayer(player->m_nPlayerID, 10392, 1, "");

    if (!Platform::FileSystem::FileExists(filename))
    {
        TRACE_ERROR("File %s not found.", filename.c_str());
        return Events::ArgumentStack();
    }
    if (bPreserveBackup)
    {
        std::string backup = filename + ".deleted";
        int i = 0;
        while (Platform::FileSystem::FileExists(backup + std::to_string(i)))
            i++;
        Platform::FileSystem::RenameFile(filename, backup + std::to_string(i));
    }
    else
    {
        Platform::FileSystem::RemoveFile(filename);
    }
    return Events::ArgumentStack();
}

}
