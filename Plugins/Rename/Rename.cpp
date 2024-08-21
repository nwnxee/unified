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


using namespace NWNXLib;
using namespace NWNXLib::API;


static Rename::Rename* g_plugin;

//Constants for Player Name states.
const int NWNX_RENAME_PLAYERNAME_DEFAULT = 0;
const int NWNX_RENAME_PLAYERNAME_OBFUSCATE = 1;
const int NWNX_RENAME_PLAYERNAME_OVERRIDE = 2;
const int NWNX_RENAME_PLAYERNAME_ANONYMOUS = 3;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Rename::Rename(services);
    return g_plugin;
}

namespace Rename {

static Hooks::Hook s_WriteGameObjUpdate_UpdateObjectHook;
static Hooks::Hook s_SendServerToPlayerExamineGui_CreatureDataHook;
static Hooks::Hook s_SendServerToPlayerPlayModuleCharacterListResponseHook;
static Hooks::Hook s_SendServerToPlayerPlayerList_AllHook;
static Hooks::Hook s_SendServerToPlayerPlayerList_AddHook;
static Hooks::Hook s_SendServerToPlayerPlayerList_DeleteHook;
static Hooks::Hook s_SendServerToPlayerDungeonMasterUpdatePartyList;
static Hooks::Hook s_SendServerToPlayerPopUpGUIPanelHook;

Rename::Rename(Services::ProxyServiceList* services)
  : Plugin(services)
{
#define REGISTER(func)              \
    ScriptAPI::RegisterEvent(PLUGIN_NAME, #func, std::bind(&Rename::func, this, std::placeholders::_1))

    REGISTER(SetPCNameOverride);
    REGISTER(GetPCNameOverride);
    REGISTER(ClearPCNameOverride);

#undef REGISTER

    m_RenameOnModuleCharList = Config::Get<bool>("ON_MODULE_CHAR_LIST", false);
    m_RenameOnPlayerList = Config::Get<bool>("ON_PLAYER_LIST", true);
    m_RenameAllowDM = Config::Get<bool>("ALLOW_DM", false);
    m_RenameAnonymousPlayerName = Config::Get<std::string>("ANONYMOUS_NAME", "Someone");
    m_RenameOverwriteDisplayName = Config::Get<bool>("OVERWRITE_DISPLAY_NAME", false);

    s_WriteGameObjUpdate_UpdateObjectHook = Hooks::HookFunction(
            &CNWSMessage::WriteGameObjUpdate_UpdateObject,
            &WriteGameObjUpdate_UpdateObjectHook, Hooks::Order::Early);
    s_SendServerToPlayerExamineGui_CreatureDataHook = Hooks::HookFunction(
            &CNWSMessage::SendServerToPlayerExamineGui_CreatureData,
            &SendServerToPlayerExamineGui_CreatureDataHook, Hooks::Order::Early);

#define HOOK_CHAT(_address) \
    static Hooks::Hook CAT(pChatHook, __LINE__) = Hooks::HookFunction(_address, \
    +[](CNWSMessage *thisPtr, uint32_t nPlayerID, OBJECT_ID oidSpeaker, CExoString sSpeakerMessage) -> int32_t \
    { \
        auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(oidSpeaker); \
        auto *observerPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayerID); \
        SetOrRestorePlayerName(true, targetPlayer, observerPlayer); \
        auto retVal = CAT(pChatHook, __LINE__)->CallOriginal<int32_t>(thisPtr, nPlayerID, oidSpeaker, sSpeakerMessage);       \
        SetOrRestorePlayerName(false, targetPlayer, observerPlayer); \
        return retVal; \
    }, Hooks::Order::Early)

    HOOK_CHAT(&CNWSMessage::SendServerToPlayerChat_Party);
    HOOK_CHAT(&CNWSMessage::SendServerToPlayerChat_Shout);
    HOOK_CHAT(&CNWSMessage::SendServerToPlayerChat_Tell);

#undef HOOK_CHAT

    if (m_RenameOnModuleCharList)
    {
        s_SendServerToPlayerPlayModuleCharacterListResponseHook = Hooks::HookFunction(
                &CNWSMessage::SendServerToPlayerPlayModuleCharacterListResponse,
                &SendServerToPlayerPlayModuleCharacterListResponseHook, Hooks::Order::Early);
    }

    if (m_RenameOnPlayerList)
    {
        s_SendServerToPlayerPlayerList_AllHook = Hooks::HookFunction(
                &CNWSMessage::SendServerToPlayerPlayerList_All,
                &SendServerToPlayerPlayerList_AllHook, Hooks::Order::Early);
        s_SendServerToPlayerPlayerList_AddHook = Hooks::HookFunction(
                &CNWSMessage::SendServerToPlayerPlayerList_Add,
                &SendServerToPlayerPlayerList_AddHook, Hooks::Order::Early);
        s_SendServerToPlayerPlayerList_DeleteHook = Hooks::HookFunction(
                &CNWSMessage::SendServerToPlayerPlayerList_Delete,
                &SendServerToPlayerPlayerList_DeleteHook, Hooks::Order::Early);
    }
    else
        LOG_INFO("Not renaming PCs in the player list.");

    if (m_RenameAllowDM)
    {
        BOOL (CNWSMessage::* funcPtr)(uint32_t) = &CNWSMessage::SendServerToPlayerDungeonMasterUpdatePartyList;
        s_SendServerToPlayerDungeonMasterUpdatePartyList = Hooks::HookFunction(
                funcPtr,
                (void*)&SendServerToPlayerDungeonMasterUpdatePartyListHook, Hooks::Order::Early);
        LOG_INFO("DMs will be included with rename logic.");
    }

    // TODO: When shared hooks are executed by exclusive hooks change this to HandlePlayerToServerParty
    s_SendServerToPlayerPopUpGUIPanelHook = Hooks::HookFunction(
            &CNWSMessage::SendServerToPlayerPopUpGUIPanel,
            &SendServerToPlayerPopUpGUIPanelHook, Hooks::Order::Early);

    MessageBus::Subscribe("NWNX_CREATURE_ORIGINALNAME_SIGNAL",
      [](const std::vector<std::string>& message)
      {
          ObjectID objectID = std::strtoul(message[0].c_str(), nullptr, 16);
          auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(objectID);
          auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(objectID);
          if (pCreature && pCreature->m_pStats && pPlayer)
          {
              auto *pPlayerInfo = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID);
              if (pPlayerInfo)
              {
                  g_plugin->m_RenameOriginalNames[objectID] = std::make_tuple(
                          pPlayerInfo->m_sPlayerName,
                          pCreature->m_pStats->m_lsFirstName,
                          pCreature->m_pStats->m_lsLastName);
                  g_plugin->SendNameUpdate(pCreature, Constants::PLAYERID_ALL_CLIENTS);
              }
          }
      });
}

Rename::~Rename()
{
}

CNWSPlayer *Rename::player(ObjectID playerId)
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

    ObjectID observerOid;
    if (observerCreature == nullptr)
        observerOid = Constants::OBJECT_INVALID;
    else
        observerOid = observerPlayer->m_oidNWSObject;

    // There's a moment when a player is just logging in that pStats doesn't exist yet.
    if (targetCreature == nullptr || targetCreature->m_pStats == nullptr || (!g_plugin->m_RenameAllowDM &&
                                                                             (targetCreature->m_pStats->GetIsDM() ||
                                                                              targetCreature->m_nAssociateType == 7 ||
                                                                              targetCreature->m_nAssociateType == 8)) ||
        (observerCreature != nullptr && (observerCreature->m_pStats == nullptr || (!g_plugin->m_RenameAllowDM &&
                                                                                   (observerCreature->m_pStats->GetIsDM() ||
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

void Rename::SetPlayerNameAsObservedBy(CNWSCreature *targetCreature, ObjectID observerOid, bool playerList)
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
            targetCreature->m_pStats->m_lsFirstName = Utils::CreateLocString(overrideName.CStr());
            targetCreature->m_pStats->m_lsLastName = Utils::CreateLocString("");
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
            targetCreature->m_pStats->m_lsFirstName = Utils::CreateLocString(overrideName.CStr());
            targetCreature->m_pStats->m_lsLastName = Utils::CreateLocString("");
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

        if (g_plugin->m_RenameOverwriteDisplayName &&
            g_plugin->m_RenamePlayerNames[targetCreature->m_idSelf].count(Constants::OBJECT_INVALID))
        {
            targetCreature->m_sDisplayName = std::get<0>(g_plugin->m_RenamePlayerNames[targetCreature->m_idSelf][Constants::OBJECT_INVALID]);
        }
        else
        {
            targetCreature->m_sDisplayName = "";
        }
    }
}

void Rename::WriteGameObjUpdate_UpdateObjectHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pAreaObject,
                                                 CLastUpdateObject *pLastUpdateObject, uint32_t nObjectUpdatesRequired,
                                                 uint32_t nObjectAppearanceUpdatesRequired)
{
    auto *pTargetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pAreaObject->m_idSelf);
    SetOrRestorePlayerName(true, pTargetPlayer, pPlayer);
    s_WriteGameObjUpdate_UpdateObjectHook->CallOriginal<void>(pMessage, pPlayer, pAreaObject, pLastUpdateObject,
                                                              nObjectUpdatesRequired, nObjectAppearanceUpdatesRequired);
    SetOrRestorePlayerName(false, pTargetPlayer, pPlayer);
}

int32_t Rename::SendServerToPlayerExamineGui_CreatureDataHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, ObjectID oidCreatureID)
{
    auto *pTargetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(oidCreatureID);
    SetOrRestorePlayerName(true, pTargetPlayer, pPlayer);
    auto retVal = s_SendServerToPlayerExamineGui_CreatureDataHook->CallOriginal<int32_t>(pMessage, pPlayer, oidCreatureID);
    SetOrRestorePlayerName(false, pTargetPlayer, pPlayer);
    return retVal;
}

// This can't work on per target basis as the player logging in hasn't selected their PC yet but it will still work for a global override.
int32_t Rename::SendServerToPlayerPlayModuleCharacterListResponseHook(CNWSMessage *thisPtr, PlayerID nPlayerId, ObjectID nCharacterId, int32_t bAdd)
{
    auto *targetPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(nCharacterId);
    auto *observerPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayerId);

    SetOrRestorePlayerName(true, targetPlayer, observerPlayer);
    auto retVal = s_SendServerToPlayerPlayModuleCharacterListResponseHook->CallOriginal<int32_t>(thisPtr, nPlayerId, nCharacterId, bAdd);
    SetOrRestorePlayerName(false, targetPlayer, observerPlayer);

    return retVal;
}

int32_t Rename::SendServerToPlayerDungeonMasterUpdatePartyListHook(CNWSMessage *pMessage, PlayerID nPlayerID)
{
    g_plugin->GlobalNameChange(true, nPlayerID, Constants::PLAYERID_ALL_PLAYERS);
    auto retVal = s_SendServerToPlayerDungeonMasterUpdatePartyList->CallOriginal<int32_t>(pMessage, nPlayerID);
    g_plugin->GlobalNameChange(false, nPlayerID, Constants::PLAYERID_ALL_PLAYERS);
    return retVal;
}

int32_t Rename::SendServerToPlayerPlayerList_AllHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer)
{
    g_plugin->GlobalNameChange(true, pPlayer->m_nPlayerID, Constants::PLAYERID_ALL_PLAYERS);
    auto retVal = s_SendServerToPlayerPlayerList_AllHook->CallOriginal<int32_t>(pMessage, pPlayer);
    g_plugin->GlobalNameChange(false, pPlayer->m_nPlayerID, Constants::PLAYERID_ALL_PLAYERS);
    return retVal;
}

int32_t Rename::SendServerToPlayerPlayerList_AddHook(CNWSMessage *pMessage, PlayerID nPlayerId, CNWSPlayer *pNewPlayer)
{
    if (!g_plugin->m_RenameAllowDM && nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS)
        return s_SendServerToPlayerPlayerList_AddHook->CallOriginal<int32_t>(pMessage, nPlayerId, pNewPlayer);

    g_plugin->GlobalNameChange(true, nPlayerId, pNewPlayer->m_nPlayerID);
    auto retVal = s_SendServerToPlayerPlayerList_AddHook->CallOriginal<int32_t>(pMessage, nPlayerId, pNewPlayer);
    g_plugin->m_RenameAddedToPlayerList.insert(pNewPlayer->m_oidNWSObject);
    g_plugin->GlobalNameChange(false, nPlayerId, pNewPlayer->m_nPlayerID);

    return retVal;
}

int32_t Rename::SendServerToPlayerPlayerList_DeleteHook(CNWSMessage *pMessage, PlayerID nPlayerId, CNWSPlayer *pNewPlayer)
{
    if (!g_plugin->m_RenameAllowDM && nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS)
        return s_SendServerToPlayerPlayerList_DeleteHook->CallOriginal<int32_t>(pMessage, nPlayerId, pNewPlayer);

    g_plugin->m_RenameAddedToPlayerList.erase(pNewPlayer->m_oidNWSObject);
    return s_SendServerToPlayerPlayerList_DeleteHook->CallOriginal<int32_t>(pMessage, nPlayerId, pNewPlayer);
}

int32_t Rename::SendServerToPlayerPopUpGUIPanelHook(
            CNWSMessage *pMessage,
            ObjectID observerOid,
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
    return s_SendServerToPlayerPopUpGUIPanelHook->CallOriginal<int32_t>(pMessage, observerOid, nGuiPanel, bGUIOption1,
                                                                 bGUIOption2, nStringReference, p_sStringReference);
}
void Rename::GlobalNameChange(
        bool before,
        PlayerID observerPlayerId,
        PlayerID targetPlayerId)
{
    auto *server = Globals::AppManager()->m_pServerExoApp;
    std::vector<PlayerID> observersToNotify;
    std::vector<PlayerID> targetsToNotify;

    if (observerPlayerId == Constants::PLAYERID_ALL_PLAYERS || observerPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS)
    {
        for (auto *observerPlayer : Globals::AppManager()->m_pServerExoApp->GetPlayerList())
        {
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
        for (auto *targetPlayer : Globals::AppManager()->m_pServerExoApp->GetPlayerList())
        {
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
            auto *targetPlayer = server->GetClientObjectByPlayerId(targetPid);
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
                                playerInfo->m_sPlayerName = CExoString(GenerateRandomPlayerName(7, targetOid).c_str());
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
            auto *observerPlayer = server->GetClientObjectByPlayerId(observerPid);
            SetOrRestorePlayerName(before, targetPlayer, observerPlayer, true);
        }
    }
}

std::string Rename::GenerateRandomPlayerName(size_t length, ObjectID targetOid)
{
    auto iter = m_ObfuscatedNames.find(targetOid);
    if (iter != m_ObfuscatedNames.end())
        return iter->second;
    static std::mt19937 rngEngine(std::random_device{}());
    static const std::string charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::uniform_int_distribution<int> distribution(0, charSet.length() - 1);
    std::string randomPlayername;
    randomPlayername.reserve(length+1);
    for (size_t i = 0; i < length; ++i)
    {
        randomPlayername += charSet[distribution(rngEngine)];
    }
    m_ObfuscatedNames[targetOid] = randomPlayername;
    return randomPlayername;
}

void Rename::SendNameUpdate(CNWSCreature *targetCreature, PlayerID observerPlayerId)
{
    std::vector<PlayerID> playersToNotify;
    auto *server = Globals::AppManager()->m_pServerExoApp;

    if (observerPlayerId == Constants::PLAYERID_ALL_CLIENTS)
    {
        for (auto *player : Globals::AppManager()->m_pServerExoApp->GetPlayerList())
        {
            playersToNotify.emplace_back(player->m_nPlayerID);
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
        auto *observerPlayerObject = server->GetClientObjectByPlayerId(pid);
        if (observerPlayerObject == nullptr)
            continue;
        auto targets = g_plugin->m_RenamePlayerNames[targetCreature->m_idSelf];

        // If the update is to all clients but the observer has a personal override of the target's name then skip
        if (observerPlayerId == Constants::PLAYERID_ALL_CLIENTS && targets.count(observerPlayerObject->m_oidNWSObject))
            continue;

        // The client may crash if we send an object update for a creature that does not exist in its
        // last update object list
        if (!IsCreatureInLastUpdateObjectList(observerPlayerObject, targetCreature->m_idSelf))
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
                message->SendServerToPlayerMessage(pid,
                                                   Constants::MessageMajor::GameObjectUpdate,
                                                   Constants::MessageGameObjectUpdateMinor::ObjectList,
                                                   data, size);
                success = true;
            }

            if (m_RenameOnPlayerList)
                message->SendServerToPlayerPlayerList_All(observerPlayerObject);
        }
        LOG_DEBUG("%s sending name update message for observer (PlayerID): '0x%08x', target (ObjectID): '0x%08x'.",
                  success ? "Succeeded" : "Failed", pid, targetCreature->m_idSelf);
    }
}

bool Rename::IsCreatureInLastUpdateObjectList(CNWSPlayer *player, ObjectID creatureId)
{
    auto *lastUpdateObj = player->GetLastUpdateObject(creatureId);
    if (lastUpdateObj)
        return true;

    auto *partyObjectsList = &player->m_lstActivePartyObjectsLastUpdate;

    for (int i = 0; i < partyObjectsList->num; i++)
    {
        auto *partyMember = partyObjectsList->element[i];
        if (partyMember && partyMember->m_nPlayerId == creatureId)
            return true;
    }

    return false;
}

ArgumentStack Rename::SetPCNameOverride(ArgumentStack&& args)
{
    auto targetOid = ScriptAPI::ExtractArgument<ObjectID>(args);
    if (auto *targetPlayer = player(targetOid))
    {
        auto *server = Globals::AppManager()->m_pServerExoApp;
        auto *targetCreature = server->GetCreatureByGameObjectID(targetOid);
        if (targetCreature == nullptr)
        {
            LOG_ERROR("No creature object found for Player ID '0x%08x', oidNWSObject '%x'", targetPlayer->m_nPlayerID, targetOid);
            return ScriptAPI::Arguments();
        }
        const auto newName = ScriptAPI::ExtractArgument<std::string>(args);
        const auto sPrefix = ScriptAPI::ExtractArgument<std::string>(args);
        const auto sSuffix = ScriptAPI::ExtractArgument<std::string>(args);
        auto bPlayerNameState = ScriptAPI::ExtractArgument<int>(args);
        const auto observerOid = ScriptAPI::ExtractArgument<ObjectID>(args);

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
            return ScriptAPI::Arguments();
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
            return ScriptAPI::Arguments();
        }

        SendNameUpdate(targetCreature, observerPlayerId);
    }
    return ScriptAPI::Arguments();
}

ArgumentStack Rename::GetPCNameOverride(ArgumentStack &&args)
{
    auto targetOid = ScriptAPI::ExtractArgument<ObjectID>(args);
    std::string retVal;
    if (auto *targetPlayer = player(targetOid))
    {
        auto *targetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(targetOid);
        if (!targetCreature)
        {
            LOG_ERROR("No creature object found for Player %x, oidNWSObject %x", targetPlayer->m_nPlayerID, targetOid);
            return ScriptAPI::Arguments();
        }
        auto observerOid = ScriptAPI::ExtractArgument<ObjectID>(args);
        if(m_RenamePlayerNames[targetOid].find(observerOid) != m_RenamePlayerNames[targetOid].end())
            retVal = std::get<0>(m_RenamePlayerNames[targetOid][observerOid]).CStr();
        else if(m_RenamePlayerNames[targetOid].find(Constants::OBJECT_INVALID) != m_RenamePlayerNames[targetOid].end())
            retVal = std::get<0>(m_RenamePlayerNames[targetOid][Constants::OBJECT_INVALID]).CStr();
    }
    return ScriptAPI::Arguments(retVal);
}

ArgumentStack Rename::ClearPCNameOverride(ArgumentStack &&args)
{
    auto playerOid = ScriptAPI::ExtractArgument<ObjectID>(args);
    auto observerOid = ScriptAPI::ExtractArgument<ObjectID>(args);
    bool bClearAll = ScriptAPI::ExtractArgument<int32_t>(args);
    auto *server = Globals::AppManager()->m_pServerExoApp;

    const auto observerPlayerId =
            observerOid == Constants::OBJECT_INVALID ? Constants::PLAYERID_ALL_CLIENTS
                                                     : server->GetPlayerIDByGameObjectID(observerOid);

    if (observerPlayerId == Constants::PLAYERID_INVALIDID)
    {
        LOG_ERROR("The target observer '0x%08x' is not a valid player.", observerPlayerId);
        return ScriptAPI::Arguments();
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
    return ScriptAPI::Arguments();
}

}
