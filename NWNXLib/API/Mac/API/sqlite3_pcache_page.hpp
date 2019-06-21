#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sqlite3_pcache_page
{
    void* pBuf;
    void* pExtra;
};

}

}
