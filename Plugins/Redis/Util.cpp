#include "Util.h"

#include <sstream>
#include <iterator>

std::string str_implode(const std::vector<std::string>& v,
                        const std::string delim)
{
    std::ostringstream imploded;
    std::copy(v.begin(), v.end(),
              std::ostream_iterator<std::string>(imploded, delim.c_str()));
    auto str = imploded.str();
    return str.substr(0, str.size() - 1);
}

std::vector<std::string> str_explode(const std::string& sp,
                                     char delim)
{
    std::vector<std::string> out;
    std::stringstream ss;
    ss.str(sp);
    std::string item;
    while (getline(ss, item, delim))
        out.push_back(item);
    return out;
}
