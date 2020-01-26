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
#include <vector>
#include <optional>

namespace NWNXLib {

namespace Services {

class Events
{
public: // Structures
    struct Argument
    {
        std::optional<int32_t>              m_int;
        std::optional<float>                m_float;
        std::optional<API::Types::ObjectID> m_object;
        std::optional<std::string>          m_string;
        std::optional<CGameEffect*>         m_effect;

        // Constructors
        Argument(int32_t v)                : m_int(v)    { }
        Argument(float v)                  : m_float(v)  { }
        Argument(API::Types::ObjectID v)   : m_object(v) { }
        Argument(std::string v)            : m_string(std::move(v)) { }
        Argument(CGameEffect* v)           : m_effect(v) { }

        template <typename T> std::optional<T>& Get();
        std::string toString() const;
    };

    using ArgumentStack = std::stack<Argument>;
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

}

}

std::ostream& operator<<(std::ostream& os, const NWNXLib::Services::Events::Argument& arg);
