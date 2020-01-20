#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWAnimBase)
#endif



typedef int BOOL;


struct CNWAnimBase
{
    float m_fWalkSpeed;
    float m_fRunSpeed;
    float m_fWalkAcceleration;
    float m_fRunAcceleration;

    CNWAnimBase();
    virtual ~CNWAnimBase();
    BOOL Get(int32_t nCharacteristic, float * pValue);
    BOOL Set(int32_t nCharacteristic, float fValue);


#ifdef NWN_CLASS_EXTENSION_CNWAnimBase
    NWN_CLASS_EXTENSION_CNWAnimBase
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWAnimBase)
#endif

