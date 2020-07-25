#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

class CNWSObjectActionNode;

namespace Tweaks {

class UnhardcodeShieldAC
{
public:
    UnhardcodeShieldAC(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CNWSItem__ComputeArmorClass(CNWSItem* thisPtr);
};

}
