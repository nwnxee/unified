#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CServerNetOptions
{
    int32_t m_nGameRegion;
    CExoString m_szGameDetails;
    int16_t m_GameType;
};

}

}
