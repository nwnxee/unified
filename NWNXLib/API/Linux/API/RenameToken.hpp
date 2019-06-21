#pragma once

#include <cstdint>

#include "Token.hpp"

namespace NWNXLib {

namespace API {

struct RenameToken
{
    void* p;
    Token t;
    RenameToken* pNext;
};

}

}
