#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CScriptCompilerStructureEntry
{
    CExoString m_psName;
    int32_t m_nFieldStart;
    int32_t m_nFieldEnd;
    int32_t m_nByteSize;
};

}

}
