/// @addtogroup admin Administration
/// @brief Various admin related functions
/// @{
/// @file nwnx_admin.nss
#include "nwnx"

const string NWNX_Administration = "NWNX_Administration"; ///< @private

/// @name Administration Options
/// @anchor admin_opts
///
/// @{
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
/// @}

/// @name Administration Debug Types
/// @anchor admin_debug
///
/// @{
const int NWNX_ADMINISTRATION_DEBUG_COMBAT                      = 0;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_DEBUG_SAVING_THROW                = 1;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_DEBUG_MOVEMENT_SPEED              = 2;  // TRUE/FALSE
const int NWNX_ADMINISTRATION_DEBUG_HIT_DIE                     = 3;  // TRUE/FALSE
/// @}

/// @brief Gets the current player password.
/// @return The current player password.
string NWNX_Administration_GetPlayerPassword();

/// @brief Sets the password for players to login.
/// @param password The password to use.
void NWNX_Administration_SetPlayerPassword(string password);

/// @brief Clears the player password required to login.
void NWNX_Administration_ClearPlayerPassword();

/// @brief Gets the current DM password.
/// @return The current DM password.
string NWNX_Administration_GetDMPassword();

/// @brief Sets the password for DMs to login.
/// @param password The password to use.
void NWNX_Administration_SetDMPassword(string password);

/// @brief Signals the server to immediately shut down.
void NWNX_Administration_ShutdownServer();

/// @brief Deletes the player character from the servervault
///
/// The PC will be immediately booted from the game with a "Delete Character" message
///
/// @param oPC The player to delete.
/// @param bPreserveBackup If true, it will leave the file on server, only appending ".deleted0" to the bic filename.
void NWNX_Administration_DeletePlayerCharacter(object oPC, int bPreserveBackup = TRUE);

/// @brief Bans the provided IP.
/// @param ip The IP Address to ban.
void NWNX_Administration_AddBannedIP(string ip);

/// @brief Removes the ban on the provided IP.
/// @param ip The IP Address to unban.
void NWNX_Administration_RemoveBannedIP(string ip);

/// @brief Bans the provided Public CD Key.
/// @param key The Public CD Key to ban.
void NWNX_Administration_AddBannedCDKey(string key);

/// @brief Removes the ban on the provided Public CD Key.
/// @param key The Public CD Key to unban.
void NWNX_Administration_RemoveBannedCDKey(string key);

/// @brief Bans the provided playername.
/// @param playerName The player name (community name) to ban.
/// @warning A user can change their playername at will.
void NWNX_Administration_AddBannedPlayerName(string playerName);

/// @brief Removes the ban on the provided playername.
/// @param playerName The player name (community name) to unban.
void NWNX_Administration_RemoveBannedPlayerName(string playerName);

/// @brief Get a list of all banned IPs/Keys/names as a string.
/// @return A string with a listing of the banned IPs/Keys/names.
string NWNX_Administration_GetBannedList();

/// @brief Set the module's name as shown to the serverlist.
/// @param name The name to give the module.
void NWNX_Administration_SetModuleName(string name);

/// @brief Set the server's name as shown to the serverlist.
/// @param name The name to give the server.
void NWNX_Administration_SetServerName(string name);

/// @brief Returns the server's name as shown to the serverlist.
string NWNX_Administration_GetServerName();

/// @brief Get an @ref admin_opts "Administration Option" value.
/// @param option An @ref admin_opts "Administration Option".
/// @return The current setting for the supplied option from @ref admin_opts "Administration Options".
int NWNX_Administration_GetPlayOption(int option);

/// @brief Set an @ref admin_opts "Administration Options" to a value.
/// @param option The option to adjust from @ref admin_opts "Administration Options".
/// @param value The new value for the option.
void NWNX_Administration_SetPlayOption(int option, int value);

/// @brief Delete the TURD of playerName + characterName.
///
/// At times a PC may get stuck in a permanent crash loop when attempting to log
/// in. This function allows administrators to delete their Temporary User
/// Resource Data where the PC's current location is stored allowing them to log
/// into the starting area.
///
/// @param playerName The community (login name).
/// @param characterName The character name.
/// @return Returns TRUE if successful
int NWNX_Administration_DeleteTURD(string playerName, string characterName);

/// @brief Get an @ref admin_debug "Administration Debug Type" value.
/// @param type An @ref admin_debug "Administration Debug Type".
/// @return The current value for the supplied debug type from @ref admin_debug "Administration Debug Types".
int NWNX_Administration_GetDebugValue(int type);

/// @brief Set an @ref admin_debug "Administration Debug Type" to a value.
/// @param type The debug type to adjust from @ref admin_debug "Administration Debug Types".
/// @param state The new state for the debug type, TRUE or FALSE
void NWNX_Administration_SetDebugValue(int type, int state);

/// @brief Reload all rules (2da stuff etc).
/// @warning DANGER, DRAGONS. Bad things may or may not happen.
void NWNX_Administration_ReloadRules();

/// @}

string NWNX_Administration_GetPlayerPassword()
{
    string sFunc = "GetPlayerPassword";

    NWNX_CallFunction(NWNX_Administration, sFunc);
    return NWNX_GetReturnValueString(NWNX_Administration, sFunc);
}

void NWNX_Administration_SetPlayerPassword(string password)
{
    string sFunc = "SetPlayerPassword";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, password);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}

void NWNX_Administration_ClearPlayerPassword()
{
    string sFunc = "ClearPlayerPassword";

    NWNX_CallFunction(NWNX_Administration, sFunc);
}

string NWNX_Administration_GetDMPassword()
{
    string sFunc = "GetDMPassword";

    NWNX_CallFunction(NWNX_Administration, sFunc);
    return NWNX_GetReturnValueString(NWNX_Administration, sFunc);
}

void NWNX_Administration_SetDMPassword(string password)
{
    string sFunc = "SetDMPassword";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, password);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}

void NWNX_Administration_ShutdownServer()
{
    string sFunc = "ShutdownServer";

    NWNX_CallFunction(NWNX_Administration, sFunc);
}

void NWNX_Administration_DeletePlayerCharacter(object oPC, int bPreserveBackup)
{
    string sFunc = "DeletePlayerCharacter";

    NWNX_PushArgumentInt(NWNX_Administration, sFunc, bPreserveBackup);
    NWNX_PushArgumentObject(NWNX_Administration, sFunc, oPC);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}

void NWNX_Administration_AddBannedIP(string ip)
{
    string sFunc = "AddBannedIP";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, ip);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}
void NWNX_Administration_RemoveBannedIP(string ip)
{
    string sFunc = "RemoveBannedIP";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, ip);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}
void NWNX_Administration_AddBannedCDKey(string key)
{
    string sFunc = "AddBannedCDKey";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, key);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}
void NWNX_Administration_RemoveBannedCDKey(string key)
{
    string sFunc = "RemoveBannedCDKey";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, key);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}
void NWNX_Administration_AddBannedPlayerName(string playerName)
{
    string sFunc = "AddBannedPlayerName";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, playerName);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}
void NWNX_Administration_RemoveBannedPlayerName(string playerName)
{
    string sFunc = "RemoveBannedPlayerName";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, playerName);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}
string NWNX_Administration_GetBannedList()
{
    string sFunc = "GetBannedList";

    NWNX_CallFunction(NWNX_Administration, sFunc);
    return NWNX_GetReturnValueString(NWNX_Administration, sFunc);
}

void NWNX_Administration_SetModuleName(string name)
{
    string sFunc = "SetModuleName";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, name);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}

void NWNX_Administration_SetServerName(string name)
{
    string sFunc = "SetServerName";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, name);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}

string NWNX_Administration_GetServerName()
{
    string sFunc = "GetServerName";
    NWNX_CallFunction(NWNX_Administration, sFunc);
    return NWNX_GetReturnValueString(NWNX_Administration, sFunc);
}

int NWNX_Administration_GetPlayOption(int option)
{
    string sFunc = "GetPlayOption";

    NWNX_PushArgumentInt(NWNX_Administration, sFunc, option);
    NWNX_CallFunction(NWNX_Administration, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Administration, sFunc);
}

void NWNX_Administration_SetPlayOption(int option, int value)
{
    string sFunc = "SetPlayOption";

    NWNX_PushArgumentInt(NWNX_Administration, sFunc, value);
    NWNX_PushArgumentInt(NWNX_Administration, sFunc, option);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}

int NWNX_Administration_DeleteTURD(string playerName, string characterName)
{
    string sFunc = "DeleteTURD";

    NWNX_PushArgumentString(NWNX_Administration, sFunc, characterName);
    NWNX_PushArgumentString(NWNX_Administration, sFunc, playerName);
    NWNX_CallFunction(NWNX_Administration, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Administration, sFunc);
}

int NWNX_Administration_GetDebugValue(int type)
{
    string sFunc = "GetDebugValue";

    NWNX_PushArgumentInt(NWNX_Administration, sFunc, type);
    NWNX_CallFunction(NWNX_Administration, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Administration, sFunc);
}

void NWNX_Administration_SetDebugValue(int type, int state)
{
    string sFunc = "SetDebugValue";

    NWNX_PushArgumentInt(NWNX_Administration, sFunc, state);
    NWNX_PushArgumentInt(NWNX_Administration, sFunc, type);
    NWNX_CallFunction(NWNX_Administration, sFunc);
}

void NWNX_Administration_ReloadRules()
{
    string sFunc = "ReloadRules";

    NWNX_CallFunction(NWNX_Administration, sFunc);
}
