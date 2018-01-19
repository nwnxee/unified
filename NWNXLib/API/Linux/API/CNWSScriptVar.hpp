#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNWSScriptVar
{
    CExoString m_sName;
    uint32_t m_nType;
    void* m_pValue;
};

}

}
