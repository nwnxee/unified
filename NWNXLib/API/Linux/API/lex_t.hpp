#pragma once

#include <cstdint>

#include "strbuffer_t.hpp"
#include "stream_t.hpp"
#include "unknown_TLS_226717B7724994FD2C378CA433BE396D.hpp"

namespace NWNXLib {

namespace API {

struct lex_t
{
    stream_t stream;
    strbuffer_t saved_text;
    uint32_t flags;
    uint32_t depth;
    int32_t token;
    TLS_226717B7724994FD2C378CA433BE396D value;
};

}

}
