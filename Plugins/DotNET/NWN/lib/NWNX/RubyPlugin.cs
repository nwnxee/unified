namespace NWNX
{
    [NWNXPlugin(NWNX_Ruby)]
    public class RubyPlugin
    {
        public const string NWNX_Ruby = "NWNX_Ruby";

        // /< @private
        public static string Evaluate(string sCode)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Ruby, "Evaluate");
            NWN.Internal.NativeFunctions.nwnxPushString(sCode);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Evaluates some ruby code.
        // / @param sCode The code to evaluate.
        // / @return The output of the call.
        // / @}
    }
}
