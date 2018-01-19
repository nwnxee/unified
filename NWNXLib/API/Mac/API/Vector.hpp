#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct Vector
{
    float x;
    float y;
    float z;

    void Normalize();
    Vector& operator*=(float);
    Vector& operator/=(float);
    Vector& operator+=(const Vector&);
    Vector& operator-=(const Vector&);
};

void Vector__Normalize(Vector* thisPtr);
Vector& Vector__OperatorMultiplicationAssignment(Vector* thisPtr, float);
Vector& Vector__OperatorDivisionAssignment(Vector* thisPtr, float);
Vector& Vector__OperatorAdditionAssignment(Vector* thisPtr, const Vector&);
Vector& Vector__OperatorSubtractionAssignment(Vector* thisPtr, const Vector&);

}

}
