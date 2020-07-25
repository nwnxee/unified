#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class CompareVarsForMerge
{
public:
    CompareVarsForMerge(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CNWSItem__CompareItem_hook(CNWSItem*, CNWSItem*);
    static NWNXLib::Hooking::FunctionHook* pCompareItem_hook;

};

}
