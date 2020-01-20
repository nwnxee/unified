/// @addtogroup skillranks SkillRanks
/// @brief Enhances and allows for manipulation of skill rank calculations including the ability to build custom
/// skill related feats as well as modifying stock feats.
/// @{
/// @file nwnx_skillranks.nss
#include "nwnx"

const string NWNX_SkillRanks = "NWNX_SkillRanks"; ///< @private

/// @name SkillRanks Key Abilities
/// @anchor skr_key_abilities
///
/// The abilities as bits
/// @{
const int NWNX_SKILLRANKS_KEY_ABILITY_STRENGTH = 1; ///< Strength
const int NWNX_SKILLRANKS_KEY_ABILITY_DEXTERITY = 2; ///< Dexterity
const int NWNX_SKILLRANKS_KEY_ABILITY_CONSTITUTION = 4; ///< Constitution
const int NWNX_SKILLRANKS_KEY_ABILITY_INTELLIGENCE = 8; ///< Intelligence
const int NWNX_SKILLRANKS_KEY_ABILITY_WISDOM = 16; ///< Wisdom
const int NWNX_SKILLRANKS_KEY_ABILITY_CHARISMA = 32; ///< Charisma
///@}

/// @name SkillRanks Key Ability Calculation Method
/// @anchor skr_key_ability_calc_bits
///
/// Constants used to calculate the ability modifier for a skill.
/// @{
/// @warning Use only one of these calculations in your mask! If you use more than one the first will be used.
const int NWNX_SKILLRANKS_KEY_ABILITY_CALC_MIN = 64; ///< Use the minimum value of the provided ability scores.
const int NWNX_SKILLRANKS_KEY_ABILITY_CALC_MAX = 128; ///< Use the maximum value of the provided ability scores.
const int NWNX_SKILLRANKS_KEY_ABILITY_CALC_AVERAGE = 256; ///< Use the average value of the provided ability scores.
const int NWNX_SKILLRANKS_KEY_ABILITY_CALC_SUM = 512; ///< Use the sum of the provided ability scores.
///@}

/// @brief A feat that manipulates skill ranks.
struct NWNX_SkillRanks_SkillFeat
{
    int iSkill; ///< The skill this feat impacts
    int iFeat; ///< The feat

    /// Skill feat bonus/penalty
    int iModifier;

    /// 1 for Focus, 2 for Epic Focus. This can be set on a feat so NWNX_SkillRanks_SetFocusMod
    /// can mass change the modifier for the Skill Focus and Epic Skill Focus feats.
    int iFocusFeat;

    /// @brief 255 char bitset string for skill ranks impacted by class levels (like Bardic Knowledge).
    ///
    /// The right most bit is barbarian (class 0), second from right is bard (class 1) etc.
    /// It's not necessary to pass in the entire string, for example Ranger is class 7 and Fighter is 4
    /// If you wanted those class levels to impact the skill modifier you could set sClasses equal to
    /// "10010000". From right to left = Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger
    /// You can alternatively use NWNX_SkillRanks_AddSkillFeatClass() for each class
    /// @remark If unset but #fClassLevelMod is set, then all classes will be included.
    string sClasses;

    /// Levels in class multiplier gives you skill modifier, for example 0.5f would mean 1 point for
    /// every two class levels. If #sClasses is not set and this is set then all class levels will be modified.
    float fClassLevelMod;

    /// Used for feats like Stonecunning or Trackless Step which restrict skill modifiers by area types.
    int iAreaFlagsRequired;

    /// Used for feats like Stonecunning or Trackless Step which restrict skill modifiers by area types.
    int iAreaFlagsForbidden;

    /// 1 for Day, 2 for Night - if skill modifiers only take effect based on the day/night cycle or an area
    /// that's set to always night. 0 is all hours.
    int iDayOrNight;

    /// This allows for feats that bypass the armor check penalty on skill rank calculations.
    int bBypassArmorCheckPenalty;

    /// @brief Bitmask of @ref skr_key_abilities "abilities" and @ref skr_key_ability_calc_bits "method to calculate"
    /// the ability modifier for a skill.
    ///
    /// Example **Doctor** Feat that used INT instead of WIS (if higher) for Heal skill would set to:
    /// #NWNX_SKILLRANKS_KEY_ABILITY_INTELLIGENCE | #NWNX_SKILLRANKS_KEY_ABILITY_WISDOM | #NWNX_SKILLRANKS_KEY_ABILITY_CALC_MAX;
    int iKeyAbilityMask;
};

/// @param iSkill The skill to check the feat count.
/// @return The count of feats for a specific skill.
int NWNX_SkillRanks_GetSkillFeatCountForSkill(int iSkill);

/// @brief Returns a skill feat.
/// @param iSkill The skill.
/// @param iFeat The feat.
/// @return A constructed NWNX_SkillRanks_SkillFeat.
struct NWNX_SkillRanks_SkillFeat NWNX_SkillRanks_GetSkillFeat(int iSkill, int iFeat);

/// @brief Returns a skill feat by index.
/// @remark Generally used in a loop with NWNX_SkillRanks_GetSkillFeatCountForSkill().
/// @param iSkill The skill.
/// @param iIndex The index in the list of feats for the skill.
/// @return A constructed NWNX_SkillRanks_SkillFeat.
struct NWNX_SkillRanks_SkillFeat NWNX_SkillRanks_GetSkillFeatForSkillByIndex(int iSkill, int iIndex);

/// @brief Modifies or creates a skill feat.
/// @param skillFeat The defined NWNX_SkillRanks_SkillFeat.
/// @param createIfNonExistent TRUE to create if the feat does not exist.
void NWNX_SkillRanks_SetSkillFeat(struct NWNX_SkillRanks_SkillFeat skillFeat, int createIfNonExistent = FALSE);

/// @brief Add classes to a skill feat instead of working with the NWNX_SkillRanks_SkillFeat::sClasses string.
///
/// Manipulating the sClasses string in the NWNX_SkillRanks_SkillFeat struct can be difficult. This
/// function allows the builder to enter one class at a time.
/// @param skillFeat The NWNX_SkillRanks_SkillFeat for which the sClasses field will be modifier.
/// @param iClass The class to add to the Skill Feat.
/// @return The updated NWNX_SkillRanks_SkillFeat.
struct NWNX_SkillRanks_SkillFeat NWNX_SkillRanks_AddSkillFeatClass(struct NWNX_SkillRanks_SkillFeat skillFeat, int iClass);

/// @brief Change the modifier value for Skill Focus and Epic Skill Focus feats.
///
/// The stock modifier on Skill Focus and Epic Skill Focus are 3 and 10 respectively, these can be
/// changed with this function.
/// @param iModifier The new value for the feat modifier.
/// @param iEpic Set to TRUE to change the value for Epic Skill Focus.
void NWNX_SkillRanks_SetSkillFeatFocusModifier(int iModifier, int iEpic = FALSE);

/// @brief Gets the current penalty to Dexterity based skills when blind.
/// @return The penalty to Dexterity when blind.
int NWNX_SkillRanks_GetBlindnessPenalty();

/// @brief Set the value the Dexterity based skills get decreased due to blindness.
/// @remark Default is 4.
/// @param iModifier The penalty to Dexterity when blind.
void NWNX_SkillRanks_SetBlindnessPenalty(int iModifier);

/// @brief Get a skill modifier for an area.
/// @param oArea The area.
/// @param iSkill The skill to check.
/// @return The modifier to that skill in the area.
int NWNX_SkillRanks_GetAreaModifier(object oArea, int iSkill);

/// @brief Sets a skill modifier for the area.
/// @param oArea The area.
/// @param iSkill The skill to change.
/// @param iModifier The modifier to the skill in the area.
void NWNX_SkillRanks_SetAreaModifier(object oArea, int iSkill, int iModifier);

/// @}

int NWNX_SkillRanks_GetSkillFeatCountForSkill(int iSkill)
{
    string sFunc = "GetSkillFeatCountForSkill";

    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iSkill);
    NWNX_CallFunction(NWNX_SkillRanks, sFunc);

    return NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
}

struct NWNX_SkillRanks_SkillFeat NWNX_SkillRanks_GetSkillFeatForSkillByIndex(int iSkill, int iIndex)
{
    string sFunc = "GetSkillFeatForSkillByIndex";

    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iIndex);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iSkill);
    NWNX_CallFunction(NWNX_SkillRanks, sFunc);

    struct NWNX_SkillRanks_SkillFeat skillFeat;

    skillFeat.iSkill                   = iSkill;
    skillFeat.iFeat                    = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.iModifier                = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.iFocusFeat               = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.sClasses                 = NWNX_GetReturnValueString(NWNX_SkillRanks, sFunc);
    skillFeat.fClassLevelMod           = NWNX_GetReturnValueFloat(NWNX_SkillRanks, sFunc);
    skillFeat.iAreaFlagsRequired       = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.iAreaFlagsForbidden      = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.iDayOrNight              = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.bBypassArmorCheckPenalty = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.iKeyAbilityMask          = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);

    return skillFeat;
}

struct NWNX_SkillRanks_SkillFeat NWNX_SkillRanks_GetSkillFeat(int iSkill, int iFeat)
{
    string sFunc = "GetSkillFeat";

    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iFeat);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iSkill);
    NWNX_CallFunction(NWNX_SkillRanks, sFunc);

    struct NWNX_SkillRanks_SkillFeat skillFeat;

    skillFeat.iSkill                   = iSkill;
    skillFeat.iFeat                    = iFeat;
    skillFeat.iModifier                = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.iFocusFeat               = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.sClasses                 = NWNX_GetReturnValueString(NWNX_SkillRanks, sFunc);
    skillFeat.fClassLevelMod           = NWNX_GetReturnValueFloat(NWNX_SkillRanks, sFunc);
    skillFeat.iAreaFlagsRequired       = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.iAreaFlagsForbidden      = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.iDayOrNight              = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.bBypassArmorCheckPenalty = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
    skillFeat.iKeyAbilityMask          = NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);

    return skillFeat;
}

void NWNX_SkillRanks_SetSkillFeat(struct NWNX_SkillRanks_SkillFeat skillFeat, int createIfNonExistent = FALSE)
{
    string sFunc = "SetSkillFeat";

    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, createIfNonExistent);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, skillFeat.iKeyAbilityMask);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, skillFeat.bBypassArmorCheckPenalty);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, skillFeat.iDayOrNight);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, skillFeat.iAreaFlagsForbidden);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, skillFeat.iAreaFlagsRequired);
    NWNX_PushArgumentFloat(NWNX_SkillRanks, sFunc, skillFeat.fClassLevelMod);
    // We only need to send the string from the point of the first set bit
    NWNX_PushArgumentString(NWNX_SkillRanks, sFunc, GetStringRight(skillFeat.sClasses, GetStringLength(skillFeat.sClasses)-FindSubString(skillFeat.sClasses, "1")));
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, skillFeat.iFocusFeat);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, skillFeat.iModifier);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, skillFeat.iFeat);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, skillFeat.iSkill);
    NWNX_CallFunction(NWNX_SkillRanks, sFunc);
}

struct NWNX_SkillRanks_SkillFeat NWNX_SkillRanks_AddSkillFeatClass(struct NWNX_SkillRanks_SkillFeat skillFeat, int iClass)
{
    if (GetStringLength(skillFeat.sClasses) < 255)
    {
        int i;
        string sPad;
        for (i = 0; i < 255-GetStringLength(skillFeat.sClasses); i++) { sPad = sPad + "0"; }
        skillFeat.sClasses = sPad + skillFeat.sClasses;
    }
    skillFeat.sClasses = GetStringLeft(skillFeat.sClasses, 254 - iClass) + "1" + GetStringRight(skillFeat.sClasses, iClass);
    return skillFeat;
}

void NWNX_SkillRanks_SetSkillFeatFocusModifier(int iModifier, int epicFocus = FALSE)
{
    string sFunc = "SetSkillFeatFocusModifier";

    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, epicFocus);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iModifier);
    NWNX_CallFunction(NWNX_SkillRanks, sFunc);
}

int NWNX_SkillRanks_GetBlindnessPenalty()
{
    string sFunc = "GetBlindnessPenalty";

    NWNX_CallFunction(NWNX_SkillRanks, sFunc);

    return NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
}

void NWNX_SkillRanks_SetBlindnessPenalty(int iModifier)
{
    string sFunc = "SetBlindnessPenalty";

    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iModifier);
    NWNX_CallFunction(NWNX_SkillRanks, sFunc);
}

int NWNX_SkillRanks_GetAreaModifier(object oArea, int iSkill)
{
    string sFunc = "GetAreaModifier";

    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iSkill);
    NWNX_PushArgumentObject(NWNX_SkillRanks, sFunc, oArea);
    NWNX_CallFunction(NWNX_SkillRanks, sFunc);

    return NWNX_GetReturnValueInt(NWNX_SkillRanks, sFunc);
}

void NWNX_SkillRanks_SetAreaModifier(object oArea, int iSkill, int iModifier)
{
    string sFunc = "SetAreaModifier";

    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iModifier);
    NWNX_PushArgumentInt(NWNX_SkillRanks, sFunc, iSkill);
    NWNX_PushArgumentObject(NWNX_SkillRanks, sFunc, oArea);
    NWNX_CallFunction(NWNX_SkillRanks, sFunc);
}
