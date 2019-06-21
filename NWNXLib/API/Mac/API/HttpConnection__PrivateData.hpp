#pragma once

#include <cstdint>

#include "unknown_std__shared_ptrTemplatedHttpBuffer.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct curl_slist;

struct HttpConnection__PrivateData
{
    std__shared_ptrTemplatedHttpBuffer m_buffer;
    curl_slist* m_headers;
};

}

}
