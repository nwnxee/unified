#pragma once

#include <string>

namespace NWNXLib {
namespace Utils {

// String converstions...
template <typename T>
T from_string(const std::string& str) = delete;
template<> bool from_string(const std::string& str);
template<> int32_t from_string(const std::string& str);
template<> uint32_t from_string(const std::string& str);
template<> int64_t from_string(const std::string& str);
template<> uint64_t from_string(const std::string& str);
template<> float from_string(const std::string& str);
template<> double from_string(const std::string& str);

// Trim functions...
std::string& ltrim(std::string& str);
std::string& rtrim(std::string& str);
std::string& trim(std::string& str);

}
}