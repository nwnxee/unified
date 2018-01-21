#include "nwnx"
#include "nwnx_redis_core"

struct Redis_PubSubMessageData {
    string channel;
    string message;
};

struct Redis_PubSubMessageData Redis_GetPubSubMessageData()
{
    struct Redis_PubSubMessageData ret;
    NWNX_CallFunction("NWNX_Redis", "GetPubSubData");
    ret.message = NWNX_GetReturnValueString("NWNX_Redis", "GetPubSubData");
    ret.channel = NWNX_GetReturnValueString("NWNX_Redis", "GetPubSubData");
    return ret;
}
