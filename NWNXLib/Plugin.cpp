#include "Plugin.hpp"

namespace NWNXLib {

Plugin::Plugin(const CreateParams& params)
    : m_services(params.m_services)
{
}

Plugin::~Plugin()
{
}

Plugin::Info::Info(std::string&& name,
    std::string&& description,
    std::string&& author,
    std::string&& contact,
    const Version version,
    const bool hotswap,
    const uint32_t flags,
    const Version targetVersion)
    : m_name(std::forward<std::string>(name)),
      m_description(std::forward<std::string>(description)),
      m_author(std::forward<std::string>(author)),
      m_contact(std::forward<std::string>(contact)),
      m_version(version),
      m_hotswap(hotswap),
      m_flags(flags),
      m_targetVersion(targetVersion)
{
}

ViewPtr<Services::ProxyServiceList> Plugin::GetServices()
{
    return m_services;
}

}
