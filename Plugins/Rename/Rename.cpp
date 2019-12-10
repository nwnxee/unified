#include "Rename.hpp"

#include <sstream>
#include <regex>
#include <string>
#include <random>
#include <algorithm>
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoString.hpp"
#include "API/CLastUpdateObject.hpp"
#include "API/CExoLinkedList.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Functions.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Messaging/Messaging.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooking::FunctionHook* m_SendServerToPlayerPopUpGUIPanelHook;
static Hooking::FunctionHook* m_SendServerToPlayerPlayModuleCharacterListResponseHook;

static Rename::Rename* g_plugin;

//Constants for Player Name states.
const int NWNX_RENAME_PLAYERNAME_DEFAULT = 0;
const int NWNX_RENAME_PLAYERNAME_OBFUSCATE = 1;
const int NWNX_RENAME_PLAYERNAME_OVERRIDE = 2;
const int NWNX_RENAME_PLAYERNAME_ANONYMOUS = 3;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Rename",
        "Functions to facilitate renaming, overriding and customization of player names.",
        "Silvard / orth",
        "jusenkyo at gmail.com",
        3,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Rename::Rename(params);
    return g_plugin;
}

namespace Rename {

Rename::Rename(const Plugin::CreateParams& params)
  : Plugin(params)
{
#define REGISTER(func)              \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Rename::func, this, std::placeholders::_1))

    REGISTER(SetPCNameOverride);
    REGISTER(GetPCNameOverride);
    REGISTER(ClearPCNameOverride);

#undef REGISTER

    m_RenameOnModuleCharList = GetServices()->m_config->Get<int32_t>("ON_MODULE_CHAR_LIST", 0);
    m_RenameOnPlayerList = GetServices()->m_config->Get<bool>("ON_PLAYER_LIST", true);
    m_RenameAllowDM = GetServices()->m_config->Get<bool>("ALLOW_DM", false);
    m_RenameAnonymousPlayerName = GetServices()->m_config->Get<std::string>("ANONYMOUS_NAME", "Someone");

    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN11CNWSMessage31WriteGameObjUpdate_UpdateObjectEP10CNWSPlayerP10CNWSObjectP17CLastUpdateObjectjj,
            int32_t, CNWSMessage *, CNWSPlayer *, CNWSObject *, CLastUpdateObject *, uint32_t, uint32_t>(
            &WriteGameObjUpdate_UpdateObjectHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN11CNWSMessage41SendServerToPlayerExamineGui_CreatureDataEP10CNWSPlayerj,
            int32_t, CNWSMessage *, CNWSPlayer *, Types::ObjectID>(&SendServerToPlayerExamineGui_CreatureDataHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN11CNWSMessage28SendServerToPlayerChat_PartyEjj10CExoString,
            int32_t, CNWSMessage*, Types::PlayerID, Types::ObjectID, CExoString*>(&SendServerToPlayerChatHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN11CNWSMessage28SendServerToPlayerChat_ShoutEjj10CExoString,
            int32_t, CNWSMessage*, Types::PlayerID, Types::ObjectID, CExoString*>(&SendServerToPlayerChatHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN11CNWSMessage27SendServerToPlayerChat_TellEjj10CExoString,
            int32_t, CNWSMessage*, Types::PlayerID, Types::ObjectID, CExoString*>(&SendServerToPlayerChatHook);

    // TODO: When shared hooks are executed by exclusive hooks we can use a shared hook for this instead and simplify
    // For now we perform the functionality of the HideClassesOnCharList Tweak for convenience
    if (m_RenameOnModuleCharList > 0)
    {
        if (m_RenameOnModuleCharList == 1)
            LOG_INFO("Renaming PCs in the module character listing.");
        else if (m_RenameOnModuleCharList == 2)
            LOG_INFO("Renaming PCs and hiding classes in the module character listing.");
        else if (m_RenameOnModuleCharList == 3)
            LOG_INFO("Hiding classes in the module character listing via the Rename plugin.");
        GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN11CNWSMessage49SendServerToPlayerPlayModuleCharacterListResponseEjji,
                int32_t, CNWSMessage *, Types::PlayerID, Types::ObjectID, int32_t>(&SendServerToPlayerPlayModuleCharacterListResponseHook);
        m_SendServerToPlayerPlayModuleCharacterListResponseHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::_ZN11CNWSMessage49SendServerToPlayerPlayModuleCharacterListResponseEjji);
    }

    if (m_RenameOnPlayerList)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AllEP10CNWSPlayer,
                int32_t, CNWSMessage*, CNWSPlayer*>(&SendServerToPlayerPlayerList_AllHook);
        GetServices()->m_hooks->RequestSharedHook<Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AddEjP10CNWSPlayer,
                int32_t, CNWSMessage*, Types::PlayerID, CNWSPlayer*>(&SendServerToPlayerPlayerList_AddHook);
        GetServices()->m_hooks->RequestSharedHook<Functions::_ZN11CNWSMessage35SendServerToPlayerPlayerList_DeleteEjP10CNWSPlayer,
                int32_t, CNWSMessage*, Types::PlayerID, CNWSPlayer*>(&SendServerToPlayerPlayerList_DeleteHook);
    }
    else
        LOG_INFO("Not renaming PCs in the player list.");

    if (m_RenameAllowDM)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::_ZN11CNWSMessage46SendServerToPlayerDungeonMasterUpdatePartyListEj,
                int32_t, CNWSMessage*, Types::PlayerID>(&SendServerToPlayerDungeonMasterUpdatePartyListHook);
        LOG_INFO("DMs will be included with rename logic.");
    }

    // TODO: When shared hooks are executed by exclusive hooks change this to HandlePlayerToServerParty
    GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN11CNWSMessage31SendServerToPlayerPopUpGUIPanelEjiiii10CExoString,
            int32_t, CNWSMessage*, Types::ObjectID, int32_t, int32_t, int32_t, int32_t, CExoString*>(&SendServerToPlayerPopUpGUIPanelHook);
    m_SendServerToPlayerPopUpGUIPanelHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::_ZN11CNWSMessage31SendServerToPlayerPopUpGUIPanelEjiiii10CExoString);

}

Rename::~Rename()
{
}

CNWSPlayer *Rename::player(Types::ObjectID playerId)
{
    if (playerId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Rename function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(playerId);
    if (!pPlayer)
    {
        LOG_NOTICE("NWNX_Rename function called on non-player object %x", playerId);
    }
    return pPlayer;
}

void Rename::SetOrRestorePlayerName(bool before, CNWSPlayer *targetPlayer, CNWSPlayer *observerPlayer, bool playerList)
{
    if (targetPlayer == nullptr || observerPlayer == nullptr)
        return;

    auto *targetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(targetPlayer->m_oidNWSObject);
    auto *observerCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(observerPlayer->m_oidNWSObject);

    Types::ObjectID observerOid;
    if (observerCreature == nullptr)
        observerOid = Constants::OBJECT_INVALID;
    else
        observerOid = observerPlayer->m_oidNWSObject;

    // There's a moment when a player is just logging in that pStats doesn't exist yet.
    if (targetCreature == nullptr || targetCreature->m_pStats == nullptr || (!g_plugin->m_RenameAllowDM &&
                                                                             (targetCreature->m_pStats->m_bIsDM ||
                                                                              targetCreature->m_nAssociateType == 7 ||
                                                                              targetCreature->m_nAssociateType == 8)) ||
        (observerCreature != nullptr && (observerCreature->m_pStats == nullptr || (!g_plugin->m_RenameAllowDM &&
                                                                                   (observerCreature->m_pStats->m_bIsDM ||
                                                                                    observerCreature->m_nAssociateType == 7 ||
                                                                                    observerCreature->m_nAssociateType == 8)))))
    {
        return;
    }

    if (before)
        SetPlayerNameAsObservedBy(targetCreature, observerOid, playerList);
    else
        RestorePlayerName(targetCreature, playerList);

}

void Rename::SetPlayerNameAsObservedBy(CNWSCreature *targetCreature, Types::ObjectID observerOid, bool playerList)
{
    auto targetOid = targetCreature->m_idSelf;
    if (!g_plugin->m_RenamePlayerNames.count(targetOid))
        return;
    if (g_plugin->m_RenamePlayerNames[targetOid].count(observerOid))
    {
        auto displayName = std::get<0>(g_plugin->m_RenamePlayerNames[targetOid][observerOid]);
        auto overrideName = std::get<1>(g_plugin->m_RenamePlayerNames[targetOid][observerOid]);
        if (playerList)
        {
            targetCreature->m_pStats->m_lsFirstName = g_plugin->ContainString(overrideName.CStr());
            targetCreature->m_pStats->m_lsLastName = g_plugin->ContainString("");
        }
        targetCreature->m_sDisplayName = displayName;
        LOG_DEBUG("Observer %x will see %x as %s due to personal override", observerOid, targetOid, overrideName.m_sString);
    }
    else if (g_plugin->m_RenamePlayerNames[targetOid].count(Constants::OBJECT_INVALID))
    {
        auto displayName = std::get<0>(g_plugin->m_RenamePlayerNames[targetOid][Constants::OBJECT_INVALID]);
        auto overrideName = std::get<1>(g_plugin->m_RenamePlayerNames[targetOid][Constants::OBJECT_INVALID]);
        if (playerList)
        {
            targetCreature->m_pStats->m_lsFirstName = g_plugin->ContainString(overrideName.CStr());
            targetCreature->m_pStats->m_lsLastName = g_plugin->ContainString("");
        }
        targetCreature->m_sDisplayName = displayName;
        LOG_DEBUG("Observer %x will see %x as %s due to global override", observerOid, targetOid, overrideName.m_sString);
    }
}

void Rename::RestorePlayerName(CNWSCreature *targetCreature, bool playerList)
{
    if (g_plugin->m_RenameOriginalNames.count(targetCreature->m_idSelf))
    {
        auto lsFirstName = std::get<1>(g_plugin->m_RenameOriginalNames[targetCreature->m_idSelf]);
        auto lsLastName = std::get<2>(g_plugin->m_RenameOriginalNames[targetCreature->m_idSelf]);
        if (playerList)
        {
            targetCreature->m_pStats->m_lsFirstName = lsFirstName;
            targetCreature->m_pStats->m_lsLastName = lsLastName;
        }

        if (g_plugin->m_RenamePlayerNames[targetCreature->m_idSelf].count(Constants::OBJECT_INVALID))
        {
            targetCreature->m_sDisplayName = std::get<0>(g_plugin->m_RenamePlayerNames[targetCreature->m_idSelf][Constants::OBJECT_INVALID]);
        }
        else
        {
            targetCreature->m_sDisplayName = "";
        }
    }
}

void Rename::WriteGameObjUpdate_UpdateObjectHook(
        bool before,
        CNWSMessage*,
        CNWSPlayer *observerPlayer,
        CNWSObject *targetObject,
        CLastUpdateObject*,
        uint32_t,
        uint32_t)
{
    auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(targetObject->m_idSelf);
    SetOrRestorePlayerName(before, targetPlayer, observerPlayer);
}

void Rename::SendServerToPlayerExamineGui_CreatureDataHook(
        bool before,
        CNWSMessage*,
        CNWSPlayer *observerPlayer,
        Types::ObjectID targetOid)
{
    auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(targetOid);
    SetOrRestorePlayerName(before, targetPlayer, observerPlayer);
}

// This can't work on per target basis as the player logging in hasn't selected their PC yet but it
// will still work for a global override. We also handle the hide classes tweak until exclusive
// hooks call shared hooks
int32_t Rename::SendServerToPlayerPlayModuleCharacterListResponseHook(
        CNWSMessage *thisPtr,
        Types::PlayerID observerPlayerId,
        Types::ObjectID targetOid,
        int32_t add)
{
    auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(targetOid);
    auto *observerClient = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(observerPlayerId, 0);
    auto *observerPlayer = static_cast<CNWSPlayer *>(observerClient);
    if (g_plugin->m_RenameOnModuleCharList == 1 || g_plugin->m_RenameOnModuleCharList == 2)
    {
        SetOrRestorePlayerName(true, targetPlayer, observerPlayer);
    }

    int32_t retVal = -1;

    if (g_plugin->m_RenameOnModuleCharList >= 2)
    {
        thisPtr->CreateWriteMessage(sizeof(observerPlayerId), observerPlayerId, true);

        thisPtr->WriteBOOL(add);
        thisPtr->WriteDWORD(targetOid, 32);

        if (add)
        {
            auto *targetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(targetOid);
            if (targetCreature)
            {
                thisPtr->WriteCExoLocStringServer(targetCreature->GetFirstName(), targetCreature->GetGender());
                thisPtr->WriteCExoLocStringServer(targetCreature->GetLastName(), targetCreature->GetGender());

                uint16_t portraitId = targetCreature->GetPortraitId();
                thisPtr->WriteWORD(portraitId, 16);
                if (portraitId >= 0xFFFE)
                {
                    thisPtr->WriteCResRef(targetCreature->GetPortrait(), 16);
                }

                thisPtr->WriteBYTE(0, 8);
            }
            else
            {
                retVal = 0;
            }
        }

        uint8_t *message;
        uint32_t size;
        if (!thisPtr->GetWriteMessage(&message, &size))
        {
            retVal = 0;
        }
        if (retVal != 0)
            retVal = thisPtr->SendServerToPlayerMessage(observerPlayerId, 0x31, 0x03, message, size);
    }
    else
    {
        retVal = m_SendServerToPlayerPlayModuleCharacterListResponseHook->CallOriginal<int32_t>(thisPtr, observerPlayerId, targetOid, add);
    }

    if (g_plugin->m_RenameOnModuleCharList == 1 || g_plugin->m_RenameOnModuleCharList == 2)
    {
        SetOrRestorePlayerName(false, targetPlayer, observerPlayer);
    }
    return retVal;
}

void Rename::SendServerToPlayerChatHook(
        bool before,
        CNWSMessage*,
        Types::PlayerID observerPlayerId,
        Types::ObjectID targetOid,
        CExoString*)
{
    auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(targetOid);
    auto *observerClient = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(observerPlayerId, 0);
    auto *observerPlayer = static_cast<CNWSPlayer*>(observerClient);
    SetOrRestorePlayerName(before, targetPlayer, observerPlayer);
}

void Rename::SendServerToPlayerDungeonMasterUpdatePartyListHook(
        bool before,
        CNWSMessage*,
        Types::PlayerID observerPlayerId)
{
    g_plugin->GlobalNameChange(before, observerPlayerId, Constants::PLAYERID_ALL_PLAYERS);
}

void Rename::SendServerToPlayerPlayerList_AllHook(
        bool before,
        CNWSMessage*,
        CNWSPlayer *observerPlayer)
{
    g_plugin->GlobalNameChange(before, observerPlayer->m_nPlayerID, Constants::PLAYERID_ALL_PLAYERS);
}

void Rename::SendServerToPlayerPlayerList_AddHook(
        bool before,
        CNWSMessage*,
        Types::PlayerID observerPlayerId,
        CNWSPlayer *targetPlayer)
{
    if (!g_plugin->m_RenameAllowDM && observerPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS)
        return;

    if (!before)
    {
        g_plugin->m_RenameAddedToPlayerList.insert(targetPlayer->m_oidNWSObject);
    }
    g_plugin->GlobalNameChange(before, observerPlayerId, targetPlayer->m_nPlayerID);
}

void Rename::SendServerToPlayerPlayerList_DeleteHook(
        bool before,
        CNWSMessage*,
        Types::PlayerID observerPlayerId,
        CNWSPlayer *targetPlayer)
{
    if (!g_plugin->m_RenameAllowDM && observerPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS)
        return;

    if (before)
    {
        g_plugin->m_RenameAddedToPlayerList.erase(targetPlayer->m_oidNWSObject);
    }
}

int32_t Rename::SendServerToPlayerPopUpGUIPanelHook(
            CNWSMessage *pMessage,
            Types::ObjectID observerOid,
            int32_t nGuiPanel,
            int32_t bGUIOption1,
            int32_t bGUIOption2,
            int32_t nStringReference,
            CExoString *p_sStringReference)
{
    if (nGuiPanel == 1) // Party invite popup
    {
        auto *server = Globals::AppManager()->m_pServerExoApp;
        auto *observerCreature = server->GetCreatureByGameObjectID(observerOid);
        auto targetOid = observerCreature->m_oidInvitedToPartyBy;
        if (g_plugin->m_RenamePlayerNames.count(targetOid) && g_plugin->m_RenamePlayerNames[targetOid].count(observerOid))
        {
            *p_sStringReference = std::get<0>(g_plugin->m_RenamePlayerNames[targetOid][observerOid]);
        }
        else if (g_plugin->m_RenamePlayerNames.count(targetOid) &&
                 g_plugin->m_RenamePlayerNames[targetOid].count(Constants::OBJECT_INVALID))
        {
            *p_sStringReference = std::get<0>(g_plugin->m_RenamePlayerNames[targetOid][Constants::OBJECT_INVALID]);
        }
    }
    return m_SendServerToPlayerPopUpGUIPanelHook->CallOriginal<int32_t>(pMessage, observerOid, nGuiPanel, bGUIOption1,
                                                                 bGUIOption2, nStringReference, p_sStringReference);
}
void Rename::GlobalNameChange(
        bool before,
        Types::PlayerID observerPlayerId,
        Types::PlayerID targetPlayerId)
{
    auto *server = Globals::AppManager()->m_pServerExoApp;
    auto *playerList = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    std::vector<Types::PlayerID> observersToNotify;
    std::vector<Types::PlayerID> targetsToNotify;

    if (observerPlayerId == Constants::PLAYERID_ALL_PLAYERS || observerPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS)
    {
        for (auto *head = playerList->pHead; head; head = head->pNext)
        {
            auto *observerPlayer = static_cast<CNWSPlayer *>(static_cast<CNWSClient *>(head->pObject));
            if ((observerPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS &&
                 observerPlayer->m_nCharacterType == Constants::CharacterType::DM) ||
                (observerPlayerId == Constants::PLAYERID_ALL_PLAYERS &&
                 observerPlayer->m_nCharacterType != Constants::CharacterType::DM))
            {
                observersToNotify.emplace_back(observerPlayer->m_nPlayerID);
            }
        }
    }
    else
    {
        observersToNotify.emplace_back(observerPlayerId);
    }

    if (targetPlayerId == Constants::PLAYERID_ALL_PLAYERS || targetPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS)
    {
        for (auto *head = playerList->pHead; head; head = head->pNext)
        {
            auto *targetPlayer = static_cast<CNWSPlayer *>(static_cast<CNWSClient *>(head->pObject));
            if ((targetPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS &&
                 targetPlayer->m_nCharacterType == Constants::CharacterType::DM) ||
                (targetPlayerId == Constants::PLAYERID_ALL_PLAYERS &&
                 targetPlayer->m_nCharacterType != Constants::CharacterType::DM))
            {
                targetsToNotify.emplace_back(targetPlayer->m_nPlayerID);
            }
        }
    }
    else
    {
        targetsToNotify.emplace_back(targetPlayerId);
    }

    auto *pNetLayer = server->GetNetLayer();

    for (auto &observerPid : observersToNotify)
    {
        for (auto &targetPid : targetsToNotify)
        {
            auto *targetPlayer = static_cast<CNWSPlayer*>(server->GetClientObjectByPlayerId(targetPid, 0));
            auto targetOid = targetPlayer->m_oidNWSObject;
            auto *targetCreature = server->GetCreatureByGameObjectID(targetOid);
            if (targetCreature && g_plugin->m_RenamePlayerNames.count(targetOid) &&
                g_plugin->m_RenamePlayerNames[targetOid].count(Constants::OBJECT_INVALID))
            {
                auto playerNameOverrideState = std::get<2>(g_plugin->m_RenamePlayerNames[targetOid][Constants::OBJECT_INVALID]);
                if (playerNameOverrideState)
                {
                    auto playerInfo = pNetLayer->GetPlayerInfo(targetPid);
                    if (!before)
                    {
                        playerInfo->m_sPlayerName = std::get<0>(g_plugin->m_RenameOriginalNames[targetOid]);
                    }
                    else
                    {
                        switch (playerNameOverrideState)
                        {
                            case NWNX_RENAME_PLAYERNAME_OBFUSCATE:
                                playerInfo->m_sPlayerName = CExoString(GenerateRandomPlayerName(7).c_str());
                                break;
                            case NWNX_RENAME_PLAYERNAME_OVERRIDE:
                                playerInfo->m_sPlayerName = std::get<1>(g_plugin->m_RenamePlayerNames[targetOid][Constants::OBJECT_INVALID]);
                                break;
                            case NWNX_RENAME_PLAYERNAME_ANONYMOUS:
                                playerInfo->m_sPlayerName = CExoString(m_RenameAnonymousPlayerName.c_str());
                                break;
                            default:
                                playerInfo->m_sPlayerName = std::get<0>(g_plugin->m_RenameOriginalNames[targetOid]);
                        }
                    }
                }
            }
            auto *observerPlayer = static_cast<CNWSPlayer*>(server->GetClientObjectByPlayerId(observerPid, 0));
            SetOrRestorePlayerName(before, targetPlayer, observerPlayer, true);
        }
    }
}

CExoLocString Rename::ContainString(const std::string& str)
{
    CExoLocString locStr;
    locStr.AddString(0,CExoString(str.c_str()),0);
    return locStr;
}

std::string Rename::GenerateRandomPlayerName(size_t length)
{
    static std::mt19937 rngEngine(std::random_device{}());
    static const std::string charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::uniform_int_distribution<int> distribution(0, charSet.length() - 1);
    std::string randomPlayername;
    randomPlayername.reserve(length+1);
    for (size_t i = 0; i < length; ++i)
    {
        randomPlayername += charSet[distribution(rngEngine)];
    }
    return randomPlayername;
}

void Rename::SendNameUpdate(CNWSCreature *targetCreature, Types::PlayerID observerPlayerId)
{
    std::vector<Types::PlayerID> playersToNotify;
    auto *server = Globals::AppManager()->m_pServerExoApp;

    if (observerPlayerId == Constants::PLAYERID_ALL_CLIENTS)
    {
        auto *playerList = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;

        for (auto *head = playerList->pHead; head; head = head->pNext)
        {
            auto *client = static_cast<CNWSClient*>(head->pObject);
            if (client)
                playersToNotify.emplace_back(client->m_nPlayerID);
        }
    }
    else
    {
        playersToNotify.emplace_back(observerPlayerId);
    }

    auto *message = static_cast<CNWSMessage*>(server->GetNWSMessage());
    for (auto &pid : playersToNotify)
    {
        bool success = false;
        auto *observerPlayerObject = static_cast<CNWSPlayer*>(server->GetClientObjectByPlayerId(pid, 0));
        if (observerPlayerObject == nullptr)
            continue;
        auto targets = g_plugin->m_RenamePlayerNames[targetCreature->m_idSelf];

        // If the update is to all clients but the observer has a personal override of the target's name then skip
        if (observerPlayerId == Constants::PLAYERID_ALL_CLIENTS && targets.count(observerPlayerObject->m_oidNWSObject))
            continue;

        if (g_plugin->m_RenameAllowDM || observerPlayerObject->m_nCharacterType != Constants::CharacterType::DM)
        {
            // Write a message notifying an object update.
            message->CreateWriteMessage(0x400, pid, 1);

            // We don't need one for our update.
            // However, the appearance update is contingent on receiving a pointer which isn't nullptr.
            auto *lastUpdateObj = reinterpret_cast<CLastUpdateObject*>(0xDEADBEEF);
            message->WriteGameObjUpdate_UpdateObject(observerPlayerObject, targetCreature, lastUpdateObj, 0, 0x400);

            uint8_t *data = nullptr;
            uint32_t size = 0;

            if (message->GetWriteMessage(&data, &size) && size)
            {
                message->SendServerToPlayerMessage(pid, 5, 1, data, size);
                success = true;
            }

            if (m_RenameOnPlayerList)
                message->SendServerToPlayerPlayerList_All(observerPlayerObject);
        }
        LOG_DEBUG("%s sending name update message for observer (PlayerID): '0x%08x', target (ObjectID): '0x%08x'.",
                  success ? "Succeeded" : "Failed", pid, targetCreature->m_idSelf);
    }
}

ArgumentStack Rename::SetPCNameOverride(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto targetOid = Services::Events::ExtractArgument<Types::ObjectID>(args);
    if (auto *targetPlayer = player(targetOid))
    {
        auto *server = Globals::AppManager()->m_pServerExoApp;
        auto *targetCreature = server->GetCreatureByGameObjectID(targetOid);
        if (targetCreature == nullptr)
        {
            LOG_ERROR("No creature object found for Player ID '0x%08x', oidNWSObject '%x'", targetPlayer->m_nPlayerID, targetOid);
            return stack;
        }
        const auto newName = Services::Events::ExtractArgument<std::string>(args);
        const auto sPrefix = Services::Events::ExtractArgument<std::string>(args);
        const auto sSuffix = Services::Events::ExtractArgument<std::string>(args);
        auto bPlayerNameState = Services::Events::ExtractArgument<int>(args);
        const auto observerOid = Services::Events::ExtractArgument<Types::ObjectID>(args);

        if (bPlayerNameState != NWNX_RENAME_PLAYERNAME_DEFAULT && observerOid != Constants::OBJECT_INVALID)
        {
            LOG_WARNING("You can not override or obfuscate a player name per target. Falling back to DEFAULT.");
            bPlayerNameState = NWNX_RENAME_PLAYERNAME_DEFAULT;
        }

        if (bPlayerNameState != NWNX_RENAME_PLAYERNAME_DEFAULT && !m_RenameOnPlayerList)
        {
            LOG_WARNING("You can not override the community name with NWNX_RENAME_ON_PLAYER_LIST set to false.");
            bPlayerNameState = NWNX_RENAME_PLAYERNAME_DEFAULT;
        }

        const auto observerPlayerId =
                observerOid == Constants::OBJECT_INVALID ? Constants::PLAYERID_ALL_CLIENTS
                                                         : server->GetPlayerIDByGameObjectID(observerOid);

        if (observerPlayerId == Constants::PLAYERID_INVALIDID)
        {
            LOG_ERROR("The target observer '0x%08x' is not a valid player.", observerPlayerId);
            return stack;
        }

        std::string fullDisplayName = sPrefix + newName + sSuffix; //put together the floaty/chat/hover name
        fullDisplayName = std::regex_replace(fullDisplayName, std::regex("^ +| +$|( ) +"), "$1"); //remove trailing and leading spaces

        // Store our override values
        m_RenamePlayerNames[targetOid][observerOid] = std::make_tuple(CExoString(fullDisplayName.c_str()),
                                                                      CExoString(newName.c_str()), bPlayerNameState);

        // Store the original values
        auto *pPlayerInfo = server->GetNetLayer()->GetPlayerInfo(targetPlayer->m_nPlayerID);
        m_RenameOriginalNames[targetOid] = std::make_tuple(
                pPlayerInfo->m_sPlayerName,
                targetCreature->m_pStats->m_lsFirstName,
                targetCreature->m_pStats->m_lsLastName);

        // If we've ran this before the PC has even been added to the other clients' player list then there's
        // nothing else we need to do, the hooks will take care of doing the renames. If we don't skip this
        // then the SendServerToPlayerPlayerList_All in the SendNameUpdate below runs before the server has even ran a
        // SendServerToPlayerPlayerList_Add and weird things happen(tm)
        auto &v = m_RenameAddedToPlayerList;
        if (m_RenameOnPlayerList && v.find(targetPlayer->m_oidNWSObject) == v.end())
        {
            return stack;
        }

        SendNameUpdate(targetCreature, observerPlayerId);
    }
    return stack;
}

ArgumentStack Rename::GetPCNameOverride(ArgumentStack &&args)
{
    ArgumentStack stack;
    auto targetOid = Services::Events::ExtractArgument<Types::ObjectID>(args);
    std::string retVal;
    if (auto *targetPlayer = player(targetOid))
    {
        auto *targetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(targetOid);
        if (!targetCreature)
        {
            LOG_ERROR("No creature object found for Player %x, oidNWSObject %x", targetPlayer->m_nPlayerID, targetOid);
            return stack;
        }
        auto observerOid = Services::Events::ExtractArgument<Types::ObjectID>(args);
        if(m_RenamePlayerNames[targetOid].find(observerOid) != m_RenamePlayerNames[targetOid].end())
            retVal = std::get<0>(m_RenamePlayerNames[targetOid][observerOid]).CStr();
        else if(m_RenamePlayerNames[targetOid].find(Constants::OBJECT_INVALID) != m_RenamePlayerNames[targetOid].end())
            retVal = std::get<0>(m_RenamePlayerNames[targetOid][Constants::OBJECT_INVALID]).CStr();
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Rename::ClearPCNameOverride(ArgumentStack &&args)
{
    ArgumentStack stack;
    auto playerOid = Services::Events::ExtractArgument<Types::ObjectID>(args);
    auto observerOid = Services::Events::ExtractArgument<Types::ObjectID>(args);
    bool bClearAll = Services::Events::ExtractArgument<int32_t>(args);
    auto *server = Globals::AppManager()->m_pServerExoApp;

    const auto observerPlayerId =
            observerOid == Constants::OBJECT_INVALID ? Constants::PLAYERID_ALL_CLIENTS
                                                     : server->GetPlayerIDByGameObjectID(observerOid);

    if (observerPlayerId == Constants::PLAYERID_INVALIDID)
    {
        LOG_ERROR("The target observer '0x%08x' is not a valid player.", observerPlayerId);
        return stack;
    }

    //clears global override for target PC
    if (observerOid == Constants::OBJECT_INVALID && !bClearAll)
    {
        auto *targetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(playerOid);
        m_RenamePlayerNames[playerOid].erase(Constants::OBJECT_INVALID);
        SendNameUpdate(targetCreature, Constants::PLAYERID_ALL_CLIENTS);
    }
    // clears global override and all personal overrides for that target PC
    else if (observerOid == Constants::OBJECT_INVALID)
    {
        auto *targetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(playerOid);
        m_RenamePlayerNames.erase(playerOid);
        SendNameUpdate(targetCreature, Constants::PLAYERID_ALL_CLIENTS);
    }
    // clears all personal overrides for the observer for any targets
    else if (playerOid == Constants::OBJECT_INVALID)
    {
        for (auto tgt = m_RenamePlayerNames.cbegin(), next_tgt = tgt; tgt != m_RenamePlayerNames.cend(); tgt = next_tgt)
        {
            ++next_tgt;
            if (m_RenamePlayerNames[tgt->first].erase(observerOid))
            {
                auto *targetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(tgt->first);
                if (targetCreature)
                    SendNameUpdate(targetCreature, observerPlayerId);
            }
        }
    }
    // clears personal override for that observer for target oPC
    else
    {
        auto *targetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(playerOid);
        m_RenamePlayerNames[playerOid].erase(observerOid);
        SendNameUpdate(targetCreature, observerPlayerId);
    }
    return stack;
}

}
