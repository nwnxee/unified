#include "nwnx.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>
#include "External/funchook/include/funchook.h"

using namespace NWNXLib;
namespace NWNXLib::Hooks
{

FunctionHook::FunctionHook(void* originalFunction, void* newFunction, int32_t order)
    : m_originalFunction(originalFunction), m_newFunction(newFunction), m_order(order)
{
    m_trampoline = nullptr;
    m_funchook = nullptr;

    auto &funcHooks = s_hooks[originalFunction];
    if (order == Order::Final && !funcHooks.empty() && funcHooks[0]->m_order == Order::Final)
        throw std::runtime_error("Multiple hooks with final ordering requested");

    auto insert = static_cast<int32_t>(funcHooks.size());
    for (int32_t i = 0; i < static_cast<int32_t>(funcHooks.size()); i++)
    {
        if (funcHooks[i]->m_order < m_order)
        {
            insert = i;
            break;
        }
        if (funcHooks[i]->m_order == m_order)
            m_order--;
    }

    UpdateHookList(originalFunction, funcHooks, insert, [&funcHooks, insert, this]
    {
        funcHooks.insert(funcHooks.begin() + insert, this);
    });
}

FunctionHook::~FunctionHook()
{
    auto &funcHooks = s_hooks[m_originalFunction];

    int32_t remove = -1;
    for (int32_t i = 0; i < static_cast<int32_t>(funcHooks.size()); i++)
    {
        if (funcHooks[i] == this)
        {
            remove = i;
            break;
        }
    }

    if (remove == -1)
    {
        LOG_WARNING("Attempt to remove unknown function hook.");
        return;
    }

    UpdateHookList(m_originalFunction, funcHooks, remove, [&funcHooks, remove]
    {
        funcHooks.erase(funcHooks.begin() + remove);
    });
}

template <typename F>
void FunctionHook::UpdateHookList(void* originalFunction, const std::vector<FunctionHook*>& hookList, const int32_t index, F&& hookOperation)
{
    for (int32_t i = static_cast<int32_t>(hookList.size()) - 1; i >= index; i--)
    {
        ASSERT(!funchook_uninstall(static_cast<funchook_t*>(hookList[i]->m_funchook), 0));
        ASSERT(!funchook_destroy(static_cast<funchook_t*>(hookList[i]->m_funchook)));
    }

    hookOperation();

    for (int32_t i = index; i < static_cast<int32_t>(hookList.size()); i++)
    {
        hookList[i]->m_trampoline = originalFunction;
        hookList[i]->m_funchook = funchook_create();
        ASSERT(hookList[i]->m_funchook);
        ASSERT(!funchook_prepare(static_cast<funchook_t*>(hookList[i]->m_funchook), &hookList[i]->m_trampoline, hookList[i]->m_newFunction));
        ASSERT(!funchook_install(static_cast<funchook_t*>(hookList[i]->m_funchook), 0));
    }
}

};
