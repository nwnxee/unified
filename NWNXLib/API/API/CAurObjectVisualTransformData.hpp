#pragma once
#include "nwn_api.hpp"

#include "LerpFloat.hpp"
#include "LerpVector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CAurObjectVisualTransformData)
#endif



struct CAurObjectVisualTransformData
{
    LerpVector m_scale;
    LerpVector m_rotate;
    LerpVector m_translate;
    LerpFloat m_animationSpeed;

    CAurObjectVisualTransformData() :
        m_scale(LerpVector{1.0, 1.0, 1.0}),
        m_rotate(LerpVector{0.0, 0.0, 0.0}),
        m_translate(LerpVector{0.0, 0.0, 0.0}),
        m_animationSpeed(1.0) {}

#ifdef NWN_CLASS_EXTENSION_CAurObjectVisualTransformData
    NWN_CLASS_EXTENSION_CAurObjectVisualTransformData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CAurObjectVisualTransformData)
#endif

