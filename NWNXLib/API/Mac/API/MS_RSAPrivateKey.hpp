#pragma once

#include <cstdint>

#include "MS_RSAPublicKey.hpp"
#include "MS_RSAVLong.hpp"

namespace NWNXLib {

namespace API {

struct MS_RSAPrivateKey
    : MS_RSAPublicKey
{
    MS_RSAVLong p;
    MS_RSAVLong q;
    MS_RSAVLong d;
};

}

}
