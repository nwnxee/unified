#include "Events/ClientEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSArea.hpp"
#include "API/Constants.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWSModule.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"

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

ClientEvents::ClientEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_CLIENT_DISCONNECT_.*", []() {
        s_RemovePCFromWorldHook = Hooks::HookFunction(API::Functions::_ZN21CServerExoAppInternal17RemovePCFromWorldEP10CNWSPlayer,
                                               (void*)&RemovePCFromWorldHook, Hooks::Order::Earliest);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_SERVER_CHARACTER_SAVE_.*", []() {
        s_ServerCharacterSaveHook = Hooks::HookFunction(API::Functions::_ZN10CNWSPlayer19SaveServerCharacterEi,
                                                 (void*)&SaveServerCharacterHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_CLIENT_CONNECT_.*", []() {
        s_SendServerToPlayerCharListHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage26SendServerToPlayerCharListEP10CNWSPlayer,
                (void*)&SendServerToPlayerCharListHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_.*", []() {
        s_CheckStickyPlayerNameReservedHook = Hooks::HookFunction(
                API::Functions::_ZN21CServerExoAppInternal29CheckStickyPlayerNameReservedE10CExoStringS0_S0_i,
                (void*)&CheckStickyPlayerNameReservedHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_CLIENT_EXPORT_CHARACTER_.*", []() {
        s_SendServerToPlayerModule_ExportReplyHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage36SendServerToPlayerModule_ExportReplyEP10CNWSPlayer,
                (void*)&SendServerToPlayerModule_ExportReplyHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_SERVER_SEND_AREA_.*", []()
    {
        s_SendServerToPlayerArea_ClientAreaHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage33SendServerToPlayerArea_ClientAreaEP10CNWSPlayerP8CNWSAreafffRK6Vectori,
                (void*)&SendServerToPlayerArea_ClientAreaHook, Hooks::Order::Earliest);
    });
}

void ClientEvents::RemovePCFromWorldHook(CServerExoAppInternal *pServerExoAppInternal, CNWSPlayer *pPlayer)
{
    // NOTE: Events won't be processed for disconnecting characters, e.g. RemoveEffect events.
    // If we wanted that to happen, we'd need to process the event like CServerAIMaster__GetPendingEvent.
    Events::SignalEvent("NWNX_ON_CLIENT_DISCONNECT_BEFORE" , pPlayer->m_oidNWSObject);
    s_RemovePCFromWorldHook->CallOriginal<void>(pServerExoAppInternal, pPlayer);
    Events::SignalEvent("NWNX_ON_CLIENT_DISCONNECT_AFTER", pPlayer->m_oidNWSObject);
}

int32_t ClientEvents::SaveServerCharacterHook(CNWSPlayer *pPlayer, int32_t bBackupPlayer)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
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

int32_t ClientEvents::SendServerToPlayerCharListHook(CNWSMessage* pThis, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    if (!pPlayer)
        return s_SendServerToPlayerCharListHook->CallOriginal<int32_t>(pThis, pPlayer);

    auto *pNetLayer = Globals::AppManager()->m_pServerExoApp->GetNetLayer();
    auto *pPlayerInfo = pNetLayer->GetPlayerInfo(pPlayer->m_nPlayerID);

    std::string playerName = pPlayerInfo->m_sPlayerName.CStr();
    std::string cdKey = pPlayerInfo->m_lstKeys[0].sPublic.CStr();
    std::string isDM = std::to_string(pPlayerInfo->m_bGameMasterPrivileges);
    std::string ipAddress = pNetLayer->GetPlayerAddress(pPlayer->m_nPlayerID).CStr();

    std::string reason;
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("PLAYER_NAME", playerName);
        Events::PushEventData("CDKEY", cdKey);
        Events::PushEventData("IS_DM", isDM);
        Events::PushEventData("IP_ADDRESS", ipAddress);
        return Events::SignalEvent(ev, Utils::GetModule()->m_idSelf, &reason);
    };

    if (PushAndSignal("NWNX_ON_CLIENT_CONNECT_BEFORE"))
    {
        retVal = s_SendServerToPlayerCharListHook->CallOriginal<int32_t>(pThis, pPlayer);
    }
    else
    {
        pNetLayer->DisconnectPlayer(pPlayer->m_nPlayerID, 5838, true, reason.c_str());
        retVal = false;
    }
    PushAndSignal("NWNX_ON_CLIENT_CONNECT_AFTER");
    return retVal;
}

int32_t ClientEvents::CheckStickyPlayerNameReservedHook(CServerExoAppInternal *pServerExoAppInternal, CExoString sClientCDKey,
                                                        CExoString sLegacyCDKey, CExoString sPlayerName, int32_t nConnectionType)
{
    int32_t retVal;

    std::string valid;
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("PLAYER_NAME", sPlayerName.CStr());
        Events::PushEventData("CDKEY", sClientCDKey.CStr());
        Events::PushEventData("LEGACY_CDKEY", sLegacyCDKey.CStr());
        Events::PushEventData("IS_DM", nConnectionType == 32 ? "1" : "0");
        return Events::SignalEvent(ev, Utils::GetModule()->m_idSelf, &valid);
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

int32_t ClientEvents::SendServerToPlayerModule_ExportReplyHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    if (Events::SignalEvent("NWNX_ON_CLIENT_EXPORT_CHARACTER_BEFORE", pPlayer->m_oidNWSObject))
    {
        retVal = s_SendServerToPlayerModule_ExportReplyHook->CallOriginal<int32_t>(pMessage, pPlayer);
    }
    else
    {
        retVal = false;
    }

    Events::SignalEvent("NWNX_ON_CLIENT_EXPORT_CHARACTER_AFTER", pPlayer->m_oidNWSObject);

    return retVal;
}

int32_t ClientEvents::SendServerToPlayerArea_ClientAreaHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSArea *pArea,
                                                         float fX, float fY, float fZ, const Vector *vNewOrientation,
                                                         BOOL bPlayerIsNewToModule)
{
    Events::PushEventData("AREA", Utils::ObjectIDToString(pArea->m_idSelf));
    Events::PushEventData("PLAYER_NEW_TO_MODULE", std::to_string(bPlayerIsNewToModule));
    Events::SignalEvent("NWNX_ON_SERVER_SEND_AREA_BEFORE", pPlayer->m_oidNWSObject);
    auto retVal = s_SendServerToPlayerArea_ClientAreaHook->CallOriginal<int32_t>(pMessage, pPlayer, pArea, fX, fY, fZ,
                                                                                 vNewOrientation, bPlayerIsNewToModule);
    Events::PushEventData("AREA", Utils::ObjectIDToString(pArea->m_idSelf));
    Events::PushEventData("PLAYER_NEW_TO_MODULE", std::to_string(bPlayerIsNewToModule));
    Events::SignalEvent("NWNX_ON_SERVER_SEND_AREA_AFTER", pPlayer->m_oidNWSObject);

    return retVal;
}

}
