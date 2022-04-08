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

#include "Services/Metrics/Metrics.hpp"

namespace NWNXLib::Services {

// Contains the raw services. Owned by the Core.
struct ServiceList
{
    std::unique_ptr<Metrics> m_metrics;
};

// Contains proxies through which the services should be accessed.
struct ProxyServiceList
{
    std::unique_ptr<MetricsProxy> m_metrics;
};

}
