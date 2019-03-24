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
#include "API/CExoLinkedListTemplatedCNWSClient.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Functions.hpp"
#include "Services/Config/Config.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Services/Messaging/Messaging.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooking::FunctionHook* m_SendServerToPlayerPopUpGUIPanelHook;
static Hooking::FunctionHook* m_SendServerToPlayerPlayModuleCharacterListResponseHook;

static ViewPtr<Rename::Rename> g_plugin;

//key names for Per Object Storage
const std::string firstNameKey = "REAL_FIRST_NAME";
const std::string lastNameKey = "REAL_LAST_NAME";
const std::string playerNameKey = "REAL_PLAYER_NAME";
const std::string playerNameOverrideStateKey = "PLAYER_NAME_OVERRIDE_STATE";
const std::string overrideNameKey = "OVERRIDE_NAME";
const std::string displayNameKey = "DISPLAY_NAME";
const std::string addedToPlayerListKey = "ADDED_TO_PLAYER_LIST";

//Constants for Player Name states.
const int NWNX_RENAME_PLAYERNAME_DEFAULT = 0;
const int NWNX_RENAME_PLAYERNAME_OBFUSCATE = 1;
const int NWNX_RENAME_PLAYERNAME_OVERRIDE = 2;

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

#undef REGISTER

    m_RenameOnModuleCharList = GetServices()->m_config->Get<int32_t>("ON_MODULE_CHAR_LIST", 0);
    m_RenameOnPlayerList = GetServices()->m_config->Get<bool>("ON_PLAYER_LIST", true);

    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__WriteGameObjUpdate_UpdateObject,
            int32_t, CNWSMessage *, CNWSPlayer *, CNWSObject *, CLastUpdateObject *, uint32_t, uint32_t>(
            &WriteGameObjUpdate_UpdateObjectHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__SendServerToPlayerExamineGui_CreatureData,
            int32_t, CNWSMessage *, CNWSPlayer *, Types::ObjectID>(&SendServerToPlayerExamineGui_CreatureDataHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__SendServerToPlayerChat_Party,
            int32_t, CNWSMessage*, Types::PlayerID, Types::ObjectID, CExoString*>(&SendServerToPlayerChatHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__SendServerToPlayerChat_Shout,
            int32_t, CNWSMessage*, Types::PlayerID, Types::ObjectID, CExoString*>(&SendServerToPlayerChatHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__SendServerToPlayerChat_Tell,
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
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSMessage__SendServerToPlayerPlayModuleCharacterListResponse,
                int32_t, CNWSMessage *, Types::PlayerID, Types::ObjectID, int32_t>(&SendServerToPlayerPlayModuleCharacterListResponseHook);
        m_SendServerToPlayerPlayModuleCharacterListResponseHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSMessage__SendServerToPlayerPlayModuleCharacterListResponse);
    }

    if (m_RenameOnPlayerList)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__SendServerToPlayerPlayerList_All,
                int32_t, CNWSMessage*, CNWSPlayer*>(&SendServerToPlayerPlayerList_AllHook);
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__SendServerToPlayerPlayerList_Add,
                int32_t, CNWSMessage*, Types::PlayerID, CNWSPlayer*>(&SendServerToPlayerPlayerList_AddHook);
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__SendServerToPlayerPlayerList_Delete,
                int32_t, CNWSMessage*, Types::PlayerID, CNWSPlayer*>(&SendServerToPlayerPlayerList_DeleteHook);
    }
    else
        LOG_INFO("Not renaming PCs in the player list.");

    // TODO: When shared hooks are executed by exclusive hooks change this to HandlePlayerToServerParty
    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSMessage__SendServerToPlayerPopUpGUIPanel,
            int32_t, CNWSMessage*, Types::ObjectID, int32_t, int32_t, int32_t, int32_t, CExoString*>(&SendServerToPlayerPopUpGUIPanelHook);
    m_SendServerToPlayerPopUpGUIPanelHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSMessage__SendServerToPlayerPopUpGUIPanel);

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

void Rename::SetOrRestorePlayerName(NWNXLib::Services::Hooks::CallType cType,
                                    CNWSPlayer *targetPlayer, CNWSPlayer *observerPlayer)
{
    if (targetPlayer == nullptr ||
        observerPlayer == nullptr ||
        targetPlayer == observerPlayer)
        return;

    auto *targetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(targetPlayer->m_oidNWSObject);
    auto *observerCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(observerPlayer->m_oidNWSObject);

    Types::ObjectID observerOid;
    if (observerCreature == nullptr)
        observerOid = Constants::PLAYERID_ALL_PLAYERS;
    else
        observerOid = observerPlayer->m_oidNWSObject;

    // There's a moment when a player is just logging in that pStats doesn't exist yet.
    if (targetCreature == nullptr || targetCreature->m_pStats == nullptr || targetCreature->m_pStats->m_bIsDM ||
            (observerCreature != nullptr && (observerCreature->m_pStats == nullptr || observerCreature->m_pStats->m_bIsDM)))
    {
        return;
    }

    if (cType == Services::Hooks::CallType::BEFORE_ORIGINAL)
        SetPlayerNameAsObservedBy(targetCreature, observerOid);
    else
        RestorePlayerName(targetCreature);

}

void Rename::SetPlayerNameAsObservedBy(CNWSCreature *targetCreature, Types::ObjectID observerOid)
{
    Rename &plugin = *g_plugin;
    auto targetOid = targetCreature->m_idSelf;
    auto *pPOS = plugin.GetServices()->m_perObjectStorage.get();
    std::string displayNameKeyObserver = displayNameKey + ":" + Utils::ObjectIDToString(observerOid);
    std::string overrideNameKeyObserver = overrideNameKey + ":" + Utils::ObjectIDToString(observerOid);
    std::string displayName = *pPOS->Get<std::string>(targetOid, displayNameKeyObserver);
    std::string overrideName = *pPOS->Get<std::string>(targetOid, overrideNameKeyObserver);
    if (!displayName.empty())
    {
        targetCreature->m_pStats->m_lsFirstName = plugin.ContainString(overrideName);
        targetCreature->m_pStats->m_lsLastName = plugin.ContainString("");
        targetCreature->m_sDisplayName = displayName.c_str();
        LOG_DEBUG("Observer %x will see %x as %s due to personal override", observerOid, targetOid, overrideName.c_str());
    }
    else
    {
        std::string allClients = Utils::ObjectIDToString(Constants::PLAYERID_ALL_CLIENTS);
        displayName = *pPOS->Get<std::string>(targetOid, displayNameKey + ":" + allClients);
        overrideName = *pPOS->Get<std::string>(targetOid, overrideNameKey + ":" + allClients);
        if (!displayName.empty())
        {
            targetCreature->m_pStats->m_lsFirstName = plugin.ContainString(overrideName);
            targetCreature->m_pStats->m_lsLastName = plugin.ContainString("");
            targetCreature->m_sDisplayName = displayName.c_str();
            LOG_DEBUG("Observer %x will see %x as %s due to global override", observerOid, targetOid, overrideName.c_str());
        }
    }
}

void Rename::RestorePlayerName(CNWSCreature *targetCreature)
{
    Rename &plugin = *g_plugin;
    auto *pPOS = plugin.GetServices()->m_perObjectStorage.get();
    std::string lsFirstName = *pPOS->Get<std::string>(targetCreature->m_idSelf, firstNameKey);
    std::string lsLastName = *pPOS->Get<std::string>(targetCreature->m_idSelf, lastNameKey);
    if (!lsFirstName.empty())
    {
        targetCreature->m_pStats->m_lsFirstName = plugin.ContainString(lsFirstName);
        targetCreature->m_pStats->m_lsLastName = plugin.ContainString(lsLastName);
        targetCreature->m_sDisplayName = "";
    }
}

void Rename::WriteGameObjUpdate_UpdateObjectHook(
        NWNXLib::Services::Hooks::CallType cType,
        CNWSMessage*,
        CNWSPlayer *observerPlayer,
        CNWSObject *targetObject,
        CLastUpdateObject*,
        uint32_t,
        uint32_t)
{
    auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(targetObject->m_idSelf);
    SetOrRestorePlayerName(cType, targetPlayer, observerPlayer);
}

void Rename::SendServerToPlayerExamineGui_CreatureDataHook(
        NWNXLib::Services::Hooks::CallType cType,
        CNWSMessage*,
        CNWSPlayer *observerPlayer,
        Types::ObjectID targetOid)
{
    auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(targetOid);
    SetOrRestorePlayerName(cType, targetPlayer, observerPlayer);
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

    Rename& plugin = *g_plugin;
    auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(targetOid);
    auto *client = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(observerPlayerId, 0);
    auto *observerPlayer = static_cast<API::CNWSPlayer *>(client);
    if (plugin.m_RenameOnModuleCharList == 1 || plugin.m_RenameOnModuleCharList == 2)
    {
        SetOrRestorePlayerName(Services::Hooks::CallType::BEFORE_ORIGINAL, targetPlayer, observerPlayer);
    }

    int32_t retVal = -1;

    if (plugin.m_RenameOnModuleCharList >= 2)
    {
        thisPtr->CreateWriteMessage(sizeof(observerPlayerId), observerPlayerId, true);

        thisPtr->WriteBOOL(add);
        thisPtr->WriteDWORD(targetOid, 32);

        if (add)
        {
            auto *creature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(targetOid);
            if (creature)
            {
                thisPtr->WriteCExoLocStringServer(creature->GetFirstName(), creature->GetGender());
                thisPtr->WriteCExoLocStringServer(creature->GetLastName(), creature->GetGender());

                uint16_t portraitId = creature->GetPortraitId();
                thisPtr->WriteWORD(portraitId, 16);
                if (portraitId >= 0xFFFE)
                {
                    thisPtr->WriteCResRef(creature->GetPortrait(), 16);
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

    if (plugin.m_RenameOnModuleCharList == 1 || plugin.m_RenameOnModuleCharList == 2)
    {
        SetOrRestorePlayerName(Services::Hooks::CallType::AFTER_ORIGINAL, targetPlayer, observerPlayer);
    }
    return retVal;
}

void Rename::SendServerToPlayerChatHook(
        NWNXLib::Services::Hooks::CallType cType,
        CNWSMessage*,
        Types::PlayerID observerPlayerId,
        Types::ObjectID targetOid,
        CExoString*)
{
    auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(targetOid);
    auto *client = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(observerPlayerId, 0);
    auto *observerPlayer = static_cast<API::CNWSPlayer*>(client);
    SetOrRestorePlayerName(cType, targetPlayer, observerPlayer);
}

void Rename::SendServerToPlayerPlayerList_AllHook(
        Services::Hooks::CallType cType,
        CNWSMessage*,
        CNWSPlayer *observerPlayer)
{
    Rename& plugin = *g_plugin;
    plugin.GlobalNameChange(cType, observerPlayer->m_nPlayerID, Constants::PLAYERID_ALL_PLAYERS);
}

void Rename::SendServerToPlayerPlayerList_AddHook(
        Services::Hooks::CallType cType,
        CNWSMessage*,
        Types::PlayerID observerPlayerId,
        CNWSPlayer *targetPlayer)
{
    if (observerPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS)
        return;

    Rename& plugin = *g_plugin;
    if (cType == Services::Hooks::CallType::AFTER_ORIGINAL)
    {
        auto *pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
        pPOS->Set(targetPlayer->m_nPlayerID, addedToPlayerListKey, true);
    }
    plugin.GlobalNameChange(cType, observerPlayerId, targetPlayer->m_nPlayerID);
}

void Rename::SendServerToPlayerPlayerList_DeleteHook(
        Services::Hooks::CallType cType,
        CNWSMessage*,
        Types::PlayerID observerPlayerId,
        CNWSPlayer *targetPlayer)
{
    if (observerPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS)
        return;

    if (cType == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        auto *pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
        pPOS->Remove(targetPlayer->m_nPlayerID, addedToPlayerListKey);
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
        Rename& plugin = *g_plugin;
        auto *pPOS = plugin.GetServices()->m_perObjectStorage.get();
        std::string overrideNameKeyObserver = overrideNameKey + ":" + Utils::ObjectIDToString(observerOid);
        std::string overrideName = *pPOS->Get<std::string>(targetOid, overrideNameKeyObserver);
        if (!overrideName.empty())
        {
            *p_sStringReference = CExoString(overrideName.c_str());
        }
        else
        {
            overrideName = *pPOS->Get<std::string>(targetOid, overrideNameKey + ":" + Utils::ObjectIDToString(
                    Constants::PLAYERID_ALL_CLIENTS));
            if (!overrideName.empty())
            {
                *p_sStringReference = CExoString(overrideName.c_str());
            }
        }
    }
    return m_SendServerToPlayerPopUpGUIPanelHook->CallOriginal<int32_t>(pMessage, observerOid, nGuiPanel, bGUIOption1,
                                                                 bGUIOption2, nStringReference, p_sStringReference);
}
void Rename::GlobalNameChange(
        NWNXLib::Services::Hooks::CallType cType,
        Types::PlayerID observerPlayerId,
        Types::PlayerID targetPlayerId)
{
    auto *server = Globals::AppManager()->m_pServerExoApp;
    auto *pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
    auto *playerList = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    std::vector<Types::PlayerID> observersToNotify;
    std::vector<Types::PlayerID> targetsToNotify;

    if (observerPlayerId == Constants::PLAYERID_ALL_PLAYERS)
    {
        for (auto *head = playerList->pHead; head; head = head->pNext)
        {
            auto *observerClient = static_cast<API::CNWSClient*>(head->pObject);
            observersToNotify.emplace_back(observerClient->m_nPlayerID);
        }
    }
    else if (observerPlayerId != Constants::OBJECT_INVALID)
        observersToNotify.emplace_back(observerPlayerId);

    if (targetPlayerId == Constants::PLAYERID_ALL_PLAYERS)
    {
        for (auto *head = playerList->pHead; head; head = head->pNext)
        {
            auto *targetClient = static_cast<API::CNWSClient*>(head->pObject);
            targetsToNotify.emplace_back(targetClient->m_nPlayerID);
        }
    }
    else if (targetPlayerId != Constants::OBJECT_INVALID)
        targetsToNotify.emplace_back(targetPlayerId);

    std::string lsFirstName;
    std::string lsLastName;
    auto *pNetLayer = server->GetNetLayer();

    for (auto &observerPid : observersToNotify)
    {
        auto *observerClient =  server->GetClientObjectByPlayerId(observerPid, 0);
        auto *observerPlayer = static_cast<API::CNWSPlayer*>(observerClient);

        for (auto &targetPid : targetsToNotify)
        {
            auto *client =  server->GetClientObjectByPlayerId(targetPid, 0);
            auto *targetPlayer = static_cast<API::CNWSPlayer*>(client);
            auto targetOid = targetPlayer->m_oidNWSObject;
            auto *targetCreature = server->GetCreatureByGameObjectID(targetOid);
            if (cType == Services::Hooks::CallType::AFTER_ORIGINAL)
            {
                lsFirstName = *pPOS->Get<std::string>(targetOid, firstNameKey);
                lsLastName = *pPOS->Get<std::string>(targetOid, lastNameKey);
            }
            else
            {
                lsFirstName = *pPOS->Get<std::string>(targetOid, overrideNameKey + ":" + Utils::ObjectIDToString(Constants::PLAYERID_ALL_CLIENTS));
                lsLastName = std::string("");
            }
            if (targetCreature && !lsFirstName.empty())
            {
                if (static_cast<bool>(*pPOS->Get<int>(targetOid, playerNameOverrideStateKey + ":" + Utils::ObjectIDToString(Constants::PLAYERID_ALL_CLIENTS))))
                {
                    auto playerInfo = pNetLayer->GetPlayerInfo(targetPid);
                    if (cType == Services::Hooks::CallType::AFTER_ORIGINAL)
                    {
                        playerInfo->m_sPlayerName = CExoString((*pPOS->Get<std::string>(targetOid, playerNameKey)).c_str());
                    }
                    else
                    {
                        switch ((*pPOS->Get<int>(targetOid, playerNameOverrideStateKey + ":" + Utils::ObjectIDToString(Constants::PLAYERID_ALL_CLIENTS))))
                        {
                            case NWNX_RENAME_PLAYERNAME_OBFUSCATE:
                                playerInfo->m_sPlayerName = CExoString(GenerateRandomPlayerName(7).c_str());
                                break;
                            case NWNX_RENAME_PLAYERNAME_OVERRIDE:
                                playerInfo->m_sPlayerName = CExoString(lsFirstName.c_str());
                                break;
                        }
                    }
                }
            }
            if (m_RenameOnPlayerList)
                SetOrRestorePlayerName(cType, targetPlayer, observerPlayer);
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

ArgumentStack Rename::SetPCNameOverride(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto targetOid = Services::Events::ExtractArgument<Types::ObjectID>(args);
    if (auto *targetPlayer = player(targetOid))
    {
        auto *server = Globals::AppManager()->m_pServerExoApp;
        auto *targetObject = server->GetCreatureByGameObjectID(targetOid);
        if (targetObject == nullptr)
        {
            LOG_ERROR("No creature object found for Player ID '0x%08x', oidNWSObject '%x'",
                      targetPlayer->m_nPlayerID, targetOid);
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

        auto *observerObject = server->GetCreatureByGameObjectID(observerOid);
        if (observerOid != Constants::OBJECT_INVALID && observerObject == nullptr)
        {
            LOG_ERROR("No creature object found for target '%x'", observerOid);
            return stack;
        }

        const auto targetPlayerId = targetPlayer->m_nPlayerID;
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

        auto *pPOS = g_plugin->GetServices()->m_perObjectStorage.get();

        std::string keyLookup =
                observerOid == Constants::OBJECT_INVALID ? Utils::ObjectIDToString(Constants::PLAYERID_ALL_CLIENTS)
                                                         : Utils::ObjectIDToString(observerOid);

        // Set our override values
        pPOS->Set(targetOid, displayNameKey + ":" + keyLookup, fullDisplayName);
        pPOS->Set(targetOid, overrideNameKey + ":" + keyLookup, newName);
        pPOS->Set(targetOid, playerNameOverrideStateKey + ":" + keyLookup, bPlayerNameState);

        // Store the original values
        auto *pPlayerInfo = server->GetNetLayer()->GetPlayerInfo(targetPlayerId);
        pPOS->Set(targetOid, playerNameKey, std::string(pPlayerInfo->m_sPlayerName.CStr()));
        pPOS->Set(targetOid, firstNameKey, Utils::ExtractLocString(targetObject->m_pStats->m_lsFirstName));
        pPOS->Set(targetOid, lastNameKey, Utils::ExtractLocString(targetObject->m_pStats->m_lsLastName));

        // If we've ran this before the PC has even been added to the other clients' player list then there's
        // nothing else we need to do, the hooks will take care of doing the renames. If we don't skip this
        // then the SendServerToPlayerPlayerList_All below runs before the server has even ran a
        // SendServerToPlayerPlayerList_Add and weird things happen(tm)
        if (!*pPOS->Get<int>(targetPlayerId, addedToPlayerListKey))
            return stack;

        std::vector<Types::PlayerID> playersToNotify;

        if (observerPlayerId == Constants::PLAYERID_ALL_CLIENTS)
        {
            // Get all the connected players except the targetPlayerId, we don't update their own name with ALL_CLIENTS
            auto *playerList = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;

            for (auto *head = playerList->pHead; head; head = head->pNext)
            {
                auto *client = static_cast<API::CNWSClient*>(head->pObject);
                if (client && client->m_nPlayerID != targetPlayerId)
                    playersToNotify.emplace_back(client->m_nPlayerID);
            }
        }
        else
        {
            playersToNotify.emplace_back(observerPlayerId);
        }

        auto *message = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        for (auto &pid : playersToNotify)
        {
            bool success = false;
            auto *observerPlayerObject = static_cast<API::CNWSPlayer*>(server->GetClientObjectByPlayerId(pid, 0));

            if (observerPlayerObject != nullptr)
            {
                // Write a message notifying an object update.
                message->CreateWriteMessage(0x400, pid, 1);

                // We don't need one for our update.
                // However, the appearance update is contingent on receiving a pointer which isn't nullptr.
                auto *lastUpdateObj = reinterpret_cast<API::CLastUpdateObject*>(0xDEADBEEF);
                message->WriteGameObjUpdate_UpdateObject(observerPlayerObject, targetObject, lastUpdateObj, 0, 0x400);

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
                                                  success ? "Succeeded" : "Failed", pid, targetOid);
        }
    }
    return stack;
}

ArgumentStack Rename::GetPCNameOverride(ArgumentStack &&args)
{
    ArgumentStack stack;
    auto playerObjectID = Services::Events::ExtractArgument<Types::ObjectID>(args);
    std::string retVal;
    if (auto *pPlayer = player(playerObjectID))
    {
        auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(playerObjectID);
        if (!pCreature)
        {
            LOG_ERROR("No creature object found for Player ID %x, oidNWSObject %x",
                      pPlayer->m_oidPCObject, playerObjectID);
            return stack;
        }
        auto targetId = Services::Events::ExtractArgument<Types::ObjectID>(args);
        if (targetId == Constants::OBJECT_INVALID)
            targetId = Constants::PLAYERID_ALL_CLIENTS;
        auto *pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
        retVal = *pPOS->Get<std::string>(playerObjectID, displayNameKey + ":" + Utils::ObjectIDToString(targetId));
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

}
