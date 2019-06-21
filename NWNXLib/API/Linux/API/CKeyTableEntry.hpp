#pragma once

#include <cstdint>

#include "CResRef.hpp"
#include "RESID.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CRes;

struct CKeyTableEntry
{
    CResRef m_cResRef;
    CRes* m_pRes;
    RESID m_nID;
    uint16_t m_nRefCount;
    uint16_t m_nType;
};

}

}
