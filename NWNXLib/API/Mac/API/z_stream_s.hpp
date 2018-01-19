#pragma once

#include <cstdint>

#include "unknown_z_Byte.hpp"
#include "unknown_z_alloc_func.hpp"
#include "unknown_z_free_func.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct z_internal_state;

struct z_stream_s
{
    z_Byte* next_in;
    uint32_t avail_in;
    uint32_t total_in;
    z_Byte* next_out;
    uint32_t avail_out;
    uint32_t total_out;
    char* msg;
    z_internal_state* state;
    z_alloc_func zalloc;
    z_free_func zfree;
    void* opaque;
    int32_t data_type;
    uint32_t adler;
    uint32_t reserved;
};

}

}
