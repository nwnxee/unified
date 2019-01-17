#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CVirtualMachineFile;

struct CExoArrayListTemplatedCVirtualMachineFilePtr
{
    CVirtualMachineFile** element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCVirtualMachineFilePtr() = default;
    CExoArrayListTemplatedCVirtualMachineFilePtr(const CExoArrayListTemplatedCVirtualMachineFilePtr&) = default;
    CExoArrayListTemplatedCVirtualMachineFilePtr& operator=(const CExoArrayListTemplatedCVirtualMachineFilePtr&) = default;

    ~CExoArrayListTemplatedCVirtualMachineFilePtr();
};

void CExoArrayListTemplatedCVirtualMachineFilePtr__CExoArrayListTemplatedCVirtualMachineFilePtrDtor(CExoArrayListTemplatedCVirtualMachineFilePtr* thisPtr);

}

}
