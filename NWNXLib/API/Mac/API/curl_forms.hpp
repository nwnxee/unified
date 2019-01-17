#pragma once

#include <cstdint>

#include "unknown_CURLformoption.hpp"

namespace NWNXLib {

namespace API {

struct curl_forms
{
    CURLformoption option;
    const char* value;
};

}

}
