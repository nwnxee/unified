#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CVirtualMachineDebuggerInstance;

struct CVirtualMachineDebuggingContext
{
    int32_t m_bStepInto;
    int32_t m_bStepOver;
    int32_t m_bRunToLineNumber;
    int32_t m_nLineNumberToRunTo;
    CVirtualMachineDebuggerInstance* m_pDebuggerInstance;
};

}

}
