#include "nwnx"

const string NWNX_Layonara = "NWNX_Layonara";

// Set the slots you can equip a base item
void NWNX_Layonara_SetEquippableSlots(int nBaseItem, int nSlots);

// Sets a feat as hostile
void NWNX_Layonara_SetHostileFeat(int nFeatID, int bHostile);

// Duelist Canny Defense
void NWNX_Layonara_DuelistCannyDefense(object creature, int nBonus);

// Duelist Grace
void NWNX_Layonara_SetDuelistGrace(object creature, int nBonus);

// Spellsword Ignore Spell Failure
void NWNX_Layonara_SetSpellswordIgnoreSpellFailure(object creature, int nBonus);

// Undead Slayer Immunity
void NWNX_Layonara_SetUndeadSlayerImmunity(object creature, int nImmunity);

// Subrace Effects for Daytime
void NWNX_Layonara_SetSubraceDayEffects(object creature, int nActive = TRUE);

// Get Quest Completed
int NWNX_Layonara_GetQuestCompleted(object creature, string sQuestName);

void NWNX_Layonara_SetEquippableSlots(int nBaseItem, int nSlots)
{
    string sFunc = "SetEquippableSlots";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nSlots);
    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nBaseItem);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetHostileFeat(int nFeatID, int bHostile)
{
    string sFunc = "SetHostileFeat";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, bHostile);
    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nFeatID);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetDuelistCannyDefense(object creature, int nBonus)
{
    string sFunc = "SetDuelistCannyDefense";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nBonus);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetDuelistGrace(object creature, int nBonus)
{
    string sFunc = "SetDuelistGrace";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nBonus);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetDuelistElaborateParry(object creature, int nBonus)
{
    string sFunc = "SetDuelistElaborateParry";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nBonus);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetSpellswordIgnoreSpellFailure(object creature, int nBonus)
{
    string sFunc = "SetSpellswordIgnoreSpellFailure";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nBonus);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetUndeadSlayerImmunity(object creature, int nImmunity)
{
    string sFunc = "SetUndeadSlayerImmunity";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nImmunity);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetSubraceDayEffects(object creature, int nActive = TRUE)
{
    string sFunc = "SetSubraceDayEffects";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nActive);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

int NWNX_Layonara_GetQuestCompleted(object creature, string sQuestName)
{
    string sFunc = "GetQuestCompleted";
    NWNX_PushArgumentString(NWNX_Layonara, sFunc, sQuestName);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
    return  NWNX_GetReturnValueInt(NWNX_Layonara, sFunc);
}
