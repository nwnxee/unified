#include "CExoArrayListTemplatedCVirtualMachineFilePtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CVirtualMachineFile.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCVirtualMachineFilePtr::~CExoArrayListTemplatedCVirtualMachineFilePtr()
{
    CExoArrayListTemplatedCVirtualMachineFilePtr__CExoArrayListTemplatedCVirtualMachineFilePtrDtor(this);
}

void CExoArrayListTemplatedCVirtualMachineFilePtr__CExoArrayListTemplatedCVirtualMachineFilePtrDtor(CExoArrayListTemplatedCVirtualMachineFilePtr* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCVirtualMachineFilePtr*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCVirtualMachineFilePtr__CExoArrayListTemplatedCVirtualMachineFilePtrDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
