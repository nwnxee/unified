namespace NWNX
{
    [NWNXPlugin(NWNX_Profiler)]
    public class ProfilerPlugin
    {
        public const string NWNX_Profiler = "NWNX_Profiler";

        // /< @private
        // / @brief Push a timing metric scope - note that every push must be matched by a corresponding pop.
        // /
        // / A timing metric contains the following information.
        // /  ```c
        // /  {
        // /    metricName: [name], // Mandatory, from user code
        // /    metricFields: { time, nanoseconds }, // Automatically captured by the push/pop pair
        // /    metricTags: { [tag0_tag], [tag0_value] } // Optional, from user code, can be used to
        // /                                                filter metrics based on some category or,
        // /                                                constant e.g. objectType or area
        // /  }
        // /  ```
        // /
        // / If you don't understand how this works and you wish to use it, you should research
        // / the Metrics system (see Metrics.hpp) as well as googling about how InfluxDB stores metrics.
        // /
        // / @note It's possible to have more than one tag pair per metric, It is just limited
        // / to one arbitrarily here. You can edit the prototype to include more and the C++
        // / code will cope with it correctly.
        // / @param name The name to use for your metric.
        // / @param tag0_tag An optional tag to filter your metrics.
        // / @param tag0_value The tag's value for which to filter.
        public static void PushPerfScope(string name, string tag0_tag = "", string tag0_value = "")
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Profiler, "PushPerfScope");
            NWN.Internal.NativeFunctions.nwnxPushString(tag0_value);
            NWN.Internal.NativeFunctions.nwnxPushString(tag0_tag);
            NWN.Internal.NativeFunctions.nwnxPushString(name);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Pops a timing metric.
        // / @remark A metric must already be pushed.
        public static void PopPerfScope()
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Profiler, "PopPerfScope");
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @}
    }
}
