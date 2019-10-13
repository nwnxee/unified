# Rename Plugin Reference

## Description

This plugin facilitates renaming, overriding and customization of player names.

Script function | Description  
----------------|-------------
NWNX_Rename_SetPCNameOverride() | Set a PCs floaty/chat name(sPrefix+sNewName+sSuffix) and name (sNewName) on the player list. If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_OVERRIDE the player name will change to (sNewName) on tells. If (iPlayerNameState) is set to NWNX_RENAME_PLAYERNAME_OBFUSCATE the player name will be set to a random string.
NWNX_Rename_GetPCNameOverride() | Gets the PCs name as seen by a specified target or all clients.

If `iPlayerNameState` is set to `NWNX_RENAME_PLAYERNAME_DEFAULT` the player name will be untouched. DMs and the player themselves will still see their original player name regardless of option set. Will not persist through saving, resets or logout.

If a target object is specified, only that target will see the PCs name as defined. This overrides a global rename.

Due to the conflict with this plugin and the Tweaks plugin to hide classes on the module character listing, this module also provides that functionality.

## Environment Variables

| Variable Name | Value | Default | Notes |
| -------------   | :----: | :----: |----------------------------- |
| `NWNX_RENAME_ON_MODULE_CHAR_LIST` | 0-3 | 0 | This is the listing of players from the character selection screen before entering the server. Setting the value to 1 overrides their names if a global rename has been set, 2 also hides class information, 3 hides class information but keeps names as their original.
| `NWNX_RENAME_ON_PLAYER_LIST` | true or false | true | Renames the player name on the player list as well.
| `NWNX_RENAME_ALLOW_DM` | true or false | false | DM observers will see global or personal overrides as well as being able to have their own name overridden for other observers.
| `NWNX_RENAME_ANONYMOUS_NAME` | string | Someone | When using `NWNX_Rename_SetPCNameOverride` with `NWNX_RENAME_PLAYERNAME_ANONYMOUS` this is the string used for the \<PlayerName\>

## Sample Include

```c
#include "nwnx_rename"
// For GetPlayerID function, set to your own lib that returns the unique player ID for your PW
// Then replace GetPlayerID in this include to whatever your call is.
#include "inc_pc_db"

const string UNKNOWN_PLAYER = "Unknown";
const string UNKNOWN_PLAYER_PREFIX = "<c~~~>";
const string UNKNOWN_PLAYER_SUFFIX = "</c>";

const string RENAMED_PLAYER_PREFIX = "";
const string RENAMED_PLAYER_SUFFIX = "";

// This should be fired on client enter as soon as possible, it loads all
// the dynamic names for the PC for the other PCs connected and the dynamic
// name for the other PCs for the connecting PC.
void LoadNamesForPC(object oPC);

// Stores the info on the database
void SetDynamicNameDB(object oPC, object oOtherPC, string sName, int iDub = 0);

// Returns whether the PC has dubbed the target PC already
int GetDynamicNameIsDubbed(object oPC, object oTarget);

// We use three custom commands =c intro, =c introparty and =c introarea (20m radius)
// So the player could do =c intro Joe and the nearest player would then see the PCs
// name as Joe
void IntroducePlayers(object oPC, object oTarget, string sName, int iType = 0);

// Dub works the other way, a PC can dub someone what they wish to see as their
// name. =c dub Joseph (nearest PC) would then change the target's name for the
// caller to Joseph.
void DubPlayer(object oPC, object oTarget, string sName);

void LoadNamesForPC(object oPC)
{
    NWNX_Rename_SetPCNameOverride(oPC, UNKNOWN_PLAYER, UNKNOWN_PLAYER_PREFIX,
                UNKNOWN_PLAYER_SUFFIX, NWNX_RENAME_PLAYERNAME_OBFUSCATE);

    int nPCID = GetPlayerID(oPC);
    object oOtherPC = GetFirstPC();
    while (GetIsObjectValid(oOtherPC))
    {
        if (oOtherPC != oPC)
        {
            int nOtherPCID = GetPlayerID(oOtherPC);
            string sSQL = "SELECT name FROM dynamic_names WHERE pc1 = ? AND pc2 = ?";
            NWNX_SQL_PrepareQuery(sSQL);
            NWNX_SQL_PreparedInt(0, nPCID);
            NWNX_SQL_PreparedInt(1, nOtherPCID);
            NWNX_SQL_ExecutePreparedQuery();
            if (NWNX_SQL_ReadyToReadNextRow())
            {
                NWNX_SQL_ReadNextRow();
                NWNX_Rename_SetPCNameOverride(oOtherPC, NWNX_SQL_ReadDataInActiveRow(0),
                            RENAMED_PLAYER_PREFIX, RENAMED_PLAYER_SUFFIX, NWNX_RENAME_PLAYERNAME_OVERRIDE, oPC);
            }
            NWNX_SQL_PrepareQuery(sSQL);
            NWNX_SQL_PreparedInt(0, nOtherPCID);
            NWNX_SQL_PreparedInt(1, nPCID);
            NWNX_SQL_ExecutePreparedQuery();
            if (NWNX_SQL_ReadyToReadNextRow())
            {
                NWNX_SQL_ReadNextRow();
                NWNX_Rename_SetPCNameOverride(oPC, NWNX_SQL_ReadDataInActiveRow(0),
                            RENAMED_PLAYER_PREFIX, RENAMED_PLAYER_SUFFIX, NWNX_RENAME_PLAYERNAME_OVERRIDE, oOtherPC);
            }
        }
        oOtherPC = GetNextPC();
    }
}

void SetDynamicNameDB(object oPC, object oOtherPC, string sName, int iDub = 0)
{
    int nPC1ID = GetPlayerID(oPC);
    int nPC2ID = GetPlayerID(oOtherPC);
    if (nPC1ID && nPC2ID)
    {
        string sSQL = "INSERT INTO dynamic_names (pc1, pc2, name, dub) "+
                      "VALUES (?, ?, ?, ?) ON DUPLICATE KEY UPDATE name = ?, dub = ?";
        NWNX_SQL_PrepareQuery(sSQL);
        NWNX_SQL_PreparedInt(0, nPC2ID);
        NWNX_SQL_PreparedInt(1, nPC1ID);
        NWNX_SQL_PreparedString(2, sName);
        NWNX_SQL_PreparedInt(3, iDub);
        NWNX_SQL_PreparedString(4, sName);
        NWNX_SQL_PreparedInt(5, iDub);
        NWNX_SQL_ExecutePreparedQuery();
    }
}

int GetDynamicNameIsDubbed(object oPC, object oTarget)
{
    int nPCID = GetPlayerID(oPC);
    int nPCID2 = GetPlayerID(oTarget);
    int iDub = 0;
    string sSQL = "SELECT dub FROM dynamic_names WHERE pc1 = ? AND pc2 = ?";
    NWNX_SQL_PrepareQuery(sSQL);
    NWNX_SQL_PreparedInt(0, nPCID);
    NWNX_SQL_PreparedInt(1, nPCID2);
    NWNX_SQL_ExecutePreparedQuery();
    if (NWNX_SQL_ReadyToReadNextRow())
    {
        NWNX_SQL_ReadNextRow();
        iDub = StringToInt(NWNX_SQL_ReadDataInActiveRow(0));
    }
    return iDub;
}

void IntroducePlayers(object oPC, object oTarget, string sName, int iType = 0)
{
    int nPC1ID = GetPlayerID(oPC);
    int nPC2ID = GetPlayerID(oTarget);
    if (nPC1ID == nPC2ID)
        return;
    int iDub = GetDynamicNameIsDubbed(oTarget, oPC);
    string sMyName = NWNX_Rename_GetPCNameOverride(oPC, oTarget);
    if (sMyName == "")
        sMyName = "Someone";
    string sTargetName = NWNX_Rename_GetPCNameOverride(oTarget, oPC);
    if (sTargetName == "")
        sTargetName = "Someone";
    if (!iType)
        SendMessageToPC(oPC, "Introducing yourself to " + sTargetName + " as " + sName + ".");
    if (iDub)
        SendMessageToPC(oTarget, "Someone wants you to know them as " + sName + " but you've "+
                                 "already dubbed them " + sMyName + " so it's ignored.");
    else
    {
        SendMessageToPC(oTarget, sMyName + " wants you to know them as " + sName + ".");
        NWNX_Rename_SetPCNameOverride(oPC, sName, RENAMED_PLAYER_PREFIX,
                        RENAMED_PLAYER_SUFFIX, NWNX_RENAME_PLAYERNAME_OVERRIDE, oTarget);
        SetDynamicNameDB(oPC, oTarget, sName);
    }
}

void DubPlayer(object oPC, object oTarget, string sName)
{
    string sTargetName = NWNX_Rename_GetPCNameOverride(oTarget, oPC);
    if (sTargetName == "")
        sTargetName = "Someone";
    SendMessageToPC(oPC, sTargetName + " will now be known as " + sName + " to you.");
    NWNX_Rename_SetPCNameOverride(oTarget, sName, RENAMED_PLAYER_PREFIX,
                    RENAMED_PLAYER_SUFFIX, NWNX_RENAME_PLAYERNAME_OVERRIDE, oPC);
    SetDynamicNameDB(oTarget, oPC, sName, 1);
}

```

And a corresponding MySQL example DB structure:

```sql
CREATE TABLE `dynamic_names` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `pc1` mediumint(8) unsigned NOT NULL,
  `pc2` mediumint(8) unsigned NOT NULL,
  `name` varchar(40) NOT NULL,
  `dub` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `pair` (`pc1`,`pc2`),
  KEY `pc1` (`pc1`),
  KEY `pc2` (`pc2`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8

```