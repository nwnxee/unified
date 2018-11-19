#pragma once

#include <cstdint>

#include "unknown_sqlite_int64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FileChunk;

struct FilePoint
{
    sqlite_int64 iOffset;
    FileChunk* pChunk;
};

}

}
