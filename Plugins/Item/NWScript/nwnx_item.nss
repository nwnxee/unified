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

// Set a color value on an armor. This will not be visible to PCs until
// the item is refreshed for them (e.g. by logging out and back in).
// nIndex: ITEM_APPR_ARMOR_COLOR_*
// nColor range: [0, 175]
// NOTE: Equivalent to SetItemColor NWNX2 function
void NWNX_Item_SetArmorColor(object oItem, int nIndex, int nColor);

// Set a color value on a weapon. This will not be visible to PCs until
// the item is refreshed for them (e.g. by logging out and back in).
// nIndex: ITEM_APPR_WEAPON_COLOR_*
// nColor range: [1, 4]
void NWNX_Item_SetWeaponColor(object oItem, int nIndex, int nColor);

// Set an appearance value on a weapon. This will not be visible to PCs until
// the item is refreshed for them (e.g. by logging out and back in).
// nIndex: ITEM_APPR_WEAPON_MODEL_* 
// nValue range: [0,255]
void NWNX_Item_SetWeaponAppearance(object oItem, int nIndex, int nValue);

// Set an appearance value on an armor. This will not be visible to PCs until
// the item is refreshed for them (e.g. by logging out and back in).
// nIndex: ITEM_APPR_ARMOR_MODEL_* 
// nValue range: [0,255]
void NWNX_Item_SetArmorAppearance(object oItem, int nIndex, int nValue);

// Set an appearance value on an item. This will not be visible to PCs until
// the item is refreshed for them (e.g. by logging out and back in).
// nIndex range:
//    - Color:   [0,  5]
//    - Weapons: [6,  8]
//    - Armor:   [9, 28]
// nValue range: [0,255]
void NWNX_Item_SetItemAppearance(object oItem, int nIndex, int nValue);

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
    
void NWNX_Item_SetArmorColor(object oItem, int nIndex, int nColor)
{
    if(nIndex>=ITEM_APPR_ARMOR_COLOR_LEATHER1 &&
       nIndex<=ITEM_APPR_ARMOR_COLOR_METAL2 &&
       nColor>=0 && nColor<=175)
    {
        NWNX_Item_SetItemAppearance(oItem, nIndex, nColor);
    }
}

void NWNX_Item_SetWeaponColor(object oItem, int nIndex, int nColor)
{
    if(nIndex>=ITEM_APPR_WEAPON_COLOR_BOTTOM &&
       nIndex<=ITEM_APPR_WEAPON_COLOR_TOP &&
       nColor>=1 && nColor<=4)
    {
        NWNX_Item_SetItemAppearance(oItem, nIndex, nColor);
    }
}

void NWNX_Item_SetWeaponAppearance(object oItem, int nIndex, int nValue)
{
    if(nIndex>=ITEM_APPR_WEAPON_MODEL_BOTTOM &&
       nIndex<=ITEM_APPR_WEAPON_MODEL_TOP &&
       nValue>=0 && nValue<=255)
    {
        NWNX_Item_SetItemAppearance(oItem, nIndex + 6, nValue);
    }  
}

void NWNX_Item_SetArmorAppearance(object oItem, int nIndex, int nValue)
{
    if(nIndex>=ITEM_APPR_ARMOR_MODEL_RFOOT &&
       nIndex<=ITEM_APPR_ARMOR_MODEL_ROBE &&
       nValue>=0 && nValue<=255)
    {
        NWNX_Item_SetItemAppearance(oItem, nIndex + 9, nValue);
    }  
}

void NWNX_Item_SetItemAppearance(object oItem, int nIndex, int nValue)
{
    string sFunc = "SetItemAppearance";
  
    NWNX_PushArgumentInt(NWNX_Item, sFunc, nValue);
    NWNX_PushArgumentInt(NWNX_Item, sFunc, nIndex);
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
		
