#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class ParryAllAttacks
{
public:
    ParryAllAttacks(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void CNWSCreature__ResolveAttackRoll_hook(CNWSCreature*, CNWSObject*);
    static NWNXLib::Hooking::FunctionHook* pResolveAttackRoll_hook;
};

}
