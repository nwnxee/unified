#include "CVirtualMachineFile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

CVirtualMachineFile::CVirtualMachineFile()
{
    CVirtualMachineFile__CVirtualMachineFileCtor__0(this);
}

CVirtualMachineFile::~CVirtualMachineFile()
{
    CVirtualMachineFile__CVirtualMachineFileDtor__0(this);
}

void CVirtualMachineFile::GetData(char** a0, uint32_t& a1)
{
    return CVirtualMachineFile__GetData(this, a0, a1);
}

int32_t CVirtualMachineFile::LoadFile(const CExoString& a0)
{
    return CVirtualMachineFile__LoadFile(this, a0);
}

void CVirtualMachineFile::UnloadFile()
{
    return CVirtualMachineFile__UnloadFile(this);
}

void CVirtualMachineFile__CVirtualMachineFileCtor__0(CVirtualMachineFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineFile__CVirtualMachineFileCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CVirtualMachineFile__CVirtualMachineFileDtor__0(CVirtualMachineFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineFile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineFile__CVirtualMachineFileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CVirtualMachineFile__GetData(CVirtualMachineFile* thisPtr, char** a0, uint32_t& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineFile*, char**, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineFile__GetData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CVirtualMachineFile__LoadFile(CVirtualMachineFile* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CVirtualMachineFile*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineFile__LoadFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CVirtualMachineFile__UnloadFile(CVirtualMachineFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineFile__UnloadFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
