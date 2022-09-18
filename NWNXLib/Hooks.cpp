#include "nwnx.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>
extern "C" {
    #include "External/funchook/include/funchook.h"
}

using namespace NWNXLib;
namespace NWNXLib::Hooks
{

FunctionHook::FunctionHook(void* originalFunction, void* newFunction, int32_t order)
    : m_originalFunction(originalFunction), m_newFunction(newFunction), m_order(order)
{
    auto &v = s_hooks[originalFunction];
    if (order == Order::Final && v.size() > 0 && v[0]->m_order == Order::Final)
        throw std::runtime_error("Multiple hooks with final ordering requested");

    int32_t insert = v.size();
    for (int32_t i = 0; i < (int32_t)v.size(); i++)
    {
        if (v[i]->m_order < m_order)
        {
            insert = i;
            break;
        }
        if (v[i]->m_order == m_order)
            m_order--;
    }

    for (int32_t i = v.size() - 1; i >= insert; i--)
    {
        ASSERT(!funchook_uninstall((funchook_t*) v[i]->m_funchook, 0));
        ASSERT(!funchook_destroy((funchook_t*) v[i]->m_funchook));
    }

    v.insert(v.begin() + insert, this);
    
    for (int32_t i = insert; i < (int32_t)v.size(); i++)
    {
        v[i]->m_trampoline = (void*)originalFunction;
        v[i]->m_funchook = (funchook_t*)funchook_create();
        ASSERT(v[i]->m_funchook);
        ASSERT(!funchook_prepare((funchook_t*)v[i]->m_funchook, &v[i]->m_trampoline, v[i]->m_newFunction));
        ASSERT(!funchook_install((funchook_t*)v[i]->m_funchook, 0));
    }
}

FunctionHook::~FunctionHook()
{
    auto &v = s_hooks[m_originalFunction];
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it == this)
        {
            v.erase(it);
            break;
        }
    }
    funchook_uninstall((funchook_t*)m_funchook, 0);
    funchook_destroy((funchook_t*)m_funchook);
}

};
