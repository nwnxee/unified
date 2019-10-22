/// @addtogroup regex Regex
/// @brief Provide regular expression functions.
/// @{
/// @file nwnx_regex.nss
#include "nwnx"

const string NWNX_Regex = "NWNX_Regex"; ///< @private

/// @param str The string to search.
/// @param regex The regular expression to use when searching.
/// @return TRUE if string matches the regular expression.
int NWNX_Regex_Search(string str, string regex);

/// @brief Replaces any matches of the regular expression with a string.
/// @param str The string to search.
/// @param regex The regular expression to use when searching.
/// @param replace The string to replace the matches with.
/// @param firstOnly Set to TRUE to only replace the first match.
/// @return A new string with any replacements made.
string NWNX_Regex_Replace(string str, string regex, string replace = "", int firstOnly = FALSE);

/// @}

int NWNX_Regex_Search(string str, string regex)
{
    string sFunc = "Search";
    NWNX_PushArgumentString(NWNX_Regex, sFunc, regex);
    NWNX_PushArgumentString(NWNX_Regex, sFunc, str);
    NWNX_CallFunction(NWNX_Regex, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Regex, sFunc);
}

string NWNX_Regex_Replace(string str, string regex, string replace="", int firstOnly=0)
{
    string sFunc = "Replace";
    NWNX_PushArgumentInt(NWNX_Regex, sFunc, firstOnly);
    NWNX_PushArgumentString(NWNX_Regex, sFunc, replace);
    NWNX_PushArgumentString(NWNX_Regex, sFunc, regex);
    NWNX_PushArgumentString(NWNX_Regex, sFunc, str);
    NWNX_CallFunction(NWNX_Regex, sFunc);
    return NWNX_GetReturnValueString(NWNX_Regex, sFunc);
}
