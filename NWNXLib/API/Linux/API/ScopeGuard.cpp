#include "ScopeGuard.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

ScopeGuard::~ScopeGuard()
{
    ScopeGuard__ScopeGuardDtor(this);
}

void ScopeGuard__ScopeGuardDtor(ScopeGuard* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(ScopeGuard*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ScopeGuard__ScopeGuardDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
