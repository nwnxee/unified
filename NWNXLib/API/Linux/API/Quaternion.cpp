#include "Quaternion.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

Quaternion& Quaternion::operator*=(float a0)
{
    return Quaternion__OperatorMultiplicationAssignment(this, a0);
}

Quaternion& Quaternion__OperatorMultiplicationAssignment(Quaternion* thisPtr, float a0)
{
    using FuncPtrType = Quaternion&(__attribute__((cdecl)) *)(Quaternion*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::Quaternion__OperatorMultiplicationAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
