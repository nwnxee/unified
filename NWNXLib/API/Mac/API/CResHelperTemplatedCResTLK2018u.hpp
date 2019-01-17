#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResTLK;

struct CResHelperTemplatedCResTLK2018u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CResTLK* m_pRes;
    CResRef m_cResRef;
};

}

}
