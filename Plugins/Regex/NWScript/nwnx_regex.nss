#include "nwnx"

const string NWNX_Regex = "NWNX_Regex";

// Returns whether the string matches the regular expression
int NWNX_Regex_Search(string str, string regex);

// Replaces any matches of the regular expression with a string
string NWNX_Regex_Replace(string str, string regex, string replace="", int firstOnly=0);


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
