#include "nwnx"

const string NWNX_Lua = "NWNX_Lua";


void NWNX_Lua_EvalVoid(string sCode)
{
    string sFunc = "EVALVOID";

    NWNX_PushArgumentString(NWNX_Lua, sFunc, sCode);
    NWNX_CallFunction(NWNX_Lua, sFunc);
}

string NWNX_Lua_Eval(string sCode)
{
    string sFunc = "EVAL";

    NWNX_PushArgumentString(NWNX_Lua, sFunc, sCode);
    NWNX_CallFunction(NWNX_Lua, sFunc);
    return NWNX_GetReturnValueString(NWNX_Lua, sFunc);
}

void NWNX_Lua_RunEvent(string sEvent, object oObject, string sExtra="")
{
    string sFunc = "EVENT";

    NWNX_PushArgumentString(NWNX_Lua, sFunc, sExtra);
    NWNX_PushArgumentObject(NWNX_Lua, sFunc, oObject);
    NWNX_PushArgumentString(NWNX_Lua, sFunc, sEvent);
    NWNX_CallFunction(NWNX_Lua, sFunc);
}
