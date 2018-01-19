#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CTlkTableToken
{
    uint32_t m_nHash;
    CExoString m_sToken;
    uint32_t m_nActionCode;
    uint32_t m_nStrRef[4];
    uint32_t m_nStrRefDefault;
};

}

}
