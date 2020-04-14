#include "Services/Config/Config.hpp"
#include <cstdlib>
#include <vector>

namespace NWNXLib::Services {

Config::Config()
{
}

std::optional<std::string> Config::Get(const std::string& section, const std::string& key,
    bool trim)
{
    // section already includes the NWNX_ prefix (from the filename)
    // But we need the filename/section to be upcase by convention
    std::string mykey = section + "_";
    std::transform(mykey.begin(), mykey.end(), mykey.begin(), ::toupper);

    // The key itself is opaque to the system though.
    mykey += key;

    const char* ev = std::getenv(mykey.c_str());

    if (!ev)
    {
        return std::optional<std::string>();
    }

    std::string v = ev;

    if (trim)
    {
        Utils::trim(v);
    }

    if (v.empty())
    {
        return std::optional<std::string>();
    }

    return std::make_optional<std::string>(std::move(v));
}

std::optional<std::string> Config::Set(const std::string&, const std::string&,
    const std::string&)
{
    throw std::runtime_error("Config::Set is not yet implemented.");
}

template<>
std::optional<std::string> ConfigProxy::Get<std::string>(const std::string& key) const
{
    return m_proxyBase.Get(m_moduleName, key);
}

template<>
std::optional<bool> ConfigProxy::Get<bool>(const std::string& key) const
{
    auto opt = m_proxyBase.Get(m_moduleName, key);

    if (!opt)
    {
        return std::optional<bool>();
    }

    // Valid boolean values.
    static const std::vector<std::string> falsies = { "", "f", "false", "n", "no", "0" };
    static const std::vector<std::string> truesies = { "t", "true", "y", "yes", "1" };

    auto v = opt.value();
    std::transform(v.begin(), v.end(), v.begin(), ::tolower);
    bool isTrue = std::find(truesies.begin(), truesies.end(), v) != truesies.end();
    // bool isFalse = std::find(falsies.begin(), falsies.end(), v) != falsies.end();
    // TODO: warn somewhere about configuration errors if neither matches
    return std::make_optional<bool>(std::move(isTrue));
}

template<>
std::optional<int64_t> ConfigProxy::Get<int64_t>(const std::string& key) const
{
    auto opt = m_proxyBase.Get(m_moduleName, key);

    if (!opt)
    {
        return std::optional<int64_t>();
    }

    auto v = opt.value();
    auto base = (v.substr(0, 2) == "0x") ? 16 : 10;
    return std::make_optional<int64_t>(std::strtoll(v.c_str(), nullptr, base));
}

template<>
std::optional<int32_t> ConfigProxy::Get<int32_t>(const std::string& key) const
{
    auto opt = m_proxyBase.Get(m_moduleName, key);

    if (!opt)
    {
        return std::optional<int32_t>();
    }

    auto v = opt.value();
    auto base = (v.substr(0, 2) == "0x") ? 16 : 10;
    return std::make_optional<int32_t>(std::strtol(v.c_str(), nullptr, base));
}

template<> std::optional<uint64_t> ConfigProxy::Get<uint64_t>(const std::string& key) const
{
    auto opt = m_proxyBase.Get(m_moduleName, key);

    if (!opt)
    {
        return std::optional<uint64_t>();
    }

    auto v = opt.value();
    auto base = (v.substr(0, 2) == "0x") ? 16 : 10;
    return std::make_optional<uint64_t>(std::strtoull(v.c_str(), nullptr, base));
}

template<> std::optional<uint32_t> ConfigProxy::Get<uint32_t>(const std::string& key) const
{
    auto opt = m_proxyBase.Get(m_moduleName, key);

    if (!opt)
    {
        return std::optional<uint32_t>();
    }

    auto v = opt.value();
    auto base = (v.substr(0, 2) == "0x") ? 16 : 10;
    return std::make_optional<uint32_t>(std::strtoul(v.c_str(), nullptr, base));
}

template<>
std::optional<float> ConfigProxy::Get<float>(const std::string& key) const
{
    auto opt = m_proxyBase.Get(m_moduleName, key);

    if (!opt)
    {
        return std::optional<float>();
    }

    auto v = opt.value();
    return std::make_optional<float>(std::strtof(v.c_str(), nullptr));
}

template<>
std::optional<double> ConfigProxy::Get<double>(const std::string& key) const
{
    auto opt = m_proxyBase.Get(m_moduleName, key);

    if (!opt)
    {
        return std::optional<double>();
    }

    auto v = opt.value();
    return std::make_optional<double>(std::strtod(v.c_str(), nullptr));
}

}
