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
#include "API/CServerInfo.hpp"
#include "API/CNWSRules.hpp"
#include "API/Globals.hpp"
#include "API/Types.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSPlayerTURD.hpp"
#include "Services/Tasks/Tasks.hpp"

#include <unistd.h>
#include <csignal>

using namespace NWNXLib;

static Administration::Administration* g_plugin;

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

#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetPlayerPassword);
    REGISTER(SetPlayerPassword);
    REGISTER(ClearPlayerPassword);
    REGISTER(GetDMPassword);
    REGISTER(SetDMPassword);
    REGISTER(ShutdownServer);
    REGISTER(DeletePlayerCharacter);
    REGISTER(AddBannedIP);
    REGISTER(RemoveBannedIP);
    REGISTER(AddBannedCDKey);
    REGISTER(RemoveBannedCDKey);
    REGISTER(AddBannedPlayerName);
    REGISTER(RemoveBannedPlayerName);
    REGISTER(GetBannedList);
    REGISTER(SetModuleName);
    REGISTER(SetServerName);
    REGISTER(GetServerName);
    REGISTER(GetPlayOption);
    REGISTER(SetPlayOption);
    REGISTER(DeleteTURD);
    REGISTER(GetDebugValue);
    REGISTER(SetDebugValue);
    REGISTER(ReloadRules);

#undef REGISTER
}

Administration::~Administration()
{
}

Events::ArgumentStack Administration::GetPlayerPassword(Events::ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerPassword();
    LOG_DEBUG("Returned player password '%s'.", password.m_sString);
    return Events::Arguments(std::string(password.m_sString ? password.m_sString : ""));
}

Events::ArgumentStack Administration::SetPlayerPassword(Events::ArgumentStack&& args)
{
    const auto newPass = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Set player password to '%s'.", newPass);
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword(newPass.c_str());
    return Events::Arguments();
}

Events::ArgumentStack Administration::ClearPlayerPassword(Events::ArgumentStack&&)
{
    LOG_NOTICE("Cleared player password.");
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword("");
    return Events::Arguments();
}

Events::ArgumentStack Administration::GetDMPassword(Events::ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetGameMasterPassword();
    LOG_DEBUG("Returned DM password '%s'.", password.m_sString);
    return Events::Arguments(std::string(password.m_sString ? password.m_sString : ""));
}

Events::ArgumentStack Administration::SetDMPassword(Events::ArgumentStack&& args)
{
    const auto newPass = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Set DM password to '%s'.", newPass);
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetGameMasterPassword(newPass.c_str());
    return Events::Arguments();
}

Events::ArgumentStack Administration::ShutdownServer(Events::ArgumentStack&&)
{
    LOG_NOTICE("Shutting down the server!");
    if (kill(getpid(), SIGTERM) != 0)
    {
      LOG_ERROR("Shutdown failed: SIGTERM signal not sent successfully");
    }
    return Events::Arguments();
}

Events::ArgumentStack Administration::DeletePlayerCharacter(Events::ArgumentStack&& args)
{
    const auto objectId = Events::ExtractArgument<Types::ObjectID>(args);
    const auto bPreserveBackup = static_cast<bool>(Events::ExtractArgument<int32_t>(args));

    CServerExoApp* exoApp = Globals::AppManager()->m_pServerExoApp;
    CNWSPlayer* player = exoApp->GetClientObjectByObjectId(objectId);

    if (!player)
    {
        LOG_ERROR("Attempted to delete invalid player");
        return Events::Arguments();
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
        playerdir = exoApp->GetNetLayer()->GetPlayerInfo(playerId)->m_lstKeys.element[0].sPublic.CStr();
    }

    std::string filename = servervault + playerdir + "/" + bicname + ".bic";

    LOG_NOTICE("Deleting %s %s", filename, bPreserveBackup ? "(backed up)" : "(no backup)");

    if( access( filename.c_str(), F_OK ) == -1 )
    {
        LOG_ERROR("File %s not found.", filename);
        return Events::Arguments();
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
                while ( access( backup.append(std::to_string(i)).c_str(), F_OK ) != -1 )
                    i++;
                rename(filename.c_str(), backup.append(std::to_string(i)).c_str());
            }
            else
            {
                unlink(filename.c_str());
            }
        });

    return Events::Arguments();
}

Events::ArgumentStack Administration::AddBannedIP(Events::ArgumentStack&& args)
{
    const auto ip = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Banning IP %s", ip);
    Globals::AppManager()->m_pServerExoApp->AddIPToBannedList(ip.c_str());
    return Events::Arguments();
}

Events::ArgumentStack Administration::RemoveBannedIP(Events::ArgumentStack&& args)
{
    const auto ip = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Unbanning IP %s", ip);
    Globals::AppManager()->m_pServerExoApp->RemoveIPFromBannedList(ip.c_str());
    return Events::Arguments();
}

Events::ArgumentStack Administration::AddBannedCDKey(Events::ArgumentStack&& args)
{
    const auto key = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Banning CDKey %s", key);
    Globals::AppManager()->m_pServerExoApp->AddCDKeyToBannedList(key.c_str());
    return Events::Arguments();
}

Events::ArgumentStack Administration::RemoveBannedCDKey(Events::ArgumentStack&& args)
{
    const auto key = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Unbanning CDKey %s", key);
    Globals::AppManager()->m_pServerExoApp->RemoveCDKeyFromBannedList(key.c_str());
    return Events::Arguments();
}

Events::ArgumentStack Administration::AddBannedPlayerName(Events::ArgumentStack&& args)
{
    const auto playername = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Banning Player name %s", playername);
    Globals::AppManager()->m_pServerExoApp->AddPlayerNameToBannedList(playername.c_str());
    return Events::Arguments();
}

Events::ArgumentStack Administration::RemoveBannedPlayerName(Events::ArgumentStack&& args)
{
    const auto playername = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Unbanning Player name %s", playername);
    Globals::AppManager()->m_pServerExoApp->RemovePlayerNameFromBannedList(playername.c_str());
    return Events::Arguments();
}

Events::ArgumentStack Administration::GetBannedList(Events::ArgumentStack&&)
{
    std::string list = Globals::AppManager()->m_pServerExoApp->GetBannedListString().CStr();
    return Events::Arguments(list);
}

Events::ArgumentStack Administration::SetModuleName(Events::ArgumentStack&& args)
{
    const auto newName = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Set module name to '%s'.", newName);
    Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pServerInfo->m_sModuleName = newName.c_str();
    return Events::Arguments();
}

Events::ArgumentStack Administration::SetServerName(Events::ArgumentStack&& args)
{
    const auto newName = Events::ExtractArgument<std::string>(args);
    LOG_NOTICE("Set server name to '%s'.", newName);
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetSessionName(CExoString(newName.c_str()));
    return Events::Arguments();
}

Events::ArgumentStack Administration::GetServerName(Events::ArgumentStack&&)
{
    CExoString serverName = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetSessionName();
    return Events::Arguments(serverName.CStr());
}

Events::ArgumentStack Administration::GetPlayOption(Events::ArgumentStack&& args)
{
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

    return Events::Arguments(retVal);
}

Events::ArgumentStack Administration::SetPlayOption(Events::ArgumentStack&& args)
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

    return Events::Arguments();
}

Events::ArgumentStack Administration::DeleteTURD(Events::ArgumentStack&& args)
{
    int32_t retVal = false;
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
        LOG_NOTICE("Deleted TURD of %s (%s)", characterName, playerName);
        Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal->Remove(foundNode);
        retVal = true;
    }

    return Events::Arguments(retVal);
}

Events::ArgumentStack Administration::GetDebugValue(Events::ArgumentStack&& args)
{
    int32_t retVal = -1;

    const auto debugType = Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(debugType >= 0);
      ASSERT_OR_THROW(debugType <= 3);

    switch (debugType)
    {
        case 0: // NWNX_ADMINISTRATION_DEBUG_COMBAT
            retVal = *Globals::EnableCombatDebugging();
            break;

        case 1: // NWNX_ADMINISTRATION_DEBUG_SAVING_THROW
            retVal = *Globals::EnableSavingThrowDebugging();
            break;

        case 2: // NWNX_ADMINISTRATION_DEBUG_MOVEMENT_SPEED
            retVal = *Globals::EnableMovementSpeedDebugging();
            break;

        case 3: // NWNX_ADMINISTRATION_DEBUG_HIT_DIE
            retVal = *Globals::EnableHitDieDebugging();
            break;

        default:
            LOG_NOTICE("Calling NWNX_Administration_GetDebugTypeValue with invalid debug type: %d", debugType);
            break;
    }

    return Events::Arguments(retVal);
}

Events::ArgumentStack Administration::SetDebugValue(Events::ArgumentStack&& args)
{
    const auto debugType = Events::ExtractArgument<int32_t>(args);
     ASSERT_OR_THROW(debugType >= 0);
     ASSERT_OR_THROW(debugType <= 3);

    const auto value = Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(value >= 0);

    switch (debugType)
    {
        case 0: // NWNX_ADMINISTRATION_DEBUG_COMBAT
            *Globals::EnableCombatDebugging() = !!value;
            break;

        case 1: // NWNX_ADMINISTRATION_DEBUG_SAVING_THROW
            *Globals::EnableSavingThrowDebugging() = !!value;
            break;

        case 2: // NWNX_ADMINISTRATION_DEBUG_MOVEMENT_SPEED
            *Globals::EnableMovementSpeedDebugging() = !!value;
            break;

        case 3: // NWNX_ADMINISTRATION_DEBUG_HIT_DIE
            *Globals::EnableHitDieDebugging() = !!value;
            break;

        default:
            LOG_NOTICE("Calling NWNX_Administration_SetDebugValue with invalid debug type: %d", debugType);
            break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Administration::ReloadRules(Events::ArgumentStack&&)
{
    LOG_NOTICE("Reloading rules!");
    Globals::Rules()->ReloadAll();
    return Events::Arguments();
}

}
