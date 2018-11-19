#pragma once

#include <cstdint>

#include "unknown_Curl_MD5_final_func.hpp"
#include "unknown_Curl_MD5_init_func.hpp"
#include "unknown_Curl_MD5_update_func.hpp"

namespace NWNXLib {

namespace API {

struct MD5_params
{
    Curl_MD5_init_func md5_init_func;
    Curl_MD5_update_func md5_update_func;
    Curl_MD5_final_func md5_final_func;
    uint32_t md5_ctxtsize;
    uint32_t md5_resultlen;
};

}

}
