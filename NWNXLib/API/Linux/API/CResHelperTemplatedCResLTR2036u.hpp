#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResLTR;

struct CResHelperTemplatedCResLTR2036u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CResLTR* m_pRes;
    CResRef m_cResRef;
};

}

}
