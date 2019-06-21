#pragma once

#include <cstdint>

#include "curl_llist_element.hpp"
#include "curltime.hpp"
#include "unknown_expire_id.hpp"

namespace NWNXLib {

namespace API {

struct time_node
{
    curl_llist_element list;
    curltime time;
    expire_id eid;
};

}

}
