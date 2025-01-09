#pragma once

#include "API/API/CGameEffect.hpp"
#include "API/API/JsonEngineStructure.hpp"
#include "API/API/CScriptLocation.hpp"

#include <deque>
#include <stdexcept>
#include <variant>

namespace NWNXLib
{

struct NullArgument {};

namespace detail
{

template <typename T>
constexpr bool is_argument_type()
{
    return (std::is_same_v<T, int32_t>
         || std::is_same_v<T, float>
         || std::is_same_v<T, ObjectID>
         || std::is_same_v<T, std::string>
         || std::is_same_v<T, Vector>
         || std::is_same_v<T, CScriptLocation>
         || std::is_same_v<T, CGameEffect*>
         || std::is_same_v<T, JsonEngineStructure>
         || std::is_same_v<T, NullArgument>);
}

} // namespace detail

struct ScriptVariant
{
    using Variant = std::variant<
        NullArgument,
        int32_t,
        float,
        ObjectID,
        std::string,
        Vector,
        CScriptLocation,
        CGameEffect*,
        JsonEngineStructure>;
    Variant m_data;

    // Constructors
    ScriptVariant() : m_data(NullArgument()) {}

    template <typename T>
    ScriptVariant(T v) : m_data{std::move(v)} {}

    ScriptVariant(ScriptVariant&&) = default;
    ScriptVariant(const ScriptVariant&) = default;
    ScriptVariant& operator=(const ScriptVariant&) = default;
    ScriptVariant& operator=(ScriptVariant&&) = default;

    template <typename T>
    bool Holds() const
    {
        static_assert(detail::is_argument_type<T>(), "Invalid argument type.");
        return std::holds_alternative<T>(m_data);
    }

    operator bool() const { return !Holds<NullArgument>(); }

    template <typename T>
    T& Get() { return const_cast<T&>(const_cast<const ScriptVariant*>(this)->Get<T>()); }

    template <typename T>
    const T& Get() const
    {
        static_assert(detail::is_argument_type<T>(), "Invalid argument type.");
        return std::get<T>(m_data);
    }

    std::string toString() const
    {
        if (Holds<int32_t>()) {             return std::to_string(Get<int32_t>()); }
        else if (Holds<float>()) {          return std::to_string(Get<float>()); }
        else if (Holds<ObjectID>()) {       return Utils::ObjectIDToString(Get<ObjectID>()); }
        else if (Holds<std::string>()) {    return Get<std::string>(); }
        else if (Holds<Vector>()) {         return Get<Vector>().ToString(); }
        else if (Holds<CScriptLocation>()) {return Get<CScriptLocation>().ToString(); }
        else if (Holds<NullArgument>()) {   return "(null)"; }
        else if (Holds<CGameEffect*>())
        {
            auto e = Get<CGameEffect*>();
            return e ? std::string("EffectID:") + std::to_string(e->m_nID) : std::string("nullptr effect");
        }
        else if (Holds<JsonEngineStructure>()) { return std::string("JSON: ") + Get<JsonEngineStructure>().m_shared->m_json.dump(); }
        return "(unknown argument type)";
    }

};

struct ScriptVariantStack
{
    using Stack = std::deque<ScriptVariant>;
    Stack m_stack;

    ScriptVariantStack() = default;

    template <typename... Ts>
    ScriptVariantStack(Ts&&... args)
    {
        push(std::forward<Ts>(args)...);
    }

    ScriptVariantStack(const ScriptVariantStack&) = default;
    ScriptVariantStack(ScriptVariantStack&&) = default;
    ScriptVariantStack& operator=(const ScriptVariantStack&) = default;
    ScriptVariantStack& operator=(ScriptVariantStack&&) = default;

    bool empty() const { return m_stack.empty(); }

    template <typename T>
    T extract()
    {
        if (empty())
            throw std::runtime_error("Tried to extract an argument from an empty argument stack.");
        if (!top().Holds<T>())
            throw std::runtime_error("Failed to match pushed argument to the provided type.");

        T real = std::move(top().Get<T>());
        pop();
        return real;
    }

    template <typename... Ts>
    std::tuple<Ts...> extract_n() { return {extract<Ts>()...}; }

    template <typename... Ts>
    void push(Ts&&... arg)
    {
        static_assert(sizeof...(Ts) > 0, "You must insert at least one argument.");
        (..., m_stack.emplace_back(std::forward<Ts>(arg)));
    }

    void pop() { m_stack.pop_back(); }

    Stack::size_type size() const { return m_stack.size(); };

    ScriptVariant& top() { return m_stack.back(); }
};

} // namespace NWNXLib

inline std::ostream& operator<<(std::ostream& os, const NWNXLib::ScriptVariant& arg)
{
    os << arg.toString();
    return os;
}
