#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct Header
{
    uint32_t m_magic;
    uint32_t m_version;
    uint32_t m_compressionAlgorithm;
    uint32_t m_uncompressedSize;
};

}

}
