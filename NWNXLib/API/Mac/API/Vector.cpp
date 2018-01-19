#include "Vector.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void Vector::Normalize()
{
    return Vector__Normalize(this);
}

Vector& Vector::operator*=(float a0)
{
    return Vector__OperatorMultiplicationAssignment(this, a0);
}

Vector& Vector::operator/=(float a0)
{
    return Vector__OperatorDivisionAssignment(this, a0);
}

Vector& Vector::operator+=(const Vector& a0)
{
    return Vector__OperatorAdditionAssignment(this, a0);
}

Vector& Vector::operator-=(const Vector& a0)
{
    return Vector__OperatorSubtractionAssignment(this, a0);
}

void Vector__Normalize(Vector* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::Vector__Normalize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

Vector& Vector__OperatorMultiplicationAssignment(Vector* thisPtr, float a0)
{
    using FuncPtrType = Vector&(__attribute__((cdecl)) *)(Vector*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::Vector__OperatorMultiplicationAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

Vector& Vector__OperatorDivisionAssignment(Vector* thisPtr, float a0)
{
    using FuncPtrType = Vector&(__attribute__((cdecl)) *)(Vector*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::Vector__OperatorDivisionAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

Vector& Vector__OperatorAdditionAssignment(Vector* thisPtr, const Vector& a0)
{
    using FuncPtrType = Vector&(__attribute__((cdecl)) *)(Vector*, const Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::Vector__OperatorAdditionAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

Vector& Vector__OperatorSubtractionAssignment(Vector* thisPtr, const Vector& a0)
{
    using FuncPtrType = Vector&(__attribute__((cdecl)) *)(Vector*, const Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::Vector__OperatorSubtractionAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
