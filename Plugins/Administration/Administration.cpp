#include "Administration.hpp"
#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CResRef.hpp"
#include "API/CServerInfo.hpp"
#include "API/Globals.hpp"
#include "API/Types.hpp"
#include "API/Version.hpp"
#include "ViewPtr.hpp"
#include "Platform/FileSystem.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "Services/Patching/Patching.hpp"
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
    REGISTER("ADD_BANNED_IP",                 OnAddBannedIP);
    REGISTER("REMOVE_BANNED_IP",              OnRemoveBannedIP);
    REGISTER("ADD_BANNED_CDKEY",              OnAddBannedCDKey);
    REGISTER("REMOVE_BANNED_CDKEY",           OnRemoveBannedCDKey);
    REGISTER("ADD_BANNED_PLAYER_NAME",        OnAddBannedPlayerName);
    REGISTER("REMOVE_BANNED_PLAYER_NAME",     OnRemoveBannedPlayerName);
    REGISTER("GET_BANNED_LIST",               OnGetBannedList);
    REGISTER("SET_MODULE_NAME",               OnSetModuleName);
    REGISTER("SET_SERVER_NAME",               OnSetServereName);

#undef REGISTER

    // HACK! Allow player names up to 127 characters in length. Temporary until fixed in base game.
    GetServices()->m_patching->PatchWithValue(0x5651f, (uint8_t)0x7F); NWNX_EXPECT_VERSION(8166);
}

Administration::~Administration()
{
}

Events::ArgumentStack Administration::OnGetPlayerPassword(Events::ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerPassword();
    LOG_DEBUG("Returned player password '%s'.", password.m_sString);
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, std::string(password.m_sString));
    return stack;
}

Events::ArgumentStack Administration::OnSetPlayerPassword(Events::ArgumentStack&& args)
{
    const auto newPass = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Set player password to '%s'.", newPass.c_str());
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword(newPass.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnClearPlayerPassword(Events::ArgumentStack&&)
{
    LOG_NOTICE("Cleared player password.");
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword("");
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnGetDMPassword(Events::ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetGameMasterPassword();
    LOG_DEBUG("Returned DM password '%s'.", password.m_sString);
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, std::string(password.m_sString));
    return stack;
}

Events::ArgumentStack Administration::OnSetDMPassword(Events::ArgumentStack&& args)
{
    const auto newPass = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Set DM password to '%s'.", newPass.c_str());
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetGameMasterPassword(newPass.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnShutdownServer(Events::ArgumentStack&&)
{
    LOG_NOTICE("Shutting down the server!");
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
        LOG_ERROR("Attempted to delete invalid player");
        return Events::ArgumentStack();
    }
    API::Types::PlayerID playerId = player->m_nPlayerID;

    std::string bicname     = player->m_resFileName.GetResRefStr();
    std::string servervault = CExoString(Globals::ExoBase()->m_pcExoAliasList->GetAliasPath("SERVERVAULT", 0)).CStr();
    std::string playerdir;
    if (exoApp->GetServerInfo()->m_PersistantWorldOptions.bServerVaultByPlayerName)
    {
        playerdir = player->GetPlayerName().CStr();
    }
    else
    {
        playerdir = exoApp->GetNetLayer()->GetPlayerInfo(playerId)->GetPublicCDKey(0).CStr();
    }

    std::string filename = servervault + playerdir + "/" + bicname + ".bic";

    LOG_NOTICE("Deleting %s %s", filename.c_str(), bPreserveBackup ? "(backed up)" : "(no backup)");

    if (!Platform::FileSystem::FileExists(filename))
    {
        LOG_ERROR("File %s not found.", filename.c_str());
        return Events::ArgumentStack();
    }

    GetServices()->m_tasks->QueueOnMainThread(
        [filename, playerId, bPreserveBackup]
        {
            // Will show "Delete Character" message to PC. Best match from dialog.tlk
            Globals::AppManager()->m_pServerExoApp->GetNetLayer()->DisconnectPlayer(playerId, 10392, 1, "");

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
        });

    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnAddBannedIP(Events::ArgumentStack&& args)
{
    const auto ip = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Banning IP %s", ip.c_str());
    Globals::AppManager()->m_pServerExoApp->AddIPToBannedList(ip.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnRemoveBannedIP(Events::ArgumentStack&& args)
{
    const auto ip = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Unbanning IP %s", ip.c_str());
    Globals::AppManager()->m_pServerExoApp->RemoveIPFromBannedList(ip.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnAddBannedCDKey(Events::ArgumentStack&& args)
{
    const auto key = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Banning CDKey %s", key.c_str());
    Globals::AppManager()->m_pServerExoApp->AddCDKeyToBannedList(key.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnRemoveBannedCDKey(Events::ArgumentStack&& args)
{
    const auto key = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Unbanning CDKey %s", key.c_str());
    Globals::AppManager()->m_pServerExoApp->RemoveCDKeyFromBannedList(key.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnAddBannedPlayerName(Events::ArgumentStack&& args)
{
    const auto playername = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Banning Player name %s", playername.c_str());
    Globals::AppManager()->m_pServerExoApp->AddPlayerNameToBannedList(playername.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnRemoveBannedPlayerName(Events::ArgumentStack&& args)
{
    const auto playername = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Unbanning Player name %s", playername.c_str());
    Globals::AppManager()->m_pServerExoApp->RemovePlayerNameFromBannedList(playername.c_str());
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnGetBannedList(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;

    std::string list = Globals::AppManager()->m_pServerExoApp->GetBannedListString().CStr();
    Events::InsertArgument(stack, list);
    return stack;
}

Events::ArgumentStack Administration::OnSetModuleName(Events::ArgumentStack&& args)
{
    const auto newName = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Set module name to '%s'.", newName.c_str());
    Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pServerInfo->m_sModuleName = newName.c_str();
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnSetServereName(Events::ArgumentStack&& args)
{
    const auto newName = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Set server name to '%s'.", newName.c_str());
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetSessionName(CExoString(newName.c_str()));
    return Events::ArgumentStack();
}

}
