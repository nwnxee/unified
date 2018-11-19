#include "CResTLK.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResTLK::CResTLK()
{
    CResTLK__CResTLKCtor__0(this);
}

CResTLK::~CResTLK()
{
    CResTLK__CResTLKDtor__0(this);
}

void CResTLK__CResTLKCtor__0(CResTLK* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResTLK*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTLK__CResTLKCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CResTLK__CResTLKDtor__0(CResTLK* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResTLK*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTLK__CResTLKDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
