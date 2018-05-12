#include "nwnx"

void NWNX_Lua_EvalVoid(string sCode)
{
    NWNX_PushArgumentString("NWNX_Lua", "EVALVOID", sCode);
    NWNX_CallFunction("NWNX_Lua", "EVALVOID");
}

string NWNX_Lua_Eval(string sCode)
{
    NWNX_PushArgumentString("NWNX_Lua", "EVAL", sCode);
    NWNX_CallFunction("NWNX_Lua", "EVAL");
    return NWNX_GetReturnValueString("NWNX_Lua", "EVAL");
}

void NWNX_Lua_RunEvent(string sEvent, object oObject, string sExtra="")
{
    NWNX_PushArgumentString("NWNX_Lua", "EVENT", sExtra);
    NWNX_PushArgumentObject("NWNX_Lua", "EVENT", oObject);
    NWNX_PushArgumentString("NWNX_Lua", "EVENT", sEvent);
    NWNX_CallFunction("NWNX_Lua", "EVENT");
}
