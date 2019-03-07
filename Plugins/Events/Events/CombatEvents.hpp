
#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"
#include "ViewPtr.hpp"

namespace Events {

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

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
    static void AttackHook
    (
        NWNXLib::Services::Hooks::CallType,
        NWNXLib::API::CNWSCombatRound*,
        uint8_t
    );
};

}
