/// @addtogroup race Race
/// @brief Define racial and subrace characteristics.
/// @{
/// @file nwnx_race.nss
#include "nwnx"

const string NWNX_Race = "NWNX_Race"; ///< @private

/// @name Racial Modifiers
/// @anchor racial_modifiers
///
/// @{
const int NWNX_RACE_MODIFIER_INVALID       = 0;
const int NWNX_RACE_MODIFIER_AB            = 1;
const int NWNX_RACE_MODIFIER_ABVSRACE      = 2;
const int NWNX_RACE_MODIFIER_AC            = 3;
const int NWNX_RACE_MODIFIER_ACVSRACE      = 4;
const int NWNX_RACE_MODIFIER_CONCEALMENT   = 5;
const int NWNX_RACE_MODIFIER_DMGIMMUNITY   = 6;
const int NWNX_RACE_MODIFIER_DMGREDUCTION  = 7;
const int NWNX_RACE_MODIFIER_DMGRESIST     = 8;
const int NWNX_RACE_MODIFIER_FEAT          = 9;
const int NWNX_RACE_MODIFIER_FEATUSAGE     = 10;
const int NWNX_RACE_MODIFIER_IMMUNITY      = 11;
const int NWNX_RACE_MODIFIER_INITIATIVE    = 12;
const int NWNX_RACE_MODIFIER_MOVEMENTSPEED = 13;
const int NWNX_RACE_MODIFIER_RACE          = 14;
const int NWNX_RACE_MODIFIER_REGENERATION  = 15;
const int NWNX_RACE_MODIFIER_SAVE          = 16;
const int NWNX_RACE_MODIFIER_SAVEVSRACE    = 17;
const int NWNX_RACE_MODIFIER_SAVEVSTYPE    = 18;
const int NWNX_RACE_MODIFIER_SKILL         = 19;
const int NWNX_RACE_MODIFIER_SPELLIMMUNITY = 20;
const int NWNX_RACE_MODIFIER_SRCHARGEN     = 21;
const int NWNX_RACE_MODIFIER_SRINCLEVEL    = 22;
///@}

/// @brief Sets a racial modifier.
/// @param iRace The RACIALTYPE_ constant or value in racialtypes.2da.
/// @param iMod The @ref racial_modifiers "racial modifier" to set.
/// @param iParam1, iParam2, iParam3 The parameters for this racial modifier.
void NWNX_Race_SetRacialModifier(int iRace, int iMod, int iParam1, int iParam2 = 0xDEADBEEF, int iParam3 = 0xDEADBEEF);

/// @brief Gets the parent race for a race.
/// @param iRace The race to check for a parent.
/// @return The parent race if applicable, if not it just returns the race passed in.
int NWNX_Race_GetParentRace(int iRace);

/// @brief Associates the race with its favored enemy feat.
/// @param iRace The race
/// @param iFeat The feat
/// @note If a creature has a race that has a parent race then favored enemy bonuses will work for either race against that creature.
/// For example a creature is a Wild Elf which has a parent race of Elf, an attacker would benefit if they had either Favored Enemy: Elf
/// or Favored Enemy: Wild Elf
void NWNX_Race_SetFavoredEnemyFeat(int iRace, int iFeat);

/// @brief Removes any nwnx_race 'Effects' on the targeted creature. Suppression lasts until levelup, next login, or Reactivated by function.
/// @param oCreature The creature to suppress
/// @note Not all nwnx_race modifiers are achieved via effect. Those that are not directly consider the creatures current race.
void NWNX_Race_SuppressCreatureRaceEffects(object oCreature);

/// @brief Reactivates the nwnx_race 'Effects' on the targeted creature after they were Suppressed.
/// @param oCreature The creature to reactive
/// @note Safe to use on non-suppressed creatures - Triggers a refresh of effects but won't stack.
void NWNX_Race_ReactivateCreatureRaceEffects(object oCreature);

/// @}

void NWNX_Race_SetRacialModifier(int iRace, int iMod, int iParam1, int iParam2 = 0xDEADBEEF, int iParam3 = 0xDEADBEEF)
{
    string sFunc = "SetRacialModifier";

    NWNX_PushArgumentInt(iParam3);
    NWNX_PushArgumentInt(iParam2);
    NWNX_PushArgumentInt(iParam1);
    NWNX_PushArgumentInt(iMod);
    NWNX_PushArgumentInt(iRace);

    NWNX_CallFunction(NWNX_Race, sFunc);
}

int NWNX_Race_GetParentRace(int iRace)
{
    string sFunc = "GetParentRace";

    NWNX_PushArgumentInt(iRace);

    NWNX_CallFunction(NWNX_Race, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Race_SetFavoredEnemyFeat(int iRace, int iFeat)
{
    string sFunc = "SetFavoredEnemyFeat";

    NWNX_PushArgumentInt(iFeat);
    NWNX_PushArgumentInt(iRace);

    NWNX_CallFunction(NWNX_Race, sFunc);
}

void NWNX_Race_SuppressCreatureRaceEffects(object creature)
{
    string sFunc = "SuppressCreatureRaceEffects";

    NWNX_PushArgumentObject(creature);
    NWNX_CallFunction(NWNX_Race, sFunc);
}

void NWNX_Race_ReactivateCreatureRaceEffects(object oCreature)
{
    string sFunc = "ReactivateCreatureRaceEffects";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Race, sFunc);
}
