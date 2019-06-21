#pragma once

#include <cstdint>

#include "curltime.hpp"

namespace NWNXLib {

namespace API {

struct Curl_tree
{
    Curl_tree* smaller;
    Curl_tree* larger;
    Curl_tree* samen;
    Curl_tree* samep;
    curltime key;
    void* payload;
};

}

}
