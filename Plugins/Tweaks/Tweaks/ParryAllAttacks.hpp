#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class ParryAllAttacks
{
public:
    ParryAllAttacks();

private:
    static void CNWSCreature__ResolveAttackRoll_hook(CNWSCreature*, CNWSObject*);
};

}
