#pragma once

#include <cstdint>

#include "unknown_MaterialShaderParam__Type.hpp"

namespace NWNXLib {

namespace API {

struct MaterialShaderParam
{
    MaterialShaderParam__Type m_nType;
    char m_sMaterialName[17];
    char m_sParamName[65];
    uint8_t _padding[2];
    int32_t m_nValue;
    float m_fValue1;
    float m_fValue2;
    float m_fValue3;
    float m_fValue4;
};

}

}
