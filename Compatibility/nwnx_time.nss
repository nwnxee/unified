/// @addtogroup time Time
/// @brief Provides various time related functions
/// @{
/// @file nwnx_time.nss
#include "nwnx_util"
#include "inc_sqlite_time"

const string NWNX_Time = "NWNX_Time"; ///< @private

/// @brief Returns the current date.
/// @deprecated Use SQLite functions (see inc_sqlite_time). This will be removed in future NWNX releases.
/// @return The date in the format (mm/dd/yyyy).
string NWNX_Time_GetSystemDate();

/// @brief Returns current time.
/// @deprecated Use SQLite functions (see inc_sqlite_time). This will be removed in future NWNX releases.
/// @return The current time in the format (24:mm:ss).
string NWNX_Time_GetSystemTime();

/// @deprecated Use SQLite functions (see inc_sqlite_time). This will be removed in future NWNX releases.
/// @return Returns the number of seconds since midnight on January 1, 1970.
int NWNX_Time_GetTimeStamp();

/// @brief A high resolution timestamp
struct NWNX_Time_HighResTimestamp
{
    int seconds; ///< Seconds since epoch
    int microseconds; ///< Microseconds
};

/// @deprecated Use NWNX_Util_GetHighResTimeStamp(). This will be removed in future NWNX releases.
/// @return Returns the number of microseconds since midnight on January 1, 1970.
struct NWNX_Time_HighResTimestamp NWNX_Time_GetHighResTimeStamp();

/// @}

string NWNX_Time_GetSystemDate()
{
    WriteTimestampedLogEntry("WARNING:  NWNX_Time is deprecated.  You should migrate to SQLite based functions (see inc_sqlite_time).");
    return SQLite_GetSystemDate();
}

string NWNX_Time_GetSystemTime()
{
    WriteTimestampedLogEntry("WARNING:  NWNX_Time is deprecated.  You should migrate to SQLite based functions (see inc_sqlite_time).");
    return SQLite_GetSystemTime();
}

int NWNX_Time_GetTimeStamp()
{
    WriteTimestampedLogEntry("WARNING:  NWNX_Time is deprecated.  You should migrate to SQLite based functions (see inc_sqlite_time).");
    return SQLite_GetTimeStamp();
}

struct NWNX_Time_HighResTimestamp NWNX_Time_GetHighResTimeStamp()
{
    WriteTimestampedLogEntry("WARNING:  NWNX_Time is deprecated.  NWNX_Time_GetHighResTimeStamp is moving to NWNX_Util.");
    struct NWNX_Util_HighResTimestamp u = NWNX_Util_GetHighResTimeStamp();
    struct NWNX_Time_HighResTimestamp t;
    t.seconds = u.seconds;
    t.microseconds = u.microseconds;
    return t;
}
