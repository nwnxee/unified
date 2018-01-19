#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResARE;

struct CResHelperTemplatedCResARE2012u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CResARE* m_pRes;
    CResRef m_cResRef;
};

}

}
