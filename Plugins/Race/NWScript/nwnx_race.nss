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

/// @}

void NWNX_Race_SetRacialModifier(int iRace, int iMod, int iParam1, int iParam2 = 0xDEADBEEF, int iParam3 = 0xDEADBEEF)
{
    string sFunc = "SetRacialModifier";

    NWNX_PushArgumentInt(NWNX_Race, sFunc, iParam3);
    NWNX_PushArgumentInt(NWNX_Race, sFunc, iParam2);
    NWNX_PushArgumentInt(NWNX_Race, sFunc, iParam1);
    NWNX_PushArgumentInt(NWNX_Race, sFunc, iMod);
    NWNX_PushArgumentInt(NWNX_Race, sFunc, iRace);

    NWNX_CallFunction(NWNX_Race, sFunc);
}

int NWNX_Race_GetParentRace(int iRace)
{
    string sFunc = "GetParentRace";

    NWNX_PushArgumentInt(NWNX_Race, sFunc, iRace);

    NWNX_CallFunction(NWNX_Race, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Race, sFunc);
}
