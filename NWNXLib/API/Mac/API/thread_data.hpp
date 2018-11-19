#pragma once

#include <cstdint>

#include "thread_sync_data.hpp"
#include "unknown___time_t.hpp"

namespace NWNXLib {

namespace API {

struct thread_data
{
    uint32_t* thread_hnd;
    uint32_t poll_interval;
    __time_t interval_end;
    thread_sync_data tsd;
};

}

}
