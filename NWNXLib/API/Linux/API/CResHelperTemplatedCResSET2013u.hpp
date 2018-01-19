#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResSET;

struct CResHelperTemplatedCResSET2013u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CResSET* m_pRes;
    CResRef m_cResRef;
};

}

}
