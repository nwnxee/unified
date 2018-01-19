#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CScriptCompilerVarStackEntry
{
    CExoString m_psVarName;
    int32_t m_nVarType;
    int32_t m_nVarLevel;
    int32_t m_nVarRunTimeLocation;
    CExoString m_sVarStructureName;
};

}

}
