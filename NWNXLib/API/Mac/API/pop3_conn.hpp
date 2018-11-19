#pragma once

#include <cstdint>

#include "SASL.hpp"
#include "pingpong.hpp"
#include "unknown_pop3state.hpp"

namespace NWNXLib {

namespace API {

struct pop3_conn
{
    pingpong pp;
    pop3state state;
    bool ssldone;
    uint32_t eob;
    uint32_t strip;
    SASL sasl;
    uint32_t authtypes;
    uint32_t preftype;
    char* apoptimestamp;
    bool tls_supported;
};

}

}
