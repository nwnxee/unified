#include "CTlkResFile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

CTlkResFile::CTlkResFile(const CResRef& a0)
{
    CTlkResFile__CTlkResFileCtor__0(this, a0);
}

CTlkResFile::~CTlkResFile()
{
    CTlkResFile__CTlkResFileDtor__0(this);
}

void CTlkResFile__CTlkResFileCtor__0(CTlkResFile* thisPtr, const CResRef& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkResFile*, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkResFile__CTlkResFileCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CTlkResFile__CTlkResFileDtor__0(CTlkResFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkResFile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkResFile__CTlkResFileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
