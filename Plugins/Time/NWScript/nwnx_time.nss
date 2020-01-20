/// @addtogroup time Time
/// @brief Provides various time related functions
/// @{
/// @file nwnx_time.nss
#include "nwnx"

const string NWNX_Time = "NWNX_Time"; ///< @private

/// @brief Returns the current date.
/// @return The date in the format (mm/dd/yyyy).
string NWNX_Time_GetSystemDate();

/// @brief Returns current time.
/// @return The current time in the format (24:mm:ss).
string NWNX_Time_GetSystemTime();

/// @return Returns the number of seconds since midnight on January 1, 1970.
int NWNX_Time_GetTimeStamp();

/// @brief A high resolution timestamp
struct NWNX_Time_HighResTimestamp
{
    int seconds; ///< Seconds since epoch
    int microseconds; ///< Microseconds
};

/// @return Returns the number of microseconds since midnight on January 1, 1970.
struct NWNX_Time_HighResTimestamp NWNX_Time_GetHighResTimeStamp();

/// @}

string NWNX_Time_GetSystemDate()
{
    string sFunc = "GetSystemDate";
    NWNX_CallFunction(NWNX_Time, sFunc);
    return NWNX_GetReturnValueString(NWNX_Time, sFunc);
}

string NWNX_Time_GetSystemTime()
{
    string sFunc = "GetSystemTime";
    NWNX_CallFunction(NWNX_Time, sFunc);
    return NWNX_GetReturnValueString(NWNX_Time, sFunc);
}

int NWNX_Time_GetTimeStamp()
{
    string sFunc = "GetTimeStamp";

    NWNX_CallFunction(NWNX_Time, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Time, sFunc);
}

struct NWNX_Time_HighResTimestamp NWNX_Time_GetHighResTimeStamp()
{
    struct NWNX_Time_HighResTimestamp t;
    string sFunc = "GetHighResTimeStamp";

    NWNX_CallFunction(NWNX_Time, sFunc);
    t.microseconds = NWNX_GetReturnValueInt(NWNX_Time, sFunc);
    t.seconds = NWNX_GetReturnValueInt(NWNX_Time, sFunc);
    return t;
}
