#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResWOK;

struct CResHelperTemplatedCResWOK2016u
{
    void** m_vtable;
    int32_t m_bAutoRequest;
    CResWOK* m_pRes;
    CResRef m_cResRef;
};

}

}
