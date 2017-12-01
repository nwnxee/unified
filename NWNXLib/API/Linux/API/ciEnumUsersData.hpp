#pragma once

#include <cstdint>

#include "unknown_chatEnumUsersCallback.hpp"

namespace NWNXLib {

namespace API {

struct ciEnumUsersData
{
    chatEnumUsersCallback callback;
    void* param;
};

}

}
