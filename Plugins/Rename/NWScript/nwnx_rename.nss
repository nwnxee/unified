#include "nwnx"

const string NWNX_Rename = "NWNX_Rename";

//Constants for Player Name states.
const int NWNX_RENAME_PLAYERNAME_DEFAULT = 0;
const int NWNX_RENAME_PLAYERNAME_OBFUSCATE = 1;
const int NWNX_RENAME_PLAYERNAME_OVERRIDE = 2;
const int NWNX_RENAME_PLAYERNAME_ANONYMOUS = 3;

//Set a PC's floaty/chat name(sPrefix+sNewName+sSuffix) and name (sNewName) on the player list.
//If an observer is specified, the PCs name will appear to that observer as set, this overrides a global setting.
//If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_OVERRIDE the player name will change to (sNewName) on tells.
//If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_OBFUSCATE the player name will be set to a random string.
//If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_ANONYMOUS the player name will be set to the value of the
// NWNX_RENAME_ANONYMOUS_NAME environment variable (default is "Someone").
//If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_DEFAULT the player name will be untouched.
//Will not persist through saving, resets or logout.
void NWNX_Rename_SetPCNameOverride(object oTarget, string sNewName, string sPrefix = "" , string sSuffix = "" ,
                                   int iPlayerNameState = NWNX_RENAME_PLAYERNAME_DEFAULT, object oObserver = OBJECT_INVALID);

//Gets a PCs name as overridden
string NWNX_Rename_GetPCNameOverride(object oTarget, object oObserver = OBJECT_INVALID);

// Clears an overridden PC Name
//ClearPCNameOverride(oTargetPC); //clears global override for that target PC
//ClearPCNameOverride(oTargetPC, OBJECT_INVALID, true); // clears global override and all personal overrides for that target PC
//ClearPCNameOverride(oTargetPC, oObserverPC); // clears personal override for that observer for target oPC
//ClearPCNameOverride(OBJECT_INVALID, oObserverPC); // clears all personal overrides for the observer for any targets
void NWNX_Rename_ClearPCNameOverride(object oTarget, object oObserver = OBJECT_INVALID, int clearAll = FALSE);

void NWNX_Rename_SetPCNameOverride(object oTarget, string sNewName, string sPrefix = "" , string sSuffix = "" ,
                                   int iPlayerNameState = NWNX_RENAME_PLAYERNAME_DEFAULT, object oObserver = OBJECT_INVALID)
{
    string sFunc = "SetPCNameOverride";

    NWNX_PushArgumentObject(NWNX_Rename, sFunc, oObserver);
    NWNX_PushArgumentInt(NWNX_Rename, sFunc, iPlayerNameState);
    NWNX_PushArgumentString(NWNX_Rename, sFunc, sSuffix);
    NWNX_PushArgumentString(NWNX_Rename, sFunc, sPrefix);
    NWNX_PushArgumentString(NWNX_Rename, sFunc, sNewName);
    NWNX_PushArgumentObject(NWNX_Rename, sFunc, oTarget);

    NWNX_CallFunction(NWNX_Rename, sFunc);
}
string NWNX_Rename_GetPCNameOverride(object oTarget, object oObserver = OBJECT_INVALID)
{
    string sFunc = "GetPCNameOverride";

    NWNX_PushArgumentObject(NWNX_Rename, sFunc, oObserver);
    NWNX_PushArgumentObject(NWNX_Rename, sFunc, oTarget);

    NWNX_CallFunction(NWNX_Rename, sFunc);
    return NWNX_GetReturnValueString(NWNX_Rename, sFunc);
}

void NWNX_Rename_ClearPCNameOverride(object oTarget, object oObserver = OBJECT_INVALID, int clearAll = FALSE)
{
    string sFunc = "ClearPCNameOverride";

    NWNX_PushArgumentInt(NWNX_Rename, sFunc, clearAll);
    NWNX_PushArgumentObject(NWNX_Rename, sFunc, oObserver);
    NWNX_PushArgumentObject(NWNX_Rename, sFunc, oTarget);

    NWNX_CallFunction(NWNX_Rename, sFunc);
}
