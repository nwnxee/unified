#include "CExoArrayListTemplatedunsignedlonglong.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedunsignedlonglong::Add(uint64_t a0)
{
    return CExoArrayListTemplatedunsignedlonglong__Add(this, a0);
}

void CExoArrayListTemplatedunsignedlonglong::AddUnique(uint64_t a0)
{
    return CExoArrayListTemplatedunsignedlonglong__AddUnique(this, a0);
}

void CExoArrayListTemplatedunsignedlonglong__Add(CExoArrayListTemplatedunsignedlonglong* thisPtr, uint64_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedunsignedlonglong*, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedunsignedlonglong__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoArrayListTemplatedunsignedlonglong__AddUnique(CExoArrayListTemplatedunsignedlonglong* thisPtr, uint64_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedunsignedlonglong*, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedunsignedlonglong__AddUnique);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

}

}
