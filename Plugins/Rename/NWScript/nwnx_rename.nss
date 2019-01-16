#include "nwnx"

const string NWNX_Rename = "NWNX_Rename";

//Constants for Player Name states.
const int NWNX_RENAME_PLAYERNAME_DEFAULT = 0;
const int NWNX_RENAME_PLAYERNAME_OBFUSCATE = 1;
const int NWNX_RENAME_PLAYERNAME_OVERRIDE = 2;

//Set a PC's floaty/chat name(sPrefix+sNewName+sSuffix) and name (sNewName) on the player list.
//If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_OVERRIDE the player name will change to (sNewName) on tells.
//If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_OBFUSCATE the player name will be set to a random string.
//If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_DEFAULT the player name will be untouched.
//Will not persist through saving, resets or logout.
void NWNX_Rename_SetPCNameOverride(object oPC, string sPrefix, string sNewName, string sSuffix, int iPlayerNameState);


void NWNX_Rename_SetPCNameOverride(object oPC, string sPrefix, string sNewName, string sSuffix, int iPlayerNameState)
{
    string sFunc = "SetPCNameOverride";
    
    NWNX_PushArgumentInt(NWNX_Rename, sFunc, bOverridePlayerName);
    NWNX_PushArgumentString(NWNX_Rename, sFunc, sSuffix);
    NWNX_PushArgumentString(NWNX_Rename, sFunc, sNewName);
    NWNX_PushArgumentString(NWNX_Rename, sFunc, sPrefix);
    NWNX_PushArgumentObject(NWNX_Rename, sFunc, oPC);

    NWNX_CallFunction(NWNX_Rename, sFunc);
}