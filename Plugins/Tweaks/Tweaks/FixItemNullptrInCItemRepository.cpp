#include "Tweaks/FixItemNullptrInCItemRepository.hpp"


#include "API/C2DA.hpp"
#include "API/CAppManager.hpp"
#include "API/CItemRepository.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSRules.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/Functions.hpp"
#include <cmath>

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

FixItemNullptrInCItemRepository::FixItemNullptrInCItemRepository()
{
    static auto s_ReplacedFunc = Hooks::HookFunction(Functions::_ZN15CItemRepository23CalculateContentsWeightEv,
                 (void*)&CItemRepository__CalculateContentsWeight_hook, Hooks::Order::Final);
}

int32_t FixItemNullptrInCItemRepository::CItemRepository__CalculateContentsWeight_hook(CItemRepository *pThis)
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
                auto *pPlayer = pServer->GetClientObjectByObjectId(pCreature->m_idSelf);
                if (pPlayer)
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
