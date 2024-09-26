#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void CanUseItemsWhilePolymorphed() __attribute__((constructor));
void CanUseItemsWhilePolymorphed()
{
    if (!Config::Get<bool>("CAN_USE_ITEMS_WHILE_POLYMORPHED", false)) return;

    LOG_INFO("Allow all items to be used while polymorphed.");

    static Hooks::Hook s_CanUseItemHook = Hooks::HookFunction(&CNWSCreature::CanUseItem,
        +[](CNWSCreature* thisPtr, CNWSItem* pItem, BOOL bIgnoreIdentifiedFlag) -> BOOL
        {
            bool isPolymorphed = thisPtr->m_bIsPolymorphed;
            thisPtr->m_bIsPolymorphed = false;
            BOOL retVal = s_CanUseItemHook->CallOriginal<BOOL>(thisPtr, pItem, bIgnoreIdentifiedFlag);
            thisPtr->m_bIsPolymorphed = isPolymorphed;
            return retVal;
        }, Hooks::Order::Early);

    static Hooks::Hook s_UseItemHook = Hooks::HookFunction(&CNWSCreature::UseItem,
        +[](CNWSCreature* thisPtr, OBJECT_ID oidItem, uint8_t nActivePropertyIndex, uint8_t nSubPropertyIndex,
            OBJECT_ID oidTarget, Vector vTargetPosition, OBJECT_ID oidArea, BOOL bUseCharges = true) -> BOOL
        {
            bool isPolymorphed = thisPtr->m_bIsPolymorphed;
            thisPtr->m_bIsPolymorphed = false;
            BOOL retVal = s_UseItemHook->CallOriginal<BOOL>(thisPtr, oidItem, nActivePropertyIndex, nSubPropertyIndex,
                oidTarget, vTargetPosition, oidArea, bUseCharges);
            thisPtr->m_bIsPolymorphed = isPolymorphed;
            return retVal;
        }, Hooks::Order::Early);
}

}
