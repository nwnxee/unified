#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class ItemChargesCost
{
public:
    ItemChargesCost(int mode);

private:

    static void CNWSItem__CalculateBaseCosts_sharedhook(CNWSItem*);
};

}
