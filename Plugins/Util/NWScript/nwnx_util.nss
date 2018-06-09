#include "nwnx"

// Returns the name of the currently executing script.
// If depth is >0, it will return the name of the script that called this one via ExecuteScript()
string NWNX_Util_GetCurrentScriptName(int depth=0);
// Returns a string that contains all characters at their position (e.g. 'A' at 65).
// The character at index 0 is a space.
string NWNX_Util_GetAsciiTableString();
// Returns an integer hash of a string
int NWNX_Util_Hash(string str);


const string NWNX_Util = "NWNX_Util";


string NWNX_Util_GetCurrentScriptName(int depth=0)
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

