#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CVirtualMachineStack;

struct CVirtualMachineScript
{
    CVirtualMachineStack* m_pStack;
    int32_t m_nStackSize;
    int32_t m_nInstructPtr;
    int32_t m_nSecondaryInstructPtr;
    char* m_pCode;
    int32_t m_nCodeSize;
    CExoString m_sScriptName;
    int32_t m_nLoadedFromSave;
};

}

}
