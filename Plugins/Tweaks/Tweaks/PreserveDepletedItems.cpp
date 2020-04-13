#include "Tweaks/PreserveDepletedItems.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSObjectActionNode.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* PreserveDepletedItems::pAIActionItemCastSpell_hook;
PreserveDepletedItems::PreserveDepletedItems(Services::HooksProxy* hooker)
{
    pAIActionItemCastSpell_hook = hooker->RequestExclusiveHook
        <Functions::_ZN12CNWSCreature21AIActionItemCastSpellEP20CNWSObjectActionNode>(&CNWSCreature__AIActionItemCastSpell_hook);
}


uint32_t PreserveDepletedItems::CNWSCreature__AIActionItemCastSpell_hook(CNWSCreature *pThis, CNWSObjectActionNode *pNode)
{
    // If at risk of destroying the item, set the item to plot, then set it back
    // afterwards to its original value.
    auto *pItem = Utils::AsNWSItem(Utils::GetGameObject((ObjectID)(uintptr_t)pNode->m_pParameter[0]));
    if (pItem && pItem->m_nNumCharges > 0 && pItem->m_nNumCharges <= 5)
    {
        int bPlot = pItem->m_bPlotObject;
        pItem->m_bPlotObject = true;
        int32_t ret = pAIActionItemCastSpell_hook->CallOriginal<uint32_t>(pThis, pNode);
        pItem->m_bPlotObject = bPlot;
        return ret;
    }
    return pAIActionItemCastSpell_hook->CallOriginal<uint32_t>(pThis, pNode);
}


}
