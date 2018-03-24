#include "nwnx"

const string NWNX_Item = "NWNX_Item";

// Set oItem's weight. Will not persist through saving.
void NWNX_Item_SetWeight(object oItem, int w);

// Set oItem's base value in gold pieces (Total cost = base_value +
// additional_value). Will not persist through saving.
// NOTE: Equivalent to SetGoldPieceValue NWNX2 function
void NWNX_Item_SetBaseGoldPieceValue(object oItem, int g);

// Set oItem's additional value in gold pieces (Total cost = base_value +
// additional_value). Will persist through saving.
void NWNX_Item_SetAddGoldPieceValue(object oItem, int g);

// Get oItem's base value in gold pieces.
int NWNX_Item_GetBaseGoldPieceValue(object oItem);

// Get oItem's additional value in gold pieces.
int NWNX_Item_GetAddGoldPieceValue(object oItem);

// Set oItem's base item type. This will not be visible until the
// item is refreshed (e.g. drop and take the item, or logging out
// and back in).
void NWNX_Item_SetBaseItemType(object oItem, int nBaseItem);

// Make a single change to the appearance of an item. This will not be visible to PCs until
// the item is refreshed for them (e.g. by logging out and back in).
// Helmet models and simple items ignore iIndex.
// nType                            nIndex                              nValue
// ITEM_APPR_TYPE_SIMPLE_MODEL      [Ignored]                           Model #
// ITEM_APPR_TYPE_WEAPON_COLOR      ITEM_APPR_WEAPON_COLOR_*            0-255
// ITEM_APPR_TYPE_WEAPON_MODEL      ITEM_APPR_WEAPON_MODEL_*            Model #
// ITEM_APPR_TYPE_ARMOR_MODEL       ITEM_APPR_ARMOR_MODEL_*             Model #
// ITEM_APPR_TYPE_ARMOR_COLOR       ITEM_APPR_ARMOR_COLOR_* [0]         0-255 [1]
//
// [0] Alternatively, where ITEM_APPR_TYPE_ARMOR_COLOR is specified, if per-part coloring is
// desired, the following equation can be used for nIndex to achieve that:
// 
// ITEM_APPR_ARMOR_NUM_COLORS + (ITEM_APPR_ARMOR_MODEL_ * ITEM_APPR_ARMOR_NUM_COLORS) + ITEM_APPR_ARMOR_COLOR_
// 
// For example, to change the CLOTH1 channel of the torso, nIndex would be:
// 
//     6 + (7 * 6) + 2 = 50
// 
// [1] When specifying per-part coloring, the value 255 corresponds with the logical
// function 'clear colour override', which clears the per-part override for that part.
void NWNX_Item_SetItemAppearance(object oItem, int nType, int nIndex, int nValue);

/* Return a string containing the entire appearance for oItem which can later be
 * passed to RestoreItemAppearance(). */
string NWNX_Item_GetEntireItemAppearance (object oItem);

/* Restore an item's appearance with the value returned by GetEntireItemAppearance(). */
void NWNX_Item_RestoreItemAppearance (object oItem, string sApp);

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
		
