#include "Tweaks/CompareVarsForMerge.hpp"
#include "API/CNWSItem.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* CompareVarsForMerge::pCompareItem_hook;
CompareVarsForMerge::CompareVarsForMerge(Services::HooksProxy* hooker)
{
    pCompareItem_hook = hooker->RequestExclusiveHook
        <Functions::_ZN8CNWSItem11CompareItemEPS_>(&CNWSItem__CompareItem_hook);
}

int32_t CompareVarsForMerge::CNWSItem__CompareItem_hook(CNWSItem* thisPtr, CNWSItem* pOtherItem)
{
    int32_t bCompare = pCompareItem_hook->CallOriginal<int32_t>(thisPtr, pOtherItem);
    if (bCompare)
    {
        bCompare = Utils::CompareVariables(&thisPtr->m_ScriptVars, &pOtherItem->m_ScriptVars);
    }
    return bCompare;
}

}
