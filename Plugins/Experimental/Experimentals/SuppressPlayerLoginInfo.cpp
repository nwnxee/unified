#include "Experimentals/SuppressPlayerLoginInfo.hpp"


#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooks::Hook s_SendServerToPlayerPlayerList_AddHook;
static NWNXLib::Hooks::Hook s_SendServerToPlayerPlayerList_AllHook;
static NWNXLib::Hooks::Hook s_SendServerToPlayerPlayerList_DeleteHook;

SuppressPlayerLoginInfo::SuppressPlayerLoginInfo()
{
    s_SendServerToPlayerPlayerList_AddHook = Hooks::HookFunction(
            API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AddEjP10CNWSPlayer,
            (void*)&SendServerToPlayerPlayerList_AddHook, Hooks::Order::Late);

    s_SendServerToPlayerPlayerList_AllHook = Hooks::HookFunction(
            API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AllEP10CNWSPlayer,
            (void*)&SendServerToPlayerPlayerList_AllHook, Hooks::Order::Late);

    s_SendServerToPlayerPlayerList_DeleteHook = Hooks::HookFunction(
            API::Functions::_ZN11CNWSMessage35SendServerToPlayerPlayerList_DeleteEjP10CNWSPlayer,
            (void*)&SendServerToPlayerPlayerList_DeleteHook, Hooks::Order::Late);

    static auto s_ReplacedFunc = Hooks::HookFunction(API::Functions::_ZN11CNWSMessage49HandlePlayerToServerPlayModuleCharacterList_StartEP10CNWSPlayer,
                 (void*)&HandlePlayerToServerPlayModuleCharacterList_StartHook, Hooks::Order::Final);
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
