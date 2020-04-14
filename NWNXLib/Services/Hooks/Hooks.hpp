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

#include "Services/Hooks/Hooks.inl"

}
