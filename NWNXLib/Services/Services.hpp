#pragma once

#include "Common.hpp"

#include <memory>
#include <string>

namespace NWNXLib::Services {

template <typename T>
struct ServiceProxy
{
public:
    ServiceProxy(T& proxyBase) : m_proxyBase(proxyBase) { }
    T* GetProxyBase() { return &m_proxyBase; }

protected:
    T& m_proxyBase;
};

struct ServiceList;
struct ProxyServiceList;

}
// TODO: This all needs to go away..

#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Services/Commands/Commands.hpp"

namespace NWNXLib::Services {

// Contains the raw services. Owned by the Core.
struct ServiceList
{
    std::unique_ptr<Events> m_events;
    std::unique_ptr<Hooks> m_hooks;
    std::unique_ptr<Tasks> m_tasks;
    std::unique_ptr<Metrics> m_metrics;
    std::unique_ptr<Config> m_config;
    std::unique_ptr<Messaging> m_messaging;
    std::unique_ptr<PerObjectStorage> m_perObjectStorage;
    std::unique_ptr<Commands> m_commands;
};

// Contains proxies through which the services should be accessed.
struct ProxyServiceList
{
    std::unique_ptr<EventsProxy> m_events;
    std::unique_ptr<HooksProxy> m_hooks;
    std::unique_ptr<TasksProxy> m_tasks;
    std::unique_ptr<MetricsProxy> m_metrics;
    std::unique_ptr<ConfigProxy> m_config;
    std::unique_ptr<MessagingProxy> m_messaging;
    std::unique_ptr<PerObjectStorageProxy> m_perObjectStorage;
    std::unique_ptr<CommandsProxy> m_commands;
};

}
