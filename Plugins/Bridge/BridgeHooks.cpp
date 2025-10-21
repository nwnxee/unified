#include "BridgeHooks.hpp"
#include "Bridge.hpp"
#include "BridgeMessage.hpp"
#include "API/Functions.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "API/API/CNWSPlayer.hpp"
#include "API/API/CVirtualMachine.hpp"
#include "API/API/CNWSCreature.hpp"
#include "API/API/CNWSModule.hpp"
#include "API/API/CNWSCreatureStats.hpp"
#include "API/API/CNWSMessage.hpp"
#include "API/API/CNWSObject.hpp"
#include "API/API/CAppManager.hpp"
#include "API/API/CServerExoApp.hpp"
#include "API/API/CServerExoAppInternal.hpp"
#include "API/API/CExoLinkedListInternal.hpp"
#include "API/API/CExoLinkedList.hpp"
#include "API/API/CExoLinkedListNode.hpp"
#include "API/API/CNetLayer.hpp"
#include "API/API/CNetLayerPlayerInfo.hpp"
#include "API/API/CServerInfo.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Bridge
{
Bridge* Hooks::s_bridge = nullptr;
Hooking::FunctionHook* pSendPlayerListAllHook;
Hooking::FunctionHook* pHandlePlayerChatHook;
}

void Bridge::Hooks::InitHooks(Bridge* bridge, NWNXLib::Services::HooksProxy* hooker)
{
    s_bridge = bridge;

    hooker->RequestSharedHook<NWNXLib::API::Functions::_ZN13CServerExoApp8MainLoopEv, void>(
        &CServerExoApp__MainLoop);
    hooker->RequestSharedHook<NWNXLib::API::Functions::_ZN21CServerExoAppInternal10InitializeEv, void>(
        &CServerExoAppInternal__Initialize);
    hooker->RequestExclusiveHook<NWNXLib::API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AllEP10CNWSPlayer>(
        &CNWSMessage__SendServerToPlayerPlayerList_All);
    pSendPlayerListAllHook = hooker->FindHookByAddress(API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AllEP10CNWSPlayer);
    hooker->RequestExclusiveHook<NWNXLib::API::Functions::_ZN11CNWSMessage31HandlePlayerToServerChatMessageEP10CNWSPlayerh>(
        &CNWSMessage__HandlePlayerToServerChatMessage);
    pHandlePlayerChatHook = hooker->FindHookByAddress(API::Functions::_ZN11CNWSMessage31HandlePlayerToServerChatMessageEP10CNWSPlayerh);
    hooker->RequestSharedHook<NWNXLib::API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AddEjP10CNWSPlayer, void>(
        &CNWSMessage__SendServerToPlayerPlayerList_Add);
    hooker->RequestSharedHook<NWNXLib::API::Functions::_ZN11CNWSMessage35SendServerToPlayerPlayerList_DeleteEjP10CNWSPlayer, void>(
        &CNWSMessage__SendServerToPlayerPlayerList_Delete);
}

void Bridge::Hooks::CServerExoApp__MainLoop(bool before, CServerExoApp*)
{
    if (before || !s_bridge || !s_bridge->IsConnected())
        return;
    static int ticks = 0;
    if (ticks < 50)
    {
        ticks++;
    }
    else
    {
        ticks = 0;
        if (auto event = s_bridge->GetBridgeInstance()->GetIncomingEvent())
        {
            s_bridge->GetBridgeInstance()->HandleIncomingEvent(std::move(event));
        }
    }
}

int32_t Bridge::Hooks::SendFakeChatMessage(const std::string& message, uint32_t targetId,
    PlayerInfo* playerInfo, NWNXLib::API::Constants::MessageChatMinor::TYPE channel)
{
    if (!playerInfo)
        return 0;

    auto chatType = channel & 0xFu;
    if (chatType != Constants::MessageChatMinor::Tell && chatType != Constants::MessageChatMinor::Shout
        && chatType != Constants::MessageChatMinor::SilentShout)
    {
        LOG_ERROR("Tried to fake a message on an unsupported chat channel: %d", chatType);
        return 0;
    }

    uint32_t crossServerSpeakerId = playerInfo->oid & 0xFFFFFFu;

    std::string coloredSpeakerName = std::string("<c|||>") + playerInfo->firstName + playerInfo->lastName + std::string("</c>");

    unsigned char* buffer = nullptr;
    uint32_t bufferSize = 0;

    LOG_DEBUG("Faking message (channel %d) from %d with oid %#010x to %d", chatType, crossServerSpeakerId, playerInfo->oid, targetId);

    auto pMessage = (CNWSMessage*)Globals::AppManager()->m_pServerExoApp->GetNWSMessage();
    pMessage->CreateWriteMessage(message.size() + 0x14, -1, 1);
    pMessage->WriteOBJECTIDServer(playerInfo->oid);
    pMessage->WriteCExoString(message.c_str(), 0x20);
    pMessage->WriteFLOAT(0, 1.0f, 0x20);
    pMessage->WriteFLOAT(0, 1.0f, 0x20);
    pMessage->WriteFLOAT(0, 1.0f, 0x20);

    pMessage->WriteBOOL(0);
    pMessage->WriteCExoString(CExoString(coloredSpeakerName.c_str()), 0x20);

    if (pMessage->GetWriteMessage(&buffer, &bufferSize))
    {
        switch (chatType)
        {
            case Constants::MessageChatMinor::Tell:
                return pMessage->SendServerToPlayerMessage(targetId & 0xFFu, Constants::MessageMajor::PlayerChat,
                    Constants::MessageChatMinor::Tell, buffer, bufferSize);
                break;
            case Constants::MessageChatMinor::Shout:
                return pMessage->SendServerToPlayerMessage(Constants::PLAYERID_ALL_PLAYERS,
                    Constants::MessageMajor::PlayerChat,
                    Constants::MessageChatMinor::Shout, buffer, bufferSize);
                break;
            case Constants::MessageChatMinor::SilentShout:
                return pMessage->SendServerToPlayerMessage(Constants::PLAYERID_ALL_GAMEMASTERS,
                    Constants::MessageMajor::PlayerChat,
                    Constants::MessageChatMinor::SilentShout, buffer, bufferSize);
            default:
                return 0;
        }
    }
    return 0;
}

int32_t Bridge::Hooks::CNWSMessage__HandlePlayerToServerChatMessage(CNWSMessage* thisPtr,
    CNWSPlayer* pPlayer, unsigned char nChatType)
{
    if (!s_bridge || !s_bridge->IsConnected() || !pPlayer)
    {
        return pHandlePlayerChatHook->CallOriginal<int32_t>(thisPtr, pPlayer, nChatType);
    }

    bool bIsDM = pPlayer && pPlayer->m_nCharacterType == Constants::CharacterType::DM;
    
    if (!thisPtr->MessageReadOverflow(1))
    {
        CExoString sTargetName;
        auto nTargetPlayerId = Constants::PLAYERID_ALL_CLIENTS;
        if (nChatType == Constants::ChatChannel::PlayerTell)
        {
            if (!thisPtr->ReadBOOL())
            {
                nTargetPlayerId = thisPtr->ReadWORD(0x20);
                LOG_DEBUG("Sending tell message for id: %d", nTargetPlayerId);
            }
            else
            {
                sTargetName = thisPtr->ReadCExoString(0x20);
                LOG_DEBUG("Trying to find tell target by name: %s", sTargetName.CStr());
                nTargetPlayerId = Globals::AppManager()->m_pServerExoApp->ResolvePlayerByFirstName(sTargetName);
                LOG_DEBUG("Id search result: %d", nTargetPlayerId);
            }
        }

        CExoString sMessage = thisPtr->ReadCExoString(0x20);
        CNWSObject* pGameObject;
        if (!thisPtr->MessageReadOverflow(1) && !thisPtr->MessageReadUnderflow(1) && (pGameObject =
            pPlayer->GetGameObject()))
        {
            uint32_t oidSpeaker = pGameObject->m_idSelf;
            std::string sStrippedMessage = sMessage.CStr();
            size_t pos;
            while ((pos = sStrippedMessage.find("<c")) != std::string::npos)
            {
                sStrippedMessage = sStrippedMessage.substr(0, pos) + sStrippedMessage.substr(pos + 6,
                    std::string::npos);
            }
            sMessage = CExoString(sStrippedMessage.c_str());

            if ((nChatType >= Constants::ChatChannel::PlayerTalk && nChatType <= Constants::ChatChannel::PlayerParty)
                || nChatType == Constants::ChatChannel::PlayerDm)
            {
                auto pModule = (CNWSModule*)Globals::AppManager()->m_pServerExoApp->GetModule();
                if (nChatType != Constants::ChatChannel::PlayerTell && pModule)
                {
                    pModule->m_oidLastPlayerChatObjectId = pGameObject->m_idSelf;
                    pModule->m_sLastPlayerChatMessage = CExoString(sMessage);
                    pModule->m_nLastPlayerChatType = nChatType;
                    Globals::VirtualMachine()->RunScript(&pModule->m_sScripts[17], pModule->m_idSelf, 1);
                    pModule->m_oidLastPlayerChatObjectId = Constants::OBJECT_INVALID;
                    if (pModule->m_sLastPlayerChatMessage.IsEmpty())
                    {
                        return 0;
                    }
                }

                uint32_t crossServerPlayerId = GetCrossServerPlayerId(pPlayer->m_nPlayerID, s_bridge->GetBridgeInstance()->GetId());
                if (nChatType == Constants::ChatChannel::PlayerTell)
                {
                    if (nTargetPlayerId > 0xFF)
                    {
                        LOG_DEBUG("Cross server tell message from %d to %d", crossServerPlayerId, nTargetPlayerId);
                        auto msg = std::make_unique<ChatMessage>(crossServerPlayerId, nTargetPlayerId, sMessage.CStr(), Constants::ChatChannel::PlayerTell);
                        s_bridge->GetBridgeInstance()->QueueOutgoingEvent(std::move(msg));
                        thisPtr->SendServerToPlayerChat_Tell(oidSpeaker, oidSpeaker, sMessage);
                    }
                }
                else if (nChatType == Constants::ChatChannel::PlayerShout)
                {
                    auto msg = std::make_unique<ChatMessage>(crossServerPlayerId, sMessage.CStr(), Constants::ChatChannel::PlayerShout);
                    s_bridge->GetBridgeInstance()->QueueOutgoingEvent(std::move(msg));
                }
                else if (nChatType == Constants::ChatChannel::PlayerDm)
                {
                    auto msg = std::make_unique<ChatMessage>(crossServerPlayerId, sMessage.CStr(), Constants::ChatChannel::PlayerDm);
                    s_bridge->GetBridgeInstance()->QueueOutgoingEvent(std::move(msg));
                }

                nChatType = bIsDM ? nChatType | 0x10u : nChatType;

                return thisPtr->SendServerToPlayerChatMessage(nChatType, oidSpeaker, sMessage, nTargetPlayerId,
                    sTargetName);
            }
        }
    }
    return 0;
}

void Bridge::Hooks::CNWSMessage__SendServerToPlayerPlayerList_Add(bool before, CNWSMessage*, uint32_t nPlayerId, CNWSPlayer* pPlayer)
{
    if (before || nPlayerId != Constants::PLAYERID_ALL_PLAYERS ||
        pPlayer->m_nLoginState < 2 || !s_bridge || !s_bridge->IsConnected())
        return;

    auto pPlayerObject = pPlayer->GetGameObject();
    auto pPlayerInfo = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID);
    CExoString sPlayerName = CExoString(pPlayerInfo->m_sPlayerName);
    auto pPlayerCreature = Utils::AsNWSCreature(pPlayerObject);
    uint32_t nCreatureId;
    bool bIsDM = pPlayer->m_nCharacterType == Constants::CharacterType::DM;
    if (!pPlayerCreature || (!pPlayerCreature->m_pStats->m_bIsPC &&
        (!(pPlayerCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(
            pPlayerCreature->m_oidMaster)) || !pPlayerCreature->m_pStats->m_bIsPC)))
    {
        nCreatureId = Constants::OBJECT_INVALID;
    }
    else
    {
        nCreatureId = pPlayerCreature->m_idSelf;
    }

    pPlayerCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(nCreatureId);
    if (!pPlayerCreature)
        return;
    CExoLocString lsFirstName, lsLastName;
    CResRef resRefPortrait;
    lsFirstName = pPlayerCreature->m_pStats->m_lsFirstName;
    lsLastName = pPlayerCreature->m_pStats->m_lsLastName;
    resRefPortrait = pPlayerCreature->m_pStats->m_cPortrait;
    int32_t out1;
    unsigned char out2;
    CExoString sFirstName;
    lsFirstName.GetString(0, &out1, &sFirstName, &out2);
    CExoString sLastName;
    lsLastName.GetString(0, &out1, &sLastName, &out2);

    PlayerInfoMessage* infoMsg = new PlayerInfoMessage();
    auto msg = std::unique_ptr<PlayerInfoMessage>(infoMsg);
    PlayerInfo& playerInfo = infoMsg->player;
    playerInfo.firstName = sFirstName.CStr();
    playerInfo.lastName = sLastName.CStr();
    playerInfo.playername = sPlayerName.CStr();
    playerInfo.id = pPlayer->m_nPlayerID;
    playerInfo.oid = Constants::OBJECT_INVALID | GetCrossServerPlayerId(pPlayer->m_nPlayerID, s_bridge->GetBridgeInstance()->GetId());
    playerInfo.isDM = bIsDM;
    s_bridge->GetBridgeInstance()->QueueOutgoingEvent(std::move(msg));
}

int32_t Bridge::Hooks::CNWSMessage__SendServerToPlayerPlayerList_All(CNWSMessage* thisPtr, CNWSPlayer* pTargetPlayer)
{
    if (!s_bridge || !s_bridge->IsConnected())
    {
        return pSendPlayerListAllHook->CallOriginal<int32_t>(thisPtr, pTargetPlayer);
    }
    int ownServerId = s_bridge->GetBridgeInstance()->GetId();

    thisPtr->CreateWriteMessage(0x200, pTargetPlayer->m_nPlayerID, 1);
    auto playerList = Globals::AppManager()
        ->m_pServerExoApp->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    if (!playerList)
    {
        return 0;
    }

    auto playerNode = playerList->pHead;
    unsigned char nPlayerCount = 0;
    while (playerNode)
    {
        auto player = (CNWSPlayer*)playerNode->pObject;
        auto pPlayerObject = player->GetGameObject();
        if (pPlayerObject)
        {
            nPlayerCount++;
        }
        playerNode = playerNode->pNext;
    }

    auto& serverList = s_bridge->GetBridgeInstance()->m_serverList;
    std::scoped_lock<std::mutex> lock(serverList.mutex);
    
    uint32_t nFakePlayerCount = 0;
    bool bSendingFakePlayers = pTargetPlayer->m_nLoginState > 1;
    if (bSendingFakePlayers)
    {
        for (const auto& server : serverList.servers)
        {
            if (server.id == (uint32_t) ownServerId)
                continue;
            nFakePlayerCount += server.players.size();
        }
    }
    uint32_t nTotalPlayerCount = nPlayerCount + nFakePlayerCount;
    uint8_t nPlayersToSend = nTotalPlayerCount > 255 ? 255 : (unsigned char)nTotalPlayerCount;

    thisPtr->WriteBYTE(nPlayersToSend, 8);
    thisPtr->WriteBOOL(Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bShowDMJoinMessage);

    playerNode = playerList->pHead;
    while (playerNode)
    {
        auto pCurrentPlayer = (CNWSPlayer*)playerNode->pObject;
        auto pPlayerObject = pCurrentPlayer->GetGameObject();

        if (pPlayerObject)
        {
            bool bIsDM = pCurrentPlayer->m_nCharacterType == Constants::CharacterType::DM;
            auto pPlayerCreature = Utils::AsNWSCreature(pPlayerObject);
            uint32_t nCreatureId;
            if (!pPlayerCreature || (!pPlayerCreature->m_pStats->m_bIsPC &&
                (!(pPlayerCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(
                    pPlayerCreature->m_oidMaster)) || !pPlayerCreature->m_pStats->m_bIsPC)))
            {
                nCreatureId = Constants::OBJECT_INVALID;
            }
            else
            {
                nCreatureId = pPlayerCreature->m_idSelf;
            }
            pPlayerCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(nCreatureId);

            bool bValidCreature = pPlayerCreature != nullptr;
            CExoLocString lsFirstName, lsLastName;
            CResRef resRefPortrait;
            if (bValidCreature)
            {
                lsFirstName = pPlayerCreature->m_pStats->m_lsFirstName;
                lsLastName = pPlayerCreature->m_pStats->m_lsLastName;
                resRefPortrait = pPlayerCreature->m_pStats->m_cPortrait;
                LOG_DEBUG("Is valid creature");
            }

            auto pPlayerInfo = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerInfo(
                pCurrentPlayer->m_nPlayerID);
            CExoString sPlayerName = CExoString(pPlayerInfo->m_sPlayerName);

            thisPtr->WriteDWORD(pCurrentPlayer->m_nPlayerID, 0x20);
            thisPtr->WriteOBJECTIDServer(pPlayerObject->m_idSelf);
            thisPtr->WriteBOOL(bIsDM);
            thisPtr->WriteCExoString(sPlayerName, 0x20);
            thisPtr->WriteBOOL(bValidCreature);
            //ADDED IN 8193
            thisPtr->WriteBYTE(pPlayerInfo->m_nPlatformId, 8);
            CExoString sPSID = CExoString(pPlayerInfo->m_sPSID);
            thisPtr->WriteCExoString(sPSID, 0x20);
            ///////////////

            if (bValidCreature)
            {
                thisPtr->WriteOBJECTIDServer(nCreatureId);
                thisPtr->WriteCExoLocStringServer(lsFirstName, 0);
                thisPtr->WriteCExoLocStringServer(lsLastName, 0);
                auto nPortraitId = pPlayerCreature->m_nPortraitId;
                if (nPortraitId >= (uint16_t)0xFFFFEu && pPlayerCreature->m_pStats->m_nGender == 1)
                    nPortraitId = (uint16_t)0xFFFFEu;
                thisPtr->WriteWORD(nPortraitId, 0x10);
                if (nPortraitId >= (uint16_t)0xFFFFEu)
                    thisPtr->WriteCResRef(resRefPortrait, 0x10);
            }

            LOG_DEBUG("Adding real player to list with playername %s, playerid %d, objectid %#010x. Platform: %d | PSID: %s",
                sPlayerName.CStr(), pCurrentPlayer->m_nPlayerID, pPlayerObject->m_idSelf, pPlayerInfo->m_nPlatformId, pPlayerInfo->m_sPSID.CStr());
        }

        playerNode = playerNode->pNext;
    }

    unsigned char* buffer = nullptr;
    uint32_t bufferSize = 0;
    uint32_t nRet = 0;
    if (bSendingFakePlayers)
    {
        uint32_t nRemainingPlayers = nPlayersToSend - nPlayerCount;

        //TODO: Proper loop

        //Append fake players
        for (const auto& server : serverList.servers)
        {
            if (server.id == (uint32_t) ownServerId)
                continue;
            for (const auto& player : server.players)
            {
                LOG_DEBUG("Adding fake player to list with playername %s, playerid %d, objectid %#010x, charname %s "
                    "%s, server %d", player.playername, player.id, player.oid,
                    player.firstName, player.lastName, server.id);

                AppendFakePlayerToMessage(thisPtr, Constants::PLAYERID_ALL_PLAYERS, player.id,
                    player.playername, player.oid, player.firstName,
                    player.lastName, player.isDM, server.id);
                nRemainingPlayers--;
                if (nRemainingPlayers < 1)
                    break;
            }
            if (nRemainingPlayers < 1)
                break;
        }

        if (!thisPtr->GetWriteMessage(&buffer, &bufferSize))
            return 0;
        if ((nRet = thisPtr->SendServerToPlayerMessage(pTargetPlayer->m_nPlayerID, 10, 1, buffer, bufferSize)))
        {
            //Send extra fake players
            uint32_t nSkipped = 0;
            nRemainingPlayers = nPlayersToSend - nPlayerCount;
            for (const auto& server : serverList.servers)
            {
                if (server.id == (uint32_t) ownServerId)
                    continue;
                if (nSkipped + server.players.size() <= nRemainingPlayers)
                {
                    nSkipped += server.players.size();
                    continue;
                }
                for (const auto& player : server.players)
                {
                    if (nSkipped < nRemainingPlayers)
                    {
                        nSkipped++;
                        continue;
                    }
                    SendFakePlayerAdd(thisPtr, Constants::PLAYERID_ALL_PLAYERS, player.id, player.playername,
                        player.oid, player.firstName, player.lastName, player.isDM, server.id);
                    SendFakePlayerAdd(thisPtr, Constants::PLAYERID_ALL_GAMEMASTERS, player.id, player.playername,
                        player.oid, player.firstName, player.lastName, player.isDM, server.id);
                }
            }
        }
    }
    else
    {
        if (!thisPtr->GetWriteMessage(&buffer, &bufferSize))
            return 0;
        return thisPtr->SendServerToPlayerMessage(pTargetPlayer->m_nPlayerID, 10, 1, buffer, bufferSize);
    }

    return nRet;
}

void Bridge::Hooks::ResendAllPlayerLists()
{
    auto serverExoApp = Globals::AppManager()->m_pServerExoApp;
    if (!serverExoApp || !serverExoApp->m_pcExoAppInternal->m_pNWSPlayerList) return;

    auto pPlayerList = serverExoApp->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    auto pMessage = (CNWSMessage*)serverExoApp->GetNWSMessage();
    if (!pPlayerList || !pMessage) return;

    auto playerNode = pPlayerList->pHead;
    while (playerNode)
    {
        auto pPlayerClient = (CNWSClient*)playerNode->pObject;
        auto pPlayer = pPlayerClient->AsNWSPlayer();
        if (pPlayer && pPlayer->m_nLoginState > 1)
        {
            pMessage->SendServerToPlayerPlayerList_All(pPlayer);
        }
        playerNode = playerNode->pNext;
    }
}

int32_t Bridge::Hooks::BroadcastFakePlayerAdd(uint32_t nPlayerId,
    const std::string& playerName, uint32_t creatureId, const std::string& characterFirstName,
    const std::string& characterLastName, bool isDM, int serverId)
{
    auto pMessage = (CNWSMessage*)Globals::AppManager()->m_pServerExoApp->GetNWSMessage();
    if (!pMessage) return 0;
    SendFakePlayerAdd(pMessage, Constants::PLAYERID_ALL_PLAYERS, nPlayerId, playerName, creatureId, characterFirstName, characterLastName, isDM, serverId);
    SendFakePlayerAdd(pMessage, Constants::PLAYERID_ALL_GAMEMASTERS, nPlayerId, playerName, creatureId, characterFirstName, characterLastName, isDM, serverId);
    return 1;
}

int32_t Bridge::Hooks::BroadcastFakePlayerDelete(uint32_t removedId, int serverId)
{
    auto pMessage = (CNWSMessage*)Globals::AppManager()->m_pServerExoApp->GetNWSMessage();
    if (!pMessage) return 0;
    SendFakePlayerDelete(pMessage, Constants::PLAYERID_ALL_PLAYERS, removedId, serverId);
    SendFakePlayerDelete(pMessage, Constants::PLAYERID_ALL_GAMEMASTERS, removedId, serverId);
    return 1;
}

int32_t Bridge::Hooks::SendFakePlayerAdd(CNWSMessage* pMessage, uint32_t targetId, uint32_t nPlayerId,
    const std::string& playerName, uint32_t creatureId, const std::string& characterFirstName,
    const std::string& characterLastName, bool isDM, int serverId)
{
    if (!pMessage) return 0;

    uint32_t crossServerPlayerId = GetCrossServerPlayerId(nPlayerId, serverId);
    LOG_DEBUG("Sending new player %d from server %d with id %d and creatureId %#010x", nPlayerId, serverId, crossServerPlayerId, creatureId);

    unsigned char* buffer = nullptr;
    uint32_t bufferSize = 0;

    pMessage->CreateWriteMessage(0x100, -1, 1);
    pMessage->WriteBOOL(Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bShowDMJoinMessage);
    AppendFakePlayerToMessage(pMessage, targetId, nPlayerId, playerName, creatureId, characterFirstName,
        characterLastName, isDM, serverId);

    if (pMessage->GetWriteMessage(&buffer, &bufferSize))
        return pMessage->SendServerToPlayerMessage(targetId, 10, 2, buffer, bufferSize);
    return 0;
}

int32_t Bridge::Hooks::SendFakePlayerDelete(CNWSMessage* pMessage, uint32_t targetId, uint32_t removedId,
    int serverId)
{
    if (!pMessage) return 0;

    uint32_t crossServerPlayerId = GetCrossServerPlayerId(removedId, serverId);
    pMessage->CreateWriteMessage(4, -1, 1);
    pMessage->WriteBOOL(Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bShowDMJoinMessage);
    pMessage->WriteDWORD(crossServerPlayerId, 0x20);
    unsigned char* buffer = nullptr;
    uint32_t bufferSize = 0;

    if (pMessage->GetWriteMessage(&buffer, &bufferSize))
        return pMessage->SendServerToPlayerMessage(targetId, 10, 3, buffer, bufferSize);
    return 0;
}

void Bridge::Hooks::AppendFakePlayerToMessage(CNWSMessage* pMessage, uint32_t, uint32_t nPlayerId,
    const std::string& playerName, uint32_t creatureId,
    const std::string& characterFirstName, const std::string& characterLastName,
    bool isDM, int serverId)
{
    uint32_t crossServerPlayerId = GetCrossServerPlayerId(nPlayerId, serverId);

    pMessage->WriteDWORD(crossServerPlayerId, 0x20);
    pMessage->WriteOBJECTIDServer(creatureId);
    pMessage->WriteBOOL(isDM);
    pMessage->WriteCExoString(playerName.c_str(), 0x20);
    pMessage->WriteBOOL(1);

    //ADDED IN 8193
    pMessage->WriteBYTE(1, 8);
    CExoString sPSID = CExoString("");
    pMessage->WriteCExoString(sPSID, 0x20);
    ///////////////

    CExoLocString lsFirstName, lsLastName;
    std::string decoratedCharacterFirstName = std::string("<c|||>") + characterFirstName;
    lsFirstName.AddString(0, decoratedCharacterFirstName.c_str(), 0);
    std::string decoratedCharacterLastName = characterLastName + std::string("</c>");
    lsLastName.AddString(0, decoratedCharacterLastName.c_str(), 0);
    pMessage->WriteOBJECTIDServer(creatureId);
    pMessage->WriteCExoLocStringServer(lsFirstName, 0);
    pMessage->WriteCExoLocStringServer(lsLastName, 0);
    pMessage->WriteWORD((uint16_t)-1u, 0x10);
    pMessage->WriteCResRef("portrait", 0x10);

    LOG_DEBUG("Appending player %s (%d) from server %d with oid %#010x and character name %s and isDM %d", playerName, nPlayerId, serverId, creatureId, characterFirstName + " " + characterLastName, isDM);
}

void Bridge::Hooks::CNWSMessage__SendServerToPlayerPlayerList_Delete(bool before, CNWSMessage*, uint32_t nPlayerId,
    CNWSPlayer* pPlayer)
{
    if (before || nPlayerId != Constants::PLAYERID_ALL_PLAYERS ||
        !s_bridge || !s_bridge->IsConnected())
        return;
    std::unique_ptr<Message> msg = std::make_unique<PlayerDisconnectMessage>(pPlayer->m_nPlayerID, s_bridge->GetBridgeInstance()->GetId());
    s_bridge->GetBridgeInstance()->QueueOutgoingEvent(std::move(msg));
}

void Bridge::Hooks::CServerExoAppInternal__Initialize(bool before, CServerExoAppInternal*)
{
    if (before)
        return;
    if (s_bridge)
        s_bridge->GetBridgeInstance()->Run();
}

void Bridge::Hooks::SendPlayerList()
{
    if (!s_bridge || !s_bridge->GetBridgeInstance())
        return;

    LOG_DEBUG("Preparing player list");
    ServerInfoMessage* msg = new ServerInfoMessage();
    std::unique_ptr<Message> m = std::unique_ptr<ServerInfoMessage>(msg);
    msg->name = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetSessionName().CStr();
    auto serverExoApp = Globals::AppManager()->m_pServerExoApp;
    if (!serverExoApp || !serverExoApp->m_pcExoAppInternal->m_pNWSPlayerList) return;

    auto pPlayerList = serverExoApp->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    auto pMessage = (CNWSMessage*)serverExoApp->GetNWSMessage();
    if (!pPlayerList || !pMessage) return;

    auto playerNode = pPlayerList->pHead;
    while (playerNode)
    {
        auto pPlayerClient = (CNWSClient*)playerNode->pObject;
        auto pPlayer = pPlayerClient->AsNWSPlayer();
        if (pPlayer && pPlayer->m_nLoginState > 1)
        {
            msg->players.emplace_back();
            auto& playerInfo = msg->players.back();
            auto pPlayerObject = pPlayer->GetGameObject();
            auto pPlayerInfo = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID);
            CExoString sPlayerName = CExoString(pPlayerInfo->m_sPlayerName);
            auto pPlayerCreature = Utils::AsNWSCreature(pPlayerObject);
            uint32_t nCreatureId;
            bool bIsDM = pPlayer->m_nCharacterType == Constants::CharacterType::DM;
            if (!pPlayerCreature || (!pPlayerCreature->m_pStats->m_bIsPC &&
                (!(pPlayerCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(
                    pPlayerCreature->m_oidMaster)) || !pPlayerCreature->m_pStats->m_bIsPC)))
            {
                nCreatureId = Constants::OBJECT_INVALID;
            }
            else
            {
                nCreatureId = pPlayerCreature->m_idSelf;
            }

            pPlayerCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(nCreatureId);
            if (!pPlayerCreature)
                continue;
            CExoLocString lsFirstName, lsLastName;
            CResRef resRefPortrait;
            lsFirstName = pPlayerCreature->m_pStats->m_lsFirstName;
            lsLastName = pPlayerCreature->m_pStats->m_lsLastName;
            resRefPortrait = pPlayerCreature->m_pStats->m_cPortrait;
            int32_t out1;
            unsigned char out2;
            CExoString sFirstName;
            lsFirstName.GetString(0, &out1, &sFirstName, &out2);
            CExoString sLastName;
            lsLastName.GetString(0, &out1, &sLastName, &out2);

            playerInfo.firstName = sFirstName.CStr();
            playerInfo.lastName = sLastName.CStr();
            playerInfo.playername = sPlayerName.CStr();
            playerInfo.id = pPlayer->m_nPlayerID;
            playerInfo.oid = Constants::OBJECT_INVALID | (pPlayer->m_nPlayerID & 0xFFu) | ((s_bridge->GetBridgeInstance()->GetId() & 0xFFFFu) << 8);
            playerInfo.isDM = bIsDM;
        }
        playerNode = playerNode->pNext;
    }
    LOG_DEBUG("Sending %d players as: %s", msg->players.size(), msg->name);
    s_bridge->GetBridgeInstance()->QueueOutgoingEvent(std::move(m));
}