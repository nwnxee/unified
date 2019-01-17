#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ZstdHeader
{
    uint32_t m_version;
    uint32_t m_dictionary;
};

}

}
