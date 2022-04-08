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

NWNX_EXPORT ArgumentStack Match(ArgumentStack&& args)
{
    const auto str = args.extract<std::string>();
      ASSERT_OR_THROW(!str.empty());
    const auto regex = args.extract<std::string>();
      ASSERT_OR_THROW(!regex.empty());

    std::regex rgx(regex);
    std::sregex_iterator it(str.begin(), str.end(), rgx);
    const static std::sregex_iterator end;

    JsonEngineStructure retVal(json::array());

    while (it != end)
    {
        json matches = json::array();
        for (size_t i = 0; i < it->size(); i++)
        {
            matches.emplace_back(it->str(i));
        }
        retVal.m_json.emplace_back(matches);
        it++;
    }

    return retVal;
}
