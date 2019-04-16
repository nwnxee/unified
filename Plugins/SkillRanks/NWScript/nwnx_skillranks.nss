#include "nwnx"

const string NWNX_SkillRanks = "NWNX_SkillRanks";

const int NWNX_SKILLRANKS_KEY_ABILITY_STRENGTH = 1;
const int NWNX_SKILLRANKS_KEY_ABILITY_DEXTERITY = 2;
const int NWNX_SKILLRANKS_KEY_ABILITY_CONSTITUTION = 4;
const int NWNX_SKILLRANKS_KEY_ABILITY_INTELLIGENCE = 8;
const int NWNX_SKILLRANKS_KEY_ABILITY_WISDOM = 16;
const int NWNX_SKILLRANKS_KEY_ABILITY_CHARISMA = 32;
// Use only one! If you use more than one the first will be used
const int NWNX_SKILLRANKS_KEY_ABILITY_CALC_MIN = 64;
const int NWNX_SKILLRANKS_KEY_ABILITY_CALC_MAX = 128;
const int NWNX_SKILLRANKS_KEY_ABILITY_CALC_AVERAGE = 256;
const int NWNX_SKILLRANKS_KEY_ABILITY_CALC_SUM = 512;

struct NWNX_SkillRanks_SkillFeat
{
    int iSkill;
    int iFeat;

    // Skill feat bonus/penalty
    int iModifier;

    // 1 for Focus, 2 for Epic Focus. This can be set on a feat so NWNX_SkillRanks_SetFocusMod
    // can mass change the modifier for the Skill Focus and Epic Skill Focus feats
    int iFocusFeat;

    // 255 char bitset string for skill ranks impacted by class levels (like Bardic Knowledge)
    // The right most bit is barbarian (class 0), second from right is bard (class 1) etc.
    // It's not necessary to pass in the entire string, for example Ranger is class 7 and Fighter is 4
    // If you wanted those class levels to impact the skill modifier you could set sClasses equal to
    // "10010000". From right to left = Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger
    // You can alternatively use NWNX_SkillRanks_SetSkillFeatClass for each class
    // If unset but fClassLevelMod is set, then all classes will be included
    string sClasses;

    // Levels in class multiplier gives you skill modifier, for example 0.5f would mean 1 point for
    // every two class levels. If sClasses is not set and this is then all class levels will be modified
    float fClassLevelMod;

    // Used for feats like Stonecunning or Trackless Step which restrict skill modifiers by area types
    int iAreaFlagsRequired;
    int iAreaFlagsForbidden;

    // 1 for Day, 2 for Night - if skill modifiers only take effect based on the day/night cycle or an area
    // that's set to always night. 0 is all hours
    int iDayOrNight;

    // This allows for feats that bypass the armor check penalty on skill rank calculations
    int bBypassArmorCheckPenalty;

    // Bitmask of abilities and method to calculate the ability modifier for a skill
    // Example "Doctor" Feat that used INT instead of WIS (if higher) for Heal skill would set to:
    // NWNX_SKILLRANKS_KEY_ABILITY_INTELLIGENCE | NWNX_SKILLRANKS_KEY_ABILITY_WISDOM | NWNX_SKILLRANKS_KEY_ABILITY_CALC_MAX;
    int iKeyAbilityMask;
};

// Returns the count of feats for a specific skill
int NWNX_SkillRanks_GetSkillFeatCountForSkill(int iSkill);

// Returns a skill feat
struct NWNX_SkillRanks_SkillFeat NWNX_SkillRanks_GetSkillFeat(int iSkill, int iFeat);

// Returns a skill feat by index
struct NWNX_SkillRanks_SkillFeat NWNX_SkillRanks_GetSkillFeatForSkillByIndex(int iSkill, int iIndex);

// Sets the values for an existing or creates a new skill feat
void NWNX_SkillRanks_SetSkillFeat(struct NWNX_SkillRanks_SkillFeat skillFeat, int createIfNonExistent = FALSE);

// Convenience function to add classes to a skill feat instead of working with the sClasses string.
struct NWNX_SkillRanks_SkillFeat NWNX_SkillRanks_AddSkillFeatClass(struct NWNX_SkillRanks_SkillFeat skillFeat, int iClass);

// The stock modifier on skill focus and epic skill focus are 3 and 10 respectively, these can be
// changed with this function.
void NWNX_SkillRanks_SetSkillFeatFocusMod(int iModifier, int iEpic = FALSE);

// Gets the current penalty to Dexterity based skills when blind
int NWNX_SkillRanks_GetBlindnessPenalty();

// Can change the value the Dexterity based skills get decreased due to blindness, default is 4
void NWNX_SkillRanks_SetBlindnessPenalty(int iModifier);

// Returns any skill modifier for the area
int NWNX_SkillRanks_GetAreaModifier(object oArea, int iSkill);

// Sets the skill modifier for the area
void NWNX_SkillRanks_SetAreaModifier(object oArea, int iSkill, int iModifier);


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
