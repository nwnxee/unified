#include "Helpers.hpp"
#include <sstream>

namespace Events {

namespace Helpers {

std::string ObjectIDToString(const NWNXLib::API::Types::ObjectID id)
{
    std::stringstream ss;
    ss << std::hex << id;
    return ss.str();
}

}

}
