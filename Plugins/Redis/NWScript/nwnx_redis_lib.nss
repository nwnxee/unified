/// @addtogroup redis Redis
/// @brief Allows connection and interfacing with a redis server.
/// @{
/// @file nwnx_redis_lib.nss
/// @brief Allows connection and interfacing with a redis server.

/// @anchor redis_results
/// @name Redis Results
/// @{

/// @brief Array result
const int NWNX_REDIS_RESULT_ARRAY       = 1;

/// This never appears: it is rewritten into STRING for simplicity reasons.
/// const int NWNX_REDIS_RESULT_BULK_STRING = 2;

/// @brief Error result
/// @note You can retrieve errors as strings.
const int NWNX_REDIS_RESULT_ERROR       = 3;

/// @brief Integer result
/// @warning This cannot represent integers above 32bit.
/// @remark Use NWNX_Redis_GetResultAsString() if you need the string representation.
const int NWNX_REDIS_RESULT_INTEGER     = 4;

/// @brief String result
const int NWNX_REDIS_RESULT_STRING      = 5;

/// @brief Null result
const int NWNX_REDIS_RESULT_NULL        = 6;
/// @}

/// Returns the result type as a int.
int NWNX_Redis_GetResultType(int resultId);

/// @brief Gets the length of the given result.
/// @param resultId The result id.
/// @return The length or 0 if the given result wasn't a list type.
int NWNX_Redis_GetArrayLength(int resultId);

/// @brief Gets a list entry as a string.
/// @param resultId The result id.
/// @param idx The index in the list.
/// @return The list entry, will return "" if the given result is not a list,
/// or if the requested index is out of bounds.
int NWNX_Redis_GetArrayElement(int resultId, int idx);

/// @brief Gets the given result as a float.
/// @param resultId The result id.
/// @return The result as a float.
float NWNX_Redis_GetResultAsFloat(int resultId);

/// @brief Gets the given result as an integer.
/// @param resultId The result id.
/// @return The result as an integer.
int NWNX_Redis_GetResultAsInt(int resultId);

/// @brief Gets the given result as a string.
/// @param resultId The result id.
/// @return The result as a string.
string NWNX_Redis_GetResultAsString(int resultId);

/// @}

int NWNX_Redis_GetResultType(int resultId)
{
    NWNXPushInt(resultId);
    NWNXCall("NWNX_Redis", "GetResultType");
    return NWNXPopInt();
}

int NWNX_Redis_GetArrayLength(int resultId)
{
    NWNXPushInt(resultId);
    NWNXCall("NWNX_Redis", "GetResultArrayLength");
    return NWNXPopInt();
}

// Returns the last
int NWNX_Redis_GetArrayElement(int resultId, int idx)
{
    NWNXPushInt(resultId);
    NWNXPushInt(idx);
    NWNXCall("NWNX_Redis", "GetResultArrayElement");
    return NWNXPopInt();
}

float NWNX_Redis_GetResultAsFloat(int resultId)
{
    NWNXPushInt(resultId);
    NWNXCall("NWNX_Redis", "GetResultAsString");
    return StringToFloat(NWNXPopString());
}

int NWNX_Redis_GetResultAsInt(int resultId)
{
    NWNXPushInt(resultId);
    NWNXCall("NWNX_Redis", "GetResultAsString");
    return StringToInt(NWNXPopString());
}

string NWNX_Redis_GetResultAsString(int resultId)
{
    NWNXPushInt(resultId);
    NWNXCall("NWNX_Redis", "GetResultAsString");
    return NWNXPopString();
}
