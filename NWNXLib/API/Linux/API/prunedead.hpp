#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_easy;
struct connectdata;

struct prunedead
{
    Curl_easy* data;
    connectdata* extracted;
};

}

}
