#pragma once

#include <cstdint>

#include "curl_llist_element.hpp"

namespace NWNXLib {

namespace API {

struct site_blacklist_entry
{
    curl_llist_element list;
    uint16_t port;
    char hostname[1];
};

}

}
