#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class CompareVarsForMerge
{
public:
    CompareVarsForMerge(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t CNWSItem__CompareItem_hook(CNWSItem*, CNWSItem*);
    static NWNXLib::Hooking::FunctionHook* pCompareItem_hook;

};

}
