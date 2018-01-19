#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CResGFFFieldIDHash
{
    char padding[1];

    static uint32_t Hash(const char*, uint32_t);
    static void Initialize();
};

uint32_t CResGFFFieldIDHash__Hash(const char*, uint32_t);
void CResGFFFieldIDHash__Initialize();

}

}
