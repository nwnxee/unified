#pragma once

#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class TrapEvents
{
public:
    TrapEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static uint32_t HandleTrapHook(const std::string&, NWNXLib::Hooking::FunctionHook* originalTrapHook, NWNXLib::API::CNWSCreature *pCreature, NWNXLib::API::CNWSObjectActionNode *pNode);
    static uint32_t AIActionDisarmTrapHook(NWNXLib::API::CNWSCreature *pCreature, NWNXLib::API::CNWSObjectActionNode *pNode);
    static uint32_t AIActionExamineTrapHook(NWNXLib::API::CNWSCreature *pCreature, NWNXLib::API::CNWSObjectActionNode *pNode);
    static uint32_t AIActionFlagTrapHook(NWNXLib::API::CNWSCreature *pCreature, NWNXLib::API::CNWSObjectActionNode *pNode);
    static uint32_t AIActionRecoverTrapHook(NWNXLib::API::CNWSCreature *pCreature, NWNXLib::API::CNWSObjectActionNode *pNode);
    static uint32_t AIActionSetTrapHook(NWNXLib::API::CNWSCreature *pCreature, NWNXLib::API::CNWSObjectActionNode *pNode);

};

}
