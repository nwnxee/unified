#include "Services/Hooks/HooksImpl.hpp"

template <uintptr_t Address, typename CallingConvention, typename Ret, typename ... Params>
typename std::enable_if<std::is_base_of<Hooking::CallingConvention::CallingConvention, CallingConvention>::value,
Hooks::RegistrationToken>::type Hooks::RequestSharedHook(void(*funcPtr)(CallType, Params ...))
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
        using SharedHandlerFuncPtr = decltype(CallingConvention::template LandingValue<Ret, Params ...>());

        SharedHandlerFuncPtr handler = &HooksImpl::
            template HookLandingHolderShared<CallingConvention>::
            template HookLanding<Address, Ret, Params ...>;

        const uintptr_t sharedHandlerAddress = reinterpret_cast<uintptr_t>(handler);
        const uintptr_t aslrAddress = Platform::ASLR::GetRelocatedAddress(Address);

        auto newHookStorage = std::make_unique<HookStorage>();
        newHookStorage->m_type = Type::SHARED;
        newHookStorage->m_hook = std::make_unique<Hooking::FunctionHook>(std::to_string(aslrAddress), aslrAddress, sharedHandlerAddress);
        newHookStorage->m_subscribers.push_back(funcPtrAddr);

        HooksImpl::template HookLandingHolderDataShared<Address>::s_hook = newHookStorage->m_hook.get();
        HooksImpl::template HookLandingHolderDataShared<Address>::s_subs = &newHookStorage->m_subscribers;

        m_hooks.insert(std::make_pair(Address, std::move(newHookStorage)));
    }

    return { Address, funcPtrAddr };
}

template <uintptr_t Address, typename CallingConvention, typename Ret, typename ... Params>
typename std::enable_if<std::is_base_of<Hooking::CallingConvention::CallingConvention, CallingConvention>::value,
Hooks::RegistrationToken>::type Hooks::RequestExclusiveHook(Ret(*funcPtr)(Params ...))
{
    const uintptr_t funcPtrAddr = reinterpret_cast<uintptr_t>(funcPtr);
    auto hookStorage = m_hooks.find(Address);

    if (hookStorage != m_hooks.end())
    {
        throw std::runtime_error("Another hook has already been applied in this memory location.");
    }
    else
    {
        using SharedHandlerFuncPtr = decltype(CallingConvention::template LandingValue<Ret, Params ...>());

        SharedHandlerFuncPtr handler = &HooksImpl::
            template HookLandingHolderExclusive<CallingConvention>::
            template HookLanding<Address, Ret, Params ...>;

        const uintptr_t sharedHandlerAddress = reinterpret_cast<uintptr_t>(handler);
        const uintptr_t aslrAddress = Platform::ASLR::GetRelocatedAddress(Address);

        auto newHookStorage = std::make_unique<HookStorage>();
        newHookStorage->m_type = Type::EXCLUSIVE;
        newHookStorage->m_hook = std::make_unique<Hooking::FunctionHook>(std::to_string(aslrAddress), aslrAddress, sharedHandlerAddress);
        newHookStorage->m_subscribers.emplace_back(funcPtrAddr);

        HooksImpl::template HookLandingHolderDataExclusive<Address>::s_addr = funcPtrAddr;

        m_hooks.insert(std::make_pair(Address, std::move(newHookStorage)));
    }

    return { Address, funcPtrAddr };
}

template <uintptr_t Address, typename Ret, typename ... Params>
typename std::enable_if<!std::is_base_of<Hooking::CallingConvention::CallingConvention, Ret>::value,
Hooks::RegistrationToken>::type Hooks::RequestSharedHook(void(*funcPtr)(Hooks::CallType, Params ...))
{
    return RequestSharedHook<Address, Hooking::CallingConvention::ThisCall, Ret>(funcPtr);
}

template <uintptr_t Address, typename Ret, typename ... Params>
typename std::enable_if<!std::is_base_of<Hooking::CallingConvention::CallingConvention, Ret>::value,
Hooks::RegistrationToken>::type Hooks::RequestExclusiveHook(Ret(*funcPtr)(Params ...))
{
    return RequestExclusiveHook<Address, Hooking::CallingConvention::ThisCall, Ret>(funcPtr);
}

template <uintptr_t Address, typename CallingConvention, typename Ret, typename ... Params>
typename std::enable_if<std::is_base_of<Hooking::CallingConvention::CallingConvention, CallingConvention>::value>::type
/*void*/ HooksProxy::RequestSharedHook(void(*funcPtr)(Hooks::CallType, Params ...))
{
    m_registrationTokens.push_back(m_proxyBase.RequestSharedHook<Address, CallingConvention, Ret>(funcPtr));
}

template <uintptr_t Address, typename CallingConvention, typename Ret, typename ... Params>
typename std::enable_if<std::is_base_of<Hooking::CallingConvention::CallingConvention, CallingConvention>::value>::type
/*void*/ HooksProxy::RequestExclusiveHook(Ret(*funcPtr)(Params ...))
{
    m_registrationTokens.push_back(m_proxyBase.RequestExclusiveHook<Address, CallingConvention, Ret>(funcPtr));
}

template <uintptr_t Address, typename Ret, typename ... Params>
typename std::enable_if<!std::is_base_of<Hooking::CallingConvention::CallingConvention, Ret>::value>::type
/*void*/ HooksProxy::RequestSharedHook(void(*funcPtr)(Hooks::CallType, Params ...))
{
    RequestSharedHook<Address, Hooking::CallingConvention::ThisCall, Ret>(funcPtr);
}

template <uintptr_t Address, typename Ret, typename ... Params>
typename std::enable_if<!std::is_base_of<Hooking::CallingConvention::CallingConvention, Ret>::value>::type
/*void*/ HooksProxy::RequestExclusiveHook(Ret(*funcPtr)(Params ...))
{
    RequestExclusiveHook<Address, Hooking::CallingConvention::ThisCall, Ret>(funcPtr);
}
