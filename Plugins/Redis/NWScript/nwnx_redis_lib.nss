#include "nwnx"

const int NWNX_REDIS_RESULT_ARRAY       = 1;

// This never appears: it is rewritten into STRING for simplicity reasons.
// const int NWNX_REDIS_RESULT_BULK_STRING = 2;

// NB: You can retrieve errors as strings.
const int NWNX_REDIS_RESULT_ERROR       = 3;

// NB: This cannot represent integers above 32bit.
//      Use NWNX_Redis_GetResultAsString()
//      if you need the string representation of it.
const int NWNX_REDIS_RESULT_INTEGER     = 4;

const int NWNX_REDIS_RESULT_STRING      = 5;

const int NWNX_REDIS_RESULT_NULL        = 6;

// Returns the result type as a int.
int NWNX_Redis_GetResultType(int resultId);

// Returns the length of the ggiven result.
// Returns 0 if the given result wasn't a list type.
int NWNX_Redis_GetArrayLength(int resultId);

// Returns a list entry as a string.
// Will return "" if the given result is not a list, or if
// the requested index is out of bounds.
int NWNX_Redis_GetArrayElement(int resultId, int idx);

// Returns the given result as a float.
float NWNX_Redis_GetResultAsFloat(int resultId);

// Returns the given result as a int.
int NWNX_Redis_GetResultAsInt(int resultId);

// Returns the given result as a string.
string NWNX_Redis_GetResultAsString(int resultId);

int NWNX_Redis_GetResultType(int resultId)
{
    NWNX_PushArgumentInt("NWNX_Redis", "GetResultType", resultId);
    NWNX_CallFunction("NWNX_Redis", "GetResultType");
    return NWNX_GetReturnValueInt("NWNX_Redis", "GetResultType");
}

int NWNX_Redis_GetArrayLength(int resultId)
{
    NWNX_PushArgumentInt("NWNX_Redis", "GetResultArrayLength", resultId);
    NWNX_CallFunction("NWNX_Redis", "GetResultArrayLength");
    return NWNX_GetReturnValueInt("NWNX_Redis", "GetResultArrayLength");
}

// Returns the last
int NWNX_Redis_GetArrayElement(int resultId, int idx)
{
    NWNX_PushArgumentInt("NWNX_Redis", "GetResultArrayElement", resultId);
    NWNX_PushArgumentInt("NWNX_Redis", "GetResultArrayElement", idx);
    NWNX_CallFunction("NWNX_Redis", "GetResultArrayElement");
    return NWNX_GetReturnValueInt("NWNX_Redis", "GetResultArrayElement");
}

float NWNX_Redis_GetResultAsFloat(int resultId)
{
    NWNX_PushArgumentInt("NWNX_Redis", "GetResultAsString", resultId);
    NWNX_CallFunction("NWNX_Redis", "GetResultAsString");
    return StringToFloat(NWNX_GetReturnValueString("NWNX_Redis", "GetResultAsString"));
}

int NWNX_Redis_GetResultAsInt(int resultId)
{
    NWNX_PushArgumentInt("NWNX_Redis", "GetResultAsString", resultId);
    NWNX_CallFunction("NWNX_Redis", "GetResultAsString");
    return StringToInt(NWNX_GetReturnValueString("NWNX_Redis", "GetResultAsString"));
}

string NWNX_Redis_GetResultAsString(int resultId)
{
    NWNX_PushArgumentInt("NWNX_Redis", "GetResultAsString", resultId);
    NWNX_CallFunction("NWNX_Redis", "GetResultAsString");
    return NWNX_GetReturnValueString("NWNX_Redis", "GetResultAsString");
}
