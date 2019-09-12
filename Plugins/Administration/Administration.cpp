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
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSPlayerTURD.hpp"
#include "ViewPtr.hpp"
#include "Platform/FileSystem.hpp"
#include "Services/Tasks/Tasks.hpp"
#include <cstdlib>
#include <unistd.h>
#include <signal.h>

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
    REGISTER("SET_SERVER_NAME",               OnSetServerName);
    REGISTER("GET_PLAY_OPTION",               OnGetPlayOption);
    REGISTER("SET_PLAY_OPTION",               OnSetPlayOption);
    REGISTER("DELETE_TURD",                   OnDeleteTURD);

#undef REGISTER
}

Administration::~Administration()
{
}

Events::ArgumentStack Administration::OnGetPlayerPassword(Events::ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerPassword();
    LOG_DEBUG("Returned player password '%s'.", password.m_sString);
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, std::string(password.m_sString ? password.m_sString : ""));
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
    Events::InsertArgument(stack, std::string(password.m_sString ? password.m_sString : ""));
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
    if (kill(getpid(), SIGTERM) != 0)
    {
      LOG_ERROR("Shutdown failed: SIGTERM signal not sent successfully");
    }
    return Events::ArgumentStack();
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
        playerdir = exoApp->GetNetLayer()->GetPlayerInfo(playerId)->m_lstKeys[0].sPublic.CStr();
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

Events::ArgumentStack Administration::OnSetServerName(Events::ArgumentStack&& args)
{
    const auto newName = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Set server name to '%s'.", newName.c_str());
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetSessionName(CExoString(newName.c_str()));
    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnGetPlayOption(Events::ArgumentStack&& args)
{
    Events::ArgumentStack stack;
    int32_t retVal = -1;

    const auto option = Events::ExtractArgument<int32_t>(args);

    ASSERT_OR_THROW(option >= 0); ASSERT_OR_THROW(option <= 26);

    switch (option)
    {
        case 0: // NWNX_ADMINISTRATION_OPTION_ALL_KILLABLE
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bAllKillable;
            break;

        case 1: // NWNX_ADMINISTRATION_OPTION_NON_PARTY_KILLABLE
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bNonPartyKillable;
            break;

        case 2: // NWNX_ADMINISTRATION_OPTION_REQUIRE_RESURRECTION
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bRequireResurrection;
            break;

        case 3: // NWNX_ADMINISTRATION_OPTION_LOSE_STOLEN_ITEMS
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bLoseStolenItems;
            break;

        case 4: // NWNX_ADMINISTRATION_OPTION_LOSE_ITEMS
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bLoseItems;
            break;

        case 5: // NWNX_ADMINISTRATION_OPTION_LOSE_EXP
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bLoseExp;
            break;

        case 6: // NWNX_ADMINISTRATION_OPTION_LOSE_GOLD
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bLoseGold;
            break;

        case 7: // NWNX_ADMINISTRATION_OPTION_LOSE_GOLD_NUM
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.nLoseGoldNum;
            break;

        case 8: // NWNX_ADMINISTRATION_OPTION_LOSE_EXP_NUM
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.nLoseExpNum;
            break;

        case 9: // NWNX_ADMINISTRATION_OPTION_LOSE_ITEMS_NUM
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.nLoseItemsNum;
            break;

        case 10: // NWNX_ADMINISTRATION_OPTION_PVP_SETTING
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.nPVPSetting;
            break;

        case 11: // NWNX_ADMINISTRATION_OPTION_PAUSE_AND_PLAY
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bPauseAndPlay;
            break;

        case 12: // NWNX_ADMINISTRATION_OPTION_ONE_PARTY_ONLY
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bOnePartyOnly;
            break;

        case 13: // NWNX_ADMINISTRATION_OPTION_ENFORCE_LEGAL_CHARACTERS
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bEnforceLegalCharacters;
            break;

        case 14: // NWNX_ADMINISTRATION_OPTION_ITEM_LEVEL_RESTRICTIONS
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bItemLevelRestrictions;
            break;

        case 15: // NWNX_ADMINISTRATION_OPTION_CDKEY_BANLIST_ALLOWLIST
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bCDKeyBanListAllowList;
            break;

        case 16: // NWNX_ADMINISTRATION_OPTION_DISALLOW_SHOUTING
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bDisallowShouting;
            break;

        case 17: // NWNX_ADMINISTRATION_OPTION_SHOW_DM_JOIN_MESSAGE
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bShowDMJoinMessage;
            break;

        case 18: // NWNX_ADMINISTRATION_OPTION_BACKUP_SAVED_CHARACTERS
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bBackupSavedCharacters;
            break;

        case 19: // NWNX_ADMINISTRATION_OPTION_AUTO_FAIL_SAVE_ON_1
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bAutoFailSaveOn1;
            break;

        case 20: // NWNX_ADMINISTRATION_OPTION_VALIDATE_SPELLS
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bValidateSpells;
            break;

        case 21: // NWNX_ADMINISTRATION_OPTION_EXAMINE_EFFECTS
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bExamineEffects;
            break;

        case 22: // NWNX_ADMINISTRATION_OPTION_EXAMINE_CHALLENGE_RATING
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bExamineChallengeRating;
            break;

        case 23: // NWNX_ADMINISTRATION_OPTION_USE_MAX_HITPOINTS
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bUseMaxHitPoints;
            break;

        case 24: // NWNX_ADMINISTRATION_OPTION_RESTORE_SPELLS_USES
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bRestoreSpellsUses;
            break;

        case 25: // NWNX_ADMINISTRATION_OPTION_RESET_ENCOUNTER_SPAWN_POOL
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bResetEncounterSpawnPool;
            break;

        case 26: // NWNX_ADMINISTRATION_OPTION_HIDE_HITPOINTS_GAINED
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bHideHitPointsGained;
            break;

        default:
            LOG_NOTICE("Calling NWNX_Administration_GetPlayOption with invalid option: %d", option);
            break;
    }

    Events::InsertArgument(stack, retVal);

    return stack;
}

Events::ArgumentStack Administration::OnSetPlayOption(Events::ArgumentStack&& args)
{
    const auto option = Events::ExtractArgument<int32_t>(args);
    const auto value = Events::ExtractArgument<int32_t>(args);

    ASSERT_OR_THROW(option >= 0); ASSERT_OR_THROW(option <= 26);
    ASSERT_OR_THROW(value >= 0);

    switch (option)
    {
        case 0: // NWNX_ADMINISTRATION_OPTION_ALL_KILLABLE
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bAllKillable = !!value;
            break;

        case 1: // NWNX_ADMINISTRATION_OPTION_NON_PARTY_KILLABLE
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bNonPartyKillable = !!value;
            break;

        case 2: // NWNX_ADMINISTRATION_OPTION_REQUIRE_RESURRECTION
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bRequireResurrection = !!value;
            break;

        case 3: // NWNX_ADMINISTRATION_OPTION_LOSE_STOLEN_ITEMS
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bLoseStolenItems = !!value;
            break;

        case 4: // NWNX_ADMINISTRATION_OPTION_LOSE_ITEMS
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bLoseItems = !!value;
            break;

        case 5: // NWNX_ADMINISTRATION_OPTION_LOSE_EXP
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bLoseExp = !!value;
            break;

        case 6: // NWNX_ADMINISTRATION_OPTION_LOSE_GOLD
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bLoseGold = !!value;
            break;

        case 7: // NWNX_ADMINISTRATION_OPTION_LOSE_GOLD_NUM
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.nLoseGoldNum = value;
            break;

        case 8: // NWNX_ADMINISTRATION_OPTION_LOSE_EXP_NUM
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.nLoseExpNum = value;
            break;

        case 9: // NWNX_ADMINISTRATION_OPTION_LOSE_ITEMS_NUM
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.nLoseItemsNum = value;
            break;

        case 10: // NWNX_ADMINISTRATION_OPTION_PVP_SETTING
        {
            ASSERT_OR_THROW(value <= 2);
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.nPVPSetting = value;
            break;
        }

        case 11: // NWNX_ADMINISTRATION_OPTION_PAUSE_AND_PLAY
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bPauseAndPlay = !!value;
            break;

        case 12: // NWNX_ADMINISTRATION_OPTION_ONE_PARTY_ONLY
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bOnePartyOnly = !!value;
            break;

        case 13: // NWNX_ADMINISTRATION_OPTION_ENFORCE_LEGAL_CHARACTERS
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bEnforceLegalCharacters = !!value;
            break;

        case 14: // NWNX_ADMINISTRATION_OPTION_ITEM_LEVEL_RESTRICTIONS
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bItemLevelRestrictions = !!value;
            break;

        case 15: // NWNX_ADMINISTRATION_OPTION_CDKEY_BANLIST_ALLOWLIST
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bCDKeyBanListAllowList = !!value;
            break;

        case 16: // NWNX_ADMINISTRATION_OPTION_DISALLOW_SHOUTING
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bDisallowShouting = !!value;
            break;

        case 17: // NWNX_ADMINISTRATION_OPTION_SHOW_DM_JOIN_MESSAGE
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bShowDMJoinMessage = !!value;
            break;

        case 18: // NWNX_ADMINISTRATION_OPTION_BACKUP_SAVED_CHARACTERS
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bBackupSavedCharacters = !!value;
            break;

        case 19: // NWNX_ADMINISTRATION_OPTION_AUTO_FAIL_SAVE_ON_1
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bAutoFailSaveOn1 = !!value;
            break;

        case 20: // NWNX_ADMINISTRATION_OPTION_VALIDATE_SPELLS
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bValidateSpells = !!value;
            break;

        case 21: // NWNX_ADMINISTRATION_OPTION_EXAMINE_EFFECTS
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bExamineEffects = !!value;
            break;

        case 22: // NWNX_ADMINISTRATION_OPTION_EXAMINE_CHALLENGE_RATING
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bExamineChallengeRating = !!value;
            break;

        case 23: // NWNX_ADMINISTRATION_OPTION_USE_MAX_HITPOINTS
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bUseMaxHitPoints = !!value;
            break;

        case 24: // NWNX_ADMINISTRATION_OPTION_RESTORE_SPELLS_USES
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bRestoreSpellsUses = !!value;
            break;

        case 25: // NWNX_ADMINISTRATION_OPTION_RESET_ENCOUNTER_SPAWN_POOL
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bResetEncounterSpawnPool = !!value;
            break;

        case 26: // NWNX_ADMINISTRATION_OPTION_HIDE_HITPOINTS_GAINED
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bHideHitPointsGained = !!value;
            break;

        default:
            LOG_NOTICE("Calling NWNX_Administration_SetPlayOption with invalid option: %d", option);
            break;
    }

    return Events::ArgumentStack();
}

Events::ArgumentStack Administration::OnDeleteTURD(Events::ArgumentStack&& args)
{
    const auto playerName = Events::ExtractArgument<std::string>(args);
    const auto characterName = Events::ExtractArgument<std::string>(args);

    ASSERT_OR_THROW(!playerName.empty());
    ASSERT_OR_THROW(!characterName.empty());

    CExoLinkedListNode *foundNode = nullptr;

    auto *turds = Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal;
    for (auto *node = turds->pHead; node; node = node->pNext)
    {
        auto *turd = static_cast<CNWSPlayerTURD*>(node->pObject);

        if (turd)
        {
            std::string turdCharacterName = Utils::ExtractLocString(turd->m_lsFirstName);
            std::string turdLastName = Utils::ExtractLocString(turd->m_lsLastName);

            if (!turdLastName.empty())
            {
                turdCharacterName += turdCharacterName.empty() ? turdLastName : " " + turdLastName;
            }

            if (turd->m_sCommunityName.CStr() == playerName &&
                characterName == turdCharacterName)
            {
                foundNode = node;
                break;
            }
        }
    }

    if (foundNode)
    {
        LOG_NOTICE("Deleted TURD of %s (%s)", characterName.c_str(), playerName.c_str());
        Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal->Remove(foundNode);
    }

    return Events::ArgumentStack();
}

}
