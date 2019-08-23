#include "Tweaks/PreserveDepletedItems.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSObjectActionNode.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* PreserveDepletedItems::pAIActionItemCastSpell_hook;
PreserveDepletedItems::PreserveDepletedItems(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWSCreature__AIActionItemCastSpell>
                                    (&CNWSCreature__AIActionItemCastSpell_hook);

    pAIActionItemCastSpell_hook = hooker->FindHookByAddress(Functions::CNWSCreature__AIActionItemCastSpell);
}


uint32_t PreserveDepletedItems::CNWSCreature__AIActionItemCastSpell_hook(CNWSCreature *pThis, CNWSObjectActionNode *pNode)
{
    // If at risk of destroying the item, set the item to plot, then set it back
    // afterwards to its original value.
    auto *pItem = Utils::AsNWSItem(Utils::GetGameObject((Types::ObjectID)pNode->m_pParameter[0]));
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
