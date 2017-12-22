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

    // The below are auto generated stubs.
    CVirtualMachineScript() = default;
    CVirtualMachineScript(const CVirtualMachineScript&) = default;
    CVirtualMachineScript& operator=(const CVirtualMachineScript&) = default;

    ~CVirtualMachineScript();
};

void CVirtualMachineScript__CVirtualMachineScriptDtor(CVirtualMachineScript* thisPtr);

}

}
