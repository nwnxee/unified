#pragma once

#include "Hooking/FunctionHook.hpp"
#include "Platform/ASLR.hpp"
#include "Platform/Hooking.hpp"
#include "Services/Services.hpp"
#include "ViewPtr.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

namespace NWNXLib {

namespace Services {

// Hooks provides a type-safe interface to register shared or exclusive function
// hooks and dispatch them to a provided function pointer.
// In the case of exclusive hook mode, the landing site for the hook is directly at the
// provided function pointer.
// In the case of shared hook mode, a landing site is magically generated (using thiscall
// calling convention) and events are dispatched to each hook one-by-one.

class Hooks : public ServiceBase
{
public: // Structures
    enum class Type
    {
        SHARED,
        EXCLUSIVE
    };

    enum class CallType
    {
        BEFORE_ORIGINAL,
        AFTER_ORIGINAL
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

    template <uintptr_t Address, typename CallingConvention, typename Ret, typename ... Params>
    typename std::enable_if<std::is_base_of<Hooking::CallingConvention::CallingConvention, CallingConvention>::value,
    RegistrationToken>::type RequestSharedHook(void(*funcPtr)(CallType, Params ...));

    template <uintptr_t Address, typename CallingConvention, typename Ret, typename ... Params>
    typename std::enable_if<std::is_base_of<Hooking::CallingConvention::CallingConvention, CallingConvention>::value,
    RegistrationToken>::type RequestExclusiveHook(Ret(*funcPtr)(Params ...));

    template <uintptr_t Address, typename Ret, typename ... Params>
    typename std::enable_if<!std::is_base_of<Hooking::CallingConvention::CallingConvention, Ret>::value,
    RegistrationToken>::type RequestSharedHook(void(*funcPtr)(CallType, Params ...));

    template <uintptr_t Address, typename Ret, typename ... Params>
    typename std::enable_if<!std::is_base_of<Hooking::CallingConvention::CallingConvention, Ret>::value,
    RegistrationToken>::type RequestExclusiveHook(Ret(*funcPtr)(Params ...));

    void ClearHook(RegistrationToken&& token);

    ViewPtr<Hooking::FunctionHook> FindHookByAddress(const uintptr_t address);
    ViewPtr<HookStorage> FindHookStorageByAddress(const uintptr_t address);

private:
    GenericHookMap m_hooks;
};

class HooksProxy : public ServiceProxy<Hooks>
{
public:
    HooksProxy(Hooks& hooks);
    ~HooksProxy();

    template <uintptr_t Address, typename CallingConvention, typename Ret, typename ... Params>
    typename std::enable_if<std::is_base_of<Hooking::CallingConvention::CallingConvention, CallingConvention>::value>::type
    /*void*/ RequestSharedHook(void(*funcPtr)(Hooks::CallType, Params ...));

    template <uintptr_t Address, typename CallingConvention, typename Ret, typename ... Params>
    typename std::enable_if<std::is_base_of<Hooking::CallingConvention::CallingConvention, CallingConvention>::value>::type
    /*void*/ RequestExclusiveHook(Ret(*funcPtr)(Params ...));

    template <uintptr_t Address, typename Ret, typename ... Params>
    typename std::enable_if<!std::is_base_of<Hooking::CallingConvention::CallingConvention, Ret>::value>::type
    /*void*/ RequestSharedHook(void(*funcPtr)(Hooks::CallType, Params ...));

    template <uintptr_t Address, typename Ret, typename ... Params>
    typename std::enable_if<!std::is_base_of<Hooking::CallingConvention::CallingConvention, Ret>::value>::type
    /*void*/ RequestExclusiveHook(Ret(*funcPtr)(Params ...));

    void ClearHook(const uintptr_t address);
    ViewPtr<Hooking::FunctionHook> FindHookByAddress(const uintptr_t address);
    ViewPtr<Hooks::HookStorage> FindHookStorageByAddress(const uintptr_t address);

private:
    std::vector<Hooks::RegistrationToken> m_registrationTokens;
};

#include "Services/Hooks/Hooks.inl"

}

}
