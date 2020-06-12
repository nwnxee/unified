#pragma once

#include "FunctionHook.hpp"
#include "Platform/ASLR.hpp"
#include "Services/Services.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

namespace NWNXLib {

namespace Services {

enum class HookType
{
    SHARED,
    EXCLUSIVE,
    CHAINED
};

struct HookBase
{
    HookBase(HookType type, uintptr_t oldAddress, uintptr_t newAddress);
    virtual ~HookBase();

    bool AddSubscriber(uintptr_t subscriber);
    void ResetChain();

    template <typename R, typename... Args>
    R CallNext(Args... args)
    {
        ASSERT(m_type == HookType::CHAINED);

        if (m_iterator == std::end(m_subscribers))
        {
            m_iterator = std::begin(m_subscribers);
            return CallOriginal<R>(args...);
        }
        else
        {
            auto f = reinterpret_cast<R(*)(Args...)>(*m_iterator);
            ++m_iterator;
            return f(args...);
        }
    }

    template <typename Ret, typename ... Params>
    Ret CallOriginal(Params ... args)
    {
        using FuncPtrType = Ret(*)(Params ...);
        FuncPtrType funcPtr = reinterpret_cast<FuncPtrType>(m_hook.m_trampoline);
        return static_cast<Ret>(funcPtr(args ...));
    }

    const HookType m_type;

    const uintptr_t m_aslrAddress;
    const uintptr_t m_oldAddress;
    const uintptr_t m_newAddress;

    void *m_sharedResult;

    using Subscribers = std::vector<uintptr_t>;
    Subscribers m_subscribers;
    Subscribers::iterator m_iterator;

    Hooking::FunctionHook m_hook;
};

// Shared Hooks

template <uintptr_t, class>
struct SharedHook;

template <uintptr_t Address, typename R, typename... Args>
struct SharedHook<Address, R(Args...)> : public HookBase
{
    static HookBase* s_hookBase;
    using SubscriberType = void(*)(bool, Args...);
    static HookBase::Subscribers* s_subscribers;

    SharedHook() : HookBase(HookType::SHARED, Address, reinterpret_cast<uintptr_t>(Call))
    {
        s_hookBase = this;
        s_subscribers = &m_subscribers;
    }

private:
    static R Call(Args... args)
    {
        if constexpr (std::is_same_v<R, void>)
        {
            for (auto& f : *s_subscribers)
                reinterpret_cast<SubscriberType>(f)(true, args...);

            s_hookBase->CallOriginal<void>(args...);

            for (auto& f : *s_subscribers)
                reinterpret_cast<SubscriberType>(f)(false, args...);
        }
        else
        {
            for (auto& f : *s_subscribers)
                reinterpret_cast<SubscriberType>(f)(true, args...);

            R result = s_hookBase->CallOriginal<R>(args...);
            if constexpr (std::is_pointer_v<R>)
            {
                s_hookBase->m_sharedResult = result;
            }
            else
            {
                s_hookBase->m_sharedResult = &result;
            }

            for (auto& f : *s_subscribers)
                reinterpret_cast<SubscriberType>(f)(false, args...);

            s_hookBase->m_sharedResult = nullptr;
            return result;
        }
    }
};

template <uintptr_t Address, typename R, typename... Args>
HookBase* SharedHook<Address, R(Args...)>::s_hookBase = nullptr;
template <uintptr_t Address, typename R, typename... Args>
HookBase::Subscribers* SharedHook<Address, R(Args...)>::s_subscribers = nullptr;

// Exclusive Hooks

template <uintptr_t, class>
struct ExclusiveHook;

template <uintptr_t Address, typename R, typename... Args>
struct ExclusiveHook<Address, R(Args...)> : public HookBase
{
    ExclusiveHook(R(*funcPtr)(Args...))
        : HookBase(HookType::EXCLUSIVE, Address, reinterpret_cast<uintptr_t>(funcPtr))
    {}
};

// Chained Hooks

template <uintptr_t, class>
struct ChainedHook;

template <uintptr_t Address, typename R, typename... Args>
struct ChainedHook<Address, R(Args...)> : public HookBase
{
    using function_type = R (*)(Args...);
    static HookBase* s_hookBase;
    static function_type s_function;

    ChainedHook(R(*funcPtr)(Args...))
        : HookBase(HookType::CHAINED, Address, reinterpret_cast<uintptr_t>(Call))
    {
        s_hookBase = this;
        s_function = funcPtr;
    }
private:
    static R Call(Args... args)
    {
        s_hookBase->ResetChain();
        return s_function(args...);
    }
};

template <uintptr_t Address, typename R, typename... Args>
HookBase* ChainedHook<Address, R(Args...)>::s_hookBase = nullptr;
template <uintptr_t Address, typename R, typename... Args>
typename ChainedHook<Address, R(Args...)>::function_type ChainedHook<Address, R(Args...)>::s_function = nullptr;

class Hooks
{
public: // Structures
    struct RegistrationToken
    {
        uintptr_t m_oldAddress;
        uintptr_t m_newAddress;
    };

private: // Structures
    using GenericHookMap = std::unordered_map<uintptr_t, std::unique_ptr<HookBase>>;

public:
    Hooks();
    ~Hooks();

    template <uintptr_t Address, typename Ret, typename ... Params>
    RegistrationToken RequestSharedHook(void(*funcPtr)(bool, Params ...));

    template <uintptr_t Address, typename Ret, typename ... Params>
    RegistrationToken RequestExclusiveHook(Ret(*funcPtr)(Params ...));

    template <uintptr_t Address, typename Ret, typename ... Params>
    RegistrationToken RequestChainedHook(Ret(*funcPtr)(Params ...));

    void ClearHook(RegistrationToken&& token);

    Hooking::FunctionHook* FindHookByAddress(const uintptr_t address);
    HookBase* FindHookStorageByAddress(const uintptr_t address);

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
    HookBase* RequestExclusiveHook(Ret(*funcPtr)(Params ...));

    template <uintptr_t Address, typename Ret, typename ... Params>
    HookBase* RequestChainedHook(Ret(*funcPtr)(Params ...));

    void ClearHook(const uintptr_t address);
    Hooking::FunctionHook* FindHookByAddress(const uintptr_t address);
    HookBase* FindHookStorageByAddress(const uintptr_t address);

private:
    std::vector<Hooks::RegistrationToken> m_registrationTokens;
};

template <uintptr_t Address, typename Ret, typename ... Params>
Hooks::RegistrationToken Hooks::RequestSharedHook(void(*funcPtr)(bool, Params ...))
{
    const uintptr_t funcPtrAddr = reinterpret_cast<uintptr_t>(funcPtr);
    auto hookStorage = m_hooks.find(Address);

    if (hookStorage != m_hooks.end())
    {
        if (hookStorage->second->m_type != HookType::SHARED)
        {
            throw std::runtime_error("An exclusive hook has already been applied in this memory location.");
        }

        if (!hookStorage->second->AddSubscriber(funcPtrAddr))
        {
            throw std::runtime_error("This handler has already been registered with this shared hook.");
        }
    }
    else
    {
        auto newHookStorage = std::make_unique<SharedHook<Address, Ret(Params...)>>();
        newHookStorage->AddSubscriber(funcPtrAddr);
        m_hooks.insert(std::make_pair(Address, std::move(newHookStorage)));
    }

    auto& subscribers = *SharedHook<Address, Ret(Params...)>::s_subscribers;
    LOG_DEBUG("Subsciber Address: 0x%x count: %d", Address, subscribers.size());

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
        auto newHookStorage = std::make_unique<ExclusiveHook<Address, Ret(Params...)>>(funcPtr);
        m_hooks.insert(std::make_pair(Address, std::move(newHookStorage)));
    }

    return { Address, funcPtrAddr };
}

template <uintptr_t Address, typename Ret, typename ... Params>
Hooks::RegistrationToken Hooks::RequestChainedHook(Ret(*funcPtr)(Params ...))
{
    const uintptr_t funcPtrAddr = reinterpret_cast<uintptr_t>(funcPtr);
    auto hookStorage = m_hooks.find(Address);

    if (hookStorage != m_hooks.end())
    {
        if (hookStorage->second->m_type != HookType::CHAINED)
        {
            throw std::runtime_error("Mismatched hook type.");
        }

        if (!hookStorage->second->AddSubscriber(funcPtrAddr))
        {
            throw std::runtime_error("This handler has already been registered with this chained hook.");
        }
    }
    else
    {
        auto newHookStorage = std::make_unique<ChainedHook<Address, Ret(Params...)>>(funcPtr);
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
HookBase* HooksProxy::RequestExclusiveHook(Ret(*funcPtr)(Params ...))
{
    m_registrationTokens.push_back(m_proxyBase.RequestExclusiveHook<Address, Ret>(funcPtr));
    return FindHookStorageByAddress(Address);
}

template <uintptr_t Address, typename Ret, typename ... Params>
HookBase* HooksProxy::RequestChainedHook(Ret(*funcPtr)(Params ...))
{
    m_registrationTokens.push_back(m_proxyBase.RequestChainedHook<Address, Ret>(funcPtr));
    return FindHookStorageByAddress(Address);
}

}

}
