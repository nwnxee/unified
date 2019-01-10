#include "nwnx"

const string NWNX_Rename = "NWNX_Rename";

//Set a player's floaty name(sPrefix+sNewName+sSuffix) and name on the player list (sNewName). Will not persist through saving, resets or logout.
void NWNX_Rename_SetPlayerOverrideName(object oPlayer, string sPrefix, string sNewName, string sSuffix);


void NWNX_Rename_SetPlayerOverrideName(object oPlayer, string sPrefix, string sNewName, string sSuffix)
{
    string sFunc = "SetPlayerOverrideName";
	
	NWNX_PushArgumentString(NWNX_Rename, sFunc, sSuffix);
	NWNX_PushArgumentString(NWNX_Rename, sFunc, sNewName);
    NWNX_PushArgumentString(NWNX_Rename, sFunc, sPrefix);
    NWNX_PushArgumentObject(NWNX_Rename, sFunc, oPlayer);

    NWNX_CallFunction(NWNX_Rename, sFunc);
}
