#include "Events.hpp"
#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSArea.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWSModule.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_RemovePCFromWorldHook;
static Hooks::Hook s_ServerCharacterSaveHook;
static Hooks::Hook s_SendServerToPlayerCharListHook;
static Hooks::Hook s_CheckStickyPlayerNameReservedHook;
static Hooks::Hook s_SendServerToPlayerModule_ExportReplyHook;
static Hooks::Hook s_SendServerToPlayerArea_ClientAreaHook;
static Hooks::Hook s_HandlePlayerToServerDeviceHook;

static void RemovePCFromWorldHook(CServerExoAppInternal*, CNWSPlayer*);
static int32_t SaveServerCharacterHook(CNWSPlayer*, int32_t);
static int32_t SendServerToPlayerCharListHook(CNWSMessage*, CNWSPlayer*);
static int32_t CheckStickyPlayerNameReservedHook(CServerExoAppInternal*, CExoString, CExoString, CExoString, int32_t);
static int32_t SendServerToPlayerModule_ExportReplyHook(CNWSMessage*, CNWSPlayer*);
static int32_t SendServerToPlayerArea_ClientAreaHook(CNWSMessage*, CNWSPlayer*, CNWSArea*, float, float, float, const Vector*, BOOL);
static int32_t HandlePlayerToServerDeviceHook(CNWSMessage*, CNWSPlayer*, uint8_t);

void ClientEvents() __attribute__((constructor));
void ClientEvents()
{
    InitOnFirstSubscribe("NWNX_ON_CLIENT_DISCONNECT_.*", []() {
        s_RemovePCFromWorldHook = Hooks::HookFunction(&CServerExoAppInternal::RemovePCFromWorld,
                                               &RemovePCFromWorldHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_SERVER_CHARACTER_SAVE_.*", []() {
        s_ServerCharacterSaveHook = Hooks::HookFunction(&CNWSPlayer::SaveServerCharacter,
                                                 &SaveServerCharacterHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_CLIENT_CONNECT_.*", []() {
        s_SendServerToPlayerCharListHook = Hooks::HookFunction(
                &CNWSMessage::SendServerToPlayerCharList,
                &SendServerToPlayerCharListHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_.*", []() {
        s_CheckStickyPlayerNameReservedHook = Hooks::HookFunction(
                &CServerExoAppInternal::CheckStickyPlayerNameReserved,
                &CheckStickyPlayerNameReservedHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_CLIENT_EXPORT_CHARACTER_.*", []() {
        s_SendServerToPlayerModule_ExportReplyHook = Hooks::HookFunction(
                &CNWSMessage::SendServerToPlayerModule_ExportReply,
                &SendServerToPlayerModule_ExportReplyHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_SERVER_SEND_AREA_.*", []()
    {
        s_SendServerToPlayerArea_ClientAreaHook = Hooks::HookFunction(
                &CNWSMessage::SendServerToPlayerArea_ClientArea,
                &SendServerToPlayerArea_ClientAreaHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_.*", []()
    {
        s_HandlePlayerToServerDeviceHook = Hooks::HookFunction(
                &CNWSMessage::HandlePlayerToServerDevice,
                &HandlePlayerToServerDeviceHook, Hooks::Order::Earliest);
    });
}

void RemovePCFromWorldHook(CServerExoAppInternal *pServerExoAppInternal, CNWSPlayer *pPlayer)
{
    // NOTE: Events won't be processed for disconnecting characters, e.g. RemoveEffect events.
    // If we wanted that to happen, we'd need to process the event like CServerAIMaster__GetPendingEvent.
    auto *pNetLayer = Globals::AppManager()->m_pServerExoApp->GetNetLayer();
    auto *pPlayerInfo = pNetLayer->GetPlayerInfo(pPlayer->m_nPlayerID);
    auto playerName = pPlayerInfo->m_sPlayerName.CStr();
    auto cdKey = pPlayerInfo->m_cCDKey.sPublic.CStr();
    PushEventData("PLAYER_NAME", playerName);
    PushEventData("CDKEY", cdKey);
    SignalEvent("NWNX_ON_CLIENT_DISCONNECT_BEFORE" , pPlayer->m_oidNWSObject);
    s_RemovePCFromWorldHook->CallOriginal<void>(pServerExoAppInternal, pPlayer);
    PushEventData("PLAYER_NAME", playerName);
    PushEventData("CDKEY", cdKey);
    SignalEvent("NWNX_ON_CLIENT_DISCONNECT_AFTER", pPlayer->m_oidNWSObject);
}

int32_t SaveServerCharacterHook(CNWSPlayer *pPlayer, int32_t bBackupPlayer)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        return SignalEvent(ev, pPlayer->m_oidNWSObject);
    };

    if (PushAndSignal("NWNX_ON_SERVER_CHARACTER_SAVE_BEFORE"))
    {
        retVal = s_ServerCharacterSaveHook->CallOriginal<int32_t>(pPlayer, bBackupPlayer);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_SERVER_CHARACTER_SAVE_AFTER");

    return retVal;
}

int32_t SendServerToPlayerCharListHook(CNWSMessage* pThis, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    if (!pPlayer)
        return s_SendServerToPlayerCharListHook->CallOriginal<int32_t>(pThis, pPlayer);

    auto *pNetLayer = Globals::AppManager()->m_pServerExoApp->GetNetLayer();
    auto *pPlayerInfo = pNetLayer->GetPlayerInfo(pPlayer->m_nPlayerID);

    std::string playerName = pPlayerInfo->m_sPlayerName.CStr();
    std::string cdKey = pPlayerInfo->m_cCDKey.sPublic.CStr();
    std::string isDM = std::to_string(pPlayerInfo->m_bGameMasterPrivileges);
    std::string ipAddress = pNetLayer->GetPlayerAddress(pPlayer->m_nPlayerID).CStr();
    std::string versionMajor = std::to_string(pPlayerInfo->m_nBuildVersion);
    std::string versionMinor = std::to_string(pPlayerInfo->m_nPatchRevision);
    std::string versionPostfix = std::to_string(pPlayerInfo->m_nPatchPostfix);
    std::string platformId = std::to_string(pPlayerInfo->m_nPlatformId);

    std::string reason;
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("PLAYER_NAME", playerName);
        PushEventData("CDKEY", cdKey);
        PushEventData("IS_DM", isDM);
        PushEventData("IP_ADDRESS", ipAddress);
        PushEventData("VERSION_MAJOR", versionMajor);
        PushEventData("VERSION_MINOR", versionMinor);
        PushEventData("VERSION_POSTFIX", versionPostfix);
        PushEventData("PLATFORM_ID", platformId);
        return SignalEvent(ev, Utils::GetModule()->m_idSelf, &reason);
    };

    if (PushAndSignal("NWNX_ON_CLIENT_CONNECT_BEFORE"))
    {
        retVal = s_SendServerToPlayerCharListHook->CallOriginal<int32_t>(pThis, pPlayer);
    }
    else
    {
        Tasks::QueueOnMainThread([pNetLayer, pPlayer, reason]()
        {
            if (pPlayer)
            {
                pNetLayer->DisconnectPlayer(pPlayer->m_nPlayerID, 5838, true, reason.c_str());
            }
        });

        retVal = false;
    }
    PushAndSignal("NWNX_ON_CLIENT_CONNECT_AFTER");
    return retVal;
}

int32_t CheckStickyPlayerNameReservedHook(CServerExoAppInternal *pServerExoAppInternal, CExoString sClientCDKey,
                                                        CExoString sLegacyCDKey, CExoString sPlayerName, int32_t nConnectionType)
{
    int32_t retVal;

    std::string valid;
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("PLAYER_NAME", sPlayerName.CStr());
        PushEventData("CDKEY", sClientCDKey.CStr());
        PushEventData("LEGACY_CDKEY", sLegacyCDKey.CStr());
        PushEventData("IS_DM", nConnectionType == 32 ? "1" : "0");
        return SignalEvent(ev, Utils::GetModule()->m_idSelf, &valid);
    };

    if (PushAndSignal("NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_BEFORE"))
    {
        retVal = s_CheckStickyPlayerNameReservedHook->CallOriginal<int32_t>(pServerExoAppInternal, sClientCDKey, sLegacyCDKey, sPlayerName, nConnectionType);
    }
    else
    {
        retVal = valid == "1" ? 1 : 0;
    }
    PushAndSignal("NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_AFTER");
    return retVal;

}

int32_t SendServerToPlayerModule_ExportReplyHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    if (SignalEvent("NWNX_ON_CLIENT_EXPORT_CHARACTER_BEFORE", pPlayer->m_oidNWSObject))
    {
        retVal = s_SendServerToPlayerModule_ExportReplyHook->CallOriginal<int32_t>(pMessage, pPlayer);
    }
    else
    {
        retVal = false;
    }

    SignalEvent("NWNX_ON_CLIENT_EXPORT_CHARACTER_AFTER", pPlayer->m_oidNWSObject);

    return retVal;
}

int32_t SendServerToPlayerArea_ClientAreaHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSArea *pArea,
                                                         float fX, float fY, float fZ, const Vector *vNewOrientation,
                                                         BOOL bPlayerIsNewToModule)
{
    PushEventData("AREA", Utils::ObjectIDToString(pArea->m_idSelf));
    PushEventData("PLAYER_NEW_TO_MODULE", std::to_string(bPlayerIsNewToModule));
    SignalEvent("NWNX_ON_SERVER_SEND_AREA_BEFORE", pPlayer->m_oidNWSObject);
    auto retVal = s_SendServerToPlayerArea_ClientAreaHook->CallOriginal<int32_t>(pMessage, pPlayer, pArea, fX, fY, fZ,
                                                                                 vNewOrientation, bPlayerIsNewToModule);
    PushEventData("AREA", Utils::ObjectIDToString(pArea->m_idSelf));
    PushEventData("PLAYER_NEW_TO_MODULE", std::to_string(bPlayerIsNewToModule));
    SignalEvent("NWNX_ON_SERVER_SEND_AREA_AFTER", pPlayer->m_oidNWSObject);

    return retVal;
}

int32_t HandlePlayerToServerDeviceHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    if (nMinor != Constants::MessageDeviceMinor::AdvertiseProperty)
        return s_HandlePlayerToServerDeviceHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);

    int32_t offset = 0;
    const auto property = Utils::PeekMessage<std::string>(pMessage, offset);
    offset += 4 + property.length();
    const auto type = Utils::PeekMessage<int32_t>(pMessage, offset);
    offset += 4;
    const auto newValue = Utils::PeekMessage<int32_t>(pMessage, offset);

    if (type != 1)// Only 1 type supported so far
        return s_HandlePlayerToServerDeviceHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);

    int32_t oldValue = pPlayer->m_device_properties[property];

    if (!pPlayer->GetGameObject())// Initial set happens on connect so no valid player character yet
        return s_HandlePlayerToServerDeviceHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);

    PushEventData("PROPERTY", property);
    PushEventData("OLD_VALUE", std::to_string(oldValue));
    PushEventData("NEW_VALUE", std::to_string(newValue));
    SignalEvent("NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_BEFORE", pPlayer->m_oidNWSObject);

    auto retVal = s_HandlePlayerToServerDeviceHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);

    PushEventData("PROPERTY", property);
    PushEventData("OLD_VALUE", std::to_string(oldValue));
    PushEventData("NEW_VALUE", std::to_string(newValue));
    SignalEvent("NWNX_ON_CLIENT_SET_DEVICE_PROPERTY_AFTER", pPlayer->m_oidNWSObject);

    return retVal;
}

}
