#include "CVirtualMachineCache.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

CVirtualMachineCache::~CVirtualMachineCache()
{
    CVirtualMachineCache__CVirtualMachineCacheDtor__0(this);
}

void CVirtualMachineCache::ClearAllFiles()
{
    return CVirtualMachineCache__ClearAllFiles(this);
}

void CVirtualMachineCache::PrecacheFile(const CExoString& a0)
{
    return CVirtualMachineCache__PrecacheFile(this, a0);
}

void CVirtualMachineCache__CVirtualMachineCacheDtor__0(CVirtualMachineCache* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineCache*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineCache__CVirtualMachineCacheDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CVirtualMachineCache__ClearAllFiles(CVirtualMachineCache* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineCache*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineCache__ClearAllFiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CVirtualMachineCache__PrecacheFile(CVirtualMachineCache* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineCache*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineCache__PrecacheFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
