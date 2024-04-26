/// @addtogroup lua LUA
/// @brief Execute Lua code and generate events in NWScript
/// @{
/// @file nwnx_lua.nss

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
    NWNXPushString(sCode);
    NWNXCall(NWNX_Lua, "EvalVoid");
}

string NWNX_Lua_Eval(string sCode)
{
    NWNXPushString(sCode);
    NWNXCall(NWNX_Lua, "Eval");
    return NWNXPopString();
}

void NWNX_Lua_RunEvent(string sEvent, object oObject, string sExtra="")
{
    NWNXPushString(sExtra);
    NWNXPushObject(oObject);
    NWNXPushString(sEvent);
    NWNXCall(NWNX_Lua, "RunEvent");
}
