#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResNDB;

struct CResHelperTemplatedCResNDB2064u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CResNDB* m_pRes;
    CResRef m_cResRef;
};

}

}
