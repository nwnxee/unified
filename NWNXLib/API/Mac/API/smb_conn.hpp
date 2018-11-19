#pragma once

#include <cstdint>

#include "unknown_smb_conn_state.hpp"

namespace NWNXLib {

namespace API {

struct smb_conn
{
    smb_conn_state state;
    char* user;
    char* domain;
    uint8_t challenge[8];
    uint32_t session_key;
    uint16_t uid;
    char* recv_buf;
    uint32_t upload_size;
    uint32_t send_size;
    uint32_t sent;
    uint32_t got;
};

}

}
