#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSTagNode
{
    char m_szTag[65];
    uint32_t m_oidObjectId;
};

}

}
