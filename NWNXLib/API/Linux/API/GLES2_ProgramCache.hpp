#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct GLES2_ProgramCacheEntry;

struct GLES2_ProgramCache
{
    int32_t count;
    GLES2_ProgramCacheEntry* head;
    GLES2_ProgramCacheEntry* tail;
};

}

}
