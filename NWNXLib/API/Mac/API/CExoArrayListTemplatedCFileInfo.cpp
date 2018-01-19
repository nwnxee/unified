#include "CExoArrayListTemplatedCFileInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCFileInfo::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCFileInfo__Allocate(this, a0);
}

void CExoArrayListTemplatedCFileInfo::Insert(CFileInfo a0, int32_t a1)
{
    return CExoArrayListTemplatedCFileInfo__Insert(this, a0, a1);
}

void CExoArrayListTemplatedCFileInfo__Allocate(CExoArrayListTemplatedCFileInfo* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCFileInfo*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCFileInfo__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedCFileInfo__Insert(CExoArrayListTemplatedCFileInfo* thisPtr, CFileInfo a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCFileInfo*, CFileInfo, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCFileInfo__Insert);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
