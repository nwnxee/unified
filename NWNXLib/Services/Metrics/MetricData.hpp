#pragma once

#include <chrono>
#include <string>
#include <vector>

namespace NWNXLib::Services {

struct MetricData
{
public: // Structures
    using FieldPair = std::pair<std::string, std::string>;
    using TagPair = std::pair<std::string, std::string>;

    using Fields = std::vector<FieldPair>;
    using Tags = std::vector<TagPair>;

public:
    std::chrono::high_resolution_clock::time_point m_timestamp;
    std::string m_name;
    Fields m_fields;
    Tags m_tags;
};

}
