#pragma once

#include "API/Types.hpp"
#include "API/API/CGameEffect.hpp"

#include <optional>
#include <stack>

namespace NWNXLib
{

struct NWVariant
{
    std::optional<int32_t>              m_int;
    std::optional<float>                m_float;
    std::optional<API::Types::ObjectID> m_object;
    std::optional<std::string>          m_string;
    std::optional<CGameEffect*>         m_effect;

    // Constructors
    NWVariant(int32_t v)                : m_int(v)    { }
    NWVariant(float v)                  : m_float(v)  { }
    NWVariant(API::Types::ObjectID v)   : m_object(v) { }
    NWVariant(std::string v)            : m_string(std::move(v)) { }
    NWVariant(CGameEffect* v)           : m_effect(v) { }

    template <typename T> std::optional<T>& Get();
    std::string toString() const;
};

using NWVariantStack = std::stack<NWVariant>;

template<> std::optional<int32_t>&              NWVariant::Get<int32_t>();
template<> std::optional<float>&                NWVariant::Get<float>();
template<> std::optional<API::Types::ObjectID>& NWVariant::Get<API::Types::ObjectID>();
template<> std::optional<std::string>&          NWVariant::Get<std::string>();
template<> std::optional<CGameEffect*>&         NWVariant::Get<CGameEffect*>();

} // namespace NWNXLib

std::ostream& operator<<(std::ostream& os, const NWNXLib::NWVariant& arg);
