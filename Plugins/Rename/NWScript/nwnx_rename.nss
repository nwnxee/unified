/// @addtogroup rename Rename
/// @brief Facilitates renaming, overriding and customization of player names.
/// @{
/// @file nwnx_rename.nss

const string NWNX_Rename = "NWNX_Rename"; ///< @private

/// @anchor rename_comm_name_override_type
/// @name Community Name Override Type
/// @{
const int NWNX_RENAME_PLAYERNAME_DEFAULT = 0; ///< Don't rename
const int NWNX_RENAME_PLAYERNAME_OBFUSCATE = 1; ///< Generate random string for Community Name
const int NWNX_RENAME_PLAYERNAME_OVERRIDE = 2; ///< Use character name specified
const int NWNX_RENAME_PLAYERNAME_ANONYMOUS = 3; ///< Use the value of the NWNX_RENAME_ANONYMOUS_NAME environment variable
///@}

/// @brief Set a PC's character name and community name on the player list.
/// @param oTarget The PC whose name is being overridden.
/// @param sNewName The new name.
/// @param sPrefix The prefix for their character name, sometimes used for a color code.
/// @param sSuffix The suffix for their character name.
/// @param iPlayerNameState How to change the Community Name, use @ref rename_comm_name_override_type "Community Name Override Type".
/// @param oObserver If specified, the character name will appear to that specific observer as set, this overrides a global setting.
/// @note Will not persist through saving, resets or logout.
void NWNX_Rename_SetPCNameOverride(object oTarget, string sNewName, string sPrefix = "" , string sSuffix = "" ,
                                   int iPlayerNameState = NWNX_RENAME_PLAYERNAME_DEFAULT, object oObserver = OBJECT_INVALID);

/// @brief Gets a PC's name as overridden.
/// @param oTarget The PC whose name to query.
/// @param oObserver The specific observer.
/// @return The PC's name as overridden either per observer or globally.
/// @note If you wish to get a PC's true name use `GetName(oPC, TRUE)`.
string NWNX_Rename_GetPCNameOverride(object oTarget, object oObserver = OBJECT_INVALID);

/// @brief Clears an overridden PC Name.
/// @param oTarget The PC whose overridden name to clear, use OBJECT_INVALID if you're clearing all overrides for an observer.
/// @param oObserver The observer whose overriden name of oTarget is being cleared.
/// If oTarget is OBJECT_INVALID then all overrides are cleared.
/// @param clearAll If true, both the global and personal overrides will be cleared for that target PC.
/// Requires oObserver be OBJECT_INVALID.
void NWNX_Rename_ClearPCNameOverride(object oTarget, object oObserver = OBJECT_INVALID, int clearAll = FALSE);

/// @}

void NWNX_Rename_SetPCNameOverride(object oTarget, string sNewName, string sPrefix = "" , string sSuffix = "" ,
                                   int iPlayerNameState = NWNX_RENAME_PLAYERNAME_DEFAULT, object oObserver = OBJECT_INVALID)
{
    NWNXPushObject(oObserver);
    NWNXPushInt(iPlayerNameState);
    NWNXPushString(sSuffix);
    NWNXPushString(sPrefix);
    NWNXPushString(sNewName);
    NWNXPushObject(oTarget);
    NWNXCall(NWNX_Rename, "SetPCNameOverride");
}
string NWNX_Rename_GetPCNameOverride(object oTarget, object oObserver = OBJECT_INVALID)
{
    NWNXPushObject(oObserver);
    NWNXPushObject(oTarget);
    NWNXCall(NWNX_Rename, "GetPCNameOverride");
    return NWNXPopString();
}

void NWNX_Rename_ClearPCNameOverride(object oTarget, object oObserver = OBJECT_INVALID, int clearAll = FALSE)
{
    NWNXPushInt(clearAll);
    NWNXPushObject(oObserver);
    NWNXPushObject(oTarget);
    NWNXCall(NWNX_Rename, "ClearPCNameOverride");
}
