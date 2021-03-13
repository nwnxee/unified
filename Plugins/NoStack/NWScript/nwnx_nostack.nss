/// @addtogroup nostack NoStack
/// @brief Functions to allow more control over ability/skill/bonuses stacking.
/// @{
/// @file nwnx_nostack.nss
#include "nwnx"

const string NWNX_Creature = "NWNX_NoStack"; ///< @private

/// @name Spell Effect Bonus Types
/// @anchor spell_bonus_types
///
/// Used with NWNX_Creature_SetSpellBonusType() these are the effect bonus types.
/// @{
const int NWNX_CREATURE_EFFECT_TYPE_ENHANCEMENT  = 0;
const int NWNX_CREATURE_EFFECT_TYPE_CIRCUMSTANCE = 1;
const int NWNX_CREATURE_EFFECT_TYPE_COMPETENCE   = 2;
const int NWNX_CREATURE_EFFECT_TYPE_INSIGHT      = 3;
const int NWNX_CREATURE_EFFECT_TYPE_LUCK         = 4;
const int NWNX_CREATURE_EFFECT_TYPE_MORALE       = 5;
const int NWNX_CREATURE_EFFECT_TYPE_PROFANE      = 6;
const int NWNX_CREATURE_EFFECT_TYPE_RESISTANCE   = 7;
const int NWNX_CREATURE_EFFECT_TYPE_SACRED       = 8;
/// @}

/// @brief Sets a spell bonus type to be used by the NoStack feature.
/// @param spell The spell ID from spells.2da.
/// @param type The new type.
void NWNX_Creature_SetSpellBonusType(int spell, int type);

/// @}

void NWNX_Creature_SetSpellBonusType(int spell, int type)
{
    string sFunc = "SetSpellBonusType";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, type);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, spell);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}
