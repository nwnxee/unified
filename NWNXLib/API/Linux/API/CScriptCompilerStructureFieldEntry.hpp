#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CScriptCompilerStructureFieldEntry
{
    uint8_t m_pchType;
    CExoString m_psStructureName;
    CExoString m_psVarName;
    int32_t m_nLocation;
};

}

}
