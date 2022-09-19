#include "nwnx.hpp"

#include "API/C2DA.hpp"
#include "API/CAppManager.hpp"
#include "API/CItemRepository.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSRules.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CTwoDimArrays.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


static int32_t CalculateContentsWeightHook(CItemRepository*);

void FixItemNullptrInCItemRepository() __attribute__((constructor));
void FixItemNullptrInCItemRepository()
{
    if (!Config::Get<bool>("FIX_ITEM_NULLPTR_IN_CITEMREPOSITORY", false))
        return;

    LOG_INFO("Will check for invalid items in the CItemRepository List.");

    static Hooks::Hook s_CalculateContentsWeightHook = Hooks::HookFunction(&CItemRepository::CalculateContentsWeight,
                                                                           &CalculateContentsWeightHook, Hooks::Order::Final);
}

static int32_t CalculateContentsWeightHook(CItemRepository *pThis)
{
    int32_t nResult = 0;
    auto *pServer = Globals::AppManager()->m_pServerExoApp;
    std::vector<CExoLinkedListNode*> badItem(32);

    for (auto *node = pThis->m_oidItems.m_pcExoLinkedListInternal->pHead; node; node = node->pNext)
    {
        auto *pItem = pThis->ItemListGetItem(node);
        auto *pParentItem = pServer->GetItemByGameObjectID(pThis->m_oidParent);

        if (pItem == nullptr)
        {
            badItem.push_back(node);
            CExoString playerName = "unknown";

            auto *pCreature = Utils::AsNWSCreature(pServer->GetGameObject(pThis->m_oidParent));
            if (!pCreature)
                pCreature = Utils::AsNWSCreature(pServer->GetGameObject(pParentItem->m_oidPossessor));

            if (pCreature)
            {
                if (auto *pPlayer = pServer->GetClientObjectByObjectId(pCreature->m_idSelf))
                    playerName = pPlayer->GetPlayerName();
            }

            ASSERT_FAIL_MSG("An item repository owned by a character played by `%s` referenced a nullptr item", playerName.CStr());

            continue;
        }

        if (pParentItem && pParentItem->GetPropertyByTypeExists(Constants::ItemProperty::EnhancedContainerReducedWeight))
        {
            float fReduction;
            CNWItemProperty *pItemProperty;
            pParentItem->GetPropertyByType(&pItemProperty, Constants::ItemProperty::EnhancedContainerReducedWeight);

            Globals::Rules()->m_p2DArrays->GetIPRPCostTable(0xFu)->GetFLOATEntry(pItemProperty->m_nCostTableValue, CExoString("Value"), &fReduction);
            int32_t nItemAdjustedWeight;
            nItemAdjustedWeight = (int32_t)(pItem->GetWeight() - (pItem->GetWeight() * fReduction));

            nResult += nItemAdjustedWeight;
        }
        else
            nResult += pItem->GetWeight();
    }

    for (auto bad: badItem)
        pThis->m_oidItems.Remove(bad);

    return nResult;
}

}
