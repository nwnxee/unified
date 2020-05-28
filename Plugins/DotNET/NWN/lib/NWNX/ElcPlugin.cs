namespace NWNX
{
    [NWNXPlugin(NWNX_ELC)]
    public class ElcPlugin
    {
        public const string NWNX_ELC = "NWNX_ELC";

        // /< @private
        // / @anchor elc_fail_type
        // / @name ELC Failure Types
        // / @{
        public const int NWNX_ELC_VALIDATION_FAILURE_TYPE_NONE = 0;
        public const int NWNX_ELC_VALIDATION_FAILURE_TYPE_CHARACTER = 1;
        public const int NWNX_ELC_VALIDATION_FAILURE_TYPE_ITEM = 2;
        public const int NWNX_ELC_VALIDATION_FAILURE_TYPE_SKILL = 3;
        public const int NWNX_ELC_VALIDATION_FAILURE_TYPE_FEAT = 4;
        public const int NWNX_ELC_VALIDATION_FAILURE_TYPE_SPELL = 5;
        public const int NWNX_ELC_VALIDATION_FAILURE_TYPE_CUSTOM = 6;

        // / @}
        // / @anchor elc_fail_subtype
        // / @name ELC Failure Subtypes
        // / @note By default these constants are commented out to avoid a
        // / limitation on constants. Uncomment them as needed.
        // / @{
        public const int NWNX_ELC_SUBTYPE_NONE = 0;

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
        // / @}
        // / @brief Sets the script that runs whenever an ELC validation failure happens
        // / @param sScript The script name.
        public static void SetELCScript(string sScript)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "SetELCScript");
            NWN.Internal.NativeFunctions.nwnxPushString(sScript);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Enables a custom ELC Check that will call the ELC Script with the
        // / NWNX_ELC_VALIDATION_FAILURE_TYPE_CUSTOM type.
        // / @param bEnabled TRUE to use this check.
        // / @note Only runs if you have an ELC script set, be sure to skip this check
        // / if a player doesn't fail your custom check otherwise they won't be able to log in
        public static void EnableCustomELCCheck(int bEnabled)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "EnableCustomELCCheck");
            NWN.Internal.NativeFunctions.nwnxPushInt(bEnabled);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Skip an ELC Validation Failure Event
        // / @note Only to be called in the ELC Script
        public static void SkipValidationFailure()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "SkipValidationFailure");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the validation failure type
        // / @return A @ref elc_fail_type "Validation Failure Type"
        // / @note Only to be called in the ELC Script
        public static int GetValidationFailureType()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "GetValidationFailureType");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the validation failure subtype
        // / @return A @ref elc_fail_subtype "Validation Failure Subtype"
        // / @note Only to be called in the ELC Script
        public static int GetValidationFailureSubType()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "GetValidationFailureSubType");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the failure message
        // / @return The talk table strref the player receives.
        // / @note Only to be called in the ELC Script
        public static int GetValidationFailureMessageStrRef()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "GetValidationFailureMessageStrRef");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the failure message
        // / @param nStrRef The talk table strref the player receives, must be > 0.
        // / @note Only to be called in the ELC Script
        public static void SetValidationFailureMessageStrRef(int nStrRef)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "SetValidationFailureMessageStrRef");
            NWN.Internal.NativeFunctions.nwnxPushInt(nStrRef);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the item that failed ILR validation
        // / @return The object that caused the ILR validation failure. Returns OBJECT_INVALID on error.
        // / @note Only to be called in the ELC Script during a
        // / NWNX_ELC_VALIDATION_FAILURE_TYPE_ITEM validation failure.
        public static uint GetValidationFailureItem()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "GetValidationFailureItem");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopObject();
        }

        // / @brief Get the character level at which the validation failure occurred
        // / @return The character level or -1 on error.
        // / @remark May not always return a level, depending on where the failure occurred.
        // / @note Only to be called in the ELC Script
        public static int GetValidationFailureLevel()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "GetValidationFailureLevel");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the ID of the skill that failed ELC validation
        // / @return The skill ID or -1 on error.
        // / @remark May not always return a skill id, depending on the validation failure subtype.
        // / @note Only to be called in the ELC Script during a
        // / NWNX_ELC_VALIDATION_FAILURE_TYPE_SKILL validation failure.
        public static int GetValidationFailureSkillID()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "GetValidationFailureSkillID");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the ID of the feat that failed ELC validation
        // / @return The feat ID or -1 on error
        // / @remark May not always return a feat id, depending on the validation failure subtype.
        // / @note Only to be called in the ELC Script during a
        // / NWNX_ELC_VALIDATION_FAILURE_TYPE_FEAT validation failure.
        public static int GetValidationFailureFeatID()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "GetValidationFailureFeatID");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the ID of the spell that failed ELC validation
        // / @return The spell ID or -1 on error
        // / @remark May not always return a spell id, depending on the validation failure subtype.
        // / @note Only to be called in the ELC Script during a
        // / NWNX_ELC_VALIDATION_FAILURE_TYPE_SPELL validation failure.
        public static int GetValidationFailureSpellID()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_ELC, "GetValidationFailureSpellID");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @}
    }
}
