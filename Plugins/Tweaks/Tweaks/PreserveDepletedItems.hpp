#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class PreserveDepletedItems
{
public:
    PreserveDepletedItems(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CNWSCreature__AIActionItemCastSpell_hook(bool, CNWSCreature*, CNWSObjectActionNode*);
};

}
