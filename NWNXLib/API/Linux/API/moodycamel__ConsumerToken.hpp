#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct moodycamel__details__ConcurrentQueueProducerTypelessBase;

struct moodycamel__ConsumerToken
{
    uint32_t initialOffset;
    uint32_t lastKnownGlobalOffset;
    uint32_t itemsConsumedFromCurrent;
    moodycamel__details__ConcurrentQueueProducerTypelessBase* currentProducer;
    moodycamel__details__ConcurrentQueueProducerTypelessBase* desiredProducer;
};

}

}
