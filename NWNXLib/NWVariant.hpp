#pragma once

#include "API/Types.hpp"
#include "API/API/CGameEffect.hpp"

#include <stack>
#include <variant>

namespace NWNXLib
{

struct NullArgument {};
using UserDefined = void*;

namespace detail
{

template <typename T>
constexpr bool is_argument_type()
{
    return (std::is_same_v<T, int32_t>
        || std::is_same_v<T, float>
        || std::is_same_v<T, API::Types::ObjectID>
        || std::is_same_v<T, std::string>
        || std::is_same_v<T, CGameEffect*>
        || std::is_same_v<T, NullArgument>
        || std::is_same_v<T, UserDefined>);
}

} // namespace detail

struct NWVariant
{
    using Variant = std::variant<NullArgument, int32_t, float, API::Types::ObjectID, std::string, CGameEffect*, UserDefined>;
    Variant m_data;

    // Constructors
    NWVariant() : m_data(NullArgument()) {}

    template <typename T>
    NWVariant(T v) : m_data{std::move(v)} {}

    NWVariant(NWVariant&&) = default;
    NWVariant(const NWVariant&) = default;
    NWVariant& operator=(const NWVariant&) = default;
    NWVariant& operator=(NWVariant&&) = default;

    template <typename T>
    bool Holds() const
    {
        static_assert(detail::is_argument_type<T>(), "Invalid argument type.");
        return std::holds_alternative<T>(m_data);
    }

    operator bool() const { return !Holds<NullArgument>(); }

    template <typename T>
    T& Get() { return const_cast<T&>(const_cast<const NWVariant*>(this)->Get<T>()); };

    template <typename T>
    const T& Get() const
    {
        static_assert(detail::is_argument_type<T>(), "Invalid argument type.");
        return std::get<T>(m_data);
    }

    std::string toString() const;
};

using NWVariantStack = std::stack<NWVariant>;

} // namespace NWNXLib

std::ostream& operator<<(std::ostream& os, const NWNXLib::NWVariant& arg);
