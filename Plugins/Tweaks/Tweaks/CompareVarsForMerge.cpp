#include "Tweaks/CompareVarsForMerge.hpp"
#include "API/CNWSItem.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"



namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_CompareItem_hook;

CompareVarsForMerge::CompareVarsForMerge()
{
    s_CompareItem_hook = Hooks::HookFunction(Functions::_ZN8CNWSItem11CompareItemEPS_, (void*)&CNWSItem__CompareItem_hook, Hooks::Order::Late);
}

int32_t CompareVarsForMerge::CNWSItem__CompareItem_hook(CNWSItem* thisPtr, CNWSItem* pOtherItem)
{
    auto bCompare = s_CompareItem_hook->CallOriginal<int32_t>(thisPtr, pOtherItem);
    if (bCompare)
    {
        bCompare = Utils::CompareVariables(&thisPtr->m_ScriptVars, &pOtherItem->m_ScriptVars);
    }
    return bCompare;
}

}
