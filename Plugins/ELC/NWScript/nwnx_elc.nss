#include "nwnx"

const string NWNX_ELC = "NWNX_ELC";

const int NWNX_ELC_VALIDATION_FAILURE_TYPE_NONE                     = 0;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_CHARACTER                = 1;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_ITEM                     = 2;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_SKILL                    = 3;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_FEAT                     = 4;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_SPELL                    = 5;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_CUSTOM                   = 6;

/*
const int NWNX_ELC_SUBTYPE_NONE                                     = 0;
const int NWNX_ELC_SUBTYPE_SERVER_LEVEL_RESTRICTION                 = 1;
const int NWNX_ELC_SUBTYPE_LEVEL_HACK                               = 2;
const int NWNX_ELC_SUBTYPE_COLORED_NAME                             = 3;
const int NWNX_ELC_SUBTYPE_UNIDENTIFIED_EQUIPPED_ITEM               = 4;
const int NWNX_ELC_SUBTYPE_MIN_EQUIP_LEVEL                          = 5;
const int NWNX_ELC_SUBTYPE_NON_PC_CHARACTER                         = 6;
const int NWNX_ELC_SUBTYPE_DM_CHARACTER                             = 7;
const int NWNX_ELC_SUBTYPE_NON_PLAYER_RACE                          = 8;
const int NWNX_ELC_SUBTYPE_NON_PLAYER_CLASS                         = 9;
const int NWNX_ELC_SUBTYPE_CLASS_LEVEL_RESTRICTION                  = 10;
const int NWNX_ELC_SUBTYPE_PRESTIGE_CLASS_REQUIREMENTS              = 11;
const int NWNX_ELC_SUBTYPE_CLASS_ALIGNMENT_RESTRICTION              = 12;
const int NWNX_ELC_SUBTYPE_STARTING_ABILITY_VALUE_MAX               = 13;
const int NWNX_ELC_SUBTYPE_ABILITY_POINT_BUY_SYSTEM_CALCULATION     = 14;
const int NWNX_ELC_SUBTYPE_CLASS_SPELLCASTER_INVALID_PRIMARY_STAT   = 15;
const int NWNX_ELC_SUBTYPE_EPIC_LEVEL_FLAG                          = 16;
const int NWNX_ELC_SUBTYPE_TOO_MANY_HITPOINTS                       = 17;
const int NWNX_ELC_SUBTYPE_UNUSABLE_SKILL                           = 18;
const int NWNX_ELC_SUBTYPE_NOT_ENOUGH_SKILLPOINTS                   = 19;
const int NWNX_ELC_SUBTYPE_INVALID_NUM_RANKS_IN_CLASS_SKILL         = 20;
const int NWNX_ELC_SUBTYPE_INVALID_NUM_RANKS_IN_NON_CLASS_SKILL     = 21;
const int NWNX_ELC_SUBTYPE_INVALID_NUM_REMAINING_SKILL_POINTS       = 22;
const int NWNX_ELC_SUBTYPE_INVALID_FEAT                             = 23;
const int NWNX_ELC_SUBTYPE_FEAT_REQUIRED_SPELL_LEVEL_NOT_MET        = 24;
const int NWNX_ELC_SUBTYPE_FEAT_REQUIRED_BASE_ATTACK_BONUS_NOT_MET  = 25;
const int NWNX_ELC_SUBTYPE_FEAT_REQUIRED_ABILITY_VALUE_NOT_MET      = 26;
const int NWNX_ELC_SUBTYPE_FEAT_REQUIRED_SKILL_NOT_MET              = 27;
const int NWNX_ELC_SUBTYPE_FEAT_REQUIRED_FEAT_NOT_MET               = 28;
const int NWNX_ELC_SUBTYPE_TOO_MANY_FEATS_THIS_LEVEL                = 29;
const int NWNX_ELC_SUBTYPE_FEAT_NOT_AVAILABLE_TO_CLASS              = 30;
const int NWNX_ELC_SUBTYPE_FEAT_IS_NORMAL_FEAT_ONLY                 = 31;
const int NWNX_ELC_SUBTYPE_FEAT_IS_BONUS_FEAT_ONLY                  = 32;
const int NWNX_ELC_SUBTYPE_SPELL_INVALID_SPELL_GAIN_WIZARD          = 33;
const int NWNX_ELC_SUBTYPE_SPELL_INVALID_SPELL_GAIN_BARD_SORCERER   = 34;
const int NWNX_ELC_SUBTYPE_SPELL_INVALID_SPELL_GAIN_OTHER_CLASSES   = 35;
const int NWNX_ELC_SUBTYPE_INVALID_SPELL                            = 36;
const int NWNX_ELC_SUBTYPE_SPELL_INVALID_SPELL_LEVEL                = 37;
const int NWNX_ELC_SUBTYPE_SPELL_MINIMUM_ABILITY_BARD_SORCERER      = 38;
const int NWNX_ELC_SUBTYPE_SPELL_MINIMUM_ABILITY_WIZARD             = 39;
const int NWNX_ELC_SUBTYPE_SPELL_MINIMUM_ABILITY_OTHER_CLASSES      = 40;
const int NWNX_ELC_SUBTYPE_SPELL_RESTRICTED_SPELL_SCHOOL            = 41;
const int NWNX_ELC_SUBTYPE_SPELL_ALREADY_KNOWN                      = 42;
const int NWNX_ELC_SUBTYPE_SPELL_WIZARD_EXCEEDS_NUMSPELLS_TO_ADD    = 43;
const int NWNX_ELC_SUBTYPE_ILLEGAL_REMOVED_SPELL                    = 44;
const int NWNX_ELC_SUBTYPE_REMOVED_NOT_KNOWN_SPELL                  = 45;
const int NWNX_ELC_SUBTYPE_INVALID_NUM_SPELLS                       = 46;
const int NWNX_ELC_SUBTYPE_SPELL_LIST_COMPARISON                    = 47;
const int NWNX_ELC_SUBTYPE_SKILL_LIST_COMPARISON                    = 48;
const int NWNX_ELC_SUBTYPE_FEAT_LIST_COMPARISON                     = 49;
const int NWNX_ELC_SUBTYPE_MISC_SAVING_THROW                        = 50;
const int NWNX_ELC_SUBTYPE_NUM_FEAT_COMPARISON                      = 51;
*/

// Sets the script that runs whenever a ELC validation failure happens
void NWNX_ELC_SetELCScript(string sScript);

// Enables a custom ELC Check that will call the ELC Script with the
// NWNX_ELC_VALIDATION_FAILURE_TYPE_CUSTOM type.
//
// NOTE: Only runs if you have an ELC script set, be sure to skip this check if a player doesn't fail your custom check
//       otherwise they won't be able to log in
void NWNX_ELC_EnableCustomELCCheck(int bEnabled);

// Skip an ELC Validation Failure Event
// This will allow a character to bypass an ELC failure
//
// NOTE: Only to be called in the ELC Script
void NWNX_ELC_SkipValidationFailure();

// Get the validation failure type
// Returns NWNX_ELC_VALIDATION_FAILURE_TYPE_*
//
// NOTE: Only to be called in the ELC Script
int NWNX_ELC_GetValidationFailureType();

// Get the validation failure subtype
// Returns NWNX_ELC_VALIDATION_FAILURE_SUBTYPE_*
//
// NOTE: Only to be called in the ELC Script
int NWNX_ELC_GetValidationFailureSubType();

// Get the failure message talk table strref the player receives
//
// NOTE: Only to be called in the ELC Script
int NWNX_ELC_GetValidationFailureMessageStrRef();

// Set the failure message talk table strref the player receives
// nStrRef: a talk table entry, must be >0
//
// NOTE: Only to be called in the ELC Script
void NWNX_ELC_SetValidationFailureMessageStrRef(int nStrRef);

// Get the item that failed ILR validation
// Returns OBJECT_INVALID on error
//
// NOTE: Only to be called in the ELC Script during a
// NWNX_ELC_VALIDATION_FAILURE_TYPE_ITEM validation failure.
object NWNX_ELC_GetValidationFailureItem();

// Get the character level at which the validation failure occurred
// Returns -1 on error
// May not always return a level, depending on where the failure occurred
//
// NOTE: Only to be called in the ELC Script
int NWNX_ELC_GetValidationFailureLevel();

// Get the ID of the skill that failed ELC validation
// Returns -1 on error
// May not always return a skill id, depending on the validation failure subtype
//
// NOTE: Only to be called in the ELC Script during a
// NWNX_ELC_VALIDATION_FAILURE_TYPE_SKILL validation failure.
int NWNX_ELC_GetValidationFailureSkillID();

// Get the ID of the feat that failed ELC validation
// Returns -1 on error
// May not always return a feat id, depending on the validation failure subtype
//
// NOTE: Only to be called in the ELC Script during a
// NWNX_ELC_VALIDATION_FAILURE_TYPE_FEAT validation failure.
int NWNX_ELC_GetValidationFailureFeatID();

// Get the ID of the spell that failed ELC validation
// Returns -1 on error
// May not always return a spell id, depending on the validation failure subtype
//
// NOTE: Only to be called in the ELC Script during a
// NWNX_ELC_VALIDATION_FAILURE_TYPE_SPELL validation failure.
int NWNX_ELC_GetValidationFailureSpellID();


void NWNX_ELC_SetELCScript(string sScript)
{
    string sFunc = "SetELCScript";

    NWNX_PushArgumentString(NWNX_ELC, sFunc, sScript);
    NWNX_CallFunction(NWNX_ELC, sFunc);
}

void NWNX_ELC_EnableCustomELCCheck(int bEnabled)
{
    string sFunc = "EnableCustomELCCheck";

    NWNX_PushArgumentInt(NWNX_ELC, sFunc, bEnabled);
    NWNX_CallFunction(NWNX_ELC, sFunc);
}

void NWNX_ELC_SkipValidationFailure()
{
    string sFunc = "SkipValidationFailure";

    NWNX_CallFunction(NWNX_ELC, sFunc);
}

int NWNX_ELC_GetValidationFailureType()
{
    string sFunc = "GetValidationFailureType";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ELC, sFunc);
}

int NWNX_ELC_GetValidationFailureSubType()
{
    string sFunc = "GetValidationFailureSubType";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ELC, sFunc);
}

int NWNX_ELC_GetValidationFailureMessageStrRef()
{
    string sFunc = "GetValidationFailureMessageStrRef";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ELC, sFunc);
}

void NWNX_ELC_SetValidationFailureMessageStrRef(int nStrRef)
{
    string sFunc = "SetValidationFailureMessageStrRef";

    NWNX_PushArgumentInt(NWNX_ELC, sFunc, nStrRef);
    NWNX_CallFunction(NWNX_ELC, sFunc);
}

object NWNX_ELC_GetValidationFailureItem()
{
    string sFunc = "GetValidationFailureItem";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueObject(NWNX_ELC, sFunc);
}

int NWNX_ELC_GetValidationFailureLevel()
{
    string sFunc = "GetValidationFailureLevel";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ELC, sFunc);
}

int NWNX_ELC_GetValidationFailureSkillID()
{
    string sFunc = "GetValidationFailureSkillID";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ELC, sFunc);
}

int NWNX_ELC_GetValidationFailureFeatID()
{
    string sFunc = "GetValidationFailureFeatID";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ELC, sFunc);
}

int NWNX_ELC_GetValidationFailureSpellID()
{
    string sFunc = "GetValidationFailureSpellID";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt(NWNX_ELC, sFunc);
}
