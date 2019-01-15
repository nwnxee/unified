# Rename Plugin Reference

## Environment Variables

None

## Description


This plugin facilitates renaming, overriding and customization of player names.

Script function | Description  
----------------|-------------
NWNX_Rename_SetPCNameOverride | Set a PC's floaty/chat name(sPrefix+sNewName+sSuffix) and name (sNewName) on the player list. If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_OVERRIDE the player name will change to (sNewName) on tells. If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_OBFUSCATE the player name will be set to a random string.
If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_DEFAULT the player name will be untouched. Will not persist through saving, resets or logout.