#pragma once

#include <cstdint>

#include "mime_state.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_easy;
struct curl_mimepart_s;

struct curl_mime_s
{
    Curl_easy* easy;
    curl_mimepart_s* parent;
    curl_mimepart_s* firstpart;
    curl_mimepart_s* lastpart;
    char* boundary;
    mime_state state;
};

}

}
