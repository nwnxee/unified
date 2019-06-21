#pragma once

#include <cstdint>

#include "unknown_std__atomicTemplatedbool.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct moodycamel__ProducerToken;

struct moodycamel__details__ConcurrentQueueProducerTypelessBase
{
    moodycamel__details__ConcurrentQueueProducerTypelessBase* next;
    std__atomicTemplatedbool inactive;
    moodycamel__ProducerToken* token;
};

}

}
