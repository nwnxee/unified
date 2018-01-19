#pragma once

#include <cstdint>

#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FILE4St;
struct OPT4LIST;

struct OPT4BLOCK
{
    l4linkSt link;
    l4linkSt lruLink;
    char changed;
    uint32_t len;
    void* data;
    uint32_t readTime;
    uint32_t accessTime;
    double hitCount;
    OPT4LIST* optList;
    FILE4St* file;
    uint32_t pos;
};

}

}
