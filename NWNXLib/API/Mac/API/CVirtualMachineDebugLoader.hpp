#pragma once

#include <cstdint>

#include "CResHelperTemplatedCResNDB2064u.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoString;

struct CVirtualMachineDebugLoader
    : CResHelperTemplatedCResNDB2064u
{
    int32_t m_bLoaded;

    // The below are auto generated stubs.
    CVirtualMachineDebugLoader() = default;
    CVirtualMachineDebugLoader(const CVirtualMachineDebugLoader&) = default;
    CVirtualMachineDebugLoader& operator=(const CVirtualMachineDebugLoader&) = default;

    ~CVirtualMachineDebugLoader();
    int32_t DemandDebugInfo(CExoString*);
    unsigned char* GetDataPtr();
    uint32_t GetSize();
    int32_t ReleaseDebugInfo();
};

void CVirtualMachineDebugLoader__CVirtualMachineDebugLoaderDtor__0(CVirtualMachineDebugLoader* thisPtr);
int32_t CVirtualMachineDebugLoader__DemandDebugInfo(CVirtualMachineDebugLoader* thisPtr, CExoString*);
unsigned char* CVirtualMachineDebugLoader__GetDataPtr(CVirtualMachineDebugLoader* thisPtr);
uint32_t CVirtualMachineDebugLoader__GetSize(CVirtualMachineDebugLoader* thisPtr);
int32_t CVirtualMachineDebugLoader__ReleaseDebugInfo(CVirtualMachineDebugLoader* thisPtr);

}

}
