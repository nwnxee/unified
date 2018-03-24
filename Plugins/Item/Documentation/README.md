# Item Plugin Reference

## Environment Variables

None

## Description

Functions exposing additional item properties.

This plugin allows changing different items properties. Just call the different NWNX_Item_* functions on a valid item target. 

Script function | Description  
----------------|-------------
NWNX_Item_SetWeight | Change the weigth of the item. Will not persist through server reset. 
NWNX_Item_SetBaseGoldPieceValue | Change the item's base value in gold pieces (Total cost = base value + additional value). Will not persist through server reset.
NWNX_Item_GetBaseGoldPieceValue | Get the item's base value in gold pieces.
NWNX_Item_SetAddGoldPieceValue | Change the item's additional value in gold pieces (Total cost = base value + additional value). Will persist through server reset.
NWNX_Item_GetAddGoldPieceValue | Get the item's additional value in gold pieces.
NWNX_Item_SetBaseItemType | Change the item's base item type (e.g. change an armor into a ring). Changes will not be visible until the item is refreshed (e.g. drop and take the item, or logging out and back in).
NWNX_Item_SetItemAppearance | Change item's appearance. A more general function with syntax similar to the NWScript function CopyItemAndModify. Changes will not be visible until the item is refreshed (e.g. drop and take the item, or logging out and back in).




 


