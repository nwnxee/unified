#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(Vector)
#endif





struct Vector
{
    float x;
    float y;
    float z;

    Vector() : x(0.0f), y(0.0f), z(0.0f) { }
    Vector(float xx, float yy, float zz) : x(xx), y(yy), z(zz) { }

#ifdef NWN_CLASS_EXTENSION_Vector
    NWN_CLASS_EXTENSION_Vector
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(Vector)
#endif

