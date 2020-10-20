
#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class CombatEvents
{
public:
    CombatEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void StartCombatRoundHook(bool, CNWSCombatRound*, uint32_t);
    static int32_t ApplyDisarmHook(CNWSEffectListHandler*, CNWSObject *, CGameEffect *, BOOL);
};

}
