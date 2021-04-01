/// @addtogroup encounter Encounter
/// @brief Functions exposing additional encounter properties.
/// @{
/// @file nwnx_encounter.nss
#include "nwnx"

const string NWNX_Encounter = "NWNX_Encounter"; ///< @private

/// @brief A creature list entry for an encounter.
struct NWNX_Encounter_CreatureListEntry
{
    string resref; ///< The resref.
    float challengeRating; ///< The challenge rating.
    int unique; ///< Creature will be unique to the encounter.
    int alreadyUsed; //< Creature has already been used.
};


/// @brief Get the number of creatures in the encounter list
/// @param encounter The encounter object.
/// @return The number of creatures in the encounter list.
int NWNX_Encounter_GetNumberOfCreaturesInEncounterList(object encounter);

/// @brief Gets the encounter creature list entry at the specified index
/// @param encounter The encounter object.
/// @param index The index of the creature in the encounter list.
/// @return An NWNX_Encounter_CreatureListEntry.
struct NWNX_Encounter_CreatureListEntry NWNX_Encounter_GetEncounterCreatureByIndex(object encounter, int index);

/// @brief Set the encounter creature list entry at the specified index
/// @param encounter The encounter object.
/// @param index The index of the creature in the encounter list.
/// @param creatureEntry The NWNX_Encounter_CreatureListEntry.
void NWNX_Encounter_SetEncounterCreatureByIndex(object encounter, int index, struct NWNX_Encounter_CreatureListEntry creatureEntry);

/// @brief Get the faction id of encounter
/// @param encounter The encounter object.
/// @return The faction id.
int NWNX_Encounter_GetFactionId(object encounter);

/// @brief Set the faction id of encounter.
/// @param encounter The encounter object.
/// @param factionId The faction id.
void NWNX_Encounter_SetFactionId(object encounter, int factionId);

/// @brief Get if encounter is player triggered only.
/// @param encounter The encounter object.
/// @return TRUE if encounter is player triggered only.
int NWNX_Encounter_GetPlayerTriggeredOnly(object encounter);

/// @brief Set if encounter is player triggered only.
/// @param encounter The encounter object.
/// @param playerTriggeredOnly TRUE/FALSE
void NWNX_Encounter_SetPlayerTriggeredOnly(object encounter, int playerTriggeredOnly);

/// @brief Get if the encounter respawns or not.
/// @param encounter The encounter object.
/// @return TRUE if the encounter does respawn, FALSE otherwise.
int NWNX_Encounter_GetCanReset(object encounter);

/// @brief Set if the encounter respawns or not.
/// @param encounter The encounter object.
/// @param reset Does the encounter respawn TRUE or FALSE.
void NWNX_Encounter_SetCanReset(object encounter, int reset);

/// @brief Get the reset time of encounter.
/// @param encounter The encounter object.
/// @return The seconds the encounter is defined to reset.
int NWNX_Encounter_GetResetTime(object encounter);

/// @brief Set the reset time of encounter.
/// @param encounter The encounter object.
/// @param resetTime The seconds the encounter will reset.
void NWNX_Encounter_SetResetTime(object encounter, int resetTime);

/// @brief Get the number of spawn points of encounter.
/// @param encounter The encounter object.
/// @return The count of the spawn points for the encounter.
int NWNX_Encounter_GetNumberOfSpawnPoints(object encounter);

/// @brief Gets the spawn point list entry at the specified index
/// @param encounter The encounter object.
/// @param index The index of the spawn point in the encounter list.
/// @return Location of spawn point.
location NWNX_Encounter_GetSpawnPointByIndex(object encounter, int index);

/// @brief Get the minimum amount of creatures that encounter will spawn.
/// @param encounter The encounter object.
/// @return the minimal amount.
int NWNX_Encounter_GetMinNumSpawned(object encounter);

/// @brief Get the maximum amount of creatures that encounter will spawn.
/// @param encounter The encounter object.
/// @return the maximal amount.
int NWNX_Encounter_GetMaxNumSpawned(object encounter);

/// @brief Get the current number of creatures that are spawned and alive
/// @param encounter The encounter object.
/// @return amount of creatures
int NWNX_Encounter_GetCurrentNumSpawned(object encounter);

/// @brief Get the geometry of an encounter
/// @param oEncounter: The encounter object.
/// @return A string of vertex positions.
string NWNX_Encounter_GetGeometry(object oEncounter);

/// @brief Set the geometry of an encounter with a list of vertex positions
/// @param oTrigger The encounter object.
/// @param sGeometry Needs to be in the following format -> {x.x, y.y, z.z} or {x.x, y.y}
/// Example Geometry: "{1.0, 1.0, 0.0}{4.0, 1.0, 0.0}{4.0, 4.0, 0.0}{1.0, 4.0, 0.0}"
///
/// @remark The Z position is optional and will be calculated dynamically based
/// on terrain height if it's not provided.
///
/// @remark The minimum number of vertices is 3.
void NWNX_Encounter_SetGeometry(object oTrigger, string sGeometry);

/// @}

int NWNX_Encounter_GetNumberOfCreaturesInEncounterList(object encounter)
{
    string sFunc = "GetNumberOfCreaturesInEncounterList";

    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt();
}

struct NWNX_Encounter_CreatureListEntry NWNX_Encounter_GetEncounterCreatureByIndex(object encounter, int index)
{
    string sFunc = "GetEncounterCreatureByIndex";
    struct NWNX_Encounter_CreatureListEntry creatureEntry;

    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentObject(encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);

    creatureEntry.alreadyUsed = NWNX_GetReturnValueInt();
    creatureEntry.unique = NWNX_GetReturnValueInt();
    creatureEntry.challengeRating = NWNX_GetReturnValueFloat();
    creatureEntry.resref = NWNX_GetReturnValueString();

    return creatureEntry;
}

void NWNX_Encounter_SetEncounterCreatureByIndex(object encounter, int index, struct NWNX_Encounter_CreatureListEntry creatureEntry)
{
    string sFunc = "SetEncounterCreatureByIndex";

    NWNX_PushArgumentInt(creatureEntry.alreadyUsed);
    NWNX_PushArgumentInt(creatureEntry.unique);
    NWNX_PushArgumentFloat(creatureEntry.challengeRating);
    NWNX_PushArgumentString(creatureEntry.resref);
    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentObject(encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);
}

int NWNX_Encounter_GetFactionId(object encounter)
{
    string sFunc = "GetFactionId";

    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Encounter_SetFactionId(object encounter, int factionId)
{
    string sFunc = "SetFactionId";

    NWNX_PushArgumentInt(factionId);
    NWNX_PushArgumentObject(encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);
}

int NWNX_Encounter_GetPlayerTriggeredOnly(object encounter)
{
    string sFunc = "GetPlayerTriggeredOnly";

    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Encounter_SetPlayerTriggeredOnly(object encounter, int playerTriggeredOnly)
{
    string sFunc = "SetPlayerTriggeredOnly";

    NWNX_PushArgumentInt(playerTriggeredOnly);
    NWNX_PushArgumentObject(encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);
}

int NWNX_Encounter_GetCanReset(object encounter)
{
    string sFunc = "GetCanReset";

    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Encounter_SetCanReset(object encounter, int reset)
{
    string sFunc = "SetCanReset";

    NWNX_PushArgumentInt(reset);
    NWNX_PushArgumentObject(encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);
}

int NWNX_Encounter_GetResetTime(object encounter)
{
    string sFunc = "GetResetTime";

    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Encounter_SetResetTime(object encounter, int resetTime)
{
    string sFunc = "SetResetTime";

    NWNX_PushArgumentInt(resetTime);
    NWNX_PushArgumentObject(encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);
}

int NWNX_Encounter_GetNumberOfSpawnPoints(object encounter)
{
    string sFunc = "GetNumberOfSpawnPoints";
  
    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);
  
    return NWNX_GetReturnValueInt();
}

location NWNX_Encounter_GetSpawnPointByIndex(object encounter, int index)
{
    string sFunc = "GetSpawnPointByIndex";
  
    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);
  
    float o = NWNX_GetReturnValueFloat();
    float z = NWNX_GetReturnValueFloat();
    float y = NWNX_GetReturnValueFloat();
    float x = NWNX_GetReturnValueFloat();
  
    return Location(GetArea(encounter), Vector(x, y, z), o);
}

int NWNX_Encounter_GetMinNumSpawned(object encounter)
{
    string sFunc = "GetMinNumSpawned";
  
    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);
  
    return NWNX_GetReturnValueInt();
}

int NWNX_Encounter_GetMaxNumSpawned(object encounter)
{
    string sFunc = "GetMaxNumSpawned";
  
    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);
  
    return NWNX_GetReturnValueInt();
}

int NWNX_Encounter_GetCurrentNumSpawned(object encounter)
{
    string sFunc = "GetCurrentNumSpawned";
  
    NWNX_PushArgumentObject(encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);
  
    return NWNX_GetReturnValueInt();
}

string NWNX_Encounter_GetGeometry(object oEncounter)
{
    string sFunc = "GetGeometry";

    NWNX_PushArgumentObject(oEncounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueString();
}

void NWNX_Encounter_SetGeometry(object oEncounter, string sGeometry)
{
    string sFunc = "SetGeometry";

    NWNX_PushArgumentString(sGeometry);
    NWNX_PushArgumentObject(oEncounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);
}
