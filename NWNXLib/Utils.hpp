#pragma once

#include "API/Types.hpp"
#include <string>


namespace NWNXLib {
namespace Utils {

std::string ObjectIDToString(const API::Types::ObjectID id);

std::string GetCurrentScript();
void ExecuteScript(const std::string& script, API::Types::ObjectID oidOwner);

}

}
