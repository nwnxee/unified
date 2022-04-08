#pragma once
#include "nwn_api.hpp"

#include "LerpFloat.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(LerpVector)
#endif



struct LerpVector
{
    LerpFloat x;
    LerpFloat y;
    LerpFloat z;


    LerpVector(float vx, float vy, float vz) : x(vx), y(vy), z(vz) {}

    LerpVector(const LerpVector& other) { *this = other; }

    LerpVector& operator=(const LerpVector& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LerpVector& operator=(const Vector& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    bool operator==(const LerpVector& rhs) const {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    Vector Value() const {
        return Vector(x.Value(), y.Value(), z.Value());
    }

    Vector Lerped() const {
        return Vector(x.Lerped(), y.Lerped(), z.Lerped());
    }

#ifdef NWN_CLASS_EXTENSION_LerpVector
    NWN_CLASS_EXTENSION_LerpVector
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(LerpVector)
#endif

