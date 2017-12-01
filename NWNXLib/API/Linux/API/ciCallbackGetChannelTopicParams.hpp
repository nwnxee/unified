#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackGetChannelTopicParams
{
    CHATBool success;
    char* channel;
    char* topic;
};

}

}
