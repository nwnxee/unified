#pragma once

#include <cstdint>

#include "unknown_pthread_mutex_t_0.hpp"

namespace NWNXLib {

namespace API {

struct sqlite3_mutex
{
    pthread_mutex_t_0 mutex;
};

}

}
