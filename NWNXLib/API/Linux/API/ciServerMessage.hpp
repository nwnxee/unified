#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciServerMessage
{
    char* message;
    char* server;
    char* nick;
    char* user;
    char* host;
    char* command;
    char* middle;
    char* param;
    char** params;
    int32_t numParams;
};

}

}
