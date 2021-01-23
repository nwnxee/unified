/// @addtogroup time Time
/// @brief Provides various time related functions.
/// @{
/// @file inc_sqlite_time.nss

/// @brief Returns the current time formatted according to the provided sqlite date time format string.
/// @param format Format string as used by sqlites STRFTIME().
/// @return The current time in the requested format. Empty string on error.
string SQLite_GetFormattedSystemTime(string format);

/// @return Returns the number of seconds since midnight on January 1, 1970.
int SQLite_GetTimeStamp();

/// @brief A millisecond timestamp
struct SQLite_MillisecondTimeStamp
{
    int seconds; ///< Seconds since epoch
    int milliseconds; ///< Milliseconds
};

/// @remark For mircosecond timestamps use NWNX_Utility_GetHighResTimeStamp().
/// @return Returns the number of milliseconds since midnight on January 1, 1970.
struct SQLite_MillisecondTimeStamp SQLite_GetMillisecondTimeStamp();

/// @brief Returns the current date.
/// @return The date in the format (mm/dd/yyyy).
string SQLite_GetSystemDate();

/// @brief Returns current time.
/// @return The current time in the format (24:mm:ss).
string SQLite_GetSystemTime();

/// @}

string SQLite_GetFormattedSystemTime(string format)
{
    sqlquery query = SqlPrepareQueryObject(GetModule(), "SELECT STRFTIME(@format, 'now', 'localtime')");
    SqlBindString(query, "@format", format);
    SqlStep(query); // sqlite returns NULL for invalid format in STRFTIME()
    return SqlGetString(query, 0);
}

int SQLite_GetTimeStamp()
{
    sqlquery query = SqlPrepareQueryObject(GetModule(), "SELECT STRFTIME('%s', 'now')");
    SqlStep(query);
    return SqlGetInt(query, 0);
}

struct SQLite_MillisecondTimeStamp SQLite_GetMillisecondTimeStamp()
{
    sqlquery query = SqlPrepareQueryObject(GetModule(), "SELECT STRFTIME('%s', 'now'), SUBSTR(STRFTIME('%f', 'now'), 4)");
    SqlStep(query);
    struct SQLite_MillisecondTimeStamp t;
    t.seconds = SqlGetInt(query, 0);
    t.milliseconds = SqlGetInt(query, 1);
    return t;
}

string SQLite_GetSystemDate()
{
    return SQLite_GetFormattedSystemTime("%m/%d/%Y");
}

string SQLite_GetSystemTime()
{
    return SQLite_GetFormattedSystemTime("%H:%M:%S");
}
