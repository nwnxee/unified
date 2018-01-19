#include "CTlkFile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CTlkFile::CTlkFile(CExoString a0)
{
    CTlkFile__CTlkFileCtor__0(this, a0);
}

int32_t CTlkFile::ReadHeader()
{
    return CTlkFile__ReadHeader(this);
}

void CTlkFile__CTlkFileCtor__0(CTlkFile* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkFile*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkFile__CTlkFileCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

int32_t CTlkFile__ReadHeader(CTlkFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTlkFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkFile__ReadHeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
