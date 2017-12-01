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

// Sets the provided ability of provided creature's to the provided value.
void NWNX_Creature_SetAbilityScore(object creature, int ability, int value);

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
    string sFunc = "SetAbilityScore";

    NWNX_PushArgumentInt(NWNX_Creature, sFunc, value);
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
