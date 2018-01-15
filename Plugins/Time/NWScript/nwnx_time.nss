#include "nwnx"

// Returns the current date in the format (mm/dd/yyyy)
string NWNX_Time_GetSystemDate();

// Returns current time in the format (24:mm:ss)
string NWNX_Time_GetSystemTime();

// Returns the number of seconds since midnight on January 1, 1970
int NWNX_Time_GetTimeStamp();


const string NWNX_Time = "NWNX_Time";

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