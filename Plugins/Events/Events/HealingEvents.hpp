#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class HealingEvents
{
public:
    HealingEvents();

private:
    static uint32_t AIActionHealHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode);
    static int32_t OnApplyHealHook(CNWSEffectListHandler *pThis, CNWSObject *pObject, CGameEffect *pGameEffect, int32_t bLoadingGame);

};

}
