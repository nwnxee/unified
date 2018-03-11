#pragma once

#include <string>
#include <vector>
#include <chrono>

std::string str_implode(const std::vector<std::string>& v,
                        const std::string delim = " ");


std::vector<std::string> str_explode(const std::string& sp,
                                     char delim);

// Executes the code given in `code`, times it and returns the runtime
// (in nanoseconds).
template<typename Lambda>
inline uint64_t Measure(Lambda code)
{
    const auto start = std::chrono::steady_clock::now();
    code();
    const auto end = std::chrono::steady_clock::now();

    const auto diff = std::chrono::
                      duration_cast<std::chrono::nanoseconds>(end - start).count();

    // assert(diff >= 0);

    return static_cast<uint64_t>(diff);
}
