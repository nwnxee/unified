#include "nwnx.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSPlayerInventoryGUI.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"

#include <unordered_map>

using namespace NWNXLib;
using namespace NWNXLib::API;

// Fake players take free slots from the top down, out of the way of real clients.
static constexpr uint32_t MAX_PLAYER_ID = 0xfe;
static constexpr uint32_t MIN_FAKE_ID   = 0xc0;

static bool s_bEnabled = false;
static std::unordered_map<uint32_t, CNWSPlayer*> s_FakePlayers;
// player id -> (major << 8 | minor) -> count
static std::unordered_map<uint32_t, std::unordered_map<uint16_t, uint32_t>> s_MessageCounts;

static Hooks::Hook s_SendServerToPlayerMessageHook;
static Hooks::Hook s_SendMessageToPlayerHook;
static Hooks::Hook s_DisconnectPlayerHook;
static Hooks::Hook s_ExportReplyHook;
static Hooks::Hook s_SaveServerCharacterHook;

static CServerExoApp* Server() { return Globals::AppManager()->m_pServerExoApp; }
static bool IsFake(uint32_t nPlayerId) { return s_FakePlayers.find(nPlayerId) != s_FakePlayers.end(); }
static void DetachPlayer(CNWSPlayer* pPlayer, bool bDeleteNow);

static void Init() __attribute__((constructor));
static void Init()
{
    s_bEnabled = Config::Get<bool>("ENABLE", false);
    if (!s_bEnabled)
    {
        LOG_INFO("Fake players are disabled, set NWNX_TESTPLAYER_ENABLE=true to use them on a test server.");
        return;
    }
    LOG_WARNING("Fake players are enabled. Never do this on a live server.");

    s_SendServerToPlayerMessageHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerMessage,
        +[](CNWSMessage* pThis, uint32_t nPlayerId, uint8_t nMajor, uint8_t nMinor, uint8_t* pBuffer, uint32_t nSize) -> BOOL
        {
            if (IsFake(nPlayerId))
                s_MessageCounts[nPlayerId][(uint16_t)(nMajor << 8 | nMinor)]++;
            return s_SendServerToPlayerMessageHook->CallOriginal<BOOL>(pThis, nPlayerId, nMajor, nMinor, pBuffer, nSize);
        }, Hooks::Order::Earliest);

    // Nothing is connected to a fake player's slot, so drop what would be sent to it.
    s_SendMessageToPlayerHook = Hooks::HookFunction(&CNetLayer::SendMessageToPlayer,
        +[](CNetLayer* pThis, uint32_t nPlayerId, uint8_t* pData, uint32_t nSize, uint32_t nFlags) -> BOOL
        {
            if (IsFake(nPlayerId))
                return true;
            return s_SendMessageToPlayerHook->CallOriginal<BOOL>(pThis, nPlayerId, pData, nSize, nFlags);
        }, Hooks::Order::Earliest);

    s_DisconnectPlayerHook = Hooks::HookFunction(&CNetLayer::DisconnectPlayer,
        +[](CNetLayer* pThis, uint32_t nPlayerId, uint32_t nStrRef, BOOL bCDAuthFail, const CExoString& sReason) -> BOOL
        {
            if (IsFake(nPlayerId))
                return true;
            return s_DisconnectPlayerHook->CallOriginal<BOOL>(pThis, nPlayerId, nStrRef, bCDAuthFail, sReason);
        }, Hooks::Order::Earliest);

    // Never save: no vault behind it, and a blueprint creature lacks the per-level data SaveClassInfo needs.
    s_ExportReplyHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerModule_ExportReply,
        +[](CNWSMessage* pThis, CNWSPlayer* pPlayer) -> BOOL
        {
            if (pPlayer && IsFake(pPlayer->m_nPlayerID))
                return true;
            return s_ExportReplyHook->CallOriginal<BOOL>(pThis, pPlayer);
        }, Hooks::Order::Earliest);

    s_SaveServerCharacterHook = Hooks::HookFunction(&CNWSPlayer::SaveServerCharacter,
        +[](CNWSPlayer* pThis, BOOL bBackupPlayer) -> BOOL
        {
            if (IsFake(pThis->m_nPlayerID))
                return true;
            return s_SaveServerCharacterHook->CallOriginal<BOOL>(pThis, bBackupPlayer);
        }, Hooks::Order::Earliest);

    // The shutdown waits on every player in the list and a fake one never answers.
    MessageBus::Subscribe("NWNX_CORE_SIGNAL",
        [](const std::vector<std::string>& message)
        {
            if (message[0] != "ON_DESTROY_SERVER")
                return;
            while (!s_FakePlayers.empty())
                DetachPlayer(s_FakePlayers.begin()->second, true);
        });
}

static void DetachPlayer(CNWSPlayer* pPlayer, bool bDeleteNow)
{
    const uint32_t nPlayerId = pPlayer->m_nPlayerID;
    const ObjectID oid = pPlayer->m_oidNWSObject;

    Server()->m_pcExoAppInternal->m_lstPlayerList.Remove(pPlayer);
    s_FakePlayers.erase(nPlayerId);
    s_MessageCounts.erase(nPlayerId);

    if (auto* pCreature = Utils::AsNWSCreature(Utils::GetGameObject(oid)))
    {
        pCreature->m_bPlayerCharacter = false;
        pCreature->m_pStats->m_bIsPC = false;
    }

    auto* pInfo = Server()->GetNetLayer()->GetPlayerInfo(nPlayerId);
    pInfo->m_sPlayerName = "";
    pInfo->m_cCDKey.sPublic = "";
    pInfo->m_bPlayerPrivileges = false;
    pInfo->m_bPlayerInUse = false;

    LOG_INFO("Detached fake player %u from %x", nPlayerId, oid);

    // The engine may still hold the player further up the stack of the script that detached it.
    if (bDeleteNow)
        delete pPlayer;
    else
        Tasks::QueueOnMainThread([pPlayer]() { delete pPlayer; });
}

// A fake player whose creature is gone can't be found by its creature any more.
static void DetachOrphans()
{
    for (auto it = s_FakePlayers.begin(); it != s_FakePlayers.end();)
    {
        auto* pPlayer = (it++)->second;
        if (!Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject)))
            DetachPlayer(pPlayer, false);
    }
}

static CNWSPlayer* FindFake(ObjectID oid)
{
    for (auto& [nPlayerId, pPlayer] : s_FakePlayers)
    {
        if (pPlayer->m_oidNWSObject == oid)
            return pPlayer;
    }
    return nullptr;
}

static uint32_t FindFreePlayerId()
{
    auto* pNetLayer = Server()->GetNetLayer();
    for (uint32_t nPlayerId = MAX_PLAYER_ID; nPlayerId >= MIN_FAKE_ID; nPlayerId--)
    {
        if (IsFake(nPlayerId) || Server()->GetClientObjectByPlayerId(nPlayerId))
            continue;
        auto* pInfo = pNetLayer->GetPlayerInfo(nPlayerId);
        if (pInfo && !pInfo->m_bPlayerInUse)
            return nPlayerId;
    }
    return 0;
}

NWNX_EXPORT ArgumentStack Attach(ArgumentStack&& args)
{
    const auto oid = args.extract<ObjectID>();
    const auto sPlayerName = args.extract<std::string>();
    const auto sCDKey = args.extract<std::string>();

    if (!s_bEnabled)
    {
        LOG_ERROR("Attach: fake players are disabled, see NWNX_TESTPLAYER_ENABLE");
        return 0;
    }

    auto* pCreature = Utils::AsNWSCreature(Utils::GetGameObject(oid));
    if (!pCreature)
    {
        LOG_ERROR("Attach: %x is not a creature", oid);
        return 0;
    }
    if (pCreature->m_bPlayerCharacter || Server()->GetClientObjectByObjectId(oid))
    {
        LOG_ERROR("Attach: %x is already a player character", oid);
        return 0;
    }

    DetachOrphans();

    const uint32_t nPlayerId = FindFreePlayerId();
    if (!nPlayerId)
    {
        LOG_ERROR("Attach: no free player slot");
        return 0;
    }

    auto* pInfo = Server()->GetNetLayer()->GetPlayerInfo(nPlayerId);
    pInfo->m_sPlayerName = sPlayerName.c_str();
    pInfo->m_cCDKey.sPublic = sCDKey.c_str();
    pInfo->m_bPlayerPrivileges = true;
    pInfo->m_bPlayerInUse = true;

    auto* pPlayer = new CNWSPlayer(nPlayerId);
    pPlayer->m_oidNWSObject = oid;
    pPlayer->m_oidPCObject = oid;
    pPlayer->m_oidLastObjectControlled = oid;
    pPlayer->m_bIsPrimaryPlayer = false;

    pCreature->m_bPlayerCharacter = true;
    pCreature->m_pStats->m_bIsPC = true;

    Server()->m_pcExoAppInternal->m_lstPlayerList.Add(pPlayer);
    s_FakePlayers[nPlayerId] = pPlayer;
    s_MessageCounts.erase(nPlayerId);

    LOG_INFO("Attached fake player %u (%s) to %x", nPlayerId, sPlayerName.c_str(), oid);
    return (int32_t)nPlayerId;
}

NWNX_EXPORT ArgumentStack Detach(ArgumentStack&& args)
{
    auto* pPlayer = FindFake(args.extract<ObjectID>());
    if (!pPlayer)
        return false;
    DetachPlayer(pPlayer, false);
    return true;
}

NWNX_EXPORT ArgumentStack GetIsFake(ArgumentStack&& args)
{
    return FindFake(args.extract<ObjectID>()) != nullptr;
}

NWNX_EXPORT ArgumentStack GetPlayerId(ArgumentStack&& args)
{
    auto* pPlayer = FindFake(args.extract<ObjectID>());
    return pPlayer ? (int32_t)pPlayer->m_nPlayerID : 0;
}

NWNX_EXPORT ArgumentStack GetCount(ArgumentStack&&)
{
    DetachOrphans();
    return (int32_t)s_FakePlayers.size();
}

NWNX_EXPORT ArgumentStack GetMessageCount(ArgumentStack&& args)
{
    auto* pPlayer = FindFake(args.extract<ObjectID>());
    const auto nMajor = args.extract<int32_t>();
    const auto nMinor = args.extract<int32_t>();
    if (!pPlayer)
        return 0;

    auto it = s_MessageCounts.find(pPlayer->m_nPlayerID);
    if (it == s_MessageCounts.end())
        return 0;

    uint32_t nCount = 0;
    for (const auto& [nType, nTypeCount] : it->second)
    {
        if ((nType >> 8) == nMajor && (nMinor < 0 || (nType & 0xff) == nMinor))
            nCount += nTypeCount;
    }
    return (int32_t)nCount;
}

NWNX_EXPORT ArgumentStack ClearMessages(ArgumentStack&& args)
{
    auto* pPlayer = FindFake(args.extract<ObjectID>());
    if (!pPlayer)
        return false;
    s_MessageCounts.erase(pPlayer->m_nPlayerID);
    return true;
}

NWNX_EXPORT ArgumentStack SetInventoryOpen(ArgumentStack&& args)
{
    auto* pPlayer = FindFake(args.extract<ObjectID>());
    const auto bOpen = args.extract<int32_t>();
    if (!pPlayer || !pPlayer->m_pInventoryGUI)
        return false;
    pPlayer->m_pInventoryGUI->m_bGuiInventoryOpen = !!bOpen;
    return true;
}
