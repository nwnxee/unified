/// @addtogroup elc ELC
/// @brief Replacement for ValidateCharacter: ELC & ILR
/// @{
/// @file nwnx_elc.nss
#include "nwnx"

const string NWNX_ELC = "NWNX_ELC"; ///< @private


/// @anchor elc_fail_type
/// @name ELC Failure Types
/// @{
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_NONE                     = 0;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_CHARACTER                = 1;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_ITEM                     = 2;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_SKILL                    = 3;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_FEAT                     = 4;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_SPELL                    = 5;
const int NWNX_ELC_VALIDATION_FAILURE_TYPE_CUSTOM                   = 6;
/// @}

/// @anchor elc_fail_subtype
/// @name ELC Failure Subtypes
/// @note By default these constants are commented out to avoid a
/// limitation on constants. Uncomment them as needed.
/// @{
const int NWNX_ELC_SUBTYPE_NONE                                     = 0;
/*
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
const int NWNX_ELC_SUBTYPE_SPELL_MINIMUM_ABILITY                    = 40;
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
/// @}

/// @brief Sets the script that runs whenever an ELC validation failure happens
/// @param sScript The script name.
void NWNX_ELC_SetELCScript(string sScript);

/// @brief Enables a custom ELC Check that will call the ELC Script with the
/// NWNX_ELC_VALIDATION_FAILURE_TYPE_CUSTOM type.
/// @param bEnabled TRUE to use this check.
/// @note Only runs if you have an ELC script set, be sure to skip this check
/// if a player doesn't fail your custom check otherwise they won't be able to log in
void NWNX_ELC_EnableCustomELCCheck(int bEnabled);

/// @brief Skip an ELC Validation Failure Event
/// @note Only to be called in the ELC Script
void NWNX_ELC_SkipValidationFailure();

/// @brief Get the validation failure type
/// @return A @ref elc_fail_type "Validation Failure Type"
/// @note Only to be called in the ELC Script
int NWNX_ELC_GetValidationFailureType();

/// @brief Get the validation failure subtype
/// @return A @ref elc_fail_subtype "Validation Failure Subtype"
/// @note Only to be called in the ELC Script
int NWNX_ELC_GetValidationFailureSubType();

/// @brief Get the failure message
/// @return The talk table strref the player receives.
/// @note Only to be called in the ELC Script
int NWNX_ELC_GetValidationFailureMessageStrRef();

/// @brief Set the failure message
/// @param nStrRef The talk table strref the player receives, must be > 0.
/// @note Only to be called in the ELC Script
void NWNX_ELC_SetValidationFailureMessageStrRef(int nStrRef);

/// @brief Get the item that failed ILR validation
/// @return The object that caused the ILR validation failure. Returns OBJECT_INVALID on error.
/// @note Only to be called in the ELC Script during a
/// NWNX_ELC_VALIDATION_FAILURE_TYPE_ITEM validation failure.
object NWNX_ELC_GetValidationFailureItem();

/// @brief Get the character level at which the validation failure occurred
/// @return The character level or -1 on error.
/// @remark May not always return a level, depending on where the failure occurred.
/// @note Only to be called in the ELC Script
int NWNX_ELC_GetValidationFailureLevel();

/// @brief Get the ID of the skill that failed ELC validation
/// @return The skill ID or -1 on error.
/// @remark May not always return a skill id, depending on the validation failure subtype.
/// @note Only to be called in the ELC Script during a
/// NWNX_ELC_VALIDATION_FAILURE_TYPE_SKILL validation failure.
int NWNX_ELC_GetValidationFailureSkillID();

/// @brief Get the ID of the feat that failed ELC validation
/// @return The feat ID or -1 on error
/// @remark May not always return a feat id, depending on the validation failure subtype.
/// @note Only to be called in the ELC Script during a
/// NWNX_ELC_VALIDATION_FAILURE_TYPE_FEAT validation failure.
int NWNX_ELC_GetValidationFailureFeatID();

/// @brief Get the ID of the spell that failed ELC validation
/// @return The spell ID or -1 on error
/// @remark May not always return a spell id, depending on the validation failure subtype.
/// @note Only to be called in the ELC Script during a
/// NWNX_ELC_VALIDATION_FAILURE_TYPE_SPELL validation failure.
int NWNX_ELC_GetValidationFailureSpellID();

/// @}

void NWNX_ELC_SetELCScript(string sScript)
{
    string sFunc = "SetELCScript";

    NWNX_PushArgumentString(sScript);
    NWNX_CallFunction(NWNX_ELC, sFunc);
}

void NWNX_ELC_EnableCustomELCCheck(int bEnabled)
{
    string sFunc = "EnableCustomELCCheck";

    NWNX_PushArgumentInt(bEnabled);
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
    return NWNX_GetReturnValueInt();
}

int NWNX_ELC_GetValidationFailureSubType()
{
    string sFunc = "GetValidationFailureSubType";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_ELC_GetValidationFailureMessageStrRef()
{
    string sFunc = "GetValidationFailureMessageStrRef";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_ELC_SetValidationFailureMessageStrRef(int nStrRef)
{
    string sFunc = "SetValidationFailureMessageStrRef";

    NWNX_PushArgumentInt(nStrRef);
    NWNX_CallFunction(NWNX_ELC, sFunc);
}

object NWNX_ELC_GetValidationFailureItem()
{
    string sFunc = "GetValidationFailureItem";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueObject();
}

int NWNX_ELC_GetValidationFailureLevel()
{
    string sFunc = "GetValidationFailureLevel";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_ELC_GetValidationFailureSkillID()
{
    string sFunc = "GetValidationFailureSkillID";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_ELC_GetValidationFailureFeatID()
{
    string sFunc = "GetValidationFailureFeatID";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_ELC_GetValidationFailureSpellID()
{
    string sFunc = "GetValidationFailureSpellID";

    NWNX_CallFunction(NWNX_ELC, sFunc);
    return NWNX_GetReturnValueInt();
}
