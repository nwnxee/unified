#include "Plugin.hpp"

namespace NWNXLib {

Plugin::Plugin(const CreateParams& params)
    : m_services(params.m_services)
{
}

Plugin::~Plugin()
{
}

Plugin::Info::Info(std::string name,
    std::string description,
    std::string author,
    std::string contact,
    const Version version,
    const bool hotswap,
    const uint32_t flags,
    const Version targetVersion)
    : m_name(std::move(name)),
      m_description(std::move(description)),
      m_author(std::move(author)),
      m_contact(std::move(contact)),
      m_version(version),
      m_hotswap(hotswap),
      m_flags(flags),
      m_targetVersion(targetVersion)
{
}

Services::ProxyServiceList* Plugin::GetServices()
{
    return m_services;
}

}
