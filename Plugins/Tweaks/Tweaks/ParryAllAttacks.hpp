#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class ParryAllAttacks
{
public:
    ParryAllAttacks(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CNWSCreature__ResolveAttackRoll_hook(CNWSCreature*, CNWSObject*);
};

}
