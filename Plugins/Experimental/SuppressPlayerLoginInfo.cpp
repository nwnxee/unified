#include "nwnx.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;

static NWNXLib::Hooks::Hook s_SendServerToPlayerPlayerList_AddHook;
static NWNXLib::Hooks::Hook s_SendServerToPlayerPlayerList_AllHook;
static NWNXLib::Hooks::Hook s_SendServerToPlayerPlayerList_DeleteHook;
static NWNXLib::Hooks::Hook s_HandlePlayerToServerPlayModuleCharacterList_StartHook;

void SuppressPlayerLoginInfo() __attribute__((constructor));
void SuppressPlayerLoginInfo()
{
    if (!Config::Get<bool>("SUPPRESS_PLAYER_LOGIN_INFO", false))
        return;

    LOG_INFO("EXPERIMENTAL: Suppressing playerlist and player login/logout messages for non DMs.");

    s_SendServerToPlayerPlayerList_AddHook = Hooks::HookFunction(API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AddEjP10CNWSPlayer,
        (void*)+[](CNWSMessage *pThis, uint32_t nPlayerId, CNWSPlayer *pNewPlayer) -> int32_t
        {
            return nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS ? s_SendServerToPlayerPlayerList_AddHook->CallOriginal<int32_t>(pThis, nPlayerId, pNewPlayer) : false;
        }, Hooks::Order::Late);

    s_SendServerToPlayerPlayerList_AllHook = Hooks::HookFunction(API::Functions::_ZN11CNWSMessage32SendServerToPlayerPlayerList_AllEP10CNWSPlayer,
        (void*)+[](CNWSMessage *pThis, CNWSPlayer *pPlayer) -> int32_t
        {
            return pPlayer->m_nPlayerID == Constants::PLAYERID_ALL_GAMEMASTERS ? s_SendServerToPlayerPlayerList_AllHook->CallOriginal<int32_t>(pThis, pPlayer) : false;
        }, Hooks::Order::Late);

    s_SendServerToPlayerPlayerList_DeleteHook = Hooks::HookFunction(API::Functions::_ZN11CNWSMessage35SendServerToPlayerPlayerList_DeleteEjP10CNWSPlayer,
        (void*)+[](CNWSMessage *pThis, uint32_t nPlayerId, CNWSPlayer *pNewPlayer) -> int32_t
        {
            return nPlayerId == Constants::PLAYERID_ALL_GAMEMASTERS ? s_SendServerToPlayerPlayerList_DeleteHook->CallOriginal<int32_t>(pThis, nPlayerId, pNewPlayer) : false;
        }, Hooks::Order::Late);

    s_HandlePlayerToServerPlayModuleCharacterList_StartHook = Hooks::HookFunction(API::Functions::_ZN11CNWSMessage49HandlePlayerToServerPlayModuleCharacterList_StartEP10CNWSPlayer,
        (void*)+[](CNWSMessage* pThis, CNWSPlayer* pPlayer) -> int32_t
        {
            if (pThis->MessageReadOverflow(true) || pThis->MessageReadUnderflow(true))
                return false;

            pPlayer->m_bPlayModuleListingCharacters = true;
            return true;
        }, Hooks::Order::Final);
}

}
