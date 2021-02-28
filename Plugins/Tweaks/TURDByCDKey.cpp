#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSPlayer.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_GetCDKeyInsteadOfPlayerName;

void TURDByCDKey() __attribute__((constructor));
void TURDByCDKey()
{
    if (!Config::Get<bool>("TURD_BY_CDKEY", false))
        return;

    LOG_INFO("TURDs are associated by CDKey/CharacterName instead of PlayerName/CharacterName.");

    static Hooks::Hook s_GetPlayerNameHook = Hooks::HookFunction(Functions::_ZN10CNWSPlayer13GetPlayerNameEv,
        (void*)+[](CNWSPlayer *pPlayer) -> CExoString
        {
            if (s_GetCDKeyInsteadOfPlayerName)
            {
                if (auto *pPlayerInfo = Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetPlayerInfo(pPlayer->m_nPlayerID))
                {
                    return pPlayerInfo->m_lstKeys[0].sPublic;
                }

                return CExoString("");
            }
            else
                return s_GetPlayerNameHook->CallOriginal<CExoString>(pPlayer);
        }, Hooks::Order::Late);

    static Hooks::Hook s_DropTURDHook = Hooks::HookFunction(Functions::_ZN10CNWSPlayer8DropTURDEv,
        (void*)+[](CNWSPlayer *pPlayer) -> void
        {
            s_GetCDKeyInsteadOfPlayerName = true;
            s_DropTURDHook->CallOriginal<void>(pPlayer);
            s_GetCDKeyInsteadOfPlayerName = false;
        }, Hooks::Order::Early);

    static Hooks::Hook s_RemoveFromTURDListHook = Hooks::HookFunction(Functions::_ZN10CNWSModule18RemoveFromTURDListEP10CNWSPlayer,
        (void*)+[](CNWSModule *pModule, CNWSPlayer *pPlayer) -> void
        {
            s_GetCDKeyInsteadOfPlayerName = true;
            s_RemoveFromTURDListHook->CallOriginal<void>(pModule, pPlayer);
            s_GetCDKeyInsteadOfPlayerName = false;
        }, Hooks::Order::Early);

    static Hooks::Hook s_GetPlayerTURDFromListHook = Hooks::HookFunction(Functions::_ZN10CNWSModule21GetPlayerTURDFromListEP10CNWSPlayer,
        (void*)+[](CNWSModule *pModule, CNWSPlayer *pPlayer) -> CNWSPlayerTURD*
        {
            s_GetCDKeyInsteadOfPlayerName = true;
            auto retVal = s_GetPlayerTURDFromListHook->CallOriginal<CNWSPlayerTURD*>(pModule, pPlayer);
            s_GetCDKeyInsteadOfPlayerName = false;
            return retVal;
        }, Hooks::Order::Early);
}

}
