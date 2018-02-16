#pragma once

#include <cstdint>

#include "unknown_json_load_callback_t.hpp"

namespace NWNXLib {

namespace API {

struct callback_data_t
{
    char data[1024];
    uint32_t len;
    uint32_t pos;
    json_load_callback_t callback;
    void* arg;
};

}

}
