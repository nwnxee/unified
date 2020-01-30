#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class ItemChargesCost
{
public:
    ItemChargesCost(NWNXLib::Services::HooksProxy* hooker, int mode, bool exclusive);

private:
    static int s_chargesCostBehavior;
    static int s_savedCharges;

    static void CNWSItem__CalculateBaseCosts_hook(CNWSItem*);
    static void CNWSItem__CalculateBaseCosts_sharedhook(bool, CNWSItem*);
};

}
