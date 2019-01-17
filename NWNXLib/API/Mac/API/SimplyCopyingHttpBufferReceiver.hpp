#pragma once

#include <cstdint>

#include "HttpBufferReceiver.hpp"
#include "unknown_std__shared_ptrTemplatedHttpBuffer.hpp"

namespace NWNXLib {

namespace API {

struct SimplyCopyingHttpBufferReceiver
    : HttpBufferReceiver
{
    std__shared_ptrTemplatedHttpBuffer* m_target;
};

}

}
