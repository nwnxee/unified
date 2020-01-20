/// @addtogroup util Util
/// @brief Provides various utility functions that don't have a better home
/// @{
/// @file nwnx_util.nss
#include "nwnx"

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

/// @brief Gets the value of customTokenNumber.
/// @param customTokenNumber The token number to query.
/// @return The string representation of the token value.
string NWNX_Util_GetCustomToken(int customTokenNumber);

/// @brief Convert an effect type to an itemproperty type.
/// @param e The effect to convert to an itemproperty.
/// @return The converted itemproperty.
itemproperty NWNX_Util_EffectToItemProperty(effect e);

///
/// @brief Convert an itemproperty type to an effect type.
/// @param ip The itemproperty to convert to an effect.
/// @return The converted effect.
effect NWNX_Util_ItemPropertyToEffect(itemproperty ip);

/// @brief Strip any color codes from a string.
/// @param str The string to strip of color.
/// @return The new string without any color codes.
string NWNX_Util_StripColors(string str);

/// @brief Determines if the supplied resref exists.
/// @param resref The resref to check.
/// @param type The @ref resref_types "Resref Type".
/// @return TRUE/FALSE
int NWNX_Util_IsValidResRef(string resref, int type = NWNX_UTIL_RESREF_TYPE_CREATURE);

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

/// @anchor twoda_row_count
/// @brief Gets the row count for a 2da.
/// @param str The 2da to check (do not include the .2da).
/// @return The amount of rows in the 2da.
int NWNX_Util_Get2DARowCount(string str);

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

/// @brief Get the ticks per second of the server.
/// @remark Useful to dynamically detect lag and adjust behavior accordingly.
/// @return The ticks per second.
int NWNX_Util_GetServerTicksPerSecond();

/// @brief Get the last created object.
/// @param nObjectType Does not take the NWScript OBJECT_TYPE_* constants.
/// Use NWNX_Consts_TranslateNWScriptObjectType() to get their NWNX equivalent.
/// @param nNthLast The nth last object created.
/// @return The last created object. On error, this returns OBJECT_INVALID.
object NWNX_Util_GetLastCreatedObject(int nObjectType, int nNthLast = 1);

/// @brief Compiles and adds a script to the UserDirectory/nwnx folder.
/// @note Will override existing scripts that are in the module.
/// @param sFileName The script filename without extension, 16 or less characters.
/// @param sScriptData The script data to compile
/// @param bWrapIntoMain Set to TRUE to wrap sScriptData into void main(){}.
/// @return "" on success, or the compilation error.
string NWNX_Util_AddScript(string sFileName, string sScriptData, int bWrapIntoMain = FALSE);

/// @brief Gets the contents of a .nss script file as a string.
/// @param sScriptName The name of the script to get the contents of.
/// @param nMaxLength The max length of the return string, -1 to get everything
/// @return The script file contents or "" on error.
string NWNX_Util_GetNSSContents(string sScriptName, int nMaxLength = -1);

/// @brief Adds a nss file to the UserDirectory/nwnx folder.
/// @note Will override existing nss files that are in the module
/// @param sFileName The script filename without extension, 16 or less characters.
/// @param sContents The contents of the nss file
/// @return TRUE on success.
int NWNX_Util_AddNSSFile(string sFileName, string sContents);

/// @brief Remove sFileName of nType from the UserDirectory/nwnx folder.
/// @param sFileName The filename without extension, 16 or less characters.
/// @param nType The @ref resref_types "Resref Type".
/// @return TRUE on success.
int NWNX_Util_RemoveNWNXResourceFile(string sFileName, int nType);

/// @}

string NWNX_Util_GetCurrentScriptName(int depth = 0)
{
    string sFunc = "GetCurrentScriptName";
    NWNX_PushArgumentInt(NWNX_Util, sFunc, depth);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

string NWNX_Util_GetAsciiTableString()
{
    string sFunc = "GetAsciiTableString";
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

int NWNX_Util_Hash(string str)
{
    string sFunc = "Hash";
    NWNX_PushArgumentString(NWNX_Util, sFunc, str);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Util, sFunc);
}

string NWNX_Util_GetCustomToken(int customTokenNumber)
{
    string sFunc = "GetCustomToken";
    NWNX_PushArgumentInt(NWNX_Util, sFunc, customTokenNumber);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

itemproperty NWNX_Util_EffectToItemProperty(effect e)
{
    string sFunc = "EffectTypeCast";
    NWNX_PushArgumentEffect(NWNX_Util, sFunc, e);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueItemProperty(NWNX_Util, sFunc);
}

effect NWNX_Util_ItemPropertyToEffect(itemproperty ip)
{
    string sFunc = "EffectTypeCast";
    NWNX_PushArgumentItemProperty(NWNX_Util, sFunc, ip);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueEffect(NWNX_Util, sFunc);
}

string NWNX_Util_StripColors(string str)
{
    string sFunc = "StripColors";
    NWNX_PushArgumentString(NWNX_Util, sFunc, str);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

int NWNX_Util_IsValidResRef(string resref, int type = NWNX_UTIL_RESREF_TYPE_CREATURE)
{
    string sFunc = "IsValidResRef";
    NWNX_PushArgumentInt(NWNX_Util, sFunc, type);
    NWNX_PushArgumentString(NWNX_Util, sFunc, resref);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Util, sFunc);
}

string NWNX_Util_GetEnvironmentVariable(string sVarname)
{
    string sFunc = "GetEnvironmentVariable";
    NWNX_PushArgumentString(NWNX_Util, sFunc, sVarname);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

int NWNX_Util_GetMinutesPerHour()
{
    string sFunc = "GetMinutesPerHour";
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Util, sFunc);
}

void NWNX_Util_SetMinutesPerHour(int minutes)
{
    string sFunc = "SetMinutesPerHour";
    NWNX_PushArgumentInt(NWNX_Util, sFunc, minutes);
    NWNX_CallFunction(NWNX_Util, sFunc);
}

string NWNX_Util_EncodeStringForURL(string sURL)
{
    string sFunc = "EncodeStringForURL";

    NWNX_PushArgumentString(NWNX_Util, sFunc, sURL);
    NWNX_CallFunction(NWNX_Util, sFunc);

    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

int NWNX_Util_Get2DARowCount(string str)
{
    string sFunc = "Get2DARowCount";
    NWNX_PushArgumentString(NWNX_Util, sFunc, str);
    NWNX_CallFunction(NWNX_Util, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Util, sFunc);
}

string NWNX_Util_GetFirstResRef(int nType, string sRegexFilter = "", int bModuleResourcesOnly = TRUE)
{
    string sFunc = "GetFirstResRef";

    NWNX_PushArgumentInt(NWNX_Util, sFunc, bModuleResourcesOnly);
    NWNX_PushArgumentString(NWNX_Util, sFunc, sRegexFilter);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, nType);
    NWNX_CallFunction(NWNX_Util, sFunc);

    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

string NWNX_Util_GetNextResRef()
{
    string sFunc = "GetNextResRef";

    NWNX_CallFunction(NWNX_Util, sFunc);

    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

int NWNX_Util_GetServerTicksPerSecond()
{
    string sFunc = "GetServerTicksPerSecond";

    NWNX_CallFunction(NWNX_Util, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Util, sFunc);
}

object NWNX_Util_GetLastCreatedObject(int nObjectType, int nNthLast = 1)
{
    string sFunc = "GetLastCreatedObject";

    NWNX_PushArgumentInt(NWNX_Util, sFunc, nNthLast);
    NWNX_PushArgumentInt(NWNX_Util, sFunc, nObjectType);
    NWNX_CallFunction(NWNX_Util, sFunc);

    return NWNX_GetReturnValueObject(NWNX_Util, sFunc);
}

string NWNX_Util_AddScript(string sFileName, string sScriptData, int bWrapIntoMain = FALSE)
{
    string sFunc = "AddScript";

    NWNX_PushArgumentInt(NWNX_Util, sFunc, bWrapIntoMain);
    NWNX_PushArgumentString(NWNX_Util, sFunc, sScriptData);
    NWNX_PushArgumentString(NWNX_Util, sFunc, sFileName);
    NWNX_CallFunction(NWNX_Util, sFunc);

    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

string NWNX_Util_GetNSSContents(string sScriptName, int nMaxLength = -1)
{
    string sFunc = "GetNSSContents";

    NWNX_PushArgumentInt(NWNX_Util, sFunc, nMaxLength);
    NWNX_PushArgumentString(NWNX_Util, sFunc, sScriptName);
    NWNX_CallFunction(NWNX_Util, sFunc);

    return NWNX_GetReturnValueString(NWNX_Util, sFunc);
}

int NWNX_Util_AddNSSFile(string sFileName, string sContents)
{
    string sFunc = "AddNSSFile";

    NWNX_PushArgumentString(NWNX_Util, sFunc, sContents);
    NWNX_PushArgumentString(NWNX_Util, sFunc, sFileName);
    NWNX_CallFunction(NWNX_Util, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Util, sFunc);
}

int NWNX_Util_RemoveNWNXResourceFile(string sFileName, int nType)
{
    string sFunc = "RemoveNWNXResourceFile";

    NWNX_PushArgumentInt(NWNX_Util, sFunc, nType);
    NWNX_PushArgumentString(NWNX_Util, sFunc, sFileName);
    NWNX_CallFunction(NWNX_Util, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Util, sFunc);
}
