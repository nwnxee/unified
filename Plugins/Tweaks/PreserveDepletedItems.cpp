#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSItem.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void PreserveDepletedItems() __attribute__((constructor));
void PreserveDepletedItems()
{
    if (!Config::Get<bool>("PRESERVE_DEPLETED_ITEMS", false))
        return;

    LOG_INFO("Items will no longer be destroyed when they run out of charges");

    static Hooks::Hook s_AIActionItemCastSpellHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature21AIActionItemCastSpellEP20CNWSObjectActionNode,
        (void*)+[](CNWSCreature *thisPtr, CNWSObjectActionNode *pNode) -> uint32_t
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
        }, Hooks::Order::Late);
}

}
