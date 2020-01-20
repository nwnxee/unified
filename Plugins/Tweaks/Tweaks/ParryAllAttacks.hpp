#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class ParryAllAttacks
{
public:
    ParryAllAttacks(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CNWSCreature__ResolveAttackRoll_hook(CNWSCreature*, CNWSObject*);
    static NWNXLib::Hooking::FunctionHook* pResolveAttackRoll_hook;
};

}
