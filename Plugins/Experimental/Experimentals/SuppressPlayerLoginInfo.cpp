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

NWNXLib::Hooking::FunctionHook* m_SendServerToPlayerPlayerList_AddHook;
NWNXLib::Hooking::FunctionHook* m_SendServerToPlayerPlayerList_AllHook;
NWNXLib::Hooking::FunctionHook* m_SendServerToPlayerPlayerList_DeleteHook;

SuppressPlayerLoginInfo::SuppressPlayerLoginInfo(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<API::Functions::CNWSMessage__SendServerToPlayerPlayerList_Add, int32_t>(&SendServerToPlayerPlayerList_AddHook);
    m_SendServerToPlayerPlayerList_AddHook = hooker->FindHookByAddress(API::Functions::CNWSMessage__SendServerToPlayerPlayerList_Add);

    hooker->RequestExclusiveHook<API::Functions::CNWSMessage__SendServerToPlayerPlayerList_All, int32_t>(&SendServerToPlayerPlayerList_AllHook);
    m_SendServerToPlayerPlayerList_AllHook = hooker->FindHookByAddress(API::Functions::CNWSMessage__SendServerToPlayerPlayerList_All);

    hooker->RequestExclusiveHook<API::Functions::CNWSMessage__SendServerToPlayerPlayerList_Delete, int32_t>(&SendServerToPlayerPlayerList_DeleteHook);
    m_SendServerToPlayerPlayerList_DeleteHook = hooker->FindHookByAddress(API::Functions::CNWSMessage__SendServerToPlayerPlayerList_Delete);
}

int32_t SuppressPlayerLoginInfo::SendServerToPlayerPlayerList_AddHook(CNWSMessage *pThis, uint32_t nPlayerId, CNWSPlayer *pNewPlayer)
{
    return nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS ?
        m_SendServerToPlayerPlayerList_AddHook->CallOriginal<int32_t>(pThis, nPlayerId, pNewPlayer) :
        false;
}

int32_t SuppressPlayerLoginInfo::SendServerToPlayerPlayerList_AllHook(CNWSMessage *pThis, CNWSPlayer *pPlayer)
{
    return pPlayer->m_nPlayerID == Constants::PLAYERID_ALL_GAMEMASTERS ?
        m_SendServerToPlayerPlayerList_AllHook->CallOriginal<int32_t>(pThis, pPlayer) :
        false;
}

int32_t SuppressPlayerLoginInfo::SendServerToPlayerPlayerList_DeleteHook(CNWSMessage *pThis, uint32_t nPlayerId, CNWSPlayer *pNewPlayer)
{
    return nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS ?
           m_SendServerToPlayerPlayerList_DeleteHook->CallOriginal<int32_t>(pThis, nPlayerId, pNewPlayer) :
           false;
}

}
