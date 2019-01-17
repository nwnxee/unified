#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct content_encoding_s;

struct contenc_writer_s
{
    const content_encoding_s* handler;
    contenc_writer_s* downstream;
    void* params;
};

}

}
