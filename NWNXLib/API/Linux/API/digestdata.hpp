#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct digestdata
{
    char* nonce;
    char* cnonce;
    char* realm;
    int32_t algo;
    bool stale;
    char* opaque;
    char* qop;
    char* algorithm;
    int32_t nc;
    bool userhash;
};

}

}
