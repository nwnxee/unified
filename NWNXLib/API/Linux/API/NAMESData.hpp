#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct NAMESData
{
    int32_t len;
    int32_t numUsers;
    char** users;
    int32_t* modes;
};

}

}
