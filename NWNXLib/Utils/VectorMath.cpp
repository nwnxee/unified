#include "nwnx.hpp"
#include "cmath"

namespace NWNXLib::VectorMath
{
    float MagnitudeSquared(const Vector& v)
    {
        return v.x * v.x + v.y * v.y + v.z * v.z;
    }

    float Magnitude(const Vector& v)
    {
        float f = MagnitudeSquared(v);

        if (f == 1.0f)
            return f;
        else if (f <= 0.0f)
            return 0.0f;

        return std::sqrt(f);
    }

    float Dot(const Vector& a, const Vector& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    Vector Add(const Vector& a, const Vector& b)
    {
        Vector v = a;
        v.x += b.x;
        v.y += b.y;
        v.z += b.z;
        return v;
    }

    Vector Subtract(const Vector& a, const Vector& b)
    {
        Vector v = a;
        v.x -= b.x;
        v.y -= b.y;
        v.z -= b.z;
        return v;
    }

    Vector Multiply(const Vector& v, const float f)
    {
        return Vector(v.x * f, v.y * f, v.z * f);
    }

    Vector Normalize(const Vector &v)
    {
        float f = MagnitudeSquared(v);

        if (f == 1.0f)
            return v;
        else if (f <= 0.0f)
            return Vector(1.0f, 0.0f, 0.0f);

        f = std::sqrt(1 / f);
        return Multiply(v, f);
    }

    Vector Lineproject(const Vector &a, const Vector &b, const Vector &c)
    {
        Vector v = Subtract(b, a);
        float f = MagnitudeSquared(v);

        if (f)
            f = Dot(v, Subtract(c, a)) / f;

        return Add(a, Multiply(v, f));
    }
}
