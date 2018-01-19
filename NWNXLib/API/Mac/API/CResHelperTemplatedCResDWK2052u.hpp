#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResDWK;

struct CResHelperTemplatedCResDWK2052u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CResDWK* m_pRes;
    CResRef m_cResRef;
};

}

}
