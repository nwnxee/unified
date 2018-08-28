#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class SneakAttackCritImmunity
{
public:
    SneakAttackCritImmunity(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void CNWSCreature__ResolveSneakAttack_hook(NWNXLib::API::CNWSCreature*, NWNXLib::API::CNWSCreature*);
    static NWNXLib::Hooking::FunctionHook* pResolveSneakAttack_hook;
};

}
