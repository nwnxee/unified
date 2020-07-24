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

}
