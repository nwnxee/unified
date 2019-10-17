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
/// @return TRUE is encounter is player triggered only.
int NWNX_Encounter_GetPlayerTriggeredOnly(object encounter);

/// @brief Set if encounter is player triggered only.
/// @param encounter The encounter object.
/// @param playerTriggeredOnly TRUE/FALSE
void NWNX_Encounter_SetPlayerTriggeredOnly(object encounter, int playerTriggeredOnly);

/// @brief Get the reset time of encounter.
/// @param encounter The encounter object.
/// @return The seconds the encounter is defined to reset.
int NWNX_Encounter_GetResetTime(object encounter);

/// @brief Set the reset time of encounter.
/// @param encounter The encounter object.
/// @param resetTime The seconds the encounter will reset.
void NWNX_Encounter_SetResetTime(object encounter, int resetTime);

/// @}

int NWNX_Encounter_GetNumberOfCreaturesInEncounterList(object encounter)
{
    string sFunc = "GetNumberOfCreaturesInEncounterList";

    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Encounter, sFunc);
}

struct NWNX_Encounter_CreatureListEntry NWNX_Encounter_GetEncounterCreatureByIndex(object encounter, int index)
{
    string sFunc = "GetEncounterCreatureByIndex";
    struct NWNX_Encounter_CreatureListEntry creatureEntry;

    NWNX_PushArgumentInt(NWNX_Encounter, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);

    creatureEntry.unique = NWNX_GetReturnValueInt(NWNX_Encounter, sFunc);
    creatureEntry.challengeRating = NWNX_GetReturnValueFloat(NWNX_Encounter, sFunc);
    creatureEntry.resref = NWNX_GetReturnValueString(NWNX_Encounter, sFunc);

    return creatureEntry;
}

void NWNX_Encounter_SetEncounterCreatureByIndex(object encounter, int index, struct NWNX_Encounter_CreatureListEntry creatureEntry)
{
    string sFunc = "SetEncounterCreatureByIndex";

    NWNX_PushArgumentInt(NWNX_Encounter, sFunc, creatureEntry.unique);
    NWNX_PushArgumentFloat(NWNX_Encounter, sFunc, creatureEntry.challengeRating);
    NWNX_PushArgumentString(NWNX_Encounter, sFunc, creatureEntry.resref);
    NWNX_PushArgumentInt(NWNX_Encounter, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);
}

int NWNX_Encounter_GetFactionId(object encounter)
{
    string sFunc = "GetFactionId";

    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Encounter, sFunc);
}

void NWNX_Encounter_SetFactionId(object encounter, int factionId)
{
    string sFunc = "SetFactionId";

    NWNX_PushArgumentInt(NWNX_Encounter, sFunc, factionId);
    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);
}

int NWNX_Encounter_GetPlayerTriggeredOnly(object encounter)
{
    string sFunc = "GetPlayerTriggeredOnly";

    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Encounter, sFunc);
}

void NWNX_Encounter_SetPlayerTriggeredOnly(object encounter, int playerTriggeredOnly)
{
    string sFunc = "SetPlayerTriggeredOnly";

    NWNX_PushArgumentInt(NWNX_Encounter, sFunc, playerTriggeredOnly);
    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);
}

int NWNX_Encounter_GetResetTime(object encounter)
{
    string sFunc = "GetResetTime";

    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Encounter, sFunc);
}

void NWNX_Encounter_SetResetTime(object encounter, int resetTime)
{
    string sFunc = "SetResetTime";

    NWNX_PushArgumentInt(NWNX_Encounter, sFunc, resetTime);
    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);
}
