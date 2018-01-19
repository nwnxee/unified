#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResIFO;

struct CResHelperTemplatedCResIFO2014u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CResIFO* m_pRes;
    CResRef m_cResRef;
};

}

}
