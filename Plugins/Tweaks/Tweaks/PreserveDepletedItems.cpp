#include "Tweaks/PreserveDepletedItems.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSObjectActionNode.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"



namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_AIActionItemCastSpellHook;

PreserveDepletedItems::PreserveDepletedItems()
{
    s_AIActionItemCastSpellHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature21AIActionItemCastSpellEP20CNWSObjectActionNode,
                                               (void*)&CNWSCreature__AIActionItemCastSpell_hook, Hooks::Order::Late);
}


uint32_t PreserveDepletedItems::CNWSCreature__AIActionItemCastSpell_hook(CNWSCreature *thisPtr, CNWSObjectActionNode *pNode)
{
    if (auto *pItem = Utils::AsNWSItem(Utils::GetGameObject((ObjectID)(uintptr_t)pNode->m_pParameter[0])))
    {
        int32_t bPlot = pItem->m_bPlotObject;

        if(pItem->m_nNumCharges > 0 && pItem->m_nNumCharges <= 5)
            pItem->m_bPlotObject = true;

        auto retVal = s_AIActionItemCastSpellHook->CallOriginal<uint32_t>(thisPtr, pNode);

        pItem->m_bPlotObject = bPlot;

        return retVal;

    }

    return s_AIActionItemCastSpellHook->CallOriginal<uint32_t>(thisPtr, pNode);
}

}
