#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "unknown_std__vectorTemplatedHttpConnection__HeaderTuplestd__allocatorTemplatedHttpConnection__HeaderTuple.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct HttpBufferReceiver;

struct HttpConnection__QueuedURL
{
    HttpBufferReceiver* m_callback;
    CExoString m_url;
    std__vectorTemplatedHttpConnection__HeaderTuplestd__allocatorTemplatedHttpConnection__HeaderTuple m_headers;
    void* m_userData;
    int32_t m_wantResponseHeaders;
};

}

}
