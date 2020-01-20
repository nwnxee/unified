/// @addtogroup lua LUA
/// @brief Execute Lua code and generate events in NWScript
/// @{
/// @file nwnx_lua.nss
#include "nwnx"

const string NWNX_Lua = "NWNX_Lua"; ///< @private

/// @brief Evaluate LUA code.
/// @param sCode The code to evaluate.
void NWNX_Lua_EvalVoid(string sCode);

/// @brief Evaluate LUA code and return the output.
/// @param sCode The code to evaluate.
/// @return The result of the Lua code execution.
string NWNX_Lua_Eval(string sCode);

/// @brief Generate events in NWScript to receive on the Lua side.
///
/// Executes all the Lua functions registered to listen to that event in order of priority.
/// For details on events just look at the three *Event() functions in preload.lua.
void NWNX_Lua_RunEvent(string sEvent, object oObject, string sExtra="");

/// @}

void NWNX_Lua_EvalVoid(string sCode)
{
    string sFunc = "EvalVoid";

    NWNX_PushArgumentString(NWNX_Lua, sFunc, sCode);
    NWNX_CallFunction(NWNX_Lua, sFunc);
}

string NWNX_Lua_Eval(string sCode)
{
    string sFunc = "Eval";

    NWNX_PushArgumentString(NWNX_Lua, sFunc, sCode);
    NWNX_CallFunction(NWNX_Lua, sFunc);
    return NWNX_GetReturnValueString(NWNX_Lua, sFunc);
}

void NWNX_Lua_RunEvent(string sEvent, object oObject, string sExtra="")
{
    string sFunc = "RunEvent";

    NWNX_PushArgumentString(NWNX_Lua, sFunc, sExtra);
    NWNX_PushArgumentObject(NWNX_Lua, sFunc, oObject);
    NWNX_PushArgumentString(NWNX_Lua, sFunc, sEvent);
    NWNX_CallFunction(NWNX_Lua, sFunc);
}
