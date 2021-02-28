#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class SpellEvents
{
public:
    SpellEvents();

private:
    static void SpellCastAndImpactHook(CNWSObject*, uint32_t, Vector, ObjectID, uint8_t, ObjectID, int32_t, int32_t, uint8_t, int32_t);
    static int32_t SetMemorizedSpellSlotHook(CNWSCreatureStats*, uint8_t, uint8_t, uint32_t, uint8_t, uint8_t, int32_t);
    static void ClearMemorizedSpellSlotHook(CNWSCreatureStats*, uint8_t, uint8_t, uint8_t);
    static void BroadcastSpellCastHook(CNWSCreature*, uint32_t, uint8_t, uint16_t);
    static int32_t OnEffectAppliedHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
};

}
