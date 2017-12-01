#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciCallbackNewUserListParams
{
    char* channel;
    int32_t numUsers;
    char** users;
    int32_t* modes;
};

}

}
