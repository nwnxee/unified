#include "nwnx"

struct NWNX_Redis_PubSubMessageData {
    string channel;
    string message;
};

struct NWNX_Redis_PubSubMessageData NWNX_Redis_GetPubSubMessageData()
{
    struct NWNX_Redis_PubSubMessageData ret;
    NWNX_CallFunction("NWNX_Redis", "GetPubSubData");
    ret.message = NWNX_GetReturnValueString("NWNX_Redis", "GetPubSubData");
    ret.channel = NWNX_GetReturnValueString("NWNX_Redis", "GetPubSubData");
    return ret;
}
