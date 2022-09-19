#include "nwnx.hpp"

#include "API/CNWSItem.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void RetainLocalVariablesOnItemSplit() __attribute__((constructor));
void RetainLocalVariablesOnItemSplit()
{
    if (!Config::Get<bool>("RETAIN_LOCAL_VARIABLES_ON_ITEM_SPLIT", false))
        return;

    LOG_INFO("Split items will retain their local variables.");

    static bool s_SplitItem;
    static Hooks::Hook s_SplitItemHook = Hooks::HookFunction(
        &CNWSItem::SplitItem,
        +[](CNWSItem *thisPtr, int32_t nNumberToSplitOff) -> CNWSItem*
        {
            s_SplitItem = true;
            auto retVal = s_SplitItemHook->CallOriginal<CNWSItem*>(thisPtr, nNumberToSplitOff);
            s_SplitItem = false;
            return retVal;
        }, Hooks::Order::Earliest);

    static Hooks::Hook s_CopyItemHook = Hooks::HookFunction(
        &CNWSItem::CopyItem,
        +[](CNWSItem *thisPtr, CNWSItem *pSourceItem, int32_t bCopyVars) -> int32_t
        {
            return s_CopyItemHook->CallOriginal<int32_t>(thisPtr, pSourceItem, s_SplitItem ? true : bCopyVars);
        }, Hooks::Order::Early);
}

}
