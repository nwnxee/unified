#pragma once

#include "API/Types.hpp"
#include "API/CGameEffect.hpp"
#include "Services/Services.hpp"

#include <cstdint>
#include <functional>
#include <ostream>
#include <tuple>
#include <stack>
#include <unordered_map>
#include <variant>
#include <vector>
#include <optional>

namespace NWNXLib::Services {

namespace detail
{
template <typename T, typename... Us>
constexpr bool is_argument_type()
{
    return (std::is_same_v<T, int32_t>
        || std::is_same_v<T, bool>
        || std::is_same_v<T, float>
        || std::is_same_v<T, API::Types::ObjectID>
        || std::is_same_v<T, std::string>
        || std::is_same_v<T, CGameEffect*>);
}
}

class Events
{
public: // Structures
    struct Argument
    {
        struct NullArgument {};
        using Variant = std::variant<NullArgument, int32_t, float, API::Types::ObjectID, std::string, CGameEffect*>;
        Variant m_data;

        // Constructors
        Argument() : m_data(NullArgument()) {}
        template <typename T>
        Argument(T v) : m_data(std::move(v)) { }

        template <typename T> bool Holds() const { return std::holds_alternative<T>(m_data); }
        operator bool() const { return !Holds<NullArgument>(); }

        template <typename T>
        T& Get() { return const_cast<T&>(const_cast<const Argument*>(this)->Get<T>()); };
        
        template <typename T> const T& Get() const
        {
            static_assert(detail::is_argument_type<T>(), "Invalid argument type.");
            return std::get<T>(m_data); 
        };

        std::string toString() const;
    };

    struct ArgumentStack 
    {
        using Stack = std::stack<Argument>;
        Stack m_stack;

        ArgumentStack() = default;

        template <typename... Ts>
        ArgumentStack(Ts&&... args) 
        { 
            push(std::forward<Ts>(args)...); 
        }

        bool empty() const { return m_stack.empty(); }

        template <typename T>
        T extract()
        {
            if (m_stack.empty()) throw std::runtime_error("Tried to extract an argument from an empty argument stack.");
            if (!m_stack.top().Holds<T>()) throw std::runtime_error("Failed to match pushed argument to the provided type.");
            
            T real = std::move(m_stack.top().Get<T>());
            pop();
            return real;
        }

        template <typename... Ts>
        std::tuple<Ts...> extract_n() { return {extract<Ts>()...}; }

        template <typename... Ts>
        void push(Ts&&... arg) 
        {
            static_assert(sizeof...(Ts) > 0, "You must insert at least one argument.");
            (m_stack.emplace(std::forward<Ts>(arg)), ...); 
        }

        void pop() { m_stack.pop(); }

        Stack::size_type size() const { return m_stack.size(); }
        Argument& top() { return m_stack.top(); }
};

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

#include "Services/Events/Events.inl"

template <typename T>
void Events::Push(const std::string& pluginName, const std::string& eventName, T&& value)
{
    if (auto* event = GetEventData(pluginName, eventName))
    {
        event->m_arguments.push(std::forward<T>(value));
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
            return std::make_optional<T>(event->m_returns.extract<T>());
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
    return { std::forward<Args>(args)... };
}

template <typename T>
T Events::ExtractArgument(ArgumentStack& arguments)
{
    return arguments.extract<T>();
}

}

std::ostream& operator<<(std::ostream& os, const NWNXLib::Services::Events::Argument& arg);
