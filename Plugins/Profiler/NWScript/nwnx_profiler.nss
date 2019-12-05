/// @addtogroup profiler Profiler
/// @brief Functions to instrument nwscript code.
/// @remark These functions are for advanced users.
/// @{
/// @file nwnx_profiler.nss
#include "nwnx"

const string NWNX_Profiler = "NWNX_Profiler"; ///< @private

/// @brief Push a timing metric scope - note that every push must be matched by a corresponding pop.
///
/// A timing metric contains the following information.
///  ```c
///  {
///    metricName: [name], // Mandatory, from user code
///    metricFields: { time, nanoseconds }, // Automatically captured by the push/pop pair
///    metricTags: { [tag0_tag], [tag0_value] } // Optional, from user code, can be used to
///                                                filter metrics based on some category or,
///                                                constant e.g. objectType or area
///  }
///  ```
///
/// If you don't understand how this works and you wish to use it, you should research
/// the Metrics system (see Metrics.hpp) as well as googling about how InfluxDB stores metrics.
///
/// @note It's possible to have more than one tag pair per metric, It is just limited
/// to one arbitrarily here. You can edit the prototype to include more and the C++
/// code will cope with it correctly.
/// @param name The name to use for your metric.
/// @param tag0_tag An optional tag to filter your metrics.
/// @param tag0_value The tag's value for which to filter.
void NWNX_Profiler_PushPerfScope(string name, string tag0_tag = "", string tag0_value = "");

/// @brief Pops a timing metric.
/// @remark A metric must already be pushed.
void NWNX_Profiler_PopPerfScope();

/// @}

void NWNX_Profiler_PushPerfScope(string name, string tag0_tag = "", string tag0_value = "")
{
    string sFunc = "PushPerfScope";

    NWNX_PushArgumentString(NWNX_Profiler, sFunc, name);

    if (tag0_value != "" && tag0_tag != "")
    {
        NWNX_PushArgumentString(NWNX_Profiler, sFunc, tag0_value);
        NWNX_PushArgumentString(NWNX_Profiler, sFunc, tag0_tag);
    }

    NWNX_CallFunction(NWNX_Profiler, sFunc);
}

void NWNX_Profiler_PopPerfScope()
{
    string sFunc = "PopPerfScope";

    NWNX_CallFunction(NWNX_Profiler, sFunc);
}