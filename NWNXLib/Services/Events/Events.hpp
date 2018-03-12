#pragma once

#include "API/Types.hpp"
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
    using Argument = std::string;
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

    void OnSetLocalString(std::string&& index, std::string&& value);
    Maybe<std::string> OnGetLocalString(std::string&& index);
    Maybe<API::Types::ObjectID> OnGetLocalObject(std::string&& index);

    RegistrationToken RegisterEvent(const std::string& pluginName, const std::string& eventName, FunctionCallback&& cb);
    void ClearEvent(RegistrationToken&& token);

    template <typename T>
    static void InsertArgument(ArgumentStack& stack, T arg);

    template <typename T>
    static T ExtractArgument(ArgumentStack& arguments);

    template <typename ... Params>
    static std::tuple<Params ...> ExtractArguments(ArgumentStack&& arguments);

private: // Structures
    struct EventDataInternal
    {
        EventData m_data;
        FunctionCallback m_callback;
        ArgumentStack m_arguments;
        ArgumentStack m_returns;
    };

    using EventList = std::vector<std::unique_ptr<EventDataInternal>>;
    using EventMap = std::unordered_map<std::string, EventList>;

    enum class CastableTypes : uint8_t
    {
        INT = 0,
        FLOAT,
        OBJECT,
        STRING,
        ENUM_COUNT
    };

    enum class BuiltInFunction
    {
        CALL_FUNCTION,
        PUSH_ARGUMENT,
        GET_RETURN_VALUE,
        INVALID
    };

    struct ParsedCommand
    {
        BuiltInFunction m_function;
        std::string m_specifiers; // These are function specifiers, eg GET_RETURN_VALUE!1 , which specifies the type.
        ViewPtr<EventDataInternal> m_eventData;
    };

private:
    ParsedCommand FindEventDataFromIndex(const std::string& index);

    static BuiltInFunction FromString(const std::string& str);
    static std::string ToString(const BuiltInFunction func);

    static CastableTypes ExtractType(const std::string& data);

    static constexpr uint8_t TYPE_SIZE_IN_CHARACTERS = 2;
    static_assert(TYPE_SIZE_IN_CHARACTERS >= 1, "The type size was invalid!");

    template <typename T>
    static Maybe<T> StringToTypeCast(std::string&& data);

    template <typename T>
    static std::string TypeToStringCast(T&& data);

    template <typename T>
    static Maybe<std::tuple<T>> MakeTupleFromArgs(Events::ArgumentStack& arguments);

    template <typename T1, typename T2, typename ... Ts>
    static Maybe<std::tuple<T1, T2, Ts ...>> MakeTupleFromArgs(Events::ArgumentStack& arguments);

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
