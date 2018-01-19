#include "Vector4.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void Vector4::Normalize()
{
    return Vector4__Normalize(this);
}

void Vector4__Normalize(Vector4* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(Vector4*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::Vector4__Normalize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
