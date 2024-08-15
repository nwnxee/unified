#include "nwnx.hpp"

#include "API/CNWSItem.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void CompareVarsForMerge() __attribute__((constructor));
void CompareVarsForMerge()
{
    if (!Config::Get<bool>("COMPARE_VARIABLES_WHEN_MERGING", false))
        return;

    LOG_INFO("Will compare local variables when merging item stacks");

    static Hooks::Hook s_CompareItem_hook = Hooks::HookFunction(&CNWSItem::CompareItem,
        +[](CNWSItem* thisPtr, CNWSItem* pOtherItem) -> int32_t
        {
            auto bCompare = s_CompareItem_hook->CallOriginal<int32_t>(thisPtr, pOtherItem);
            if (bCompare)
            {
                bCompare = Utils::CompareVariables(&thisPtr->m_ScriptVars, &pOtherItem->m_ScriptVars);
            }
            return bCompare;
        }, Hooks::Order::Late);
}

}
