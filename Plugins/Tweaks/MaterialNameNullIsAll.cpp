#include "nwnx.hpp"

#include "ctype.h"
#include "API/CNWSObject.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


static void sanitize(const char* unsafe, char *safe, int32_t maxlen)
{
    memset(safe, 0, maxlen + 1);
    for (int i = 0, k = 0; i <= maxlen && unsafe[k] != '\0'; k++)
    {
        char c = unsafe[k];
        if (isalnum(c) || c == '_')
        {
            safe[i++] = tolower(c);
        }
    }
}

constexpr int MAX_MATERIAL_NAME = 16;
constexpr int MAX_PARAM_NAME = 64;
constexpr int MAX_SHADER_UNIFORMS = 1024;
void hook_SetMaterialShaderParamI(CNWSObject* pThis, const CExoString& sMaterialName, const CExoString& sParamName, int nValue)
{
    char safeMaterial[MAX_MATERIAL_NAME+1];
    char safeParam[MAX_PARAM_NAME+1];

    sanitize(sMaterialName.CStr(), safeMaterial, MAX_MATERIAL_NAME);
    sanitize(sParamName.CStr(), safeParam, MAX_PARAM_NAME);

    // Clear any that might be duplicates
    if (safeMaterial[0] == 0)
    {
        for (int i = pThis->m_lMaterialShaderParameters.num - 1; i > 0; i--)
        {
            auto& p = pThis->m_lMaterialShaderParameters[i];
            if (!strcmp(p.m_sParamName, safeParam))
                pThis->m_lMaterialShaderParameters.DelIndex(i);
        }
    }
    else
    {
        for (auto& p : pThis->m_lMaterialShaderParameters)
        {
            if (!strcmp(p.m_sMaterialName, safeMaterial) &&
                !strcmp(p.m_sParamName, safeParam))
            {
                p.m_nType = 1; // int
                p.m_nValue = nValue;
                return;
            }
        }
    }

    if (pThis->m_lMaterialShaderParameters.num >= MAX_SHADER_UNIFORMS)
        return;

    MaterialShaderParam p;
    p.m_nType = 1;
    p.m_nValue = nValue;
    strcpy(p.m_sMaterialName, safeMaterial);
    strcpy(p.m_sParamName, safeParam);

    pThis->m_lMaterialShaderParameters.Add(p);
}
void hook_SetMaterialShaderParamVec4(CNWSObject* pThis, const CExoString& sMaterialName, const CExoString& sParamName,
                                     float fValue1, float fValue2, float fValue3, float fValue4)
{
    char safeMaterial[MAX_MATERIAL_NAME+1];
    char safeParam[MAX_PARAM_NAME+1];

    sanitize(sMaterialName.CStr(), safeMaterial, MAX_MATERIAL_NAME);
    sanitize(sParamName.CStr(), safeParam, MAX_PARAM_NAME);

    // Clear any that might be duplicates
    if (safeMaterial[0] == 0)
    {
        for (int i = pThis->m_lMaterialShaderParameters.num - 1; i > 0; i--)
        {
            auto& p = pThis->m_lMaterialShaderParameters[i];
            if (!strcmp(p.m_sParamName, safeParam))
                pThis->m_lMaterialShaderParameters.DelIndex(i);
        }
    }
    else
    {
        for (auto& p : pThis->m_lMaterialShaderParameters)
        {
            if (!strcmp(p.m_sMaterialName, safeMaterial) &&
                !strcmp(p.m_sParamName, safeParam))
            {
                p.m_nType = 2; // vec4
                p.m_fValue1 = fValue1;
                p.m_fValue2 = fValue2;
                p.m_fValue3 = fValue3;
                p.m_fValue4 = fValue4;
                return;
            }
        }
    }

    if (pThis->m_lMaterialShaderParameters.num >= MAX_SHADER_UNIFORMS)
        return;

    MaterialShaderParam p;
    p.m_nType = 2; // vec4
    p.m_fValue1 = fValue1;
    p.m_fValue2 = fValue2;
    p.m_fValue3 = fValue3;
    p.m_fValue4 = fValue4;
    strcpy(p.m_sMaterialName, safeMaterial);
    strcpy(p.m_sParamName, safeParam);

    pThis->m_lMaterialShaderParameters.Add(p);
}


void MaterialNameNullIsAll() __attribute__((constructor));
void MaterialNameNullIsAll()
{
    if (!Config::Get<bool>("MATERIAL_NAME_NULL_IS_ALL", false))
        return;

    LOG_INFO("Passing sMaterial=\"\" to SetMaterialShaderUniformXxx() will apply to all materials");

    static auto s_SetInt = Hooks::HookFunction(
        Functions::_ZN10CNWSObject23SetMaterialShaderParamIERK10CExoStringS2_i,
        (void*)hook_SetMaterialShaderParamI, Hooks::Order::Final);

    static auto s_SetVec4 = Hooks::HookFunction(
        Functions::_ZN10CNWSObject26SetMaterialShaderParamVec4ERK10CExoStringS2_ffff,
        (void*)hook_SetMaterialShaderParamVec4, Hooks::Order::Final);
}

}
