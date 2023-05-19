/// @ingroup feat
/// @file nwnx_feat_2da.nss
/// @brief Parse a column in the feat.2da to load the modifiers.
#include "nwnx_feat"

/// @ingroup feat
/// @brief Translate a modifier type from a string to its constant.
/// @param featMod The string representation of the constant.
/// @return The constant for the feat modifier.
int NWNX_Feat_GetModifierConstant(string featMod);

/// @ingroup feat
/// @brief Loops through feat.2da and checks for the column for feat modifications and sets them.
/// @param sColumnName The column name in the feat.2da that defines the 2da for the feat mods.
void NWNX_Feat_LoadFeatModifiers(string sColumnName = "FeatModsTable");

int NWNX_Feat_GetModifierConstant(string featMod)
{
    if (featMod == "AB")                        return NWNX_FEAT_MODIFIER_AB;
    else if (featMod == "ABILITY")              return NWNX_FEAT_MODIFIER_ABILITY;
    else if (featMod == "ABVSRACE")             return NWNX_FEAT_MODIFIER_ABVSRACE;
    else if (featMod == "AC")                   return NWNX_FEAT_MODIFIER_AC;
    else if (featMod == "ACVSRACE")             return NWNX_FEAT_MODIFIER_ACVSRACE;
    else if (featMod == "ARCANESPELLFAILURE")   return NWNX_FEAT_MODIFIER_ARCANESPELLFAILURE;
    else if (featMod == "BONUSSPELL")           return NWNX_FEAT_MODIFIER_BONUSSPELL;
    else if (featMod == "CONCEALMENT")          return NWNX_FEAT_MODIFIER_CONCEALMENT;
    else if (featMod == "DMGREDUCTION")         return NWNX_FEAT_MODIFIER_DMGREDUCTION;
    else if (featMod == "DMGRESIST")            return NWNX_FEAT_MODIFIER_DMGRESIST;
    else if (featMod == "DMGIMMUNITY")          return NWNX_FEAT_MODIFIER_DMGIMMUNITY;
    else if (featMod == "IMMUNITY")             return NWNX_FEAT_MODIFIER_IMMUNITY;
    else if (featMod == "HASTE")                return NWNX_FEAT_MODIFIER_HASTE;
    else if (featMod == "MOVEMENTSPEED")        return NWNX_FEAT_MODIFIER_MOVEMENTSPEED;
    else if (featMod == "REGENERATION")         return NWNX_FEAT_MODIFIER_REGENERATION;
    else if (featMod == "SAVE")                 return NWNX_FEAT_MODIFIER_SAVE;
    else if (featMod == "SAVEVSRACE")           return NWNX_FEAT_MODIFIER_SAVEVSRACE;
    else if (featMod == "SAVEVSTYPE")           return NWNX_FEAT_MODIFIER_SAVEVSTYPE;
    else if (featMod == "SAVEVSTYPERACE")       return NWNX_FEAT_MODIFIER_SAVEVSTYPERACE;
    else if (featMod == "SEEINVISIBLE")         return NWNX_FEAT_MODIFIER_SEEINVISIBLE;
    else if (featMod == "SPELLIMMUNITY")        return NWNX_FEAT_MODIFIER_SPELLIMMUNITY;
    else if (featMod == "SRCHARGEN")            return NWNX_FEAT_MODIFIER_SRCHARGEN;
    else if (featMod == "SRINCLEVEL")           return NWNX_FEAT_MODIFIER_SRINCLEVEL;
    else if (featMod == "SPELLSAVEDC")          return NWNX_FEAT_MODIFIER_SPELLSAVEDC;
    else if (featMod == "TRUESEEING")           return NWNX_FEAT_MODIFIER_TRUESEEING;
    else if (featMod == "ULTRAVISION")          return NWNX_FEAT_MODIFIER_ULTRAVISION;
    else if (featMod == "VISUALEFFECT")         return NWNX_FEAT_MODIFIER_VISUALEFFECT;
    else if (featMod == "SPELLSAVEDCFORSCHOOL") return NWNX_FEAT_MODIFIER_SPELLSAVEDCFORSCHOOL;
    else if (featMod == "SPELLSAVEDCFORSPELL")  return NWNX_FEAT_MODIFIER_SPELLSAVEDCFORSPELL;
    
    return NWNX_FEAT_MODIFIER_INVALID;
}

void NWNX_Feat_LoadFeatModifiers(string sColumnName = "FeatModsTable")
{
    int iFeatRows = Get2DARowCount("feat");
    int iFeat;
    for (iFeat = 0; iFeat < iFeatRows; iFeat++)
    {
        string sFeatModTable = Get2DAString("feat", sColumnName, iFeat);
        if(sFeatModTable != "")
        {
            int iFeatModRows = Get2DARowCount(sFeatModTable);
            int iFeatMod;
            for (iFeatMod = 0; iFeatMod < iFeatModRows; iFeatMod++)
            {
                string sType = Get2DAString(sFeatModTable, "Type", iFeatMod);
                string sParam1 = Get2DAString(sFeatModTable, "Param1", iFeatMod);
                string sParam2 = Get2DAString(sFeatModTable, "Param2", iFeatMod);
                string sParam3 = Get2DAString(sFeatModTable, "Param3", iFeatMod);
                string sParam4 = Get2DAString(sFeatModTable, "Param4", iFeatMod);
                int iParam1 = sParam1 == "" ? 0xDEADBEEF : StringToInt(sParam1);
                int iParam2 = sParam2 == "" ? 0xDEADBEEF : StringToInt(sParam2);
                int iParam3 = sParam3 == "" ? 0xDEADBEEF : StringToInt(sParam3);
                int iParam4 = sParam4 == "" ? 0xDEADBEEF : StringToInt(sParam4);
                NWNX_Feat_SetFeatModifier(iFeat, NWNX_Feat_GetModifierConstant(sType), iParam1, iParam2, iParam3, iParam4);
            }
        }
    }
}