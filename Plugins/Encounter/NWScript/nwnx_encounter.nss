#include "nwnx"

struct NWNX_Encounter_CreatureListEntry
{
    string resref;
    float challengeRating;
    int unique;
};

// Get the number of creatures in the encounter list
int NWNX_Encounter_GetNumberOfCreaturesInEncounterList(object encounter);

// Gets the encounter creature list entry at the specified index
// Index bounds: 0 <= index < NWNX_Encounter_GetNumberOfCreaturesInEncounterList(encounter)
struct NWNX_Encounter_CreatureListEntry NWNX_Encounter_GetEncounterCreatureByIndex(object encounter, int index);

// Set the encounter creature list entry at the specified index
// Index bounds: 0 <= index < NWNX_Encounter_GetNumberOfCreaturesInEncounterList(encounter)
void NWNX_Encounter_SetEncounterCreatureByIndex(object encounter, int index, struct NWNX_Encounter_CreatureListEntry creatureEntry);

// Get the faction id of encounter
int NWNX_Encounter_GetFactionId(object encounter);

// Set the faction id of encounter
void NWNX_Encounter_SetFactionId(object encounter, int factionId);

// Get if encounter is player triggered only
int NWNX_Encounter_GetPlayerTriggeredOnly(object encounter);

// Set if encounter is player triggered only
// playerTriggeredOnly = TRUE/FALSE
void NWNX_Encounter_SetPlayerTriggeredOnly(object encounter, int playerTriggeredOnly);

// Get the reset time of encounter
int NWNX_Encounter_GetResetTime(object encounter);

// Set the reset time of encounter
void NWNX_Encounter_SetResetTime(object encounter, int resetTime);


const string NWNX_Encounter = "NWNX_Encounter";


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
