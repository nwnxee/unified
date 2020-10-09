#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class HealingEvents
{
public:
    HealingEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static uint32_t AIActionHealHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode);
    static int32_t OnApplyHealHook(CNWSEffectListHandler *pThis, CNWSObject *pObject, CGameEffect *pGameEffect, int32_t bLoadingGame);

};

}
