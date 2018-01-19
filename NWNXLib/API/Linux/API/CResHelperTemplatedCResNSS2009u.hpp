#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResNSS;

struct CResHelperTemplatedCResNSS2009u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CResNSS* m_pRes;
    CResRef m_cResRef;
};

}

}
