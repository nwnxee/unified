#pragma once
#include "Platform/ASLR.hpp"
#include "Services/Services.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>
extern "C" {
    #include "External/funchook/include/funchook.h"
}

namespace NWNXLib::Hooking {
class FunctionHook final
{
public:
    FunctionHook(uintptr_t originalFunction, void* newFunction)
    {
        ASSERT(m_funchook = funchook_create());
        ASSERT(!funchook_prepare(m_funchook, (void **)&originalFunction, newFunction));
        ASSERT(!funchook_install(m_funchook, 0));
        ASSERT(m_trampoline = (void *)originalFunction);
    }
    ~FunctionHook()
    {
        funchook_uninstall(m_funchook, 0);
        funchook_destroy(m_funchook);
    }
    template <typename Ret, typename ... Params>
    Ret CallOriginal(Params ... args)
    {
        return reinterpret_cast<Ret(*)(Params...)>(m_trampoline)(args ...);
    }
private:
    funchook_t* m_funchook;
    void*       m_trampoline;
};
}

namespace NWNXLib::Services {
class Hooks
{
public:
    std::unique_ptr<Hooking::FunctionHook> Hook(uintptr_t address, void* funcPtr)
    {
        return std::make_unique<Hooking::FunctionHook>(Platform::ASLR::GetRelocatedAddress(address), funcPtr);
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
                })).get();
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
    Hooking::FunctionHook* Hook(uintptr_t address, void* funcPtr)
    {
        return m_hooks.emplace_back(m_proxyBase.Hook(address, funcPtr)).get();
    }

private:
    std::vector<std::unique_ptr<Hooking::FunctionHook>> m_hooks;
};
}
