#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CAurObjectVisualTransformData)
#endif





struct CAurObjectVisualTransformData
{
    Vector m_scale;
    Vector m_rotate;
    Vector m_translate;
    float m_animationSpeed;

    CAurObjectVisualTransformData() :
        m_scale(Vector{1.0, 1.0, 1.0}),
        m_rotate(Vector{0.0, 0.0, 0.0}),
        m_translate(Vector{0.0, 0.0, 0.0}),
        m_animationSpeed(1.0) {}

#ifdef NWN_CLASS_EXTENSION_CAurObjectVisualTransformData
    NWN_CLASS_EXTENSION_CAurObjectVisualTransformData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CAurObjectVisualTransformData)
#endif

