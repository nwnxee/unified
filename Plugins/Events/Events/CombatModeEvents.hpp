#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class CombatModeEvents
{
public:
    CombatModeEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void SetCombatModeHook(NWNXLib::API::CNWSCreature*, uint8_t, int32_t);
};

}