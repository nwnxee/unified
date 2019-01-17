#pragma once

#include <cstdint>

#include "ZSTD_fseCTables_t.hpp"
#include "ZSTD_hufCTables_t.hpp"

namespace NWNXLib {

namespace API {

struct ZSTD_entropyCTables_t
{
    ZSTD_hufCTables_t huf;
    ZSTD_fseCTables_t fse;
};

}

}
