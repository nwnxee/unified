#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(Vector2)
#endif





struct Vector2
{
    float x;
    float y;

    Vector2() : x(0.0f), y(0.0f){ }
    Vector2(float xx, float yy) : x(xx), y(yy) { }

#ifdef NWN_CLASS_EXTENSION_Vector
    NWN_CLASS_EXTENSION_Vector
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(Vector2)
#endif

