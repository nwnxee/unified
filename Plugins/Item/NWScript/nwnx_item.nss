/// @addtogroup item Item
/// @brief Functions exposing additional item properties.
/// @{
/// @file nwnx_item.nss
#include "nwnx"

const string NWNX_Item = "NWNX_Item"; ///< @private

/// @brief Set an item's weight.
/// @note Will not persist through saving.
/// @param oItem The item object.
/// @param weight The weight, note this is in tenths of pounds.
void NWNX_Item_SetWeight(object oItem, int weight);

/// @brief Set an item's base value in gold pieces.
/// @remark Total cost = base_value + additional_value.
/// @remark Equivalent to SetGoldPieceValue NWNX2 function.
/// @note Will not persist through saving.
/// @param oItem The item object.
/// @param gold The base gold value.
void NWNX_Item_SetBaseGoldPieceValue(object oItem, int gold);

/// @brief Set an item's additional value in gold pieces.
/// @remark Total cost = base_value + additional_value.
/// @note Will persist through saving.
/// @param oItem The item object.
/// @param gold The additional gold value.
void NWNX_Item_SetAddGoldPieceValue(object oItem, int gold);

/// @brief Get an item's base value in gold pieces.
/// @param oItem The item object.
/// @return The base gold piece value for the item.
int NWNX_Item_GetBaseGoldPieceValue(object oItem);

/// @brief Get an item's additional value in gold pieces.
/// @param oItem The item object.
/// @return The additional gold piece value for the item.
int NWNX_Item_GetAddGoldPieceValue(object oItem);

/// @brief Set an item's base item type.
/// @warning This will not be visible until the item is refreshed (e.g. drop and take the item,
/// or logging out and back in).
/// @param oItem The item object.
/// @param nBaseItem The new base item.
void NWNX_Item_SetBaseItemType(object oItem, int nBaseItem);

/// @brief Make a single change to the appearance of an item.
/// @warning This will not be visible to PCs until the item is refreshed for them (e.g. by logging out and back in).
///
/// Helmet models and simple items ignore nIndex.
/// ```
/// nType                            nIndex                              nValue
/// ITEM_APPR_TYPE_SIMPLE_MODEL      [Ignored]                           Model #
/// ITEM_APPR_TYPE_WEAPON_COLOR      ITEM_APPR_WEAPON_COLOR_*            0-255
/// ITEM_APPR_TYPE_WEAPON_MODEL      ITEM_APPR_WEAPON_MODEL_*            Model #
/// ITEM_APPR_TYPE_ARMOR_MODEL       ITEM_APPR_ARMOR_MODEL_*             Model #
/// ITEM_APPR_TYPE_ARMOR_COLOR       ITEM_APPR_ARMOR_COLOR_* [0]         0-255 [1]
/// ```
///
/// [0] Where ITEM_APPR_TYPE_ARMOR_COLOR is specified, if per-part coloring is
/// desired, the following equation can be used for nIndex to achieve that:
///
/// ITEM_APPR_ARMOR_NUM_COLORS + (ITEM_APPR_ARMOR_MODEL_ * ITEM_APPR_ARMOR_NUM_COLORS) + ITEM_APPR_ARMOR_COLOR_
///
/// For example, to change the CLOTH1 channel of the torso, nIndex would be:
///
///     6 + (7 * 6) + 2 = 50
///
/// [1] When specifying per-part coloring, the value 255 corresponds with the logical
/// function 'clear colour override', which clears the per-part override for that part.
void NWNX_Item_SetItemAppearance(object oItem, int nType, int nIndex, int nValue);

/// @brief Return a string containing the entire appearance for an item.
/// @sa NWNX_Item_RestoreItemAppearance
/// @param oItem The item object.
/// @return A string representing the item's appearance.
string NWNX_Item_GetEntireItemAppearance(object oItem);

/// @brief Restores an item's appearance using the value retrieved through NWNX_Item_GetEntireItemAppearance().
/// @param oItem The item object.
/// @param sApp A string representing the item's appearance.
void NWNX_Item_RestoreItemAppearance(object oItem, string sApp);

/// @brief Get an item's base armor class
/// @param oItem The item object.
/// @return The base armor class.
int NWNX_Item_GetBaseArmorClass(object oItem);

/// @brief Get an item's minimum level required to equip.
/// @param oItem The item object.
/// @return The minimum level required to equip the item.
int NWNX_Item_GetMinEquipLevel(object oItem);

/// @}

void NWNX_Item_SetWeight(object oItem, int w)
{
    string sFunc = "SetWeight";

    NWNX_PushArgumentInt(NWNX_Item, sFunc, w);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
}

void NWNX_Item_SetBaseGoldPieceValue(object oItem, int g)
{
    string sFunc = "SetBaseGoldPieceValue";

    NWNX_PushArgumentInt(NWNX_Item, sFunc, g);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
}

void NWNX_Item_SetAddGoldPieceValue(object oItem, int g)
{
    string sFunc = "SetAddGoldPieceValue";

    NWNX_PushArgumentInt(NWNX_Item, sFunc, g);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
}

int NWNX_Item_GetBaseGoldPieceValue(object oItem)
{
    string sFunc = "GetBaseGoldPieceValue";

    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Item, sFunc);
}

int NWNX_Item_GetAddGoldPieceValue(object oItem)
{
    string sFunc = "GetAddGoldPieceValue";

    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Item, sFunc);
}

void NWNX_Item_SetBaseItemType(object oItem, int nBaseItem)
{
    string sFunc = "SetBaseItemType";

    NWNX_PushArgumentInt(NWNX_Item, sFunc, nBaseItem);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
}

void NWNX_Item_SetItemAppearance(object oItem, int nType, int nIndex, int nValue)
{
    string sFunc = "SetItemAppearance";

    NWNX_PushArgumentInt(NWNX_Item, sFunc, nValue);
    NWNX_PushArgumentInt(NWNX_Item, sFunc, nIndex);
    NWNX_PushArgumentInt(NWNX_Item, sFunc, nType);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);

}

string NWNX_Item_GetEntireItemAppearance(object oItem)
{
    string sFunc = "GetEntireItemAppearance";

    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
    return NWNX_GetReturnValueString(NWNX_Item, sFunc);
}

void NWNX_Item_RestoreItemAppearance(object oItem, string sApp)
{
    string sFunc = "RestoreItemAppearance";

    NWNX_PushArgumentString(NWNX_Item, sFunc, sApp);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
}

int NWNX_Item_GetBaseArmorClass(object oItem)
{
    string sFunc = "GetBaseArmorClass";

    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Item, sFunc);
}

int NWNX_Item_GetMinEquipLevel(object oItem)
{
    string sFunc = "GetMinEquipLevel";

    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Item, sFunc);
}
