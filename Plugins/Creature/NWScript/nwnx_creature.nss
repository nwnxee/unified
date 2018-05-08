#include "nwnx"

const int NWNX_CREATURE_MOVEMENT_RATE_PC        = 0;
const int NWNX_CREATURE_MOVEMENT_RATE_IMMOBILE  = 1;
const int NWNX_CREATURE_MOVEMENT_RATE_VERY_SLOW = 2;
const int NWNX_CREATURE_MOVEMENT_RATE_SLOW      = 3;
const int NWNX_CREATURE_MOVEMENT_RATE_NORMAL    = 4;
const int NWNX_CREATURE_MOVEMENT_RATE_FAST      = 5;
const int NWNX_CREATURE_MOVEMENT_RATE_VERY_FAST = 6;
const int NWNX_CREATURE_MOVEMENT_RATE_DEFAULT   = 7;
const int NWNX_CREATURE_MOVEMENT_RATE_DM_FAST   = 8;

const int NWNX_CREATURE_MOVEMENT_TYPE_STATIONARY      = 0;
const int NWNX_CREATURE_MOVEMENT_TYPE_WALK            = 1;
const int NWNX_CREATURE_MOVEMENT_TYPE_RUN             = 2;
const int NWNX_CREATURE_MOVEMENT_TYPE_SIDESTEP        = 3;
const int NWNX_CREATURE_MOVEMENT_TYPE_WALK_BACKWARDS  = 4;

const int NWNX_CREATURE_CLERIC_DOMAIN_AIR         = 0;
const int NWNX_CREATURE_CLERIC_DOMAIN_ANIMAL      = 1;
const int NWNX_CREATURE_CLERIC_DOMAIN_DEATH       = 3;
const int NWNX_CREATURE_CLERIC_DOMAIN_DESTRUCTION = 4;
const int NWNX_CREATURE_CLERIC_DOMAIN_EARTH       = 5;
const int NWNX_CREATURE_CLERIC_DOMAIN_EVIL        = 6;
const int NWNX_CREATURE_CLERIC_DOMAIN_FIRE        = 7;
const int NWNX_CREATURE_CLERIC_DOMAIN_GOOD        = 8;
const int NWNX_CREATURE_CLERIC_DOMAIN_HEALING     = 9;
const int NWNX_CREATURE_CLERIC_DOMAIN_KNOWLEDGE   = 10;
const int NWNX_CREATURE_CLERIC_DOMAIN_MAGIC       = 13;
const int NWNX_CREATURE_CLERIC_DOMAIN_PLANT       = 14;
const int NWNX_CREATURE_CLERIC_DOMAIN_PROTECTION  = 15;
const int NWNX_CREATURE_CLERIC_DOMAIN_STRENGTH    = 16;
const int NWNX_CREATURE_CLERIC_DOMAIN_SUN         = 17;
const int NWNX_CREATURE_CLERIC_DOMAIN_TRAVEL      = 18;
const int NWNX_CREATURE_CLERIC_DOMAIN_TRICKERY    = 19;
const int NWNX_CREATURE_CLERIC_DOMAIN_WAR         = 20;
const int NWNX_CREATURE_CLERIC_DOMAIN_WATER       = 21;

struct NWNX_Creature_SpecialAbility
{
    int id;
    int ready;
    int level;
};

struct NWNX_Creature_MemorisedSpell
{
    int id;
    int ready;
    int meta;
    int domain;
};

// Gives the provided creature the provided feat.
void NWNX_Creature_AddFeat(object creature, int feat);

// Gives the provided creature the provided feat.
// Adds the feat to the stat list at the provided level.
void NWNX_Creature_AddFeatByLevel(object creature, int feat, int level);

// Removes from the provided creature the provided feat.
void NWNX_Creature_RemoveFeat(object creature, int feat);

int NWNX_Creature_GetKnowsFeat(object creature, int feat);

// Returns the count of feats learned at the provided level.
int NWNX_Creature_GetFeatCountByLevel(object creature, int level);

// Returns the feat learned at the provided level at the provided index.
// Index bounds: 0 <= index < NWNX_Creature_GetFeatCountByLevel(creature, level).
int NWNX_Creature_GetFeatByLevel(object creature, int level, int index);

// Returns the total number of feats known by creature
int NWNX_Creature_GetFeatCount(object creature);

// Returns the creature's feat at a given index
// Index bounds: 0 <= index < NWNX_Creature_GetFeatCount(creature);
int NWNX_Creature_GetFeatByIndex(object creature, int index);

// Returns TRUE if creature meets all requirements to take given feat
int NWNX_Creature_GetMeetsFeatRequirements(object creature, int feat);

// Returns the special ability of the provided creature at the provided index.
// Index bounds: 0 <= index < NWNX_Creature_GetSpecialAbilityCount(creature).
struct NWNX_Creature_SpecialAbility NWNX_Creature_GetSpecialAbility(object creature, int index);

// Returns the count of special ability count of the provided creature.
int NWNX_Creature_GetSpecialAbilityCount(object creature);

// Adds the provided special ability to the provided creature.
void NWNX_Creature_AddSpecialAbility(object creature, struct NWNX_Creature_SpecialAbility ability);

// Removes the provided special ability from the provided creature.
// Index bounds: 0 <= index < NWNX_Creature_GetSpecialAbilityCount(creature).
void NWNX_Creature_RemoveSpecialAbility(object creature, int index);

// Sets the special ability at the provided index for the provided creature to the provided ability.
// Index bounds: 0 <= index < NWNX_Creature_GetSpecialAbilityCount(creature).
void NWNX_Creature_SetSpecialAbility(object creature, int index, struct NWNX_Creature_SpecialAbility ability);

// Returns the class taken by the provided creature at the provided level.
int NWNX_Creature_GetClassByLevel(object creature, int level);

// Sets the base AC for the provided creature.
void NWNX_Creature_SetBaseAC(object creature, int ac);

// Returns the base AC for the provided creature.
int NWNX_Creature_GetBaseAC(object creature);

// DEPRECATED. Please use NWNX_Creature_SetRawAbilityScore now. This will be removed in future NWNX releases.
// Sets the provided ability score of provided creature to the provided value.
void NWNX_Creature_SetAbilityScore(object creature, int ability, int value);

// Sets the provided ability score of provided creature to the provided value. Does not apply racial bonuses/penalties.
void NWNX_Creature_SetRawAbilityScore(object creature, int ability, int value);

// Gets the provided ability score of provided creature. Does not apply racial bonuses/penalties.
int NWNX_Creature_GetRawAbilityScore(object creature, int ability);

// Adjusts the provided ability score of a provided creature. Does not apply racial bonuses/penalties.
void NWNX_Creature_ModifyRawAbilityScore(object creature, int ability, int modifier);

// Gets the memorised spell of the provided creature for the provided class, level, and index.
// Index bounds: 0 <= index < NWNX_Creature_GetMemorisedSpellCountByLevel(creature, class, level).
struct NWNX_Creature_MemorisedSpell NWNX_Creature_GetMemorisedSpell(object creature, int class, int level, int index);

// Gets the count of memorised spells of the provided class and level belonging to the provided creature.
int NWNX_Creature_GetMemorisedSpellCountByLevel(object creature, int class, int level);

// Sets the memorised spell of the provided creature for the provided class, level, and index.
// Index bounds: 0 <= index < NWNX_Creature_GetMemorisedSpellCountByLevel(creature, class, level).
void NWNX_Creature_SetMemorisedSpell(object creature, int class, int level, int index, struct NWNX_Creature_MemorisedSpell spell);

// Gets the remaining spell slots (innate casting) for the provided creature for the provided class and level.
int NWNX_Creature_GetRemainingSpellSlots(object creature, int class, int level);

// Sets the remaining spell slots (innate casting) for the provided creature for the provided class and level.
void NWNX_Creature_SetRemainingSpellSlots(object creature, int class, int level, int slots);

// Gets the maximum count of spell slots for the proivded creature for the provided class and level.
int NWNX_Creature_GetMaxSpellSlots(object creature, int class, int level);

// Get the spell at index in level in creature's spellbook from class.
int NWNX_Creature_GetKnownSpell(object creature, int class, int level, int index);

int NWNX_Creature_GetKnownSpellCount(object creature, int class, int level);

// Remove a spell from creature's spellbook for class.
void NWNX_Creature_RemoveKnownSpell(object creature, int class, int level, int spellId);

// Add a new spell to creature's spellbook for class.
void NWNX_Creature_AddKnownSpell(object creature, int class, int level, int spellId);

// Clear a specific spell from the creature's spellbook for class
void NWNX_Creature_ClearMemorisedKnownSpells(object creature, int class, int spellId);

// Clear the memorised spell of the provided creature for the provided class, level and index. */
// Index bounds: 0 <= index < NWNX_Creature_GetMemorisedSpellCountByLevel(creature, class, level).
void NWNX_Creature_ClearMemorisedSpell(object creature, int class, int level, int index);

// Gets the maximum hit points for creature for level.
int NWNX_Creature_GetMaxHitPointsByLevel(object creature, int level);

// Sets the maximum hit points for creature for level to nValue.
void NWNX_Creature_SetMaxHitPointsByLevel(object creature, int level, int value);

// Set creature's movement rate.
void NWNX_Creature_SetMovementRate(object creature, int rate);

// Set creature's raw good/evil alignment value.
void NWNX_Creature_SetAlignmentGoodEvil(object creature, int value);

// Set creature's raw law/chaos alignment value.
void NWNX_Creature_SetAlignmentLawChaos(object creature, int value);

// Gets one of creature's cleric domains (either 1 or 2).
int NWNX_Creature_GetClericDomain(object creature, int index);

// Sets one of creature's cleric domains (either 1 or 2).
void NWNX_Creature_SetClericDomain(object creature, int index, int domain);

// Gets whether or not creature has a specialist school of wizardry.
int NWNX_Creature_GetWizardSpecialization(object creature);

// Sets creature's wizard specialist school.
void NWNX_Creature_SetWizardSpecialization(object creature, int school);

// Get the soundset index for creature.
int NWNX_Creature_GetSoundset(object creature);

// Set the soundset index for creature.
void NWNX_Creature_SetSoundset(object creature, int soundset);

// Set the base ranks in a skill for creature
void NWNX_Creature_SetSkillRank(object creature, int skill, int rank);

// Set the class ID in a particular position for a creature.
// Position should be 0, 1, or 2.
// ClassID should be a valid ID number in classes.2da and be between 0 and 255.
void NWNX_Creature_SetClassByPosition(object creature, int position, int classID);

// Set creature's base attack bonus (BAB)
// Modifying the BAB will also affect the creature's attacks per round and its
// eligability for feats, prestige classes, etc.
// The BAB value should be between 0 and 254.
// Setting BAB to 0 will cause the creature to revert to its original BAB based
// on its classes and levels. A creature can never have an actual BAB of zero.
// NOTE: The base game has a function SetBaseAttackBonus(), which actually sets
//       the bonus attacks per round for a creature, not the BAB.
void NWNX_Creature_SetBaseAttackBonus(object creature, int bab);

// Gets the creatures current attacks per round (using equipped weapon)
// bBaseAPR - If true, will return the base attacks per round, based on BAB and
//            equipped weapons, regardless of overrides set by
//            calls to SetBaseAttackBonus() builtin function.
int NWNX_Creature_GetAttacksPerRound(object creature, int bBaseAPR = FALSE);

// Sets the creature gender
void NWNX_Creature_SetGender(object creature, int gender);

// Restore all creature feat uses
void NWNX_Creature_RestoreFeats(object creature);

// Restore all creature special ability uses
void NWNX_Creature_RestoreSpecialAbilities(object creature);

// Restore all creature spells per day for given level.
// If level is -1, all spells are restored
void NWNX_Creature_RestoreSpells(object creature, int level = -1);

// Restore uses for all items carried by the creature
void NWNX_Creature_RestoreItems(object creature);

// Sets the creature size. Use CREATURE_SIZE_* constants
void NWNX_Creature_SetSize(object creature, int size);

// Gets the creature's remaining unspent skill points
int NWNX_Creature_GetSkillPointsRemaining(object creature);

// Sets the creature's remaining unspent skill points
void NWNX_Creature_SetSkillPointsRemaining(object creature, int skillpoints);

// Sets the creature's racial type 
void NWNX_Creature_SetRacialType(object creature, int racialtype);

// Returns the creature's current movement type (NWNX_CREATURE_MOVEMENT_TYPE_*)
int NWNX_Creature_GetMovementType(object creature);

// Sets the maximum movement rate a creature can have while walking (not running)
// This allows a creature with movement speed enhancemens to walk at a normal rate.
// Setting the value to -1.0 will remove the cap.
// Default value is 2000.0, which is the base human walk speed.
void NWNX_Creature_SetWalkRateCap(object creature, float fWalkRate = 2000.0f);

// Sets the creature's gold without sending a feedback message
void NWNX_Creature_SetGold(object creature, int gold);

// Sets corpse decay time in milliseconds
void NWNX_Creature_SetCorpseDecayTime(object creature, int nDecayTime);

// Returns the creature's base save and any modifiers set in the toolset
int NWNX_Creature_GetBaseSavingThrow(object creature, int which);

// Sets the base saving throw of the creature
void NWNX_Creature_SetBaseSavingThrow(object creature, int which, int value);

const string NWNX_Creature = "NWNX_Creature";


void NWNX_Creature_AddFeat(object creature, int feat)
{
    string sFunc = "AddFeat";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, feat);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_AddFeatByLevel(object creature, int feat, int level)
{
    string sFunc = "AddFeatByLevel";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, feat);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RemoveFeat(object creature, int feat)
{
    string sFunc = "RemoveFeat";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, feat);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetKnowsFeat(object creature, int feat)
{
    string sFunc = "GetKnowsFeat";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, feat);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetFeatCountByLevel(object creature, int level)
{
    string sFunc = "GetFeatCountByLevel";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetFeatByLevel(object creature, int level, int index)
{
    string sFunc = "GetFeatByLevel";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetFeatCount(object creature)
{
    string sFunc = "GetFeatCount";

    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetFeatByIndex(object creature, int index)
{
    string sFunc = "GetFeatByIndex";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetMeetsFeatRequirements(object creature, int feat)
{
    string sFunc = "GetMeetsFeatRequirements";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, feat);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

struct NWNX_Creature_SpecialAbility NWNX_Creature_GetSpecialAbility(object creature, int index)
{
    string sFunc = "GetSpecialAbility";

    struct NWNX_Creature_SpecialAbility ability;

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);

    ability.level  = NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
    ability.ready  = NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
    ability.id     = NWNX_GetReturnValueInt(NWNX_Creature, sFunc);

    return ability;
}

int NWNX_Creature_GetSpecialAbilityCount(object creature)
{
    string sFunc = "GetSpecialAbilityCount";

    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_AddSpecialAbility(object creature, struct NWNX_Creature_SpecialAbility ability)
{
    string sFunc = "AddSpecialAbility";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ability.id);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ability.ready);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ability.level);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RemoveSpecialAbility(object creature, int index)
{
    string sFunc = "RemoveSpecialAbility";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetSpecialAbility(object creature, int index, struct NWNX_Creature_SpecialAbility ability)
{
    string sFunc = "SetSpecialAbility";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ability.id);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ability.ready);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ability.level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetClassByLevel(object creature, int level)
{
    string sFunc = "GetClassByLevel";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetBaseAC(object creature, int ac)
{
    string sFunc = "SetBaseAC";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ac);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetBaseAC(object creature)
{
    string sFunc = "GetBaseAC";

    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetAbilityScore(object creature, int ability, int value)
{
    WriteTimestampedLogEntry("NWNX_Creature: SetAbilityScore() is deprecated. Use native NWNX_Creature_SetRawAbilityScore() instead");
    NWNX_Creature_SetRawAbilityScore(creature, ability, value);
}

void NWNX_Creature_SetRawAbilityScore(object creature, int ability, int value)
{
    string sFunc = "SetRawAbilityScore";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, value);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ability);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetRawAbilityScore(object creature, int ability)
{
    string sFunc = "GetRawAbilityScore";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ability);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_ModifyRawAbilityScore(object creature, int ability, int modifier)
{
    string sFunc = "ModifyRawAbilityScore";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, modifier);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, ability);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

struct NWNX_Creature_MemorisedSpell NWNX_Creature_GetMemorisedSpell(object creature, int class, int level, int index)
{
    string sFunc = "GetMemorisedSpell";
    struct NWNX_Creature_MemorisedSpell spell;

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);

    spell.domain = NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
    spell.meta   = NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
    spell.ready  = NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
    spell.id     = NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
    return spell;
}

int NWNX_Creature_GetMemorisedSpellCountByLevel(object creature, int class, int level)
{
    string sFunc = "GetMemorisedSpellCountByLevel";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetMemorisedSpell(object creature, int class, int level, int index, struct NWNX_Creature_MemorisedSpell spell)
{
    string sFunc = "SetMemorisedSpell";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, spell.id);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, spell.ready);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, spell.meta);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, spell.domain);

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetRemainingSpellSlots(object creature, int class, int level)
{
    string sFunc = "GetRemainingSpellSlots";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetRemainingSpellSlots(object creature, int class, int level, int slots)
{
    string sFunc = "SetRemainingSpellSlots";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, slots);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetKnownSpell(object creature, int class, int level, int index)
{
    string sFunc = "GetKnownSpell";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetKnownSpellCount(object creature, int class, int level)
{
    string sFunc = "GetKnownSpellCount";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_RemoveKnownSpell(object creature, int class, int level, int spellId)
{
    string sFunc = "RemoveKnownSpell";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, spellId);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_AddKnownSpell(object creature, int class, int level, int spellId)
{
    string sFunc = "AddKnownSpell";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, spellId);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_ClearMemorisedKnownSpells(object creature, int class, int spellId)
{
    string sFunc = "ClearMemorisedKnownSpells";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, spellId);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_ClearMemorisedSpell(object creature, int class, int level, int index)
{
    string sFunc = "ClearMemorisedSpell";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetMaxSpellSlots(object creature, int class, int level)
{
    string sFunc = "GetMaxSpellSlots";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, class);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}


int NWNX_Creature_GetMaxHitPointsByLevel(object creature, int level)
{
    string sFunc = "GetMaxHitPointsByLevel";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetMaxHitPointsByLevel(object creature, int level, int value)
{
    string sFunc = "SetMaxHitPointsByLevel";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, value);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetMovementRate(object creature, int rate)
{
    string sFunc = "SetMovementRate";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, rate);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}
void NWNX_Creature_SetAlignmentGoodEvil(object creature, int value)
{
    string sFunc = "SetAlignmentGoodEvil";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, value);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetAlignmentLawChaos(object creature, int value)
{
    string sFunc = "SetAlignmentLawChaos";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, value);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetClericDomain(object creature, int index)
{
    string sFunc = "GetClericDomain";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetClericDomain(object creature, int index, int domain)
{
    string sFunc = "SetClericDomain";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, domain);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}            

int NWNX_Creature_GetWizardSpecialization(object creature)
{
    string sFunc = "GetWizardSpecialization";

    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetWizardSpecialization(object creature, int school)
{
    string sFunc = "SetWizardSpecialization";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, school);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetSoundset(object creature)
{
    string sFunc = "GetSoundset";

    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetSoundset(object creature, int soundset)
{
    string sFunc = "SetSoundset";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, soundset);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetSkillRank(object creature, int skill, int rank)
{
    string sFunc = "SetSkillRank";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, rank);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, skill);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetClassByPosition(object creature, int position, int classID)
{
    string sFunc = "SetClassByPosition";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, classID);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, position);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetBaseAttackBonus(object creature, int bab)
{
    string sFunc = "SetBaseAttackBonus";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, bab);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetAttacksPerRound(object creature, int bBaseAPR = FALSE)
{
    string sFunc = "GetAttacksPerRound";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, bBaseAPR);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetGender(object creature, int gender)
{
    string sFunc = "SetGender";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, gender);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RestoreFeats(object creature)
{
    string sFunc = "RestoreFeats";
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RestoreSpecialAbilities(object creature)
{
    string sFunc = "RestoreSpecialAbilities";
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RestoreSpells(object creature, int level = -1)
{
    string sFunc = "RestoreSpells";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, level);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RestoreItems(object creature)
{
    string sFunc = "RestoreItems";
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetSize(object creature, int size)
{
    string sFunc = "SetSize";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, size);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetSkillPointsRemaining(object creature)
{
    string sFunc = "GetSkillPointsRemaining";
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}


void NWNX_Creature_SetSkillPointsRemaining(object creature, int skillpoints)
{
    string sFunc = "SetSkillPointsRemaining";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, skillpoints);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetRacialType(object creature, int racialtype)
{
    string sFunc = "SetRacialType";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, racialtype);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetMovementType(object creature)
{
    string sFunc = "GetMovementType";
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetWalkRateCap(object creature, float fWalkRate = 2000.0f)
{
    string sFunc = "SetWalkRateCap";
    NWNX_PushArgumentFloat(NWNX_Creature, sFunc, fWalkRate);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetGold(object creature, int gold)
{
    string sFunc = "SetGold";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, gold);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetCorpseDecayTime(object creature, int nDecayTime)
{
    string sFunc = "SetCorpseDecayTime";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, nDecayTime);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}


int NWNX_Creature_GetBaseSavingThrow(object creature, int which)
{
    string sFunc = "GetBaseSavingThrow";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, which);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetBaseSavingThrow(object creature, int which, int value)
{
    string sFunc = "SetBaseSavingThrow";
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, value);
    NWNX_PushArgumentInt(NWNX_Creature, sFunc, which);
    NWNX_PushArgumentObject(NWNX_Creature, sFunc, creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}
