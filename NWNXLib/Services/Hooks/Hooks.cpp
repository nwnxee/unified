#include "Services/Hooks/Hooks.hpp"

namespace NWNXLib {

namespace Services {

Hooks* HooksImpl::g_hooks;

Hooks::Hooks()
{
    HooksImpl::g_hooks = this;
}

Hooks::~Hooks()
{
}

void Hooks::ClearHook(Hooks::RegistrationToken&& token)
{
    ViewPtr<HookStorage> storage = FindHookStorageByAddress(token.m_oldAddress);

    if (storage == nullptr)
    {
        throw std::runtime_error("Invalid or duplicate hook registration token.");
    }
    else
    {
        switch (storage->m_type)
        {
            case Type::EXCLUSIVE:
            {
                // Exclusive just needs to be erased.
                m_hooks.erase(token.m_oldAddress);
                break;
            }

            case Type::SHARED:
            {
                // Shared needs the callback removed, and erased if all callbacks are gone.
                std::vector<uintptr_t>& subscribers = storage->m_subscribers;
                ASSERT(subscribers.size() > 0);

                auto addrInSubscribers = std::find(subscribers.begin(), subscribers.end(), token.m_newAddress);

                if (addrInSubscribers == subscribers.end())
                {
                    throw std::runtime_error("Invalid or duplicate hook registration token.");
                }

                subscribers.erase(addrInSubscribers);

                if (subscribers.size() == 0)
                {
                    // All subscribers are gone -- just clear the hook.
                    m_hooks.erase(token.m_oldAddress);
                }

                break;
            }
        }
    }
}

ViewPtr<Hooking::FunctionHook> Hooks::FindHookByAddress(const uintptr_t address)
{
    auto ptr = FindHookStorageByAddress(address);
    return ptr ? ptr->m_hook.get() : nullptr;
}

ViewPtr<Hooks::HookStorage> Hooks::FindHookStorageByAddress(const uintptr_t address)
{
    auto hookStorage = m_hooks.find(address);
    return hookStorage != m_hooks.end() ? hookStorage->second.get() : nullptr;
}

HooksProxy::HooksProxy(Hooks& hooks)
    : ServiceProxy<Hooks>(hooks)
{
}

HooksProxy::~HooksProxy()
{
    for (Hooks::RegistrationToken& token : m_registrationTokens)
    {
        m_proxyBase.ClearHook(std::move(token));
    }
}

void HooksProxy::ClearHook(const uintptr_t address)
{
    auto token = std::find_if(std::begin(m_registrationTokens), std::end(m_registrationTokens),
        [address](const Hooks::RegistrationToken& check)
        {
            return check.m_oldAddress == address;
        }
    );

    if (token == std::end(m_registrationTokens))
    {
        throw std::runtime_error("Tried to clear hook at an unregistered address.");
    }

    Hooks::RegistrationToken concreteToken = std::move(*token);
    m_registrationTokens.erase(token);
    m_proxyBase.ClearHook(std::move(concreteToken));
}

ViewPtr<Hooking::FunctionHook> HooksProxy::FindHookByAddress(const uintptr_t address)
{
    return m_proxyBase.FindHookByAddress(address);
}

ViewPtr<Hooks::HookStorage> HooksProxy::FindHookStorageByAddress(const uintptr_t address)
{
    return m_proxyBase.FindHookStorageByAddress(address);
}

}

}
