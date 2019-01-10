# Rename Plugin Reference

## Environment Variables

None

## Description

Functions to facilitate renaming, overriding and customization of player names.

This plugin allows changing different items properties. Just call the different NWNX_Item_* functions on a valid item target. 

Script function | Description  
----------------|-------------
NWNX_Rename_SetPlayerOverrideName | Set a player's floaty name(sPrefix+sNewName+sSuffix) and name on the player list (sNewName). Will not persist through saving, resets or logout.