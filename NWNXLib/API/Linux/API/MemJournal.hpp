#pragma once

#include <cstdint>

#include "FilePoint.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FileChunk;
struct sqlite3_io_methods;
struct sqlite3_vfs;

struct MemJournal
{
    const sqlite3_io_methods* pMethod;
    int32_t nChunkSize;
    int32_t nSpill;
    int32_t nSize;
    FileChunk* pFirst;
    FilePoint endpoint;
    FilePoint readpoint;
    int32_t flags;
    sqlite3_vfs* pVfs;
    const char* zJournal;
};

}

}
