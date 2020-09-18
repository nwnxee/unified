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

PreserveDepletedItems::PreserveDepletedItems(Services::HooksProxy* hooker)
{
    hooker->RequestSharedHook<Functions::_ZN12CNWSCreature21AIActionItemCastSpellEP20CNWSObjectActionNode, uint32_t>(&CNWSCreature__AIActionItemCastSpell_hook);
}


void PreserveDepletedItems::CNWSCreature__AIActionItemCastSpell_hook(bool before, CNWSCreature*, CNWSObjectActionNode *pNode)
{
    static int bPlot;
    // If at risk of destroying the item, set the item to plot, then set it back
    // afterwards to its original value.
    auto *pItem = Utils::AsNWSItem(Utils::GetGameObject((ObjectID)(uintptr_t)pNode->m_pParameter[0]));
    if (pItem)
    {
        if (before)
        {
            bPlot = pItem->m_bPlotObject;
            if(pItem->m_nNumCharges > 0 && pItem->m_nNumCharges <= 5)
                pItem->m_bPlotObject = true;
        }
        else
        {
            pItem->m_bPlotObject = bPlot;
        }
    }
}


}
