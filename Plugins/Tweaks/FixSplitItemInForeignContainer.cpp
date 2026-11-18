#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSItem.hpp"
#include "API/CServerExoApp.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void FixSplitItemInForeignContainer() __attribute__((constructor));
void FixSplitItemInForeignContainer()
{
    if (!Config::Get<bool>("FIX_SPLIT_ITEM_IN_FOREIGN_CONTAINER", false))
        return;

    LOG_INFO("Splitting an item inside a container owned by another object will be refused.");

    static Hooks::Hook s_SplitItemHook = Hooks::HookFunction(&CNWSCreature::SplitItem,
        +[](CNWSCreature *pCreature, CNWSItem *pItem, int32_t nNumberToSplitOff) -> void
        {
            if (pCreature && pItem && pItem->m_oidPossessor != pCreature->m_idSelf)
            {
                if (!Globals::AppManager()->m_pServerExoApp->GetGameObject(pItem->m_oidPossessor))
                {
                    LOG_WARNING("Refused to split item 0x%08x with no possessor for creature 0x%08x.",
                                pItem->m_idSelf, pCreature->m_idSelf);
                    return;
                }
                // The engine would put the split-off stack in the creature's own inventory
                if (auto *pBag = Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(pItem->m_oidPossessor))
                {
                    if (pBag->m_oidPossessor != pCreature->m_idSelf)
                    {
                        LOG_WARNING("Refused to split item 0x%08x in container 0x%08x (owned by 0x%08x) for creature 0x%08x.",
                                    pItem->m_idSelf, pBag->m_idSelf, pBag->m_oidPossessor, pCreature->m_idSelf);
                        return;
                    }
                }
            }
            s_SplitItemHook->CallOriginal<void>(pCreature, pItem, nNumberToSplitOff);
        }, Hooks::Order::Earliest);
}

}
