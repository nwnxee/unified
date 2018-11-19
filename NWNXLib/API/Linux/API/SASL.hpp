#pragma once

#include <cstdint>

#include "unknown_saslstate.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct SASLproto;

struct SASL
{
    const SASLproto* params;
    saslstate state;
    uint32_t authmechs;
    uint32_t prefmech;
    uint32_t authused;
    bool resetprefs;
    bool mutual_auth;
    bool force_ir;
};

}

}
