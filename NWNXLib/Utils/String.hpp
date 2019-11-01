#pragma once

#include <string>
#include <vector>

namespace NWNXLib {

template <typename T>
class Maybe;

namespace Utils {

// String conversions...
template <typename T>
Maybe<T> from_string(const std::string& str) = delete;
template<> Maybe<bool> from_string(const std::string& str);
template<> Maybe<int32_t> from_string(const std::string& str);
template<> Maybe<uint32_t> from_string(const std::string& str);
template<> Maybe<int64_t> from_string(const std::string& str);
template<> Maybe<uint64_t> from_string(const std::string& str);
template<> Maybe<float> from_string(const std::string& str);
template<> Maybe<double> from_string(const std::string& str);

// Trim functions...
std::string& ltrim(std::string& str);
std::string& rtrim(std::string& str);
std::string& trim(std::string& str);

// Join & Split...
std::string join(const std::vector<std::string>& str, const char* delim = " ");
std::vector<std::string> split(const std::string& str, char delim, bool skipEmpty = true, bool trimmed = true);

}
}
