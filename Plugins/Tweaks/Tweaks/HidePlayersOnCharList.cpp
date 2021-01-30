#include "Tweaks/HidePlayersOnCharList.hpp"


#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

int HidePlayersOnCharList::s_hideCharBehavior = 0;

HidePlayersOnCharList::HidePlayersOnCharList(int mode)
{
    s_hideCharBehavior = mode;
    if (mode < 1 || mode > 3)
    {
        LOG_INFO("Unknown value for HIDE_PLAYERS_ON_CHAR_LIST.");
        return;
    }
    static auto s_ReplacedFunc = Hooks::HookFunction(API::Functions::_ZN11CNWSMessage49HandlePlayerToServerPlayModuleCharacterList_StartEP10CNWSPlayer,
                 (void*)&HandlePlayerToServerPlayModuleCharacterList_StartHook, Hooks::Order::Final);
}

int32_t HidePlayersOnCharList::HandlePlayerToServerPlayModuleCharacterList_StartHook(CNWSMessage* pThis, CNWSPlayer* pPlayer)
{
    if (pThis->MessageReadOverflow(true) || pThis->MessageReadUnderflow(true))
        return false;

    auto *server = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal;
    auto *players = server->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    if (pPlayer->GetIsDM() || s_hideCharBehavior < 3)
    {
        for (auto *node = players->pHead; node; node = node->pNext)
        {
            auto *other = static_cast<CNWSPlayer*>(node->pObject);
            if (other &&
                (pPlayer->GetIsDM() ||
                (s_hideCharBehavior == 1 && !other->GetIsDM()) || (s_hideCharBehavior == 2 && other->GetIsDM())))
            {
                pThis->SendServerToPlayerPlayModuleCharacterListResponse(
                        pPlayer->m_nPlayerID, other->m_oidNWSObject, true);
            }
        }
    }

    pPlayer->m_bPlayModuleListingCharacters = true;
    return true;
}

}
