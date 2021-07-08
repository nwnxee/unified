#pragma once
#include <string>
#include "API/Constants.hpp"

namespace NWNXLib
{
namespace Services
{
class HooksProxy;
}
namespace Hooking
{
class FunctionHook;
}
}

class CServerExoApp;
class CServerExoAppInternal;
class CNWSMessage;
class CNWSPlayer;

namespace Bridge
{
class Bridge;
class PlayerInfo;

class Hooks
{
public:
    static void InitHooks(Bridge* bridge, NWNXLib::Services::HooksProxy* hooker);
    static void ResendAllPlayerLists();
    static int32_t SendFakeChatMessage(const std::string& message, uint32_t targetId,
        PlayerInfo* playerInfo, NWNXLib::API::Constants::MessageChatMinor::TYPE channel);
    static int32_t BroadcastFakePlayerAdd(uint32_t nPlayerId,
        const std::string& playerName, uint32_t creatureId, const std::string& characterFirstName,
        const std::string& characterLastName, bool isDM, int serverId);
    static int32_t BroadcastFakePlayerDelete(uint32_t removedId, int serverId);
    static inline uint32_t GetCrossServerPlayerId(int playerId, int serverId) { return (playerId & 0xFFu) | (((uint32_t)serverId & 0xFFFFu) << 8u); }
    static void SendPlayerList();

private:
    static Bridge* s_bridge;
    
    static void CServerExoApp__MainLoop(bool before, CServerExoApp*);
    static void CServerExoAppInternal__Initialize(bool before, CServerExoAppInternal*);
    static void CNWSMessage__SendServerToPlayerPlayerList_Delete(bool before,
        CNWSMessage* thisPtr, uint32_t nPlayerId, CNWSPlayer* pPlayer);
    static void CNWSMessage__SendServerToPlayerPlayerList_Add(bool before, CNWSMessage*,
        uint32_t nPlayerId, CNWSPlayer* pPlayer);
    static int32_t CNWSMessage__SendServerToPlayerPlayerList_All(CNWSMessage* thisPtr, CNWSPlayer* pTargetPlayer);
    static int32_t CNWSMessage__HandlePlayerToServerChatMessage(CNWSMessage* thisPtr, CNWSPlayer* pPlayer, unsigned char nChatType);

    static void AppendFakePlayerToMessage(CNWSMessage* pMessage, uint32_t targetId, uint32_t nPlayerId,
        const std::string& playerName, uint32_t creatureId, const std::string& characterFirstName,
        const std::string& characterLastName, bool isDM, int serverId);
    static int32_t SendFakePlayerAdd(CNWSMessage* pMessage, uint32_t targetId, uint32_t nPlayerId,
        const std::string& playerName, uint32_t creatureId, const std::string& characterFirstName,
        const std::string& characterLastName, bool isDM, int serverId);
    static int32_t SendFakePlayerDelete(CNWSMessage* pMessage, uint32_t targetId, uint32_t removedId, int serverId);
};
}