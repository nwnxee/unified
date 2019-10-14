#include "String.hpp"
#include <string.h>

namespace NWNXLib {
namespace Utils {

template<> bool from_string(const std::string& str) 
{
    static const char* truesies[] = { "t", "true", "y", "yes", "1" };

    for (const auto& t : truesies){
        if (strcasecmp(t, str.c_str()) == 0)
        {
            return true; 
        }
    }

    return false;
}

inline int base(const std::string& str)
{
    return str.length() > 2 && str[0] == '0' && str[1] == 'x' ? 16 : 10;
}

template <>
int32_t from_string(const std::string& str)
{
    return std::stol(str, nullptr, base(str));
}

template<> uint32_t from_string(const std::string& str)
{
    return std::stoul(str, nullptr, base(str));
}

template<> int64_t from_string(const std::string& str)
{
    return std::stoll(str, nullptr, base(str));
}

template<> uint64_t from_string(const std::string& str)
{
    return std::stoull(str, nullptr, base(str));
}

template<> float from_string(const std::string& str)
{
    return std::stof(str);
}

template<> double from_string(const std::string& str)
{
    return std::stod(str);
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

}
}