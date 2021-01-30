#pragma once
#include "nwnx.hpp"


class CNWSObjectActionNode;

namespace Tweaks {

class UnhardcodeShields
{
public:
    UnhardcodeShields(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CNWSItem__ComputeArmorClass(CNWSItem* thisPtr);
    static void CNWSCreature__ComputeArmourClass(bool before, CNWSCreature* thisPtr, CNWSItem* pItemToEquip, BOOL bEquipping, BOOL bLoadingItem);
};

}
