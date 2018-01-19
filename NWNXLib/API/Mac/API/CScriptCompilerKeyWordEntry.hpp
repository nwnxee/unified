#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CScriptCompilerKeyWordEntry
{
    CExoString m_sAlphanumericName;
    uint32_t m_nHashValue;
    uint32_t m_nNameLength;
    int32_t m_nTokenToTranslate;
};

}

}
