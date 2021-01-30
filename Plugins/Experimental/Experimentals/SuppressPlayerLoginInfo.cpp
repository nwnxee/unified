#include "Experimentals/SuppressPlayerLoginInfo.hpp"


#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooking::FunctionHook* s_SendServerToPlayerPlayerList_AddHook;
static NWNXLib::Hooking::FunctionHook* s_SendServerToPlayerPlayerList_AllHook;
static NWNXLib::Hooking::FunctionHook* s_SendServerToPlayerPlayerList_DeleteHook;

SuppressPlayerLoginInfo::SuppressPlayerLoginInfo(Services::HooksProxy* hooker)
{
    s_SendServerToPlayerPlayerList_AddHook = hooker->Hook(
            API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AddEjP10CNWSPlayer,
            (void*)&SendServerToPlayerPlayerList_AddHook, Hooking::Order::Late);

    s_SendServerToPlayerPlayerList_AllHook = hooker->Hook(
            API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AllEP10CNWSPlayer,
            (void*)&SendServerToPlayerPlayerList_AllHook, Hooking::Order::Late);

    s_SendServerToPlayerPlayerList_DeleteHook = hooker->Hook(
            API::Functions::_ZN11CNWSMessage35SendServerToPlayerPlayerList_DeleteEjP10CNWSPlayer,
            (void*)&SendServerToPlayerPlayerList_DeleteHook, Hooking::Order::Late);

    hooker->Hook(API::Functions::_ZN11CNWSMessage49HandlePlayerToServerPlayModuleCharacterList_StartEP10CNWSPlayer,
                 (void*)&HandlePlayerToServerPlayModuleCharacterList_StartHook, Hooking::Order::Final);
}

int32_t SuppressPlayerLoginInfo::SendServerToPlayerPlayerList_AddHook(CNWSMessage *pThis, uint32_t nPlayerId, CNWSPlayer *pNewPlayer)
{
    return nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS ? s_SendServerToPlayerPlayerList_AddHook->CallOriginal<int32_t>(pThis, nPlayerId, pNewPlayer) : false;
}
int32_t SuppressPlayerLoginInfo::SendServerToPlayerPlayerList_AllHook(CNWSMessage *pThis, CNWSPlayer *pPlayer)
{
    return pPlayer->m_nPlayerID == Constants::PLAYERID_ALL_GAMEMASTERS ? s_SendServerToPlayerPlayerList_AllHook->CallOriginal<int32_t>(pThis, pPlayer) : false;
}
int32_t SuppressPlayerLoginInfo::SendServerToPlayerPlayerList_DeleteHook(CNWSMessage *pThis, uint32_t nPlayerId, CNWSPlayer *pNewPlayer)
{
    return nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS ? s_SendServerToPlayerPlayerList_DeleteHook->CallOriginal<int32_t>(pThis, nPlayerId, pNewPlayer) : false;
}
int32_t SuppressPlayerLoginInfo::HandlePlayerToServerPlayModuleCharacterList_StartHook(
    CNWSMessage* pThis, CNWSPlayer* pPlayer)
{
    if (pThis->MessageReadOverflow(true) || pThis->MessageReadUnderflow(true))
        return false;

    pPlayer->m_bPlayModuleListingCharacters = true;
    return true;
}

}
