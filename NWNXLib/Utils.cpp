#include "Utils.hpp"
#include <sstream>

namespace NWNXLib {
namespace Utils {


std::string ObjectIDToString(const API::Types::ObjectID id)
{
    std::stringstream ss;
    ss << std::hex << id;
    return ss.str();
}

}

}
