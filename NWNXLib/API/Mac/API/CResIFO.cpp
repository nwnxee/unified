#include "CResIFO.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResIFO::CResIFO()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CResIFO::CResIFO(const CResIFO&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CResIFO& CResIFO::operator=(const CResIFO&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CResIFO::~CResIFO()
{
    CResIFO__CResIFODtor__0(this);
}

void CResIFO__CResIFODtor__0(CResIFO* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResIFO*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResIFO__CResIFODtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
