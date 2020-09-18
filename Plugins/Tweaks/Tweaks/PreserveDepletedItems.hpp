#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class PreserveDepletedItems
{
public:
    PreserveDepletedItems(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CNWSCreature__AIActionItemCastSpell_hook(bool, CNWSCreature*, CNWSObjectActionNode*);
};

}
