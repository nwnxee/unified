#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CGameID__GameID_t
{
    uint32_t m_nAppID : 24;
    uint32_t m_nType : 8;
    uint32_t m_nModID : 32;
};

}

}
