#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct audio_buf_info
{
    int32_t fragments;
    int32_t fragstotal;
    int32_t fragsize;
    int32_t bytes;
};

}

}
