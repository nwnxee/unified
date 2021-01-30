#pragma once

#include "nwnx.hpp"

class CNWSObjectActionNode;

namespace Tweaks {

class FixUnlimitedPotionsBug
{
public:
    FixUnlimitedPotionsBug();

private:
    static uint32_t CNWSCreature__AIActionItemCastSpell_hook(CNWSCreature*, CNWSObjectActionNode*);
    static int32_t CServerAIMaster__AddEventDeltaTime(CServerAIMaster*, uint32_t, uint32_t, ObjectID, ObjectID, uint32_t, void*);
};

}
