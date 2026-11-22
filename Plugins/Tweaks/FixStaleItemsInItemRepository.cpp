#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CItemRepository.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CServerExoApp.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void FixStaleItemsInItemRepository() __attribute__((constructor));
void FixStaleItemsInItemRepository()
{
    if (!Config::Get<bool>("FIX_STALE_ITEMS_IN_ITEM_REPOSITORY", false))
        return;

    LOG_INFO("Item IDs that no longer resolve to an item will be removed from inventories before they are sent to players.");

    static Hooks::Hook s_WriteRepositoryUpdateHook = Hooks::HookFunction(&CNWSMessage::WriteRepositoryUpdate,
        +[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pPlayerGameObject, CItemRepository *pItemRepository,
            CNWSPlayerLUOInventory *pLastUpdateInventory, uint8_t nLastUpdateList, char cGuiElementByte, uint8_t nCurrentPanel) -> void
        {
            if (pItemRepository && pItemRepository->m_oidItems.m_pcExoLinkedListInternal)
            {
                auto *pServer = Globals::AppManager()->m_pServerExoApp;
                for (auto *pNode = pItemRepository->m_oidItems.m_pcExoLinkedListInternal->pHead; pNode;)
                {
                    auto *pNext = pNode->pNext;
                    auto *pOid = static_cast<OBJECT_ID*>(pNode->pObject);
                    if (!pOid || !pServer->GetItemByGameObjectID(*pOid))
                    {
                        LOG_WARNING("Removed item 0x%08x, which no longer exists, from the item repository of 0x%08x.",
                                    pOid ? *pOid : Constants::OBJECT_INVALID, pItemRepository->m_oidParent);
                        delete pItemRepository->m_oidItems.Remove(pNode);
                    }
                    pNode = pNext;
                }
            }
            s_WriteRepositoryUpdateHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pItemRepository,
                                                            pLastUpdateInventory, nLastUpdateList, cGuiElementByte, nCurrentPanel);
        }, Hooks::Order::Earliest);
}

}
