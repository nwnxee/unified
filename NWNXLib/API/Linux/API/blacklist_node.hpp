#pragma once

#include <cstdint>

#include "curl_llist_element.hpp"

namespace NWNXLib {

namespace API {

struct blacklist_node
{
    curl_llist_element list;
    char server_name[1];
};

}

}
