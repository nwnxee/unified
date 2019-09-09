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

// Apply Rune
void NWNX_Layonara_ApplyRune(object creature, object item);

// Combine Runes
string NWNX_Layonara_CombineRunes(object target, object item);

// Get Rune Description
string NWNX_Layonara_GetRuneDescription(object item);

// Quiver Effect
void NWNX_Layonara_SetQuiver(object creature, int nColor);

// Quiver Arrow Effects
void NWNX_Layonara_SetQuiverArrows(object creature);

// Place new AT VFX at centroid of transitions
void NWNX_Layonara_CreateVFXAtTransitionCentroid();

// Surface material change
void NWNX_Layonara_ClearSurfaceMaterial(object creature);

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

void NWNX_Layonara_ApplyRune(object creature, object item)
{
    string sFunc = "ApplyRune";

    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, item);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

string NWNX_Layonara_CombineRunes(object target, object item)
{
    string sFunc = "CombineRunes";

    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, item);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, target);

    NWNX_CallFunction(NWNX_Layonara, sFunc);

    return NWNX_GetReturnValueString(NWNX_Layonara, sFunc);
}

string NWNX_Layonara_GetRuneDescription(object item)
{
    string sFunc = "GetRuneDescription";

    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, item);

    NWNX_CallFunction(NWNX_Layonara, sFunc);

    return NWNX_GetReturnValueString(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetQuiver(object creature, int nColor)
{
    string sFunc = "SetQuiver";

    NWNX_PushArgumentInt(NWNX_Layonara, sFunc, nColor);
    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetQuiverArrows(object creature)
{
    string sFunc = "SetQuiverArrows";

    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_CreateVFXAtTransitionCentroid()
{
    string sFunc = "CreateVFXAtTransitionCentroid";

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_ClearSurfaceMaterial(object creature)
{
    string sFunc = "ClearSurfaceMaterial";

    NWNX_PushArgumentObject(NWNX_Layonara, sFunc, creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

