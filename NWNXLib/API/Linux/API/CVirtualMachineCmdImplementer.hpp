#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CVirtualMachineCmdImplementer
{
    void** m_vtable;
    int32_t m_bValidObjectRunScript;
    uint32_t m_oidObjectRunScript;
};

}

}
