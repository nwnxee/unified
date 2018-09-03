#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class HealerKitEvents
{
public:
    HealerKitEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t AIActionHealHook(NWNXLib::API::CNWSCreature *pCreature, NWNXLib::API::CNWSObjectActionNode *pNode);

    NWNXLib::Hooking::FunctionHook* m_AIActionHealHook; 
};

}
