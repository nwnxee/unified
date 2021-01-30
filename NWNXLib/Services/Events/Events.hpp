#pragma once

#include "API/CGameEffect.hpp"
#include "ScriptVariant.hpp"
#include "Services/Services.hpp"

#include <cstdint>
#include <functional>
#include <ostream>
#include <tuple>
#include <stack>
#include <unordered_map>
#include <vector>
#include <optional>

namespace NWNXLib::Services {

class Events
{
public:
    // Defined in ScriptVariant.hpp
    using Argument = ScriptVariant;
    using ArgumentStack = ScriptVariantStack;

    using FunctionCallback = std::function<ArgumentStack(ArgumentStack&& in)>;
    using FunctionCallbackPtr = ArgumentStack(*)(ArgumentStack&&);

    std::optional<FunctionCallback> GetEventCallback(const std::string& pluginName, const std::string& eventName);
    void RegisterEvent(const std::string& pluginName, const std::string& eventName, FunctionCallback&& cb);

    void Call(const std::string& pluginName, const std::string& eventName);

    template <typename T> void Push(T&& value)
    {
        m_arguments.push(Events::Argument(std::forward<T>(value)));
        LOG_DEBUG("Pushing argument '%s'", m_arguments.top());
    }

    template <typename T> std::optional<T> Pop()
    {
        if (m_returns.empty())
            LOG_ERROR("Tried to get a return value when one did not exist.");
        else if (!m_returns.top().Holds<T>())
            LOG_ERROR("Type mismatch in return values");
        else
        {
            LOG_DEBUG("Returning value '%s'", m_returns.top());
            return m_returns.extract<T>();
        }
        return std::optional<T>();
    }

    template <typename T>
    static void InsertArgument(ArgumentStack& stack, T&& arg)
    {
        stack.push(std::forward<T>(arg));
    }
    template <typename... Args>
    static void InsertArguments(ArgumentStack& stack, Args&&... args)
    {
        stack.push(std::forward<Args>(args)...);
    }
    template <typename... Args>
    static ArgumentStack Arguments(Args&&... args)
    {
        return {std::forward<Args>(args)...};
    }
    template <typename T>
    static T ExtractArgument(ArgumentStack& arguments)
    {
        return arguments.extract<T>();
    }
private:
    ArgumentStack m_arguments;
    ArgumentStack m_returns;

    using PluginEventMap = std::unordered_map<std::string, FunctionCallback>;
    std::unordered_map<std::string, PluginEventMap> m_eventMap;
};

class EventsProxy : public ServiceProxy<Events>
{
public:
    EventsProxy(Events& events, std::string pluginName) :
        ServiceProxy<Events>(events), m_pluginName(pluginName) {}
    ~EventsProxy() {}

    void RegisterEvent(const std::string& eventName, Events::FunctionCallback&& cb)
    {
        m_proxyBase.RegisterEvent(m_pluginName, eventName, std::move(cb));
    }

private:
    std::string m_pluginName;
};

}
