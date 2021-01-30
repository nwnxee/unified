#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class PreserveDepletedItems
{
public:
    PreserveDepletedItems(NWNXLib::Services::HooksProxy* hooker);

private:
    static uint32_t CNWSCreature__AIActionItemCastSpell_hook(CNWSCreature*, CNWSObjectActionNode*);
};

}
