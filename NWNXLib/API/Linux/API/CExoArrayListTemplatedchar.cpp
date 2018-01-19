#include "CExoArrayListTemplatedchar.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedchar::Add(char a0)
{
    return CExoArrayListTemplatedchar__Add(this, a0);
}

void CExoArrayListTemplatedchar__Add(CExoArrayListTemplatedchar* thisPtr, char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedchar*, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedchar__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
