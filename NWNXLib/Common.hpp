#pragma once

#include "API/ALL_CLASSES.hpp"

#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Assert.hpp"
#include "Log.hpp"

namespace NWNXLib::Services {

class Hooks;
class Tasks;
class Metrics;
class Config;
class Messaging;
class PerObjectStorage;

class HooksProxy;
class TasksProxy;
class MetricsProxy;
class ConfigProxy;
class MessagingProxy;
class PerObjectStorageProxy;

}
#include <functional>

namespace NWNXLib
{
struct ScopeGuard {
    template<class C> ScopeGuard(C&& func) : f(std::forward<C>(func)) {}
    ScopeGuard(ScopeGuard&& sg) : f(std::move(sg.f)) {
        sg.f = nullptr;
    }
    ~ScopeGuard() {
        if (f) f();
    }
    void dismiss() noexcept {
        f = nullptr;
    }
    ScopeGuard(const ScopeGuard&) = delete;
    void operator=(const ScopeGuard&) = delete;
    std::function<void()> f;
};

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a,b)
#define SCOPEGUARD(x) ::NWNXLib::ScopeGuard CAT(_scopeguard_, __LINE__) ([&]{x;})

}
