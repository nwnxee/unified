#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct AuxData
{
    int32_t iAuxOp;
    int32_t iAuxArg;
    void* pAux;
    void** m_funcPtrPlaceholder__0;
    AuxData* pNextAux;
};

}

}
