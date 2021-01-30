#pragma once
#include "nwnx.hpp"


class CNWSObjectActionNode;

namespace Tweaks {

class UnhardcodeShields
{
public:
    UnhardcodeShields();

private:
    static int32_t CNWSItem__ComputeArmorClass(CNWSItem* thisPtr);
    static void CNWSCreature__ComputeArmourClass(CNWSCreature* thisPtr, CNWSItem* pItemToEquip, BOOL bEquipping, BOOL bLoadingItem);
};

}
