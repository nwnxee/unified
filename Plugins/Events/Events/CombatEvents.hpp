
#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class CombatEvents
{
public:
    CombatEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void StartCombatRoundHook
    (
        NWNXLib::Services::Hooks::CallType, 
        NWNXLib::API::CNWSCombatRound*,
        uint32_t
    );
    static NWNXLib::ViewPtr<NWNXLib::Hooking::FunctionHook> m_hook;
};

}
