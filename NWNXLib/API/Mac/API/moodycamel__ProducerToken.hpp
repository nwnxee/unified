#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct moodycamel__details__ConcurrentQueueProducerTypelessBase;

struct moodycamel__ProducerToken
{
    moodycamel__details__ConcurrentQueueProducerTypelessBase* producer;
};

}

}
