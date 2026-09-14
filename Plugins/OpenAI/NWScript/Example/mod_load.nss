#include "nwnx_events"

void main()
{
    NWNX_Events_SubscribeEvent("NWNX_ON_OPENAI_RESPONSE", "evt_openai");
}
