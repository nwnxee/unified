/// @addtogroup appearance Appearance
/// @brief Allows the appearance and some other things of creatures to be overridden per player.
/// @{
/// @file nwnx_appearance.nss
#include "nwnx"

const string NWNX_Factions = "NWNX_Factions"; ///< @private



/// @brief returns an integer representing the faction id used for a creatures faction affiliation.
/// @param oCreature The creature who's faction id we wish to get - note currently only works for creatures.
void NWNX_Factions_GetFactionId(object oCreature);

/// @brief Sets the faction id of a target object to nFaction
/// @param oObject - should work with any object type
/// @param nFaction - this should be an integer retrieved from the GetFactionId method
/// @return -1 = Unsuccessful, 1 = Successful : In the event of Unsuccessful, check that the target object and faction id are valid.
int NWNX_Factions_SetFactionId(object oObject, int nFaction);

/// @}

void NWNX_Factions_GetFactionId(object oCreature)
{
    string sFunc = "GetFactionId";
    NWNX_PushArgumentObject(NWNX_Factions, sFunc, oObject);
    NWNX_CallFunction(NWNX_Factions, sFunc);
}

int NWNX_Factions_SetFactionId(object oObject, int nFaction))
{
    string sFunc = "SetFactionId";

    NWNX_PushArgumentInt(NWNX_Factions, sFunc, nFaction);
    NWNX_PushArgumentObject(NWNX_Factions, sFunc, oObject);
    NWNX_CallFunction(NWNX_Factions, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Factions, sFunc);
}
