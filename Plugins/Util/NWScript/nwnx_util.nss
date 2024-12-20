/// @addtogroup util Util
/// @brief Provides various utility functions that don't have a better home
/// @{
/// @file nwnx_util.nss

const string NWNX_Util = "NWNX_Util"; ///< @private

/// @name Resref Types
/// @anchor resref_types
/// Constants for the various types of resrefs.
///
/// @{
const int NWNX_UTIL_RESREF_TYPE_NSS       = 2009;
const int NWNX_UTIL_RESREF_TYPE_NCS       = 2010;
const int NWNX_UTIL_RESREF_TYPE_AREA_ARE  = 2012;
const int NWNX_UTIL_RESREF_TYPE_TWODA     = 2017;
const int NWNX_UTIL_RESREF_TYPE_AREA_GIT  = 2023;
const int NWNX_UTIL_RESREF_TYPE_ITEM      = 2025;
const int NWNX_UTIL_RESREF_TYPE_CREATURE  = 2027;
const int NWNX_UTIL_RESREF_TYPE_DIALOG    = 2029;
const int NWNX_UTIL_RESREF_TYPE_TRIGGER   = 2032;
const int NWNX_UTIL_RESREF_TYPE_SOUND     = 2035;
const int NWNX_UTIL_RESREF_TYPE_ENCOUNTER = 2040;
const int NWNX_UTIL_RESREF_TYPE_DOOR      = 2042;
const int NWNX_UTIL_RESREF_TYPE_PLACEABLE = 2044;
const int NWNX_UTIL_RESREF_TYPE_STORE     = 2051;
const int NWNX_UTIL_RESREF_TYPE_WAYPOINT  = 2058;
///@}

/// @brief A world time struct
struct NWNX_Util_WorldTime
{
    int nCalendarDay; ///< The calendar day
    int nTimeOfDay; ///< The time of day
};

/// @brief A high resolution timestamp
struct NWNX_Util_HighResTimestamp
{
    int seconds; ///< Seconds since epoch
    int microseconds; ///< Microseconds
};

/// @brief Gets the name of the currently executing script.
/// @note If depth is > 0, it will return the name of the script that called this one via ExecuteScript().
/// @param depth to seek the executing script.
/// @return The name of the currently executing script.
string NWNX_Util_GetCurrentScriptName(int depth = 0);

/// @brief Gets a string that contains the ascii table.
/// @note The character at index 0 is a space.
/// @return A string that contains all characters at their position (e.g. 'A' at 65).
string NWNX_Util_GetAsciiTableString();

/// @brief Gets an integer hash of a string.
/// @param str The string to hash.
/// @return The hashed string as an integer.
int NWNX_Util_Hash(string str);

/// @brief Gets the last modified timestamp (mtime) of the module file in seconds.
/// @return The mtime of the module file.
int NWNX_Util_GetModuleMtime();

/// @brief Gets the module short file name.
/// @return The module file as a string.
string NWNX_Util_GetModuleFile();

/// @brief Gets the value of customTokenNumber.
/// @param customTokenNumber The token number to query.
/// @return The string representation of the token value.
string NWNX_Util_GetCustomToken(int customTokenNumber);

/// @brief Convert an effect type to an itemproperty type.
/// @param e The effect to convert to an itemproperty.
/// @return The converted itemproperty.
itemproperty NWNX_Util_EffectToItemProperty(effect e);

/// @brief Convert an itemproperty type to an effect type.
/// @param ip The itemproperty to convert to an effect.
/// @return The converted effect.
effect NWNX_Util_ItemPropertyToEffect(itemproperty ip);

/// @brief Strip any color codes from a string.
/// @param str The string to strip of color.
/// @return The new string without any color codes.
string NWNX_Util_StripColors(string str);

/// @brief Retrieves an environment variable.
/// @param sVarname The environment variable to query.
/// @return The value of the environment variable.
string NWNX_Util_GetEnvironmentVariable(string sVarname);

/// @brief Gets the module real life minutes per in game hour.
/// @return The minutes per hour.
int NWNX_Util_GetMinutesPerHour();

/// @brief Set module real life minutes per in game hour.
/// @param minutes The minutes per hour.
void NWNX_Util_SetMinutesPerHour(int minutes);

/// @anchor util_encode_url
/// @brief Encodes a string for usage in a URL.
/// @param str The string to encode for a URL.
/// @return The url encoded string.
string NWNX_Util_EncodeStringForURL(string str);

/// @brief Get the first resref of nType.
/// @param nType A @ref resref_types "Resref Type".
/// @param sRegexFilter Lets you filter out resrefs using a regexfilter.
/// For example: **nwnx_.\*** gets you all scripts prefixed with nwnx_
/// when using the NSS resref type.
/// @param bModuleResourcesOnly If TRUE only custom resources will be returned.
/// @return The first resref found or "" if none is found.
string NWNX_Util_GetFirstResRef(int nType, string sRegexFilter = "", int bModuleResourcesOnly = TRUE);

/// @brief Get the next resref.
/// @return The next resref found or "" if none is found.
string NWNX_Util_GetNextResRef();

/// @brief Get the last created object.
/// @param nObjectType Does not take the NWScript OBJECT_TYPE_* constants.
/// Use NWNX_Consts_TranslateNWScriptObjectType() to get their NWNX equivalent.
/// @param nNthLast The nth last object created.
/// @return The last created object. On error, this returns OBJECT_INVALID.
object NWNX_Util_GetLastCreatedObject(int nObjectType, int nNthLast = 1);

/// @brief Compiles and adds a script to the UserDirectory/nwnx folder, or to the location of sAlias.
/// @note Will override existing scripts that are in the module.
/// @param sFileName The script filename without extension, 16 or less characters.
/// @param sScriptData The script data to compile
/// @param bWrapIntoMain Set to TRUE to wrap sScriptData into void main(){}.
/// @param sAlias The alias of the resource directory to add the ncs file to. Default: UserDirectory/nwnx
/// @return "" on success, or the compilation error.
string NWNX_Util_AddScript(string sFileName, string sScriptData, int bWrapIntoMain = FALSE, string sAlias = "NWNX");

/// @brief Adds a nss file to the UserDirectory/nwnx folder, or to the location of sAlias.
/// @note Will override existing nss files that are in the module
/// @param sFileName The script filename without extension, 16 or less characters.
/// @param sContents The contents of the nss file
/// @param sAlias The alias of the resource directory to add the nss file to. Default: UserDirectory/nwnx
/// @return TRUE on success.
int NWNX_Util_AddNSSFile(string sFileName, string sContents, string sAlias = "NWNX");

/// @brief Remove sFileName of nType from the UserDirectory/nwnx folder, or from the location of sAlias.
/// @param sFileName The filename without extension, 16 or less characters.
/// @param nType The @ref resref_types "Resref Type".
/// @param sAlias The alias of the resource directory to remove the file from. Default: UserDirectory/nwnx
/// @return TRUE on success.
int NWNX_Util_RemoveNWNXResourceFile(string sFileName, int nType, string sAlias = "NWNX");

/// @brief Set the NWScript instruction limit.
/// @param nInstructionLimit The new limit or -1 to reset to default.
void NWNX_Util_SetInstructionLimit(int nInstructionLimit);

/// @brief Get the NWScript instruction limit.
int NWNX_Util_GetInstructionLimit();

/// @brief Set the number of NWScript instructions currently executed.
/// @param nInstructions The number of instructions, must be >= 0.
void NWNX_Util_SetInstructionsExecuted(int nInstructions);

/// @brief Get the number of NWScript instructions currently executed.
int NWNX_Util_GetInstructionsExecuted();

/// @brief Register a server console command that will execute a script chunk.
/// @note Example usage: NWNX_Util_RegisterServerConsoleCommand("test", "PrintString(\"Test Command -> Args: $args\");");
/// @param sCommand The name of the command.
/// @param sScriptChunk The script chunk to run. You can use $args to get the console command arguments.
/// @return TRUE on success.
int NWNX_Util_RegisterServerConsoleCommand(string sCommand, string sScriptChunk);

/// @brief Unregister a server console command that was registered with NWNX_Util_RegisterServerConsoleCommand().
/// @param sCommand The name of the command.
void NWNX_Util_UnregisterServerConsoleCommand(string sCommand);

/// @brief Gets the server's current working user folder.
/// @return The absolute path of the server's home directory (-userDirectory)
string NWNX_Util_GetUserDirectory();

/// @brief Get the return value of the last run script with a StartingConditional
/// @return Return value of the last run script.
int NWNX_Util_GetScriptReturnValue();

/// @brief Create a door.
/// @param sResRef The ResRef of the door.
/// @param locLocation The location to create the door at.
/// @param sNewTag An optional new tag for the door.
/// @param nAppearanceType An optional index into doortypes.2da for appearance.
/// @return The door, or OBJECT_INVALID on failure.
object NWNX_Util_CreateDoor(string sResRef, location locLocation, string sNewTag = "", int nAppearanceType = -1);

/// @brief Set the object that will be returned by GetItemActivator.
/// @param oObject An object.
void NWNX_Util_SetItemActivator(object oObject);

/// @brief Get the world time as calendar day and time of day.
/// @note This function is useful for calculating effect expiry times.
/// @param fAdjustment An adjustment in seconds, 0.0f will return the current world time,
/// positive or negative values will return a world time in the future or past.
/// @return A NWNX_Util_WorldTime struct with the calendar day and time of day.
struct NWNX_Util_WorldTime NWNX_Util_GetWorldTime(float fAdjustment = 0.0f);

/// @brief Set a server-side resource override.
/// @param nResType A @ref resref_types "Resref Type".
/// @param sOldName The old resource name, 16 characters or less.
/// @param sNewName The new resource name or "" to clear a previous override, 16 characters or less.
void NWNX_Util_SetResourceOverride(int nResType, string sOldName, string sNewName);

/// @brief Get a server-side resource override.
/// @param nResType A @ref resref_types "Resref Type".
/// @param sName The name of the resource, 16 characters or less.
/// @return The resource override, or "" if one is not set.
string NWNX_Util_GetResourceOverride(int nResType, string sName);

/// @brief Get if a script param is set.
/// @param sParamName The script parameter name to check.
/// @return TRUE if the script param is set, FALSE if not or on error.
int NWNX_Util_GetScriptParamIsSet(string sParamName);

/// @brief Set the module dawn hour.
/// @param nDawnHour The new dawn hour
void NWNX_Util_SetDawnHour(int nDawnHour);

/// @brief Get the module dawn hour.
/// @return The dawn hour
int NWNX_Util_GetDawnHour();

/// @brief Set the module dusk hour.
/// @param nDuskHour The new dusk hour
void NWNX_Util_SetDuskHour(int nDuskHour);

/// @brief Get the module dusk hour.
/// @return The dusk hour
int NWNX_Util_GetDuskHour();

/// @return Returns the number of microseconds since midnight on January 1, 1970.
struct NWNX_Util_HighResTimestamp NWNX_Util_GetHighResTimeStamp();

/// @return Return name of a terminal, "" if not a TTY
string NWNX_Util_GetTTY();

/// @brief Set the currently running script event.
/// @param nEventID The ID of the event.
void NWNX_Util_SetCurrentlyRunningEvent(int nEventID);

/// @brief Calculate the levenshtein distance of two strings
/// @param sString The string to compare with.
/// @param sCompareTo The string to compare sString to.
/// @return The number of characters different between the compared strings.
int NWNX_Util_GetStringLevenshteinDistance(string sString, string sCompareTo);

/// @brief Sends a full object update of oObjectToUpdate to all clients
/// @param oObjectToUpdate The object to update
/// @param oPlayer The player for which the objects needs to update, OBJECT_INVALID for all players
void NWNX_Util_UpdateClientObject(object oObjectToUpdate, object oPlayer = OBJECT_INVALID);

/// @brief Clean a resource directory, deleting all files of nResType.
/// @param sAlias A resource directory alias, NWNX or one defined in the custom resource directory file.
/// @param nResType The type of file to delete or 0xFFFF for all types.
/// @return TRUE if successful, FALSE on error.
int NWNX_Util_CleanResourceDirectory(string sAlias, int nResType = 0xFFFF);

/// @brief Return the filename of the tlk file.
/// @return The name
string NWNX_Util_GetModuleTlkFile();

/// @brief Update a resource directory by having ResMan reindex it.
/// @param sAlias A resource directory alias, eg: TEMP
/// @return TRUE if successful, FALSE on error.
int NWNX_Util_UpdateResourceDirectory(string sAlias);

/// @}

string NWNX_Util_GetCurrentScriptName(int depth = 0)
{
    NWNXPushInt(depth);
    NWNXCall(NWNX_Util, "GetCurrentScriptName");
    return NWNXPopString();
}

string NWNX_Util_GetAsciiTableString()
{
    NWNXCall(NWNX_Util, "GetAsciiTableString");
    return NWNXPopString();
}

int NWNX_Util_Hash(string str)
{
    NWNXPushString(str);
    NWNXCall(NWNX_Util, "Hash");
    return NWNXPopInt();
}

int NWNX_Util_GetModuleMtime()
{
    NWNXCall(NWNX_Util, "GetModuleMtime");
    return NWNXPopInt();
}

string NWNX_Util_GetModuleFile()
{
    NWNXCall(NWNX_Util, "GetModuleFile");
    return NWNXPopString();
}

string NWNX_Util_GetCustomToken(int customTokenNumber)
{
    NWNXPushInt(customTokenNumber);
    NWNXCall(NWNX_Util, "GetCustomToken");
    return NWNXPopString();
}

itemproperty NWNX_Util_EffectToItemProperty(effect e)
{
    NWNXPushEffect(e);
    NWNXCall(NWNX_Util, "EffectTypeCast");
    return NWNXPopItemProperty();
}

effect NWNX_Util_ItemPropertyToEffect(itemproperty ip)
{
    NWNXPushItemProperty(ip);
    NWNXCall(NWNX_Util, "EffectTypeCast");
    return NWNXPopEffect();
}

string NWNX_Util_StripColors(string str)
{
    NWNXPushString(str);
    NWNXCall(NWNX_Util, "StripColors");
    return NWNXPopString();
}

string NWNX_Util_GetEnvironmentVariable(string sVarname)
{
    NWNXPushString(sVarname);
    NWNXCall(NWNX_Util, "GetEnvironmentVariable");
    return NWNXPopString();
}

int NWNX_Util_GetMinutesPerHour()
{
    NWNXCall(NWNX_Util, "GetMinutesPerHour");
    return NWNXPopInt();
}

void NWNX_Util_SetMinutesPerHour(int minutes)
{
    NWNXPushInt(minutes);
    NWNXCall(NWNX_Util, "SetMinutesPerHour");
}

string NWNX_Util_EncodeStringForURL(string sURL)
{
    NWNXPushString(sURL);
    NWNXCall(NWNX_Util, "EncodeStringForURL");
    return NWNXPopString();
}

string NWNX_Util_GetFirstResRef(int nType, string sRegexFilter = "", int bModuleResourcesOnly = TRUE)
{
    NWNXPushInt(bModuleResourcesOnly);
    NWNXPushString(sRegexFilter);
    NWNXPushInt(nType);
    NWNXCall(NWNX_Util, "GetFirstResRef");
    return NWNXPopString();
}

string NWNX_Util_GetNextResRef()
{
    NWNXCall(NWNX_Util, "GetNextResRef");
    return NWNXPopString();
}

object NWNX_Util_GetLastCreatedObject(int nObjectType, int nNthLast = 1)
{
    NWNXPushInt(nNthLast);
    NWNXPushInt(nObjectType);
    NWNXCall(NWNX_Util, "GetLastCreatedObject");
    return NWNXPopObject();
}

string NWNX_Util_AddScript(string sFileName, string sScriptData, int bWrapIntoMain = FALSE, string sAlias = "NWNX")
{
    NWNXPushString(sAlias);
    NWNXPushInt(bWrapIntoMain);
    NWNXPushString(sScriptData);
    NWNXPushString(sFileName);
    NWNXCall(NWNX_Util, "AddScript");
    return NWNXPopString();
}

int NWNX_Util_AddNSSFile(string sFileName, string sContents, string sAlias = "NWNX")
{
    NWNXPushString(sAlias);
    NWNXPushString(sContents);
    NWNXPushString(sFileName);
    NWNXCall(NWNX_Util, "AddNSSFile");
    return NWNXPopInt();
}

int NWNX_Util_RemoveNWNXResourceFile(string sFileName, int nType, string sAlias = "NWNX")
{
    NWNXPushString(sAlias);
    NWNXPushInt(nType);
    NWNXPushString(sFileName);
    NWNXCall(NWNX_Util, "RemoveNWNXResourceFile");
    return NWNXPopInt();
}

void NWNX_Util_SetInstructionLimit(int nInstructionLimit)
{
    NWNXPushInt(nInstructionLimit);
    NWNXCall(NWNX_Util, "SetInstructionLimit");
}

int NWNX_Util_GetInstructionLimit()
{
    NWNXCall(NWNX_Util, "GetInstructionLimit");
    return NWNXPopInt();
}

void NWNX_Util_SetInstructionsExecuted(int nInstructions)
{
    NWNXPushInt(nInstructions);
    NWNXCall(NWNX_Util, "SetInstructionsExecuted");
}

int NWNX_Util_GetInstructionsExecuted()
{
    NWNXCall(NWNX_Util, "GetInstructionsExecuted");
    return NWNXPopInt();
}

int NWNX_Util_RegisterServerConsoleCommand(string sCommand, string sScriptChunk)
{
    NWNXPushString(sScriptChunk);
    NWNXPushString(sCommand);
    NWNXCall(NWNX_Util, "RegisterServerConsoleCommand");
    return NWNXPopInt();
}

void NWNX_Util_UnregisterServerConsoleCommand(string sCommand)
{
    NWNXPushString(sCommand);
    NWNXCall(NWNX_Util, "UnregisterServerConsoleCommand");
}

string NWNX_Util_GetUserDirectory()
{
    NWNXCall(NWNX_Util, "GetUserDirectory");
    return NWNXPopString();
}

int NWNX_Util_GetScriptReturnValue()
{
    NWNXCall(NWNX_Util, "GetScriptReturnValue");
    return NWNXPopInt();
}

object NWNX_Util_CreateDoor(string sResRef, location locLocation, string sNewTag = "", int nAppearanceType = -1)
{
    NWNXPushInt(nAppearanceType);
    NWNXPushString(sNewTag);
    NWNXPushLocation(locLocation);
    NWNXPushString(sResRef);
    NWNXCall(NWNX_Util, "CreateDoor");
    return NWNXPopObject();
}

void NWNX_Util_SetItemActivator(object oObject)
{
    NWNXPushObject(oObject);
    NWNXCall(NWNX_Util, "SetItemActivator");
}

struct NWNX_Util_WorldTime NWNX_Util_GetWorldTime(float fAdjustment = 0.0f)
{
    NWNXPushFloat(fAdjustment);
    NWNXCall(NWNX_Util, "GetWorldTime");
    struct NWNX_Util_WorldTime strWorldTime;
    strWorldTime.nTimeOfDay = NWNXPopInt();
    strWorldTime.nCalendarDay = NWNXPopInt();
    return strWorldTime;
}

void NWNX_Util_SetResourceOverride(int nResType, string sOldName, string sNewName)
{
    NWNXPushString(sNewName);
    NWNXPushString(sOldName);
    NWNXPushInt(nResType);
    NWNXCall(NWNX_Util, "SetResourceOverride");
}

string NWNX_Util_GetResourceOverride(int nResType, string sName)
{
    NWNXPushString(sName);
    NWNXPushInt(nResType);
    NWNXCall(NWNX_Util, "GetResourceOverride");
    return NWNXPopString();
}

int NWNX_Util_GetScriptParamIsSet(string sParamName)
{
    NWNXPushString(sParamName);
    NWNXCall(NWNX_Util, "GetScriptParamIsSet");
    return NWNXPopInt();
}

void NWNX_Util_SetDawnHour(int nDawnHour)
{
    NWNXPushInt(nDawnHour);
    NWNXCall(NWNX_Util, "SetDawnHour");
}

int NWNX_Util_GetDawnHour()
{
    NWNXCall(NWNX_Util, "GetDawnHour");
    return NWNXPopInt();
}

void NWNX_Util_SetDuskHour(int nDuskHour)
{
    NWNXPushInt(nDuskHour);
    NWNXCall(NWNX_Util, "SetDuskHour");
}

int NWNX_Util_GetDuskHour()
{
    NWNXCall(NWNX_Util, "GetDuskHour");
    return NWNXPopInt();
}

struct NWNX_Util_HighResTimestamp NWNX_Util_GetHighResTimeStamp()
{
    struct NWNX_Util_HighResTimestamp t;
    NWNXCall(NWNX_Util, "GetHighResTimeStamp");
    t.microseconds = NWNXPopInt();
    t.seconds = NWNXPopInt();
    return t;
}

string NWNX_Util_GetTTY()
{
    NWNXCall(NWNX_Util, "GetTTY");
    return NWNXPopString();
}

void NWNX_Util_SetCurrentlyRunningEvent(int nEventID)
{
    NWNXPushInt(nEventID);
    NWNXCall(NWNX_Util, "SetCurrentlyRunningEvent");
}

int NWNX_Util_GetStringLevenshteinDistance(string sString, string sCompareTo)
{
    NWNXPushString(sCompareTo);
    NWNXPushString(sString);
    NWNXCall(NWNX_Util, "GetStringLevenshteinDistance");
    return NWNXPopInt();
}

void NWNX_Util_UpdateClientObject(object oObjectToUpdate, object oPlayer = OBJECT_INVALID)
{
    NWNXPushObject(oPlayer);
    NWNXPushObject(oObjectToUpdate);
    NWNXCall(NWNX_Util, "UpdateClientObject");
}

int NWNX_Util_CleanResourceDirectory(string sAlias, int nResType = 0xFFFF)
{
    NWNXPushInt(nResType);
    NWNXPushString(sAlias);
    NWNXCall(NWNX_Util, "CleanResourceDirectory");
    return NWNXPopInt();
}

string NWNX_Util_GetModuleTlkFile()
{
    string sFunc = "GetModuleTlkFile";
    NWNXCall(NWNX_Util, sFunc);
    return NWNXPopString();
}

int NWNX_Util_UpdateResourceDirectory(string sAlias)
{
    NWNXPushString(sAlias);
    NWNXCall(NWNX_Util, "UpdateResourceDirectory");
    return NWNXPopInt();
}
