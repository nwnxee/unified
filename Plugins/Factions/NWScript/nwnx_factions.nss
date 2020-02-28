/// @addtogroup factions Factions
/// @brief Functions exposing additional faction properties.
/// @{
/// @file nwnx_factions.nss
#include "nwnx"

const string NWNX_Factions = "NWNX_Factions"; ///< @private

/// @brief Gets the faction id from oCreature
/// @param oCreature the creature we wish to query against
/// @return faction id as an integer, -1 when used against invalid creature or invalid object.
int NWNX_Factions_GetFaction(object oCreature);

/// @brief Sets oCreatures faction to be the faction with id nFactionId.
/// @param oCreature The creature.
/// @param nFactionId The faction id we want the creature to join.
/// @return 1 on success, -1 on any error - Eg: No Creature, Invalid Creature, Invalid Faction etc.
int NWNX_Factions_SetFaction(object oCreature, int nFactionId);


/// @}



int NWNX_Factions_GetFaction(object oCreature)
{
    string sFunc = "GetFaction";
    NWNX_PushArgumentObject(NWNX_Factions, sFunc, oItem);
    NWNX_CallFunction(NWNX_Factions, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Factions, sFunc);
}

int NWNX_Factions_SetFaction(object oCreature, int nFactionId)
{
    string sFunc = "SetFaction";
    NWNX_PushArgumentInt(NWNX_Factions, sFunc, nFactionId);
    NWNX_PushArgumentObject(NWNX_Factions, sFunc, oItem);
    NWNX_CallFunction(NWNX_Factions, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Factions, sFunc);
}
