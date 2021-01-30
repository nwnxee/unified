#pragma once
#include "nwnx.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>
extern "C" {
    #include "External/funchook/include/funchook.h"
}

namespace NWNXLib::Hooking {

namespace Order
{
    constexpr int32_t SharedHook = INT32_MIN;
    constexpr int32_t Earliest = -3000000;
    constexpr int32_t VeryEarly = -2000000;
    constexpr int32_t Early = -1000000;
    constexpr int32_t Default = 0;
    constexpr int32_t Late = 1000000;
    constexpr int32_t VeryLate = 2000000;
    constexpr int32_t Latest = 3000000;
    constexpr int32_t Final = INT32_MAX;
}

class FunctionHook final
{
public:
    FunctionHook(uintptr_t originalFunction, void* newFunction, int32_t order = Hooking::Order::Default)
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
            ASSERT(!funchook_uninstall(v[i]->m_funchook, 0));
            ASSERT(!funchook_destroy(v[i]->m_funchook));
        }

        v.insert(v.begin() + insert, this);
        
        for (int32_t i = insert; i < (int32_t)v.size(); i++)
        {
            v[i]->m_trampoline = (void*)originalFunction;
            ASSERT(v[i]->m_funchook = funchook_create());
            ASSERT(!funchook_prepare(v[i]->m_funchook, &v[i]->m_trampoline, v[i]->m_newFunction));
            ASSERT(!funchook_install(v[i]->m_funchook, 0));
        }
    }
    ~FunctionHook()
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
        funchook_uninstall(m_funchook, 0);
        funchook_destroy(m_funchook);
    }
    template <typename Ret, typename ... Params>
    Ret CallOriginal(Params ... args)
    {
        return reinterpret_cast<Ret(*)(Params...)>(GetOriginal())(args ...);
    }

    void *GetOriginal() { return m_trampoline; }
private:
    uintptr_t   m_originalFunction;
    void*       m_newFunction;
    int32_t     m_order;
    funchook_t* m_funchook;
    void*       m_trampoline;
    static inline std::unordered_map<uintptr_t, std::vector<FunctionHook*>> s_hooks;

};
}

namespace NWNXLib::Services {
class Hooks
{
public:
    std::unique_ptr<Hooking::FunctionHook> Hook(uintptr_t address, void* funcPtr, int32_t order = Hooking::Order::Default)
    {
        return std::make_unique<Hooking::FunctionHook>(Platform::GetRelocatedAddress(address), funcPtr, order);
    }

    template <uintptr_t Address, typename Ret, typename ... Params>
    void RequestSharedHook(void(*funcPtr)(bool, Params ...))
    {
        static std::vector<void(*)(bool, Params...)> observers;
        observers.push_back(funcPtr);

        static Hooking::FunctionHook *original;
        if (!original)
        {
            original = m_sharedHooks.emplace_back(Hook(Address, (void*)
                +[](Params ... args) -> Ret
                {
                    SCOPEGUARD(for (auto o: observers) o(false, args...));
                    for (auto o : observers)
                        o(true, args...);

                    return original->CallOriginal<Ret>(args...);
                }, Hooking::Order::SharedHook)).get();
        }
    }
private:
    std::vector<std::unique_ptr<Hooking::FunctionHook>> m_sharedHooks;
};

// NOTE: The templated versions are deprecated, use Hook() in new code
class HooksProxy : public ServiceProxy<Hooks>
{
public:
    HooksProxy(Hooks& hooks) : ServiceProxy<Hooks>(hooks) {}

    template <uintptr_t Address, typename Ret, typename ... Params>
    void RequestSharedHook(void(*funcPtr)(bool, Params ...))
    {
        m_proxyBase.RequestSharedHook<Address, Ret>(funcPtr);
    }

    template <uintptr_t Address, typename Ret, typename ... Params>
    Hooking::FunctionHook* RequestExclusiveHook(Ret(*funcPtr)(Params ...))
    {
        return m_hooks.emplace_back(m_proxyBase.Hook(Address, (void*)funcPtr)).get();
    }
    Hooking::FunctionHook* Hook(uintptr_t address, void* funcPtr, int32_t order = Hooking::Order::Default)
    {
        return m_hooks.emplace_back(m_proxyBase.Hook(address, funcPtr, order)).get();
    }

private:
    std::vector<std::unique_ptr<Hooking::FunctionHook>> m_hooks;
};
}
