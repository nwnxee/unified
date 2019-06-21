#pragma once

#include <cstdint>

#include "SASL.hpp"
#include "pingpong.hpp"
#include "unknown_imapstate.hpp"

namespace NWNXLib {

namespace API {

struct imap_conn
{
    pingpong pp;
    imapstate state;
    bool ssldone;
    bool preauth;
    SASL sasl;
    uint32_t preftype;
    int32_t cmdid;
    char resptag[5];
    bool tls_supported;
    bool login_disabled;
    bool ir_supported;
    char* mailbox;
    char* mailbox_uidvalidity;
};

}

}
