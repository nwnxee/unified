#include "NWVariant.hpp"
#include "Utils.hpp"

namespace NWNXLib
{

template<> std::optional<int32_t>&              NWVariant::Get<int32_t>()             { return m_int; }
template<> std::optional<float>&                NWVariant::Get<float>()               { return m_float; }
template<> std::optional<API::Types::ObjectID>& NWVariant::Get<API::Types::ObjectID>(){ return m_object; }
template<> std::optional<std::string>&          NWVariant::Get<std::string>()         { return m_string; }
template<> std::optional<CGameEffect*>&         NWVariant::Get<CGameEffect*>()        { return m_effect; }

std::string NWVariant::toString() const
{
    if (m_int)    return std::to_string(*m_int);
    if (m_float)  return std::to_string(*m_float);
    if (m_object) return Utils::ObjectIDToString(*m_object);
    if (m_string) return *m_string;
    if (m_effect) return *m_effect ? std::string("EffectID:") + std::to_string((*m_effect)->m_nID) : std::string("nullptr effect");

    return std::string("");
}

} // namespace NWNXLib

std::ostream& operator<<(std::ostream& os, const NWNXLib::NWVariant& arg)
{
    os << arg.toString();
    return os;
}
