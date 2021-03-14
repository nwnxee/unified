#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


static int s_HideCharBehavior = 0;

static int32_t HandlePlayerToServerPlayModuleCharacterList_StartHook(CNWSMessage*, CNWSPlayer*);

void HidePlayersOnCharList() __attribute__((constructor));
void HidePlayersOnCharList()
{
    s_HideCharBehavior = Config::Get<int>("HIDE_PLAYERS_ON_CHAR_LIST", 0);

    if (s_HideCharBehavior == 0)
        return;
    else if (s_HideCharBehavior == 1)
        LOG_INFO("DMs will not be visible on character list.");
    else if (s_HideCharBehavior == 2)
        LOG_INFO("PCs will not be visible on character list.");
    else if (s_HideCharBehavior == 3)
        LOG_INFO("DMs and PCs will not be visible on character list.");
    else
    {
        LOG_INFO("Unknown value for HIDE_PLAYERS_ON_CHAR_LIST.");
        return;
    }

    static Hooks::Hook s_HandlePlayerToServerPlayModuleCharacterList_StartHook =
            Hooks::HookFunction(API::Functions::_ZN11CNWSMessage49HandlePlayerToServerPlayModuleCharacterList_StartEP10CNWSPlayer,
                (void*)&HandlePlayerToServerPlayModuleCharacterList_StartHook, Hooks::Order::Final);
}

static int32_t HandlePlayerToServerPlayModuleCharacterList_StartHook(CNWSMessage* pThis, CNWSPlayer* pPlayer)
{
    if (pThis->MessageReadOverflow(true) || pThis->MessageReadUnderflow(true))
        return false;

    auto *server = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal;
    auto *players = server->m_pNWSPlayerList->m_pcExoLinkedListInternal;
    if (pPlayer->GetIsDM() || s_HideCharBehavior < 3)
    {
        for (auto *node = players->pHead; node; node = node->pNext)
        {
            auto *other = static_cast<CNWSPlayer*>(node->pObject);
            if (other &&
                (pPlayer->GetIsDM() ||
                (s_HideCharBehavior == 1 && !other->GetIsDM()) || (s_HideCharBehavior == 2 && other->GetIsDM())))
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
