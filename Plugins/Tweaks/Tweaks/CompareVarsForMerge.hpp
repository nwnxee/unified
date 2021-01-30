#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class CompareVarsForMerge
{
public:
    CompareVarsForMerge(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CNWSItem__CompareItem_hook(CNWSItem*, CNWSItem*);
};

}
