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
public: // Structures
    // Defined in ScriptVariant.hpp
    using Argument = ScriptVariant;
    using ArgumentStack = ScriptVariantStack;

    using FunctionCallback = std::function<ArgumentStack(ArgumentStack&& in)>;

    struct EventData
    {
        std::string m_pluginName;
        std::string m_eventName;
    };

    struct RegistrationToken
    {
        EventData m_data;
    };

public:
    template <typename T>
    void Push(const std::string& pluginName, const std::string& eventName, T&& value);

    template <typename T>
    std::optional<T> Pop(const std::string& pluginName, const std::string& eventName);

    void Call(const std::string& pluginName, const std::string& eventName);

    RegistrationToken RegisterEvent(const std::string& pluginName, const std::string& eventName, FunctionCallback&& cb);
    void ClearEvent(RegistrationToken&& token);

    template <typename T>
    static void InsertArgument(ArgumentStack& stack, T&& arg);

    template <typename... Args>
    static void InsertArguments(ArgumentStack& stack, Args&&... args);

    template <typename... Args>
    static ArgumentStack Arguments(Args&&... args);

    template <typename T>
    static T ExtractArgument(ArgumentStack& arguments);

private: // Structures
    struct EventDataInternal
    {
        EventData m_data;
        FunctionCallback m_callback;
        ArgumentStack m_arguments;
        ArgumentStack m_returns;
    };

    EventDataInternal* GetEventData(const std::string& pluginName, const std::string& eventName);

    using EventList = std::vector<std::unique_ptr<EventDataInternal>>;
    using EventMap = std::unordered_map<std::string, EventList>;
    EventMap m_eventMap;
};

class EventsProxy : public ServiceProxy<Events>
{
public:
    EventsProxy(Events& events, std::string pluginName);
    ~EventsProxy();

    void RegisterEvent(const std::string& eventName, Events::FunctionCallback&& cb);
    void ClearEvent(const std::string& eventName);

private:
    std::string m_pluginName;
    std::vector<Events::RegistrationToken> m_registrationTokens;
};



template <typename T>
void Events::Push(const std::string& pluginName, const std::string& eventName, T&& value)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        event->m_arguments.push(Events::Argument(std::forward<T>(value)));
        LOG_DEBUG("Pushing argument '%s'. Event '%s', Plugin: '%s'.",
            event->m_arguments.top(), eventName, pluginName);
    }
    else
    {
        LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName, eventName);
    }
}

template <typename T>
std::optional<T> Events::Pop(const std::string& pluginName, const std::string& eventName)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        if (event->m_returns.empty())
        {
            LOG_ERROR("Plugin '%s', event '%s': Tried to get a return value when one did not exist.",
                pluginName, eventName);
            return std::optional<T>();
        }

        if (!event->m_returns.top().Holds<T>())
        {
            LOG_ERROR("Plugin '%s', event '%s': Type mismatch in return values",
                pluginName, eventName);
        }
        else
        {
            LOG_DEBUG("Returning value '%s'. Event '%s', Plugin: '%s'.",
                event->m_returns.top(), eventName, pluginName);

            // I'm probably using all these moves wrong..
            return event->m_returns.extract<T>();
        }
    }
    else
    {
        LOG_ERROR("Plugin '%s' does not have an event '%s' registered", pluginName, eventName);
    }
    return std::optional<T>();
}

template <typename T>
void Events::InsertArgument(ArgumentStack& stack, T&& arg)
{
    stack.push(std::forward<T>(arg));
}

template <typename... Args>
void Events::InsertArguments(ArgumentStack& stack, Args&&... args)
{
    stack.push(std::forward<Args>(args)...);
}

template <typename... Args>
Events::ArgumentStack Events::Arguments(Args&&... args)
{
    return {std::forward<Args>(args)...};
}

template <typename T>
T Events::ExtractArgument(ArgumentStack& arguments)
{
    return arguments.extract<T>();
}

}
