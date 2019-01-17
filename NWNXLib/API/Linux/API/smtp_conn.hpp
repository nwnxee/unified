#pragma once

#include <cstdint>

#include "SASL.hpp"
#include "pingpong.hpp"
#include "unknown_smtpstate.hpp"

namespace NWNXLib {

namespace API {

struct smtp_conn
{
    pingpong pp;
    smtpstate state;
    bool ssldone;
    char* domain;
    SASL sasl;
    bool tls_supported;
    bool size_supported;
    bool auth_supported;
};

}

}
