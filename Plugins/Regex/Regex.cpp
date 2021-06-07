#include "nwnx.hpp"

#include <regex>

using namespace NWNXLib;
using namespace NWNXLib::Services;

NWNX_EXPORT ArgumentStack Search(ArgumentStack&& args)
{
    const auto str = args.extract<std::string>();
    const auto regex = args.extract<std::string>();

    std::regex rgx(regex);
    const auto retVal = std::regex_search(str, rgx);

    return retVal;
}

NWNX_EXPORT ArgumentStack Replace(ArgumentStack&& args)
{
    const auto str = args.extract<std::string>();
    const auto regex = args.extract<std::string>();
    const auto rpl = args.extract<std::string>();
    const auto firstOnly = args.extract<int32_t>();

    std::regex rgx(regex);
    std::string retVal;
    if (firstOnly)
        retVal = std::regex_replace(str, rgx, rpl, std::regex_constants::format_first_only);
    else
        retVal = std::regex_replace(str, rgx, rpl);

    return retVal;
}
