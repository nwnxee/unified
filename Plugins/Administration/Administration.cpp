#include "nwnx.hpp"
#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNWSRules.hpp"
#include "API/Globals.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSPlayerTURD.hpp"
#include <unistd.h>
#include <csignal>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static CExoLinkedListNode* FindTURD(std::string playerName, std::string characterName)
{
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
    return foundNode;
}

NWNX_EXPORT ArgumentStack GetPlayerPassword(ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerPassword();
    LOG_DEBUG("Returned player password '%s'.", password.m_sString);
    return std::string(password.m_sString ? password.m_sString : "");
}

NWNX_EXPORT ArgumentStack SetPlayerPassword(ArgumentStack&& args)
{
    const auto newPass = args.extract<std::string>();
    LOG_NOTICE("Set player password to '%s'.", newPass);
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword(newPass.c_str());
    return {};
}

NWNX_EXPORT ArgumentStack ClearPlayerPassword(ArgumentStack&&)
{
    LOG_NOTICE("Cleared player password.");
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetPlayerPassword("");
    return {};
}

NWNX_EXPORT ArgumentStack GetDMPassword(ArgumentStack&&)
{
    const CExoString password = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetGameMasterPassword();
    LOG_DEBUG("Returned DM password '%s'.", password.m_sString);
    return std::string(password.m_sString ? password.m_sString : "");
}

NWNX_EXPORT ArgumentStack SetDMPassword(ArgumentStack&& args)
{
    const auto newPass = args.extract<std::string>();
    LOG_NOTICE("Set DM password to '%s'.", newPass);
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetGameMasterPassword(newPass.c_str());
    return {};
}

NWNX_EXPORT ArgumentStack ShutdownServer(ArgumentStack&&)
{
    LOG_NOTICE("Shutting down the server!");
    *Globals::ExitProgram() = true;
    return {};
}

NWNX_EXPORT ArgumentStack DeletePlayerCharacter(ArgumentStack&& args)
{
    const auto objectId = args.extract<ObjectID>();
    const bool bPreserveBackup = !!args.extract<int32_t>();
    const auto kickMessage = args.extract<std::string>();

    CServerExoApp* exoApp = Globals::AppManager()->m_pServerExoApp;
    CNWSPlayer* player = exoApp->GetClientObjectByObjectId(objectId);

    if (!player)
    {
        LOG_ERROR("Attempted to delete invalid player");
        return {};
    }
    PlayerID playerId = player->m_nPlayerID;

    std::string bicname     = player->m_resFileName.GetResRefStr();
    std::string servervault = CExoString(Globals::ExoBase()->m_pcExoAliasList->GetAliasPath("SERVERVAULT", 0)).CStr();
    std::string playerdir;
    if (exoApp->GetServerInfo()->m_PersistantWorldOptions.bServerVaultByPlayerName)
    {
        playerdir = player->GetPlayerName().CStr();
    }
    else
    {
        playerdir = exoApp->GetNetLayer()->GetPlayerInfo(playerId)->m_cCDKey.sPublic.CStr();
    }

    std::string filename = servervault + playerdir + "/" + bicname + ".bic";
    std::string playerName = player->GetPlayerName().CStr();

    LOG_NOTICE("Deleting %s %s", filename, bPreserveBackup ? "(backed up)" : "(no backup)");

    if( access( filename.c_str(), F_OK ) == -1 )
    {
        LOG_ERROR("File %s not found.", filename);
        return {};
    }

    CNWSCreature* creature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(objectId);
    std::string characterName, characterLastName;
    if (creature && creature->m_pStats)
    {
        characterName = Utils::ExtractLocString(creature->m_pStats->m_lsFirstName);
        characterLastName = Utils::ExtractLocString(creature->m_pStats->m_lsLastName);
    }

    Tasks::QueueOnMainThread(
        [filename, playerId, bPreserveBackup, playerName, characterName, characterLastName, kickMessage, playerdir]
        {
            // Will show "Delete Character" message to PC. Best match from dialog.tlk
            Globals::AppManager()->m_pServerExoApp->GetNetLayer()->DisconnectPlayer(playerId, 10392, 1, kickMessage);

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

            std::string chararacterFullName = characterName;

            if (!characterLastName.empty())
            {
                chararacterFullName += characterName.empty() ? characterLastName : " " + characterLastName;
            }

            CExoLinkedListNode *foundNode = FindTURD(playerName, chararacterFullName);
            if (!foundNode)
                foundNode = FindTURD(playerdir, chararacterFullName);

            if (foundNode)
            {
                LOG_NOTICE("Deleted TURD of %s (%s)", chararacterFullName, playerName);
                Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal->Remove(foundNode);
            }
        });

    return {};
}

NWNX_EXPORT ArgumentStack AddBannedIP(ArgumentStack&& args)
{
    const auto ip = args.extract<std::string>();
    LOG_NOTICE("Banning IP %s", ip);
    Globals::AppManager()->m_pServerExoApp->AddIPToBannedList(ip.c_str());
    return {};
}

NWNX_EXPORT ArgumentStack RemoveBannedIP(ArgumentStack&& args)
{
    const auto ip = args.extract<std::string>();
    LOG_NOTICE("Unbanning IP %s", ip);
    Globals::AppManager()->m_pServerExoApp->RemoveIPFromBannedList(ip.c_str());
    return {};
}

NWNX_EXPORT ArgumentStack AddBannedCDKey(ArgumentStack&& args)
{
    const auto key = args.extract<std::string>();
    LOG_NOTICE("Banning CDKey %s", key);
    Globals::AppManager()->m_pServerExoApp->AddCDKeyToBannedList(key.c_str());
    return {};
}

NWNX_EXPORT ArgumentStack RemoveBannedCDKey(ArgumentStack&& args)
{
    const auto key = args.extract<std::string>();
    LOG_NOTICE("Unbanning CDKey %s", key);
    Globals::AppManager()->m_pServerExoApp->RemoveCDKeyFromBannedList(key.c_str());
    return {};
}

NWNX_EXPORT ArgumentStack AddBannedPlayerName(ArgumentStack&& args)
{
    const auto playername = args.extract<std::string>();
    LOG_NOTICE("Banning Player name %s", playername);
    Globals::AppManager()->m_pServerExoApp->AddPlayerNameToBannedList(playername.c_str());
    return {};
}

NWNX_EXPORT ArgumentStack RemoveBannedPlayerName(ArgumentStack&& args)
{
    const auto playername = args.extract<std::string>();
    LOG_NOTICE("Unbanning Player name %s", playername);
    Globals::AppManager()->m_pServerExoApp->RemovePlayerNameFromBannedList(playername.c_str());
    return {};
}

NWNX_EXPORT ArgumentStack GetBannedList(ArgumentStack&&)
{
    std::string list = Globals::AppManager()->m_pServerExoApp->GetBannedListString().CStr();
    return list;
}

NWNX_EXPORT ArgumentStack SetModuleName(ArgumentStack&& args)
{
    const auto newName = args.extract<std::string>();
    LOG_NOTICE("Set module name to '%s'.", newName);
    Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pServerInfo->m_sModuleName = newName.c_str();
    return {};
}

NWNX_EXPORT ArgumentStack SetServerName(ArgumentStack&& args)
{
    const auto newName = args.extract<std::string>();
    LOG_NOTICE("Set server name to '%s'.", newName);
    Globals::AppManager()->m_pServerExoApp->GetNetLayer()->SetSessionName(CExoString(newName.c_str()));
    return {};
}

NWNX_EXPORT ArgumentStack GetServerName(ArgumentStack&&)
{
    CExoString serverName = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetSessionName();
    return serverName.CStr();
}

NWNX_EXPORT ArgumentStack GetPlayOption(ArgumentStack&& args)
{
    int32_t retVal = -1;

    const auto option = args.extract<int32_t>();

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

        case 27: // NWNX_ADMINISTRATION_OPTION_PLAYER_PARTY_CONTROL
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bPlayerPartyControl;
            break;

        case 28: // NWNX_ADMINISTRATION_OPTION_SHOW_PLAYER_JOIN_MESSAGES
            retVal = Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bShowPlayerJoinMessages;
            break;

        default:
            LOG_NOTICE("Calling NWNX_Administration_GetPlayOption with invalid option: %d", option);
            break;
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack SetPlayOption(ArgumentStack&& args)
{
    const auto option = args.extract<int32_t>();
    const auto value = args.extract<int32_t>();

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
            ASSERT_OR_THROW(value <= 2);
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.nPVPSetting = value;
            break;

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

        case 27: // NWNX_ADMINISTRATION_OPTION_PLAYER_PARTY_CONTROL
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bPlayerPartyControl = !!value;
            break;

        case 28: // NWNX_ADMINISTRATION_OPTION_SHOW_PLAYER_JOIN_MESSAGES
            Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bShowPlayerJoinMessages = !!value;
            break;

        default:
            LOG_NOTICE("Calling NWNX_Administration_SetPlayOption with invalid option: %d", option);
            break;
    }

    return {};
}

NWNX_EXPORT ArgumentStack DeleteTURD(ArgumentStack&& args)
{
    int32_t retVal = false;
    const auto playerName = args.extract<std::string>();
    const auto characterName = args.extract<std::string>();

    ASSERT_OR_THROW(!playerName.empty());
    ASSERT_OR_THROW(!characterName.empty());

    CExoLinkedListNode *foundNode = FindTURD(playerName, characterName);

    if (foundNode)
    {
        LOG_NOTICE("Deleted TURD of %s (%s)", characterName, playerName);
        Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal->Remove(foundNode);
        retVal = true;
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack GetDebugValue(ArgumentStack&& args)
{
    int32_t retVal = -1;

    const auto debugType = args.extract<int32_t>();
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

    return retVal;
}

NWNX_EXPORT ArgumentStack SetDebugValue(ArgumentStack&& args)
{
    const auto debugType = args.extract<int32_t>();
     ASSERT_OR_THROW(debugType >= 0);
     ASSERT_OR_THROW(debugType <= 3);

    const auto value = args.extract<int32_t>();
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

    return {};
}

NWNX_EXPORT ArgumentStack ReloadRules(ArgumentStack&&)
{
    LOG_NOTICE("Reloading rules!");
    Globals::Rules()->ReloadAll();
    return {};
}

NWNX_EXPORT ArgumentStack GetMinLevel(ArgumentStack&&)
{
    auto *pServerInfo = Globals::AppManager()->m_pServerExoApp->GetServerInfo();
    return pServerInfo->m_JoiningRestrictions.nMinLevel;
}

NWNX_EXPORT ArgumentStack SetMinLevel(ArgumentStack&& args)
{
    const auto nLevel = args.extract<int32_t>();
    ASSERT_OR_THROW(nLevel >= 1);
    ASSERT_OR_THROW(nLevel <= 255);
    LOG_NOTICE("Set minimum level to %d.", nLevel);
    auto *pServerInfo = Globals::AppManager()->m_pServerExoApp->GetServerInfo();
    pServerInfo->m_JoiningRestrictions.nMinLevel = nLevel;
    return {};
}

NWNX_EXPORT ArgumentStack GetMaxLevel(ArgumentStack&&)
{
    auto *pServerInfo = Globals::AppManager()->m_pServerExoApp->GetServerInfo();
    return pServerInfo->m_JoiningRestrictions.nMaxLevel;
}

NWNX_EXPORT ArgumentStack SetMaxLevel(ArgumentStack&& args)
{
    const auto nLevel = args.extract<int32_t>();
    ASSERT_OR_THROW(nLevel >= 1);
    ASSERT_OR_THROW(nLevel <= 255);
    LOG_NOTICE("Set maximum level to %d.", nLevel);
    auto *pServerInfo = Globals::AppManager()->m_pServerExoApp->GetServerInfo();
    pServerInfo->m_JoiningRestrictions.nMaxLevel = nLevel;
    return {};
}
