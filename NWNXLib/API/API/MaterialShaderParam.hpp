#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(MaterialShaderParam)
#endif





class MaterialShaderParam
{
    int m_nType;
    char m_sMaterialName[16+1];
    char m_sParamName[64+1];
    int m_nValue;
    float m_fValue1;
    float m_fValue2;
    float m_fValue3;
    float m_fValue4;



#ifdef NWN_CLASS_EXTENSION_MaterialShaderParam
    NWN_CLASS_EXTENSION_MaterialShaderParam
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(MaterialShaderParam)
#endif

