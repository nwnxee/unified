#include "nwnx"


struct NWNX_Encounter_CreatureListEntry
{
    string resref;
    float cr;
    int unique;
};

// Get the number of creatures in the encounter list
int NWNX_Encounter_GetNumberOfCreaturesInEncounterList(object encounter);

// Returns the encounter creature list entry at the specified index
// Index bounds: 0 <= index < NWNX_Encounter_GetNumberOfCreaturesInEncounterList(encounter)
struct NWNX_Encounter_CreatureListEntry GetEncounterCreatureByIndex(object encounter, int index);


const string NWNX_Encounter = "NWNX_Encounter";


int NWNX_Encounter_GetNumberOfCreaturesInEncounterList(object encounter)
{
    string sFunc = "GetNumberOfCreaturesInEncounterList";

    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);
    NWNX_CallFunction(NWNX_Encounter, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Encounter, sFunc);
}

struct NWNX_Encounter_CreatureListEntry GetEncounterCreatureByIndex(object encounter, int index)
{
    string sFunc = "GetEncounterCreatureByIndex";
    struct NWNX_Encounter_CreatureListEntry creatureEntry;

    NWNX_PushArgumentInt(NWNX_Encounter, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Encounter, sFunc, encounter);

    NWNX_CallFunction(NWNX_Encounter, sFunc);

    creatureEntry.unique = NWNX_GetReturnValueInt(NWNX_Encounter, sFunc);
    creatureEntry.cr = NWNX_GetReturnValueFloat(NWNX_Encounter, sFunc);
    creatureEntry.resref = NWNX_GetReturnValueString(NWNX_Encounter, sFunc);

    return creatureEntry;
}
