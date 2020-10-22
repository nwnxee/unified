#pragma once

#include "Hooking/FunctionHook.hpp"
#include "Platform/ASLR.hpp"
#include "Services/Services.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

namespace NWNXLib::Services {

// Hooks provides a type-safe interface to register shared or exclusive function
// hooks and dispatch them to a provided function pointer.
// In the case of exclusive hook mode, the landing site for the hook is directly at the
// provided function pointer.
// In the case of shared hook mode, a landing site is magically generated (using thiscall
// calling convention) and events are dispatched to each hook one-by-one.

class Hooks
{
public: // Structures
    enum class Type
    {
        SHARED,
        EXCLUSIVE
    };

    struct HookStorage
    {
        std::unique_ptr<Hooking::FunctionHook> m_hook;
        Type m_type;
        std::vector<uintptr_t> m_subscribers;
    };

    struct RegistrationToken
    {
        uintptr_t m_oldAddress;
        uintptr_t m_newAddress;
    };

private: // Structures
    using GenericHookMap = std::unordered_map<uintptr_t, std::unique_ptr<HookStorage>>;

public:
    Hooks();
    ~Hooks();

    template <uintptr_t Address, typename Ret, typename ... Params>
    RegistrationToken RequestSharedHook(void(*funcPtr)(bool, Params ...));

    template <uintptr_t Address, typename Ret, typename ... Params>
    RegistrationToken RequestExclusiveHook(Ret(*funcPtr)(Params ...));

    void ClearHook(RegistrationToken&& token);

    Hooking::FunctionHook* FindHookByAddress(const uintptr_t address);
    HookStorage* FindHookStorageByAddress(const uintptr_t address);

private:
    GenericHookMap m_hooks;
};

class HooksProxy : public ServiceProxy<Hooks>
{
public:
    HooksProxy(Hooks& hooks);
    ~HooksProxy();

    template <uintptr_t Address, typename Ret, typename ... Params>
    void RequestSharedHook(void(*funcPtr)(bool, Params ...));

    template <uintptr_t Address, typename Ret, typename ... Params>
    Hooking::FunctionHook* RequestExclusiveHook(Ret(*funcPtr)(Params ...));

    void ClearHook(const uintptr_t address);
    Hooking::FunctionHook* FindHookByAddress(const uintptr_t address);
    Hooks::HookStorage* FindHookStorageByAddress(const uintptr_t address);

private:
    std::vector<Hooks::RegistrationToken> m_registrationTokens;
};

#include "Services/Hooks/HooksImpl.hpp"

template <uintptr_t Address, typename Ret, typename ... Params>
Hooks::RegistrationToken Hooks::RequestSharedHook(void(*funcPtr)(bool, Params ...))
{
    const uintptr_t funcPtrAddr = reinterpret_cast<uintptr_t>(funcPtr);
    auto hookStorage = m_hooks.find(Address);

    if (hookStorage != m_hooks.end())
    {
        if (hookStorage->second->m_type != Type::SHARED)
        {
            throw std::runtime_error("An exclusive hook has already been applied in this memory location.");
        }

        auto& subscribers = hookStorage->second->m_subscribers;

        if (std::find(subscribers.begin(), subscribers.end(), funcPtrAddr) != subscribers.end())
        {
            throw std::runtime_error("This handler has already been registered with this shared hook.");
        }

        subscribers.push_back(funcPtrAddr);
    }
    else
    {
        using SharedHandlerFuncPtr = Ret(*)(Params ...);

        SharedHandlerFuncPtr handler = &HooksImpl::HookLandingHolderShared::
            template HookLanding<Address, Ret, Params ...>;

        const uintptr_t sharedHandlerAddress = reinterpret_cast<uintptr_t>(handler);
        const uintptr_t aslrAddress = Platform::ASLR::GetRelocatedAddress(Address);

        auto newHookStorage = std::make_unique<HookStorage>();
        newHookStorage->m_type = Type::SHARED;
        newHookStorage->m_hook = std::make_unique<Hooking::FunctionHook>(aslrAddress, sharedHandlerAddress);
        newHookStorage->m_subscribers.push_back(funcPtrAddr);

        HooksImpl::template HookLandingHolderDataShared<Address>::s_hook = newHookStorage->m_hook.get();
        HooksImpl::template HookLandingHolderDataShared<Address>::s_subs = &newHookStorage->m_subscribers;

        m_hooks.insert(std::make_pair(Address, std::move(newHookStorage)));
    }

    return { Address, funcPtrAddr };
}

template <uintptr_t Address, typename Ret, typename ... Params>
Hooks::RegistrationToken Hooks::RequestExclusiveHook(Ret(*funcPtr)(Params ...))
{
    const uintptr_t funcPtrAddr = reinterpret_cast<uintptr_t>(funcPtr);
    auto hookStorage = m_hooks.find(Address);

    if (hookStorage != m_hooks.end())
    {
        throw std::runtime_error("Another hook has already been applied in this memory location.");
    }
    else
    {
        using SharedHandlerFuncPtr = Ret(*)(Params ...);

        SharedHandlerFuncPtr handler = &HooksImpl::HookLandingHolderExclusive::
            template HookLanding<Address, Ret, Params ...>;

        const uintptr_t sharedHandlerAddress = reinterpret_cast<uintptr_t>(handler);
        const uintptr_t aslrAddress = Platform::ASLR::GetRelocatedAddress(Address);

        auto newHookStorage = std::make_unique<HookStorage>();
        newHookStorage->m_type = Type::EXCLUSIVE;
        newHookStorage->m_hook = std::make_unique<Hooking::FunctionHook>(aslrAddress, sharedHandlerAddress);
        newHookStorage->m_subscribers.emplace_back(funcPtrAddr);

        HooksImpl::template HookLandingHolderDataExclusive<Address>::s_addr = funcPtrAddr;

        m_hooks.insert(std::make_pair(Address, std::move(newHookStorage)));
    }

    return { Address, funcPtrAddr };
}

template <uintptr_t Address, typename Ret, typename ... Params>
void HooksProxy::RequestSharedHook(void(*funcPtr)(bool, Params ...))
{
    m_registrationTokens.push_back(m_proxyBase.RequestSharedHook<Address, Ret>(funcPtr));
}

template <uintptr_t Address, typename Ret, typename ... Params>
Hooking::FunctionHook* HooksProxy::RequestExclusiveHook(Ret(*funcPtr)(Params ...))
{
    m_registrationTokens.push_back(m_proxyBase.RequestExclusiveHook<Address, Ret>(funcPtr));
    return FindHookByAddress(Address);
}

}
