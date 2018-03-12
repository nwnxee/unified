#include "Services/Config/Config.hpp"
#include <cstdlib>
#include <vector>

namespace NWNXLib {

namespace Services {

Config::Config()
{
}

Maybe<std::string> Config::Get(const std::string& section, const std::string& key,
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
        return Maybe<std::string>();
    }

    std::string v = ev;

    if (trim)
    {
        v.erase(0, v.find_first_not_of(" \n\r\t"));
        v.erase(v.find_last_not_of(" \n\r\t") + 1);
    }

    if (v.empty())
    {
        return Maybe<std::string>();
    }

    return Maybe<std::string>(std::move(v));
}

Maybe<std::string> Config::Set(const std::string&, const std::string&,
    const std::string&)
{
    throw std::runtime_error("Config::Set is not yet implemented.");
}

template<>
Maybe<std::string> ConfigProxy::Get<std::string>(const std::string& key) const
{
    return m_proxyBase.Get(m_moduleName, key);
}

template<>
Maybe<bool> ConfigProxy::Get<bool>(const std::string& key) const
{
    auto may = m_proxyBase.Get(m_moduleName, key);

    if (!may)
    {
        return Maybe<bool>();
    }

    // Valid boolean values.
    static const std::vector<std::string> falsies = { "", "f", "false", "n", "no", "0" };
    static const std::vector<std::string> truesies = { "t", "true", "y", "yes", "1" };

    auto v = may.Extract();
    std::transform(v.begin(), v.end(), v.begin(), ::tolower);
    bool isTrue = std::find(truesies.begin(), truesies.end(), v) != truesies.end();
    // bool isFalse = std::find(falsies.begin(), falsies.end(), v) != falsies.end();
    // TODO: warn somewhere about configuration errors if neither matches
    return Maybe<bool>(std::move(isTrue));
}

template<>
Maybe<int64_t> ConfigProxy::Get<int64_t>(const std::string& key) const
{
    auto may = m_proxyBase.Get(m_moduleName, key);

    if (!may)
    {
        return Maybe<int64_t>();
    }

    auto v = may.Extract();
    auto base = (v.substr(0, 2) == "0x") ? 16 : 10;
    return Maybe<int64_t>(std::strtoll(v.c_str(), nullptr, base));
}

template<>
Maybe<int32_t> ConfigProxy::Get<int32_t>(const std::string& key) const
{
    auto may = m_proxyBase.Get(m_moduleName, key);

    if (!may)
    {
        return Maybe<int32_t>();
    }

    auto v = may.Extract();
    auto base = (v.substr(0, 2) == "0x") ? 16 : 10;
    return Maybe<int32_t>(std::strtol(v.c_str(), nullptr, base));
}

template<> Maybe<uint64_t> ConfigProxy::Get<uint64_t>(const std::string& key) const
{
    auto may = m_proxyBase.Get(m_moduleName, key);

    if (!may)
    {
        return Maybe<uint64_t>();
    }

    auto v = may.Extract();
    auto base = (v.substr(0, 2) == "0x") ? 16 : 10;
    return Maybe<uint64_t>(std::strtoull(v.c_str(), nullptr, base));
}

template<> Maybe<uint32_t> ConfigProxy::Get<uint32_t>(const std::string& key) const
{
    auto may = m_proxyBase.Get(m_moduleName, key);

    if (!may)
    {
        return Maybe<uint32_t>();
    }

    auto v = may.Extract();
    auto base = (v.substr(0, 2) == "0x") ? 16 : 10;
    return Maybe<uint32_t>(std::strtoul(v.c_str(), nullptr, base));
}

template<>
Maybe<float> ConfigProxy::Get<float>(const std::string& key) const
{
    auto may = m_proxyBase.Get(m_moduleName, key);

    if (!may)
    {
        return Maybe<float>();
    }

    auto v = may.Extract();
    return Maybe<float>(std::strtof(v.c_str(), nullptr));
}

template<>
Maybe<double> ConfigProxy::Get<double>(const std::string& key) const
{
    auto may = m_proxyBase.Get(m_moduleName, key);

    if (!may)
    {
        return Maybe<double>();
    }

    auto v = may.Extract();
    return Maybe<double>(std::strtod(v.c_str(), nullptr));
}

}

}
