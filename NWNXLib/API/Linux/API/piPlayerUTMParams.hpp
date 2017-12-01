#pragma once

#include <cstdint>

#include "unknown_PEERBool.hpp"

namespace NWNXLib {

namespace API {

struct piPlayerUTMParams
{
    char* nick;
    char* command;
    char* parameters;
    PEERBool authenticated;
};

}

}
