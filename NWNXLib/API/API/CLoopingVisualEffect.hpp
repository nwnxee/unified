#pragma once
#include "nwn_api.hpp"

#include "ObjectVisualTransformData.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CLoopingVisualEffect)
#endif



typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CLoopingVisualEffect
{
    uint16_t m_nId;
    OBJECT_ID m_oOriginator;
    uint8_t m_nBodyPart;
    ObjectVisualTransformData m_ovtd;

    CLoopingVisualEffect();
    BOOL GetIsBeam();


#ifdef NWN_CLASS_EXTENSION_CLoopingVisualEffect
    NWN_CLASS_EXTENSION_CLoopingVisualEffect
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CLoopingVisualEffect)
#endif

