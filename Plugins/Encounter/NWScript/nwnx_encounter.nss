/// @addtogroup encounter Encounter
/// @brief Functions exposing additional encounter properties.
/// @{
/// @file nwnx_encounter.nss

const string NWNX_Encounter = "NWNX_Encounter"; ///< @private

/// @brief A creature list entry for an encounter.
struct NWNX_Encounter_CreatureListEntry
{
    string resref; ///< The resref.
    float challengeRating; ///< The challenge rating.
    int unique; ///< Creature will be unique to the encounter.
    int alreadyUsed; //< Creature has already been used.
};

/// @brief Immediately destroys the specified encounter object.
/// @param encounter The encounter object.
void NWNX_Encounter_Destroy(object encounter);

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

void NWNX_Encounter_Destroy(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "Destroy");
}

int NWNX_Encounter_GetNumberOfCreaturesInEncounterList(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetNumberOfCreaturesInEncounterList");
    return NWNXPopInt();
}

struct NWNX_Encounter_CreatureListEntry NWNX_Encounter_GetEncounterCreatureByIndex(object encounter, int index)
{
    struct NWNX_Encounter_CreatureListEntry creatureEntry;
    NWNXPushInt(index);
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetEncounterCreatureByIndex");
    creatureEntry.alreadyUsed = NWNXPopInt();
    creatureEntry.unique = NWNXPopInt();
    creatureEntry.challengeRating = NWNXPopFloat();
    creatureEntry.resref = NWNXPopString();
    return creatureEntry;
}

void NWNX_Encounter_SetEncounterCreatureByIndex(object encounter, int index, struct NWNX_Encounter_CreatureListEntry creatureEntry)
{
    NWNXPushInt(creatureEntry.alreadyUsed);
    NWNXPushInt(creatureEntry.unique);
    NWNXPushFloat(creatureEntry.challengeRating);
    NWNXPushString(creatureEntry.resref);
    NWNXPushInt(index);
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "SetEncounterCreatureByIndex");
}

int NWNX_Encounter_GetFactionId(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetFactionId");
    return NWNXPopInt();
}

void NWNX_Encounter_SetFactionId(object encounter, int factionId)
{
    NWNXPushInt(factionId);
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "SetFactionId");
}

int NWNX_Encounter_GetPlayerTriggeredOnly(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetPlayerTriggeredOnly");
    return NWNXPopInt();
}

void NWNX_Encounter_SetPlayerTriggeredOnly(object encounter, int playerTriggeredOnly)
{

    NWNXPushInt(playerTriggeredOnly);
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "SetPlayerTriggeredOnly");
}

int NWNX_Encounter_GetCanReset(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetCanReset");
    return NWNXPopInt();
}

void NWNX_Encounter_SetCanReset(object encounter, int reset)
{
    NWNXPushInt(reset);
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "SetCanReset");
}

int NWNX_Encounter_GetResetTime(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetResetTime");
    return NWNXPopInt();
}

void NWNX_Encounter_SetResetTime(object encounter, int resetTime)
{
    NWNXPushInt(resetTime);
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "SetResetTime");
}

int NWNX_Encounter_GetNumberOfSpawnPoints(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetNumberOfSpawnPoints");
    return NWNXPopInt();
}

location NWNX_Encounter_GetSpawnPointByIndex(object encounter, int index)
{
    NWNXPushInt(index);
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetSpawnPointByIndex");
    float fOrientation = NWNXPopFloat();
    vector vPosition = NWNXPopVector();
    return Location(GetArea(encounter), vPosition, fOrientation);
}

int NWNX_Encounter_GetMinNumSpawned(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetMinNumSpawned");
    return NWNXPopInt();
}

int NWNX_Encounter_GetMaxNumSpawned(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetMaxNumSpawned");
    return NWNXPopInt();
}

int NWNX_Encounter_GetCurrentNumSpawned(object encounter)
{
    NWNXPushObject(encounter);
    NWNXCall(NWNX_Encounter, "GetCurrentNumSpawned");
    return NWNXPopInt();
}

string NWNX_Encounter_GetGeometry(object oEncounter)
{
    NWNXPushObject(oEncounter);
    NWNXCall(NWNX_Encounter, "GetGeometry");
    return NWNXPopString();
}

void NWNX_Encounter_SetGeometry(object oEncounter, string sGeometry)
{
    NWNXPushString(sGeometry);
    NWNXPushObject(oEncounter);
    NWNXCall(NWNX_Encounter, "SetGeometry");
}
