/// @ingroup race
/// @file nwnx_race_2da.nss
/// @brief Parse a column in the racialtypes.2da to load the modifiers.
#include "nwnx_race"
#include "nwnx_util"

/// @ingroup race
/// @brief Translate a modifier type from a string to its constant.
/// @param raceMod The string representation of the constant.
/// @return The constant for the race modifier.
int NWNX_Race_GetModifierConstant(string raceMod);

/// @ingroup race
/// @brief Loops through racialtypes.2da and checks for the column for racial modifications and sets them.
/// @note Requires NWNX_Util_Get2DARowCount()
/// @param sColumnName The column name in the racialtypes.2da that defines the 2da for the racial mods.
void NWNX_Race_LoadRacialModifiers(string sColumnName = "RacialModsTable");

int NWNX_Race_GetModifierConstant(string raceMod)
{
    if (raceMod == "AB")                 return NWNX_RACE_MODIFIER_AB;
    else if (raceMod == "ABVSRACE")      return NWNX_RACE_MODIFIER_ABVSRACE;
    else if (raceMod == "AC")            return NWNX_RACE_MODIFIER_AC;
    else if (raceMod == "ACVSRACE")      return NWNX_RACE_MODIFIER_ACVSRACE;
    else if (raceMod == "CONCEALMENT")   return NWNX_RACE_MODIFIER_CONCEALMENT;
    else if (raceMod == "DMGIMMUNITY")   return NWNX_RACE_MODIFIER_DMGIMMUNITY;
    else if (raceMod == "DMGREDUCTION")  return NWNX_RACE_MODIFIER_DMGREDUCTION;
    else if (raceMod == "DMGRESIST")     return NWNX_RACE_MODIFIER_DMGRESIST;
    else if (raceMod == "FEAT")          return NWNX_RACE_MODIFIER_FEAT;
    else if (raceMod == "FEATUSAGE")     return NWNX_RACE_MODIFIER_FEATUSAGE;
    else if (raceMod == "IMMUNITY")      return NWNX_RACE_MODIFIER_IMMUNITY;
    else if (raceMod == "INITIATIVE")    return NWNX_RACE_MODIFIER_INITIATIVE;
    else if (raceMod == "MOVEMENTSPEED") return NWNX_RACE_MODIFIER_MOVEMENTSPEED;
    else if (raceMod == "RACE")          return NWNX_RACE_MODIFIER_RACE;
    else if (raceMod == "REGENERATION")  return NWNX_RACE_MODIFIER_REGENERATION;
    else if (raceMod == "SAVE")          return NWNX_RACE_MODIFIER_SAVE;
    else if (raceMod == "SAVEVSRACE")    return NWNX_RACE_MODIFIER_SAVEVSRACE;
    else if (raceMod == "SAVEVSTYPE")    return NWNX_RACE_MODIFIER_SAVEVSTYPE;
    else if (raceMod == "SKILL")         return NWNX_RACE_MODIFIER_SKILL;
    else if (raceMod == "SPELLIMMUNITY") return NWNX_RACE_MODIFIER_SPELLIMMUNITY;
    else if (raceMod == "SRCHARGEN")     return NWNX_RACE_MODIFIER_SRCHARGEN;
    else if (raceMod == "SRINCLEVEL")    return NWNX_RACE_MODIFIER_SRINCLEVEL;
    return NWNX_RACE_MODIFIER_INVALID;
}

void NWNX_Race_LoadRacialModifiers(string sColumnName = "RacialModsTable")
{
    int iRaceRows = NWNX_Util_Get2DARowCount("racialtypes");
    int iRace;
    for (iRace = 0; iRace < iRaceRows; iRace++)
    {
        string sRaceModTable = Get2DAString("racialtypes", sColumnName, iRace);
        if(sRaceModTable != "")
        {
            int iRaceModRows = NWNX_Util_Get2DARowCount(sRaceModTable);
            int iRaceMod;
            for (iRaceMod = 0; iRaceMod < iRaceModRows; iRaceMod++)
            {
                string sType = Get2DAString(sRaceModTable, "Type", iRaceMod);
                string sParam1 = Get2DAString(sRaceModTable, "Param1", iRaceMod);
                string sParam2 = Get2DAString(sRaceModTable, "Param2", iRaceMod);
                string sParam3 = Get2DAString(sRaceModTable, "Param3", iRaceMod);
                int iParam1 = sParam1 == "" ? 0xDEADBEEF : StringToInt(sParam1);
                int iParam2 = sParam2 == "" ? 0xDEADBEEF : StringToInt(sParam2);
                int iParam3 = sParam3 == "" ? 0xDEADBEEF : StringToInt(sParam3);
                NWNX_Race_SetRacialModifier(iRace, NWNX_Race_GetModifierConstant(sType), iParam1, iParam2, iParam3);
            }
        }
    }
}
