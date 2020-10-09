#pragma once

#include <string>
#include <vector>
#include <optional>

namespace NWNXLib::Utils {

// String conversions...
template <typename T>
std::optional<T> from_string(const std::string& str) = delete;
template<> std::optional<bool> from_string(const std::string& str);
template<> std::optional<int32_t> from_string(const std::string& str);
template<> std::optional<uint32_t> from_string(const std::string& str);
template<> std::optional<int64_t> from_string(const std::string& str);
template<> std::optional<uint64_t> from_string(const std::string& str);
template<> std::optional<float> from_string(const std::string& str);
template<> std::optional<double> from_string(const std::string& str);

// Trim functions...
std::string& ltrim(std::string& str);
std::string& rtrim(std::string& str);
std::string& trim(std::string& str);

// Join & Split...
std::string join(const std::vector<std::string>& str, const char* delim = " ");
std::vector<std::string> split(const std::string& str, char delim, bool skipEmpty = true, bool trimmed = true);

std::string basename(const std::string& path);

}
