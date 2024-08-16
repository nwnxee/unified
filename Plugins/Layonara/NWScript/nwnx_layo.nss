/// @defgroup layonara Layonara
/// @brief Various Layonara specific functions
/// @{
/// @file nwnx_layo.nss
#include "nwnx"

const string NWNX_Layonara = "NWNX_Layonara";

/// @brief Set the slots you can equip a base item
/// @param nBaseItem The base item id.
/// @param nSlots The slots this item can be equipped.
void NWNX_Layonara_SetEquippableSlots(int nBaseItem, int nSlots);

/// @brief Sets a feat as hostile
/// @param nFeatID The feat id.
/// @param bHostile TRUE if hostile.
void NWNX_Layonara_SetHostileFeat(int nFeatID, int bHostile);

/// @brief Enable the Duelist Canny Defense effects
/// @param creature The creature object.
/// @param nBonus The bonus amount.
void NWNX_Layonara_SetDuelistCannyDefense(object creature, int nBonus);

/// @brief Enable the Duelist Grace effects.
/// @param creature The creature object.
/// @param nBonus The bonus amount.
void NWNX_Layonara_SetDuelistGrace(object creature, int nBonus);

/// @brief Enable the Duelist Elaborate Parry effects.
/// @param creature The creature object.
/// @param nBonus The bonus amount.
void NWNX_Layonara_SetDuelistElaborateParry(object creature, int nBonus);

/// @brief Set the Subrace Effects for Daytime
/// @param creature The creature object.
/// @param nActive TRUE if turned on.
void NWNX_Layonara_SetSubraceDayEffects(object creature, int nActive = TRUE);

/// @brief Apply a Rune
/// @param creature The creature object.
/// @param item The rune
void NWNX_Layonara_ApplyRune(object creature, object item);

/// @brief Combine runes
/// @param target The target rune
/// @param item The original rune
/// @return The resref of the new rune.
string NWNX_Layonara_CombineRunes(object target, object item);

/// @brief Get rune description
/// @param item The rune.
/// @return A description of a rune's properties.
string NWNX_Layonara_GetRuneDescription(object item);

/// @brief Apply a quiver effect
/// @param creature The creature object.
/// @param nColor The quiver color.
void NWNX_Layonara_SetQuiver(object creature, int nColor);

/// @brief Apply quiver arrow effects
/// @param creature The creature object.
void NWNX_Layonara_SetQuiverArrows(object creature);

/// @brief Place new AT VFX at centroid of transitions
void NWNX_Layonara_CreateVFXAtTransitionCentroid();

/// @brief Clear the surface material so a change is fired on next movement.
/// @param creature The creature object.
void NWNX_Layonara_ClearSurfaceMaterial(object creature);

/// @}

void NWNX_Layonara_SetEquippableSlots(int nBaseItem, int nSlots)
{
    string sFunc = "SetEquippableSlots";

    NWNX_PushArgumentInt(nSlots);
    NWNX_PushArgumentInt(nBaseItem);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetHostileFeat(int nFeatID, int bHostile)
{
    string sFunc = "SetHostileFeat";

    NWNX_PushArgumentInt(bHostile);
    NWNX_PushArgumentInt(nFeatID);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetDuelistCannyDefense(object creature, int nBonus)
{
    string sFunc = "SetDuelistCannyDefense";

    NWNX_PushArgumentInt(nBonus);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetDuelistGrace(object creature, int nBonus)
{
    string sFunc = "SetDuelistGrace";

    NWNX_PushArgumentInt(nBonus);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetDuelistElaborateParry(object creature, int nBonus)
{
    string sFunc = "SetDuelistElaborateParry";

    NWNX_PushArgumentInt(nBonus);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetSubraceDayEffects(object creature, int nActive = TRUE)
{
    string sFunc = "SetSubraceDayEffects";

    NWNX_PushArgumentInt(nActive);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_ApplyRune(object creature, object item)
{
    string sFunc = "ApplyRune";

    NWNX_PushArgumentObject(item);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

string NWNX_Layonara_CombineRunes(object target, object item)
{
    string sFunc = "CombineRunes";

    NWNX_PushArgumentObject(item);
    NWNX_PushArgumentObject(target);

    NWNX_CallFunction(NWNX_Layonara, sFunc);

    return NWNX_GetReturnValueString();
}

string NWNX_Layonara_GetRuneDescription(object item)
{
    string sFunc = "GetRuneDescription";

    NWNX_PushArgumentObject(item);

    NWNX_CallFunction(NWNX_Layonara, sFunc);

    return NWNX_GetReturnValueString();
}

void NWNX_Layonara_SetQuiver(object creature, int nColor)
{
    string sFunc = "SetQuiver";

    NWNX_PushArgumentInt(nColor);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

void NWNX_Layonara_SetQuiverArrows(object creature)
{
    string sFunc = "SetQuiverArrows";

    NWNX_PushArgumentObject(creature);

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

    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Layonara, sFunc);
}

