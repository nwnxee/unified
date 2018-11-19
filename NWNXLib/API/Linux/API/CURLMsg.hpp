#pragma once

#include <cstdint>

#include "unknown_CURLMSG.hpp"
#include "unknown_CURLMsg__TLS_1B88962F26CF66E39AFE7F7738FD0002.hpp"

namespace NWNXLib {

namespace API {

struct CURLMsg
{
    CURLMSG msg;
    void* easy_handle;
    CURLMsg__TLS_1B88962F26CF66E39AFE7F7738FD0002 data;
};

}

}
