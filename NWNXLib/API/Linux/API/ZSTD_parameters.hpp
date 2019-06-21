#pragma once

#include <cstdint>

#include "ZSTD_compressionParameters.hpp"
#include "ZSTD_frameParameters.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_parameters
{
    ZSTD_compressionParameters cParams;
    ZSTD_frameParameters fParams;
};

}

}
