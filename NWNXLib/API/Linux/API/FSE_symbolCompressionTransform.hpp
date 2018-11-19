#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct FSE_symbolCompressionTransform
{
    int32_t deltaFindState;
    uint32_t deltaNbBits;
};

}

}
