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
    // If at risk of destroying the item, inflate charge count temporarily to bypass the destroy
    // event, then set it back to mark the spells as unusable.
    auto *pItem = Utils::AsNWSItem(Utils::GetGameObject((Types::ObjectID)pNode->m_pParameter[0]));
    if (pItem && pItem->m_nNumCharges <= 5)
    {
        pItem->m_nNumCharges += 10;
        int32_t ret = pAIActionItemCastSpell_hook->CallOriginal<uint32_t>(pThis, pNode);
        pItem->SetNumCharges(pItem->m_nNumCharges - 10, true /* update which properties are usable */);
        return ret;
    }
    return pAIActionItemCastSpell_hook->CallOriginal<uint32_t>(pThis, pNode);
}


}
