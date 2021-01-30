#pragma once

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

#include "Services/Tasks/Tasks.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"

namespace NWNXLib::Services {

// Contains the raw services. Owned by the Core.
struct ServiceList
{
    std::unique_ptr<Tasks> m_tasks;
    std::unique_ptr<Metrics> m_metrics;
    std::unique_ptr<PerObjectStorage> m_perObjectStorage;
};

// Contains proxies through which the services should be accessed.
struct ProxyServiceList
{
    std::unique_ptr<TasksProxy> m_tasks;
    std::unique_ptr<MetricsProxy> m_metrics;
    std::unique_ptr<PerObjectStorageProxy> m_perObjectStorage;
};

}
