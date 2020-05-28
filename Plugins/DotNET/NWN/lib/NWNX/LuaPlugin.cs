namespace NWNX
{
    [NWNXPlugin(NWNX_Lua)]
    public class LuaPlugin
    {
        public const string NWNX_Lua = "NWNX_Lua";

        // /< @private
        // / @brief Evaluate LUA code.
        // / @param sCode The code to evaluate.
        public static void EvalVoid(string sCode)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Lua, "EvalVoid");
            NWN.Internal.NativeFunctions.nwnxPushString(sCode);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Evaluate LUA code and return the output.
        // / @param sCode The code to evaluate.
        // / @return The result of the Lua code execution.
        public static string Eval(string sCode)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Lua, "Eval");
            NWN.Internal.NativeFunctions.nwnxPushString(sCode);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Generate events in NWScript to receive on the Lua side.
        // /
        // / Executes all the Lua functions registered to listen to that event in order of priority.
        // / For details on events just look at the three *Event() functions in preload.lua.
        public static void RunEvent(string sEvent, uint oObject, string sExtra = "")
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Lua, "RunEvent");
            NWN.Internal.NativeFunctions.nwnxPushString(sExtra);
            NWN.Internal.NativeFunctions.nwnxPushObject(oObject);
            NWN.Internal.NativeFunctions.nwnxPushString(sEvent);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @}
    }
}
