#pragma once

#include <cstdint>

#include "MS_RSAVLong.hpp"

namespace NWNXLib {

namespace API {

struct MS_RSAPublicKey
{
    MS_RSAVLong n;
    MS_RSAVLong e;
};

}

}
