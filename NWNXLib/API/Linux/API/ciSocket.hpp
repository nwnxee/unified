#pragma once

#include <cstdint>

#include "ciBuffer.hpp"
#include "ciServerMessage.hpp"
#include "unknown_CHATBool.hpp"
#include "unknown__gs_crypt_key.hpp"
#include "unknown_ciConnectState.hpp"

namespace NWNXLib {

namespace API {

struct ciSocket
{
    int32_t sock;
    ciConnectState connectState;
    char serverAddress[256];
    ciBuffer inputQueue;
    ciBuffer outputQueue;
    CHATBool secure;
    _gs_crypt_key inKey;
    _gs_crypt_key outKey;
    ciServerMessage lastMessage;
};

}

}
