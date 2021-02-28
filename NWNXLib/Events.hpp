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

namespace NWNXLib::Events
{
    extern ArgumentStack s_arguments;
    extern ArgumentStack s_returns;

    template <typename T> void Push(T&& value)
    {
        s_arguments.push(Events::Argument(std::forward<T>(value)));
        LOG_DEBUG("Pushing argument '%s'", s_arguments.top());
    }

    template <typename T> std::optional<T> Pop()
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
    void InsertArgument(ArgumentStack& stack, T&& arg)
    {
        stack.push(std::forward<T>(arg));
    }
    template <typename... Args>
    void InsertArguments(ArgumentStack& stack, Args&&... args)
    {
        stack.push(std::forward<Args>(args)...);
    }
    template <typename... Args>
    ArgumentStack Arguments(Args&&... args)
    {
        return {std::forward<Args>(args)...};
    }
    template <typename T>
    T ExtractArgument(ArgumentStack& arguments)
    {
        return arguments.extract<T>();
    }
}
