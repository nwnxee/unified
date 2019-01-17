#include "CExoArrayListTemplatedCLoopingVisualEffectPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CLoopingVisualEffect.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCLoopingVisualEffectPtr::~CExoArrayListTemplatedCLoopingVisualEffectPtr()
{
    CExoArrayListTemplatedCLoopingVisualEffectPtr__CExoArrayListTemplatedCLoopingVisualEffectPtrDtor(this);
}

void CExoArrayListTemplatedCLoopingVisualEffectPtr__CExoArrayListTemplatedCLoopingVisualEffectPtrDtor(CExoArrayListTemplatedCLoopingVisualEffectPtr* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCLoopingVisualEffectPtr*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCLoopingVisualEffectPtr__CExoArrayListTemplatedCLoopingVisualEffectPtrDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
