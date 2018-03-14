#include "nwnx"

const string NWNX_Item = "NWNX_Item";

// Set oItem's weight. Will not persist through saving.
void NWNX_Item_SetWeight(object oItem, int w);

// Set oItem's value in golp pieces. Will not persist through saving.
void NWNX_Item_SetGoldPieceValue(object oItem, int g);

// Set oItem's base item type. This will not be visible until the
// item is refreshed (e.g. drop and take the item, or logging out
// and back in).
void NWNX_Item_SetBaseItemType(object oItem, int nBaseItem);

// Set a color value on an item. This will not be visible to PCs until
// the item is refreshed for them (e.g. by logging out and back in).
// nIndex range: [0, 6]
// nColor range: [0,255]
void NWNX_Item_SetItemColor(object oItem, int nIndex, int nColor);

// Set an appearance value on an item. This will not be visible to PCs until
// the item is refreshed for them (e.g. by logging out and back in).
// nIndex range:
//    - Color: [-9,-4]
//    - General item: [-3,-1]
//    - Armor: [0,18]
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

void NWNX_Item_SetGoldPieceValue(object oItem, int g)
{
    string sFunc = "SetGoldPieceValue";
    
    NWNX_PushArgumentInt(NWNX_Item, sFunc, g);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);
    
    NWNX_CallFunction(NWNX_Item, sFunc);
}
				
void NWNX_Item_SetBaseItemType(object oItem, int nBaseItem)
{
    string sFunc = "SetBaseItemType";
    
    NWNX_PushArgumentInt(NWNX_Item, sFunc, nBaseItem);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);
    
    NWNX_CallFunction(NWNX_Item, sFunc);
}
    
void NWNX_Item_SetItemColor (object oItem, int nIndex, int nColor)
{
    string sFunc = "SetItemColor";

    NWNX_PushArgumentInt(NWNX_Item, sFunc, nColor);
    NWNX_PushArgumentInt(NWNX_Item, sFunc, nIndex);
    NWNX_PushArgumentObject(NWNX_Item, sFunc, oItem);

    NWNX_CallFunction(NWNX_Item, sFunc);
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
		
