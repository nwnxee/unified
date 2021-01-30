#pragma once

#include "nwnx.hpp"

namespace Events {

class CombatEvents
{
public:
    CombatEvents();

private:
    static void StartCombatRoundHook(CNWSCombatRound*, ObjectID);
    static int32_t ApplyDisarmHook(CNWSEffectListHandler*, CNWSObject *, CGameEffect *, BOOL);
    static int32_t SendServerToPlayerAmbientBattleMusicPlayHook(CNWSMessage*, PlayerID oidPlayer, BOOL bPlay);
};

}
