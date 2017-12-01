#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackChangeNickParams
{
    CHATBool success;
    char* oldNick;
    char* newNick;
};

}

}
