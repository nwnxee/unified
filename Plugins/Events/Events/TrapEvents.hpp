#pragma once

#include "nwnx.hpp"

namespace Events {

class TrapEvents
{
public:
    TrapEvents();

private:
    static uint32_t HandleTrapHook(const std::string&, NWNXLib::Hooks::FunctionHook* originalTrapHook, CNWSCreature *pCreature, CNWSObjectActionNode *pNode);
    static uint32_t AIActionDisarmTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode);
    static uint32_t AIActionExamineTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode);
    static uint32_t AIActionFlagTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode);
    static uint32_t AIActionRecoverTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode);
    static uint32_t AIActionSetTrapHook(CNWSCreature *pCreature, CNWSObjectActionNode *pNode);
    static void OnEnterTrapHook(CNWSTrigger *pTrigger, int32_t bForceSet);

};

}
