#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class ItemChargesCost
{
public:
    ItemChargesCost(NWNXLib::Services::HooksProxy* hooker, int mode);

private:

    static void CNWSItem__CalculateBaseCosts_sharedhook(CNWSItem*);
};

}
