#include "Matrix.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

Quaternion Matrix::getquaternion()
{
    return Matrix__getquaternion(this);
}

Quaternion Matrix__getquaternion(Matrix* thisPtr)
{
    using FuncPtrType = Quaternion(__attribute__((cdecl)) *)(Matrix*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::Matrix__getquaternion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
