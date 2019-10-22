/// @addtogroup rename Rename
/// @brief Facilitates renaming, overriding and customization of player names.
/// @{
/// @file nwnx_rename.nss
#include "nwnx"

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
