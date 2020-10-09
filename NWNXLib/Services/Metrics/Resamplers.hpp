#pragma once

#include "Services/Metrics/MetricData.hpp"
#include <functional>
#include <vector>

namespace NWNXLib::Services {

struct Resamplers
{
public:
    Resamplers() = delete;

    using ResamplerFunction = std::function<std::vector<MetricData>(std::vector<MetricData>&&)>;
    using ResamplerFuncPtr = std::vector<MetricData>(*)(std::vector<MetricData>&&);

    template <typename T>
    static std::vector<MetricData> Sum(std::vector<MetricData>&& data);

    template <typename T>
    static std::vector<MetricData> Mean(std::vector<MetricData>&& data);

    template <typename T>
    static std::vector<MetricData> Min(std::vector<MetricData>&& data);

    template <typename T>
    static std::vector<MetricData> Max(std::vector<MetricData>&& data);

    static std::vector<MetricData> Discard(std::vector<MetricData>&& data);

    template <typename T>
    static std::vector<MetricData> Sum(std::vector<MetricData>&& data,
        std::function<T(const std::string&)>&& fromString,
        std::function<std::string(const T&)>&& toString,
        T startingVal = {});

    template <typename T>
    static std::vector<MetricData> Mean(std::vector<MetricData>&& data,
        std::function<T(const std::string&)>&& fromString,
        std::function<std::string(const T&)>&& toString);

    template <typename T>
    static std::vector<MetricData> Min(std::vector<MetricData>&& data,
        std::function<T(const std::string&)>&& fromString,
        std::function<std::string(const T&)>&& toString);

    template <typename T>
    static std::vector<MetricData> Max(std::vector<MetricData>&& data,
        std::function<T(const std::string&)>&& fromString,
        std::function<std::string(const T&)>&& toString);

    // This can be used as an easy way to resample values.
    // Given the provided data, it will then call the provided function with a vector
    // of all the values that belong to a matching field and need to be joined.
    static std::vector<MetricData> Resample(std::vector<MetricData>&& data,
        std::function<std::string(std::vector<std::string>&&)> resampler);

    // Given a MetricData entry, this will find (or insert if does not exist) a unique
    // entry in the provided collection which satisfies the conditions in TestLogicalEquality.
    static size_t FindOrInsertUniqueEntry(const MetricData& entry, std::vector<MetricData>& collection);

    // Returns true if the following conditions are satisfied:
    // - Tags keys and values identical, same number.
    // - Field keys identical, same number, values irrelevant.
    static bool TestLogicalEquality(const MetricData& first, const MetricData& second);

};

#include "Services/Metrics/Resamplers.inl"

}
