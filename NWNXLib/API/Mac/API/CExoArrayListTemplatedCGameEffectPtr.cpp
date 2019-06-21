#include "CExoArrayListTemplatedCGameEffectPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CGameEffect.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCGameEffectPtr::~CExoArrayListTemplatedCGameEffectPtr()
{
    CExoArrayListTemplatedCGameEffectPtr__CExoArrayListTemplatedCGameEffectPtrDtor(this);
}

void CExoArrayListTemplatedCGameEffectPtr__CExoArrayListTemplatedCGameEffectPtrDtor(CExoArrayListTemplatedCGameEffectPtr* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCGameEffectPtr*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCGameEffectPtr__CExoArrayListTemplatedCGameEffectPtrDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
