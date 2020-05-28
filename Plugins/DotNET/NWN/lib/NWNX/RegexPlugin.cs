namespace NWNX
{
    [NWNXPlugin(NWNX_Regex)]
    public class RegexPlugin
    {
        public const string NWNX_Regex = "NWNX_Regex";

        // /< @private
        // / @param str The string to search.
        // / @param regex The regular expression to use when searching.
        // / @return TRUE if string matches the regular expression.
        public static int Search(string str, string regex)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Regex, "Search");
            NWN.Internal.NativeFunctions.nwnxPushString(regex);
            NWN.Internal.NativeFunctions.nwnxPushString(str);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Replaces any matches of the regular expression with a string.
        // / @param str The string to search.
        // / @param regex The regular expression to use when searching.
        // / @param replace The string to replace the matches with.
        // / @param firstOnly Set to TRUE to only replace the first match.
        // / @return A new string with any replacements made.
        public static string Replace(string str, string regex, string replace = "", int firstOnly = NWN.NWScript.FALSE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Regex, "Replace");
            NWN.Internal.NativeFunctions.nwnxPushInt(firstOnly);
            NWN.Internal.NativeFunctions.nwnxPushString(replace);
            NWN.Internal.NativeFunctions.nwnxPushString(regex);
            NWN.Internal.NativeFunctions.nwnxPushString(str);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @}
    }
}
