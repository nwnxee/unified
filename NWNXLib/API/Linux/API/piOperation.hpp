#pragma once

#include <cstdint>

#include "unknown_PEERBool.hpp"
#include "unknown_RoomType.hpp"
#include "unknown_piOperationType.hpp"

namespace NWNXLib {

namespace API {

struct piOperation
{
    void* peer;
    piOperationType type;
    void* data;
    int32_t ID;
    void* callback;
    void* callback2;
    void* callbackParam;
    RoomType roomType;
    char* name;
    char* password;
    int32_t num;
    int32_t socket;
    uint16_t port;
    PEERBool socketClose;
    PEERBool cancel;
};

}

}
