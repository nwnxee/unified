#pragma once

#include <cstdint>

#include "code.hpp"
#include "unknown_inflate_mode.hpp"
#include "unknown_z_gz_header.hpp"
#include "unknown_z_stream_0.hpp"

namespace NWNXLib {

namespace API {

struct inflate_state
{
    z_stream_0* strm;
    inflate_mode mode;
    int32_t last;
    int32_t wrap;
    int32_t havedict;
    int32_t flags;
    uint32_t dmax;
    uint32_t check;
    uint32_t total;
    z_gz_header* head;
    uint32_t wbits;
    uint32_t wsize;
    uint32_t whave;
    uint32_t wnext;
    uint8_t* window;
    uint32_t hold;
    uint32_t bits;
    uint32_t length;
    uint32_t offset;
    uint32_t extra;
    const code* lencode;
    const code* distcode;
    uint32_t lenbits;
    uint32_t distbits;
    uint32_t ncode;
    uint32_t nlen;
    uint32_t ndist;
    uint32_t have;
    code* next;
    uint16_t lens[320];
    uint16_t work[288];
    code codes[1444];
    int32_t sane;
    int32_t back;
    uint32_t was;
};

}

}
