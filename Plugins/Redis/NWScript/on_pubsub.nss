/// @ingroup redis
/// @brief Script to handle PubSub event
/// @{
/// @file on_pubsub.nss
#include "nwnx_redis_ps"

void main()
{
  struct NWNX_Redis_PubSubMessageData data = NWNX_Redis_GetPubSubMessageData();

  WriteTimestampedLogEntry("Pubsub Event: channel=" + data.channel +
    " message=" + data.message);
}
/// @}
