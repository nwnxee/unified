#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class SneakAttackCritImmunity
{
public:
    SneakAttackCritImmunity();

private:
    static void CNWSCreature__ResolveSneakAttack_hook(CNWSCreature*, CNWSCreature*);
    static void CNWSCreature__ResolveDeathAttack_hook(CNWSCreature*, CNWSCreature*);
};

}
