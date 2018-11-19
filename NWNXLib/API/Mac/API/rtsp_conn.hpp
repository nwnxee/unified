#pragma once

#include <cstdint>

#include "unknown___ssize_t.hpp"

namespace NWNXLib {

namespace API {

struct rtsp_conn
{
    char* rtp_buf;
    __ssize_t rtp_bufsize;
    int32_t rtp_channel;
};

}

}
