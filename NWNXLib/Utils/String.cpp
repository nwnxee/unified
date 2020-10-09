#include "String.hpp"
#include <sstream>
#include <stdlib.h> 
#include <string.h>

namespace NWNXLib::Utils {

template<> std::optional<bool> from_string(const std::string& str)
{
    static const char* truesies[] = { "t", "true", "y", "yes", "1" };
    static const char* falsies[] = { "f", "false", "n", "no", "0" };

    for (const char* t : truesies)
    {
        if (strcasecmp(t, str.c_str()) == 0)
        {
            return std::make_optional<bool>(true);
        }
    }

    for (const char* f : falsies)
    {
        if (strcasecmp(f, str.c_str()) == 0)
        {
            return std::make_optional<bool>(false);
        }
    }

    return std::optional<bool>();
}

inline int base(const std::string& str)
{
    return str.length() > 2 && str[0] == '0' && str[1] == 'x' ? 16 : 10;
}

inline const char* first_non_space(const std::string& str) {
    const char* start = str.c_str();
    while (*start && std::isspace(*start)) ++start;
    return start;
}

template <> std::optional<int32_t> from_string(const std::string& str)
{
    const char* start = first_non_space(str);
    if (!*start) return std::optional<int32_t>();
    char* end;
    int32_t res = strtol(start, &end, base(str));
    return (!*end || std::isspace(*end)) ? std::optional<int32_t>(res) : std::optional<int32_t>();
}

template<> std::optional<uint32_t> from_string(const std::string& str)
{
    const char* start = first_non_space(str);
    if (!*start) return std::optional<uint32_t>();
    char* end;
    uint32_t res = strtoul(start, &end, base(str));
    return (!*end || std::isspace(*end)) ? std::optional<uint32_t>(res) : std::optional<uint32_t>();
}

template<> std::optional<int64_t> from_string(const std::string& str)
{
    const char* start = first_non_space(str);
    if (!*start) return std::optional<int64_t>();
    char* end;
    int64_t res = strtoll(start, &end, base(str));
    return (!*end || std::isspace(*end)) ? std::optional<int64_t>(res) : std::optional<int64_t>();
}

template<> std::optional<uint64_t> from_string(const std::string& str)
{
    const char* start = first_non_space(str);
    if (!*start) return std::optional<uint64_t>();
    char* end;
    uint64_t res = strtoull(start, &end, base(str));
    return (!*end || std::isspace(*end)) ? std::optional<uint64_t>(res) : std::optional<uint64_t>();
}

template<> std::optional<float> from_string(const std::string& str)
{
    const char* start = first_non_space(str);
    if (!*start) return std::optional<float>();
    char* end;
    float res = strtof(start, &end);
    return (!*end || std::isspace(*end)) ? std::optional<float>(res) : std::optional<float>();
}

template<> std::optional<double> from_string(const std::string& str)
{
    const char* start = first_non_space(str);
    if (!*start) return std::optional<double>();
    char* end;
    double res = strtod(start, &end);
    return (!*end || std::isspace(*end)) ? std::optional<double>(res) : std::optional<double>();
}

std::string& ltrim(std::string& str) 
{
    str.erase(0, str.find_first_not_of(" \n\r\t"));
    return str;
}

std::string& rtrim(std::string& str) 
{
    str.erase(str.find_last_not_of(" \n\r\t") + 1);
    return str;
}

std::string& trim(std::string& str) 
{
    return ltrim(rtrim(str));
}

std::string join(const std::vector<std::string>& v, const char* delim)
{
    if (!v.size()) return {};

    std::ostringstream out;
    auto it = std::begin(v);

    out << *it;
    while(++it != std::end(v)) 
    {
        out << delim << *it; 
    }
    return out.str();
}

std::vector<std::string> split(const std::string& sp, char delim, bool skipEmpty, bool trimmed)
{
    std::vector<std::string> out;
    std::istringstream ss{sp};
    std::string item;
    while (getline(ss, item, delim))
    {
        if (skipEmpty && item.empty()) 
            continue;
        
        if (trimmed)
            trim(item);

        out.push_back(item);
    }
    return out;
}

std::string basename(const std::string& path)
{
    std::string name = path;
    auto slash = name.find_last_of('/');
    if (slash != std::string::npos)
        name = name.substr(slash+1);

    auto dot = name.find_last_of('.');
    if (dot != std::string::npos)
        name = name.substr(0, dot);
    return name;
}


}
