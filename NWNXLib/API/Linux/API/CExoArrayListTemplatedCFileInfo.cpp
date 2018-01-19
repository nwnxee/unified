#include "CExoArrayListTemplatedCFileInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCFileInfo::~CExoArrayListTemplatedCFileInfo()
{
    CExoArrayListTemplatedCFileInfo__CExoArrayListTemplatedCFileInfoDtor(this);
}

void CExoArrayListTemplatedCFileInfo::Add(CFileInfo a0)
{
    return CExoArrayListTemplatedCFileInfo__Add(this, a0);
}

void CExoArrayListTemplatedCFileInfo::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCFileInfo__Allocate(this, a0);
}

void CExoArrayListTemplatedCFileInfo__CExoArrayListTemplatedCFileInfoDtor(CExoArrayListTemplatedCFileInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCFileInfo*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCFileInfo__CExoArrayListTemplatedCFileInfoDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoArrayListTemplatedCFileInfo__Add(CExoArrayListTemplatedCFileInfo* thisPtr, CFileInfo a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCFileInfo*, CFileInfo);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCFileInfo__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedCFileInfo__Allocate(CExoArrayListTemplatedCFileInfo* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCFileInfo*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCFileInfo__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
