#include "nwnx"

const int NWNX_ADMINISTRATION_OPTION_ALL_KILLABLE               = 0;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_NON_PARTY_KILLABLE         = 1;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_REQUIRE_RESURRECTION       = 2;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_LOSE_STOLEN_ITEMS          = 3;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_LOSE_ITEMS                 = 4;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_LOSE_EXP                   = 5;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_LOSE_GOLD                  = 6;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_LOSE_GOLD_NUM              = 7;
const int NWNX_ADMINISTRATION_OPTION_LOSE_EXP_NUM               = 8;
const int NWNX_ADMINISTRATION_OPTION_LOSE_ITEMS_NUM             = 9;
const int NWNX_ADMINISTRATION_OPTION_PVP_SETTING                = 10; // 0 = No PVP, 1 = Party PVP, 2 = Full PVP
const int NWNX_ADMINISTRATION_OPTION_PAUSE_AND_PLAY             = 11; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_ONE_PARTY_ONLY             = 12; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_ENFORCE_LEGAL_CHARACTERS   = 13; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_ITEM_LEVEL_RESTRICTIONS    = 14; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_CDKEY_BANLIST_ALLOWLIST    = 15; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_DISALLOW_SHOUTING          = 16; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_SHOW_DM_JOIN_MESSAGE       = 17; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_BACKUP_SAVED_CHARACTERS    = 18; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_AUTO_FAIL_SAVE_ON_1        = 19; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_VALIDATE_SPELLS            = 20; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_EXAMINE_EFFECTS            = 21; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_EXAMINE_CHALLENGE_RATING   = 22; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_USE_MAX_HITPOINTS          = 23; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_RESTORE_SPELLS_USES        = 24; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_RESET_ENCOUNTER_SPAWN_POOL = 25; // TRUE/FALSE
const int NWNX_ADMINISTRATION_OPTION_HIDE_HITPOINTS_GAINED      = 26; // TRUE/FALSE

// Gets, sets, and clears the current player password.
// Note that this password can be an empty string.
string NWNX_Administration_GetPlayerPassword();
void NWNX_Administration_SetPlayerPassword(string password);
void NWNX_Administration_ClearPlayerPassword();

// Gets and sets the current DM password.
// Note that this password can be an empty string.
string NWNX_Administration_GetDMPassword();
void NWNX_Administration_SetDMPassword(string password);

// Signals the server to immediately shut down.
void NWNX_Administration_ShutdownServer();

// DEPRECATED: Use BootPC() native function
// Boots the provided player from the server with the provided strref as message.
void NWNX_Administration_BootPCWithMessage(object pc, int strref);

// Deletes the player character from the servervault
//    bPreserveBackup - if true, it will leave the file on server,
//                      only appending ".deleted0" to the bic filename.
// The PC will be immediately booted from the game with a "Delete Character" message
void NWNX_Administration_DeletePlayerCharacter(object pc, int bPreserveBackup = TRUE);

// Ban a given IP - get via GetPCIPAddress()
void NWNX_Administration_AddBannedIP(string ip);
void NWNX_Administration_RemoveBannedIP(string ip);
// Ban a given public cdkey - get via GetPCPublicCDKey
void NWNX_Administration_AddBannedCDKey(string key);
void NWNX_Administration_RemoveBannedCDKey(string key);
// Ban a given player name - get via GetPCPlayerName
// NOTE: Players can easily change their names
void NWNX_Administration_AddBannedPlayerName(string playername);
void NWNX_Administration_RemoveBannedPlayerName(string playername);
// Get a list of all banned IPs/Keys/names as a string
string NWNX_Administration_GetBannedList();

// Set the module's name as shown to the serverlist
void NWNX_Administration_SetModuleName(string name);
// Set the server's name as shown to the serverlist
void NWNX_Administration_SetServerName(string name);

// Get a NWNX_ADMINISTRATION_OPTION_* value
int NWNX_Administration_GetPlayOption(int option);
// Set a NWNX_ADMINISTRATION_OPTION_* to value
void NWNX_Administration_SetPlayOption(int option, int value);

// Delete the TURD of playerName + characterName
void NWNX_Administration_DeleteTURD(string playerName, string characterName);


string NWNX_Administration_GetPlayerPassword()
{
    NWNX_CallFunction("NWNX_Administration", "GET_PLAYER_PASSWORD");
    return NWNX_GetReturnValueString("NWNX_Administration", "GET_PLAYER_PASSWORD");
}

void NWNX_Administration_SetPlayerPassword(string password)
{
    NWNX_PushArgumentString("NWNX_Administration", "SET_PLAYER_PASSWORD", password);
    NWNX_CallFunction("NWNX_Administration", "SET_PLAYER_PASSWORD");
}

void NWNX_Administration_ClearPlayerPassword()
{
    NWNX_CallFunction("NWNX_Administration", "CLEAR_PLAYER_PASSWORD");
}

string NWNX_Administration_GetDMPassword()
{
    NWNX_CallFunction("NWNX_Administration", "GET_DM_PASSWORD");
    return NWNX_GetReturnValueString("NWNX_Administration", "GET_DM_PASSWORD");
}

void NWNX_Administration_SetDMPassword(string password)
{
    NWNX_PushArgumentString("NWNX_Administration", "SET_DM_PASSWORD", password);
    NWNX_CallFunction("NWNX_Administration", "SET_DM_PASSWORD");
}

void NWNX_Administration_ShutdownServer()
{
    NWNX_CallFunction("NWNX_Administration", "SHUTDOWN_SERVER");
}

void NWNX_Administration_BootPCWithMessage(object pc, int strref)
{
    WriteTimestampedLogEntry("NWNX_Administration: BootPCWithMessage() is deprecated. Use native BootPC() instead");
    BootPC(pc, GetStringByStrRef(strref));
}

void NWNX_Administration_DeletePlayerCharacter(object pc, int bPreserveBackup)
{
    NWNX_PushArgumentInt("NWNX_Administration", "DELETE_PLAYER_CHARACTER", bPreserveBackup);
    NWNX_PushArgumentObject("NWNX_Administration", "DELETE_PLAYER_CHARACTER", pc);
    NWNX_CallFunction("NWNX_Administration", "DELETE_PLAYER_CHARACTER");
}

void NWNX_Administration_AddBannedIP(string ip)
{
    NWNX_PushArgumentString("NWNX_Administration", "ADD_BANNED_IP", ip);
    NWNX_CallFunction("NWNX_Administration", "ADD_BANNED_IP");
}
void NWNX_Administration_RemoveBannedIP(string ip)
{
    NWNX_PushArgumentString("NWNX_Administration", "REMOVE_BANNED_IP", ip);
    NWNX_CallFunction("NWNX_Administration", "REMOVE_BANNED_IP");
}
void NWNX_Administration_AddBannedCDKey(string key)
{
    NWNX_PushArgumentString("NWNX_Administration", "ADD_BANNED_CDKEY", key);
    NWNX_CallFunction("NWNX_Administration", "ADD_BANNED_CDKEY");
}
void NWNX_Administration_RemoveBannedCDKey(string key)
{
    NWNX_PushArgumentString("NWNX_Administration", "REMOVE_BANNED_CDKEY", key);
    NWNX_CallFunction("NWNX_Administration", "REMOVE_BANNED_CDKEY");
}
void NWNX_Administration_AddBannedPlayerName(string playername)
{
    NWNX_PushArgumentString("NWNX_Administration", "ADD_BANNED_PLAYER_NAME", playername);
    NWNX_CallFunction("NWNX_Administration", "ADD_BANNED_PLAYER_NAME");
}
void NWNX_Administration_RemoveBannedPlayerName(string playername)
{
    NWNX_PushArgumentString("NWNX_Administration", "REMOVE_BANNED_PLAYER_NAME", playername);
    NWNX_CallFunction("NWNX_Administration", "REMOVE_BANNED_PLAYER_NAME");
}
string NWNX_Administration_GetBannedList()
{
    NWNX_CallFunction("NWNX_Administration", "GET_BANNED_LIST");
    return NWNX_GetReturnValueString("NWNX_Administration", "GET_BANNED_LIST");
}


void NWNX_Administration_SetModuleName(string name)
{
    NWNX_PushArgumentString("NWNX_Administration", "SET_MODULE_NAME", name);
    NWNX_CallFunction("NWNX_Administration", "SET_MODULE_NAME");
}

void NWNX_Administration_SetServerName(string name)
{
    NWNX_PushArgumentString("NWNX_Administration", "SET_SERVER_NAME", name);
    NWNX_CallFunction("NWNX_Administration", "SET_SERVER_NAME");
}

int NWNX_Administration_GetPlayOption(int option)
{
    NWNX_PushArgumentInt("NWNX_Administration", "GET_PLAY_OPTION", option);
    NWNX_CallFunction("NWNX_Administration", "GET_PLAY_OPTION");

    return NWNX_GetReturnValueInt("NWNX_Administration", "GET_PLAY_OPTION");
}

void NWNX_Administration_SetPlayOption(int option, int value)
{
    NWNX_PushArgumentInt("NWNX_Administration", "SET_PLAY_OPTION", value);
    NWNX_PushArgumentInt("NWNX_Administration", "SET_PLAY_OPTION", option);
    NWNX_CallFunction("NWNX_Administration", "SET_PLAY_OPTION");
}

void NWNX_Administration_DeleteTURD(string playerName, string characterName)
{
    NWNX_PushArgumentString("NWNX_Administration", "DELETE_TURD", characterName);
    NWNX_PushArgumentString("NWNX_Administration", "DELETE_TURD", playerName);
    NWNX_CallFunction("NWNX_Administration", "DELETE_TURD");
}
