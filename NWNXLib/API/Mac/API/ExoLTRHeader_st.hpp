#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ExoLTRHeader_st
{
    uint32_t m_nType;
    uint32_t m_nVersion;
    uint8_t m_nNumLetters;
};

}

}
