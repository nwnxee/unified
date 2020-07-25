#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class HealerKitEvents
{
public:
    HealerKitEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static uint32_t AIActionHealHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode);

};

}
