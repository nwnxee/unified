#pragma once

#include <cstdint>

#include "curl_llist.hpp"

namespace NWNXLib {

namespace API {

struct connectbundle
{
    int32_t multiuse;
    uint32_t num_connections;
    curl_llist conn_list;
};

}

}
