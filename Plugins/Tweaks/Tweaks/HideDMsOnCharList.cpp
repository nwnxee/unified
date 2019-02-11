#include "Tweaks/HideDMsOnCharList.hpp"

#include "Services/Hooks/Hooks.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CExoLinkedListTemplatedCNWSClient.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

HideDMsOnCharList::HideDMsOnCharList(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<API::Functions::CNWSMessage__HandlePlayerToServerPlayModuleCharacterList_Start>
        (&HandlePlayerToServerPlayModuleCharacterList_StartHook);
}

int32_t HideDMsOnCharList::HandlePlayerToServerPlayModuleCharacterList_StartHook(
    CNWSMessage* pThis, CNWSPlayer* pPlayer)
{
    if (pThis->MessageReadOverflow(true) || pThis->MessageReadUnderflow(true))
        return false;

    auto *server = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal;
    auto *players = server->m_pNWSPlayerList->m_pcExoLinkedListInternal;

    for (auto *node = players->pHead; node; node = node->pNext)
    {
        auto *other = static_cast<CNWSPlayer*>(node->pObject);
        if (other && other->m_nCharacterType != Constants::CharacterType::DM)
        {
            pThis->SendServerToPlayerPlayModuleCharacterListResponse(
                pPlayer->m_nPlayerID, other->m_oidNWSObject, true);
        }
    }

    pPlayer->m_bPlayModuleListingCharacters = true;
    return true;
}

}
