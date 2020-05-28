namespace NWNX
{
    [NWNXPlugin(NWNX_Util)]
    public class UtilPlugin
    {
        public const string NWNX_Util = "NWNX_Util";

        // /< @private
        // / @name Resref Types
        // / @anchor resref_types
        // / Constants for the various types of resrefs.
        // /
        // / @{
        public const int NWNX_UTIL_RESREF_TYPE_NSS = 2009;
        public const int NWNX_UTIL_RESREF_TYPE_NCS = 2010;
        public const int NWNX_UTIL_RESREF_TYPE_AREA_ARE = 2012;
        public const int NWNX_UTIL_RESREF_TYPE_TWODA = 2017;
        public const int NWNX_UTIL_RESREF_TYPE_AREA_GIT = 2023;
        public const int NWNX_UTIL_RESREF_TYPE_ITEM = 2025;
        public const int NWNX_UTIL_RESREF_TYPE_CREATURE = 2027;
        public const int NWNX_UTIL_RESREF_TYPE_DIALOG = 2029;
        public const int NWNX_UTIL_RESREF_TYPE_TRIGGER = 2032;
        public const int NWNX_UTIL_RESREF_TYPE_SOUND = 2035;
        public const int NWNX_UTIL_RESREF_TYPE_ENCOUNTER = 2040;
        public const int NWNX_UTIL_RESREF_TYPE_DOOR = 2042;
        public const int NWNX_UTIL_RESREF_TYPE_PLACEABLE = 2044;
        public const int NWNX_UTIL_RESREF_TYPE_STORE = 2051;
        public const int NWNX_UTIL_RESREF_TYPE_WAYPOINT = 2058;

        // /@}
        // / @brief Gets the name of the currently executing script.
        // / @note If depth is > 0, it will return the name of the script that called this one via ExecuteScript().
        // / @param depth to seek the executing script.
        // / @return The name of the currently executing script.
        public static string GetCurrentScriptName(int depth = 0)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetCurrentScriptName");
            NWN.Internal.NativeFunctions.nwnxPushInt(depth);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Gets a string that contains the ascii table.
        // / @note The character at index 0 is a space.
        // / @return A string that contains all characters at their position (e.g. 'A' at 65).
        public static string GetAsciiTableString()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetAsciiTableString");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Gets an integer hash of a string.
        // / @param str The string to hash.
        // / @return The hashed string as an integer.
        public static int Hash(string str)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "Hash");
            NWN.Internal.NativeFunctions.nwnxPushString(str);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Gets the value of customTokenNumber.
        // / @param customTokenNumber The token number to query.
        // / @return The string representation of the token value.
        public static string GetCustomToken(int customTokenNumber)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetCustomToken");
            NWN.Internal.NativeFunctions.nwnxPushInt(customTokenNumber);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Convert an effect type to an itemproperty type.
        // / @param e The effect to convert to an itemproperty.
        // / @return The converted itemproperty.
        public static NWN.ItemProperty EffectToItemProperty(NWN.Effect e)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "EffectToItemProperty");
            NWN.Internal.NativeFunctions.nwnxPushEffect(e.Handle);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.nwnxPopItemProperty());
        }

        // /
        // / @brief Convert an itemproperty type to an effect type.
        // / @param ip The itemproperty to convert to an effect.
        // / @return The converted effect.
        public static NWN.Effect ItemPropertyToEffect(NWN.ItemProperty ip)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "ItemPropertyToEffect");
            NWN.Internal.NativeFunctions.nwnxPushItemProperty(ip.Handle);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return new NWN.Effect(NWN.Internal.NativeFunctions.nwnxPopEffect());
        }

        // / @brief Strip any color codes from a string.
        // / @param str The string to strip of color.
        // / @return The new string without any color codes.
        public static string StripColors(string str)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "StripColors");
            NWN.Internal.NativeFunctions.nwnxPushString(str);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Determines if the supplied resref exists.
        // / @param resref The resref to check.
        // / @param type The @ref resref_types "Resref Type".
        // / @return TRUE/FALSE
        public static int IsValidResRef(string resref, int type = NWNX_UTIL_RESREF_TYPE_CREATURE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "IsValidResRef");
            NWN.Internal.NativeFunctions.nwnxPushInt(type);
            NWN.Internal.NativeFunctions.nwnxPushString(resref);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Retrieves an environment variable.
        // / @param sVarname The environment variable to query.
        // / @return The value of the environment variable.
        public static string GetEnvironmentVariable(string sVarname)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetEnvironmentVariable");
            NWN.Internal.NativeFunctions.nwnxPushString(sVarname);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Gets the module real life minutes per in game hour.
        // / @return The minutes per hour.
        public static int GetMinutesPerHour()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetMinutesPerHour");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set module real life minutes per in game hour.
        // / @param minutes The minutes per hour.
        public static void SetMinutesPerHour(int minutes)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "SetMinutesPerHour");
            NWN.Internal.NativeFunctions.nwnxPushInt(minutes);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @anchor util_encode_url
        // / @brief Encodes a string for usage in a URL.
        // / @param str The string to encode for a URL.
        // / @return The url encoded string.
        public static string EncodeStringForURL(string str)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "EncodeStringForURL");
            NWN.Internal.NativeFunctions.nwnxPushString(str);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @anchor twoda_row_count
        // / @brief Gets the row count for a 2da.
        // / @param str The 2da to check (do not include the .2da).
        // / @return The amount of rows in the 2da.
        public static int Get2DARowCount(string str)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "Get2DARowCount");
            NWN.Internal.NativeFunctions.nwnxPushString(str);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the first resref of nType.
        // / @param nType A @ref resref_types "Resref Type".
        // / @param sRegexFilter Lets you filter out resrefs using a regexfilter.
        // / For example: **nwnx_.\*** gets you all scripts prefixed with nwnx_
        // / when using the NSS resref type.
        // / @param bModuleResourcesOnly If TRUE only custom resources will be returned.
        // / @return The first resref found or "" if none is found.
        public static string GetFirstResRef(int nType, string sRegexFilter = "", int bModuleResourcesOnly = NWN.NWScript.TRUE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetFirstResRef");
            NWN.Internal.NativeFunctions.nwnxPushInt(bModuleResourcesOnly);
            NWN.Internal.NativeFunctions.nwnxPushString(sRegexFilter);
            NWN.Internal.NativeFunctions.nwnxPushInt(nType);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Get the next resref.
        // / @return The next resref found or "" if none is found.
        public static string GetNextResRef()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetNextResRef");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Get the ticks per second of the server.
        // / @remark Useful to dynamically detect lag and adjust behavior accordingly.
        // / @return The ticks per second.
        public static int GetServerTicksPerSecond()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetServerTicksPerSecond");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get the last created object.
        // / @param nObjectType Does not take the NWScript OBJECT_TYPE_* constants.
        // / Use NWNX_Consts_TranslateNWScriptObjectType() to get their NWNX equivalent.
        // / @param nNthLast The nth last object created.
        // / @return The last created object. On error, this returns OBJECT_INVALID.
        public static uint GetLastCreatedObject(int nObjectType, int nNthLast = 1)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetLastCreatedObject");
            NWN.Internal.NativeFunctions.nwnxPushInt(nNthLast);
            NWN.Internal.NativeFunctions.nwnxPushInt(nObjectType);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopObject();
        }

        // / @brief Compiles and adds a script to the UserDirectory/nwnx folder.
        // / @note Will override existing scripts that are in the module.
        // / @param sFileName The script filename without extension, 16 or less characters.
        // / @param sScriptData The script data to compile
        // / @param bWrapIntoMain Set to TRUE to wrap sScriptData into void main(){}.
        // / @return "" on success, or the compilation error.
        public static string AddScript(string sFileName, string sScriptData, int bWrapIntoMain = NWN.NWScript.FALSE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "AddScript");
            NWN.Internal.NativeFunctions.nwnxPushInt(bWrapIntoMain);
            NWN.Internal.NativeFunctions.nwnxPushString(sScriptData);
            NWN.Internal.NativeFunctions.nwnxPushString(sFileName);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Gets the contents of a .nss script file as a string.
        // / @param sScriptName The name of the script to get the contents of.
        // / @param nMaxLength The max length of the return string, -1 to get everything
        // / @return The script file contents or "" on error.
        public static string GetNSSContents(string sScriptName, int nMaxLength = -1)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetNSSContents");
            NWN.Internal.NativeFunctions.nwnxPushInt(nMaxLength);
            NWN.Internal.NativeFunctions.nwnxPushString(sScriptName);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Adds a nss file to the UserDirectory/nwnx folder.
        // / @note Will override existing nss files that are in the module
        // / @param sFileName The script filename without extension, 16 or less characters.
        // / @param sContents The contents of the nss file
        // / @return TRUE on success.
        public static int AddNSSFile(string sFileName, string sContents)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "AddNSSFile");
            NWN.Internal.NativeFunctions.nwnxPushString(sContents);
            NWN.Internal.NativeFunctions.nwnxPushString(sFileName);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Remove sFileName of nType from the UserDirectory/nwnx folder.
        // / @param sFileName The filename without extension, 16 or less characters.
        // / @param nType The @ref resref_types "Resref Type".
        // / @return TRUE on success.
        public static int RemoveNWNXResourceFile(string sFileName, int nType)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "RemoveNWNXResourceFile");
            NWN.Internal.NativeFunctions.nwnxPushInt(nType);
            NWN.Internal.NativeFunctions.nwnxPushString(sFileName);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the NWScript instruction limit
        // / @param nInstructionLimit The new limit or -1 to reset to default.
        public static void SetInstructionLimit(int nInstructionLimit)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "SetInstructionLimit");
            NWN.Internal.NativeFunctions.nwnxPushInt(nInstructionLimit);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Register a server console command that will execute a script chunk.
        // / @note Example usage: NWNX_Util_RegisterServerConsoleCommand("test", "PrintString(\"Test Command -> Args: $args\");");
        // / @param sCommand The name of the command.
        // / @param sScriptChunk The script chunk to run. You can use $args to get the console command arguments.
        // / @return TRUE on success.
        public static int RegisterServerConsoleCommand(string sCommand, string sScriptChunk)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "RegisterServerConsoleCommand");
            NWN.Internal.NativeFunctions.nwnxPushString(sScriptChunk);
            NWN.Internal.NativeFunctions.nwnxPushString(sCommand);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Unregister a server console command that was registered with NWNX_Util_RegisterServerConsoleCommand().
        // / @param sCommand The name of the command.
        public static void UnregisterServerConsoleCommand(string sCommand)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "UnregisterServerConsoleCommand");
            NWN.Internal.NativeFunctions.nwnxPushString(sCommand);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Determines if the given plugin exists and is enabled.
        // / @param sPlugin The name of the plugin to check. This is the case sensitive plugin name as used by NWNX_CallFunction, NWNX_PushArgumentX
        // / @note Example usage: NWNX_Util_PluginExists("NWNX_Creature");
        // / @return TRUE if the plugin exists and is enabled, otherwise FALSE.
        public static int PluginExists(string sPlugin)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "PluginExists");
            NWN.Internal.NativeFunctions.nwnxPushString(sPlugin);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Gets the server's current working user folder.
        // / @return The absolute path of the server's home directory (-userDirectory)
        public static string GetUserDirectory()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetUserDirectory");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Get the return value of the last run script with a StartingConditional
        // / @return Return value of the last run script.
        public static int GetScriptReturnValue()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Util, "GetScriptReturnValue");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @}
    }
}
