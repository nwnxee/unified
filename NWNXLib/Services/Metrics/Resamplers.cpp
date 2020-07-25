#include "Services/Metrics/Resamplers.hpp"
#include <algorithm>
#include <unordered_map>

namespace NWNXLib::Services {

template <>
std::vector<MetricData> Resamplers::Sum<std::chrono::nanoseconds>(std::vector<MetricData>&& data)
{
    return Sum<int64_t>(std::forward<std::vector<MetricData>>(data));
}

template <>
std::vector<MetricData> Resamplers::Sum<int64_t>(std::vector<MetricData>&& data)
{
    return Sum<int64_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> int64_t { return std::stoll(str); },
        [](const int64_t& val) -> std::string { return std::to_string(val); },
        0);
}

template <>
std::vector<MetricData> Resamplers::Sum<uint64_t>(std::vector<MetricData>&& data)
{
    return Sum<uint64_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> uint64_t { return std::stoull(str); },
        [](const uint64_t& val) -> std::string { return std::to_string(val); },
        0);
}

template<>
std::vector<MetricData> Resamplers::Sum<double>(std::vector<MetricData>&& data)
{
    return Sum<double>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> double { return std::stod(str); },
        [](const double& val) -> std::string { return std::to_string(val); },
        0.0);
}

template<>
std::vector<MetricData> Resamplers::Sum<int32_t>(std::vector<MetricData>&& data)
{
    return Sum<int32_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> int32_t { return std::stol(str); },
        [](const int32_t& val) -> std::string { return std::to_string(val); },
        0);
}

template<>
std::vector<MetricData> Resamplers::Sum<uint32_t>(std::vector<MetricData>&& data)
{
    return Sum<uint32_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> uint32_t { return std::stoul(str); },
        [](const uint32_t& val) -> std::string { return std::to_string(val); },
        0);
}

template<>
std::vector<MetricData> Resamplers::Sum<float>(std::vector<MetricData>&& data)
{
    return Sum<float>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> float { return std::stof(str); },
        [](const float& val) -> std::string { return std::to_string(val); },
        0.0f);
}

template <>
std::vector<MetricData> Resamplers::Mean<std::chrono::nanoseconds>(std::vector<MetricData>&& data)
{
    return Mean<int64_t>(std::forward<std::vector<MetricData>>(data));
}

template <>
std::vector<MetricData> Resamplers::Mean<int64_t>(std::vector<MetricData>&& data)
{
    return Mean<int64_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> int64_t { return std::stoll(str); },
        [](const int64_t& val) -> std::string { return std::to_string(val); });
}

template <>
std::vector<MetricData> Resamplers::Mean<uint64_t>(std::vector<MetricData>&& data)
{
    return Mean<uint64_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> uint64_t { return std::stoull(str); },
        [](const uint64_t& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Mean<double>(std::vector<MetricData>&& data)
{
    return Mean<double>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> double { return std::stod(str); },
        [](const double& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Mean<int32_t>(std::vector<MetricData>&& data)
{
    return Mean<int32_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> int32_t { return std::stol(str); },
        [](const int32_t& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Mean<uint32_t>(std::vector<MetricData>&& data)
{
    return Mean<uint32_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> uint32_t { return std::stoul(str); },
        [](const uint32_t& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Mean<float>(std::vector<MetricData>&& data)
{
    return Mean<float>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> float { return std::stof(str); },
        [](const float& val) -> std::string { return std::to_string(val); });
}

template <>
std::vector<MetricData> Resamplers::Min<std::chrono::nanoseconds>(std::vector<MetricData>&& data)
{
    return Min<int64_t>(std::forward<std::vector<MetricData>>(data));
}

template <>
std::vector<MetricData> Resamplers::Min<int64_t>(std::vector<MetricData>&& data)
{
    return Min<int64_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> int64_t { return std::stoll(str); },
        [](const int64_t& val) -> std::string { return std::to_string(val); });
}

template <>
std::vector<MetricData> Resamplers::Min<uint64_t>(std::vector<MetricData>&& data)
{
    return Min<uint64_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> uint64_t { return std::stoull(str); },
        [](const uint64_t& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Min<double>(std::vector<MetricData>&& data)
{
    return Min<double>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> double { return std::stod(str); },
        [](const double& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Min<int32_t>(std::vector<MetricData>&& data)
{
    return Min<int32_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> int32_t { return std::stol(str); },
        [](const int32_t& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Min<uint32_t>(std::vector<MetricData>&& data)
{
    return Min<uint32_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> uint32_t { return std::stoul(str); },
        [](const uint32_t& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Min<float>(std::vector<MetricData>&& data)
{
    return Min<float>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> float { return std::stof(str); },
        [](const float& val) -> std::string { return std::to_string(val); });
}

template <>
std::vector<MetricData> Resamplers::Max<std::chrono::nanoseconds>(std::vector<MetricData>&& data)
{
    return Max<int64_t>(std::forward<std::vector<MetricData>>(data));
}

template <>
std::vector<MetricData> Resamplers::Max<int64_t>(std::vector<MetricData>&& data)
{
    return Max<int64_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> int64_t { return std::stoll(str); },
        [](const int64_t& val) -> std::string { return std::to_string(val); });
}

template <>
std::vector<MetricData> Resamplers::Max<uint64_t>(std::vector<MetricData>&& data)
{
    return Max<uint64_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> uint64_t { return std::stoull(str); },
        [](const uint64_t& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Max<double>(std::vector<MetricData>&& data)
{
    return Max<double>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> double { return std::stod(str); },
        [](const double& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Max<int32_t>(std::vector<MetricData>&& data)
{
    return Max<int32_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> int32_t { return std::stol(str); },
        [](const int32_t& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Max<uint32_t>(std::vector<MetricData>&& data)
{
    return Max<uint32_t>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> uint32_t { return std::stoul(str); },
        [](const uint32_t& val) -> std::string { return std::to_string(val); });
}

template<>
std::vector<MetricData> Resamplers::Max<float>(std::vector<MetricData>&& data)
{
    return Max<float>(std::forward<std::vector<MetricData>>(data),
        [](const std::string& str) -> float { return std::stof(str); },
        [](const float& val) -> std::string { return std::to_string(val); });
}

std::vector<MetricData> Resamplers::Discard(std::vector<MetricData>&&)
{
    return std::vector<MetricData>();
}

std::vector<MetricData> Resamplers::Resample(std::vector<MetricData>&& data,
    std::function<std::string(std::vector<std::string>&&)> resample)
{
    std::vector<MetricData> uniqueData;
    std::unordered_map<size_t, std::vector<MetricData*>> uniqueMap;

    for (auto& entry : data)
    {
        // Construct a suitable entry for the full collection.
        uniqueMap[FindOrInsertUniqueEntry(entry, uniqueData)].emplace_back(&entry);
    }

    for (size_t i = 0; i < uniqueData.size(); ++i)
    {
        auto& entry = uniqueData[i];
        auto& existingData = uniqueMap[i];

        // Set up the earliest timestamp for each entry.
        auto earliestEntry = *std::min_element(
            std::begin(existingData),
            std::end(existingData),
            [](auto& first, auto& second)
            {
                return first->m_timestamp < second->m_timestamp;
            });

        entry.m_timestamp = earliestEntry->m_timestamp;

        // Now, for each field, resample.
        for (size_t j = 0; j < entry.m_fields.size(); ++j)
        {
            std::vector<std::string> valuesForThisField;

            for (auto& existingValue : existingData)
            {
                valuesForThisField.emplace_back(std::move(existingValue->m_fields[j].second));
            }

            entry.m_fields[j].second = resample(std::move(valuesForThisField));
        }
    }

    return uniqueData;
}

size_t Resamplers::FindOrInsertUniqueEntry(const MetricData& entry, std::vector<MetricData>& collection)
{
    for (size_t i = 0; i < collection.size(); ++i)
    {
        if (TestLogicalEquality(entry, collection[i]))
        {
            // Match. Return it.
            return i;
        }
    }

    // No match. Insert one.
    MetricData newData;
    newData.m_name = entry.m_name;
    newData.m_tags = entry.m_tags;
    newData.m_fields = entry.m_fields;
    collection.emplace_back(std::move(newData));
    return collection.size() - 1;
}

bool Resamplers::TestLogicalEquality(const MetricData& first, const MetricData& second)
{
    if (first.m_name != second.m_name)
    {
        return false;
    }

    const size_t tagCount = first.m_tags.size();
    const size_t fieldCount = first.m_fields.size();

    if (tagCount != second.m_tags.size() || fieldCount != second.m_fields.size())
    {
        // Early out -- do the numbers line up?
        return false;
    }

    for (size_t j = 0; j < tagCount; ++j)
    {
        // Tags need key AND value compared. For this, we can just compare pairs.
        if (first.m_tags[j] != second.m_tags[j])
        {
            // Mismatch tags. Carry on.
            return false;
        }
    }

    for (size_t j = 0; j < fieldCount; ++j)
    {
        // Fields just need keys to be the same. Values will be resampled.
        if (first.m_fields[j].first != second.m_fields[j].first)
        {
            // Mismatch field keys. Carry on.
            return false;
        }
    }

    // At this point, we're a match.
    return true;
}

}
