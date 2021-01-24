#pragma once

#include "ScriptVariant.hpp"
#include "Log.hpp"

#include <cstdint>
#include <functional>
#include <ostream>
#include <tuple>
#include <stack>
#include <unordered_map>
#include <vector>
#include <optional>

namespace NWNXLib {

class Events
{
public:
    // Defined in ScriptVariant.hpp
    using Argument = ScriptVariant;
    using ArgumentStack = ScriptVariantStack;

    using FunctionCallback = std::function<ArgumentStack(ArgumentStack&& in)>;
    using FunctionCallbackPtr = ArgumentStack(*)(ArgumentStack&&);

    static std::optional<FunctionCallback> GetEventCallback(const std::string& pluginName, const std::string& eventName);
    static void RegisterEvent(const std::string& pluginName, const std::string& eventName, FunctionCallback&& cb);

    static void Call(const std::string& pluginName, const std::string& eventName);

    template <typename T> static void Push(T&& value)
    {
        s_arguments.push(Events::Argument(std::forward<T>(value)));
        LOG_DEBUG("Pushing argument '%s'", s_arguments.top());
    }

    template <typename T> static std::optional<T> Pop()
    {
        if (s_returns.empty())
            LOG_ERROR("Tried to get a return value when one did not exist.");
        else if (!s_returns.top().Holds<T>())
            LOG_ERROR("Type mismatch in return values");
        else
        {
            LOG_DEBUG("Returning value '%s'", s_returns.top());
            return s_returns.extract<T>();
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
    static inline ArgumentStack s_arguments;
    static inline ArgumentStack s_returns;
};


}
