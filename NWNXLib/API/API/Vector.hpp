#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(Vector)
#endif




inline Vector operator+(const Vector& v1, const Vector& v2);
inline Vector operator-(const Vector& v1, const Vector& v2);
inline Vector operator-(const Vector& v);
inline Vector operator*(const Vector& v, float s);
inline Vector operator*(float s, const Vector& v);
inline Vector operator/(const Vector& v, float s);

struct Vector
{
    float x;
    float y;
    float z;

    Vector() : x(0.0f), y(0.0f), z(0.0f) { }
    Vector(float xx, float yy, float zz) : x(xx), y(yy), z(zz) { }

    int IsZero() const
    {
        if (x == 0 && y == 0 && z == 0)
            return 1;
        return 0;
    }

    bool operator==(Vector& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }
    bool operator!=(Vector& v) const
    {
        return x != v.x || y != v.y || z != v.z;
    }
    Vector& operator+=(const Vector& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    Vector& operator-=(const Vector& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    Vector& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    Vector& operator/=(float s)
    {
        if (s)
        {
            float i = 1.0f / s;
            x *= i;
            y *= i;
            z *= i;
            return *this;
        }
        else
            return *this;
    }

    static float MagnitudeSquared(const Vector& v)
    {
        return v.x * v.x + v.y * v.y + v.z * v.z;
    }

    static float Magnitude(const Vector& v)
    {
        float f = MagnitudeSquared(v);
        if (f == 1.0f)
            return f;
        else if (f <= 0.0f)
            return 0.0f;

        return std::sqrt(f);
    }

    static float Dot(const Vector& v1, const Vector& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    void Normalize()
    {
        float f = MagnitudeSquared(*this);
        if (f == 1.0f)
            return;
        else if (f <= 0.0f)
        {
            x = 1.0f;
            y = 0.0f;
            z = 0.0f;
            return;
        }
        f = std::sqrt(1 / f);
        x *= f;
        y *= f;
        z *= f;
    }

    static Vector Normalize(const Vector &v)
    {
        float f = MagnitudeSquared(v);
        if (f == 1.0f) return v;
        else if (f <= 0.0f) return {1.0f, 0.0f, 0.0f};
        f = std::sqrt(1 / f);
        return {v.x * f, v.y * f, v.z * f};
    }

    static Vector Lineproject(const Vector &p0, const Vector &p1, const Vector &a)
    {
        Vector w = p1 - p0;
        float t = MagnitudeSquared(w);
        if (t) t = Dot(w, a - p0) / t;
        return p0 + w * t;
    }

    std::string ToString() const
    {
        return "{" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "}";
    }

#ifdef NWN_CLASS_EXTENSION_Vector
    NWN_CLASS_EXTENSION_Vector
#endif
};

inline Vector operator+(const Vector& v1, const Vector& v2)
{
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}
inline Vector operator-(const Vector& v1, const Vector& v2)
{
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}
inline Vector operator-(const Vector& v)
{
    return {-v.x, -v.y, -v.z};
}
inline Vector operator*(const Vector& v, float s)
{
    return {v.x * s, v.y * s, v.z * s};
}
inline Vector operator*(float s, const Vector& v)
{
    return {v.x * s, v.y * s, v.z * s};
}
inline Vector operator/(const Vector& v, float s)
{
    return s ? v * (1.0f / s) : v;
}


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(Vector)
#endif

