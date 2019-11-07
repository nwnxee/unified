#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class PreserveDepletedItems
{
public:
    PreserveDepletedItems(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static uint32_t CNWSCreature__AIActionItemCastSpell_hook(CNWSCreature*, CNWSObjectActionNode*);
    static NWNXLib::Hooking::FunctionHook* pAIActionItemCastSpell_hook;
};

}
