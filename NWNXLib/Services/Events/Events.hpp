#pragma once

#include "API/Types.hpp"
#include "API/CGameEffect.hpp"
#include "Maybe.hpp"
#include "Services/Services.hpp"

#include <cstdint>
#include <functional>
#include <tuple>
#include <stack>
#include <unordered_map>
#include <vector>

namespace NWNXLib {

namespace Services {

class Events : public ServiceBase
{
public: // Structures
    struct Argument
    {
        Maybe<int32_t>              Int;
        Maybe<float>                Float;
        Maybe<API::Types::ObjectID> Object;
        Maybe<std::string>          String;
        Maybe<API::CGameEffect*>    Effect;

        // Constructors
        Argument(const int32_t& v)                : Int(v)    { }
        Argument(const float& v)                  : Float(v)  { }
        Argument(const API::Types::ObjectID& v)   : Object(v) { }
        Argument(const std::string& v)            : String(std::move(v)) { }
        Argument(API::CGameEffect* v)             : Effect(v) { }

        template <typename T> Maybe<T>& Get();
        std::string toString();
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
    Events();
    ~Events();

    template <typename T>
    void Push(const std::string& pluginName, const std::string& eventName, const T& value);

    template <typename T>
    Maybe<T> Pop(const std::string& pluginName, const std::string& eventName);

    void Call(const std::string& pluginName, const std::string& eventName);

    RegistrationToken RegisterEvent(const std::string& pluginName, const std::string& eventName, FunctionCallback&& cb);
    void ClearEvent(RegistrationToken&& token);

    template <typename T>
    static void InsertArgument(ArgumentStack& stack, T arg);

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
