#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CRes2DA;

struct CResHelperTemplatedCRes2DA2017u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CRes2DA* m_pRes;
    CResRef m_cResRef;
};

}

}
