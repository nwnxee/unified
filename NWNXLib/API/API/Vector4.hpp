#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(Vector4)
#endif





struct Vector4
{
    float x;
    float y;
    float z;
    float w;

    Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
    Vector4(float xx, float yy, float zz, float ww) : x(xx), y(yy), z(zz), w(ww) { }

#ifdef NWN_CLASS_EXTENSION_Vector
    NWN_CLASS_EXTENSION_Vector
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(Vector4)
#endif

