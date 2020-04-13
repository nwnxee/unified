#include "Experimentals/SuppressPlayerLoginInfo.hpp"

#include "Services/Hooks/Hooks.hpp"

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
    s_SendServerToPlayerPlayerList_AddHook = hooker->RequestExclusiveHook
        <API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AddEjP10CNWSPlayer, int32_t>
        (&SendServerToPlayerPlayerList_AddHook);

    s_SendServerToPlayerPlayerList_AllHook = hooker->RequestExclusiveHook
        <API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AllEP10CNWSPlayer, int32_t>
        (&SendServerToPlayerPlayerList_AllHook);

    s_SendServerToPlayerPlayerList_DeleteHook = hooker->RequestExclusiveHook
        <API::Functions::_ZN11CNWSMessage35SendServerToPlayerPlayerList_DeleteEjP10CNWSPlayer, int32_t>
        (&SendServerToPlayerPlayerList_DeleteHook);

    hooker->RequestExclusiveHook<API::Functions::_ZN11CNWSMessage49HandlePlayerToServerPlayModuleCharacterList_StartEP10CNWSPlayer>
        (&HandlePlayerToServerPlayModuleCharacterList_StartHook);
}

int32_t SuppressPlayerLoginInfo::SendServerToPlayerPlayerList_AddHook(CNWSMessage *pThis, uint32_t nPlayerId, CNWSPlayer *pNewPlayer)
{
    return nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS ?
        s_SendServerToPlayerPlayerList_AddHook->CallOriginal<int32_t>(pThis, nPlayerId, pNewPlayer) :
        false;
}

int32_t SuppressPlayerLoginInfo::SendServerToPlayerPlayerList_AllHook(CNWSMessage *pThis, CNWSPlayer *pPlayer)
{
    return pPlayer->m_nPlayerID == Constants::PLAYERID_ALL_GAMEMASTERS ?
        s_SendServerToPlayerPlayerList_AllHook->CallOriginal<int32_t>(pThis, pPlayer) :
        false;
}

int32_t SuppressPlayerLoginInfo::SendServerToPlayerPlayerList_DeleteHook(CNWSMessage *pThis, uint32_t nPlayerId, CNWSPlayer *pNewPlayer)
{
    return nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS ?
           s_SendServerToPlayerPlayerList_DeleteHook->CallOriginal<int32_t>(pThis, nPlayerId, pNewPlayer) :
           false;
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
