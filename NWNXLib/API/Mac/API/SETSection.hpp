#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct SETEntry;

struct SETSection
{
    CExoString m_sSection;
    SETEntry* m_pEntry;
    uint32_t m_nNumEntries;
};

}

}
