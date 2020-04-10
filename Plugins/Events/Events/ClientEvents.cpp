#include "Events/ClientEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Constants.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWSModule.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static NWNXLib::Hooking::FunctionHook* m_ServerCharacterSaveHook;
static NWNXLib::Hooking::FunctionHook* m_SendServerToPlayerCharListHook;
static NWNXLib::Hooking::FunctionHook* m_CheckStickyPlayerNameReservedHook;

ClientEvents::ClientEvents(HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_CLIENT_DISCONNECT_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN21CServerExoAppInternal17RemovePCFromWorldEP10CNWSPlayer, void,
            CServerExoAppInternal*, CNWSPlayer*>(&RemovePCFromWorldHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_SERVER_CHARACTER_SAVE_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN10CNWSPlayer19SaveServerCharacterEi, int32_t,
            CNWSPlayer*, int32_t>(&OnServerCharacterSave);
        m_ServerCharacterSaveHook = hooker->FindHookByAddress(API::Functions::_ZN10CNWSPlayer19SaveServerCharacterEi);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_CLIENT_CONNECT_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN11CNWSMessage26SendServerToPlayerCharListEP10CNWSPlayer, int32_t,
            CNWSMessage*, CNWSPlayer*>(&SendServerToPlayerCharListHook);
        m_SendServerToPlayerCharListHook = hooker->FindHookByAddress(API::Functions::_ZN11CNWSMessage26SendServerToPlayerCharListEP10CNWSPlayer);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN13CServerExoApp29CheckStickyPlayerNameReservedE10CExoStringS0_S0_i, int32_t,
                CServerExoApp*, CExoString*, CExoString*, CExoString*, int32_t>(&CheckStickyPlayerNameReservedHook);
        m_CheckStickyPlayerNameReservedHook = hooker->FindHookByAddress(API::Functions::_ZN13CServerExoApp29CheckStickyPlayerNameReservedE10CExoStringS0_S0_i);
    });
}

int32_t ClientEvents::OnServerCharacterSave(CNWSPlayer* savingChar, int32_t bBackupPlayer)
{
    int32_t retVal;

    auto PushAndSignal = [&](std::string ev) -> bool {
        return Events::SignalEvent(ev, savingChar->GetGameObject()->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_SERVER_CHARACTER_SAVE_BEFORE"))
    {
        retVal = m_ServerCharacterSaveHook->CallOriginal<int32_t>(savingChar, bBackupPlayer);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_SERVER_CHARACTER_SAVE_AFTER");
    return retVal;
}

void ClientEvents::RemovePCFromWorldHook(bool before, CServerExoAppInternal*, CNWSPlayer* player)
{
    if (before)
    {
        Events::SignalEvent("NWNX_ON_CLIENT_DISCONNECT_BEFORE" , player->m_oidNWSObject);
        // NOTE: Events won't be processed for disconnecting characters, e.g. RemoveEffect events.
        // If we wanted that to happen, we'd need to process the event like CServerAIMaster__GetPendingEvent.
    }
    else
    {
        Events::SignalEvent("NWNX_ON_CLIENT_DISCONNECT_AFTER", player->m_oidNWSObject);
    }

}

int32_t ClientEvents::SendServerToPlayerCharListHook(CNWSMessage* pThis, CNWSPlayer* pPlayer)
{
    int32_t retVal;

    if (!pPlayer)
        return false;

    auto *pNetLayer = Globals::AppManager()->m_pServerExoApp->GetNetLayer();
    auto *pPlayerInfo = pNetLayer->GetPlayerInfo(pPlayer->m_nPlayerID);

    std::string playerName = pPlayerInfo->m_sPlayerName.CStr();
    std::string cdKey = pPlayerInfo->m_lstKeys[0].sPublic.CStr();
    std::string isDM = std::to_string(pPlayerInfo->m_bGameMasterPrivileges);
    std::string ipAddress = pNetLayer->GetPlayerAddress(pPlayer->m_nPlayerID).CStr();

    std::string reason;
    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("PLAYER_NAME", playerName);
        Events::PushEventData("CDKEY", cdKey);
        Events::PushEventData("IS_DM", isDM);
        Events::PushEventData("IP_ADDRESS", ipAddress);
        return Events::SignalEvent(ev, Utils::GetModule()->m_idSelf, &reason);
    };

    if (PushAndSignal("NWNX_ON_CLIENT_CONNECT_BEFORE"))
    {
        retVal = m_SendServerToPlayerCharListHook->CallOriginal<int32_t>(pThis, pPlayer);
    }
    else
    {
        pNetLayer->DisconnectPlayer(pPlayer->m_nPlayerID, 5838, true, reason.c_str());
        retVal = false;
    }
    PushAndSignal("NWNX_ON_CLIENT_CONNECT_AFTER");
    return retVal;
}

int32_t ClientEvents::CheckStickyPlayerNameReservedHook(
        CServerExoApp *pServer,
        CExoString *p_sClientCDKey,
        CExoString *p_sClientLegacyCDKey,
        CExoString *p_sPlayerName,
        int32_t nConnectionType)
{
    int32_t retVal;

    std::string valid;
    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("PLAYER_NAME", p_sPlayerName->CStr());
        Events::PushEventData("CDKEY", p_sClientCDKey->CStr());
        Events::PushEventData("LEGACY_CDKEY", p_sClientLegacyCDKey->CStr());
        Events::PushEventData("IS_DM", nConnectionType == 32 ? "1" : "0");
        return Events::SignalEvent(ev, Utils::GetModule()->m_idSelf, &valid);
    };

    if (PushAndSignal("NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_BEFORE"))
    {
        retVal = m_CheckStickyPlayerNameReservedHook->CallOriginal<int32_t>(pServer, p_sClientCDKey, p_sClientLegacyCDKey, p_sPlayerName, nConnectionType);
    }
    else
    {
        retVal = valid == "1" ? 1 : 0;
    }
    PushAndSignal("NWNX_ON_CHECK_STICKY_PLAYER_NAME_RESERVED_AFTER");
    return retVal;

}

}
