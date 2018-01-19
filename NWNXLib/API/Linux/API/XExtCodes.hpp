#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XExtCodes
{
    int32_t extension;
    int32_t major_opcode;
    int32_t first_event;
    int32_t first_error;
};

}

}
