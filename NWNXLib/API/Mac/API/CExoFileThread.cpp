#include "CExoFileThread.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoFileThread::CExoFileThread()
{
    CExoFileThread__CExoFileThreadCtor__0(this);
}

CExoFileThread::~CExoFileThread()
{
    CExoFileThread__CExoFileThreadDtor__0(this);
}

void CExoFileThread::AsyncRead()
{
    return CExoFileThread__AsyncRead(this);
}

void CExoFileThread::Read(void* a0, uint32_t a1, uint32_t a2, __sFILE* a3)
{
    return CExoFileThread__Read(this, a0, a1, a2, a3);
}

void CExoFileThread__CExoFileThreadCtor__0(CExoFileThread* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileThread*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileThread__CExoFileThreadCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoFileThread__CExoFileThreadDtor__0(CExoFileThread* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileThread*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileThread__CExoFileThreadDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoFileThread__AsyncRead(CExoFileThread* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileThread*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileThread__AsyncRead);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoFileThread__Read(CExoFileThread* thisPtr, void* a0, uint32_t a1, uint32_t a2, __sFILE* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileThread*, void*, uint32_t, uint32_t, __sFILE*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileThread__Read);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
