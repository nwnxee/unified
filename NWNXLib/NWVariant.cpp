#include "NWVariant.hpp"
#include "Utils.hpp"

namespace NWNXLib
{

std::string NWVariant::toString() const
{
    if (Holds<int32_t>()) { return std::to_string(Get<int32_t>()); }
    else if (Holds<float>()) { return std::to_string(Get<float>()); }
    else if (Holds<API::Types::ObjectID>()) { return Utils::ObjectIDToString(Get<API::Types::ObjectID>()); }
    else if (Holds<std::string>()) { return Get<std::string>(); }
    else if (Holds<NullArgument>()) { return "(null)"; }
    else if (Holds<CGameEffect*>())
    {
        auto e = Get<CGameEffect*>();
        return e ? std::string("EffectID:") + std::to_string(e->m_nID) : std::string("nullptr effect");
    }
    return "(unknown argument type)";
}

} // namespace NWNXLib

std::ostream& operator<<(std::ostream& os, const NWNXLib::NWVariant& arg)
{
    os << arg.toString();
    return os;
}
