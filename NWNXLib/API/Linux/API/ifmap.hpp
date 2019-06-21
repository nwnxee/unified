#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ifmap
{
    uint32_t mem_start;
    uint32_t mem_end;
    uint16_t base_addr;
    uint8_t irq;
    uint8_t dma;
    uint8_t port;
};

}

}
