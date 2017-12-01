#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciChannelListUsersData
{
    void* chat;
    int32_t numUsers;
    char** users;
    int32_t* modes;
};

}

}
