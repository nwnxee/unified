#pragma once

#include <cstdint>

#include "unknown_HMAC_hfinal_func.hpp"
#include "unknown_HMAC_hinit_func.hpp"
#include "unknown_HMAC_hupdate_func.hpp"

namespace NWNXLib {

namespace API {

struct HMAC_params
{
    HMAC_hinit_func hmac_hinit;
    HMAC_hupdate_func hmac_hupdate;
    HMAC_hfinal_func hmac_hfinal;
    uint32_t hmac_ctxtsize;
    uint32_t hmac_maxkeylen;
    uint32_t hmac_resultlen;
};

}

}
