/// @ingroup redis
/// @brief Interface to Redis PUBSUB
/// @{
/// @file nwnx_redis_ps.nss
#include "nwnx"

/// A redis PUBSUB message
struct NWNX_Redis_PubSubMessageData {
    string channel; ///< The channel
    string message; ///< The message
};

/// @brief Get a PUBSUB message
/// @return A NWNX_Redis_PubSubMessageData struct.
struct NWNX_Redis_PubSubMessageData NWNX_Redis_GetPubSubMessageData()
{
    struct NWNX_Redis_PubSubMessageData ret;
    NWNX_CallFunction("NWNX_Redis", "GetPubSubData");
    ret.message = NWNX_GetReturnValueString("NWNX_Redis", "GetPubSubData");
    ret.channel = NWNX_GetReturnValueString("NWNX_Redis", "GetPubSubData");
    return ret;
}
/// @}
