#pragma once

#include <cstdint>

#include "chatChannelCallbacks.hpp"
#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct JOINData
{
    chatChannelCallbacks callbacks;
    CHATBool joined;
    char password[256];
};

}

}
