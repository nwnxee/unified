#include "Plane.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "Quaternion.hpp"

namespace NWNXLib {

namespace API {

void Plane::Transform(const Vector& a0, const Quaternion& a1)
{
    return Plane__Transform(this, a0, a1);
}

void Plane__Transform(Plane* thisPtr, const Vector& a0, const Quaternion& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(Plane*, const Vector&, const Quaternion&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::Plane__Transform);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
